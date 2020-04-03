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

print(cv2.__version__)

#  Loading data from the stereo calibration

print("Loading data from the stereo calibration")
stereoParams  = pickle.load(open("stereoParams_Feb_12_2020.p", "rb"))
thermalParams = pickle.load(open("thermalParams_Feb_12_2020.p", "rb"))
print(stereoParams)

timeCurrent = '40_11_05_17_58_00_'
# timeCurrent = '050_11_05_17_58_28_'
# timeCurrent = '060_11_05_17_58_56_'
# timeCurrent = '070_11_05_17_59_24_'
# timeCurrent = '080_11_05_17_59_52_'
# timeCurrent = '090_11_05_18_00_28_'
# timeCurrent = '100_11_05_18_00_56_'
# timeCurrent = '110_11_05_18_01_17_'
# timeCurrent = '120_11_05_18_01_52_'
# timeCurrent = '130_11_05_18_02_27_'
# timeCurrent = '140_11_05_18_02_48_'
# # timeCurrent = '150_11_05_18_03_23_'
# # timeCurrent = '160_11_05_18_03_44_'
# # timeCurrent = '170_11_05_18_04_41_'
# # timeCurrent = '180_11_05_18_05_02_'
# # timeCurrent = '190_11_05_18_05_44_'
# # timeCurrent = '200_11_05_18_06_12_'
# # timeCurrent = '210_11_05_18_07_08_'
# # timeCurrent = '220_11_05_18_07_36_'
# # timeCurrent = '230_11_05_18_08_12_'
# # timeCurrent = '240_11_05_18_08_33_'
# # timeCurrent = '250_11_05_18_09_29_'
# # timeCurrent = '260_11_05_18_10_04_'
# # timeCurrent = '270_11_05_18_10_32_'
# # timeCurrent = '280_11_05_18_11_21_'
# # timeCurrent = '290_11_05_18_11_57_'
# # timeCurrent = '300_11_05_18_12_32_'

 # Scripting the real values for distance

# 40cm    = 1000
# 50cm    = 850
# 60cm    = 705
# 70cm    = 600
# 80cm    = 525
# 90cm    = 470
# 100cm   = 420
# 110cm   = 385
# 120cm   = 352
# 130cm   = 320
# 140cm   = 300
# 150cm   = 275
# 160cm   = 260
# 170cm   = 245
# 180cm   = 225
# 190cm   = 218
# 200cm   = 208
# 210cm   = 195
# 220cm   = 180
# 230cm   = 176
# 240cm   = 172
# 250cm   = 160
# 260cm   = 158
# 270cm   = 147
# 280cm   = 143
# 290cm   = 140
# 300cm   = 130

fileNamePre     = '../threeWayImageDataSets/utdSet4/'

leftImageName    = fileNamePre + 'left/'  + timeCurrent +'left.jpg'
rightImageName   = fileNamePre + 'right/' + timeCurrent +'right.jpg'


imLeft  = cv2.imread(leftImageName)
imRight = cv2.imread(rightImageName)

im_left_remapped =cv2.remap(imLeft,stereoParams['mapXLeft'],\
                                    stereoParams['mapYLeft'],cv2.INTER_CUBIC)
im_right_remapped=cv2.remap(imRight,stereoParams['mapXRight'],\
                                    stereoParams['mapYRight'],cv2.INTER_CUBIC)

#  After this point I am looking at gaining the depth map

# SGBM Parameters -----------------
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

disparityPre = leftMatcher.compute(im_left_remapped,im_right_remapped)

rightMatcher = 	cv2.ximgproc.createRightMatcher(leftMatcher)
# To obtain hole free depth-images we can use the WLS-Filter. This filter also requires some parameters which are shown below:

# FILTER Parameters
lmbda = 80000
sigma = 1.2
visual_multiplier = 1.0

wls_filter = cv2.ximgproc.createDisparityWLSFilter(matcher_left=leftMatcher)
wls_filter.setLambda(lmbda)
wls_filter.setSigmaColor(sigma)

print('computing disparity...')
displ = leftMatcher.compute(im_left_remapped, im_right_remapped)  # .astype(np.float32)/16
dispr = rightMatcher.compute(im_left_remapped, im_right_remapped) # .astype(np.float32)/16
displ = np.int16(displ)
dispr = np.int16(dispr)
filteredImg = wls_filter.filter(displ,im_left_remapped, None, dispr)  # important to put "imgL" here!!!

# Finally if you show this image with imshow() you may not see anything. This is due to values being not normalized to a 8-bit format. So lets fix this by normalizing our depth map:

# filteredImg = cv2.normalize(src=filteredImg, dst=filteredImg, beta=0, alpha=255, norm_type=cv2.NORM_MINMAX);
# filteredImg = np.uint8(filteredImg)
# cv2.imshow('Disparity Map', filteredImg)
# cv2.waitKey()
# cv2.destroyAllWindows()

# a =   3.059e+04  (2.695e+04, 3.423e+04)
# b =     -0.9453
# Distance Image

a = 30590
b= -0.9453

distanceImage  = 30590*(disparityPre**-0.9453)

plt.subplot(221)
plt.imshow(cv2.cvtColor(im_left_remapped, cv2.COLOR_BGR2RGB))
plt.subplot(222)
plt.imshow(cv2.cvtColor(im_right_remapped, cv2.COLOR_BGR2RGB))
plt.subplot(223)
plt.imshow(disparityPre)
plt.subplot(224)
plt.imshow(distanceImage)
plt.show()




# print("Saving Disparity Parametors")
#
# disparityParams = { \
#                  'windowSize' :windowSize,\
#                  'maxDisparity': maxDisparity, \
#                  'leftMatcher':leftMatcher,\
#                  'a':a,\
#                  'b':b\
#                 }

print(disparityParams)
pickle.dump(disparityParams, open( "disparityParams_Feb_20_2020.p", "wb" ))

 # Scripting the real values for distance

# 40cm    = 1000
# 50cm    = 850
# 60cm    = 705
# 70cm    = 600
# 80cm    = 525
# 90cm    = 470
# 100cm   = 420
# 110cm   = 385
# 120cm   = 352
# 130cm   = 320
# 140cm   = 300
# 150cm   = 275
# 160cm   = 260
# 170cm   = 245
# 180cm   = 225
# 190cm   = 218
# 200cm   = 208
# 210cm   = 195
# 220cm   = 180
# 230cm   = 176
# 240cm   = 172
# 250cm   = 160
# 260cm   = 158
# 270cm   = 147
# 280cm   = 143
# 290cm   = 140
# 300cm   = 130

# rawDistance =



#
#
#
#
# If normalization is needed you may do this
#
# def imageNormalization(img):
#     # img = cv2.imread('input.jpg')
#
#     img_yuv = cv2.cvtColor(img, cv2.COLOR_BGR2YUV)
#
#     # equalize the histogram of the Y channel
#     img_yuv[:,:,0] = cv2.equalizeHist(img_yuv[:,:,0])
#
#     # convert the YUV image back to RGB format
#     img_output = cv2.cvtColor(img_yuv, cv2.COLOR_YUV2BGR)
#     #
#     cv2.imshow('Color input image', img)
#     cv2.imshow('Histogram equalized', img_output)
#     cv2.waitKey(1000)
#
#     return img_output
#
# def histogram_equalize(img):
#     b, g, r = cv2.split(img)
#     red = cv2.equalizeHist(r)
#     green = cv2.equalizeHist(g)
#     blue = cv2.equalizeHist(b)
#     return cv2.merge((blue, green, red))
