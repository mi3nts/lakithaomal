# ***************************************************************************
#   camReader
#   ---------------------------------
#   Written by: Lakitha Omal Harindha Wijeratne
#   - for -
#   Mints: Multi-scale Integrated Sensing and Simulation
#      &
#   algolook.com
#   ---------------------------------
#   Date: March 29 th, 2019
#   ---------------------------------
#   This module is written for generic implimentation of MINTS projects
#   --------------------------------------------------------------------------
#   https://github.com/mi3nts
#   http://utdmints.info/
#
#  ***************************************************************************


import cv2
import os
import numpy as np
from imutils.video import WebcamVideoStream
import math
# def py_frame_callback(frame, userptr):

#   array_pointer = cast(frame.contents.data, POINTER(c_uint16 * (frame.contents.width * frame.contents.height)))
#   data = np.frombuffer(
#     array_pointer.contents, dtype=np.dtype(np.uint16)
#   ).reshape(
#     frame.contents.height, frame.contents.width
#   ) # no copy

#   # data = np.fromiter(
#   #   frame.contents.data, dtype=np.dtype(np.uint8), count=frame.contents.data_bytes
#   # ).reshape(
#   #   frame.contents.height, frame.contents.width, 2
#   # ) # copy

#   if frame.contents.data_bytes != (2 * frame.contents.width * frame.contents.height):
#     return

#   if not q.full():
#     q.put(data)

# # PTR_PY_FRAME_CALLBACK = CFUNCTYPE(None, POINTER(uvc_frame), c_void_p)(py_frame_callback)

def ktof(val):
  return (1.8 * ktoc(val) + 32.0)

def ktoc(val):
  return (val - 27315) / 100.0

def raw_to_8bit(data):
  cv2.normalize(data, data, 0, 65535, cv2.NORM_MINMAX)
  np.right_shift(data, 8, data)
  return cv2.cvtColor(np.uint8(data), cv2.COLOR_GRAY2RGB)

def display_temperature(img, val_k, loc, color):
  val = ktoc(val_k)
  cv2.putText(img,"{0:.1f} degC".format(val), loc, cv2.FONT_HERSHEY_SIMPLEX, 0.75, color, 2)
  x, y = loc
  cv2.line(img, (x - 2, y), (x + 2, y), color, 1)
  cv2.line(img, (x, y - 2), (x, y + 2), color, 1)

def getLeftWebCamIndex(myCmd):
    lines = myCmd.splitlines()
    for num, name in enumerate(lines, start=1):
        if "2.2" in name:
            camString =  int(lines[num].strip().replace("/dev/video",""))
            return  True ,camString;

    return False , "xxx";


def getRightWebCamIndex(myCmd):
    lines = myCmd.splitlines()
    for num, name in enumerate(lines, start=1):
        if "2.4" in name:
            camString =  int(lines[num].strip().replace("/dev/video",""))
            return True, camString;

    return False, "xxx";


def takeWebCamImage(indexIn):
    capture = cv2.VideoCapture(indexIn)
    # capture.set(cv2.CAP_PROP_FOURCC, cv2.VideoWriter_fourcc('Y', 'U', 'Y', 'V'))
    # capture.set(cv::CAP_PROP_FOURCC, cv::VideoWriter::fourcc('M', 'J', 'P', 'G'));
    time.sleep(0.1)
    ret0, out_image = capture.read()
    # print(out_image.shape)
    # time.sleep(1)
    # out_image = cv2.cvtColor(out_image , cv2.COLOR_HSV2BGR)

    # cv2.imshow('frame',out_image)
    # cv2.waitKey(0)


    capture.release()
    return ret0,out_image;


def getImagePathTail(dateTime,labelIn):
    pathTail = labelIn+"/"+\
    str(dateTime.year).zfill(4) + \
    "_" +str(dateTime.month).zfill(2) + \
    "_" +str(dateTime.day).zfill(2)+ \
    "_" +str(dateTime.hour).zfill(2) + \
    "_" +str(dateTime.minute).zfill(2)+ \
    "_" +str(dateTime.second).zfill(2)+ \
    "_" +str(dateTime.microsecond).zfill(6)+ \
    "_"+labelIn+".jpg"
    # print(pathTail)
    return pathTail;

