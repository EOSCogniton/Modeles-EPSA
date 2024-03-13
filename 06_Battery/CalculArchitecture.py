### Calculs des caractéristiques nécessaires en puissance, couple, courant,
### tension, et architecture pour atteindre certaines performances avec la
### voiture

# Ce script est utile pour déterminer le couple et la puissance moteur
# nécessaires pour atteindre certaines performances


## Paramètres
# Paramètres du programme
v_max = 100  # km/h (vitesse maximale pour les courbes)
v_min = 1 # km/h (vitesse minimale pour les courbes)
pas_v = 1  # km/h (vitesse entre chaque point de la courbe)
t = 10  # s (temps visé pour passer de 0 à v km/h)

v_calcul = 30 # km/h (vitesse qui sera utilisé pour les calculs d'optimisation de volume)
module_max = 7 # Nombre de modules maximum, nécessaire tant qu'on a pas optimisé le programme


dict_mode = {'d':'debouts','c':'de côté','p':'à plat'} # d,c,p pour debout, couché, à plat (orientation des modules pour les calculs)
dict_orientation = {'l':'largeur','L':'longueur'} # L ou l pour orienté selon la Longueur ou la largeur


# Paramètres de la cellule
cell_A = 10  # A (décharge en pic)
cell_V = 3.6  # V (Tension nominale)
cell_C = 3000 # mAh (Capacité de la cellule)
cell_h = 65  # mm (hauteur)
cell_d = 18.5  # mm (diamètre)
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
module_V_max = 120 # V (Tension maximale d'un module)
module_E_max = 1*10**6 # J (Energie maximale d'un module)

# Paramètres Batterie
largeur_b = 430 # mm (de bord à bord)
longueur_b = 320 # mm (du devant à l'arrière)
hauteur_b = 260 # mm (hauteur)

largeur_lv = 150 # mm (Ce qu'on retire afin de caser les parties LV de la batterie)
longueur_lv = 0 # mm 
hauteur_lv = 0 # mm

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

def ajout_point(chemins):
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
        chemins = ajout_point(chemins)
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

v = np.arange(v_min, v_max + 1, pas_v)
a = v / t / 3.6
F = m * a
w_t = F * D_roue / 2  # N.m (Wheel torque)
m_t = w_t * gear_ratio  # N.m (motor torque needed)
m_I = m_t / NmA  # A (courant nécessaire par phase)
w_s = v / D_roue * 2  # rad/s (vitesse de rotation des roues à v)
m_s = w_s / gear_ratio  # rad/s (vitesse moteur)
Pnec = m_s * m_t  # W Puissance totale nécessaire
Vnec = Pnec / m_I / np.sqrt(3)  # V Tension en sortie de batterie nécessaire
n_v_cell = np.ceil(Vnec / cell_V)  # nombre de cellule nécessaire en série
n_a_cell = np.ceil(m_I / cell_A)  # nombre de cellule nécessaire en parallèle

# Affichage des résultats
print('Temps (s) :', t)
print('Vitesse pour optimisation volume (km/h) :', v_calcul)

# Tracer des courbes
# fig, ax1 = plt.subplots()
# ax2 = ax1.twinx()
# ax1.plot(v, m_t, 'b', label='Couple (N.m)')
# ax2.plot(v, Pnec, 'r', label='Puissance (W)')
# ax1.set_ylabel('Couple (N.m)',color='b')
# ax2.set_ylabel('Puissance (W)',color='r')
# ax1.legend(loc='upper left')
# ax2.legend(loc='upper center')
# plt.title('Courbe de Couple/Puissance pour t= {}s'.format(t))
# ax1.set_xlabel('Vitesse de {} à {} km/h'.format(v_min,v_max))

# fig, ax1 = plt.subplots()
# ax2 = ax1.twinx()
# ax1.plot(v, Vnec, 'b', label='Tension (V)')
# ax2.plot(v, m_I, 'r', label='Courant (A)')
# ax1.set_ylabel('Tension (V)',color='b')
# ax2.set_ylabel('Courant (A)',color='r')
# ax1.legend(loc='upper left')
# ax2.legend(loc='upper center')
# plt.title('Courbe de courants/tensions pour t= {}s'.format(t))
# ax1.set_xlabel('Vitesse de {} à {} km/h'.format(v_min,v_max))

# fig, ax1 = plt.subplots()
# ax2 = ax1.twinx()
# ax1.plot(v, n_v_cell, 'b', label='Série')
# ax2.plot(v, n_a_cell, 'r', label='Parallèle')
# ax1.set_ylabel('Nombre de cellule en série',color='b')
# ax2.set_ylabel('Nombre de cellule en parallèle',color='r')
# ax1.legend(loc='upper left')
# ax2.legend(loc='upper center')
# plt.title('Besoin en cellule séries/parallèles pour t= {}s'.format(t))
# ax1.set_xlabel('Vitesse de {} à {} km/h'.format(v_min,v_max))
# plt.show()


vit_indice = int(np.ceil((v_calcul-v[0])/pas_v))

p=int(n_a_cell[vit_indice])
smax=int(n_v_cell[vit_indice])

modes=["d","c","p"]
orientations=['l','L']

minichem=[]
result_cara=[]
for mode in modes:
    for orientation in orientations:
        for m in range(1,module_max+1):
            s=int(np.ceil(smax/m))
            if s*p*cell_E <= module_E_max and s*cell_V <= module_V_max:  
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
                c = int(hauteur_util/hauteur_mod)-1
                
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
    print("Dimensions d'un module : {}x{}x{}mm (lxLxh), pour une tension de {}V.".format(int(calcul_largeur(r[2])),int(calcul_longueur(r[1])),int(hauteur-separation),r[1]*cell_V))
    print("Les modules sont placés {}, dans le sens de la {}, selon les coordonnées suivantes : {}".format(dict_mode[r[4]],dict_orientation[r[5]],resfinal[1][0]))
    print("Ils occupent une enveloppe totale de {}L, avec comme point en extrémité de l'enveloppe : ({},{},{})".format(round(r[0][0]*10**(-6),2),int(r[0][1]),int(r[0][2]),int(r[0][3])))

except:
    print("Impossible d'atteindre une telle vitesse avec si peu d'espace !")
