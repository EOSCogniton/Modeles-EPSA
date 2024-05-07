### Ce programme a pour but de calculer les températures des différentes
### cellules composants un module. Il peut évidemment être amélioré.

import math
import matplotlib.pyplot as plt 
# Paramètre de la cellule
cell_h = 65e-3  # m (hauteur)
cell_d = 18.4e-3  # m (diamètre)
cell_R = 18e-3 # Ohm (résistance interne)
cell_m = 45e-3 # kg (masse) 

cell_S = cell_h *2* math.pi *cell_d/2 # m² (surface de contact à l'air)
cell_V = cell_d/2 * cell_S #m³ (volume)

cell_rho = cell_m/cell_V

F = 96485 # C/mol (Constante de Faraday)
e=1.6e-19 # C

cell_I = 15 #A (courant traversant chaque cellule)

Q = cell_R * cell_I**2 # W (puissance issue de l'effet Joule)

# Configuration
serie = 12 # (nombre de cellule en série)
parallele = 5 # (nombre de cellule en parallèle)

# Paramètre ventilo
P = 50 # W (puissance ventilateur)
Qv= 1 # m³/h (débit)
Cv_air = 0.34 # Wh/m³/K
v_air = 20 # m/s (vitesse de l'air)
cp_air = 1003.5 # J/kg/K (chaleur spécifique air)
l_c = 50e-3 # m (largeur conduite)
kin_viscosity=15.6e-6 # m²/s (viscosité cinématique)

T_ini = 20 #°C (température initiale air)

t_final = 1800 # s (temps d'arrêt de la simulation)
N = 100000 # (nombre de point de la simulation)
dt = t_final/N

T_air = T_ini

T=[T_ini]
t=[0]

def newton(c): # (wikipedia, newton coefficient)
    return 10.45 - c + 10 * math.sqrt(c)

def entropy(SOC): #https://iopscience.iop.org/article/10.1088/1757-899X/53/1/012014/pdf
    return -179*SOC**2+274.29*SOC-116

def heat_spec_capacity(T): #https://www.sciencedirect.com/science/article/pii/S1359431123012413
    return 2.08*T+812.16

def equation(h,deltaS,T):#https://www.sciencedirect.com/science/article/pii/S0378775305013054#eq3
    return (Q+deltaS*cell_I/F*T-h*cell_S*(T-T_air))/(cell_m*heat_spec_capacity(T))

# def air_thermal_conductivity(T): #http://bouteloup.pierre.free.fr/lica/phythe/don/air/air_k_plot.pdf
#     return 1.5207E-11*T**3 - 4.8574E-08*T**2 + 1.0184E-04*T - 3.9333E-04

# def air_density(T):
#     return 1013*10*2/(287.0500676*T)

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
    h = newton(v_air)
    deltaS = entropy(0.8)
    T_act=T[k]
    T.append(T_act+dt*equation(h,deltaS,T_act))
    t.append(dt*k)

plt.plot(t,T)
plt.show()