def getImagePathTailMat(dateTime,labelIn):
    pathTail = labelIn+"/"+\
    str(dateTime.year).zfill(4) + \
    "_" +str(dateTime.month).zfill(2) + \
    "_" +str(dateTime.day).zfill(2)+ \
    "_" +str(dateTime.hour).zfill(2) + \
    "_" +str(dateTime.minute).zfill(2)+ \
    "_" +str(dateTime.second).zfill(2)+ \
    "_"+labelIn+".mat"

    return pathTail;

def getImagePathTailHdf5(dateTime,labelIn):

    pathTail = labelIn+"/"+\
    str(dateTime.year).zfill(4) + \
    "_" +str(dateTime.month).zfill(2) + \
    "_" +str(dateTime.day).zfill(2)+ \
    "_" +str(dateTime.hour).zfill(2) + \
    "_" +str(dateTime.minute).zfill(2)+ \
    "_" +str(dateTime.second).zfill(2)+ \
    "_" +str(dateTime.microsecond).zfill(2)+ \
    "_"+labelIn+".h5"

    return pathTail;


def getImagePathTailHdf5Mod(dateTime,labelIn):
    mod = round(dateTime.microsecond/200000)
    pathTail = labelIn+"/"+\
    str(dateTime.year).zfill(4) + \
    "_" +str(dateTime.month).zfill(2) + \
    "_" +str(dateTime.day).zfill(2)+ \
    "_" +str(dateTime.hour).zfill(2) + \
    "_" +str(dateTime.minute).zfill(2)+ \
    "_" +str(dateTime.second).zfill(2)+ \
    "_" +str((mod-1)*20).zfill(2)+ \
    "_"+labelIn+".h5"

    return pathTail;

def saveWebCamImage(capture,imageName):
    ret,image  = capture.read()
    print(image)
    print(imageName)
    cv2.imwrite(imageName,image)

def grab_frame(cap):
    ret,frame = cap.read()
    return cv2.cvtColor(frame,cv2.COLOR_BGR2RGB)


def openWebCamMPGJ(dev, width, height,framerate):
    gst = ('v4l2src device=/dev/video{} do-timestamp=true ! \
         image/jpeg, width={}, height={}, framerate={}/1 \
           ! jpegparse ! jpegdec ! videoconvert ! appsink ').format(dev, width, height,framerate)

    return cv2.VideoCapture(gst, cv2.CAP_GSTREAMER)



def openUSBCam(dev, width, height):
    # We want to set width and height here, otherwise we could just do:
    #     return cv2.VideoCapture(dev)
    gst_str = ('v4l2src device=/dev/video{} ! '
               'video/x-raw, width=(int){}, height=(int){} ! '
               'videoconvert ! appsink').format(dev, width, height)
    return cv2.VideoCapture(gst_str, cv2.CAP_GSTREAMER)

def openUSBCamVS(dev, width, height):
    # We want to set width and height here, otherwise we could just do:
    #     return cv2.VideoCapture(dev)
    gst_str = ('v4l2src device=/dev/video{} ! '
               'video/x-raw, width=(int){}, height=(int){} ! '
               'videoconvert ! appsink').format(dev, width, height)
    return WebcamVideoStream(gst_str, cv2.CAP_GSTREAMER).start()


def getImagePathTailHdf5Mod2(dateTime,labelIn):

    pathTail = labelIn+"/"+\
    str(dateTime.year).zfill(4) + \
    "_" +str(dateTime.month).zfill(2) + \
    "_" +str(dateTime.day).zfill(2)+ \
    "_" +str(dateTime.hour).zfill(2) + \
    "_" +str(dateTime.minute).zfill(2)+ \
    "_" +str(dateTime.second).zfill(2)+ \
    "_" +str(dateTime.microsecond).zfill(6)[0]+ \
    "_"+labelIn+".h5"

    return pathTail;

def folderCheck(outputPath):
    exists = os.path.isdir(outputPath)
    if not exists:
        print("Creating Directory '{}'".format(outputPath))
        os.makedirs(outputPath)
    else:
        print("Directory '{}' exists".format(outputPath))

    return exists

def thermalRawConvert(thermalData):
  return raw_to_8bit(cv2.resize(thermalData[:,:], (640, 480)))



