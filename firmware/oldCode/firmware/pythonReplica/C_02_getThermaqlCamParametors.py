
# % # ***************************************************************************
# % #   Stereo Vision - Thermal
# % #   ---------------------------------
# % #   Written by: Lakitha Omal Harindha Wijeratne
# % #   - for -
# % #   Mints: Multi-scale Integrated Sensing and Simulation
# % #   ---------------------------------
# % #   Date: January 23rd, 2020
# % #   ---------------------------------
# % #   This module is written for generic implimentation of MINTS projects
# % #   --------------------------------------------------------------------------
# % #   https:/github.com/mi3nts
# % #   http:/utdmints.info/
# % #  ***************************************************************************
#
# Gaining the Images
# Creating Image File Names
import cv2
import numpy as np
from matplotlib import pyplot as plt

import scipy.io
mat = scipy.io.loadmat('corners.mat')

print(mat['imagePoints'][0][0][0])
horizontalSquares = 8
verticalSquares   = 7

horizontalInnerCorners = horizontalSquares-1
verticalInnerCorners   = verticalSquares-1

objp        = np.zeros((horizontalInnerCorners*verticalInnerCorners, 3), np.float32)
objp[:, :2] = np.mgrid[0:horizontalInnerCorners, 0:verticalInnerCorners].T.reshape(-1, 2)
# Arrays to store object points and image points from all the images.

objPoints      = []  # 3d point in real world space
imgPointsLeft  = []  # 2d points in image plane.
imgPointsRight = []  # 2d points in image plane.



imageFileNames = [\
    '../../threeWayImageDataSets/utdSet4/thermalCalib/040_11_05_17_56_13_thermal.jpg',\
    '../../threeWayImageDataSets/utdSet4/thermalCalib/040_11_05_17_56_20_thermal.jpg',\
    '../../threeWayImageDataSets/utdSet4/thermalCalib/040_11_05_17_56_27_thermal.jpg',\
    '../../threeWayImageDataSets/utdSet4/thermalCalib/040_11_05_17_57_53_thermal.jpg',\
    '../../threeWayImageDataSets/utdSet4/thermalCalib/040_11_05_17_58_00_thermal.jpg',\
    '../../threeWayImageDataSets/utdSet4/thermalCalib/050_11_05_17_58_21_thermal.jpg',\
    '../../threeWayImageDataSets/utdSet4/thermalCalib/050_11_05_17_58_28_thermal.jpg',\
    '../../threeWayImageDataSets/utdSet4/thermalCalib/060_11_05_17_58_49_thermal.jpg',\
    '../../threeWayImageDataSets/utdSet4/thermalCalib/060_11_05_17_58_56_thermal.jpg',\
    '../../threeWayImageDataSets/utdSet4/thermalCalib/070_11_05_17_59_10_thermal.jpg',\
    '../../threeWayImageDataSets/utdSet4/thermalCalib/070_11_05_17_59_17_thermal.jpg',\
    '../../threeWayImageDataSets/utdSet4/thermalCalib/070_11_05_17_59_24_thermal.jpg',\
    '../../threeWayImageDataSets/utdSet4/thermalCalib/080_11_05_17_59_45_thermal.jpg',\
    '../../threeWayImageDataSets/utdSet4/thermalCalib/080_11_05_17_59_52_thermal.jpg',\
    '../../threeWayImageDataSets/utdSet4/thermalCalib/080_11_05_17_59_59_thermal.jpg',\
    '../../threeWayImageDataSets/utdSet4/thermalCalib/080_11_05_18_00_21_thermal.jpg',\
    '../../threeWayImageDataSets/utdSet4/thermalCalib/080_11_05_18_00_28_thermal.jpg',\
    '../../threeWayImageDataSets/utdSet4/thermalCalib/100_11_05_18_00_49_thermal.jpg',\
    '../../threeWayImageDataSets/utdSet4/thermalCalib/100_11_05_18_00_56_thermal.jpg',\
    '../../threeWayImageDataSets/utdSet4/thermalCalib/110_11_05_18_01_17_thermal.jpg',\
    '../../threeWayImageDataSets/utdSet4/thermalCalib/120_11_05_18_01_45_thermal.jpg',\
    '../../threeWayImageDataSets/utdSet4/thermalCalib/120_11_05_18_01_52_thermal.jpg',\
    '../../threeWayImageDataSets/utdSet4/thermalCalib/130_11_05_18_02_20_thermal.jpg',\
    '../../threeWayImageDataSets/utdSet4/thermalCalib/140_11_05_18_02_27_thermal.jpg',\
    '../../threeWayImageDataSets/utdSet4/thermalCalib/140_11_05_18_02_48_thermal.jpg',\
    '../../threeWayImageDataSets/utdSet4/thermalCalib/150_11_05_18_03_09_thermal.jpg',\
    '../../threeWayImageDataSets/utdSet4/thermalCalib/150_11_05_18_03_16_thermal.jpg',\
    '../../threeWayImageDataSets/utdSet4/thermalCalib/150_11_05_18_03_23_thermal.jpg'\
    ];



objpoints = [] # 3d point in real world space
imgpoints = [] # 2d points in image plane.

for idx, fname in enumerate(imageFileNames):
    print(fname)
    img = cv2.imread(fname)
    img_size = (img.shape[1], img.shape[0])
    subpix_criteria = (cv2.TERM_CRITERIA_EPS + cv2.TERM_CRITERIA_MAX_ITER, 30, 0.01)
    # print("====================")
    # print(fname)
    gray   = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
    clahe = cv2.createCLAHE(clipLimit=2.0, tileGridSize=(8,8))
    # equImg = cv2.equalizeHist(gray)
    equImg2 = clahe.apply(gray)

    ret, corners = cv2.findChessboardCorners(img, (horizontalInnerCorners,verticalInnerCorners), None)
    print(ret)

    if(ret):
        # print(corners)
        cv2.cornerSubPix(gray, corners, (3, 3), (-1, -1), subpix_criteria)
        cv2.drawChessboardCorners(img, (horizontalInnerCorners,verticalInnerCorners), corners, ret)
        imgPointsLeft.append(corners)
        cv2.imshow(imageFileNames1[idx], img)
        cv2.waitKey(1500)
