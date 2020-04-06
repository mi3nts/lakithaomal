
# % # ***************************************************************************
# % #   Stereo Vision - Thermal
# % #   ---------------------------------
# % #   Written by: Lakitha Omal Harindha Wijeratne
# % #   - for -
# % #   Mints: Multi-scale Integrated Sensing and Simulation
# % #   ---------------------------------
# % #   Date: April 02nd, 2020
# % #   ---------------------------------
# % #   This module is written for generic implimentation of MINTS projects
# % #   --------------------------------------------------------------------------
# % #   https://github.com/mi3nts
# % #   http://utdmints.info/
# % #  ***************************************************************************
#
#  Step 11 : Obtaining a Overlay Params

import cv2
import pickle
import numpy as  np
from matplotlib import pyplot as plt
import os
from scipy.io import loadmat
import math
import pickle
import datetime
import h5py
from mintsJetson import camReader as cr

cr.printMINTS("Fever Sensor Calibration")

cr.printLabel("User Defined Variables")
loadName1 = 'dataFiles/DF_010_overlayParams_jetson001_Set2_2020_04_04_17_32_48.mat'
loadName2 = 'dataFiles/DF_007_distanceParams_Jetson001_Set2_2020_04_04_19_02_26.mat'


dateTime = datetime.datetime.now()
horizontalSquares = 8
verticalSquares   = 7
saveName =  "dataFiles/DF_011_overlayParams_Jetson001_{}_{}_{}_{}_{}_{}.p".format(\
                                            str(dateTime.year).zfill(4),\
                                            str(dateTime.month).zfill(2),\
                                            str(dateTime.day).zfill(2),\
                                            str(dateTime.hour).zfill(2),\
                                            str(dateTime.minute).zfill(2),\
                                            str(dateTime.second).zfill(2)\
                                            )

print("Load Name 1         : '{}'".format(loadName1))
print("Load Name 2         : '{}'".format(loadName2))
print("Save Name           : '{}'".format(saveName))
print("Implimentation Time : '{}'".format(dateTime))
print("Horizontal Squares  : '{}'".format(horizontalSquares))
print("Vertical Squares    : '{}'".format(verticalSquares))


cr.printLabel("Loading Parametors")
overlayParamsMat     = loadmat(loadName1)
distanceParamsMat    = loadmat(loadName2)

leftImagePointsAll           = overlayParamsMat['imagePointsLeft']
leftFileNames                = overlayParamsMat['imageFileNamesLeft']
thermalImagePointsAll        = overlayParamsMat['imagePointsThermal']
thermalFileNames             = overlayParamsMat['imageFileNamesThermal']



cr.printMINTS("Converting Matalb Data to Python Data")
cornersThermal, fileNamesThermal = cr.mat2PyGetCornerPointsMono(thermalImagePointsAll,\
                                    thermalFileNames,\
                                        horizontalSquares,\
                                            verticalSquares)

cornersLeft, fileNamesLeft      = cr.mat2PyGetCornerPointsMono(leftImagePointsAll,\
                                    leftFileNames,\
                                        horizontalSquares,\
                                            verticalSquares)





cr.printMINTS("Gaining Homogrpahy Data")
homographyAll = cr.getHomogrpahyParams(cornersLeft,cornersThermal)


fitA, fitB, cutOffs, distancesCM = cr.getDistanceParamsMat2Py(loadName2,\
                                                            len(homographyAll))

overlayParams = {\
                'homographyAll':homographyAll,'fitA':fitA, 'fitB' :fitB, \
                    'cutOffs' :cutOffs, 'distancesCM' :distancesCM \
                    }

print(overlayParams)

cr.printLabel("Saving Data to File")
pickle.dump(overlayParams, open(saveName, "wb" ) )

cr.printLabel("MINTS done")
