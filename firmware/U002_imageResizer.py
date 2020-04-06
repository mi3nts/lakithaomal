import os
import shutil
from mintsJetson import camReader as cr
import imutils
import cv2

cr.printMINTS("fevSen")

directory          = "/home/teamlary/mintsData/jetson001Set2/"

sourceLeft         = directory +"left/"
sourceRight        = directory +"right/"

destinationLeft    = directory +"leftResized/"
destinationRight   = directory +"rightResized/"

resizeWidth        = 648

cr.printLabel("Creating Sub Directories")
cr.folderCheck(destinationLeft)
cr.folderCheck(destinationRight)



def resizeAndWrite(source,destination,widthIn):
    if (os.path.exists(source)):
        print("Source Path Left       : {}".format(source))
        print("Destination Path Right : {}".format(destination))
        cr.folderCheck(os.path.dirname(destination))
        resized = imutils.resize(cv2.imread(source) , width=widthIn)
        print("Writing Resized Image of '{}' to '{}'".format(source,destination))
        cv2.imwrite(destination,resized)
        return True, resized;
    else:
        print("File'{}' does not exist".format(sourcePathRight))
        return False, None;


def resizeImages(source,destination,widthIn):
    if os.path.isdir(source):
        print("Available Files in '{}':".format(source))
        for fileName in sorted(os.listdir(source)):
            if fileName.endswith(".jpg"):
                sourceFile        = source + fileName
                destinationFile   = destination + fileName.replace(".jpg", "Resized.jpg")
                print("Source Path      : {}".format(sourceFile))
                print("Destination Path : {}".format(destinationFile))
                resizedVal, resized = resizeAndWrite(sourceFile,destinationFile,widthIn)
                cv2.imshow('resized' ,resized )
                if cv2.waitKey(1)&0xFF == ord('q'):
                    break
    else:
        print("Directory '{}' does not exist".format(sourceLeft))





def saveRectifiedForMatStereo(leftFileNames,rightFileNames,stereoParams):
    for leftFileNamesCurrent,rightFileNamesCurrent in \
                   zip(leftFileNames,rightFileNames):

        imLeft  = cv2.imread(leftFileNamesCurrent)
        imRight = cv2.imread(rightFileNamesCurrent)

        imLeftRemapped =cv2.remap(imLeft,stereoParams['mapXLeft'],\
                                            stereoParams['mapYLeft'],\
                                                cv2.INTER_CUBIC)

        imRightRemapped=cv2.remap(imRight,stereoParams['mapXRight'],\
                                            stereoParams['mapYRight'],
                                                cv2.INTER_CUBIC)

        newLeft  = leftFileNamesCurrent.replace("Resized", "ResizedRectified")
        newRight = rightFileNamesCurrent.replace("Resized", "ResizedRectified")

        print("Writing Rectified Left  Image of '{}' as '{}'".format(leftFileNamesCurrent,newRight))
        cv2.imwrite(newLeft,    imLeftRemapped);
        print("Writing Rectified Right Image of '{}' as '{}'".format(rightFileNamesCurrent,newRight))
        cv2.imwrite(newRight,   imRightRemapped);


def saveUndistortedForMatThermal(thermalFileNames,thermalParams):
    for thermalFileNamesCurrent in thermalFileNames:

        imThermal  = cv2.imread(thermalFileNamesCurrent)

        imThermalRemapped = cv2.undistort(\
                                    imThermal,\
                                    thermalParams['mtxThermal'],\
                                    thermalParams['distThermal']
                                    , None,\
                                    thermalParams['newcameramtx']\
                                    )

        newThermal  = thermalFileNamesCurrent.replace("thermal", "thermalUndistorted")

        print("Writing Rectified Thermal  Image of '{}' as '{}'".format(thermalFileNamesCurrent,newThermal))
        cv2.imwrite(newThermal,    imThermalRemapped);


def getReplacedFileNames(leftFileNames,replace,replaceWith):
    thermalFileNames = []
    for leftFileName in leftFileNames:
        thermalFileNames.append(leftFileName.replace(replace,replaceWith))
    return thermalFileNames;


cr.printLabel("Going Through Left Files")
resizeImages(sourceLeft,destinationLeft,resizeWidth)

cr.printLabel("Going Through Right Files")
resizeImages(sourceRight,destinationRight,resizeWidth)

cv2.destroyAllWindows()
cr.printLabel("MINTS done")
