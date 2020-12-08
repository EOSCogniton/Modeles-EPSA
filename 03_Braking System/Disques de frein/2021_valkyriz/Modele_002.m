%% Thermal calculations
clear
m_veh=225; %kg car's weight
m_per=75; %kg weight of a person
vel=100/3.6;%m/s car speed before braking
alpha=0.72; % percentage of braking force absorbed by the front wheels
g=9.81; % m/s^2 gravity
decel=1.5*g; %m/s^2 deceleration of the vehicule
r_fr_ext_disc=149e-3; %m
D_ext_disc=149e-3*2;% m Outer diameter of disc
ka=.02624 ;% W/mk thermal conductivity of air at 25ºC
r_fr_int_disc=128.8e-3; %m
rho_disc=7750; %kg/m^3 stainless steel density
rho_air=1.184;%kg/m^3 air density at 25ºC
c_disc=450; %J/(kg K) brake disc specific heat capacity
k_disc=15.1; % W/(m ºC)brake disc thermal conductivity
Tamb=22; %K ambient temperature
FOS=2.5; %factor of safety
mu=1.85e-5; %kg/(m s) dynamic viscosity of air at 25ºC
rho_pad=2595;
c_pad=1465;
k_pad=1.212;
%% Calculations
%HEAT FLUX
A_fr_pad=pi*(r_fr_ext_disc^2-r_fr_int_disc^2)*40/360;
A_fr_disc=pi*(r_fr_ext_disc^2-r_fr_int_disc^2);
th_effus_disc=sqrt(rho_disc*c_disc*k_disc);% W s^0.5/(m^2 K)thermal effusivity
th_effus_pad=sqrt(rho_pad*c_pad*k_pad);% W s^0.5/(m^2 K)thermal effusivity
prop_disc=th_effus_disc*A_fr_disc/(th_effus_disc*A_fr_disc+th_effus_pad*A_fr_pad);
KE=prop_disc*alpha*0.5*(m_veh+m_per)*vel^2; % J kinetic energy at the front wheels. 
t=vel/decel; % s braking time
Br_power=KE/t*0.5; % W braking power at one of the front wheels
heat_flux=Br_power/(2*A_fr_disc); % W/m^2 double area because there are two sides.
T_max_disc=0.527*heat_flux*sqrt(t)/th_effus_disc+Tamb; %ºC maximum temperature
T_max_real_disc=T_max_disc*FOS;%ºC maximum temperature taking into account FSO
%CONVECTIVE COEFFICIENT
Re=rho_air*vel*D_ext_disc/mu;
if Re>2.4e5
    h=0.04*ka/D_ext_disc*Re^0.8;
else
    h=0.7*ka/D_ext_disc*Re^0.55;
end

