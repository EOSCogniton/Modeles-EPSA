### Ce programme a pour but de calculer les températures des différentes
### cellules composants un module. Il peut évidemment être amélioré.

import math
import matplotlib as mpl
import matplotlib.pyplot as plt 
import matplotlib.animation as animation
import numpy as np
from functools import partial

# Paramètre de la cellule
cell_h = 65e-3  # m (hauteur)
cell_d = 18.4e-3  # m (diamètre)
cell_R = 18e-3 # Ohm (résistance interne)
cell_m = 45e-3 # kg (masse) 

cell_S = cell_h *2* math.pi *cell_d/2 # m² (surface de contact à l'air)
cell_V = cell_d/4 * cell_S #m³ (volume)

cell_rho = cell_m/cell_V

F = 96485 # C/mol (Constante de Faraday)
e=1.6e-19 # C

#Paramètre de courant
cell_I = 15 #A (courant traversant chaque cellule)
Q = cell_R * cell_I**2 # W (puissance issue de l'effet Joule)

# Configuration
serie = 12 # (nombre de cellule en série)
parallele = 5 # (nombre de cellule en parallèle)
marge_cell = 4e-3 # m (marge à rajouter pour chaque trou de cellule)

largeur_tot = (parallele + 1/2) * (cell_d + marge_cell)
longueur_tot = (cell_d + marge_cell) * math.cos(30 * math.pi / 180) * (serie - 1) + (cell_d + marge_cell)

cell_largeur = largeur_tot
cell_longueur = longueur_tot
air_V = cell_largeur*cell_longueur*cell_h-serie*parallele*cell_V

# Paramètre ventilo
P = 50 # W (puissance ventilateur)
Qv= 1 # m³/h (débit)
Cv_air = 0.34 # Wh/m³/K
v_air = 20 # m/s (vitesse de l'air)

cp_air = 1001.2 # J/kg/K (chaleur spécifique air)
l_c = 50e-3 # m (largeur conduite)
kin_viscosity=15.6e-6 # m²/s (viscosité cinématique)

# Paramètre de simulation
T_ini = 20. #°C (température initiale air)
t_final = 3600 # s (temps d'arrêt de la simulation)
N = 100000 # (nombre de point de la simulation)
dt = t_final/N

cell_temp = np.array([[[T_ini]*N]*parallele]*serie)
air_temp = np.array([[[T_ini]*N]*parallele]*serie)
t=[0]

def newton(c): # (wikipedia, newton coefficient)
    return 10.45 - c + 10 * math.sqrt(c)

def entropy(SOC): #https://iopscience.iop.org/article/10.1088/1757-899X/53/1/012014/pdf
    return -179*SOC**2+274.29*SOC-116

def heat_spec_capacity(T): #https://www.sciencedirect.com/science/article/pii/S1359431123012413
    return 2.08*T+812.16

def equation(h,deltaS,T_cell,T_air):#https://www.sciencedirect.com/science/article/pii/S0378775305013054#eq3
    return (Q+deltaS*cell_I/F*(T_cell+273.15)-h*cell_S*(T_cell-T_air))/(cell_m*heat_spec_capacity(T_cell))

# def air_thermal_conductivity(T): #http://bouteloup.pierre.free.fr/lica/phythe/don/air/air_k_plot.pdf
#     return 1.5207E-11*T**3 - 4.8574E-08*T**2 + 1.0184E-04*T - 3.9333E-04

def air_density(T):
    Tf = T+273.15
    return 1013*10*2/(287.0500676*Tf)

# def Pr_air(T):
#     return kin_viscosity/air_thermal_conductivity(T)*cp_air*air_density(T)

# def Ra(T,L):
#     Tf=(T+T_air)/2+273.15
#     return 9.81/Tf/kin_viscosity**2*(T-T_air)*L**3*Pr_air(Tf)

# def heat_transfer_coeff(T,L):
#     Tf=(T+T_air)/2+273.15
#     Ray=Ra(T,L)
#     Pra=Pr_air(Tf)
#     k = air_thermal_conductivity(Tf)
#     return k/L*(0.825+0.387*Ray**(1/6)/(1+(0.492/Pra)**(9/16))**(8/27))**2

for k in range(N-1):
    for x in range(serie):
        for y in range(parallele):
            h = newton(v_air)
            deltaS = entropy(0.8)
            T_cell=cell_temp[x][y][k]
            if x==0:
                if y==0:
                    T_air=T_ini
                else:
                    T_cell_up=cell_temp[x][y-1][k]
                    T_air_up=air_temp[x][y-1][k]
                    T_air=0.5*T_ini+0.5*(T_air_up+1/air_density(T_air_up)/cp_air/air_V*h*cell_S*(T_cell_up-T_air_up))
            else:
                T_cell_left=cell_temp[x-1][y][k]
                T_air_left=air_temp[x-1][y][k]
                if y==0:
                    T_air=(T_air_left+1/air_density(T_air_left)/cp_air/air_V*h*cell_S*(T_cell_left-T_air_left))
                else:
                    T_cell_up=cell_temp[x][y-1][k]
                    T_air_up=air_temp[x][y-1][k]
                    T_air=0.5*(T_air_left+1/air_density(T_air_left)/cp_air/air_V*h*cell_S*(T_cell_left-T_air_left))+0.5*(T_air_up+1/air_density(T_air_up)/cp_air/air_V*h*cell_S*(T_cell_up-T_air_up))
            cell_temp[x][y][k+1]=T_cell+dt*equation(h,deltaS,T_cell,T_air)
            air_temp[x][y][k+1]=T_air
    t.append(dt*k)

