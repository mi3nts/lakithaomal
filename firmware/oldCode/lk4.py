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
import datetime


cr.printMINTS("fevSen")



cr.printLabel("User Defined Variables")
loadName = 'dataFiles/DF_002_pythonVisualJetson001_Set2_2020_04_01.mat'
dateTime = datetime.datetime.now()
horizontalSquares = 8
verticalSquares   = 7
saveName =  "dataFiles/DF_003_stereoParams_Jetson001_{}_{}_{}_{}_{}_{}.p".format(\
                                            str(dateTime.year).zfill(4),\
                                            str(dateTime.month).zfill(2),\
                                            str(dateTime.day).zfill(2),\
                                            str(dateTime.hour).zfill(2),\
                                            str(dateTime.minute).zfill(2),\
                                            str(dateTime.second).zfill(2)\
                                            )

print("Load Name           : '{}'".format(loadName))
print("Save Name           : '{}'".format(saveName))
print("Implimentation Time : '{}'".format(dateTime))
print("Horizontal Squares  : '{}'".format(horizontalSquares))
print("Vertical Squares    : '{}'".format(verticalSquares))


cr.printLabel("Gaining Stereo Parametors")
leftFileNames,rightFileNames,mapXLeft,mapYLeft,mapXRight, mapYRight,\
M1, d1, M2, d2, R1, R2, P1, P2, \
R, T, E, F, Q \
=  cr.mat2PyGetStereoMapping(horizontalSquares,\
                                    verticalSquares,\
                                        loadName,False,500)

cr.printLabel("Validating Stereo Maps")
imLeftRemapped,imRightRemapped = cr.stereoTestMap(leftFileNames[0],rightFileNames[0],\
                                    mapXLeft,mapYLeft,mapXRight,mapYRight,5000)


cr.printLabel("Gaining Reverse Maps")
mapXLeftReverse,mapYLeftReverse   = cr.getReverseMapping(mapXLeft,mapYLeft)
mapXRightReverse,mapYRightReverse = cr.getReverseMapping(mapXRight,mapYRight)

cr.printLabel("Validating Reverse Maps")
cr.stereoReverseTestMap(imLeftRemapped,imRightRemapped,\
                            mapXLeftReverse,mapYLeftReverse,\
                                mapXRightReverse,mapYRightReverse,\
                                5000)

cr.printLabel("Stereo Parametors:")
stereoParams = {'M1':M1, 'd1':d1, 'M2': M2, 'd2': d2, 'R':R, 'T':T, 'E':E, 'F':F ,\
                'R1':R1, 'R2':R2, 'P1' :P1, 'P2':P2, 'Q': Q,\
                'mapXLeft':mapXLeft, 'mapYLeft':mapYLeft , \
                'mapXRight':mapXRight, 'mapYRight':mapYRight,\
                'mapXLeftReverse':mapXLeftReverse, 'mapYLeftReverse':mapYLeftReverse , \
                'mapXRightReverse':mapXRightReverse, 'mapYRightReverse':mapYRightReverse\
                                }
print(stereoParams)

cr.printLabel("Saving Data to File")
pickle.dump( stereoParams, open(saveName, "wb" ) )

cr.printLabel("MINTS done")
