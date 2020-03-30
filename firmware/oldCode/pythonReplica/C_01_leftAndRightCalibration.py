
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
# Gaining the Images
# Creating Image File Names
import cv2
import numpy as np
from matplotlib import pyplot as plt


horizontalSquares = 8
verticalSquares   = 7

horizontalInnerCorners = horizontalSquares-1
verticalInnerCorners   = verticalSquares-1

objp        = np.zeros((horizontalInnerCorners*verticalInnerCorners, 3), np.float32)
objp[:, :2] = np.mgrid[0:horizontalInnerCorners, 0:verticalInnerCorners].T.reshape(-1, 2)
# Arrays to store object points and image points from all the images.

objPoints      = []  # 3d point in real world space
imgPointsLeft  = []  # 2d points in image plane.
imgPointsRight = []  # 2d points in image plane.

#
# self.read_images(self.cal_path)
#


imageFileNames1 = [\
    '../../threeWayImageDataSets/utdSet0/left/2019_10_24_13_28_41_left.jpg',\
    '../../threeWayImageDataSets/utdSet0/left/2019_10_24_13_28_55_left.jpg',\
    '../../threeWayImageDataSets/utdSet0/left/2019_10_24_13_29_16_left.jpg',\
    '../../threeWayImageDataSets/utdSet0/left/2019_10_24_13_29_30_left.jpg',\
    '../../threeWayImageDataSets/utdSet0/left/2019_10_24_13_29_37_left.jpg',\
    '../../threeWayImageDataSets/utdSet0/left/2019_10_24_13_29_44_left.jpg',\
    '../../threeWayImageDataSets/utdSet0/left/2019_10_24_13_29_51_left.jpg',\
    '../../threeWayImageDataSets/utdSet0/left/2019_10_24_13_29_58_left.jpg',\
    '../../threeWayImageDataSets/utdSet0/left/2019_10_24_13_30_05_left.jpg',\
    '../../threeWayImageDataSets/utdSet0/left/2019_10_24_13_30_12_left.jpg',\
    '../../threeWayImageDataSets/utdSet0/left/2019_10_24_13_55_49_left.jpg',\
    '../../threeWayImageDataSets/utdSet0/left/2019_10_24_13_55_56_left.jpg',\
    '../../threeWayImageDataSets/utdSet0/left/2019_10_24_13_56_03_left.jpg',\
    '../../threeWayImageDataSets/utdSet0/left/2019_10_24_13_56_10_left.jpg',\
    '../../threeWayImageDataSets/utdSet0/left/2019_10_24_13_56_17_left.jpg',\
    '../../threeWayImageDataSets/utdSet0/left/2019_10_24_13_56_24_left.jpg',\
    '../../threeWayImageDataSets/utdSet0/left/2019_10_24_13_56_31_left.jpg',\
    '../../threeWayImageDataSets/utdSet0/left/2019_10_24_13_56_38_left.jpg',\
    '../../threeWayImageDataSets/utdSet0/left/2019_10_24_13_56_45_left.jpg',\
    '../../threeWayImageDataSets/utdSet0/left/2019_10_24_13_56_52_left.jpg',\
    '../../threeWayImageDataSets/utdSet0/left/2019_10_24_13_56_59_left.jpg',\
    '../../threeWayImageDataSets/utdSet0/left/2019_10_24_13_57_06_left.jpg',\
    '../../threeWayImageDataSets/utdSet0/left/2019_10_24_13_57_13_left.jpg',\
    '../../threeWayImageDataSets/utdSet0/left/2019_10_24_13_57_20_left.jpg',\
    '../../threeWayImageDataSets/utdSet0/left/2019_10_24_14_34_34_left.jpg',\
    '../../threeWayImageDataSets/utdSet0/left/2019_10_24_14_34_42_left.jpg',\
    '../../threeWayImageDataSets/utdSet0/left/2019_10_24_14_34_49_left.jpg',\
    '../../threeWayImageDataSets/utdSet0/left/2019_10_24_14_34_56_left.jpg',\
    '../../threeWayImageDataSets/utdSet0/left/2019_10_24_14_35_03_left.jpg',\
    '../../threeWayImageDataSets/utdSet0/left/2019_10_24_14_35_10_left.jpg',\
    '../../threeWayImageDataSets/utdSet0/left/2019_10_24_14_35_17_left.jpg',\
    '../../threeWayImageDataSets/utdSet0/left/2019_10_24_14_35_24_left.jpg',\
    '../../threeWayImageDataSets/utdSet0/left/2019_10_24_14_35_31_left.jpg',\
    '../../threeWayImageDataSets/utdSet0/left/2019_10_24_14_36_06_left.jpg',\
    '../../threeWayImageDataSets/utdSet0/left/2019_10_24_14_36_13_left.jpg',\
    '../../threeWayImageDataSets/utdSet0/left/2019_10_24_14_36_20_left.jpg',\
    ];


