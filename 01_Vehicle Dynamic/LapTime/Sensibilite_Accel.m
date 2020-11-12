%Script d'étude de sensibilité sur l'accel
addpath(genpath('.\subfunctions'))
%- rentrez le path de votre fichier véhicule de base :

Paramfile_1 = '.\Vehicules\Valkyriz_accel.mat'; %<-- à modifier
copyfile(Paramfile_1,'.\temp.mat');
Paramfile_temp = '.\temp.mat';

m = matfile(Paramfile_temp,'Writable',true);

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
   [V_acc,Gx,time] = Accelelec(75,Paramfile_temp);
   T = [T,time];
end

delete(Paramfile_temp)

plot(L,T)
% Changer les titres des axes et du graphique
title('Etude de sensitivité du rapport de réduction')
xlabel('Rapport de réduction')
ylabel('Acceleration time (s)')