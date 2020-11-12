%Attention ce script donne une valeur moins pr�cise de l'�nergie que
%l'application, en effet cette derni�re prend en compte le fait que sur la
%plupart des tours de l'endurance la voiture ne part pas avec une vitesse
%nulle. 

%Script d'�tude de sensibilit� sur l'autoX
addpath(genpath('.\subfunctions'))

%- Rentrez le path de votre fichier v�hicule de base :
%- Attention � enregistrer le param�tre d'origine !!
Paramfile = 'C:\Users\Bob\Documents\EPSA\Modeles-EPSA\01_Vehicle Dynamic\LapTime\Vehicules\Valkyriz_accel.mat'; %<-- � modifier

%- Rentrer le path du track :
trackfile = 'C:\Users\Bob\Documents\EPSA\Modeles-EPSA\01_Vehicle Dynamic\LapTime\Tracks\FSATA_track_elec.mat';
m = matfile(Paramfile,'Writable',true);

start = 2; %<-- � modifier
step = 0.2; %<-- � modifier
End = 2; %<-- � modifier

L = start:step:End;
T = [];
E = [];
for param=L
    %noter le nom du param�tre � �tudier apr�s m. , voir le fichier
    %param.txt dans le dossier subfunctions
    % Attention si ce param�tre et relier � une relation ( ex masse
    % v�hicule reli� � la masse totale et � l ahauteur du COG) il faut
    % retaper la relation avec m. devant le nom des variables
    m.k_f = 1/param;  %<-- � modifier
    [V,Gx,Gy,time,D,GGV] = LapTime(trackfile,Paramfile,0);
    [~,e,~,~] = get_Pelec(V*3.6,Gx,time,Paramfile,24,0);
    T = [T,time(end)];  
    E = [E,e];
    disp(length(T))
end

figure(1)
plot(L,T)
% Changer les titres des axes et du graphique
title('Etude de sensitivit� du rapport de r�duction')
xlabel('Rapport de r�duction')
ylabel('AutoX time (s)')

figure(2)
plot(L,E/3600/1000)
% Changer les titres des axes et du graphique
title('Etude de sensitivit� du rapport de r�duction')
xlabel('Rapport de r�duction')
ylabel("Energie utilis� sur l'autoX (kWh)")