imageFileNames2 = [\
    '../../threeWayImageDataSets/utdSet0/right/2019_10_24_13_28_41_right.jpg',\
    '../../threeWayImageDataSets/utdSet0/right/2019_10_24_13_28_55_right.jpg',\
    '../../threeWayImageDataSets/utdSet0/right/2019_10_24_13_29_16_right.jpg',\
    '../../threeWayImageDataSets/utdSet0/right/2019_10_24_13_29_30_right.jpg',\
    '../../threeWayImageDataSets/utdSet0/right/2019_10_24_13_29_37_right.jpg',\
    '../../threeWayImageDataSets/utdSet0/right/2019_10_24_13_29_44_right.jpg',\
    '../../threeWayImageDataSets/utdSet0/right/2019_10_24_13_29_51_right.jpg',\
    '../../threeWayImageDataSets/utdSet0/right/2019_10_24_13_29_58_right.jpg',\
    '../../threeWayImageDataSets/utdSet0/right/2019_10_24_13_30_05_right.jpg',\
    '../../threeWayImageDataSets/utdSet0/right/2019_10_24_13_30_12_right.jpg',\
    '../../threeWayImageDataSets/utdSet0/right/2019_10_24_13_55_49_right.jpg',\
    '../../threeWayImageDataSets/utdSet0/right/2019_10_24_13_55_56_right.jpg',\
    '../../threeWayImageDataSets/utdSet0/right/2019_10_24_13_56_03_right.jpg',\
    '../../threeWayImageDataSets/utdSet0/right/2019_10_24_13_56_10_right.jpg',\
    '../../threeWayImageDataSets/utdSet0/right/2019_10_24_13_56_17_right.jpg',\
    '../../threeWayImageDataSets/utdSet0/right/2019_10_24_13_56_24_right.jpg',\
    '../../threeWayImageDataSets/utdSet0/right/2019_10_24_13_56_31_right.jpg',\
    '../../threeWayImageDataSets/utdSet0/right/2019_10_24_13_56_38_right.jpg',\
    '../../threeWayImageDataSets/utdSet0/right/2019_10_24_13_56_45_right.jpg',\
    '../../threeWayImageDataSets/utdSet0/right/2019_10_24_13_56_52_right.jpg',\
    '../../threeWayImageDataSets/utdSet0/right/2019_10_24_13_56_59_right.jpg',\
    '../../threeWayImageDataSets/utdSet0/right/2019_10_24_13_57_06_right.jpg',\
    '../../threeWayImageDataSets/utdSet0/right/2019_10_24_13_57_13_right.jpg',\
    '../../threeWayImageDataSets/utdSet0/right/2019_10_24_13_57_20_right.jpg',\
    '../../threeWayImageDataSets/utdSet0/right/2019_10_24_14_34_34_right.jpg',\
    '../../threeWayImageDataSets/utdSet0/right/2019_10_24_14_34_42_right.jpg',\
    '../../threeWayImageDataSets/utdSet0/right/2019_10_24_14_34_49_right.jpg',\
    '../../threeWayImageDataSets/utdSet0/right/2019_10_24_14_34_56_right.jpg',\
    '../../threeWayImageDataSets/utdSet0/right/2019_10_24_14_35_03_right.jpg',\
    '../../threeWayImageDataSets/utdSet0/right/2019_10_24_14_35_10_right.jpg',\
    '../../threeWayImageDataSets/utdSet0/right/2019_10_24_14_35_17_right.jpg',\
    '../../threeWayImageDataSets/utdSet0/right/2019_10_24_14_35_24_right.jpg',\
    '../../threeWayImageDataSets/utdSet0/right/2019_10_24_14_35_31_right.jpg',\
    '../../threeWayImageDataSets/utdSet0/right/2019_10_24_14_36_06_right.jpg',\
    '../../threeWayImageDataSets/utdSet0/right/2019_10_24_14_36_13_right.jpg',\
    '../../threeWayImageDataSets/utdSet0/right/2019_10_24_14_36_20_right.jpg',\
    ];



