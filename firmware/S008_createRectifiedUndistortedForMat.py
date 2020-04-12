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
# S_008 : Saving Image Files for MatLab


import cv2
import pickle
import numpy as  np
from matplotlib import pyplot as plt
import cv2
from mintsJetson import camReader as cr
import datetime

from scipy.io import loadmat


cr.printMINTS("fevSen")

cr.printLabel("User Defined Variables")
directory = "/home/teamlary/mintsData/jetson002Set1/"

cr.printLabel("Loading Data Files")
stereoParams           = pickle.load(open("dataFiles/DF_003_stereoParams_Jetson002_Set1_2020_04_10_14_09_01.p", "rb"))
thermalParams          = pickle.load(open("dataFiles/DF_005_thermalParams_Jetson002_Set1_2020_04_11_16_51_50.p", "rb"))
leftAndRightParametors = loadmat('dataFiles/DF_002_pythonVisualJetson002_Set1_2020_04_10_14_07_40.mat')
imageFileNamesLeft     = leftAndRightParametors['imageFileNames1']
imageFileNamesRight    = leftAndRightParametors['imageFileNames2']

cr.printLabel("Gaining Stereo File Names from the Matlab Deployment")
leftFileNames,rightFileNames = cr.mat2PyGetStereoFileNames(imageFileNamesLeft,imageFileNamesRight)

cr.printLabel("Creating Sub Directories")
cr.folderCheck(directory+"leftResizedRectified/")
cr.folderCheck(directory+"rightResizedRectified/")
cr.folderCheck(directory+"thermalUndistorted/")

cr.printLabel("Savining Rectified Stereo Images")
cr.saveRectifiedForMatStereo(leftFileNames,rightFileNames,stereoParams)

cr.printLabel("Gaining Thermal File Names")
thermalFileNames = cr.getReplacedFileNames(leftFileNames,"leftResized","thermal")

cr.printLabel("Savining Undistorted Thermal Images")
cr.saveUndistortedForMatThermal(thermalFileNames,thermalParams)

cr.printLabel("MINTS done")
