

clc
close all 
clear all 

saveNamePre = 'dataFiles/DF_007_distanceParams_Jetson'
addpath("functions/")

jetsonSN    = '001'
setNum      = '2'

actualDistances   = [40:10:320];
cutOffs(1) = 0

for n= 1:length(actualDistances)-1
    cutOffs(n+1) = (actualDistances(n) + actualDistances(n+1))/2;
end

% Gained through visual investigation 
rawDistances = [1005,925,765,657,572,512,460,418,382,352,...
                 320,307,289,270,256,240,227,220,208,200, ...
                 192,182,176,167,160,157,147,144,143 ...
                ]';
            
            
xData = actualDistances';
yData = rawDistances ;
% Set up fittype and options.
ft = fittype( 'power1' );
opts = fitoptions( 'Method', 'NonlinearLeastSquares' );
opts.Display = 'Off';
opts.StartPoint = [132298.119290413 -1.18732029745298];

% Fit model to data.
[fitresult, gof] = fit( xData, yData, ft, opts )

% Plot fit with data.
figure( 'Name', 'Power Fit' );
h = plot( fitresult, xData, yData );
legend( h, 'data', 'fit', 'Location', 'NorthEast', 'Interpreter', 'none' );
% Label axes
xlabel( 'Raw Distance', 'Interpreter', 'none' );
ylabel( 'Actual Distance (cm)', 'Interpreter', 'none' );
title('Actual Distances vs Raw Distances')
grid on
a=fitresult.a;
b=fitresult.b;

save( getSaveNameJetson(saveNamePre,jetsonSN,setNum), 'fitresult', 'a', 'b', 'actualDistances','cutOffs')
