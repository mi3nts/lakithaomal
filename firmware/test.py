# USAGE
# python fps_demo.py
# python fps_demo.py --display 1

# import the necessary packages
from __future__ import print_function
from imutils.video import WebcamVideoStream
from imutils.video import FPS
import argparse
import imutils
import cv2

# construct the argument parse and parse the arguments
ap = argparse.ArgumentParser()
ap.add_argument("-n", "--num-frames", type=int, default=1000,
	help="# of frames to loop over for FPS test")
ap.add_argument("-d", "--display", type=int, default=-1,
	help="Whether or not frames should be displayed")
args = vars(ap.parse_args())

# # grab a pointer to the video stream and initialize the FPS counter
# print("[INFO] sampling frames from webcam...")
# stream1 = cv2.VideoCapture(0)
# stream2 = cv2.VideoCapture(1)
# fps = FPS().start()

# # loop over some frames
# while fps._numFrames < args["num_frames"]:
# 	# grab the frame from the stream and resize it to have a maximum
# 	# width of 400 pixels
# 	(grabbed, frame1) = stream1.read()
# 	(grabbed, frame2) = stream2.read()
# 	frame1 = imutils.resize(frame1, width=400)
# 	frame2 = imutils.resize(frame2, width=400)

# 	# check to see if the frame should be displayed to our screen
# 	if args["display"] > 0:
# 		cv2.imshow("Frame1", frame1)
# 		cv2.imshow("Frame2", frame2)
# 		key = cv2.waitKey(1) & 0xFF

# 	# update the FPS counter
# 	fps.update()

# # stop the timer and display FPS information
# fps.stop()
# print("[INFO] elasped time: {:.2f}".format(fps.elapsed()))
# print("[INFO] approx. FPS: {:.2f}".format(fps.fps()))

# # do a bit of cleanup
# stream1.release()
# stream2.release()
# cv2.destroyAllWindows()

# created a *threaded *video stream, allow the camera senor to warmup,
# and start the FPS counter
print("[INFO] sampling THREADED frames from webcam...")
vs1 = WebcamVideoStream(src=7).start()
# vs2 = WebcamVideoStream(src=1).start()
fps = FPS().start()

# loop over some frames...this time using the threaded stream
while fps._numFrames < args["num_frames"]:
	# grab the frame from the threaded video stream and resize it
	# to have a maximum width of 400 pixels
	frame0 = vs1.read()
	# frame1 = vs2.read()
	frame0 = imutils.resize(frame0, width=400)
	# frame1 = imutils.resize(frame1, width=400)

	# check to see if the frame should be displayed to our screen
	if args["display"] > 0:
		cv2.imshow("Frame1", frame0)
		# cv2.imshow("Frame2", frame1)
		key = cv2.waitKey(1) & 0xFF

	# update the FPS counter
	fps.update()

# stop the timer and display FPS information
fps.stop()
print("[INFO] elasped time: {:.2f}".format(fps.elapsed()))
print("[INFO] approx. FPS: {:.2f}".format(fps.fps()))

# do a bit of cleanup
cv2.destroyAllWindows()
vs1.stop()
vs2.stop()
