# USAGE
# python fps_demo.py
# python fps_demo.py --display 1

# import the necessary packages
from imutils.video import WebcamVideoStream

import imutils
import cv2
import datetime 

print("[INFO] sampling THREADED frames from webcam...")
vs1 = WebcamVideoStream(src=7).start()
vs2 = WebcamVideoStream(src=8).start()


# loop over some frames...this time using the threaded stream
while True:
    dateTime = datetime.datetime.now()
    print(dateTime)
    frame0 = vs1.read()
    frame1 = vs2.read()
    
    cv2.imwrite(str(dateTime)+'lk.jpg',frame0)

vs1.stop()
vs2.stop()
