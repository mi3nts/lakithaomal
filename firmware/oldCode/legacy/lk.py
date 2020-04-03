import numpy as np
import cv2
import datetime

gst0 = ('v4l2src device=/dev/video3 do-timestamp=true ! \
         image/jpeg, width=2592, height=1944, framerate=15/1 \
           ! jpegparse ! jpegdec ! videoconvert ! appsink ')

gst1 = ('v4l2src device=/dev/video2 do-timestamp=true ! \
         image/jpeg, width=2592, height=1944, framerate=15/1 \
           ! jpegparse ! jpegdec ! videoconvert ! appsink ')

cap_receive1 = cv2.VideoCapture(gst0, cv2.CAP_GSTREAMER)
cap_receive2 = cv2.VideoCapture(gst1, cv2.CAP_GSTREAMER)



while True:
    print(datetime.datetime.now())
    if not cap_receive1.isOpened() :
        print('VideoCapture 1 not opened')
        exit(0)
    if not cap_receive2.isOpened()  :
        print('VideoCapture 2 not opened')
        exit(0)


    ret,frame1 = cap_receive1.read()
    if not ret:
        print('empty frame')
        continue
    
    ret,frame2 = cap_receive2.read()
    if not ret:
        print('empty frame 2')
        continue
    

    # cv2.imshow('receive1', frame1)
    # cv2.imshow('receive2', frame2)

    if cv2.waitKey(1)&0xFF == ord('q'):
        break

cap_receive.release()
