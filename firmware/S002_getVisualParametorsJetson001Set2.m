% Auto-generated by stereoCalibrator app on 01-Apr-2020
%-------------------------------------------------------

% Define images to process
imageFileNames1 = {...
    '/home/teamlary/mintsData/jetson001Set2/leftResized/2020_04_01_00_40_28_394452_leftResized.jpg',...
    '/home/teamlary/mintsData/jetson001Set2/leftResized/2020_04_01_00_40_58_660498_leftResized.jpg',...
    '/home/teamlary/mintsData/jetson001Set2/leftResized/2020_04_01_00_41_23_667819_leftResized.jpg',...
    '/home/teamlary/mintsData/jetson001Set2/leftResized/2020_04_01_00_41_50_934824_leftResized.jpg',...
    '/home/teamlary/mintsData/jetson001Set2/leftResized/2020_04_01_00_42_14_639005_leftResized.jpg',...
    '/home/teamlary/mintsData/jetson001Set2/leftResized/2020_04_01_00_42_38_403410_leftResized.jpg',...
    '/home/teamlary/mintsData/jetson001Set2/leftResized/2020_04_01_00_43_00_102290_leftResized.jpg',...
    '/home/teamlary/mintsData/jetson001Set2/leftResized/2020_04_01_00_43_36_571202_leftResized.jpg',...
    '/home/teamlary/mintsData/jetson001Set2/leftResized/2020_04_01_00_44_03_296711_leftResized.jpg',...
    '/home/teamlary/mintsData/jetson001Set2/leftResized/2020_04_01_00_44_41_694820_leftResized.jpg',...
    '/home/teamlary/mintsData/jetson001Set2/leftResized/2020_04_01_00_58_52_830652_leftResized.jpg',...
    '/home/teamlary/mintsData/jetson001Set2/leftResized/2020_04_01_00_59_34_349471_leftResized.jpg',...
    '/home/teamlary/mintsData/jetson001Set2/leftResized/2020_04_01_01_00_00_834721_leftResized.jpg',...
    '/home/teamlary/mintsData/jetson001Set2/leftResized/2020_04_01_01_00_32_551930_leftResized.jpg',...
    '/home/teamlary/mintsData/jetson001Set2/leftResized/2020_04_01_01_00_58_447069_leftResized.jpg',...
    '/home/teamlary/mintsData/jetson001Set2/leftResized/2020_04_01_01_01_21_406380_leftResized.jpg',...
    '/home/teamlary/mintsData/jetson001Set2/leftResized/2020_04_01_01_01_57_664492_leftResized.jpg',...
    '/home/teamlary/mintsData/jetson001Set2/leftResized/2020_04_01_01_02_30_368067_leftResized.jpg',...
    '/home/teamlary/mintsData/jetson001Set2/leftResized/2020_04_01_01_02_49_083378_leftResized.jpg',...
    '/home/teamlary/mintsData/jetson001Set2/leftResized/2020_04_01_01_03_13_386326_leftResized.jpg',...
    '/home/teamlary/mintsData/jetson001Set2/leftResized/2020_04_01_01_03_33_189726_leftResized.jpg',...
    '/home/teamlary/mintsData/jetson001Set2/leftResized/2020_04_01_01_03_53_471965_leftResized.jpg',...
    '/home/teamlary/mintsData/jetson001Set2/leftResized/2020_04_01_01_04_13_482513_leftResized.jpg',...
    '/home/teamlary/mintsData/jetson001Set2/leftResized/2020_04_01_01_04_30_012930_leftResized.jpg',...
    '/home/teamlary/mintsData/jetson001Set2/leftResized/2020_04_01_01_04_53_603655_leftResized.jpg',...
    '/home/teamlary/mintsData/jetson001Set2/leftResized/2020_04_01_01_05_10_092858_leftResized.jpg',...
    '/home/teamlary/mintsData/jetson001Set2/leftResized/2020_04_01_01_05_38_782783_leftResized.jpg',...
    '/home/teamlary/mintsData/jetson001Set2/leftResized/2020_04_01_01_05_57_271086_leftResized.jpg',...
    '/home/teamlary/mintsData/jetson001Set2/leftResized/2020_04_01_01_06_11_787439_leftResized.jpg'...
    };

