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
cell_I = 20 #A (courant traversant chaque cellule)
Q = cell_R * cell_I**2 # W (puissance issue de l'effet Joule)

# Configuration
serie = 12 # (nombre de cellule en série)
parallele = 5 # (nombre de cellule en parallèle)
marge_cell = 4e-3 # m (marge à rajouter au diametre de cellule)

largeur_tot = (parallele + 1/2) * (cell_d + marge_cell)
longueur_tot = (cell_d + marge_cell) * math.cos(30 * math.pi / 180) * (serie - 1) + (cell_d + marge_cell)

cell_largeur = largeur_tot
cell_longueur = longueur_tot
air_V = math.pi*((cell_d+marge_cell)/2)**2*cell_h-cell_V

# Paramètre ventilo
P = 3 # W (puissance ventilateur)
Qv= 115 # m³/h (débit)
Cv_air = 0.34 # Wh/m³/K
v_air = 20 # m/s (vitesse de l'air)

cp_air = 1001.2 # J/kg/K (chaleur spécifique air)
l_c = 123e-3 # m (largeur conduite)
kin_viscosity=15.6e-6 # m²/s (viscosité cinématique)

# Paramètre busbar cuivre
cp_cuivre = 385 #J/kg/K (chaleur spécifique cuivre)
resi_cuivre = 20e-9 #Ohm m (résistivité cuivre à 60°C)
rho_cuivre = 8960 #kg/m³ (densité volumique cuivre)


# Paramètre de simulation
T_ini = 20. #°C (température initiale air)
t_final = 500 # s (temps d'arrêt de la simulation)
N = 50000 # (nombre de point de la simulation)
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

def air_thermal_conductivity(T): #http://bouteloup.pierre.free.fr/lica/phythe/don/air/air_k_plot.pdf
    Tf=T+273.15
    return 1.5207E-11*Tf**3 - 4.8574E-08*Tf**2 + 1.0184E-04*Tf - 3.9333E-04

def air_density(T):
    Tf = T+273.15
    return 1013*10*2/(287.0500676*Tf)

def Pr_air(T): #https://en.wikipedia.org/wiki/Prandtl_number
    return 10**9/(1.1*T**3-1200*T**2+322000*T+1.393*10**9)

def area_busbar(T,t):
    return parallele*cell_I*math.sqrt(resi_cuivre*t/(cp_cuivre*rho_cuivre*(T-T_ini)))

# def Ra(T,L):
#     Tf=(T+T_air)/2+273.15
#     return 9.81/Tf/kin_viscosity**2*(T-T_air)*L**3*Pr_air(Tf)

def Re(v,L):
    return v*L/kin_viscosity

def heat_transfer_coeff(v,T,L): #Dittus–Boelter equation
    Nu = 0.023*np.abs(Re(v,L))**(0.8)*np.abs(Pr_air(T))**0.4
    return Nu * air_thermal_conductivity(T)/L


