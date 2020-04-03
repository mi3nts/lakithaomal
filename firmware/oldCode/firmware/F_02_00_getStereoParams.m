
function [frameLeftRect] = F_02_00_getStereoParams(stereoParamsStruct)



persistent stereoParamsLeftAndRight 

if isempty(stereoParamsLeftAndRight)
    stereoParamsLeftAndRight = stereoParameters(stereoParamsStruct);
end
    
% [frameLeftRect, frameRightRect] = rectifyStereoImages(frameLeft,...
%                                                             frameRight,...
%                                                                 stereoParamsLeftAndRight);
    
end


