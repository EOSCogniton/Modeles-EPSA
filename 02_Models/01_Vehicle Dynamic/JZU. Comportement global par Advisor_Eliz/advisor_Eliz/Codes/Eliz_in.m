% Eliz_in.m  ADVISOR 2003-00-r0116 input file created: 06-Apr-2020 22:15:26
% Created by JZU, jinhan.zhou@ecl19.ec-lyon.fr

global vinf 

vinf.name='Eliz_in';
vinf.drivetrain.name='ev';
vinf.motor_controller.name='MC_ERMAX228';
vinf.energy_storage.name='ESS_18650';
vinf.energy_storage.ver='rint';
vinf.energy_storage.type='li';
vinf.transmission.name='TX_1SPD_Focus';
vinf.transmission.ver='man';
vinf.transmission.type='man';
vinf.wheel_axle.name='WH_FOCUS_REGEN';
vinf.wheel_axle.ver='Crr';
vinf.wheel_axle.type='Crr';
vinf.vehicle.name='VEH_Eliz';
vinf.powertrain_control.name='PTC_EV';
vinf.powertrain_control.ver='ev';
vinf.powertrain_control.type='man';
vinf.accessory.name='ACC_EV_Focus';
vinf.accessory.ver='Const';
vinf.accessory.type='Const';
vinf.variables.name{1}='wh_rear_active_bool';
vinf.variables.value(1)=1;
vinf.variables.default(1)=0;
vinf.variables.name{2}='wh_front_active_bool';
vinf.variables.value(2)=0;
vinf.variables.default(2)=1;
vinf.variables.name{3}='cs_lo_soc';
vinf.variables.value(3)=0.3;
vinf.variables.default(3)=0;
