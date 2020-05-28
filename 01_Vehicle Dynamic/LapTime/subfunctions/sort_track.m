function [X_sort,Y_sort] = sort_track(X,Y)
    X_sort=zeros(length(X),1);
    Y_sort=zeros(length(X),1);
    k=1;
    for id =1:length(X)-1
        X_sort(id) = X(k);
        Y_sort(id) = Y(k);
        X(k) = [];
        Y(k) = [];
        k = dsearchn([X,Y],[X_sort(id),Y_sort(id)]);
    end
    X_sort(end) = X(k);
    Y_sort(end) = Y(k);
end