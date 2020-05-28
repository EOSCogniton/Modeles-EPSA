clear all;close all;clc;

%Settings
set(0, 'DefaultLineLineWidth', 1, ...
           'DefaultTextInterpreter', 'LaTeX', ...
           'DefaultAxesTickLabelInterpreter', 'LaTeX', ...
           'DefaultAxesFontName', 'LaTeX', ...
           'DefaultLegendInterpreter', 'LaTeX', ...
           'DefaultAxesLineWidth', .5, ...
           'DefaultAxesFontSize', 10);

%%  Unit
% Voltage - volt; Energy - kWh; Mass - g; Capacity - Ah; Intensite - A;
%  Temperature - ?; Length - mm;  Power - kW;

%% Limitation of the Rules
V_lim=600;
V_seg_lim=120;
E_seg_lim=1833.33;
m_seg_lim=12e3;
P_inf=40;

%% Parameters of the VTC=18650
V_cell_max_ch=4.25;
V_cell_max_dis=4.2;
V_cell_nom=3.6;
V_cell_min=2;
Q_cell=3.12;
E_cell=631*pi*18.35^2*65/4*1e-9;
m_cell_max=48.1;
m_cell=46.5; %Mass of the cell [g]
I_cell_max_dis=30;
I_cell_max_ch=5;
I_cell_nom=10;
D_cell=18.5; %Diameter of the cell (in this case : model 18650) [mm]
La_cell=D_cell; %Width of the cell [mm]
Lo_cell=D_cell; %length of the cell [mm]
H_cell=65.2; %height of the cell [mm]
T_cell_max=60; %temperature max of the cell [C]
enve_bottom=3.2;
enve_wall=2.3;

%%  Geometrical Limitation
Long=100; %Lenght of the container [mm]
Larg=240; %width of the container [mm]
Haut=80; %height of the container [mm]

%%  Calcul of Energetic Limitation
ns_sup_e=floor(V_lim/V_cell_max_dis);
np_inf_e=ceil(P_inf*1e3/V_lim/I_cell_max_dis);
n_seg_sup=min([floor(E_seg_lim/E_cell),floor(m_seg_lim/m_cell_max)]);
ns_sup_seg=min([floor(V_seg_lim/V_cell_max_dis),floor(n_seg_sup/np_inf_e)]);

%%  Calcul of Geometrical Limitation
enve_vol=[Haut-enve_bottom-enve_wall,Long-2*enve_wall,Larg-2*enve_wall]; %Volume inside the container [mm]
cell_vol=[Lo_cell,La_cell,H_cell]; %Volume effectif of the cell [mm^3]
config_pro=[
    floor(enve_vol(1)/cell_vol(1)),floor(enve_vol(2)/cell_vol(2)),floor(enve_vol(3)/cell_vol(3));
    floor(enve_vol(1)/cell_vol(1)),floor(enve_vol(2)/cell_vol(3)),floor(enve_vol(3)/cell_vol(2));
    floor(enve_vol(1)/cell_vol(2)),floor(enve_vol(2)/cell_vol(1)),floor(enve_vol(3)/cell_vol(3));
    floor(enve_vol(1)/cell_vol(2)),floor(enve_vol(2)/cell_vol(3)),floor(enve_vol(3)/cell_vol(1));
    floor(enve_vol(1)/cell_vol(3)),floor(enve_vol(2)/cell_vol(1)),floor(enve_vol(3)/cell_vol(2));
    floor(enve_vol(1)/cell_vol(3)),floor(enve_vol(2)/cell_vol(2)),floor(enve_vol(3)/cell_vol(1));
    ]
num_pro=zeros(1,6);
for k=1:6
    num_pro(k)=config_pro(k,1)*config_pro(k,2)*config_pro(k,3);
end
n_pro=[];
n_sup_g=max(num_pro);
ind_choix=find(num_pro==n_sup_g);
for m=1:length(ind_choix)
    n_choix=[config_pro(ind_choix(m),1),config_pro(ind_choix(m),2),config_pro(ind_choix(m),3)];

    %% Calcul of all Limitation
    n_seg_c=ceil(V_lim/V_cell_max_dis/floor(n_seg_sup/np_inf_e));
    ind_seg=find(n_choix>=n_seg_c);
    for l=1:length(ind_seg)
        n_seg=n_choix(ind_seg(l));
        n_par_seg=n_sup_g/n_seg;n_s_seg=min(ns_sup_seg,floor(n_par_seg/np_inf_e));n_p=floor(n_par_seg/n_s_seg);
        n_choix(mod(ind_seg(l),3)+1)=n_s_seg*n_p/n_choix(mod(ind_seg(l)+1,3)+1);
        n_pro=[n_pro;n_seg,n_s_seg,n_p,n_choix];
    end
end

n_tot_pro=n_pro(:,1).*n_pro(:,2).*n_pro(:,3);n_tot=max(n_tot_pro);
ind_n=find(n_tot_pro==n_tot);n_pro=n_pro(ind_n,:);
n_p_max=max(n_pro(:,3));ind_n=find(n_pro(:,3)==n_p_max);

for l=1:length(ind_n)
    n_seg=n_pro(ind_n(l),1);n_s_seg=n_pro(ind_n(l),2);n_p=n_pro(ind_n(l),3);
    resultat=[int2str(n_seg),'seg_',int2str(n_s_seg),'s',int2str(n_p),'p | H:',num2str(n_pro(ind_n(l),4)),',Length:',num2str(n_pro(ind_n(l),5)),',Width:',num2str(n_pro(ind_n(l),6))]
end

