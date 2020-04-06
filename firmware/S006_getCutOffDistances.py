 #
# % # ***************************************************************************
# % #   Stereo Vision - Thermal
# % #   ---------------------------------
# % #   Written by: Lakitha Omal Harindha Wijeratne
# % #   - for -
# % #   Mints: Multi-scale Integrated Sensing and Simulation
# % #   ---------------------------------
# % #   Date:  April 02nd, 2020
# % #   ---------------------------------
# % #   This module is written for generic implimentation of MINTS projects
# % #   --------------------------------------------------------------------------
# % #   https://github.com/mi3nts
# % #   http://utdmints.info/
# % #  ***************************************************************************
#
# %% Chapter_06 : Gaining Cut off Distances

import cv2
import pickle
import numpy as  np
from matplotlib import pyplot as plt
from scipy.io import loadmat
from mintsJetson import camReader as cr
print(cv2.__version__)

#  Loading data from the stereo calibration

print("Loading data from the stereo calibration")
stereoParams  = pickle.load(open("dataFiles/DF_003_stereoParams_Jetson001_2020_04_02_19_05_49.p", "rb"))
thermalParams = pickle.load(open("dataFiles/DF_005_thermalParams_Jetson001_2020_04_02_22_55_59.p", "rb"))


leftAndRightParametors = loadmat('dataFiles/DF_002_pythonVisualJetson001_Set2_2020_04_01.mat')
imageFileNamesLeft     = leftAndRightParametors['imageFileNames1']
imageFileNamesRight    = leftAndRightParametors['imageFileNames2']

cr.printLabel("Gaining Stereo File Names from the Matlab Deployment")
leftFileNames,rightFileNames = cr.mat2PyGetStereoFileNames(imageFileNamesLeft,imageFileNamesRight)

distances = np.arange(40, 321, 10).tolist()


currentIndex = 27

rawDistances = [1005,925,765,657,572,512,460,418,382,352,\
                 320,307,289,270,256,240,227,220,208,200,\
                 192,182,176,167,160,157,147,144,143\
                ]

# Scripting the real values for distance

#0  40cm    = 1005
#1  50cm    = 925
#2  60cm    = 765
#3  70cm    = 657
#4  80cm    = 572
#5  90cm    = 512
#6  100cm   = 460
#7  110cm   = 418
#8  120cm   = 382
#9  130cm   = 352
#10 140cm   = 320
#11 150cm   = 307
#12 160cm   = 289
#13 170cm   = 270
#14 180cm   = 256
#15 190cm   = 240
#16 200cm   = 227
#17 210cm   = 220
#18 220cm   = 208
#19 230cm   = 200
#20 240cm   = 192
#21 250cm   = 182
#22 260cm   = 176
#23 270cm   = 167
#24 280cm   = 160
#25 290cm   = 157
#26 300cm   = 147
#27 310cm   = 144
#28 320cm   = 143

leftImage  = cv2.imread(leftFileNames[currentIndex])
rightImage = cv2.imread(rightFileNames[currentIndex])

frameLeftRect    = cv2.remap(leftImage ,stereoParams['mapXLeft'],\
                                                            stereoParams['mapYLeft'],\
                                                                        cv2.INTER_CUBIC)
frameRightRect   = cv2.remap(rightImage,stereoParams['mapXRight'],\
                                                                    stereoParams['mapYRight'],
                                                                        cv2.INTER_CUBIC)

#  After this point I am looking at gaining the depth map

print("Loading Disparity Model")

a = 30590
b = -0.9453

windowSize = 15                    # wsize default 3; 5; 7 for SGBM reduced size image; 15 for SGBM full size image (1300px and above); 5 Works nicely
maxDisparity = 64
leftMatcher = cv2.StereoSGBM_create(
    minDisparity=0,
    numDisparities=maxDisparity,             # max_disp has to be dividable by 16 f. E. HH 192, 256
    blockSize=5,
    P1=8 * 3 * windowSize ** 2,    # wsize default 3; 5; 7 for SGBM reduced size image; 15 for SGBM full size image (1300px and above); 5 Works nicely
    P2=32 * 3 * windowSize ** 2,
    disp12MaxDiff=1,
    uniquenessRatio=15,
    speckleWindowSize=0,
    speckleRange=2,
    preFilterCap=63,
    mode=cv2.STEREO_SGBM_MODE_SGBM_3WAY
)




disparityPre     = leftMatcher.compute(frameLeftRect,frameRightRect)

# plt.imshow(disparityPre,cmap='rainbow')

# cv2.imshow('Disparity Map', filteredImg)
# cv2.destroyAllWindows()

# a =   3.059e+04  (2.695e+04, 3.423e+04)
# b =     -0.9453
# Distance Image

# a = 30590
# b= -0.9453
#
# distanceImage  = 30590*(disparityPre**-0.9453)

plt.subplot(221)
plt.imshow(cv2.cvtColor(frameLeftRect, cv2.COLOR_BGR2RGB))
plt.subplot(222)
plt.imshow(cv2.cvtColor(frameRightRect, cv2.COLOR_BGR2RGB))
plt.subplot(223)
plt.imshow(disparityPre,cmap='rainbow')
plt.suptitle("Distance Image for {} cm".format(distances[currentIndex]))
plt.show()
