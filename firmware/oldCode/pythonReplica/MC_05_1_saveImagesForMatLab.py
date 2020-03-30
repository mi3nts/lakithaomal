
 #
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
# % #   https://github.com/mi3nts
# % #   http://utdmints.info/
# % #  ***************************************************************************
#
#  Chapter_05 : Saving Left and Thermal Parameters for Matlab


import cv2
import pickle
import numpy as  np
from matplotlib import pyplot as plt
import os


print(cv2.__version__)

print("Loading data from the stereo calibration")

stereoParams  = pickle.load(open("stereoParams_Feb_12_2020.p", "rb"))
thermalParams = pickle.load(open("thermalParams_Feb_12_2020.p", "rb"))

print(stereoParams)

# Matlab needs the calibrated images to get the images for dewarping
# The following block of code is used to dewarping the images and
# saving them


print(stereoParams)

fileNamePre     = '../threeWayImageDataSets/utdSet4/'
fileNamePost    = '../threeWayImageDataSets/utdSet4PyCalibrated/'

timeCurrentAll =  [ \
                    '040_11_05_17_58_00_', \
                    '050_11_05_17_58_28_', \
                    '060_11_05_17_58_56_', \
                    '070_11_05_17_59_24_', \
                    '080_11_05_17_59_52_', \
                    '090_11_05_18_00_28_', \
                    '100_11_05_18_00_56_', \
                    '110_11_05_18_01_17_', \
                    '120_11_05_18_01_52_', \
                    '130_11_05_18_02_27_', \
                    '140_11_05_18_02_48_', \
                    '150_11_05_18_03_23_', \
                    '160_11_05_18_03_44_', \
                    '170_11_05_18_04_41_', \
                    '180_11_05_18_05_02_', \
                    '190_11_05_18_05_44_', \
                    '200_11_05_18_06_12_', \
                    '210_11_05_18_07_08_', \
                    '220_11_05_18_07_36_', \
                    '230_11_05_18_08_05_', \
                    '240_11_05_18_08_33_', \
                    '250_11_05_18_09_29_', \
                    '260_11_05_18_10_04_', \
                    '270_11_05_18_10_32_', \
                    '280_11_05_18_11_21_', \
                    '290_11_05_18_11_57_', \
                    '300_11_05_18_12_32_', \
                    ]

def directoryCheck(outputPath):

    exists = os.path.isfile(outputPath)
    print(exists)
    directoryIn = os.path.dirname(outputPath)
    print(directoryIn)
    if not os.path.exists(directoryIn):
        os.makedirs(directoryIn)
    return exists


for timeCurrent in timeCurrentAll:

    print("============")
    print(timeCurrent)
    leftImageName    = fileNamePre + 'leftNegative/'  + timeCurrent +'leftNegative.jpg'
    rightImageName   = fileNamePre + 'rightNegative/' + timeCurrent +'rightNegative.jpg'
    thermalImageName = fileNamePre + 'thermal/' + timeCurrent +'thermal.jpg'

    leftImageNamePost    = fileNamePost + 'leftNegative/'  + timeCurrent +'leftNegative.jpg'
    rightImageNamePost   = fileNamePost+ 'rightNegative/' + timeCurrent +'rightNegative.jpg'
    thermalImageNamePost = fileNamePost+ 'thermal/' + timeCurrent +'thermal.jpg'

    imLeft  = cv2.imread(leftImageName)
    imRight = cv2.imread(rightImageName)
    imThermal = cv2.imread(thermalImageName)

    imLeftRemapped =cv2.remap(imLeft,stereoParams['mapXLeft'],\
                                        stereoParams['mapYLeft'],\
                                            cv2.INTER_CUBIC)
    imRightRemapped=cv2.remap(imRight,stereoParams['mapXRight'],\
                                        stereoParams['mapYRight'],
                                            cv2.INTER_CUBIC)

    imThermalRemapped = cv2.undistort(\
                                imThermal,\
                                thermalParams['mtxThermal'],\
                                thermalParams['distThermal']
                                , None,\
                                thermalParams['newcameramtx']\
                                )



    directoryCheck(leftImageNamePost)
    directoryCheck(rightImageNamePost)
    directoryCheck(thermalImageNamePost)

    cv2.imwrite(leftImageNamePost,    imLeftRemapped);
    cv2.imwrite(rightImageNamePost,   imRightRemapped);
    cv2.imwrite(thermalImageNamePost, imThermalRemapped);
