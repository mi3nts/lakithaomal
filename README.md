# thermalStereoCalib
The current repo provides a thorough desciption into calibrating a tri camera system to detect pixel temperatures of a given jpeg image. 

## Check Available Cameras
```v4l2-ctl --list-devices ```

## Check Camera Capabilties
``` v4l2-ctl -d /dev/videoX --list-formats```
note: Make sure to give the apprproate camera index

## Steps taken 

### Process 1: Data collection for Camera Calibration
Data collection for the camera calibration process can be done simultaneously. This can be done using the 'p01_triCameraCalibration.py' code.

2020_03_29_19_55_02_652197_left
```pip install -U numpy```
