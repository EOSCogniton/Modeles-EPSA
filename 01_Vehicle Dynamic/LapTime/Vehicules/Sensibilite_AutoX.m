%Attention ce script donne une valeur moins précise de l'énergie que
%l'application, en effet cette dernière prend en compte le fait que sur la
%plupart des tours de l'endurance la voiture ne part pas avec une vitesse
%nulle. 

%Script d'étude de sensibilité sur l'autoX
addpath(genpath('.\subfunctions'))

%- Rentrez le path de votre fichier véhicule de base :
%- Attention à enregistrer le paramètre d'origine !!
Paramfile = 'C:\Users\Bob\Documents\EPSA\Modeles-EPSA\01_Vehicle Dynamic\LapTime\Vehicules\Valkyriz_accel.mat'; %<-- à modifier

%- Rentrer le path du track :
trackfile = 'C:\Users\Bob\Documents\EPSA\Modeles-EPSA\01_Vehicle Dynamic\LapTime\Tracks\FSATA_track_elec.mat';
m = matfile(Paramfile,'Writable',true);

start = 2; %<-- à modifier
step = 0.2; %<-- à modifier
End = 2; %<-- à modifier

L = start:step:End;
T = [];
E = [];
for param=L
    %noter le nom du paramètre à étudier après m. , voir le fichier
    %param.txt dans le dossier subfunctions
    % Attention si ce paramètre et relier à une relation ( ex masse
    % véhicule relié à la masse totale et à l ahauteur du COG) il faut
    % retaper la relation avec m. devant le nom des variables
    m.k_f = 1/param;  %<-- à modifier
    [V,Gx,Gy,time,D,GGV] = LapTime(trackfile,Paramfile,0);
    [~,e,~,~] = get_Pelec(V*3.6,Gx,time,Paramfile,24,0);
    T = [T,time(end)];  
    E = [E,e];
    disp(length(T))
end

figure(1)
plot(L,T)
% Changer les titres des axes et du graphique
title('Etude de sensitivité du rapport de réduction')
xlabel('Rapport de réduction')
ylabel('AutoX time (s)')

figure(2)
plot(L,E/3600/1000)
% Changer les titres des axes et du graphique
title('Etude de sensitivité du rapport de réduction')
xlabel('Rapport de réduction')
ylabel("Energie utilisé sur l'autoX (kWh)")