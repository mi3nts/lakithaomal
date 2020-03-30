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
#  Deployment 001 :
# Gaining 3 images from the 3 cameras
#!/usr/bin/env python
# -*- coding: utf-8 -*-
import datetime
from uvctypes import *
import time
import cv2
import numpy as np
try:
  from queue import Queue
except ImportError:
  from Queue import Queue
import platform
import os
import threading
import time
import numpy, scipy.io


BUF_SIZE = 2
q = Queue(BUF_SIZE)

def py_frame_callback(frame, userptr):

  array_pointer = cast(frame.contents.data, POINTER(c_uint16 * (frame.contents.width * frame.contents.height)))
  data = np.frombuffer(
    array_pointer.contents, dtype=np.dtype(np.uint16)
  ).reshape(
    frame.contents.height, frame.contents.width
  ) # no copy

  if frame.contents.data_bytes != (2 * frame.contents.width * frame.contents.height):
    return

  if not q.full():
    q.put(data)

PTR_PY_FRAME_CALLBACK = CFUNCTYPE(None, POINTER(uvc_frame), c_void_p)(py_frame_callback)

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
        if "7-4.4" in name:
            camString =  int(lines[num].strip().replace("/dev/video",""))
            return  True ,camString;

    return False , "xxx";


def getRightWebCamIndex(myCmd):
    lines = myCmd.splitlines()
    for num, name in enumerate(lines, start=1):
        if "7-4.3" in name:
            camString =  int(lines[num].strip().replace("/dev/video",""))
            return True, camString;

    return False, "xxx";


def takeWebCamImage(indexIn):
    capture = cv2.VideoCapture(indexIn)
    time.sleep(0.1)
    ret0, out_image = capture.read()


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

def saveWebCamImage(capture,imageName):
    ret,image  = capture.read()
    print(image)
    print(imageName)
    cv2.imwrite(imageName,image)

def main():
  cap = cv2.VideoCapture(0) # video capture source camera (Here webcam of laptop)
  ret,frame = cap.read() # return a single frame in variable `frame`
  cv2.destroyAllWindows()
  cv2.imshow('img1',frame)
  cv2.waitKey(1)


  ctx = POINTER(uvc_context)()
  dev = POINTER(uvc_device)()
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

      myCmd = os.popen('v4l2-ctl --list-devices').read()
      print(myCmd)
      leftCamIndex   =  getLeftWebCamIndex(myCmd)[1]
      print(leftCamIndex)
      rightCamIndex  = getRightWebCamIndex(myCmd)[1]
      print(rightCamIndex)

      capLeft       = cv2.VideoCapture(leftCamIndex)
      capRight      = cv2.VideoCapture(rightCamIndex)

      try:
          startTime = time.time()
          while True:
              # Thermal Camera Save
              retLeft, leftImage = capLeft.read()
              retRight,rightImage = capRight.read()

              elapsedTime = time.time() - startTime
              print(elapsedTime)

              if elapsedTime > 5:

                  readTime = time.time()
                  dateTime = datetime.datetime.now()

                  leftImageName    = "threeWayImageDataSets/utdSet6/"+ getImagePathTail(dateTime,'left')
                  rightImageName   = "threeWayImageDataSets/utdSet6/"+ getImagePathTail(dateTime,'right')
                  thermalImageName = "threeWayImageDataSets/utdSet6/"+ getImagePathTail(dateTime,'thermal')
                  kelvinImageName  = "threeWayImageDataSets/utdSet6/"+ getImagePathTailMat(dateTime,'kelvin')
                  celciusImageName = "threeWayImageDataSets/utdSet6/"+ getImagePathTailMat(dateTime,'celcius')

                  print("==================================")
                  print("Taking Snapshot")
                  time.sleep(2)
                  thermalData = q.get(True, 500)
                  print("==================================")

                  retLeft, leftImage   = capLeft.read()
                  retRight, rightImage = capRight.read()
                  print("Read Time Thermal= "+ str(time.time() - readTime))
                  print("==================================")
                  cv2.waitKey(1)
                  startTime = time.time()
                  dateTime = datetime.datetime.now()

                  if (retLeft and retRight) :

                      thermalData   = cv2.resize(thermalData[:,:], (640, 480))
                      thermalKelvin = thermalData;
                      thermalCelcius = ktoc(thermalData);
                      scipy.io.savemat(kelvinImageName, mdict={'thermalKelvin': thermalKelvin})
                      scipy.io.savemat(celciusImageName, mdict={'thermalCelcius': thermalCelcius})
                      thermalImage  = raw_to_8bit(thermalData)
                      print(leftImageName)
                      print(rightImageName)
                      cv2.imwrite(leftImageName,leftImage)
                      cv2.imwrite(rightImageName,rightImage)
                      cv2.imwrite(thermalImageName,thermalImage)


              capLeft.release()
              capRight.release()

          cv2.destroyAllWindows()
      finally:
        libuvc.uvc_stop_streaming(devh)

      print("done")
    finally:
      libuvc.uvc_unref_device(dev)
  finally:
    libuvc.uvc_exit(ctx)

if __name__ == '__main__':
  main()
