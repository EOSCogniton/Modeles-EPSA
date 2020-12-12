%% Dimensionnement du radiateur

%% Données du problème :
 
debit_eau = 12/60; %(L/s)
cp_eau = 4185; %(J/(K.kg))
cp_air = 1005;
he = 10000; %(valeur mediane)
ha = 150; 
rho_air = 1; %(kg/m3)
rho_eau = 1000;
Tei = 65 + 273.15;
Tai = 35 + 273.15;
h = 0.210;
L = 0.160;
l = 0.038; %valeur du constructeur à récupérer
e_ailette = 6e-4; %valeur du constructeur à récupérer

%% Etablissement des courbes :

n_ailette = h/e_ailette;
mean_v = [1 : 10 : 101]/3.6;
S_ech = 2*[L*l+e_ailette*l]*(n_ailette+1)%m2
m_air = rho_air*L*h.*mean_v; %kg/s 
q = [];
C_eau = debit_eau*cp_eau;
% for i = m_air;
%     %kg/s 
%     C_air = i*cp_air;
%     Cmin = min(C_air,C_eau);
%     Cmax = max(C_air,C_eau);
%     Cr = Cmin/Cmax;
% 
%     U = 1/(1/he + 1/ha);
%     NTU = U*S_ech/Cmin;
%     eps = 1-exp((1/Cr)*(NTU)^0.22*(exp(-Cr*(NTU)^0.78)-1));
%     qmax = Cmin*(Tei-Tai);
% 
%     q = [q eps*qmax];
% end
% 
% figure,
% plot(mean_v*3.6,q)
% xlabel("Vitesse véhicule (km/h)")
% ylabel("Puissance thermique évacuée (W)")

%% Tracé courbe 3D :

vect_surface = [0 : 0.8 : 8];
[X,Y] = meshgrid(vect_surface,m_air);
MC_air = cp_air*Y;
MCmin = min(MC_air,C_eau);
MCmax = max(MC_air,C_eau);
MCr = MCmin./MCmax;
U = 1/(1/he + 1/ha);
MNTU = U*X./MCmin;
Meps = 1-exp((1./MCr).*(MNTU).^0.22.*(exp(-MCr.*(MNTU).^0.78)-1));
Mqmax = (Tei-Tai)*MCmin;
Q = Meps.*Mqmax;

s = surf(X,Y,Q,'facealpha',0.6);
s.FaceColor = 'flat';

xlabel("Surface équivalente (m2)");ylabel("Débit d'air (kg/s)");zlabel("Puissance thermique dissipée dans le radiateur (W)");
colorbar


%% Dimensionnement pompe : 

% pdc_moteur = 1000; %kPa
% pdc_cont = 560;
% pdc_rad = 10;
% Qw = debit_eau/(60*1000);
% 
% km = pdc_moteur/Qw^2;
% kcont = pdc_cont/Qw^2;
% krad = pdc_rad/Qw^2;
% 
% Pdc_tot = (km+kcont+krad)*Qw^2 %kPa

