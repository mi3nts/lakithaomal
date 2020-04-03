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
# %% Chapter_01 : Generating Thermal Camera Calibration Parametors
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

objPoints      = []  # 3d point in real world space
imgPointsLeft  = []  # 2d points in image plane.
imgPointsRight = []  # 2d points in image plane.


leftAndRightParametors = loadmat('dataProducts/pythonLeftAndRightFeb10.mat')
allImagePoints         = leftAndRightParametors['imagePoints']
leftImagePoints        = leftAndRightParametors['leftImagePoints']
rightImagePoints       = leftAndRightParametors['rightImagePoints']
imageFileNamesLeft     = leftAndRightParametors['imageFileNames1']
imageFileNamesRight    = leftAndRightParametors['imageFileNames2']

#  Organizing Corner Points
print("Organizing Corner Points")
leftImageCorners  = []
rightImageCorners = []

leftFileNames  =  []
rightFileNames = []


for imageIndex in range(len(leftImagePoints[0][0])):
    leftImageCurrentCorners  = []
    rightImageCurrentCorners = []
    objPoints.append(objp)

    for cornerIndex in range(len(leftImagePoints)):

        leftXCordCurrent= np.float32(leftImagePoints[cornerIndex][0][imageIndex])
        leftYCordCurrent= np.float32(leftImagePoints[cornerIndex][1][imageIndex])
        leftImageCurrentCorners.append([[leftXCordCurrent,leftYCordCurrent]])

        rightXCordCurrent = np.float32(rightImagePoints[cornerIndex][0][imageIndex])
        rightYCordCurrent = np.float32(rightImagePoints[cornerIndex][1][imageIndex])
        rightImageCurrentCorners.append([[rightXCordCurrent,rightYCordCurrent]])

    leftImageCorners.append(leftImageCurrentCorners)
    rightImageCorners.append(rightImageCurrentCorners)

leftCorners = np.array(leftImageCorners)
rightCorners = np.array(rightImageCorners)



print("Rearanging Corners")

leftCornersArranged  = leftCorners
rightCornersArranged = rightCorners

for imageIndex in range(len(leftImagePoints[0][0])):

    currentLeftCornerPoints = leftCorners[imageIndex]

    for cornerIndex in range(len(leftImagePoints)):

        arrangedIndex = horizontalInnerCorners*((cornerIndex)%verticalInnerCorners)\
                            + math.floor(cornerIndex/verticalInnerCorners)

        leftCornersArranged[imageIndex][arrangedIndex]  = \
                                        leftImageCorners[imageIndex][cornerIndex]
        rightCornersArranged[imageIndex][arrangedIndex] = \
                                        rightImageCorners[imageIndex][cornerIndex]



# Organizing the file names
print("Organizing File Names")
for leftImageFileName,rightImageFileName in zip(imageFileNamesLeft[0],imageFileNamesRight[0]):
    leftFileNames.append(leftImageFileName[0])
    rightFileNames.append(rightImageFileName[0])

#
# Verification of Corner Points
print("Verification of Corner Points")
subpix_criteria = (cv2.TERM_CRITERIA_EPS + cv2.TERM_CRITERIA_MAX_ITER, 30, 0.01)

for leftCornersCurrent,leftFileNamesCurrent,rightCornersCurrent,rightFileNamesCurrent in \
                zip(leftCornersArranged,leftFileNames,rightCornersArranged,rightFileNames):

    imgLeft  = cv2.imread(leftFileNamesCurrent)
    imgRight = cv2.imread(rightFileNamesCurrent)

    grayLeft   = cv2.cvtColor(imgLeft, cv2.COLOR_BGR2GRAY)
    grayRight   = cv2.cvtColor(imgRight, cv2.COLOR_BGR2GRAY)

    cv2.cornerSubPix(grayLeft, leftCornersCurrent, (3, 3), (-1, -1), subpix_criteria)
    cv2.drawChessboardCorners(imgLeft, (horizontalInnerCorners,verticalInnerCorners),\
            leftCornersCurrent, True)
    cv2.imshow("LEFT", imgLeft)

    cv2.cornerSubPix(grayRight, rightCornersCurrent, (3, 3), (-1, -1), subpix_criteria)
    cv2.drawChessboardCorners(imgRight, (horizontalInnerCorners,verticalInnerCorners),\
            rightCornersCurrent, True)
    cv2.imshow("RIGHT", imgRight)
    cv2.waitKey(100)

cv2.destroyAllWindows()

print("Get Image Size")
imgLeft  = cv2.imread(leftFileNames[0])
imgSize = (imgLeft.shape[1], imgLeft.shape[0])

print("Calibrating Stereo Cameras")
retLeft, mtxLeft, distLeft, rvecsLeft, tvecsLeft      = cv2.calibrateCamera(\
                                                        objPoints, leftCorners, imgSize, None, None)
print("Left Camera Calibrated")


retRight, mtxRight, distRight, rvecsRight, tvecsRight = cv2.calibrateCamera(\
                                                        objPoints, rightCorners, imgSize, None, None)
print("Right Camera Calibrated")

print("==============================")

