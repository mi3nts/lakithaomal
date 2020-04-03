
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
# %% Chapter_01 : Generating thermal and Right Camera Calibration Parametors
#
# % For the visual camera calibration utdset0 is used
#
# % Define images to process
import math
import pickle

from scipy.io import loadmat
import numpy as np
from matplotlib import pyplot as plt
import cv2

horizontalSquares = 8
verticalSquares   = 7

horizontalInnerCorners = horizontalSquares-1
verticalInnerCorners   = verticalSquares-1

objp        = np.zeros((horizontalInnerCorners*verticalInnerCorners, 3), np.float32)
objp[:, :2] = np.mgrid[0:horizontalInnerCorners, 0:verticalInnerCorners].T.reshape(-1, 2)

# Arrays to store object points and image points from all the images.

objPoints         = []  # 3D point in real world space
imgPointsthermal  = []  # 2D points in image plane.
imgPointsRight    = []  # 2D points in image plane.


thermalParametors = loadmat('dataProducts/pythonThermalFeb12.mat')

thermalImagePoints        = thermalParametors['imagePoints']
imageFileNamesThermal     = thermalParametors['imageFileNames']

# Organizing Corner Points
print("Organizing Corner Points")
thermalImageCorners  = []
thermalFileNames  =  []


for imageIndex in range(len(thermalImagePoints[0][0])):
    thermalImageCurrentCorners  = []
    objPoints.append(objp)

    for cornerIndex in range(len(thermalImagePoints)):

        thermalXCordCurrent= np.float32(thermalImagePoints[cornerIndex][0][imageIndex])
        thermalYCordCurrent= np.float32(thermalImagePoints[cornerIndex][1][imageIndex])
        thermalImageCurrentCorners.append([[thermalXCordCurrent,thermalYCordCurrent]])

    thermalImageCorners.append(thermalImageCurrentCorners)

thermalCorners = np.array(thermalImageCorners)

print("Rearanging Corners")
thermalCornersArranged  = thermalCorners

for imageIndex in range(len(thermalImagePoints[0][0])):

    for cornerIndex in range(len(thermalImagePoints)):

        arrangedIndex = horizontalInnerCorners*((cornerIndex)%verticalInnerCorners)\
                            + math.floor(cornerIndex/verticalInnerCorners)

        thermalCornersArranged[imageIndex][arrangedIndex]  = \
                                        thermalImageCorners[imageIndex][cornerIndex]

# Organizing the file names
print("Organizing File Names")
for thermalImageFileName in imageFileNamesThermal[0]:
    thermalFileNames.append(thermalImageFileName[0])

# Verification of Corner Points
print("Verification of Corner Points")
subpix_criteria = (cv2.TERM_CRITERIA_EPS + cv2.TERM_CRITERIA_MAX_ITER, 30, 0.01)

for thermalCornersCurrent,thermalFileNamesCurrent in \
                zip(thermalCornersArranged,thermalFileNames):

    imgthermal  = cv2.imread(thermalFileNamesCurrent)


    graythermal   = cv2.cvtColor(imgthermal, cv2.COLOR_BGR2GRAY)

    cv2.cornerSubPix(graythermal, thermalCornersCurrent, (3, 3), (-1, -1), subpix_criteria)
    cv2.drawChessboardCorners(imgthermal, (horizontalInnerCorners,verticalInnerCorners),\
            thermalCornersCurrent, True)
    cv2.imshow("thermal", imgthermal)

    cv2.waitKey(100)

cv2.destroyAllWindows()

print("Get Image Size")
imgThermal  = cv2.imread(thermalFileNames[0])
imgSize = (imgThermal.shape[1], imgThermal.shape[0])

print("Calibrating Thermal Camera")
retThermal, mtxThermal, distThermal, rvecsThermal, tvecsThermal      = cv2.calibrateCamera(\
                                                        objPoints, thermalCorners, imgSize, None, None)
print("Thermal Camera Calibrated")

# im = undistort(im, mtxThermal,  distThermal)

imThermal          = cv2.imread(thermalFileNames[0])
newcameramtx, _    = cv2.getOptimalNewCameraMatrix(mtxThermal,distThermal, imgSize, 1)
undistortedThermal = cv2.undistort(imThermal , mtxThermal,distThermal, None, newcameramtx)

cv2.imshow(thermalFileNames[0],undistortedThermal)
cv2.waitKey(10000)
cv2.destroyAllWindows()


print("Saving Camera Parametors")

thermalParams = {'retThermal' :retThermal, 'mtxThermal': mtxThermal, \
                'distThermal':distThermal, 'rvecsThermal':rvecsThermal,\
                'tvecsThermal':tvecsThermal,'newcameramtx':newcameramtx \
                                }

pickle.dump(thermalParams, open( "thermalParams_Feb_12_2020.p", "wb" ) )
