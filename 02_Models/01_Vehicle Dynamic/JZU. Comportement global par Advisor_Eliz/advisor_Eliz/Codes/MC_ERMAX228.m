%%%%% ADVISOR data file:  MC_ERMAX228
%
% Data source:
% Motor: ERMAX228 ; Controllor: 100DZ
%
% Created on:  06/04/2020
% By:  JZU, jinhan.zhou@ecl19.ec-lyon.fr
%
% Revision history at end of file.

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% FILE ID INFO
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
mc_description='Solectria ACgtx20/AC300 AC induction motor/controller';
mc_version=2003;
mc_proprietary=0;  % 0=> public data, 1=> restricted access, see comments above
mc_validation=0; % 0=> no validation, 1=> data agrees with source data, 
% 2=> data matches source data and data collection methods have been verified
disp(['Data loaded: MC_AC25 - ',mc_description]);


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% TORQUE AND SPEED ranges
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% N-m, torque vector corresponding to columns of efficiency & loss maps
mc_map_trq=[-250  -225  -200  -175  -150  -125  -100   -75   -50   -25 0 25 50 75 100 125 150 175 200 225 250];

% rad/s, speed vector corresponding to rows of efficiency & loss maps
mc_map_spd=[0 1200 1400 1600 1800 2000 2200 2400 2600 2800 3000 3200 3400 3600 3800 4000 4200 4400 4600 4800 5000 5500].*(2*pi/60);


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% LOSSES AND EFFICIENCIES
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
eff =(0.01*0.98).*[...
83 84 85 84.5 85 84.8 84.59999999999999 84.3 84 83.5 82.8
84 84 86 86 85.8 85.59999999999999 85.59999999999999 85.2 84.5 84 83.3
84 86 87.5 88 88 88 87 86 85 84.5 83.90000000000001
84 87 88.5 90 91 91 90 88 86.2 85.5 84.5
84 87.5 89.5 93.8 93.5 93.8 94.3 91 89.5 86.5 85
84 88 92 94.2 94.5 94.5 95 94 91 91.5 85.8
84 88 92.5 94.59999999999999 95 95.3 95.40000000000001 94.7 92 90.2 85.8
84 88 93 95.59999999999999 96.2 96.3 95.40000000000001 94.90000000000001 93 90.2 85.5
84 88 93 95.8 96.40000000000001 97 95.40000000000001 94.90000000000001 94 90.2 85.8
84 88 92 96 96.59999999999999 97.5 95.40000000000001 94.90000000000001 94 90.2 85.8
84 88 93 95.90000000000001 98 97.5 95.40000000000001 94.90000000000001 94 90.2 85.8
84 88 93 95.90000000000001 97.5 97.5 95.40000000000001 94.90000000000001 94 90.2 85.8
84 88 93 95.59999999999999 97 97.5 95.40000000000001 94.90000000000001 94 90.2 85.8
84 88 93 95.5 96.8 97.3 95.40000000000001 94.90000000000001 94 90.2 85.8
84 86 93 95 96.40000000000001 96.5 95.40000000000001 94.90000000000001 94 90.2 85.8
83.5 85 93 94.8 96.2 96.2 95.40000000000001 94.8 94 90.2 85.8
83.5 84 92 94.59999999999999 95.7 95.7 95.2 94.8 94 90.2 85.8
83.2 83.5 89.5 94.40000000000001 95.2 95.5 95.09999999999999 94.7 94 90.2 85.8
83 83.2 88 94 94.7 95.2 95 94.59999999999999 94 90.2 85.8
82.7 83 86 91 94.3 94.5 94.8 94.59999999999999 94 90.2 85.8
82.5 83.7 85 92 93.8 94.2 94.5 94.5 94 90.2 85.8
82 82.7 83 84 85.2 86 94 94 94 90.2 85.8];
mc_eff_map=[fliplr(eff),eff(:,2:11)];																				
% CONVERT EFFICIENCY MAP TO INPUT POWER MAP
%% find indices of well-defined efficiencies (where speed and torque > 0)
pos_trqs=find(mc_map_trq>0);
pos_spds=find(mc_map_spd>0);

