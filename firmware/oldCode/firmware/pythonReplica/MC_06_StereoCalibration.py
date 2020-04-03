

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
#  Chapter_05 : Obtaining a thermal overlay specific for each

import cv2
import pickle
import numpy as  np
from matplotlib import pyplot as plt
import os
from scipy.io import loadmat

print(cv2.__version__)

print("Loading data from the stereo and thermal calibration")

stereoParams  = pickle.load(open("stereoParams_Feb_12_2020.p", "rb"))
thermalParams = pickle.load(open("thermalParams_Feb_12_2020.p", "rb"))
overlayParams = pickle.load(open("overlayParams_Feb_20_2020.p", "rb"))



cutOffs       = overlayParams['cutOffs ']
homographyAll = overlayParams['homographyAll']

print("Loading Disparity Parametors ")



a = 30590
b= -0.9453

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

print("Gaining Distance Image")

imLeft     = cv2.imread("2019_10_24_14_35_10_left.jpg")
imRight    = cv2.imread("2019_10_24_14_35_10_right.jpg")
imThermal  = cv2.imread("2019_10_24_14_35_10_thermal.jpg")
celciusImage  = loadmat('2019_11_07_15_29_37_celcius.mat')
imCelcius = celciusImage['thermalCelcius']

frameLeftRect    = cv2.remap(imLeft,stereoParams['mapXLeft'],\
                                        stereoParams['mapYLeft'],\
                                            cv2.INTER_CUBIC)
frameRightRect   = cv2.remap(imRight,stereoParams['mapXRight'],\
                                        stereoParams['mapYRight'],
                                            cv2.INTER_CUBIC)

frameCelciusRect = cv2.undistort(\
                                imCelcius,\
                                thermalParams['mtxThermal'],\
                                thermalParams['distThermal']
                                , None,\
                                thermalParams['newcameramtx']\
                                )

#
disparityPre     = leftMatcher.compute(frameLeftRect,frameRightRect)
distanceImage    = 30590*(disparityPre**-0.9453)



maskCelcliusAll       = []
celciusImageAll       = []
maskedCelciusImageAll = []
finalCelciusImage     = np.zeros((480, 640))

rows,cols,ch = frameLeftRect.shape
# lk = np.multiply(maskNow,imCelciusRemapped)

for indexIn in range(len(homographyAll)):
    maskCelclius          = (cutOffs[indexIn]<=distanceImage)&\
                                        (distanceImage<cutOffs[indexIn+1])
    maskCelcliusAll.append(maskCelclius)
    celciusImage          = cv2.warpPerspective(frameCelciusRect,\
                                                 homographyAll[indexIn],\
                                                  (cols,rows))
    celciusImageAll.append(celciusImage)

    maskedCelciusImage    = np.multiply(maskCelclius,celciusImage)
    maskedCelciusImageAll.append(maskedCelciusImage)
    finalCelciusImage = finalCelciusImage + maskedCelciusImage
    # End of for


finalCelcius = finalCelciusImage/(finalCelciusImage.max()/255.0)

cmap = plt.cm.jet
norm = plt.Normalize(vmin=finalCelcius.min(), vmax=finalCelcius.max())

# map the normalized data to colors
# image is now RGBA (512x512x4)
thermal = cmap(norm(finalCelcius))
plt.imsave('thermal.png',thermal)

left    = cv2.cvtColor(frameLeftRect, cv2.COLOR_BGR2RGB)
thermal = cv2.cvtColor(cv2.imread('thermal.png'), cv2.COLOR_BGR2RGB)

alpha = 0.5
beta = (1.0 - alpha)

overlay = cv2.addWeighted(left,alpha,thermal,beta,0)

distanceImage[distanceImage>1500]=0

plt.subplot(221)
plt.imshow(cv2.cvtColor(frameLeftRect, cv2.COLOR_BGR2RGB))
plt.title("Original Image")
plt.subplot(222)
plt.imshow(distanceImage,cmap='rainbow')
plt.title("Depth Image")
cbar1 =  plt.colorbar();
cbar1.ax.set_ylabel(r"Distance(cm)", rotation=270,labelpad=20)
plt.subplot(223)
plt.imshow(overlay)
plt.title("Thermal Visual Overlay")
plt.subplot(224)
plt.imshow(finalCelciusImage,cmap='jet')
plt.title("Thermal Image")
cbar1 =  plt.colorbar();
cbar1.ax.set_ylabel(r"Temperature(C)", rotation=270,labelpad=20)
plt.show()