objpoints = [] # 3d point in real world space
imgpoints = [] # 2d points in image plane.

for idx, fname in enumerate(imageFileNames1):
    img = cv2.imread(fname)
    img_size = (img.shape[1], img.shape[0])
    subpix_criteria = (cv2.TERM_CRITERIA_EPS + cv2.TERM_CRITERIA_MAX_ITER, 30, 0.01)
    # print("====================")
    # print(fname)
    gray   = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
    clahe = cv2.createCLAHE(clipLimit=2.0, tileGridSize=(8,8))
    # equImg = cv2.equalizeHist(gray)
    equImg2 = clahe.apply(gray)

    ret, corners = cv2.findChessboardCorners(equImg2, (horizontalInnerCorners,verticalInnerCorners), None)
    print("------")
    print(fname)
    print(ret)
    # print("------")
    # print(corners)
    if(ret):
        # print(corners)
        cv2.cornerSubPix(gray, corners, (3, 3), (-1, -1), subpix_criteria)
        cv2.drawChessboardCorners(img, (horizontalInnerCorners,verticalInnerCorners), corners, ret)
        imgPointsLeft.append(corners)
        # cv2.imshow(imageFileNames1[idx], img)
        # cv2.waitKey(1500)

for idx, fname in enumerate(imageFileNames2):
    img = cv2.imread(fname)
    img_size = (img.shape[1], img.shape[0])
    subpix_criteria = (cv2.TERM_CRITERIA_EPS + cv2.TERM_CRITERIA_MAX_ITER, 30, 0.01)
    # print("====================")
    # print(fname)
    gray   = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
    clahe = cv2.createCLAHE(clipLimit=2.0, tileGridSize=(8,8))
    # equImg = cv2.equalizeHist(gray)
    equImg2 = clahe.apply(gray)

    ret, corners = cv2.findChessboardCorners(equImg2, (horizontalInnerCorners,verticalInnerCorners), None)
    # print(ret)
    if(ret):
        # print(corners)
        #Object Points - Just enough for the number of images we have
        objPoints.append(objp)
        imgPointsRight.append(corners)
        cv2.cornerSubPix(gray, corners, (3, 3), (-1, -1), subpix_criteria)
        cv2.drawChessboardCorners(img, (horizontalInnerCorners,verticalInnerCorners), corners, ret)
        img_size = (img.shape[1], img.shape[0])
        # cv2.imshow(imageFileNames1[idx], img)
        # cv2.waitKey(1500)

print(fname)
print(corners)

## Before doing the Stereo Calibrate, the individual camera calibration must be done.
print("Calibrating Cameras ")
print(imgPointsLeft[0])

retLeft, mtxLeft, distLeft, rvecsLeft, tvecsLeft      = cv2.calibrateCamera(\
                                                        objPoints, imgPointsLeft, img_size, None, None)
print("Left Camera Done")

retRight, mtxRight, distRight, rvecsRight, tvecsRight      = cv2.calibrateCamera(\
                                                        objPoints, imgPointsRight, img_size, None, None)
print("Right Camera Done")


# print("RET Left   :"+str(retLeft))
# print("MTX Left   :"+str(mtxLeft))
# print("DIST Left  :"+str(distLeft))
# print("RVECS Left :"+str(rvecsLeft))
# print("TVECS Left :"+str(tvecsLeft))
#
# print("RET Right  :"+str(retRight))
# print("MTX Right  :"+str(mtxRight))
# print("DIST Right :"+str(distRight))
# print("RVECS Right:"+str(rvecsRight))
# print("TVECS Right:"+str(tvecsRight))

# imLeft=cv2.imread(imageFileNames1[5])[...,::-1]
# imRight=cv2.imread(imageFileNames2[5])[...,::-1]
# im_undistortedLeft=cv2.undistort(imLeft, mtxLeft, distLeft)
# im_undistortedRight =cv2.undistort(imRight, mtxRight, distRight)
# plt.subplot(221)
# plt.imshow(imLeft)
# plt.subplot(222)
# plt.imshow(im_undistortedLeft)
# plt.subplot(223)
# plt.imshow(imRight)
# plt.subplot(224)
# plt.imshow(im_undistortedRight)
# plt.show()
# #
# # #