print("Stereo Calibration")


flags = 0
flags |= cv2.CALIB_FIX_INTRINSIC
# flags |= cv2.CALIB_FIX_PRINCIPAL_POINT
flags |= cv2.CALIB_USE_INTRINSIC_GUESS
flags |= cv2.CALIB_FIX_FOCAL_LENGTH
# flags |= cv2.CALIB_FIX_ASPECT_RATIO
flags |= cv2.CALIB_ZERO_TANGENT_DIST
# flags |= cv2.CALIB_RATIONAL_MODEL
# flags |= cv2.CALIB_SAME_FOCAL_LENGTH
# flags |= cv2.CALIB_FIX_K3
# flags |= cv2.CALIB_FIX_K4
# flags |= cv2.CALIB_FIX_K5

stereocalib_criteria = (cv2.TERM_CRITERIA_MAX_ITER +
                                cv2.TERM_CRITERIA_EPS, 100, 1e-5)
ret, M1, d1, M2, d2, R, T, E, F = cv2.stereoCalibrate(
                                        objPoints, \
                                        leftCorners,rightCorners,\
                                        mtxLeft, distLeft, \
                                        mtxLeft, distLeft, \
                                        imgSize,\
                                        criteria=stereocalib_criteria, flags=flags)

print("Stereo Rectification")

R1, R2, P1, P2, Q, _, _        = cv2.stereoRectify(\
                                     mtxLeft, distLeft, \
                                        mtxLeft, distLeft, \
                                            imgSize,\
                                                R,\
                                                    T, \
                                                        alpha=1)


mapXLeft, mapYLeft = cv2.initUndistortRectifyMap(mtxLeft, \
                                            distLeft,\
                                            R1,\
                                            P1,\
                                            imgSize,
                                            cv2.CV_32F)
mapXRight, mapYRight = cv2.initUndistortRectifyMap(mtxLeft, \
                                            distLeft,\
                                            R2,\
                                            P2,\
                                            imgSize,
                                            cv2.CV_32F)

#  Runnning a Test
print("Doing a Test Image")

imLeft          = cv2.imread(leftImageFileName[0])
imRight         = cv2.imread(rightImageFileName[0])
imLeftRemapped  = cv2.remap(imLeft,mapXLeft,mapYLeft,cv2.INTER_CUBIC)
imRightRemapped = cv2.remap(imRight,mapXRight,mapYRight,cv2.INTER_CUBIC)

cv2.imshow(leftImageFileName[0],imLeftRemapped)
cv2.imshow(rightImageFileName[0],imRightRemapped)
cv2.waitKey(10000)
cv2.destroyAllWindows()

print("Saving Camera Parametors")


#  Reverse Mapping
def invert_maps(map_x, map_y):
    assert(map_x.shape == map_y.shape)
    rows = map_x.shape[0]
    cols = map_x.shape[1]
    m_x = np.ones(map_x.shape, dtype=map_x.dtype) * -1
    m_y = np.ones(map_y.shape, dtype=map_y.dtype) * -1
    for i in range(rows):
        for j in range(cols):

            i_ = round(map_y[i, j])
            j_ = round(map_x[i, j])

            if 0 <= i_ < rows and 0 <= j_ < cols:
                m_x[int(i_), int(j_)] = j
                m_y[int(i_), int(j_)] = i
    return m_x, m_y

print("Getting Reverse Image")

mapXLeftReverse,mapYLeftReverse   = invert_maps(mapXLeft,mapYLeft)
mapXRightReverse,mapYRightReverse = invert_maps(mapXRight,mapYRight)

# print(mapXLeftReverse)

imLeftRemappedReverse  = cv2.remap(imLeftRemapped,mapXLeftReverse,mapYLeftReverse,cv2.INTER_CUBIC)
imRightRemappedReverse = cv2.remap(imRightRemapped,mapXRightReverse,mapYRightReverse,cv2.INTER_CUBIC)

cv2.imshow(leftImageFileName[0],imLeftRemappedReverse)
cv2.imshow(rightImageFileName[0],imRightRemappedReverse)
cv2.waitKey(10000)
cv2.destroyAllWindows()


stereoParams = {'M1':M1, 'd1':d1, 'M2': M1, 'd2': d2, 'R':R, 'T':T, 'E':E, 'F':F ,\
                'R1':R1, 'R2':R2, 'P1' :P1, 'P2':P2, 'Q': Q,\
                'mapXLeft':mapXLeft, 'mapYLeft':mapYLeft , \
                'mapXRight':mapXRight, 'mapYRight':mapYRight,\
                'mapXLeftReverse':mapXLeftReverse, 'mapYLeftReverse':mapYLeftReverse , \
                'mapXRightReverse':mapXRightReverse, 'mapYRightReverse':mapYRightReverse\
                                }


print(stereoParams)

cv2.imshow(leftImageFileName[0],imLeftRemapped)
cv2.imshow(rightImageFileName[0],imRightRemapped)
cv2.waitKey(10000)
cv2.destroyAllWindows()


pickle.dump( stereoParams, open( "stereoParams_Feb_25_2020.p", "wb" ) )














#
