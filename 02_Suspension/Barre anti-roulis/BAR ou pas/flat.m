function resu=flat(N)
q = 0.483 ; %coef multiplicateur des testeurs de pneus
resu=q*(-(N - 500).*(7.4E-4) + 2.95) .* N ;
end