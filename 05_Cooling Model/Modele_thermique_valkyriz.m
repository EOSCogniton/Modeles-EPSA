% Auteur : PBL
% Réalisé grâce aux travaux d'Aimery Saulière et celui de Arthur Accart
%% Dimensionnement du radiateur de Valkyriz (Pierre Bernal)
clear all 
close all

%% Données du problème :
debit_eau = 12/60; %(L/s)
Tei = 65 + 273.15; % température de l'eau souhaitée en entrée du radiateur
Tai = 35 + 273.15; %température de l'air ambiant autour du radiateur
P =1.013*10^5; % Pression atmosphérique (Pa)

% e_ailette = 6e-4; %valeur du constructeur à récupérer, espacement entre ailette

%% Détermination puissance à évacuer :

Pu_batterie = 53000; %W
Pu_batterie_max = 80000; %W fixé par le règlement
r_mot = 0.92; % rendement moteur EMRAX 228 dans le pire des cas
r_cont = 0.97; % rendement contrôleur type BAMOCAR D3
r_syst = r_mot*r_cont;
Pth = Pu_batterie*(1-r_syst)
Pth_max = Pu_batterie_max*(1-r_syst)

%% Coefficient thermiques convectifs de l'air et l'eau

%valable entre 100K et 1600K
T = Tai;
lambda1=1.5207*10^(-11)*T^3-4.857*10^(-8)*T^2+1.0184*10^(-4)*T-3.9333*10^(-4); % conductivité thermique de l'air
mu1=8.8848*10^(-15)*T^3-3.2398*10^(-11)*T^2+6.2657*10^(-8)*T+2.3543*10^(-6); % viscosité dynamique
Cp1=1.9327*10^(-10)*T^4-7.9999*10^(-7)*T^3+1.1407*10^(-3)*T^2-4.4890*10^(-1)*T+1.0575*10^3; % capacité calorifique massique de l'air (J/kg/K)

R=8.314; % constante des gaz parfaits (J/K/mol)

M=10^(-3)*(4/5*2*14+1/5*2*16); %masse molaire de l'air (kg/mol)

rho1=M*P/(R*T); % masse volumique de l'air

nu1=mu1/rho1; % viscosité cinématique de l'air

v1=30/3.6; % vitesse moyenne supposée de Valkyriz à l'endurance (m/s)