# print(cv2.__version__)

flags = 0
flags |= cv2.CALIB_FIX_INTRINSIC
# flags |= cv2.CALIB_FIX_PRINCIPAL_POINT
flags |= cv2.CALIB_USE_INTRINSIC_GUESS
flags |= cv2.CALIB_FIX_FOCAL_LENGTH
# flags |= cv2.CALIB_FIX_ASPECT_RATIO
flags |= cv2.CALIB_ZERO_TANGENT_DIST
# flags |= cv2.CALIB_RATIONAL_MODEL
# flags |= cv2.CALIB_SAME_FOCAL_LENGTH
# flags |= cv2.CALIB_FIX_K3
# flags |= cv2.CALIB_FIX_K4
# flags |= cv2.CALIB_FIX_K5

stereocalib_criteria = (cv2.TERM_CRITERIA_MAX_ITER +
                                cv2.TERM_CRITERIA_EPS, 100, 1e-5)
ret, M1, d1, M2, d2, R, T, E, F = cv2.stereoCalibrate(
            objPoints, imgPointsLeft,imgPointsRight,\
            mtxLeft, distLeft, \
            mtxLeft, distLeft, \
            img_size,\
            criteria=stereocalib_criteria, flags=flags)

R1, R2, P1, P2, Q, _, _ = cv2.stereoRectify(\
                                     mtxLeft, distLeft, \
                                        mtxLeft, distLeft, \
                                            img_size,\
                                                R,\
                                                    T, \
                                                        alpha=-1)


mapx1, mapy1 = cv2.initUndistortRectifyMap(mtxLeft, \
                                            distLeft,\
                                            R1,\
                                            P1,\
                                            img_size,
                                            cv2.CV_32F)
mapx2, mapy2 = cv2.initUndistortRectifyMap(mtxLeft, \
                                            distLeft,\
                                            R2,\
                                            P2,\
                                            img_size,
                                            cv2.CV_32F)


# im_left=cv2.imread('left07.jpg')
# im_right=cv2.imread('right07.jpg')

# imLeft=cv2.imread(imageFileNames1[5])
# imRight=cv2.imread(imageFileNames2[5])

imLeft  = cv2.imread('../threeWayImageDataSets/utdSet4/left/140_11_05_18_02_48_left.jpg')
imRight = cv2.imread('../threeWayImageDataSets/utdSet4/right/140_11_05_18_02_48_right.jpg')



im_left_remapped =cv2.remap(imLeft,mapx1,mapy1,cv2.INTER_CUBIC)
im_right_remapped=cv2.remap(imRight,mapx2,mapy2,cv2.INTER_CUBIC)


#  After this point I am looking at gaining the depth map

#
# window_size = 5
# min_disp = 32
# num_disp = 112-min_disp
# stereo = cv2.StereoSGBM(
#     minDisparity = min_disp,
#     numDisparities = num_disp,
#     SADWindowSize = window_size,
#     uniquenessRatio = 10,
#     speckleWindowSize = 100,
#     speckleRange = 32,
#     disp12MaxDiff = 1,
#     P1 = 8*3*window_size**2,
#     P2 = 32*3*window_size**2,
#     fullDP = False
# )
#
#
#
# disparity = stereo.compute(im_left_remapped,im_right_remapped).astype(np.float32) / 16.0
# disparity = (disparity-min_disp)/num_disp
#
#
#
# plt.figure(figsize=(10,4))
# plt.imshow(disparity)
# plt.show()

# SGBM Parameters -----------------
window_size = 15                    # wsize default 3; 5; 7 for SGBM reduced size image; 15 for SGBM full size image (1300px and above); 5 Works nicely
max_disparity = 64
left_matcher = cv2.StereoSGBM_create(
    minDisparity=0,
    numDisparities=max_disparity,             # max_disp has to be dividable by 16 f. E. HH 192, 256
    blockSize=5,
    P1=8 * 3 * window_size ** 2,    # wsize default 3; 5; 7 for SGBM reduced size image; 15 for SGBM full size image (1300px and above); 5 Works nicely
    P2=32 * 3 * window_size ** 2,
    disp12MaxDiff=1,
    uniquenessRatio=15,
    speckleWindowSize=0,
    speckleRange=2,
    preFilterCap=63,
    mode=cv2.STEREO_SGBM_MODE_SGBM_3WAY
)


