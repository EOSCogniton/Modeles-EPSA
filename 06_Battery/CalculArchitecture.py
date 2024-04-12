### Calculs des caractéristiques nécessaires en puissance, couple, courant,
### tension, et architecture pour atteindre certaines performances avec la
### voiture

# Ce script est utile pour déterminer l'architecture batterie minimale 
# pour atteindre certaines performances

# Les courbes de tensions/courants et puissance/couple nécessaire en fonction
# de la vitesse sont accessible via un matlab appelé "BatterySpec.m"


## Paramètres
# Paramètres du programme
t = 10  # s (temps visé pour passer de 0 à v km/h)
v = 20 # km/h (vitesse qui sera utilisé pour les calculs d'optimisation de volume)
module_max = 7 # Nombre de modules maximum, nécessaire tant qu'on n'a pas optimisé le programme

dict_mode = {'d':'debouts','c':'de côté','p':'à plat'} # d,c,p pour debout, couché, à plat (orientation des modules pour les calculs)
dict_orientation = {'l':'largeur','L':'longueur'} # L ou l pour orienté selon la Longueur ou la largeur


# Paramètres de la cellule
cell_A = 10  # A (décharge en pic)
cell_V_max = 4.2 # V (Tension maximale après charge) 
cell_V = 3.6  # V (Tension nominale)
cell_V_cutoff = 2.5 # V (Tension minimale à la décharge)
cell_C = 2500 # mAh (Capacité de la cellule)
cell_h = 65  # mm (hauteur)
cell_d = 18.4  # mm (diamètre)
cell_E = cell_V*cell_C*10**(-3)/3600

# Marges pour module
marge_trou = 3  # mm (On ajoute x mm au diamètre pour être sûr que ça rentre bien)
marge_largeur = 1  # mm (Marges latérales avant et après une parallèle de cellule)
marge_longueur = 3  # mm (Marges en longueur avant et après une série de cellule)
marge_hauteur = 2  # mm (Marge pour rajouter une plaque en hauteur)
marge_BMS = 10  # mm (Marge à rajouter pour contenir le BMS du module)
separation = 10 # mm (Epaisseur de la séparation entre chaque module)
hauteur = cell_h + marge_hauteur * 2 + separation

# Limitations modules
module_V_max = 60 # V (Tension maximale d'un module)
module_E_max = 1*10**6 # J (Energie maximale d'un module)

# Paramètres Batterie
largeur_b = 455 # mm (de bord à bord)
longueur_b = 370 # mm (du devant à l'arrière)
hauteur_b = 200 # mm (hauteur)

V_LV_tyva=440*280*80 # mm³ (Volume utilisé chez Tyva pour la LV)
largeur_lv = 140+10 # mm (Ce qu'on retire afin de caser les parties LV de la batterie)
longueur_lv = 10 # mm 
hauteur_lv = 10 # mm

largeur_util = largeur_b-largeur_lv # mm
longueur_util = longueur_b-longueur_lv # mm
hauteur_util = hauteur_b-hauteur_lv # mm

# Paramètres de la voiture
Z_roue = 42
Z_motor = 13
gear_ratio = Z_motor / Z_roue
m_v = 230  # kg (masse à vide)
mp = 80  # kg (masse pilote)
m = m_v + mp  # kg (masse totale)
D_roue = 0.52  # m (diamètre extérieur de la roue)
L = 75  # m (Longueur de la piste)
v_th = L / t * 2 * 3.6  # juste pour info
NmA = 0.75  # N.m/Aph (Torque par ampère)
mot_eff = 0.95 # (Efficacité du moteur)

SCx = 0.66 # m² (Issu des essais d'invictus, à redémontrer via simulation)
rho_a = 1.225 # kg/m³ (Densité de l'air)

mu_roll = 0.02 # (arbitraire, à déterminer avec nos pneus)

Sf = 1.5 # (Safety factor, pour prendre des marges)

g=9.81 # m/s² (accélération terrestre)


import copy as cop
import math
import numpy as np
import matplotlib.pyplot as plt



