
import numpy as np
import cv2

cap = cv2.VideoCapture(0) # video capture source camera (Here webcam of laptop)
ret,frame = cap.read() # return a single frame in variable `frame`
cv2.destroyAllWindows()
cv2.imshow('img1',frame)
cv2.waitKey(1)
while(True):
    cv2.imshow('img1',frame)
    cv2.waitKey(1) #display the captured image
    if cv2.waitKey(1) & 0xFF == ord('y'): #save on pressing 'y'
        # cv2.imwrite('images/c1.png',frame)
        # cv2.destroyAllWindows()
        break
cap.release()
