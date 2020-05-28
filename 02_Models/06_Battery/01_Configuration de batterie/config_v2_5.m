clear all;close all;clc;
an=input("Do you have a data ? (yes-0/no-1): \t");
if an==0
    input("Please load it and press space to continue...")
    an=input("Is there a geometric limitation ? (yes-0/no-1):\t");
    if an==1
        d_lo=Inf;
        d_la=Inf;
        d_h=Inf;
    end
else
    %% Limitation of the Rules
    V_lim=600;
    V_seg_lim=120;
    E_seg_lim=1.833;
    m_seg_lim=12e3;
    P_inf=40;
    
    %% Desire of comportements
    V_des=input("Set your parameters of desire: \n  Total Maximal Voltage (V): \t");
    
    %% Energetic parameters of cell
    I_cell=input("Set energetic parameters of cell : \n  Cell Maximal Continuous Discharge Courant (A): \t");
    I_cell_ch=input("Cell Maximal Continuous Charge Courant (A): \t");
    E_cell=input("  Cell Energy (kW.h): \t");
    V_cell=input("  Cell Maximal Voltage (V): \t");
    R_cell=input("  Cell Maximal Resistance (Ohm): \t")
    C_cell=input("  Cell Maximal Capacity (Ah): \t")
    %% Geometric parameters of cell
    d_cell_lo=input("Set geometric parameter of cell :\n  Cell Length (mm): \t");
    d_cell_la=input("  Cell Width (mm): \t");
    d_cell_h=input("  Cell Height (mm): \t");
    m_cell=input("  Cell Mass (g) : \t");
    %% Geometric parameters of volume:
    an=input("Is there a geometric limitation ? (yes-0/no-1): \t");
    if an==0
        d_lo=input("Set geometric limitation :\n  Volume Length (mm): \t");
        d_la=input("  Volume Width (mm): \t");
        d_h=input("  Volume Height (mm): \t");
    else
        d_lo=Inf;
        d_la=Inf;
        d_h=Inf;
    end
end

d=[d_lo,d_la,d_h;d_lo,d_h,d_la;d_la,d_lo,d_h;d_la,d_h,d_lo;d_h,d_lo,d_la;d_h,d_la,d_lo];
d_ordre=[1,2,3;1,3,2;2,1,3;2,3,1;3,1,2;3,2,1];name=["cell_length","cell_width","cell_height"];

%% Calcul ns->nseg->np:
n_cell=0;config=[0,0,100];
for k=1:6
    for ns=5:floor(V_seg_lim/V_cell)
        for nseg=ceil(0.6*V_des/V_cell/ns):floor(min(d(k,3)/d_cell_h,V_lim/V_cell/ns))
            np=floor(min([floor(d(k,1)/d_cell_lo)*floor(d(k,2)/d_cell_la)/ns,m_seg_lim/m_cell/ns,E_seg_lim/E_cell/ns]));
            if np*ns*nseg>n_cell
                n_cell=np*ns*nseg;
                index=k;
                config=[nseg,ns,np];
            else
                if np*ns*nseg==n_cell
                    if nseg<config(1)
                        index=k;
                        config=[nseg,ns,np];
                    else
                        if np>config(2)
                            index=k;
                            config=[nseg,ns,np];
                        end
                    end
                end
            end
        end
    end
end
config_LWH=[0,0,0];
config_LWH(d_ordre(index,3))=config(1);
dL=Inf;
if an==1
    for n=1:floor(sqrt(config(2)*config(3)))
        if (mod(config(2)*config(3),n)==0) && (abs(n*d_cell_lo-config(2)*config(3)/n*d_cell_la)<dL)
            dL=abs(config_LWH(d_ordre(index,1))*d_cell_lo-config_LWH(d_ordre(index,2))*d_cell_la);
            config_LWH(d_ordre(index,1))=n;
            config_LWH(d_ordre(index,2))=config(2)*config(3)/n;
        end
    end
else
    config_LWH(d_ordre(index,1))=floor(d(index,1)/d_cell_lo);
    config_LWH(d_ordre(index,2))=floor(d(index,2)/d_cell_la);
