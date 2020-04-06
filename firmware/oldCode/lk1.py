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
# S_003 : Generating Thermal Camera Parametors

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
loadName = 'dataFiles/DF_004_pythonThermalJetson001_Set2_2020_04_02.mat'
dateTime = datetime.datetime.now()
horizontalSquares = 8
verticalSquares   = 7
saveName =  "dataFiles/DF_005_thermalParams_Jetson001_{}_{}_{}_{}_{}_{}.p".format(\
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

cr.printLabel("Gaining Thermal Parametors")
thermalFileNames, thermalCorners,\
            mtxThermal, distThermal, rvecsThermal, tvecsThermal, \
                newCameraMtx = cr.mat2PyGetThermalMapping(horizontalSquares,\
                                    verticalSquares,\
                                        loadName,\
                                            True,100)


cr.printLabel("Validating Thermal Undistortion")
cr.thermalTestUndistort(thermalFileNames[0],mtxThermal,distThermal,newCameraMtx,10000)

cr.printLabel("Thermal Parametors")
thermalParams = {\
                'mtxThermal': mtxThermal,'distThermal':distThermal, \
                'rvecsThermal':rvecsThermal,'tvecsThermal':tvecsThermal,\
                'newcameramtx':newCameraMtx \
                }

print(thermalParams)

cr.printLabel("Saving Data to File")
pickle.dump(thermalParams, open(saveName, "wb" ) )

cr.printLabel("MINTS done")