def mat2PyGetImageCornersStereo(leftImagePoints,rightImagePoints,objp,\
                                    horizontalInnerCorners,verticalInnerCorners):
    printLabel("Reading Corner Points from Stereo Visual Cameras")
    objPoints         = []  # 3d point in real world space
    leftImageCorners  = []
    rightImageCorners = []
    leftFileNames     =  []
    rightFileNames    = []


    for imageIndex in range(len(leftImagePoints[0][0])):
       leftImageCurrentCorners  = []
       rightImageCurrentCorners = []
       objPoints.append(objp)

       for cornerIndex in range(len(leftImagePoints)):

           leftXCordCurrent= np.float32(leftImagePoints[cornerIndex][0][imageIndex])
           leftYCordCurrent= np.float32(leftImagePoints[cornerIndex][1][imageIndex])
           leftImageCurrentCorners.append([[leftXCordCurrent,leftYCordCurrent]])

           rightXCordCurrent = np.float32(rightImagePoints[cornerIndex][0][imageIndex])
           rightYCordCurrent = np.float32(rightImagePoints[cornerIndex][1][imageIndex])
           rightImageCurrentCorners.append([[rightXCordCurrent,rightYCordCurrent]])

       leftImageCorners.append(leftImageCurrentCorners)
       rightImageCorners.append(rightImageCurrentCorners)

    leftCorners = np.array(leftImageCorners)
    rightCorners = np.array(rightImageCorners)


    printLabel("Rearranging Corners of Stereo Cameras to Suit Python Deployments")

    leftCornersArranged  = leftCorners
    rightCornersArranged = rightCorners

    for imageIndex in range(len(leftImagePoints[0][0])):
       currentLeftCornerPoints = leftCorners[imageIndex]
       for cornerIndex in range(len(leftImagePoints)):
           arrangedIndex = horizontalInnerCorners*((cornerIndex)%verticalInnerCorners)\
                               + math.floor(cornerIndex/verticalInnerCorners)
           leftCornersArranged[imageIndex][arrangedIndex]  = \
                                           leftImageCorners[imageIndex][cornerIndex]
           rightCornersArranged[imageIndex][arrangedIndex] = \
                                           rightImageCorners[imageIndex][cornerIndex]
    return leftCornersArranged,rightCornersArranged, objPoints;

print("Organizing File Names")
def mat2PyGetStereoFileNames(imageFileNamesLeft,imageFileNamesRight):
    leftFileNames  =  []
    rightFileNames  =  []
    for leftImageFileName,rightImageFileName in zip(imageFileNamesLeft[0],imageFileNamesRight[0]):
       leftFileNames.append(leftImageFileName[0])
       rightFileNames.append(rightImageFileName[0])

    return leftFileNames,rightFileNames;


def displayCornerPointsStereo(leftCorners,rightCorners,leftFileNames,rightFileNames,\
                                            horizontalInnerCorners,verticalInnerCorners,
                                                delayTimeMillis):
    subpix_criteria = (cv2.TERM_CRITERIA_EPS + cv2.TERM_CRITERIA_MAX_ITER, 30, 0.01)

    for leftCornersCurrent,leftFileNamesCurrent,rightCornersCurrent,rightFileNamesCurrent in \
                   zip(leftCorners,leftFileNames,rightCorners,rightFileNames):

       imgLeft  = cv2.imread(leftFileNamesCurrent)
       imgRight = cv2.imread(rightFileNamesCurrent)

       grayLeft   = cv2.cvtColor(imgLeft, cv2.COLOR_BGR2GRAY)
       grayRight   = cv2.cvtColor(imgRight, cv2.COLOR_BGR2GRAY)

       cv2.cornerSubPix(grayLeft, leftCornersCurrent, (3, 3), (-1, -1), subpix_criteria)
       cv2.drawChessboardCorners(imgLeft, (horizontalInnerCorners,verticalInnerCorners),\
               leftCornersCurrent, True)
       cv2.imshow("Left", imgLeft)

       cv2.cornerSubPix(grayRight, rightCornersCurrent, (3, 3), (-1, -1), subpix_criteria)
       cv2.drawChessboardCorners(imgRight, (horizontalInnerCorners,verticalInnerCorners),\
               rightCornersCurrent, True)
       cv2.imshow("Right", imgRight)
       cv2.waitKey(delayTimeMillis)

    cv2.destroyAllWindows()



def printLabel(inputString):
    print(" ")
    print("------------------------------------------")
    print(inputString)

def printMINTS(inputString):
    print(" ")
    print("============== MINTS {} ==============".format(inputString))
    print(" ")