## Fonctions
def calcul_largeur(p):
    return (p + 1/2) * (cell_d + marge_trou) + marge_largeur * 2 + separation

def calcul_longueur(s):
    return (cell_d + marge_trou) * math.cos(30 * math.pi / 180) * (s - 1) + (cell_d + marge_trou) + 2 * marge_longueur + marge_BMS + separation

def comp(x,y):
    if x == y:
        return(True)
    if x[0]>y[0]: 
        return(True)
    if x[0]<y[0]: 
        return(False)
    if x[0]==y[0]:
        if x[1]>y[1]: 
            return(True)
        if x[1]<y[1]: 
            return(False)
        if x[1] == y[1]:
            if x[2]>y[2]: 
                return(True)
            if x[2]<y[2]: 
                return(False)
    
def transfo(x,y,z,t):
    return(x+t[0], y+t[1], z+t[2])

def ajout_point(chemins,a,b,c,nb_points):
    res = []
    transformations = [[1,0,0], [0,1,0], [0,0,1],[-1,0,0], [0,-1,0], [0,0,-1]]
    for chem in chemins:
        if len(chem) < nb_points:
            for k in range (len(chem)):
                x, y, z = chem[k]
                for t in transformations:
                    chem2 = cop.deepcopy(chem)
                    T = transfo(x,y,z,t)
                    #print(T)
                    if T[0]<=a and T[1]<=b and T[2]<=c and T[0]>=0 and T[1]>=0 and T[2]>=0:
                        #print('oui')
                        if T not in chem:
                            #print('aaa')
                            chem2.append(T)
                            tr = sorted(chem2)
                            res.append(tr)                 
    
    res2 = []
    for truc in res:
        if truc not in res2:
            res2.append(truc)              
    return(res2)
        

def connexes(a,b,c,nb_points):
    chemins = [[(0,0,0)]]
    for _ in range(nb_points-1):
        chemins = ajout_point(chemins,a,b,c,nb_points)
    tr = sorted(chemins)
    res = []
    for truc in tr:
        if truc not in res:
            res.append(truc)
    return(res)

def calcul_v(chemin,larg,long,haut):
    chem=np.array(chemin)
    xmax=max(chem[:,0])+1
    ymax=max(chem[:,1])+1
    zmax=max(chem[:,2])+1
    return xmax*larg*ymax*long*zmax*haut,xmax*larg,ymax*long,zmax*haut

def minimal_v(all_chemins,larg,long,haut):
    mini=calcul_v(all_chemins[0],larg,long,haut)
    mini_c=all_chemins[0]
    indi=0
    for i in range(len(all_chemins)):
        v=calcul_v(all_chemins[i],larg,long,haut)
        if v[0]<mini[0]:
            mini=v
            mini_c=all_chemins[i]
            indi=i
    return mini,mini_c,indi

def final_minimal_v(all_chemins):
    mini=calcul_v(all_chemins[0][0],all_chemins[0][1],all_chemins[0][2],all_chemins[0][3])
    mini_c=all_chemins[0]
    indi=0
    for i in range(len(all_chemins)):
        v=calcul_v(all_chemins[i][0],all_chemins[i][1],all_chemins[i][2],all_chemins[i][3])
        if v[0]<mini[0]:
            mini=v
            mini_c=all_chemins[i]
            indi=i
    return mini,mini_c,indi


## Début des calculs

a = v / t / 3.6

Fair=SCx * 1/2 * rho_a * (1/3.6)*v**2
Froll=mu_roll*m*g
Facc = m * a
F = Sf*(Facc + Fair + Froll)

w_t = F * D_roue / 2  # N.m (Wheel torque)
m_t = w_t * gear_ratio  # N.m (motor torque needed)
m_I = m_t / NmA  # A (courant nécessaire par phase)
w_s = v / D_roue * 2  # rad/s (vitesse de rotation des roues à v)
m_s = w_s / gear_ratio  # rad/s (vitesse moteur)
Pnec = m_s * m_t   # W Puissance totale en sortie du moteur nécessaire
Vnec = Pnec / m_I / np.sqrt(3) / mot_eff  # V Tension en sortie de batterie nécessaire
n_v_cell = np.ceil(Vnec / cell_V_cutoff)  # nombre de cellule nécessaire en série
n_a_cell = np.ceil(m_I / cell_A)  # nombre de cellule nécessaire en parallèle