imageFileNames2 = {...
    '/home/teamlary/mintsData/jetson001Set2/rightResized/2020_04_01_00_40_28_394452_rightResized.jpg',...
    '/home/teamlary/mintsData/jetson001Set2/rightResized/2020_04_01_00_40_58_660498_rightResized.jpg',...
    '/home/teamlary/mintsData/jetson001Set2/rightResized/2020_04_01_00_41_23_667819_rightResized.jpg',...
    '/home/teamlary/mintsData/jetson001Set2/rightResized/2020_04_01_00_41_50_934824_rightResized.jpg',...
    '/home/teamlary/mintsData/jetson001Set2/rightResized/2020_04_01_00_42_14_639005_rightResized.jpg',...
    '/home/teamlary/mintsData/jetson001Set2/rightResized/2020_04_01_00_42_38_403410_rightResized.jpg',...
    '/home/teamlary/mintsData/jetson001Set2/rightResized/2020_04_01_00_43_00_102290_rightResized.jpg',...
    '/home/teamlary/mintsData/jetson001Set2/rightResized/2020_04_01_00_43_36_571202_rightResized.jpg',...
    '/home/teamlary/mintsData/jetson001Set2/rightResized/2020_04_01_00_44_03_296711_rightResized.jpg',...
    '/home/teamlary/mintsData/jetson001Set2/rightResized/2020_04_01_00_44_41_694820_rightResized.jpg',...
    '/home/teamlary/mintsData/jetson001Set2/rightResized/2020_04_01_00_58_52_830652_rightResized.jpg',...
    '/home/teamlary/mintsData/jetson001Set2/rightResized/2020_04_01_00_59_34_349471_rightResized.jpg',...
    '/home/teamlary/mintsData/jetson001Set2/rightResized/2020_04_01_01_00_00_834721_rightResized.jpg',...
    '/home/teamlary/mintsData/jetson001Set2/rightResized/2020_04_01_01_00_32_551930_rightResized.jpg',...
    '/home/teamlary/mintsData/jetson001Set2/rightResized/2020_04_01_01_00_58_447069_rightResized.jpg',...
    '/home/teamlary/mintsData/jetson001Set2/rightResized/2020_04_01_01_01_21_406380_rightResized.jpg',...
    '/home/teamlary/mintsData/jetson001Set2/rightResized/2020_04_01_01_01_57_664492_rightResized.jpg',...
    '/home/teamlary/mintsData/jetson001Set2/rightResized/2020_04_01_01_02_30_368067_rightResized.jpg',...
    '/home/teamlary/mintsData/jetson001Set2/rightResized/2020_04_01_01_02_49_083378_rightResized.jpg',...
    '/home/teamlary/mintsData/jetson001Set2/rightResized/2020_04_01_01_03_13_386326_rightResized.jpg',...
    '/home/teamlary/mintsData/jetson001Set2/rightResized/2020_04_01_01_03_33_189726_rightResized.jpg',...
    '/home/teamlary/mintsData/jetson001Set2/rightResized/2020_04_01_01_03_53_471965_rightResized.jpg',...
    '/home/teamlary/mintsData/jetson001Set2/rightResized/2020_04_01_01_04_13_482513_rightResized.jpg',...
    '/home/teamlary/mintsData/jetson001Set2/rightResized/2020_04_01_01_04_30_012930_rightResized.jpg',...
    '/home/teamlary/mintsData/jetson001Set2/rightResized/2020_04_01_01_04_53_603655_rightResized.jpg',...
    '/home/teamlary/mintsData/jetson001Set2/rightResized/2020_04_01_01_05_10_092858_rightResized.jpg',...
    '/home/teamlary/mintsData/jetson001Set2/rightResized/2020_04_01_01_05_38_782783_rightResized.jpg',...
    '/home/teamlary/mintsData/jetson001Set2/rightResized/2020_04_01_01_05_57_271086_rightResized.jpg',...
    '/home/teamlary/mintsData/jetson001Set2/rightResized/2020_04_01_01_06_11_787439_rightResized.jpg'...
     };



% Detect checkerboards in images
[imagePoints, boardSize, imagesUsed] = detectCheckerboardPoints(imageFileNames1, imageFileNames2);


% Generate world coordinates of the checkerboard keypoints
squareSize = 35;  % in units of 'millimeters'
worldPoints = generateCheckerboardPoints(boardSize, squareSize);

% Read one of the images from the first stereo pair
I1 = imread(imageFileNames1{1});
[mrows, ncols, ~] = size(I1);

% Calibrate the camera
[stereoParamsLeftAndRight, pairsUsed, estimationErrors] = estimateCameraParameters(imagePoints, worldPoints, ...
    'EstimateSkew', false, 'EstimateTangentialDistortion', false, ...
    'NumRadialDistortionCoefficients', 2, 'WorldUnits', 'millimeters', ...
    'InitialIntrinsicMatrix', [], 'InitialRadialDistortion', [], ...
    'ImageSize', [mrows, ncols]);

% View reprojection errors
h1=figure; showReprojectionErrors(stereoParamsLeftAndRight);

% Visualize pattern locationsleftAnd
h2=figure; showExtrinsics(stereoParamsLeftAndRight, 'CameraCentric');

% Display parameter estimation errors
displayErrors(estimationErrors, stereoParamsLeftAndRight);

% You can use the calibration data to rectify stereo images.
I2 = imread(imageFileNames2{1});
[J1, J2] = rectifyStereoImages(I1, I2, stereoParamsLeftAndRight);

% Saving Data Products
leftImagePoints = imagePoints(:,:,:,1);
rightImagePoints= imagePoints(:,:,:,2);

save('dataFiles/DF_002_visualJetson001_Set2_2020_04_01')
save('dataFiles/DF_002_visualParametorsJetson001_Set2_2020_04_01','stereoParamsLeftAndRight')
save('dataFiles/DF_002_pythonVisualJetson001_Set2_2020_04_01',...
        'imageFileNames1','imageFileNames2',...
        'imagePoints','leftImagePoints','rightImagePoints'...
        )