%% compute losses in well-defined efficiency area
[T1,w1]=meshgrid(mc_map_trq(pos_trqs),mc_map_spd(pos_spds));
mc_outpwr1_map=T1.*w1;
mc_losspwr_map=(1./mc_eff_map(pos_spds,pos_trqs)-1).*mc_outpwr1_map;

%% to compute losses in entire operating range
%% ASSUME that losses are symmetric about zero-torque axis, and
%% ASSUME that losses at zero torque are the same as those at the lowest positive
%% torque, and
%% ASSUME that losses at zero speed are the same as those at the lowest positive
%% speed
mc_losspwr_map=[fliplr(mc_losspwr_map) mc_losspwr_map(:,1) mc_losspwr_map];
mc_losspwr_map=[mc_losspwr_map(1,:);mc_losspwr_map];

%% compute input power (power req'd at electrical side of motor/inverter set)
[T,w]=meshgrid(mc_map_trq,mc_map_spd);
mc_outpwr_map=T.*w;
mc_inpwr_map=mc_outpwr_map+mc_losspwr_map;


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% LIMITS
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% max torque curve of the motor indexed by mc_map_spd
mc_max_trq=[240 240 240 240 240 240 240 239.1 237.8 236.6 235.7 234.5 233.1 231.6 230.6 228 225.8 222.9 220.6 217.7 216.2 216]; % (N*m)
mc_max_gen_trq=-1*mc_max_trq; % (N*m), estimate

% maximum overtorque capability (not continuous, because the motor would overheat) 
mc_overtrq_factor=1.5; % (--), estimated

mc_max_crrnt=200; % (A), maximum current allowed by the controller and motor
mc_min_volts=70; % (V), minimum voltage allowed by the controller and motor


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% DEFAULT SCALING
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% (--), used to scale mc_map_spd to simulate a faster or slower running motor 
mc_spd_scale=1.0;

% (--), used to scale mc_map_trq to simulate a higher or lower torque motor
mc_trq_scale=1.0;


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% OTHER DATA		
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%													
mc_inertia=0.0383;		% rotor's rotational inertia, kg-m^2, unknown

% sum of motor and controller mass																		
mc_mass=12+7.5;

% motor/controller thermal model 
mc_th_calc=1;                             % --     0=no mc thermal calculations, 1=do calc's
mc_cp=430;                                % J/kgK  ave heat capacity of motor/controller (estimate: ave of SS & Cu)
mc_tstat=45;                              % C      thermostat temp of motor/controler when cooling pump comes on
mc_area_scale=(mc_mass/91)^0.7;           % --     if motor dimensions are unknown, assume rectang shape and scale vs AC75
mc_sarea=0.4*mc_area_scale;               % m^2    total module surface area exposed to cooling fluid (typ rectang module)

%the following variable is not used directly in modelling and should always be equal to one
%it's used for initialization purposes
mc_eff_scale=1;

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% CLEAN UP
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
clear T w mc_outpwr_map mc_outpwr1_map mc_losspwr_map T1 w1 pos_spds pos_trqs
clear mc_description1 mc_description2


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% REVISION HISTORY
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% 2/3/99  (SB): added thermal model variables
% 3/15/99:ss updated *_version to 2.1 from 2.0

% 11/03/99:ss updated version from 2.2 to 2.21
% % 11/1/00:tm added max gen trq placeholder data
% Begin added by ADVISOR 3.2 converter: 30-Jul-2001
mc_mass_scale_coef=[1 0 1 0];

mc_mass_scale_fun=inline('(x(1)*mc_trq_scale+x(2))*(x(3)*mc_spd_scale+x(4))*mc_mass','x','mc_spd_scale','mc_trq_scale','mc_mass');

% End added by ADVISOR 3.2 converter: 06/04/2020