# def heat_transfer_coeff(T,L):
#     Tf=(T+T_air)/2+273.15
#     Ray=Ra(T,L)
#     Pra=Pr_air(Tf)
#     k = air_thermal_conductivity(Tf)
#     return k/L*(0.825+0.387*Ray**(1/6)/(1+(0.492/Pra)**(9/16))**(8/27))**2
Prise en compte débit massique !
for k in range(N-1):
    for x in range(serie):
        for y in range(parallele):
            deltaS = entropy(0.8)
            T_cell=cell_temp[x][y][k]
            if x==0:
                v_air=Qv/largeur_tot/cell_h/3600
                L=l_c
                T_air=T_ini
            else:
                v_air=Qv/(largeur_tot*cell_h-cell_d*parallele*cell_h)/3600
                L=largeur_tot-cell_d*parallele
                T_cell_left=cell_temp[x-1][y][k]
                T_air_left=air_temp[x-1][y][k]
                if x%2==0:
                    if y==parallele-1:
                        T_cell_second_left=cell_temp[x-2][y][k]
                        T_air_second_left=air_temp[x-2][y][k]
                    else :
                        T_cell_second_left=cell_temp[x-1][y+1][k]
                        T_air_second_left=air_temp[x-1][y+1][k]
                else:
                    if y==0:
                        if x==1:
                            T_cell_second_left=T_ini
                            T_air_second_left=T_ini
                        else:
                            T_cell_second_left=cell_temp[x-2][y][k]
                            T_air_second_left=air_temp[x-2][y][k]
                    else :
                        T_cell_second_left=cell_temp[x-1][y-1][k]
                        T_air_second_left=air_temp[x-1][y-1][k]
                coeff_left=heat_transfer_coeff(v_air,T_air_left,L)*cell_S/air_density(T_air_left)/heat_spec_capacity(T_air_left)/cell_V*(T_cell_left-T_air_left)*dt
                coeff_second_left=heat_transfer_coeff(v_air,T_air_second_left,L)*cell_S/air_density(T_air_second_left)/heat_spec_capacity(T_air_second_left)/cell_V*(T_cell_second_left-T_air_second_left)*dt
                # print(heat_transfer_coeff(v_air,T_air_left,L),air_density(T_air_left),heat_spec_capacity(T_air_left),(T_cell_left-T_air_left),coeff_left)
                T_air = 0.5*(T_air_left+T_air_second_left+coeff_left+coeff_second_left)
            h = heat_transfer_coeff(v_air,T_air,L)
            cell_temp[x][y][k+1]=T_cell+dt*equation(h,deltaS,T_cell,T_air)
            air_temp[x][y][k+1]=T_air
    t.append(dt*k)

def print_temp(t):
    for x in range(parallele):
        string= ""
        for y in range(serie):
            string=string+str(cell_temp[y][x][t])+" - "
        print(string)

def print_air_temp(t):
    for x in range(parallele):
        string= ""
        for y in range(serie):
            string=string+str(air_temp[y][x][t])+" - "
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
    r_air = math.sqrt((air_V+cell_V)/cell_h/math.pi)
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
    texts_air=[]
    colors=["blue","cyan","lawngreen","yellow","orange","red","darkred"]
    r = cell_d/2
    r_air = math.sqrt((air_V+cell_V)/cell_h/math.pi)
    for i in range(serie):
        for j in range(parallele):
            temp_air=air_temp[i][j][t]
            temp_cell=cell_temp[i][j][t]
            color_air=0*(temp_air<T_ini)+1*(T_ini<=temp_air<30)+2*(30<=temp_air<40)+3*(40<=temp_air<50)+4*(50<=temp_air<55)+5*(55<=temp_air<60)+6*(60<=temp_air)
            color_cell=0*(temp_cell<T_ini)+1*(T_ini<=temp_cell<30)+2*(30<=temp_cell<40)+3*(40<=temp_cell<50)+4*(50<=temp_cell<55)+5*(55<=temp_cell<60)+6*(60<=temp_cell)
            y = (parallele-j-1+1/2+1/2*(i%2))*(cell_d+marge_cell)
            x = (i*math.cos(30 * math.pi / 180)+1/2)*(cell_d+marge_cell)
            circles_air.append(plt.Circle((x, y), r_air, color=colors[color_air]))
            circles_cell.append(plt.Circle((x, y), r, color=colors[color_cell]))
            circles_cell.append(plt.Circle((x, y), r, color="black", fill = False))
            texts.append([x,y,str(round(temp_cell,1))])
            texts_air.append([x,y,str(round(temp_air,1))])

    axes.clear()
    axes.set_xlim([0, longueur_tot])
    axes.set_ylim([0, largeur_tot])
    for x in circles_air:
        axes.add_patch(x)
    for c in circles_cell:
        axes.add_patch(c)
    for tex in texts:
        plt.text(tex[0],tex[1],tex[2],horizontalalignment='center',verticalalignment='bottom')
    for tex in texts_air:
        plt.text(tex[0],tex[1],tex[2],horizontalalignment='center',verticalalignment='top',fontsize=10)
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