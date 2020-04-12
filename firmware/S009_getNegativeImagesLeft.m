
% # ***************************************************************************
% #   Stereo Vision - Thermal 
% #   ---------------------------------
% #   Written by: Lakitha Omal Harindha Wijeratne
% #   - for -
% #   Mints: Multi-scale Integrated Sensing and Simulation
% #   ---------------------------------
% #   Date: April 4th, 2020
% #   ---------------------------------
% #   This module is written for generic implimentation of MINTS projects
% #   --------------------------------------------------------------------------
% #   https://github.com/mi3nts
% #   http://utdmints.info/
% #  ***************************************************************************


%% Step 009: Generating Negative Images For Thermal Mapping 

clc
clear all 
close all 

directory = "/home/teamlary/mintsData/jetson002Set1/leftResizedRectified/"
directoryData =  dir( strcat(directory,"*.jpg"))
imageDataTable  = unique(struct2table(directoryData),'rows')
mkdir(strrep(directory,"left","leftNegative"))

for n = 1:height(imageDataTable)
    
    fileName = strcat(imageDataTable.folder{n}+"/",imageDataTable.name{n})
    A = imread(fileName);
    C = imcomplement(A);  
    image(C)
    FN = strrep(fileName,"left","leftNegative")
    imwrite(C,FN)
    
end 
