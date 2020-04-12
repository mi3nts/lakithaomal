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
stereoParams  = pickle.load(open("dataFiles/DF_003_stereoParams_Jetson002_Set1_2020_04_10_14_09_01.p", "rb"))
leftAndRightParametors = loadmat('dataFiles/DF_002_pythonVisualJetson002_Set1_2020_04_10_14_07_40.mat')



imageFileNamesLeft     = leftAndRightParametors['imageFileNames1']
imageFileNamesRight    = leftAndRightParametors['imageFileNames2']

cr.printLabel("Gaining Stereo File Names from the Matlab Deployment")
leftFileNames,rightFileNames = cr.mat2PyGetStereoFileNames(imageFileNamesLeft,imageFileNamesRight)

distances = np.arange(40, 301, 10).tolist()
cr.printLabel("Number of Distcanes Calibrated :{}".format(len(distances)))

currentIndex = 23

# rawDistances for jetson001= [1005,925,765,657,572,512,460,418,382,352,\
#                  320,307,289,270,256,240,227,220,208,200,\
#                  192,182,176,167,160,157,147,144,143\
#                 ]

# rawDistances for jetson001= \
            #      [1010,944,778,670,583,520,468,422,390,360,\
#                  336  ,315,292,275,259,254,241,225,212,208,
                #  197,192,177,176,165,160,158\
#                 ]



# Scripting the real values for distance

# 0  40cm    = 1010
# 1  50cm    = 944
# 2  60cm    = 778
# 3  70cm    = 670
# 4  80cm    = 583
# 5  90cm    = 520
# 6  100cm   = 468
# 7  110cm   = 422
# 8  120cm   = 390
# 9  130cm   = 360

# 10 140cm   = 336
# 11 150cm   = 315
# 12 160cm   = 292
# 13 170cm   = 275
# 14 180cm   = 259
# 15 190cm   = 254
# 16 200cm   = 241
# 17 210cm   = 225
# 18 220cm   = 212
# 19 230cm   = 208

# 20 240cm   = 197
# 21 250cm   = 192
# 22 260cm   = 177
# 23 270cm   = 176
# 24 280cm   = 165
# 25 290cm   = 160
# 26 300cm   = 158


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