# Affichage des résultats
print('Temps : {} s'.format(t))
print('Vitesse pour optimisation volume : {} km/h'.format(v))

p=int(n_a_cell)
smax=int(n_v_cell)

modes=["d","c","p"]
orientations=['l','L']

minichem=[]
result_cara=[]
for mode in modes:
    for orientation in orientations:
        for m in range(1,module_max+1):
            s=int(np.ceil(smax/m))
            if s*p*cell_E <= module_E_max and s*cell_V_max <= module_V_max:  
                if mode == "d" and orientation == 'L':
                    largeur_mod=hauteur
                    longueur_mod=calcul_largeur(p)
                    hauteur_mod=calcul_longueur(s)
                elif mode == "d" and orientation == 'l':
                    largeur_mod=calcul_largeur(p)
                    longueur_mod=hauteur
                    hauteur_mod=calcul_longueur(s)
                elif mode == "p" and orientation =='L':
                    largeur_mod=calcul_largeur(p)
                    longueur_mod=calcul_longueur(s)
                    hauteur_mod=hauteur
                elif mode == "p" and orientation =='l':
                    largeur_mod=calcul_longueur(s)
                    longueur_mod=calcul_largeur(p)
                    hauteur_mod=hauteur
                elif mode == "c" and orientation == 'L':
                    largeur_mod=hauteur
                    longueur_mod=calcul_longueur(s)
                    hauteur_mod=calcul_largeur(p)
                else:
                    largeur_mod=calcul_longueur(s)
                    longueur_mod=hauteur
                    hauteur_mod=calcul_largeur(p)

                a = int(largeur_util/largeur_mod)-1
                b = int(longueur_util/longueur_mod)-1
                c = min(0,int(hauteur_util/hauteur_mod)-1)
                
                nb_points=m
                # print(a,b,c,m)
                if (a+1)*(b+1)*(c+1)>=m:
                    L = connexes(a,b,c,nb_points)
                    # print('')
                    # print('')
                    # print('')
                    # print(L)
                    # print(len(L))
                    res=minimal_v(L,largeur_mod,longueur_mod,hauteur_mod)
                    # print(res[0],res[1])
                    minichem.append([res[1],largeur_mod,longueur_mod,hauteur_mod])
                    result_cara.append([res[0],s,p,m,mode,orientation])

print("")
try : 
    resfinal = final_minimal_v(minichem)
    r=result_cara[resfinal[2]]
    print("Architecture finale en {}s{}p, avec {} modules.".format(r[1],r[2],r[3]))
    print("Tension de la batterie : {} V nominal, {} V maximum, {} V minimum.".format(round(r[1]*cell_V*r[3],1),round(r[1]*cell_V_max*r[3],1),round(r[1]*cell_V_cutoff*r[3],1)))
    print("Courant maximal en sortie : {} A.".format(round(r[2]*cell_A,1)))
    print("Dimensions d'un module : {} x {} x {} mm (lxLxh), pour une tension de {} V nominal, {} V max, {} V min.".format(int(calcul_largeur(r[2])),int(calcul_longueur(r[1])),int(hauteur-separation),round(r[1]*cell_V,1),round(r[1]*cell_V_max,1),round(r[1]*cell_V_cutoff,1)))
    print("Les modules sont placés {}, dans le sens de la {}, selon les coordonnées suivantes : {}".format(dict_mode[r[4]],dict_orientation[r[5]],resfinal[1][0]))
    print("Ils occupent une enveloppe totale de {} L, avec comme point en extrémité de l'enveloppe : ({},{},{})".format(round(r[0][0]*10**(-6),2),int(r[0][1]),int(r[0][2]),int(r[0][3])))

except:
    print("Impossible d'atteindre une telle vitesse avec si peu d'espace !")
