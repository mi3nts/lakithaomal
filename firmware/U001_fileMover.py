import os
import shutil
from mintsJetson import camReader as cr


cr.printMINTS("fevSen")

directory                  = "/home/teamlary/mintsData/jetson001Set000/"
lookUpFolder               = directory +"left/"
sourceFolder               = "/home/teamlary/mintsData/jetson001Set0All/"
destinationFolder           = directory

sourceFolderRight          = sourceFolder + "right/"
sourceFolderThermal        = sourceFolder + "thermal/"

destinationFolderRight     = destinationFolder + "right/"
destinationFolderThermal   = destinationFolder + "thermal/"

cr.printLabel("Creating Sub Directories")
cr.folderCheck(destinationFolderRight)
cr.folderCheck(destinationFolderThermal)


print("Listing all files")

if os.path.isdir(lookUpFolder):
    print("Available Files in '{}':".format(lookUpFolder))
    for fileName in sorted(os.listdir(lookUpFolder)):

        if fileName.endswith(".jpg"):
            full= lookUpFolder + fileName
            fileNameCheck   = fileName[0:26]

            # Moving Right Images
            sourcePathRight      = sourceFolderRight      + fileNameCheck + "_right.jpg"
            destinationPathRight = destinationFolderRight + fileNameCheck + "_right.jpg"
            print("Source Path:      {}".format(sourcePathRight))
            print("Destination Path: {}".format(destinationPathRight))
            if(os.path.exists(sourcePathRight)):
                print("Moving '{}' to '{}'".format(sourcePathRight,destinationPathRight))
                shutil.copyfile(sourcePathRight, destinationPathRight)

            else:
                print("File'{}' does not exist".format(sourcePathRight))

            # Moving Thermal Images
            sourcePathThermal      = sourceFolderThermal      + fileNameCheck + "_thermal.jpg"
            destinationPathThermal = destinationFolderThermal + fileNameCheck + "_thermal.jpg"
            print("Source Path:      {}".format(sourcePathThermal))
            print("Destination Path: {}".format(destinationPathThermal))
            if(os.path.exists(sourcePathThermal)):
                print("Moving '{}' to '{}'".format(sourcePathThermal,destinationPathThermal))
                shutil.copyfile(sourcePathThermal, destinationPathThermal)

            else:
                print("File'{}' does not exist".format(sourcePathThermal))

else:
    print("Directory '{}' does not exist".format(lookUpFolder))

cr.printLabel("MINTS done")
