



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

myCmd = os.popen('v4l2-ctl --list-devices').read()

leftCamIndex   = cr.getLeftWebCamIndex(myCmd)[1]

print(leftCamIndex)


# #Initiate the cameras
print("Initiating Visual Cameras with Maximum Resolution")

capLeft  =  WebcamVideoStream(leftCamIndex).start()


print("Defining Directory")
directory = "/home/teamlary/mintsData/jetson001/"


print("Creating Directories")
cr.folderCheck(directory+"left")

nn=10

def main():

        startTime = time.time()
        # your code
        for n in range(nn):
          print("Check: " + str(n))
          capLeft.read()

        while(True):

            dateTime    = datetime.datetime.now()
            print(dateTime)

            leftImage  = capLeft.read()

         
            if (leftImage is None):
              print(leftImage)
              break
            
            leftImageName      = directory + cr.getImagePathTail(dateTime,'left')
        
            cv2.imwrite(leftImageName,leftImage)
        
        capLeft.stop()
        

if __name__ == '__main__':
  main()
