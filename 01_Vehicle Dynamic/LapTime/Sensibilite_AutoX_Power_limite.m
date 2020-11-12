%Attention ce script donne une valeur moins précise de l'énergie que
%l'application, en effet cette dernière prend en compte le fait que sur la
%plupart des tours de l'endurance la voiture ne part pas avec une vitesse
%nulle. 

%Script d'étude de sensibilité sur l'autoX
addpath(genpath('.\subfunctions'))

%- Rentrez le path de votre fichier véhicule de base :
%- Attention à enregistrer le paramètre d'origine !!
Paramfile_1 = 'C:\Users\Bob\Documents\EPSA\Modeles-EPSA\01_Vehicle Dynamic\LapTime\Vehicules\Valkyriz_accel.mat'; %<-- à modifier
copyfile(Paramfile_1,'.\temp.mat');
Paramfile_temp = '.\temp.mat';

%- Rentrer le path du track :
trackfile = 'C:\Users\Bob\Documents\EPSA\Modeles-EPSA\01_Vehicle Dynamic\LapTime\Tracks\FSATA_track_elec.mat';
m = matfile(Paramfile_temp,'Writable',true);

start = 30000; %<-- à modifier
step = 10000; %<-- à modifier
End = 80000; %<-- à modifier

load(Paramfile_temp,'rmot','cmot','efficiency','eff_cont')
L = start:step:End;
T = [];
E = [];
for param=L
    %noter le nom du paramètre à étudier après m. , voir le fichier
    %param.txt dans le dossier subfunctions
    % Attention si ce paramètre et relier à une relation ( ex masse
    % véhicule relié à la masse totale et à l ahauteur du COG) il faut
    % retaper la relation avec m. devant le nom des variables
    
    m.cmot = power_limit_torque(rmot,cmot,param,efficiency,eff_cont);  %<-- à modifier
    [V,Gx,Gy,time,D,GGV] = LapTime(trackfile,Paramfile_temp,0);
    [~,e,~,~] = get_Pelec(V*3.6,Gx,time,Paramfile_temp,24,0);
    T = [T,time(end)];  
    E = [E,e];
    disp(length(T))
end

delete(Paramfile_temp)

figure(1)
plot(L/1000,T)
yyaxis left
% Changer les titres des axes et du graphique
title('Etude de sensitivité du rapport de réduction')
xlabel('Puissance max en sortie de batterie (kW)')
ylabel('AutoX time (s)')
hold on
yyaxis right
plot(L/1000,E/3600/1000)
% Changer les titres des axes et du graphique
ylabel("Energie utilisé sur l'endurance (kWh)")