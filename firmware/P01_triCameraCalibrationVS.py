

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
import imutils
import numpy, scipy.io
from imutils.video import WebcamVideoStream
# from matplotlib import pyplot as plt
# from matplotlib.animation import FuncAnimation
# from PIL import Image
#
# from matplotlib import cm
from mintsJetson import camReader as cr

def py_frame_callback(frame, userptr):

  array_pointer = cast(frame.contents.data, POINTER(c_uint16 * (frame.contents.width * frame.contents.height)))
  data = np.frombuffer(
    array_pointer.contents, dtype=np.dtype(np.uint16)
  ).reshape(
    frame.contents.height, frame.contents.width
  ) # no copy

  # data = np.fromiter(
  #   frame.contents.data, dtype=np.dtype(np.uint8), count=frame.contents.data_bytes
  # ).reshape(
  #   frame.contents.height, frame.contents.width, 2
  # ) # copy

  if frame.contents.data_bytes != (2 * frame.contents.width * frame.contents.height):
    return

  if not q.full():
    q.put(data)

PTR_PY_FRAME_CALLBACK = CFUNCTYPE(None, POINTER(uvc_frame), c_void_p)(py_frame_callback)

myCmd = os.popen('v4l2-ctl --list-devices').read()

leftCamIndex   = cr.getLeftWebCamIndex(myCmd)[1]
rightCamIndex  = cr.getRightWebCamIndex(myCmd)[1]

print(leftCamIndex)
print(rightCamIndex)


# #Initiate the cameras
print("Initiating Visual Cameras with Maximum Resolution")

capLeft  =  WebcamVideoStream(leftCamIndex).start()
capRight =  WebcamVideoStream(rightCamIndex).start()

print("Initiating the Thermal Camera")
BUF_SIZE = 2
q = Queue(BUF_SIZE)


print("Defining Directory")
directory = "/home/teamlary/mintsData/jetson001/"


print("Creating Directories")
cr.folderCheck(directory+"left")
cr.folderCheck(directory+"right")
cr.folderCheck(directory+"thermal")


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
            leftImage  = capLeft.read()
            rightImage = capRight.read()
         
            if (thermalData is None) or ((leftImage is None) or (rightImage is None)) :
              print(thermalData)
              print(leftImage)
              print(rightImage) 
              break
            
            leftImageName      = directory + cr.getImagePathTail(dateTime,'left')
            rightImageName     = directory + cr.getImagePathTail(dateTime,'right')
            thermalImageName   = directory + cr.getImagePathTail(dateTime,'thermal')

            thermalData   = cv2.resize(thermalData[:,:], (640, 480))
            thermalImage  = cr.raw_to_8bit(thermalData)

            cv2.imwrite(leftImageName,leftImage)
            cv2.imwrite(rightImageName,rightImage)
            cv2.imwrite(thermalImageName,thermalImage)
            time.sleep(1)
            print(dateTime)
            # cv2.imshow("Left",imutils.resize(leftImage, width=640))
            # cv2.imshow("Right", imutils.resize(rightImage, width=640))
            # cv2.imshow("Thermal", thermalImage)
            # key = cv2.waitKey(1) & 0xFF

            # if(retLeft and retRight):
            #     # hf = h5py.File(threeWayImageName, 'w')
            #     # print(threeWayImageName)
            #     # hf.create_dataset('left' , data=leftImage)
            #     # hf.create_dataset('thermal', data=thermalData)
            #     # hf.create_dataset('right', data=rightImage)
            #     # hf.close()

        # When everything done, release the capture
        # capLeft.release()
        # capRight.release()
        capLeft.stop()
        capRight.stop()
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
