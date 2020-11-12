%Attention ce script donne une valeur moins pr�cise de l'�nergie que
%l'application, en effet cette derni�re prend en compte le fait que sur la
%plupart des tours de l'endurance la voiture ne part pas avec une vitesse
%nulle. 

%Script d'�tude de sensibilit� sur l'autoX
addpath(genpath('.\subfunctions'))

%- Rentrez le path de votre fichier v�hicule de base :

Paramfile_1 = '.\Vehicules\Valkyriz_accel.mat'; %<-- � modifier
copyfile(Paramfile_1,'.\temp.mat');
Paramfile_temp = '.\temp.mat';

%- Rentrer le path du track :
trackfile = '.\Tracks\FSATA_track_elec.mat';
nb_de_tour = 24; %<-- � modifier

m = matfile(Paramfile_temp,'Writable',true);

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
    [V,Gx,Gy,time,D,GGV] = LapTime(trackfile,Paramfile_temp,0);
    [~,e,~,~] = get_Pelec(V*3.6,Gx,time,Paramfile_temp,nb_de_tour,0);
    T = [T,time(end)];  
    E = [E,e];
    disp(length(T))
end

delete(Paramfile_temp)
figure(1)

figure(1)
plot(L,T)
yyaxis left
% Changer les titres des axes et du graphique
title('Etude de sensitivit� du rapport de r�duction')
xlabel('rapport de r�duction')
ylabel('AutoX time (s)')
hold on
yyaxis right
plot(L,E/3600/1000)
% Changer les titres des axes et du graphique
ylabel("Energie utilis� sur l'autoX (kWh)")