def print_temp(t):
    for x in range(serie):
        string= ""
        for y in range(parallele):
            string=string+str(cell_temp[x][y][t])+" - "
        print(string)

def print_all():
    for x in range(serie):
        for y in range(parallele):
            plt.subplot(parallele,serie,y*serie+x+1)
            plt.plot(t,cell_temp[x][y])
    plt.show()

def simple_render(t=0):
    circles_cell=[]
    circles_air=[]
    colors=["blue","cyan","lawngreen","yellow","orange","red","darkred"]
    r = cell_d/2
    r_air = math.sqrt(air_V/cell_h/math.pi)
    for i in range(serie):
        for j in range(parallele):
            temp_air=air_temp[i][j][t]
            temp_cell=cell_temp[i][j][t]
            color_air=0*(temp_air<20)+1*(20<=temp_air<30)+2*(30<=temp_air<40)+3*(40<=temp_air<50)+4*(50<=temp_air<55)+5*(55<=temp_air<60)+6*(60<=temp_air)
            color_cell=0*(temp_cell<20)+1*(20<=temp_cell<30)+2*(30<=temp_cell<40)+3*(40<=temp_cell<50)+4*(50<=temp_cell<55)+5*(55<=temp_cell<60)+6*(60<=temp_cell)
            y = (parallele-j-1+1/2+1/2*(i%2))*(cell_d+marge_cell)
            x = (i*math.cos(30 * math.pi / 180)+1/2)*(cell_d+marge_cell)
            circles_air.append(plt.Circle((x, y), r_air, color=colors[color_air]))
            circles_cell.append(plt.Circle((x, y), r, color=colors[color_cell]))
            circles_cell.append(plt.Circle((x, y), r, color="black", fill = False))
    
    fig, ax = plt.subplots() # note we must use plt.subplots, not plt.subplot
    ax.set_xlim([0, longueur_tot])
    ax.set_ylim([0, largeur_tot])
    for x in circles_air:
        ax.add_patch(x)
    for c in circles_cell:
        ax.add_patch(c)
    plt.show()

def animate(frame,axes,frames,tini,tfin):
    t= math.floor(tini/dt + frame/frames*(tfin-tini)/dt)
    circles_cell=[]
    circles_air=[]
    texts=[]
    colors=["blue","cyan","lawngreen","yellow","orange","red","darkred"]
    r = cell_d/2
    r_air = math.sqrt(air_V/cell_h/math.pi)
    for i in range(serie):
        for j in range(parallele):
            temp_air=air_temp[i][j][t]
            temp_cell=cell_temp[i][j][t]
            color_air=0*(temp_air<20)+1*(20<=temp_air<30)+2*(30<=temp_air<40)+3*(40<=temp_air<50)+4*(50<=temp_air<55)+5*(55<=temp_air<60)+6*(60<=temp_air)
            color_cell=0*(temp_cell<20)+1*(20<=temp_cell<30)+2*(30<=temp_cell<40)+3*(40<=temp_cell<50)+4*(50<=temp_cell<55)+5*(55<=temp_cell<60)+6*(60<=temp_cell)
            y = (parallele-j-1+1/2+1/2*(i%2))*(cell_d+marge_cell)
            x = (i*math.cos(30 * math.pi / 180)+1/2)*(cell_d+marge_cell)
            circles_air.append(plt.Circle((x, y), r_air, color=colors[color_air]))
            circles_cell.append(plt.Circle((x, y), r, color=colors[color_cell]))
            circles_cell.append(plt.Circle((x, y), r, color="black", fill = False))
            texts.append([x,y,str(round(temp_cell,1))])

    axes.clear()
    axes.set_xlim([0, longueur_tot])
    axes.set_ylim([0, largeur_tot])
    for x in circles_air:
        axes.add_patch(x)
    for c in circles_cell:
        axes.add_patch(c)
    for tex in texts:
        plt.text(tex[0],tex[1],tex[2],horizontalalignment='center',verticalalignment='center')
    plt.title("Temps : {}s".format(str(int(t*dt))))

def create_animation(tini,tfin,frames=150,fps=15):
    fig, ax = plt.subplots(figsize=(int(5*longueur_tot/largeur_tot),5)) # note we must use plt.subplots, not plt.subplot
    cmap = (mpl.colors.ListedColormap(["cyan","lawngreen","yellow","orange","red"]).with_extremes(under="blue", over="darkred"))
    bounds = [20, 30, 40, 50, 55, 60]
    norm = mpl.colors.BoundaryNorm(bounds, cmap.N)
    mpl.rcParams['font.size']=12
    fig.colorbar(
        mpl.cm.ScalarMappable(cmap=cmap, norm=norm),
        ax=ax,
        orientation='vertical',
        extend='both',
        spacing='proportional',
        label='Températures des cellules et de l\'air (°C)',
    )
    ani = animation.FuncAnimation(fig, partial(animate,axes=ax,frames=frames,tini=tini,tfin=tfin), frames=frames)
    ani.save('module.gif', fps=fps)
    plt.show()