
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
from scipy.io import loadmat
import math
import pickle

print(cv2.__version__)

print("Loading data from Matlab for Overlay Points")

leftImagePoints    = loadmat('dataProducts/pythonScrapLeftImagePoints.mat')
thermalImagePoints = loadmat('dataProducts/pythonScrapThermalFeb19.mat')

horizontalSquares = 8
verticalSquares   = 7

thermalImagePointsAll        = thermalImagePoints['imagePoints']
thermalFileNames             = thermalImagePoints['imageFileNames']

leftImagePointsAll        = leftImagePoints['imagePoints']
leftFileNames             = leftImagePoints['imageFileNames']


def matlabToPythonCornerPoints(imagePoints,\
                                fileNamesIn,\
                                    horizontalSquares,\
                                        verticalSquares):

    horizontalInnerCorners = horizontalSquares-1
    verticalInnerCorners   = verticalSquares-1

    print("Organizing Corner Points")
    imageCorners  = []
    fileNames  =  []


    for imageIndex in range(len(imagePoints[0][0])):
        imageCurrentCorners  = []

        for cornerIndex in range(len(imagePoints)):

            XCordCurrent= np.float32(imagePoints[cornerIndex][0][imageIndex])
            YCordCurrent= np.float32(imagePoints[cornerIndex][1][imageIndex])
            imageCurrentCorners.append([[XCordCurrent,YCordCurrent]])

        imageCorners.append(imageCurrentCorners)

    corners = np.array(imageCorners)

    print("Rearanging Corners for the  Sensor")
    cornersArranged  = corners

    for imageIndex in range(len(imagePoints[0][0])):

        for cornerIndex in range(len(imagePoints)):

            arrangedIndex = horizontalInnerCorners*((cornerIndex)%verticalInnerCorners)\
                                + math.floor(cornerIndex/verticalInnerCorners)

            cornersArranged[imageIndex][arrangedIndex]  = \
                                            imageCorners[imageIndex][cornerIndex]

    # Organizing the file names
    print("Organizing File Names")
    for imageFileName in fileNamesIn[0]:
        fileNames.append(imageFileName[0])

    return cornersArranged,fileNames;




cornersThermal, fileNamesThermal = matlabToPythonCornerPoints(thermalImagePointsAll,\
                                    thermalFileNames,\
                                        horizontalSquares,\
                                            verticalSquares)

cornersLeft, fileNamesLeft = matlabToPythonCornerPoints(leftImagePointsAll,\
                                    leftFileNames,\
                                        horizontalSquares,\
                                            verticalSquares)


print("Saving all Perspectivive Transformation Matrices")

homographyAll = []

for leftCornerNow,thermalCornerNow,homographyIndex in zip (cornersLeft,cornersThermal,range(len(cornersLeft))):
    homographyAll.append(cv2.findHomography(thermalCornerNow,\
                                                                leftCornerNow,\
                                                                  cv2.RANSAC, 4)[0])


# Verification of Corner Points
print("Verification of Thermal Overlay")

for currentImageIndex in range(len(fileNamesLeft)):

    imLeft    = cv2.imread(fileNamesLeft[currentImageIndex])
    imThermal = cv2.imread(fileNamesThermal[currentImageIndex])

    cv2.imshow("Left" ,imLeft )
    cv2.imshow("Thermal" ,imThermal)

    rows,cols,ch = imLeft.shape

    thermalOverlay   = cv2.warpPerspective(imThermal,homographyAll[currentImageIndex],(cols,rows))

    cv2.imshow("Homography" , thermalOverlay)

    alpha = 0.2
    beta = (1.0 - alpha)

    mergedHomographyLocal = cv2.addWeighted(imLeft,alpha,thermalOverlay, beta, 0.0)
    cv2.imshow("Homography" , mergedHomographyLocal)
    cv2.waitKey(1000)
    cv2.destroyAllWindows()

print("Gaining cut off Distances")
# boundries = [40:10:300]
boundries = np.arange(40, 300, 10).tolist()
#
cutOffs   = boundries
cutOffs[0] = 0
#

for indexes in range(len(boundries)-1):
    cutOffs[indexes+1] = boundries[indexes]+ (boundries[indexes+1]-boundries[indexes])/2;

cutOffs.append(float("inf"))

print(cutOffs)

print("Saving all homographic matrices")

overlayParams = {\
                    'cutOffs ':cutOffs, 'homographyAll':homographyAll , \
                    }

print(overlayParams)
pickle.dump(overlayParams, open( "overlayParams_Feb_20_2020.p", "wb" ) )