disparity1 = left_matcher.compute(im_left_remapped,im_right_remapped)
# cv2.filterSpeckles(disparity, 0, 40, max_disparity)

_, disparity = cv2.threshold(disparity1,0, max_disparity * 16, cv2.THRESH_TOZERO)
disparity_scaled = (disparity / 16.).astype(np.uint8)
disparity_colour_mapped = cv2.applyColorMap((disparity_scaled * (256. / max_disparity)).astype(np.uint8), cv2.COLORMAP_HOT)
#
points = cv2.reprojectImageTo3D(disparity1, Q)
print(points[0])
plt.subplot(221)
plt.imshow(im_left_remapped)
plt.subplot(222)
plt.imshow(im_right_remapped)
plt.subplot(223)
plt.imshow((disparity_scaled * (256. / max_disparity)).astype(np.uint8))
plt.subplot(224)
plt.imshow(1/(1+disparity_colour_mapped))
plt.show()



# plt.imshow("LEFT",im_left_remapped)
#
# plt.imshow("RIGHT",im_right_remapped)
# plt.imshow("Disparity", disparity_colour_mapped)
#
# plt.show()

# right_matcher = cv2.ximgproc.createRightMatcher(left_matcher)
# # To obtain hole free depth-images we can use the WLS-Filter. This filter also requires some parameters which are shown below:
#
# # FILTER Parameters
# lmbda = 80000
# sigma = 1.2
# visual_multiplier = 1.0
#
# wls_filter = cv2.ximgproc.createDisparityWLSFilter(matcher_left=left_matcher)
# wls_filter.setLambda(lmbda)
# wls_filter.setSigmaColor(sigma)
#
#
#
# print('computing disparity...')
# displ = left_matcher.compute(im_left_remapped,im_right_remapped)  # .astype(np.float32)/16
# dispr = right_matcher.compute(im_right_remapped, im_left_remapped)  # .astype(np.float32)/16
# displ = np.int16(displ)
# dispr = np.int16(dispr)
# filteredImg = wls_filter.filter(displ, im_left_remapped, None,  im_left_remapped)  # important to put "imgL" here!!!
# filteredImg = cv2.normalize(src=filteredImg, dst=filteredImg, beta=0, alpha=255, norm_type=cv2.NORM_MINMAX);
# filteredImg = np.uint8(filteredImg)
# cv2.imshow('Disparity Map', filteredImg)
# cv2.waitKey()
# cv2.destroyAllWindows()


#
# out=np.hstack((im_left_remapped,im_right_remapped))
#
# plt.figure(figsize=(10,4))
# plt.imshow(out[...,::-1])
# plt.show()
#
# def write_ply(fn, verts, colors):
#     verts = verts.reshape(-1, 3)
#     colors = colors.reshape(-1, 3)
#     verts = np.hstack([verts, colors])
#     with open(fn, 'wb') as f:
#         f.write((ply_header % dict(vert_num=len(verts))).encode('utf-8'))
#         np.savetxt(f, verts, fmt='%f %f %f %d %d %d ')
#
#     # disparity range is tuned for 'aloe' image pair
# window_size = 3
# min_disp = 16
# num_disp = 112-min_disp
# stereo = cv2.StereoSGBM_create(minDisparity = min_disp,\
#         numDisparities = num_disp,\
#         blockSize = 16,\
#         P1 = 8*3*window_size**2,\
#         P2 = 32*3*window_size**2,\
#         disp12MaxDiff = 1,\
#         uniquenessRatio = 10,\
#         speckleWindowSize = 100,\
#         speckleRange = 32\
#     )
#
#
#
# print('computing disparity...')
# stereo = cv2.StereoSGBM(minDisparity = 0, numDisparities = 160, SADWindowSize =    11, disp12MaxDiff = 1, uniquenessRatio = 20, speckleWindowSize = 100, speckleRange = 2)
# disparity = stereo.compute(im_left_remapped,im_right_remapped)/16
#
# print('generating 3d point cloud...',)
# h, w = imLeft.shape[:2]
# f = 0.8*w                          # guess for focal length
# Q = np.float32([[1, 0, 0, -0.5*w],
#                     [0,-1, 0,  0.5*h], # turn points 180 deg around x-axis,
#                     [0, 0, 0,     -f], # so that y-axis looks up
#                     [0, 0, 1,      0]])
# points = cv2.reprojectImageTo3D(disp, Q)
# colors = cv2.cvtColor(imLeft, cv2.COLOR_BGR2RGB)
# mask = disp > disp.min()
# out_points = points[mask]
# out_colors = colors[mask]
# out_fn = 'out.ply'
# # write_ply(out_fn, out_points, out_colors)
# # print('%s saved' % out_fn)
# cv2.imshow('left', imLeft)
# cv2.imshow('disparity', (disp-min_disp)/num_disp)
# cv2.waitKey()
#
# print('Done')





























