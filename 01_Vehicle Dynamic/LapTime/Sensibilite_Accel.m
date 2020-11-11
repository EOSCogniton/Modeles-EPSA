%Script d'étude de sensibilité sur l'accel
addpath(genpath('.\subfunctions'))
%- rentrez le path de votre fichier véhicule de base :

Paramfile = 'C:\Users\Bob\Documents\EPSA\Modeles-EPSA\01_Vehicle Dynamic\LapTime\Vehicules\param_elec_peak.mat'; %<-- à modifier

m = matfile(Paramfile,'Writable',true);

start = 1; %<-- à modifier
step = 0.5; %<-- à modifier
End = 10; %<-- à modifier

L = start:step:End;
T = [];
for param=L
    %noter le nom du paramètre à étudier après m. , voir le fichier
    %param.txt dans le dossier subfunctions
    % Attention si ce paramètre et relier à une relation ( ex masse
    % véhicule relié à la masse totale et à l ahauteur du COG) il faut
    % retaper la relation avec de m. devant le nom des variables
    m.k_f = 1/param;  %<-- à modifier
   [V_acc,Gx,time,t_acc] = Accelelec(75,Paramfile);
   T = [T,time];
end

plot(L,T)
% Changer les titres des axes et du graphique
title('Etude de sensitivité du rapport de réduction')
xlabel('Rapport de réduction')
ylabel('Acceleration time (s)')