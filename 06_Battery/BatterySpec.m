%%% Calculs des caractéristiques nécessaires en puissance, couple, courant,
%%% tension, et architecture pour atteindre certaines performances avec la
%%% voiture
% 
% clear
% close all

% Le script suivant permet de simuler une acceleration sur une distance
% donnee. De nombreuses ameliorations peuvent etre apportees par la suite.

% Ce script est utile pour déterminer le couple et la puissance moteur
% nécessaires pour atteindre certaines performances
% Bien penser à répondre à l'invite de commande


%%%% Paramètres du programme

vmax = 100; %km/h (vitesse maximale pour les courbes)
pas_v = 5 ; %km/h (vitesse entre chaque point de la courbe)

t = 10; % s (temps visé pour passer de 0 à v km/h)

%%%% Paramètres de la voiture
%Cellule
cell_V = 3.6; % V (tension cellule)
cell_A = 10; % A (décharge en pic)

Z_roue = 42;
Z_motor = 13;

gear_ratio = Z_motor/Z_roue; % en comptant les dents sur valkyriz (à vérifier)

SCx = 0.66; % m² (Issu des essais d'invictus, à redémontrer via simulation)
rho_a = 1.225; % kg/m³

m_v = 230; %kg (masse à vide)
m_p = 80; %kg (masse pilote)

m = m_v + m_p; %kg (masse totale)

D_roue = 0.52; % m (diametre exterieur de la roue)
L = 75; % m (Longueur de la piste)

v_th = L/t * 2 * 3.6; % juste pour info

NmA = 0.75; % N.m/Aph (Torque par ampère)

%%%%%

v = 0:pas_v:vmax;

a =  v/t/3.6;

F = m * a + SCx * 1/2 * rho_a * (1/3.6)*v.^2;

w_t = F * D_roue/2; % N.m (Wheel torque) 

m_t=w_t*gear_ratio; % N.m (motor torque needed)

m_I = m_t/NmA; % A (courant nécessaire par phase)

w_s = v/D_roue *2; % rad/s (vitesse de rotation des roues à v)

m_s = w_s/gear_ratio; % rad/s (vitesse moteur)

Pnec = m_s .* m_t; %W Puissance totale nécessaire

Vnec = Pnec./m_I/sqrt(3); %V Tension en sortie de batterie nécessaire

n_v_cell = ceil(Vnec./cell_V) ; % nombre de cellule nécessaire en série

n_a_cell = ceil(m_I./cell_A) ; % nombre de cellule nécessaire en parallèle

disp('Temps (s) :')
disp(t)
disp('Vitesse max (km/h) :')
disp(vmax)
% disp('Couple nécessaire (N.m) :')
% disp(m_t)
% disp('Puissance nécessaire (kW) :')
% disp(Pnec/10^3)
% disp('Tension en sortie de batterie nécessaire (V) :')
% disp(Vnec)
% disp('Courant en sortie de batterie nécessaire (A) :')
% disp(m_I)

figure(1)
hold on
yyaxis left
ylabel('Couple (N.m)')
plot(v,m_t,'b')
yyaxis right
ylabel('Puissance (W)')
plot(v,Pnec,'r')
legend('Couple (N.m)','Puissance (W)')
title('Courbe de Couple/Puissance pour t = '+string(t)+'s')
xlabel('Vitesse de 0 à '+string(vmax)+'km/h')
hold off

figure(2)
hold on
yyaxis left
ylabel('Tension (V)')
plot(v,Vnec,'b')
yyaxis right
ylabel('Courant (A)')
plot(v,m_I,'r')
legend('Tension nécessaire (V)','Courant nécessaire (A)')
title('Courbe de courants/tensions pour t='+string(t)+' s')
xlabel('Vitesse de 0 à '+string(vmax)+'km/h')

figure(3)
hold on
yyaxis left
ylabel('Nombre de cellule en série')
plot(v,n_v_cell,'b')
yyaxis right
ylabel('Nombre de cellule en parallèle')
plot(v,n_a_cell,'r')
legend('Nombre de cellule en série','Nombre de cellule en parallèle')
title('Besoin en cellule séries/parallèles pour t='+string(t)+' s')
xlabel('Vitesse de 0 à '+string(vmax)+'km/h')

% askmodule = inputdlg('Nombre de modules à mettre dans la voiture :','Modules');
% n_module = str2num(askmodule{1});
% 
% n_s_module = ceil(n_v_cell./n_module); % paramètre s du module
% 
% n_p_module = n_a_cell; % paramètre p du module
% 
% figure(4)
% hold on
% yyaxis left
% ylabel('Nombre de cellule en série par module')
% plot(v,n_s_module,'b')
% yyaxis right
% ylabel('Nombre de cellule en parallèle')
% plot(v,n_p_module,'r')
% legend('Nombre de cellule en série','Nombre de cellule en parallèle')
% title('Besoin en cellule séries/parallèles par module pour t='+string(t)+' s')
% xlabel('Vitesse de 0 à '+string(vmax)+'km/h')
% 
% vitesse_f = inputdlg('Vitesse souhaitée (km/h) : ','Vitesse');
% vit_f = ceil((str2num(vitesse_f{1})+1-v(1))/pas_v);
% 
% disp('Architecture module :')
% disp(string(n_s_module(vit_f))+'s'+string(n_p_module(vit_f))+'p'+newline)


disp('---------------------------------------------------------')