# map1_x,map1_y=cv2.initUndistortRectifyMap(mtxLeft, distLeft, R1, P1,cv2.cv.CV_32FC1)
# retval, _, _, _, _, R, T, E, F=cv2.stereoCalibrate(\
#                                     objPoints,imgPointsLeft,imgPointsRight,\
#                                     img_size,\
#                                     mtxLeft,distLeft,mtxLeft,distLeft,\
#                                     flags=cv2.cv.CV_CALIB_FIX_INTRINSIC)
#
#
# flags = 0
# flags |= cv2.CALIB_FIX_INTRINSIC
# # flags |= cv2.CALIB_FIX_PRINCIPAL_POINT
# flags |= cv2.CALIB_USE_INTRINSIC_GUESS
# flags |= cv2.CALIB_FIX_FOCAL_LENGTH
# # flags |= cv2.CALIB_FIX_ASPECT_RATIO
# flags |= cv2.CALIB_ZERO_TANGENT_DIST
# # flags |= cv2.CALIB_RATIONAL_MODEL
# # flags |= cv2.CALIB_SAME_FOCAL_LENGTH
# # flags |= cv2.CALIB_FIX_K3
# # flags |= cv2.CALIB_FIX_K4
# # flags |= cv2.CALIB_FIX_K5
#
# stereocalib_criteria = (cv2.TERM_CRITERIA_MAX_ITER +\
#                                 cv2.TERM_CRITERIA_EPS, 100, 1e-5)
#
# ret, mLeft, dLeft, MRight, dRight, R, T, E, F =\
#                                     cv2.stereoCalibrate(\
#                                     objPoints, \
#                                     imgPointsLeft,\
#                                     imgPointsRight,\
#                                     img_size,\
#                                     mtxLeft,distLeft,mtxRight,distRight,\
#                                     flags=cv2.cv.CV_CALIB_FIX_INTRINSIC)
# #
# R1=cv2.cv.fromarray(np.zeros((3,3))) #output 3x3 matrix
# R2=cv2.cv.fromarray(np.zeros((3,3))) #output 3x3 matrix
# P1=cv2.cv.fromarray(np.zeros((3,4))) #output 3x4 matrix
# P2=cv2.cv.fromarray(np.zeros((3,4))) #output 3x4 matrix
#
# R1, R2, P1, P2, Q,roi1,roi2=cv2.StereoRectify(\
#    mtxLeft, #intrinsic parameters of the first camera
#    distRight, #distortion parameters of the first camera
#    mtxLeft, #intrinsic parameters of the first camera
#    distRight, #distortion parameters of the first camera
#    img_size, #image dimensions
#    R, #Rotation matrix between first and second cameras (returned by cv2.stereoCalibrate)
#    T, #Translation vector between coordinate systems of the cameras (returned by cv2.stereoCalibrate)
#    alpha=1.0) #last 4 parameters point to inizialized output variables

# R1=np.array(R1) #convert output back to numpy format
# R2=np.array(R2)
# P1=np.array(P1)
# P2=np.array(P2)


#
#
# print('Intrinsic_mtx_1', mLeft)
# print('dist_1', dLeft)
# print('Intrinsic_mtx_2', mRight)
# print('dist_2', dRight)
# print('R', R)
# print('T', T)
# print('E', E)
# print('F', F)
#
# print('')
#
# camera_model = dict([('M1', M1), ('M2', M2), ('dist1', d1),
#                             ('dist2', d2), ('rvecs1', self.r1),
#                             ('rvecs2', self.r2), ('R', R), ('T', T),
#                             ('E', E), ('F', F)])