end
config_name(d_ordre(index,1))=name(1);
config_name(d_ordre(index,2))=name(2);
config_name(d_ordre(index,3))=name(3);
d_ordre_cell=[1,2,3];d_ordre_cell=d_ordre(index,d_ordre(index,:));
d_cell=[d_cell_lo,d_cell_la,d_cell_h];d_cell=d_cell(d_ordre_cell);
config_seg_vide=config_LWH(1)*config_LWH(2)*config_LWH(3)-config(1)*config(2)*config(3);
Configuration=int2str(config(1))+"seg_"+int2str(config(2))+"s"+int2str(config(3))+"p | Length:"+int2str(config_LWH(1))+config_name(1)+"; Width:"+int2str(config_LWH(2))+config_name(2)+"; Heigth:"+int2str(config_LWH(3))+config_name(3)+" - With "+int2str(config_seg_vide)+" vides in each module.| Volume(L*W*H)="+int2str(config_LWH(1)*d_cell(1))+"*"+int2str(config_LWH(2)*d_cell(2))+"*"+int2str(config_LWH(3)*d_cell(3))

%%  Comportement
power_max_kW=nseg*ns*np*V_cell*I_cell*1e-3
energy_kW.h=nseg*ns*np*E_cell
masse_tot_kg=nseg*ns*np*m_cell/1000
charge_time=E_cell/(V_cell*I_cell_ch)

%% Characters of cell (to change in workspace)
% SOC RANGE over which data is defined
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
soc=[0:.1:1];  % (--)
% Temperature range over which data is defined
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
tmp=[-10 0 10 23 40 45];  % (C)
% Parameters vary by temperature
max_cap=[0.8077,0.8494,0.9071,1.0000,1.0000,1.0000]*C_cell;	% (A.h), max. capacity at C/5 rate, indexed by ess_tmp
% module's resistance to being discharged, indexed by ess_soc and ess_tmp
Rint=[
   1.0000,0.8889,0.8333,0.7222,0.6111,0.5556,0.5278,0.5278,0.5278,0.5278,0.5278;
   1.0000,0.8333,0.7222,0.6111,0.5556,0.5278,0.5000,0.5000,0.5000,0.5000,0.5000;
   1.0000,0.7222,0.6111,0.5556,0.5000,0.4722,0.4722,0.4722,0.4722,0.4722,0.4722;
   1.0000,0.4444,0.4444,0.4444,0.4444,0.4444,0.4444,0.4444,0.4444,0.4444,0.4444;
   1.0000,0.4444,0.4444,0.4444,0.4444,0.4444,0.4444,0.4444,0.4444,0.4444,0.4444;
   1.0000,0.4444,0.4444,0.4444,0.4444,0.4444,0.4444,0.4444,0.4444,0.4444,0.4444
]*R_cell; % (ohm)
voc=[0.7143,0.8762,0.8905,0.8976,0.9024,0.9095,0.9214,0.9333,0.9476,0.9667,1.0000]*V_cell; % (V)
input("Now, you can check these CELL's characters in function of Temperature and SOC at WORKSPACE: \n   Rint(tmp,soc)\n   voc(soc)\n   max_cap(tmp)\n      where, Rint is Inner Resistance, voc is VOC(Voltage in Open Circuit), max_cap is Maximal Capacity, soc is SOC(State of Charge) and tmp is Temperature.You can change these parameters with your own data and press ENTRE to continue once you have finished the modification.")

%% Plot
figure;subplot(2,2,1);
plot(tmp,nseg*ns*np*max_cap);xlabel('Temperature(^oC)');ylabel('Capacity(A.h)');title('Estimated Maximal Capacityin different Temperature');
subplot(2,2,2);[c,h]=contour(soc*100,tmp,nseg*ns/np*Rint);
xlabel('SOC(%)');ylabel('Tempearture(^oC)');clabel(c,h);title('Estimated Inner Resistor(Ohm)');
subplot(2,2,3);plot(soc*100,nseg*ns*voc)
xlabel('SOC(%)');ylabel('Voltage(V)');title('Estimated VOC with different SOC');
subplot(2,2,4);plot(soc*100,nseg*ns*np*voc*I_cell*0.9*1e-3)
xlabel('SOC(%)');ylabel('Power(kW)');title('Estimated Maximal Power with different SOC');

%% Stock of data
clear k;clear index;clear an;clear d;clear config;clear config_LWH;clear config_name;clear config_seg_vide;clear d_ordre;clear name;
save('test.mat')