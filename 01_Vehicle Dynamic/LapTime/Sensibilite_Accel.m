%Script d'�tude de sensibilit� sur l'accel
addpath(genpath('.\subfunctions'))
%- rentrez le path de votre fichier v�hicule de base :

Paramfile_1 = '.\Vehicules\Valkyriz_accel.mat'; %<-- � modifier
copyfile(Paramfile_1,'.\temp.mat');
Paramfile_temp = '.\temp.mat';

m = matfile(Paramfile_temp,'Writable',true);

start = 1; %<-- � modifier
step = 0.5; %<-- � modifier
End = 10; %<-- � modifier

L = start:step:End;
T = [];
for param=L
    %noter le nom du param�tre � �tudier apr�s m. , voir le fichier
    %param.txt dans le dossier subfunctions
    % Attention si ce param�tre et relier � une relation ( ex masse
    % v�hicule reli� � la masse totale et � l ahauteur du COG) il faut
    % retaper la relation avec de m. devant le nom des variables
    m.k_f = 1/param;  %<-- � modifier
   [V_acc,Gx,time] = Accelelec(75,Paramfile_temp);
   T = [T,time];
end

delete(Paramfile_temp)

plot(L,T)
% Changer les titres des axes et du graphique
title('Etude de sensitivit� du rapport de r�duction')
xlabel('Rapport de r�duction')
ylabel('Acceleration time (s)')