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


cr.printLabel("Going Through Left Files")
resizeImages(sourceLeft,destinationLeft,resizeWidth)

cr.printLabel("Going Through Right Files")
resizeImages(sourceRight,destinationRight,resizeWidth)

cv2.destroyAllWindows()
cr.printLabel("MINTS done")
