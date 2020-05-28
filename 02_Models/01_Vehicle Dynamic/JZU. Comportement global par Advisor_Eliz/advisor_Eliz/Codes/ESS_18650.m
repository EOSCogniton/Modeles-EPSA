% ADVISOR data file:  ESS_18650.m
%
% Data source:
% https://sep.yimg.com/ty/cdn/theshorelinemarket/sony_us18650vtc6-2.pdf?t=1578456466&&fbclid=IwAR0en93hUuDaYsZnxrT4yFMItj_LfHDOrja14R6ZisfZuU8QVh79ZTyW8uI#jmui=f%3A1426%3A305419896%3AbDJrmkUnSz%2CkZ8lBkfq5yChP
% 
% Created on: 06/04/2020
% By: JZU,jinhan.zhou@ecl19.ec-lyon.fr
%
% Revision history at end of file.
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% FILE ID INFO
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
ess_description='Sony VTC6 18650, 112s5p';
ess_version=2020; % version of ADVISOR for which the file was generated
ess_proprietary=0; % 0=> non-proprietary, 1=> proprietary, do not distribute
ess_validation=0; % 0=> no validation, 1=> data agrees with source data, 
% 2=> data matches source data and data collection methods have been verified
disp(['Data loaded: ESS_18650 - ',ess_description])

%%For a module
ns=16; % number of cells in serie 
np=5;  % number of cells in parallel
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% SOC RANGE over which data is defined
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
ess_soc=[0:.1:1];  % (--)

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Temperature range over which data is defined
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
ess_tmp=[-10 0 10 23 40 45];  % (C)

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% LOSS AND EFFICIENCY parameters
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Parameters vary by SOC horizontally, and temperature vertically
ess_max_ah_cap=np*ns*[
   2.52
   2.65
   2.83
   3.12
   3.12
   3.12
];	% (A*h), max. capacity at C/5 rate, indexed by ess_tmp
% average coulombic (a.k.a. amp-hour) efficiency below, indexed by ess_tmp
ess_coulombic_eff=[
   .9
   .9
   .9
   .9
   .9
   .9
];  % (--);
% module's resistance to being discharged, indexed by ess_soc and ess_tmp
ess_r_dis=[
   18 16 15 13 11 10 9.5 9.5 9.5 9.5 9.5
   18 15 13 11 10 9.5 9 9 9 9 9
   18 13 11 10 9 8.5 8.5 8.5 8.5 8.5 8.5
   18 8 8 8 8 8 8 8 8 8 8
   18 8 8 8 8 8 8 8 8 8 8
   18 8 8 8 8 8 8 8 8 8 8
]/1000/np*ns; % (ohm)
% module's resistance to being charged, indexed by ess_soc and ess_tmp
ess_r_chg=[
   18 16 15 13 11 10 9.5 9.5 9.5 9.5 9.5
   18 15 13 11 10 9.5 9 9 9 9 9
   18 13 11 10 9 8.5 8.5 8.5 8.5 8.5 8.5
   18 8 8 8 8 8 8 8 8 8 8
   18 8 8 8 8 8 8 8 8 8 8
   18 8 8 8 8 8 8 8 8 8 8
]/1000/np*ns; % (ohm)
% module's open-circuit (a.k.a. no-load) voltage, indexed by ess_soc and ess_tmp
ess_voc=ns*[
   3 3.68 3.74 3.77 3.79 3.82 3.87 3.92 3.98 4.06 4.2
   3 3.68 3.74 3.77 3.79 3.82 3.87 3.92 3.98 4.06 4.2
   3 3.68 3.74 3.77 3.79 3.82 3.87 3.92 3.98 4.06 4.2
   3 3.68 3.74 3.77 3.79 3.82 3.87 3.92 3.98 4.06 4.2
   3 3.68 3.74 3.77 3.79 3.82 3.87 3.92 3.98 4.06 4.2
   3 3.68 3.74 3.77 3.79 3.82 3.87 3.92 3.98 4.06 4.2
]; % (V)


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% LIMITS
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
ess_min_volts=2*ns;
ess_max_volts=4.25*ns;


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% OTHER DATA
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
ess_module_mass=46.6e-3*np*ns;  % (kg), mass of a single ~12 V module

% user definable mass scaling relationship 
ess_mass_scale_fun=inline('(x(1)*ess_module_num+x(2))*(x(3)*ess_cap_scale+x(4))*(ess_module_mass)','x','ess_module_num','ess_cap_scale','ess_module_mass');
ess_mass_scale_coef=[1 0 1 0]; % coefficients in ess_mass_scale_fun

% user definable resistance scaling relationship
ess_res_scale_fun=inline('(x(1)*ess_module_num+x(2))/(x(3)*ess_cap_scale+x(4))','x','ess_module_num','ess_cap_scale');
ess_res_scale_coef=[1 0 1 0]; % coefficients in ess_res_scale_fun

ess_module_num=7;  % a default value for number of modules
ess_cap_scale=1; % scale factor for module max ah capacity

% battery thermal model
ess_th_calc=1;                             % --     0=no ess thermal calculations, 1=do calc's
ess_mod_cp=660;                            % J/kgK  ave heat capacity of module
ess_set_tmp=35;                            % C      thermostat temp of module when cooling fan comes on
ess_mod_sarea=(18*18*np*ns*2+18*65*2*(np+ns))*1e-6;          % m^2    total module surface area exposed to cooling air
ess_mod_airflow=0.07/5;                   % kg/s   cooling air mass flow rate across module (140 cfm=0.07 kg/s at 20 C)
ess_mod_flow_area=(18*18-pi*9*9)*np*ns*1e-6;                  % m^2    cross-sec flow area for cooling air per module (10-mm gap btwn mods)
ess_mod_case_thk=3.2/1000;                   % m      thickness of module case
ess_mod_case_th_cond=237;                 % W/mK   thermal conductivity of module case material
ess_air_vel=ess_mod_airflow/(1.16*ess_mod_flow_area); % m/s  ave velocity of cooling air
ess_air_htcoef=30*(ess_air_vel/5)^0.8;      % W/m^2K cooling air heat transfer coef.
ess_th_res_on=((1/ess_air_htcoef)+(ess_mod_case_thk/ess_mod_case_th_cond))/ess_mod_sarea; % K/W  tot thermal res key on
ess_th_res_off=((1/4)+(ess_mod_case_thk/ess_mod_case_th_cond))/ess_mod_sarea; % K/W  tot thermal res key off (cold soak)
% set bounds on flow rate and thermal resistance
ess_mod_airflow=max(ess_mod_airflow,0.001);
ess_th_res_on=min(ess_th_res_on,ess_th_res_off);
clear ess_mod_sarea ess_mod_flow_area ess_mod_case_thk ess_mod_case_th_cond ess_air_vel ess_air_htcoef

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% REVISION HISTORY
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% JZU,06/04/2020