%% initialisation (nous)

Ms = 239 ; %masse suspendue
M = 305 ; %masse totale
q = 0.483 ; %coef multiplicateur des testeurs de pneus
g = 9.81 ;
b = 690e-3 ; %distance entre essieu arrière et CG (en m)
e = 1570e-3 ; %empattement (en m)
v = 1240e-3 ; %voie (en m)
h = 290e-3 ;
% Hf = 84.8e-3 ;
% Hr = 59.5e-3 ;
% Dh = h - (b*Hf + (e-b)*Hr)/e ;
% kf = 10900 ;
% kr = 13200 ;
% lf = 0 ;
% lr = 0 ;
% Lf = lf + 0.5*kf*v^2 ;
% Lr = lr + 0.5*kr*v^2 ;


%% initialisation (laurent)

M = 300 ; 
g = 9.81 ;
e = 1200e-3 ; 
v = 1200e-3 ; 
b = 500e-3 ;
h = 300e-3 ;
kf = 10000 ;
kr = 12000 ;
lf = 0 ;
lr = 0 ;
Lf = lf + 0.5*kf*v^2 ;
Lr = lr + 0.5*kr*v^2 ;


%% vecteurs pour la tracé (nous)
Ay = linspace(0,1.3,100) ;
Fy_rec_f = zeros(1,100) ;
Fy_rec_r = zeros(1,100) ;
Fy_max_f = zeros(1,100) ;
Fy_max_r = zeros(1,100) ;

for i=1:100
    Trf = (M*Ay(i)*g/v)*((Dh*Lf/(Lf+Lr))+b*Hf/e) ;
    Trr = (M*Ay(i)*g/v)*((Dh*Lr/(Lf+Lr))+(e-b)*Hr/e) ;
    Fymax_fl = q*(-(((239*0.44*0.5 + 16.5)*g + Trf) - 500).*(5E-4) + 2.65) .* ((239*0.44*0.5 + 16.5)*g + Trf) ;
    Fymax_fr = q*(-(((239*0.44*0.5 + 16.5)*g - Trf) - 500).*(5E-4) + 2.65) .* ((239*0.44*0.5 + 16.5)*g - Trf) ;
    Fymax_rl = q*(-(((239*0.56*0.5 + 16.5)*g + Trr) - 500).*(5E-4) + 2.65) .* ((239*0.56*0.5 + 16.5)*g + Trr) ;
    Fymax_rr = q*(-(((239*0.56*0.5 + 16.5)*g - Trr) - 500).*(5E-4) + 2.65) .* ((239*0.56*0.5 + 16.5)*g - Trr) ;
    Fy_rec_f(i) = M*g*Ay(i)*b/e ;
    Fy_rec_r(i) = M*g*Ay(i)*(e-b)/e ;
    Fy_max_f(i) = Fymax_fl + Fymax_fr ;
    Fy_max_r(i) = Fymax_rl + Fymax_rr ;
end

Fy_rec = Fy_rec_f + Fy_rec_r ;
Fy_max = Fy_max_f + Fy_max_r ;

%% recherche de la répartition avant / arrière de transfert de charge

