

#!/usr/bin/env python
# -*- coding: utf-8 -*-
# import h5py
# import pickle
import datetime
from uvctypes import *
import time
# import math
import cv2
import numpy as np
try:
  from queue import Queue
except ImportError:
  from Queue import Queue
import platform
import os
# import threading
import time
import numpy, scipy.io
# from matplotlib import pyplot as plt
# from matplotlib.animation import FuncAnimation
# from PIL import Image
#
# from matplotlib import cm
from mintsJetson import camReader as cr

# def py_frame_callback(frame, userptr):
#
#   array_pointer = cast(frame.contents.data, POINTER(c_uint16 * (frame.contents.width * frame.contents.height)))
#   data = np.frombuffer(
#     array_pointer.contents, dtype=np.dtype(np.uint16)
#   ).reshape(
#     frame.contents.height, frame.contents.width
#   ) # no copy
#
#   # data = np.fromiter(
#   #   frame.contents.data, dtype=np.dtype(np.uint8), count=frame.contents.data_bytes
#   # ).reshape(
#   #   frame.contents.height, frame.contents.width, 2
#   # ) # copy
#
#   if frame.contents.data_bytes != (2 * frame.contents.width * frame.contents.height):
#     return
#
#   if not q.full():
#     q.put(data)
#
# PTR_PY_FRAME_CALLBACK = CFUNCTYPE(None, POINTER(uvc_frame), c_void_p)(py_frame_callback)
#
# def ktof(val):
#   return (1.8 * ktoc(val) + 32.0)
#
# def ktoc(val):
#   return (val - 27315) / 100.0
#
# def raw_to_8bit(data):
#   cv2.normalize(data, data, 0, 65535, cv2.NORM_MINMAX)
#   np.right_shift(data, 8, data)
#   return cv2.cvtColor(np.uint8(data), cv2.COLOR_GRAY2RGB)
#
# def display_temperature(img, val_k, loc, color):
#   val = ktoc(val_k)
#   cv2.putText(img,"{0:.1f} degC".format(val), loc, cv2.FONT_HERSHEY_SIMPLEX, 0.75, color, 2)
#   x, y = loc
#   cv2.line(img, (x - 2, y), (x + 2, y), color, 1)
#   cv2.line(img, (x, y - 2), (x, y + 2), color, 1)
#
# def getLeftWebCamIndex(myCmd):
#     lines = myCmd.splitlines()
#     for num, name in enumerate(lines, start=1):
#         if "2.3" in name:
#             camString =  int(lines[num].strip().replace("/dev/video",""))
#             return  True ,camString;
#
#     return False , "xxx";
#
#
# def getRightWebCamIndex(myCmd):
#     lines = myCmd.splitlines()
#     for num, name in enumerate(lines, start=1):
#         if "2.4" in name:
#             camString =  int(lines[num].strip().replace("/dev/video",""))
#             return True, camString;
#
#     return False, "xxx";
#
#
# def takeWebCamImage(indexIn):
#     capture = cv2.VideoCapture(indexIn)
#     # capture.set(cv2.CAP_PROP_FOURCC, cv2.VideoWriter_fourcc('Y', 'U', 'Y', 'V'))
#     # capture.set(cv::CAP_PROP_FOURCC, cv::VideoWriter::fourcc('M', 'J', 'P', 'G'));
#     time.sleep(0.1)
#     ret0, out_image = capture.read()
#     # print(out_image.shape)
#     # time.sleep(1)
#     # out_image = cv2.cvtColor(out_image , cv2.COLOR_HSV2BGR)
#
#     # cv2.imshow('frame',out_image)
#     # cv2.waitKey(0)
#
#
#     capture.release()
#     return ret0,out_image;
#
#
# def getImagePathTail(dateTime,labelIn):
#     pathTail = labelIn+"/"+\
#     str(dateTime.year).zfill(4) + \
#     "_" +str(dateTime.month).zfill(2) + \
#     "_" +str(dateTime.day).zfill(2)+ \
#     "_" +str(dateTime.hour).zfill(2) + \
#     "_" +str(dateTime.minute).zfill(2)+ \
#     "_" +str(dateTime.second).zfill(2)+ \
#     "_"+labelIn+".jpg"
#     # print(pathTail)
#     return pathTail;
#
# def getImagePathTailMat(dateTime,labelIn):
#     pathTail = labelIn+"/"+\
#     str(dateTime.year).zfill(4) + \
#     "_" +str(dateTime.month).zfill(2) + \
#     "_" +str(dateTime.day).zfill(2)+ \
#     "_" +str(dateTime.hour).zfill(2) + \
#     "_" +str(dateTime.minute).zfill(2)+ \
#     "_" +str(dateTime.second).zfill(2)+ \
#     "_"+labelIn+".mat"
#
#     return pathTail;
#
# def getImagePathTailHdf5(dateTime,labelIn):
#
#     pathTail = labelIn+"/"+\
#     str(dateTime.year).zfill(4) + \
#     "_" +str(dateTime.month).zfill(2) + \
#     "_" +str(dateTime.day).zfill(2)+ \
#     "_" +str(dateTime.hour).zfill(2) + \
#     "_" +str(dateTime.minute).zfill(2)+ \
#     "_" +str(dateTime.second).zfill(2)+ \
#     "_" +str(dateTime.microsecond).zfill(2)+ \
#     "_"+labelIn+".h5"
#
#     return pathTail;
#
#
# def getImagePathTailHdf5Mod(dateTime,labelIn):
#     mod = round(dateTime.microsecond/200000)
#     pathTail = labelIn+"/"+\
#     str(dateTime.year).zfill(4) + \
#     "_" +str(dateTime.month).zfill(2) + \
#     "_" +str(dateTime.day).zfill(2)+ \
#     "_" +str(dateTime.hour).zfill(2) + \
#     "_" +str(dateTime.minute).zfill(2)+ \
#     "_" +str(dateTime.second).zfill(2)+ \
#     "_" +str((mod-1)*20).zfill(2)+ \
#     "_"+labelIn+".h5"
#
#     return pathTail;
#
# def saveWebCamImage(capture,imageName):
#     ret,image  = capture.read()
#     print(image)
#     print(imageName)
#     cv2.imwrite(imageName,image)
#
# def grab_frame(cap):
#     ret,frame = cap.read()
#     return cv2.cvtColor(frame,cv2.COLOR_BGR2RGB)
#
# def openUSBCam(dev, width, height):
#     # We want to set width and height here, otherwise we could just do:
#     #     return cv2.VideoCapture(dev)
#     gst_str = ('v4l2src device=/dev/video{} ! '
#                'video/x-raw, width=(int){}, height=(int){} ! '
#                'videoconvert ! appsink').format(dev, width, height)
#     return cv2.VideoCapture(gst_str, cv2.CAP_GSTREAMER)
#
# def getImagePathTailHdf5Mod2(dateTime,labelIn):
#
#     pathTail = labelIn+"/"+\
#     str(dateTime.year).zfill(4) + \
#     "_" +str(dateTime.month).zfill(2) + \
#     "_" +str(dateTime.day).zfill(2)+ \
#     "_" +str(dateTime.hour).zfill(2) + \
#     "_" +str(dateTime.minute).zfill(2)+ \
#     "_" +str(dateTime.second).zfill(2)+ \
#     "_" +str(dateTime.microsecond).zfill(6)[0]+ \
#     "_"+labelIn+".h5"
#
#     return pathTail;
#

