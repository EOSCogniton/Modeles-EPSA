function resu=flat_voiture(Ay)
Ms = 239 ;
g = 9.81 ;
b = 690e-3 ;
e = 1570e-3 ;
v = 1240e-3 ;
Dh = 154e-3 ;
Hf = 115e-3 ;
Hr = 152.5e-3 ;
kf = 15000 ;
kr = 12000 ;
lf = 0 ;
lr = 0 ;
Lf = lf + 0.5*kf/v ;
Lr = lr + 0.5*kr/v ;
%Trf = (Ms*Ay*g/v)*((Dh*Lf/(Lf+Lr))+b*Hf/e) ;
%Trr = (Ms*Ay*g/v)*((Dh*Lr/(Lf+Lr))+(e-b)*Hr/e) ;
Trf = (Ms*Ay*g/v)*((Dh*1)+b*Hf/e) ;
Trr = (Ms*Ay*g/v)*((Dh*0)+(e-b)*Hr/e) ;

Fymax_fl = flat((239*0.44*0.5 + 16.5)*g + Trf) ;
Fymax_fr = flat((239*0.44*0.5 + 16.5)*g - Trf) ;
Fymax_rl = flat((239*0.56*0.5 + 16.5)*g + Trr) ;
Fymax_rr = flat((239*0.56*0.5 + 16.5)*g - Trr) ;
resu = [Fymax_fl+Fymax_fr Fymax_rl+Fymax_rr] ;
end