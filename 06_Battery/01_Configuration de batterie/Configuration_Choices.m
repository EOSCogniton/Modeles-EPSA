clear all;close all;clc;

%Settings
set(0, 'DefaultLineLineWidth', 1, ...
           'DefaultTextInterpreter', 'LaTeX', ...
           'DefaultAxesTickLabelInterpreter', 'LaTeX', ...
           'DefaultAxesFontName', 'LaTeX', ...
           'DefaultLegendInterpreter', 'LaTeX', ...
           'DefaultAxesLineWidth', .5, ...
           'DefaultAxesFontSize', 10);

ns = 1:1:30;
np = 1:1:40;
D_cell=18.5e-3; %Diameter of the cell (in this case : model 18650) [m]
H_cell=65.2e-3; %height of the cell [m]

[X,Y] = meshgrid(ns,np);
Z = X.*Y.*(D_cell^2)*H_cell;
contour(X,Y,Z,'ShowText','on')
xlabel("number of cells in serie")
ylabel("number of cells in parallel")