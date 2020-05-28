% ADVISOR data file:  VEH_Eliz.m
%
% Data source: JZU  (jinhan.zhou@ecl19.ec-lyon.fr)
%
% Data confirmation: NONE
%
% Gearbox
% 	Modified OEM manual 5-spd gearbox,only 2nd and final drive used, ratio = 7.42:1 
% Energy Storage = Optima PbA D750S (yellow top) x 28 cells
% 	
% Tires:  Yokohama 215/45 ZR17  (same as SVT Focus)
%	
% Performance 
% 	0-60mph in approx 7 sec (goal)
%	City = 
%	Hwy = 
%  Range = 75 miles at 60mph steady state
%
% Created on: 06/04/2020
% 
% BY: JZU
% Revision history at end of file.
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% FILE ID INFO
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
veh_description='Ford Focus vehicle chassis';
veh_version=2020; % version of ADVISOR for which the file was generated
veh_proprietary=0; % 0=> non-proprietary, 1=> proprietary, do not distribute
veh_validation=0; % 0=> no validation, 1=> data agrees with source data, 
% 						  2=> data matches source data and data collection methods have been verified
disp(['Data loaded: VEH_FOCUS - ',veh_description])


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% PHYSICAL CONSTANTS
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
veh_gravity=9.81;    % m/s^2
veh_air_density=1.2; % kg/m^3

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% VEHICLE PARAMETERS
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%Wt estimate for a totally stripped EV Focus "Glider" = 704kg
veh_glider_mass=200; % (kg), 
veh_CD=0.312;  % (--), coefficient of drag (given on ford.com) NOTE: can be improved with EV!!

% vehicle width = 66.9 in
% vehicle height = 56.3 in
% vehicle clearance = 5 in
veh_FA=2.06;    % (m^2), frontal area, measured

% for the eq'n:  rolling_drag=mass*gravity*(veh_1st_rrc+veh_2nd_rrc*v)
% tires are P215/45 ZR17
% the rolling resistance data below is not verified, only estimated BJA. 
%veh_1st_rrc=8.630/1000;  % (--) rolling resistance = 0.008630 kg/kg
%veh_2nd_rrc=0;		% (s/m)

% fraction of vehicle weight on front axle when standing still
veh_front_wt_frac=0.50;  % (--), unknown, assume that this can be attained with battery distribution.

% height of vehicle center-of-gravity above the road
veh_cg_height=0.3;	% (m), published data - assume that this is maintained after conversion

% vehicle wheelbase, from center of front tire patch to center of rear patch
veh_wheelbase=103*25.4/1000;	% (m), Ford website

veh_cargo_mass=60; % (kg) default EPA cargo/passenger weight


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% REVISION HISTORY
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% 06/04/2020:jzu file created