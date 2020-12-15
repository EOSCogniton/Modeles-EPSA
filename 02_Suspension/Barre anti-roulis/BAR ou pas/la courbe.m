M = 305 ;
g = 9.81 ;
b = 690e-3 ;
e = 1570e-3 ;
Ay = linspace(0,1.3,100) ;
Fy_rec_f = zeros(1,100) ;
Fy_rec_r = zeros(1,100) ;
Fy_max_f = zeros(1,100) ;
Fy_max_r = zeros(1,100) ;
for i=1:100
    flat_voit = flat_voiture(Ay(i)) ;
    Fy_rec_f(i) = M*g*Ay(i)*b/e ;
    Fy_rec_r(i) = M*g*Ay(i)*(e-b)/e ;
    Fy_max_f(i) = flat_voit(1) ;
    Fy_max_r(i) = flat_voit(2) ;
end
Fy_rec = Fy_rec_f + Fy_rec_r ;
Fy_max = Fy_max_f + Fy_max_r ;

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
hold on

xlabel('Accélération latérale') ;
ylabel('Effort roue') ;
legend({'Force latérale total requise','Force latérale totale disponible','Force latérale requise à l avant','Force latérale disponible à l avant','Force latérale requise à l arrière','Force latérale disponible à l arrière'},'Location','southwest')
