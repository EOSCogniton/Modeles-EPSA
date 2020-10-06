length = sum(sqrt(diff(track(:,1)).^2+diff(track(:,2)).^2));
X = ['La longueur du circuit est de ',num2str(length),'m'];
disp(X)