x = linspace(0,1,100) ; 
Af = zeros(1,100) ;  %accel de décrochage essieu avant
Ar = zeros(1,100) ;  %accel de décrochage essieu arrière
for j=1:100
    Ay = linspace(0,1.5,10000) ;
    Fy_rec_f = zeros(1,10000) ;
    Fy_rec_r = zeros(1,10000) ;
    Fy_max_f = zeros(1,10000) ;
    Fy_max_r = zeros(1,10000) ;

    for i=1:10000
        Trf = h*(M*Ay(i)*g/v)*(x(j)) ;
        Trr = h*(M*Ay(i)*g/v)*(1-x(j)) ;
        Fymax_fl = q*(-(((239*0.44*0.5 + 16.5)*g + Trf) - 500).*(7.4E-4) + 2.95) .* ((239*0.44*0.5 + 16.5)*g + Trf) ;
        Fymax_fr = q*(-(((239*0.44*0.5 + 16.5)*g - Trf) - 500).*(7.4E-4) + 2.95) .* ((239*0.44*0.5 + 16.5)*g - Trf) ;
        Fymax_rl = q*(-(((239*0.56*0.5 + 16.5)*g + Trr) - 500).*(7.4E-4) + 2.95) .* ((239*0.56*0.5 + 16.5)*g + Trr) ;
        Fymax_rr = q*(-(((239*0.56*0.5 + 16.5)*g - Trr) - 500).*(7.4E-4) + 2.95) .* ((239*0.56*0.5 + 16.5)*g - Trr) ;
        Fy_rec_f(i) = M*g*Ay(i)*b/e ;
        Fy_rec_r(i) = M*g*Ay(i)*(e-b)/e ;
        Fy_max_f(i) = Fymax_fl + Fymax_fr ;
        Fy_max_r(i) = Fymax_rl + Fymax_rr ;
    end
    i = 1 ;
    while Fy_rec_f(i) < Fy_max_f(i)
        i = i+1 ;
    end
    Af(j) = Ay(i) ;
    i = 1 ;
    while Fy_rec_r(i) < Fy_max_r(i)
        i = i+1 ;
    end
    Ar(j) = Ay(i) ;
end

plot(x,Af,'-b') ;
hold on ;
plot(x,Ar,'-r') ;
xlabel('proportion de transfert de charge à l avant') ;
ylabel('accel de décrochage de l essieu (en g)') ;
legend({'avant','arrière'},'Location','southwest')

%% recherche de la raideur de BAR
v = 1240e-3 ;
b = 690e-3 ;
e = 1570e-3 ;
h = 290e-3 ;
Hr = 95e-3 ;
Hf = 67e-3 ;
Dh = h - (b*Hf + (e-b)*Hr)/e ;
kt = 80000 ; %tire stiffness
kf = 10900 ; %front ride rate
kr = 13200 ; %rear ride rate
kwf = kt*kf/(kt-kf) ; %front wheel rate
kwr = kt*kr/(kt-kr) ; %rear wheel rate
% kwf = 175*175,126835 ;
% kwr = 200*175,126835 ;
% kf = kt*kwf/(kt+kwf) ;
% kr = kt*kwr/(kt+kwr) ;
lf = linspace(0,100000,100) ; %raideur associée à la BAR (en N.m)
Lf = ((lf + 0.5*kwf*v^2).^(-1) + (0.5*kt*v^2)^(-1)).^(-1);
Lr = 0.5*kr*v^2 ; % =(0.5*kwr*v^2)^(-1) + (0.5*kt*v^2)^(-1)).^(-1)
Af = zeros(1,100) ;  %accel de décrochage essieu avant
Ar = zeros(1,100) ;  %accel de décrochage essieu arrière
for j=1:100
    Ay = linspace(0,1.5,10000) ;
    Fy_rec_f = zeros(1,10000) ;
    Fy_rec_r = zeros(1,10000) ;
    Fy_max_f = zeros(1,10000) ;
    Fy_max_r = zeros(1,10000) ;

    for i=1:10000
        Trf = (M*Ay(i)*g/v)*(Dh*(Lf(j)/(Lf(j)+Lr))+b*Hf/e) ;
        Trr = (M*Ay(i)*g/v)*(Dh*(Lr/(Lf(j)+Lr))+(e-b)*Hr/e) ;
        Fymax_fl = q*(-(((239*0.44*0.5 + 16.5)*g + Trf) - 500).*(7.4E-4) + 2.95) .* ((239*0.44*0.5 + 16.5)*g + Trf) ;
        Fymax_fr = q*(-(((239*0.44*0.5 + 16.5)*g - Trf) - 500).*(7.4E-4) + 2.95) .* ((239*0.44*0.5 + 16.5)*g - Trf) ;
        Fymax_rl = q*(-(((239*0.56*0.5 + 16.5)*g + Trr) - 500).*(7.4E-4) + 2.95) .* ((239*0.56*0.5 + 16.5)*g + Trr) ;
        Fymax_rr = q*(-(((239*0.56*0.5 + 16.5)*g - Trr) - 500).*(7.4E-4) + 2.95) .* ((239*0.56*0.5 + 16.5)*g - Trr) ;
        Fy_rec_f(i) = M*g*Ay(i)*b/e ;
        Fy_rec_r(i) = M*g*Ay(i)*(e-b)/e ;
        Fy_max_f(i) = Fymax_fl + Fymax_fr ;
        Fy_max_r(i) = Fymax_rl + Fymax_rr ;
    end
    i = 1 ;
    while Fy_rec_f(i) < Fy_max_f(i)
        i = i+1 ;
    end
    Af(j) = Ay(i) ;
    i = 1 ;
    while Fy_rec_r(i) < Fy_max_r(i)
        i = i+1 ;
    end
    Ar(j) = Ay(i) ;
