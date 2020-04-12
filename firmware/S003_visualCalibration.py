#
# % # ***************************************************************************
# % #   Stereo Vision - Thermal
# % #   ---------------------------------
# % #   Written by: Lakitha Omal Harindha Wijeratne
# % #   - for -
# % #   Mints: Multi-scale Integrated Sensing and Simulation
# % #   ---------------------------------
# % #   Date: April 2nd, 2020
# % #   ---------------------------------
# % #   This module is written for generic implimentation of MINTS projects
# % #   --------------------------------------------------------------------------
# % #   https://github.com/mi3nts
# % #   http://utdmints.info/
# % #  ***************************************************************************
#
# S_003 : Generating Visual Camera Parametors

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
loadName = 'dataFiles/DF_002_pythonVisualJetson002_Set1_2020_04_10_14_07_40.mat'
jetsonNum = "002"
setNum    = "1"

dateTime = datetime.datetime.now()

horizontalSquares = 8
verticalSquares   = 7

saveName =  "dataFiles/DF_003_stereoParams_Jetson{}_Set{}_{}_{}_{}_{}_{}_{}.p".format(\
                                            jetsonNum,\
                                            setNum,\
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
                                        loadName,False,1000)

cr.printLabel("Validating Stereo Maps")
imLeftRemapped,imRightRemapped = cr.stereoTestMap(leftFileNames[0],rightFileNames[0],\
                                    mapXLeft,mapYLeft,mapXRight,mapYRight,20000)


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

cr.printLabel("Saving Stereo Visual Data to {}".format(saveName))
pickle.dump( stereoParams, open(saveName, "wb" ) )

cr.printLabel("MINTS done")
