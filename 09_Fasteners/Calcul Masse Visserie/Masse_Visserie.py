# -*- coding: utf-8 -*-
"""
Created on Mon May  3 10:47:31 2021

@author: MMA
"""
import csv
import pandas as pd
import sqlite3
import numpy as np

m_vol_acier = 7860 #kg/m^3

def Conversion(m):
    m1 = str(m).replace("m", " ")
    m2 = float(str(m1).replace(",", ".").rstrip())
    return m2

#Masse_Rondelles
conn = sqlite3.connect('CatalogueVisserie.sqlite')
c = conn.cursor()
c.execute("SELECT NAME, diametre_interieur, diametre_exterieur, epaisseur FROM 'Rondelles'")
R = c.fetchall()
conn.commit()
conn.close()

def Rondelles(m, L):
    n = len(L)
    M = []
    for i in range(n):
        d_int = Conversion(L[i][1])
        d_ext = Conversion(L[i][2])
        h = Conversion(L[i][3])
        V = h*np.pi*((d_ext/2)**2 - (d_int/2)**2)
        M.append([L[i][0], m*V])
    with open('Masse_Rondelles.csv', 'w') as csvfile: 
        csvwriter = csv.writer(csvfile) 
        csvwriter.writerow(['Name', 'Masse']) 
        csvwriter.writerows(M)
# Rondelles(m_vol_acier, R)

# #Masse_Ecrous
conn = sqlite3.connect('CatalogueVisserie.sqlite')
c = conn.cursor()
c.execute("SELECT NAME, diametreInterieur, hauteur, largeur FROM 'Ecrou'")
E = c.fetchall()
conn.commit()
conn.close()

def Ecrous(m, L):
    n = len(L)
    M = []
    for i in range(n):
        d_int = Conversion(L[i][1])
        larg = Conversion(L[i][2])
        h = Conversion(L[i][3])
        V = h*(((3*np.sqrt(3)/2)*12*(larg/np.sqrt(3))**2)-np.pi*(d_int/2)**2)
        M.append([L[i][0], m*V])
    with open('Masse_Ecrous.csv', 'w') as csvfile: 
        csvwriter = csv.writer(csvfile) 
        csvwriter.writerow(['Name', 'Masse']) 
        csvwriter.writerows(M)

# Ecrous(m_vol_acier, E)

# Masse_EcrouNS
conn = sqlite3.connect('CatalogueVisserie.sqlite')
c = conn.cursor()
c.execute("SELECT NAME, diametreInterieur, hauteur, largeur, diametreExterieur FROM 'EcrouNS'")
ENS = c.fetchall()
conn.commit()
conn.close()

def EcrousNS(m, L):
    n = len(L)
    M = []
    for i in range(n):
        d_int = Conversion(L[i][1])
        larg = Conversion(L[i][3])
        # d_ext = Conversion(L[i][4])
        h = Conversion(L[i][2])
        Vsup = (1/4)*np.pi*(larg/2 - 0.4*h)*(np.pi*(h*0.2)**2) + 0.2*h*np.pi*((larg/2 - 0.2*h)**2 - (d_int/2)**2)
        Vbase = 0.8*h*(((3*np.sqrt(3)/2)*(larg/np.sqrt(3))**2)-np.pi*(d_int/2)**2)
        M.append([L[i][0], m*(Vbase+Vsup)])
    with open('Masse_EcrousNS.csv', 'w') as csvfile: 
        csvwriter = csv.writer(csvfile) 
        csvwriter.writerow(['Name', 'Masse']) 
        csvwriter.writerows(M)

# EcrousNS(m_vol_acier, ENS)

# Masse_VisHexa
conn = sqlite3.connect('CatalogueVisserie.sqlite')
c = conn.cursor()
c.execute("SELECT NAME, diametreVis, Longueur, largeurTete, hauteurTete FROM 'VisHexa'")
Hexa = c.fetchall()
conn.commit()
conn.close()

def VisHexa(m, L):
    n = len(L)
    M = []
    for i in range(n):
        d_vis = Conversion(L[i][1])
        long = Conversion(L[i][2])
        LargTete = Conversion(L[i][3])
        hTete = Conversion(L[i][4])
        Vsup = hTete*(3*np.sqrt(3)/2)*(LargTete/np.sqrt(3))**2
        Vinf = long*np.pi*(d_vis/2)**2
        M.append([m*(Vsup + Vinf)])
    with open('Masse_VisHexa.csv', 'w') as csvfile: 
        csvwriter = csv.writer(csvfile) 
        csvwriter.writerow(['Name', 'Masse']) 
        csvwriter.writerows(M)

# VisHexa(m_vol_acier, Hexa)

# Masse_VisCHC
conn = sqlite3.connect('CatalogueVisserie.sqlite')
c = conn.cursor()
c.execute("SELECT NAME, diametreVis, Longueur, diametreTete, hauteurTete, LargeurEmpreinte  FROM 'VisCHC'")
CHC = c.fetchall()
conn.commit()
conn.close()

def VisCHC(m, L):
    n = len(L)
    M = []
    for i in range(n):
        d_vis = Conversion(L[i][1])
        long = Conversion(L[i][2])
        d_tete = Conversion(L[i][3])
        h_tete = Conversion(L[i][4])
        larg_trou = Conversion(L[i][5])
        Vinf = long*np.pi*(d_vis/2)**2
        Vsup = h_tete*np.pi*(d_tete/2)**2
        Vtrou = 0.7*h_tete*(3*np.sqrt(3)/2)*(larg_trou/np.sqrt(3))**2
        M.append([m*(Vsup + Vinf - Vtrou)])
    with open('Masse_VisCHC.csv', 'w') as csvfile: 
        csvwriter = csv.writer(csvfile) 
        csvwriter.writerow(['Name', 'Masse']) 
        csvwriter.writerows(M)

# VisCHC(m_vol_acier, CHC)