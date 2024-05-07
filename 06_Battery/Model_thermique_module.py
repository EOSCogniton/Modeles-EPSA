### Ce programme a pour but de calculer les températures des différentes
### cellules composants un module. Il peut évidemment être amélioré.

import math
# Paramètre de la cellule
cell_h = 65  # mm (hauteur)
cell_d = 18.4  # mm (diamètre)
cell_R = 18e-3 # Ohm (résistance interne)
cell_m = 45e-3 # kg (masse) 

cell_S = (cell_d/2)**2 * math.pi # m² (surface de contact à l'air)
cell_V = cell_h * cell_S #m³ (volume)

cell_rho = cell_m/cell_V

Cp = 1000 # J/kg/K (Chaleur spécifique, à voir)
nF = 96485 # C/mol (Constante de Faraday)

cell_I = 20 #A (courant traversant chaque cellule)

Q = cell_R * cell_I**2 # W (puissance issue de l'effet Joule)

# Configuration
serie = 12 # (nombre de cellule en série)
parallele = 5 # (nombre de cellule en parallèle)

# Paramètre ventilo
P = 50 # W (puissance ventilateur)
Qv= 1 # m³/h (débit)
Cv_air = 0.34 # Wh/m³/K
v_air = 10 # m/s (vitesse de l'air)

T_ini = 20 #°C (température initiale air)

t_final = 100 # s (temps d'arrêt de la simulation)
N = 10000 # (nombre de point de la simulation)
dt = t_final/N

T_air = T_ini

T=[T_ini]

def newton(c): # (wikipedia, newton coefficient)
    return 10.45 - c + 10 * math.sqrt(c)

def entropy(SOC): #https://iopscience.iop.org/article/10.1088/1757-899X/53/1/012014/pdf
    return -179*SOC**2+274.29*SOC-116

for k in range(N-1):
    h = newton(v_air)
    deltaS = entropy(1)

    # https://iopscience.iop.org/article/10.1088/1757-899X/53/1/012014/pdf
    T.append(dt/(cell_m*Cp) * (Q+T[k]*deltaS*cell_I/nF-h*cell_S*(T[k]-T_air))+T[k])
    print(T[-1])