myCmd = os.popen('v4l2-ctl --list-devices').read()

leftCamIndex   = cr.getLeftWebCamIndex(myCmd)[1]
rightCamIndex  = cr.getRightWebCamIndex(myCmd)[1]

print(leftCamIndex)
print(rightCamIndex)


# #Initiate the cameras
print("Initiating Visual Cameras with Maximum Resolution")

capLeft  =  cr.openUSBCam(leftCamIndex,2560,1920)
capRight =  cr.openUSBCam(rightCamIndex,2560,1920)

print("Initiating the Thermal Camera")
BUF_SIZE = 2
q = Queue(BUF_SIZE)


print("Defining Directory")
directory = "/home/teamlary/mintsData/jetson001/"


print("Creating Directories")
folderCheck(directory+"left")
folderCheck(directory+"right")
folderCheck(directory+"thermal")


def main():
  print("Entering the main function")
  ctx  = POINTER(uvc_context)()
  dev  = POINTER(uvc_device)()
  devh = POINTER(uvc_device_handle)()
  ctrl = uvc_stream_ctrl()

  res = libuvc.uvc_init(byref(ctx), 0)
  if res < 0:
    print("uvc_init error")
    exit(1)

  try:
    res = libuvc.uvc_find_device(ctx, byref(dev), PT_USB_VID, PT_USB_PID, 0)
    if res < 0:
      print("uvc_find_device error")
      exit(1)

    try:
      res = libuvc.uvc_open(dev, byref(devh))
      if res < 0:
        print("uvc_open error")
        exit(1)

      print("device opened!")

      print_device_info(devh)
      print_device_formats(devh)

      frame_formats = uvc_get_frame_formats_by_guid(devh, VS_FMT_GUID_Y16)
      if len(frame_formats) == 0:
        print("device does not support Y16")
        exit(1)

      libuvc.uvc_get_stream_ctrl_format_size(devh, byref(ctrl), UVC_FRAME_FORMAT_Y16,
        frame_formats[0].wWidth, frame_formats[0].wHeight, int(1e7 / frame_formats[0].dwDefaultFrameInterval)
      )

      res = libuvc.uvc_start_streaming(devh, byref(ctrl), PTR_PY_FRAME_CALLBACK, None, 0)
      if res <0:
        print("uvc_start_streaming failed: {0}".format(res))
        exit(1)
      nn = 10
      try:
        startTime = time.time()
        # your code
        for n in range(nn):
          print("Check: " + str(n))
          capLeft.read()
          capRight.read()
          q.get(True, 500)

        while(True):

            dateTime    = datetime.datetime.now()
            thermalData = q.get(True, 500)
            retLeft , leftImage  = capLeft.read()
            retRight, rightImage = capRight.read()

            threeWayImageNameLeft      = directory + cr.getImagePathTail(dateTime,'left')
            threeWayImageNameRight     = directory + cr.getImagePathTail(dateTime,'right')
            threeWayImageNameThermal   = directory + cr.getImagePathTail(dateTime,'thermal')

            if(retLeft and retRight):
                # hf = h5py.File(threeWayImageName, 'w')
                # print(threeWayImageName)
                # hf.create_dataset('left' , data=leftImage)
                # hf.create_dataset('thermal', data=thermalData)
                # hf.create_dataset('right', data=rightImage)
                # hf.close()

        # When everything done, release the capture
        capLeft.release()
        capRight.release()
        cv2.destroyAllWindows()


        # ani = FuncAnimation(plt.gcf(), update, interval=300)
        # plt.show()


      finally:
        libuvc.uvc_stop_streaming(devh)

      print("done")
    finally:
      libuvc.uvc_unref_device(dev)
  finally:
    libuvc.uvc_exit(ctx)

if __name__ == '__main__':
  main()
