%%% Acceleration

% Le script suivant permet de simuler une acceleration sur une distance
% donnee. De nombreuses ameliorations peuvent etre apportees par la suite.

% Ce script est utile pour déterminer le couple et la puissance moteur
% nécessaires pour atteindre certaines performances

Z_roue = 42;
Z_motor = 13;

gear_ratio = Z_motor/Z_roue; % en comptant les dents sur valkyriz (à vérifier)

m_v = 230; %kg (masse à vide)
mp = 80; %kg (masse pilote)

m = m_v + mp; %kg (masse totale)

D_roue = 0.52; % m (diametre exterieur de la roue)
L = 75; % m (Longueur de la piste)

NmA = 0.75; % N.m/Aph (Torque par ampère)


%%%%
v_max = 30; % km/h (vitesse max visée) 
t = 10; % s (temps visé pour passer de 0 à v km/h)
%%%%

v_th = L/t * 2 * 3.6; % juste pour info

a =  v_max/t/3.6;

F = m * a;

w_t = F * D_roue/2; % N.m (Wheel torque) 

m_t=w_t*gear_ratio; % N.m (motor torque needed)

m_I = m_t/NmA; % A (courant nécessaire par phase)

w_s = v_max/D_roue *2; % rad/s (vitesse de rotation des roues à v)

m_s = w_s/gear_ratio; % rad/s (vitesse moteur)

Pnec = m_s * m_t; % Puissance totale nécessaire

Vnec = Pnec/m_I/sqrt(3); % Tension en sortie de batterie nécessaire

disp('Temps (s) :')
disp(t)
disp('Vitesse max (km/h) :')
disp(v_max)
disp('Couple nécessaire (N.m) :')
disp(m_t)
disp('Puissance nécessaire (kW) :')
disp(Pnec/10^3)
disp('Tension en sortie de batterie nécessaire (V) :')
disp(Vnec)
disp('Courant en sortie de batterie nécessaire (A) :')
disp(m_I)
disp('---------------------------------------------------------')



