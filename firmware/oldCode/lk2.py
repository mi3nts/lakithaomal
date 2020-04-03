#
# % # ***************************************************************************
# % #   Stereo Vision - Thermal
# % #   ---------------------------------
# % #   Written by: Lakitha Omal Harindha Wijeratne
# % #   - for -
# % #   Mints: Multi-scale Integrated Sensing and Simulation
# % #   ---------------------------------
# % #   Date: March 30th, 2020
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
from mintsJetson import camReader as cr

cr.printMINTS("fevSen")

cr.printLabel("Loading Stereo Vision Parametors From Matlab")
leftAndRightParametors = loadmat('dataFiles/DF_002_pythonVisualJetson001_Set2_2020_04_01.mat')
allImagePoints         = leftAndRightParametors['imagePoints']
leftImagePoints        = leftAndRightParametors['leftImagePoints']
rightImagePoints       = leftAndRightParametors['rightImagePoints']
imageFileNamesLeft     = leftAndRightParametors['imageFileNames1']
imageFileNamesRight    = leftAndRightParametors['imageFileNames2']


cr.printLabel("Defining Chekerboard Specifications")
horizontalSquares = 8
verticalSquares   = 7
horizontalInnerCorners = horizontalSquares-1
verticalInnerCorners   = verticalSquares-1
scaleFactor = 1

cr.printLabel("Gaining Corner Points from the Matlab Deployment")
leftCorners,rightCorners, objPoints = cr.mat2PyGetImageCornersStereoScaled(\
                                                        leftImagePoints,\
                                                        rightImagePoints,\
                                                        horizontalInnerCorners,\
                                                        verticalInnerCorners,
                                                        scaleFactor\
                                                        )


cr.printLabel("Gaining Stereo File Names from the Matlab Deployment")
leftFileNames,rightFileNames = cr.mat2PyGetStereoFileNames(imageFileNamesLeft,imageFileNamesRight)



cr.printLabel("Gaining Stereo File For High Resolution Images")
leftFileNamesHR  = cr.replaceNames(leftFileNames,"leftResized","left")
rightFileNamesHR = cr.replaceNames(rightFileNames,"rightResized","right")


#
# cr.printLabel("Verification of Stereo Corners")
# cr.displayCornerPointsStereoScaled(leftCorners,rightCorners,leftFileNamesHR,rightFileNamesHR,\
#                                         horizontalInnerCorners,verticalInnerCorners,\
#                                         500,1080)

cr.printLabel("Gaining Image Size")
imgSize = cr.getImageSize(leftFileNames[0])

cr.printLabel("Gaining Stereo Calibration and Stereo Maps")
mapXLeft,mapYLeft,mapXRight,mapYRight = cr.getStereoRectificationMaps(leftCorners,rightCorners,objPoints,imgSize)


imLeft          = cv2.imread(leftFileNames[0])
imRight         = cv2.imread(rightFileNames[0])
imLeftRemapped  = cv2.remap(imLeft,mapXLeft,mapYLeft,cv2.INTER_CUBIC)
imRightRemapped = cv2.remap(imRight,mapXRight,mapYRight,cv2.INTER_CUBIC)


cv2.imshow(leftFileNames[0]+"remapped",imLeftRemapped)
cv2.imshow(rightFileNames[0]+"remapped",imRightRemapped)
cv2.waitKey(10000)
cv2.destroyAllWindows()

# print("Saving Camera Parametors")
#
#
# #  Reverse Mapping
# def invert_maps(map_x, map_y):
#     assert(map_x.shape == map_y.shape)
#     rows = map_x.shape[0]
#     cols = map_x.shape[1]
#     m_x = np.ones(map_x.shape, dtype=map_x.dtype) * -1
#     m_y = np.ones(map_y.shape, dtype=map_y.dtype) * -1
#     for i in range(rows):
#         for j in range(cols):
#
#             i_ = round(map_y[i, j])
#             j_ = round(map_x[i, j])
#
#             if 0 <= i_ < rows and 0 <= j_ < cols:
#                 m_x[int(i_), int(j_)] = j
#                 m_y[int(i_), int(j_)] = i
#     return m_x, m_y
#
# print("Getting Reverse Image")
#
# mapXLeftReverse,mapYLeftReverse   = invert_maps(mapXLeft,mapYLeft)
# mapXRightReverse,mapYRightReverse = invert_maps(mapXRight,mapYRight)
#
# # print(mapXLeftReverse)
#
# imLeftRemappedReverse  = cv2.remap(imLeftRemapped,mapXLeftReverse,mapYLeftReverse,cv2.INTER_CUBIC)
# imRightRemappedReverse = cv2.remap(imRightRemapped,mapXRightReverse,mapYRightReverse,cv2.INTER_CUBIC)
#
# cv2.imshow(leftFileNames[0],imLeftRemappedReverse)
# cv2.imshow(rightFileNames[0],imRightRemappedReverse)
# cv2.waitKey(1000)
# cv2.destroyAllWindows()
#
#
# stereoParams = {'M1':M1, 'd1':d1, 'M2': M1, 'd2': d2, 'R':R, 'T':T, 'E':E, 'F':F ,\
#                 'R1':R1, 'R2':R2, 'P1' :P1, 'P2':P2, 'Q': Q,\
#                 'mapXLeft':mapXLeft, 'mapYLeft':mapYLeft , \
#                 'mapXRight':mapXRight, 'mapYRight':mapYRight,\
#                 'mapXLeftReverse':mapXLeftReverse, 'mapYLeftReverse':mapYLeftReverse , \
#                 'mapXRightReverse':mapXRightReverse, 'mapYRightReverse':mapYRightReverse\
#                                 }
#
#
# print(stereoParams)
#
# pickle.dump( stereoParams, open( "dataFiles/DF_003_stereoParams_Jetson001_2020_04_02.p", "wb" ) )
