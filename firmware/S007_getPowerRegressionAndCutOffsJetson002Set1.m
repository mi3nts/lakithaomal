

clc
close all 
clear all 

saveNamePre = 'DF_007_distanceParams_Jetson'
addpath("functions/")

jetsonSN    = '002'
setNum      = '1'

actualDistances   = [40:10:301];
cutOffs(1) = 0

for n= 1:length(actualDistances)-1
    cutOffs(n+1) = (actualDistances(n) + actualDistances(n+1))/2;
end

% Gained through visual investigation 
rawDistances =  [1010,944,778,670,583,520,468,422,390,360,  ...
                 336 ,315,292,275,259,254,241,225,212,208, ...
                 197 ,192,177,176,165,160,158 ...
                ];
            
            
xData  = actualDistances';
yData = rawDistances' ;
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