end

% plot(lf*2*pi/360,Af,'-g') ;
% hold on ;
% plot(lf*2*pi/360,Ar,'-y') ;
plot(lf,Af,'-b') ;
hold on ;
plot(lf,Ar,'-r') ;
% xlabel('raideur antiroulis liée à la BAR (en N.m/deg)') ;
xlabel('raideur antiroulis liée à la BAR (en N.m/rad)') ;
ylabel('accel de décrochage de l essieu (en g)') ;
legend({'avant','arrière'},'Location','southwest') ;
%% vecteurs pour la tracé (laurent)
Ay = linspace(0,1.3,100) ;
Fy_rec_f = zeros(1,100) ;
Fy_rec_r = zeros(1,100) ;
Fy_max_f = zeros(1,100) ;
Fy_max_r = zeros(1,100) ;

for i=1:100
    Trf = (Ms*Ay(i)*g/v)*(h*Lf/(Lf+Lr)) ;
    Trr = (Ms*Ay(i)*g/v)*(h*Lr/(Lf+Lr)) ;
    Fymax_fl = (-((239*0.44*0.5 + 16.5)*g + Trf).*0.2/1500 + 1.3) .* ((239*0.44*0.5 + 16.5)*g + Trf) ;
    Fymax_fr = (-((239*0.44*0.5 + 16.5)*g - Trf).*0.2/1500 + 1.3) .* ((239*0.44*0.5 + 16.5)*g - Trf) ;
    Fymax_rl = (-((239*0.56*0.5 + 16.5)*g + Trr).*0.2/1500 + 1.3) .* ((239*0.56*0.5 + 16.5)*g + Trr) ;
    Fymax_rr = (-((239*0.56*0.5 + 16.5)*g - Trr).*0.2/1500 + 1.3) .* ((239*0.56*0.5 + 16.5)*g - Trr) ;
    Fy_rec_f(i) = M*g*Ay(i)*b/e ;
    Fy_rec_r(i) = M*g*Ay(i)*(e-b)/e ;
    Fy_max_f(i) = Fymax_fl + Fymax_fr ;
    Fy_max_r(i) = Fymax_rl + Fymax_rr ;
end

Fy_rec = Fy_rec_f + Fy_rec_r ;
Fy_max = Fy_max_f + Fy_max_r ;

%% le graphe

plot(g*Ay,Fy_rec,':r') ;
hold on ;
plot(g*Ay,Fy_max,'-r') ;
hold on
plot(g*Ay,Fy_rec_f,':b') ;
hold on ;
plot(g*Ay,Fy_max_f,'-b') ;
hold on
plot(g*Ay,Fy_rec_r,':g') ;
hold on ;
plot(g*Ay,Fy_max_r,'-g') ;

xlabel('Accélération latérale') ;
ylabel('Effort roue') ;
legend({'Force latérale total requise','Force latérale totale disponible','Force latérale requise à l avant','Force latérale disponible à l avant','Force latérale requise à l arrière','Force latérale disponible à l arrière'},'Location','southwest')

%% sus

f = linspace(1,2.5,100) ;
k_f = ((2*pi*f).^2)*(320*0.44*0.5+16) ;
k_r = ((2*pi*f).^2)*(320*0.56*0.5+16) ;

plot(f,k_f,'r') ;
hold on ;
plot(f,k_r,'b') ;