%%  Comportement
power_max=n_seg*n_s_seg*n_p*V_cell_max_dis*I_cell_max_dis*1e-3
power_nom=n_seg*n_s_seg*n_p*V_cell_nom*I_cell_nom*1e-3
energy=n_seg*n_s_seg*n_p*E_cell
masse_tot = n_seg*n_s_seg*n_p*m_cell
charge_time=E_cell/(V_cell_max_ch*I_cell_max_ch)

% SOC RANGE over which data is defined
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
soc=[0:.1:1];  % (--)

% Temperature range over which data is defined
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
tmp=[-10 0 10 23 40 45];  % (C)

% Parameters vary by temperature
max_cap=[2.52,2.65,2.83,3.12,3.12,3.12];	% (A*h), max. capacity at C/5 rate, indexed by ess_tmp
figure;
subplot(2,2,1);
plot(tmp,n_seg*n_s_seg*n_p*max_cap);
xlabel('Temperature(^oC)');
ylabel('Capacity(A.h)');
title('Capacity');

% module's resistance to being discharged, indexed by ess_soc and ess_tmp
Rint=[
   18 16 15 13 11 10 9.5 9.5 9.5 9.5 9.5
   18 15 13 11 10 9.5 9 9 9 9 9
   18 13 11 10 9 8.5 8.5 8.5 8.5 8.5 8.5
   18 8 8 8 8 8 8 8 8 8 8
   18 8 8 8 8 8 8 8 8 8 8
   18 8 8 8 8 8 8 8 8 8 8
]/1000; % (ohm)
subplot(2,2,2);
[c,h]=contour(soc*100,tmp,n_seg*n_s_seg/n_p*Rint);
xlabel('SOC(%)');
ylabel('Tempearture(^oC)');
clabel(c,h);
title('Inner Resistor(Ohm)');
voc=[3 3.68 3.74 3.77 3.79 3.82 3.87 3.92 3.98 4.06 4.2]; % (V)
subplot(2,2,3);
plot(soc*100,n_seg*n_s_seg*voc)
xlabel('SOC(%)');
ylabel('Voltage(V)');
title('Voltage of Open Circuit');
subplot(2,2,4);
plot(soc*100,n_seg*n_s_seg*n_p*voc*I_cell_max_dis*0.9*1e-3)
xlabel('SOC(%)');
ylabel('Power(kW)');
title('Max Power');

%% Heating Calcul
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Excepted Cooling Degree 
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
tmp_a=20; %Room temperature [degre Celsius C]
cfm_fan=18.7;
ess_mod_cp=964.92; % J/kgK  ave heat capacity of module
ess_set_tmp=35;  % C      thermostat temp of module when cooling fan comes on
ess_mod_sarea=(Long*Larg+Larg*Haut+Long*Haut)*2e-6; % m^2    total module surface area exposed to cooling air
ess_mod_flow_area=min([Larg,Long])*Haut*1e-6; % m^2    cross-sec flow area for cooling air per module (10-mm gap btwn mods)
ess_mod_case_thk=enve_wall*1e-3;  % m      thickness of module case
ess_mod_case_th_cond=204e-3; % W/mK   thermal conductivity of module case material
ess_th_res_off=((1/4)+(ess_mod_case_thk/ess_mod_case_th_cond))/ess_mod_sarea; % K/W  tot thermal res key on=tot thermal res key off (cold soak)
n_fans=ceil(I_cell_max_dis^2*n_seg*n_s_seg/n_p*max(Rint(:,1))/1.003/(ess_set_tmp-tmp_a)/cfm_fan)
ess_mod_airflow=n_fans*cfm_fan*1.7/3600*1.293;   % kg/s   cooling air mass flow rate across module (140 cfm=0.07 kg/s at 20 C)
ess_air_vel=ess_mod_airflow/(1.16*ess_mod_flow_area); % m/s  ave velocity of cooling air
ess_air_htcoef=30*(ess_air_vel/5)^0.8;      % W/m^2K cooling air heat transfer coef.
ess_th_res_on=((1/ess_air_htcoef)+(ess_mod_case_thk/ess_mod_case_th_cond))/ess_mod_sarea; % K/W  tot thermal res key on
ess_mod_airflow=max(ess_mod_airflow,0.001);

temp_max=(n_seg*n_s_seg*n_p*Q_cell)/I_cell_max_dis;
temp_sam = 0:temp_max/10000:temp_max;
ess_temp=zeros(1,length(temp_sam));
SOC_i=1;
d_temp_i=40;
temp_i=tmp_a;
[SOC,TMP]=meshgrid(soc,tmp);
ess_temp(1)=d_temp_i+temp_i;

for n=2:length(temp_sam)
    P_joule=I_cell_max_dis^2*interp2(SOC,TMP,n_seg*n_s_seg/n_p*Rint,SOC_i,temp_i+d_temp_i,'spline');
    P_Q=P_joule-d_temp_i/ess_th_res_on;
    d_temp_i=d_temp_i+P_Q*temp_max/(length(temp_sam)-1)/3.6/masse_tot;
    if d_temp_i+temp_i<ess_set_tmp
        P_Q=P_joule-d_temp_i/ess_th_res_off;d_temp_i=d_temp_i+P_Q*temp_max/(length(temp_sam)-1)/3.6e3/masse_tot;
    end
    SOC_i=SOC_i-I_cell_max_dis*temp_max/(length(temp_sam)-1)/(n_seg*n_s_seg*n_p*Q_cell);
    ess_temp(n)=d_temp_i+temp_i;
end
figure;
plot(temp_sam,ess_temp);
xlabel('time (s)');
ylabel('Temperature ($^o$C)')
title('Heating Courbe - Maximal-Circuit Discharge till SOC=0');