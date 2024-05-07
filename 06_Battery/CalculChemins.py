import copy as cop
import math
import numpy as np
import matplotlib.pyplot as plt
import json
from time import time


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

def facto(n):
    if n==0 or n==1:
        return 1
    else:
        return n*facto(n-1)

N = 12

try :
    f = open('chemins.json')
    
    # returns JSON object as 
    # a dictionary
    data = json.load(f)
    
    # Iterating through the json
    # list

    f.close()
except:
    data={}

p=len(data)
if p < N :
    for i in range(p+1,N+1):
        t=time()
        a=b=nb_points=i
        c=0
        listes=connexes(a,b,c,nb_points)
        data[str(i)]=listes
        with open('chemins.json', 'w') as f:
            json.dump(data, f)
        print("\n",time()-t," - ", i)
        t=time()
for i in range(1,len(data)+1):
    print(len(data[str(i)]))
