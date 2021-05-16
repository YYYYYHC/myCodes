clc,clear,close all
x=linspace(-2,2,40);
y=x;
z=x;
[X,Y,Z]=meshgrid(x,y,z);
w=X.^2+Y.^2+Z.^2;
slice(X,Y,Z,w,[-1,0,1],[-1,0,1],[-1,0,1]);
colorbar;