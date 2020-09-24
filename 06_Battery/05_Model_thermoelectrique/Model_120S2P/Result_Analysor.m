s=input('Number of cells along the axe :   ');
p=floor(size(struct2cell(out.temperature),1)/s);
figure;
subplot(1,2,1);ylabel('Temperature(^oC)');
names=fieldnames(out.temperature);tem=[];label=[];
for i = 1:length(names)
    name=names(i);name=name{1};
    eval(['out.temperature.',name,'.Name="Temperature(^oC)";']);
    tem_i=eval(['out.temperature.',name]);
    tem=[tem,tem_i.Data(length(tem_i))];
    hold on;plot(tem_i);
    label=[label;['S',num2str(ceil(i/s).','%03d'),...
        'P',num2str(1+mod(i,s).','%03d')]];
end
legend(label);title("Evolution of each cell's Temperature");
clear tem_i;

subplot(1,2,2);ylabel('SOC(.)');
names=fieldnames(out.soc);soc=[];
for i = 1:length(names)
    name=names(i);name=name{1};
    eval(['out.soc.',name,'.Name="SOC(.)";']);
    soc_i=eval(['out.soc.',name]);
    soc=[soc,soc_i.Data(length(soc_i))];
    plot(soc_i);
end
legend(label);title("Evolution of each cell's SOC(State of Charge)");
clear soc_i;

clear label;clear name;clear names;clear i;

figure;
subplot(1,2,1);out.Power.Name='Power(kW)';ylabel('Power(kW)');
plot(out.Power);title("Evolution of total power");
subplot(1,2,2);out.ocv.Name='Voltage';ylabel('Voltage(V)');
plot(out.ocv);title("Evolution of total voltage");

figure;
subplot(1,2,1);tem = reshape(tem,s,p);
if max(max(tem)) == min(min(tem))
    tem(1,1)=tem(1,1)-1e-12;
end
contourf(tem,15:0.5:65,'ShowText','on');
title("Final distribution of temperature");

subplot(1,2,2);soc = reshape(soc,s,p);
if max(max(soc)) == min(min(soc))
    soc(1,1)=soc(1,1)-1e-12;
end
contourf(soc,1:-0.01:0,'ShowText','on');
title("Final distribution of SOC");

clear tem;clear soc;
clear s;clear p;