function [Cmot_limited] = power_limit_torque(rmot,cmot,Pmax,efficiency,eff_cont)

% plot(rmot,cmot,'--',"DisplayName",'without power limit')
% title('Motor curb for motor EMRAX 228 CC')

%%On estime le pire cas pour l'efficiency pour se rapporcher du vraai point de fonctionnement
emot = 0.9; % electrical efficiency of the motor

Cmax = Pmax*eff_cont*emot.*ones(length(rmot),1)./(rmot*2*pi/60);
id_max_case = (Cmax<cmot);
Cmot_limited = id_max_case.*Cmax + (1-id_max_case).*cmot;
Cmax2 = zeros(length(rmot));
%% afinement avec une efficiency moteur plus réaliste
Cmax2 = zeros(length(rmot),1);
for id=1:length(rmot)
    Cmax = Pmax*eff_cont/(rmot(id)*2*pi/60)*get_efficency(rmot(id),abs(Cmot_limited(id)),efficiency);
    
    Cmax2(id) = Cmax;
end
id_max_case = (Cmax2<cmot);
Cmot_limited = id_max_case.*Cmax2 + (1-id_max_case).*cmot;

% hold on
% plot(rmot,Cmot_limited,"DisplayName",'with power limit')
% xlabel('Motor Speed (rpm)')
% ylabel('Motor Torque (N.m)')
% legend

end