d1=0.0015; %longueur caractéristique de l'écoulement d'air (distance entre deux tuyaux d'eau) (DONNÉE À RÉCUPÉRER CHEZ CONSTRUCTEUR)

Re1=d1*v1/nu1;  %nombre de Renolds dans l'air passant dans le radiateur
Pr1=mu1*Cp1/lambda1; % nombre de Prandt dans l'air passant dans le radiateur
Nu1=0.036*Pr1^(1/3)*Re1^(4/5); % nombre de Nusselt
h1=lambda1*Nu1/d1 % coefficient de Newton entre l'air atmosphérique et le radiateur



rho2=1000; % masse volumique de l'eau (kg/m^3)
lambda2=(0.6071-.06)/(298-293)*(T-293)+.06; % conductivité thermique de l'eau
Cp2 = 4185; % capacité thermique massique de l'eau (J/kg/K)
mu2=8.52*10^(-4); % viscosite dynamique de l'eau (kg.m/s)

e=0.040;% épaisseur du faisceau (A RÉCUPERER CHEZ CONSTRUCTEUR)
ee=0.001; % largeur du faisceau (A RÉCUPERER CHEZ CONSTRUCTEUR)
L=0.21; % longueur du faisceau relié à la hauteur ou largeur du radiateur en fonction de si c'est un cross-flow ou down-flow (A DÉCIDER)
H=0.18; % 3ème dimension du radiateur (À DÉCIDER)
n = 120; %nombre de faisceau par m (A RÉCUPERER)

d2=ee; % longueur caractéristique de l'écoulement d'eau dans le radiateur

D2=debit_eau/rho2; % débit volumique souhaité en eau (m^3/s)

v2=D2/((n*L)*L*e*ee); % vitesse de l'eau dans le faisceaux du radiateur ; n*L est un terme estimant le nombre de faisceau présent dans le radiateur (DÉDUITE DES DONNÉES CONSTRUCTEUR)

nu2=mu2/rho2; %viscosité cinématique de l'eau

Re2=d2*v2/nu2; %nombre de Renolds
Pr2=mu2*Cp2/lambda2; % nombre de Prandt dans l'eau passant dans le radiateur
Nu2=0.036*Pr2^(1/3)*Re2^(4/5); % nombre de Nusselt dans l'eau passant dans le radiateur

h2=lambda2*Nu2/d2 % coefficient de Newton entre le radiateur et l'eau de refroidissement

% h2 >> h1 donc on peut supposer que l'alu du radiateur est à la
% température de l'eau

mean_v = [1 : 5 : 101]/3.6; %vecteur vitesse du véhicule
m_air = rho1*L*H.*mean_v; %kg/s vecteur débit d'air à travers le radiateur 
vect_surface = [0 : 0.4 : 8]; %m2 vecteur surface équivalente d'échange thermique = environ surface de toutes les ailettes
%% Obtention courbe Pth = f(débit_air) pour une dimension de radiateur DONNÉE :
l = e; %epaisseur
e_ailette = 6e-4; %espacement entre ailettes
n_ailette = H/e_ailette; % estimation du nombre d'ailette entre 2 faisceau
e_faisceau = 1/n-ee; %espacement entre 2 faisceau 

Aw = n*L*2*l*H; %estimation de la surface d'échange eau/métal
Aa = 2*(e_faisceau+e_ailette)*l*(n_ailette-1)*(n*L-1); %estimation de la surface d'échange air/métal

Aeq = Aw+Aa % surface équivalente d'échange thermique en m2

q = [];
C_eau = debit_eau*Cp2;
 for i = m_air;
     %kg/s 
     C_air = i*Cp1;
     Cmin = min(C_air,C_eau);
     Cmax = max(C_air,C_eau);
     Cr = Cmin/Cmax;
 
     U = 1/(1/h1 + 1/h2);
     NTU = U*Aeq/Cmin;
     eps = 1-exp((1/Cr)*(NTU)^0.22*(exp(-Cr*(NTU)^0.78)-1));
     qmax = Cmin*(Tei-Tai);
 
     q = [q eps*qmax];
 end
 
 figure,
 plot(mean_v*3.6,q)
 xlabel("Vitesse véhicule (km/h)")
 ylabel("Puissance thermique évacuée (W)")


%% Tracé courbe 3D Pth = f(débit_air, surface_équivalente) :

% [X,Y] = meshgrid(vect_surface,m_air);
% MC_air = Cp1*Y;
% MCmin = min(MC_air,Cp2*debit_eau);
% MCmax = max(MC_air,Cp2*debit_eau);
% MCr = MCmin./MCmax;
% U = 1/(1/h1 + 1/h2);
% MNTU = U*X./MCmin;
% Meps = 1-exp((1./MCr).*(MNTU).^0.22.*(exp(-MCr.*(MNTU).^0.78)-1));
% Mqmax = (Tei-Tai)*MCmin;
% Q = Meps.*Mqmax;
% 
% s = surf(X,Y,Q);
% s.FaceColor = 'flat';
% xlabel("Surface équivalente (m2)");ylabel("Débit d'air (kg/s)");zlabel("Puissance thermique dissipée dans le radiateur (W)");
% colorbar

% Il faut ensuite remonter à partir de la surface équivalente à des
% dimensions hauteur x largeur x épaisseur (A FAIRE EN V0.2)

%% DIMENSIONNEMENT VASES D'EXPANSIONS (A FAIRE EN V.1)

