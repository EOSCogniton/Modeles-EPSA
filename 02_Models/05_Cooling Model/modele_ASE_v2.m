% Mod�le radiateur Invictus 
% Auteur : ASE ( Aimery Sauli�re )
% Description : 


%% TOUS LES UNITES sont (SI)

%% Dimensions et caract�ristiques du radiateur

Teau0 = 90; % EN DEGRE CELSIUS temp�rature de l'eau � l'entr�e du radiateur
T0 = 30;% EN DEGRE CELSIUS temp�rature air ambiant ( proche de l'endroit o� ce trouve le radiateur )
V_air = 12; % vitesse du flux d'air � travers le radiateur

L = 65*0.33; % longueur du conduit du radiateur 
espace_btw_tubulures=0.002; %espace entre les tubulures
Dy = 0.0005; % �paisseur m�tallique de la tubulure suivant y 
Dx = 0.001; % �paisseur m�tallique de la tubulure suivant x
lx = 0.1; % largeur tubulure suivant x
ly = 0.001; % largeur tubulure suivant y
Cad = 1.2; % <= 2
% coefficient de correction pour les hypoth�ses simplificatrices faites sur 
% les directions du flux thermique au sein du radiateur 

rho_radiateur = 2.27; % masse volumique du m�tal constituant le radiateur 
lambda = 203; % conductivit� thermique Aluminium 


%% Air :
rho_air = 1.225; % masse volumique de l'air
p_atm = 101325; % pression atmosph�rique
T0 = T0 + 273.15;
Tair = T0*(1-1/2*rho_air*V_air^2/p_atm); % temp�rature de l'air � travers le radiateur

%% Expression de la loi de Sutherland (cf wikipedia) 
T_ref_air_sutherland = 273.15; % T0
mu_air_0 = 1.715*10^(-5); % viscosit� de l'air � T_ref_air_sutherland
T_sutherland = 110.4; % temp�rature de sutherland
mu_air = mu_air_0*(Tair/T_ref_air_sutherland)^(3/2) * (T_ref_air_sutherland + T_sutherland)/(Tair + T_sutherland); %mu
mu_air_tubulures = mu_air_0*(Tair/T_ref_air_sutherland)^(3/2) * (T_ref_air_sutherland + T_sutherland)/(Teau0 + T_sutherland); %mu_p
%% Corr�lation de Sieder et Tate (approximation constance nusselt, correction � faire pour v3)
Cp1=(1.9327*10^(-10)*Tair^4-7.9999*10^(-7)*Tair^3+1.1407*10^(-3)*Tair^2-4.4890*10^(-1)*Tair+1.0575*10^3);

lambda1=1.5207*10^(-11)*Tair^3-4.857*10^(-8)*Tair^2+1.0184*10^(-4)*Tair-3.9333*10^(-4); 
nu_air=mu_air/rho_air;

Re_air=espace_btw_tubulures*V_air/nu_air; % nombre de Reynolds dans l'�coulement entrant dans le radiateur
Pr_air=mu_air*Cp1/lambda1; % nombre de Prandlt dans l'air passant dans le radiateur
Nu_air=1.86*(Pr_air*Re_air*ly/lx)^(1/3)*(mu_air/mu_air_tubulures)^(0.14); % nombre de Nusselt

h1 = lambda1*Nu_air/espace_btw_tubulures; % coefficient d'�change convectif Air- M�tal

%% Eau
V_eau = 0.5; %vitesse de l'eau dans le radiateur
C_eau = 4180; %capacit� thermique massique de l'eau
rho_eau = 997; %masse volumique de l'eau

mu_eau=0.3*10^-3; % viscosit� dynamique de l'eau (kg/m.s)
lambda_eau=0.6; % conductivit� thermique de l'eau (W/m/K)
nu_eau=mu_eau/rho_eau; % viscosit� cin�matique de l'eau
d2=(lx+ly)/2; % longueur caract�ristique de l'�coulement d'eau dans le radiateur --> diam�tre de nos durites
Re_eau=d2*V_eau/nu_eau; % nombre de Reynolds
Pr_eau=mu_eau*C_eau/lambda_eau; % nombre de Prandt dans l'eau passant dans le radiateur
Nu_eau=0.036*Pr_eau^(1/3)*Re_eau^(4/5); % nombre de Nusselt dans l'eau passant dans le radiateur (Approximation)

h2 = lambda_eau*Nu_eau/d2; % M�tal eau 

%% D�termination de la temp�rature de l'eau apr�s avoir travers� le radiateur
Teau0 = Teau0 + 273.15; % Conversion en Kelvin
Omega = lambda*h1*h2/(V_eau*C_eau*rho_eau*lx*ly) *  (  Cad*ly/( lambda*(h1+h2) + h1*h2*Dx )  +   2*lx/(lambda*(h1+h2) +  h1*h2*Dy));
Tho = 1/Omega;

TeauSortie = (Teau0 - Tair)*exp(-L*Omega) + Tair ;% temp�rature de l'eau � la sortie du radiateur

TeauSortieCelsius = TeauSortie - 273.15
Puissance = C_eau*rho_eau*lx*ly*V_eau*(TeauSortieCelsius-Teau0);
%% Masse des tubulures du radiateur
Section_tubulures = (2*Dx + lx) * Dy * 2 + ly * Dx * 2;
Volume_tubulures = Section_tubulures * L;
Masse_tubulures = Volume_tubulures * rho_radiateur;
%% Puissance � dissiper
Pmoteur = 85; % en ch
rendement_explosion = 0.3;
pourcentage_evacue = 0.15;
P_a_dissiper = Pmoteur/rendement_explosion*pourcentage_evacue;
%% Dur�e du r�gime transitoire
% A compl�ter
%% R�sultats 
disp("Puissance dissip�e :   " + Puissance+ " W  , soit " + Puissance * 10^(-3) * 0.7355 + " ch" )
disp("D�bit volumique dans le radiateur :   " + V_eau*lx*ly*10^3 + " L/s")
disp("Masse de la tubulure du radiateur :   " + Masse_tubulures + " kg")
disp("Dur�e du r�gime transitoire :  " )


