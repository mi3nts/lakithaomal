% Auto-generated by cameraCalibrator app on 10-Apr-2020
%-------------------------------------------------------
clc
clear all
close all 

addpath("functions/")

jetsonSN    = '002'
setNum      = '1'


saveNamePrePython    = 'DF_004_pythonThermalJetson'
saveNamePreMatLabAll = 'DF_004_thermalParametorsJetson'
saveNamePreMatLab    = 'DF_004_thermalParametorsJetsonThermal'

% Define images to process
imageFileNames = {...
    '/home/teamlary/mintsData/jetson002Set1/thermal/2020_04_09_19_53_12_951848_thermal.jpg',...
    '/home/teamlary/mintsData/jetson002Set1/thermal/2020_04_09_19_53_36_036249_thermal.jpg',...
    '/home/teamlary/mintsData/jetson002Set1/thermal/2020_04_09_19_53_54_772552_thermal.jpg',...
    '/home/teamlary/mintsData/jetson002Set1/thermal/2020_04_09_19_54_20_326969_thermal.jpg',...
    '/home/teamlary/mintsData/jetson002Set1/thermal/2020_04_09_19_54_41_284758_thermal.jpg',...
    '/home/teamlary/mintsData/jetson002Set1/thermal/2020_04_09_19_55_11_759111_thermal.jpg',...
    '/home/teamlary/mintsData/jetson002Set1/thermal/2020_04_09_19_55_56_060261_thermal.jpg',...
    '/home/teamlary/mintsData/jetson002Set1/thermal/2020_04_09_19_56_30_993626_thermal.jpg',...
    '/home/teamlary/mintsData/jetson002Set1/thermal/2020_04_09_19_57_00_937629_thermal.jpg',...
    '/home/teamlary/mintsData/jetson002Set1/thermal/2020_04_09_19_57_31_509844_thermal.jpg',...
    '/home/teamlary/mintsData/jetson002Set1/thermal/2020_04_09_19_58_05_900426_thermal.jpg',...
    '/home/teamlary/mintsData/jetson002Set1/thermal/2020_04_09_19_58_53_118418_thermal.jpg',...
    '/home/teamlary/mintsData/jetson002Set1/thermal/2020_04_09_19_59_32_610982_thermal.jpg',...
    '/home/teamlary/mintsData/jetson002Set1/thermal/2020_04_09_20_00_03_014975_thermal.jpg',...
    '/home/teamlary/mintsData/jetson002Set1/thermal/2020_04_09_20_00_38_070443_thermal.jpg',...
    '/home/teamlary/mintsData/jetson002Set1/thermal/2020_04_09_20_01_28_096171_thermal.jpg',...
    '/home/teamlary/mintsData/jetson002Set1/thermal/2020_04_09_20_01_56_644711_thermal.jpg',...
    '/home/teamlary/mintsData/jetson002Set1/thermal/2020_04_09_20_03_06_284881_thermal.jpg',...
    '/home/teamlary/mintsData/jetson002Set1/thermal/2020_04_09_20_04_26_111613_thermal.jpg',...
    '/home/teamlary/mintsData/jetson002Set1/thermal/2020_04_09_20_05_02_687697_thermal.jpg',...
    '/home/teamlary/mintsData/jetson002Set1/thermal/2020_04_09_20_05_26_049710_thermal.jpg',...
    '/home/teamlary/mintsData/jetson002Set1/thermal/2020_04_09_20_05_51_379794_thermal.jpg',...
    '/home/teamlary/mintsData/jetson002Set1/thermal/2020_04_09_20_06_51_695544_thermal.jpg',...
    '/home/teamlary/mintsData/jetson002Set1/thermal/2020_04_09_20_07_28_784957_thermal.jpg',...
    '/home/teamlary/mintsData/jetson002Set1/thermal/2020_04_09_20_07_53_843112_thermal.jpg',...
    '/home/teamlary/mintsData/jetson002Set1/thermal/2020_04_09_20_08_17_765157_thermal.jpg',...
    '/home/teamlary/mintsData/jetson002Set1/thermal/2020_04_09_20_08_46_031450_thermal.jpg',...
    };

%% Detect checkerboards in images
[imagePoints, boardSize, imagesUsed] = detectCheckerboardPoints(imageFileNames);
imageFileNames = imageFileNames(imagesUsed);

% Read the first image to obtain image size
originalImage = imread(imageFileNames{1});
[mrows, ncols, ~] = size(originalImage);

% Generate world coordinates of the corners of the squares
squareSize = 35;  % in units of 'millimeters'
worldPoints = generateCheckerboardPoints(boardSize, squareSize);

% Calibrate the camera
[thermalParams, imagesUsed, estimationErrors] = estimateCameraParameters(imagePoints, worldPoints, ...
    'EstimateSkew', false, 'EstimateTangentialDistortion', false, ...
    'NumRadialDistortionCoefficients', 2, 'WorldUnits', 'millimeters', ...
    'InitialIntrinsicMatrix', [], 'InitialRadialDistortion', [], ...
    'ImageSize', [mrows, ncols]);

% View reprojection errors
h1=figure; showReprojectionErrors(thermalParams);

% Visualize pattern locations
h2=figure; showExtrinsics(thermalParams, 'CameraCentric');

% Display parameter estimation errors
displayErrors(estimationErrors, thermalParams);

% For example, you can use the calibration data to remove effects of lens distortion.
undistortedImage = undistortImage(originalImage, thermalParams);

save(getSaveNameJetson(saveNamePreMatLabAll,jetsonSN,setNum))
save(getSaveNameJetson(saveNamePreMatLab,jetsonSN,setNum),'thermalParams')
save(getSaveNameJetson(saveNamePrePython,jetsonSN,setNum),...
        'imageFileNames',...
        'imagePoints'...
        )  

close all
