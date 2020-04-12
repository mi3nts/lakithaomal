function saveName = getSaveNameJetson(saveNamePre,jetsonSN,setNum)
%GETSAVENAME Summary of this function goes here
%   Detailed explanation goes here
dateTime = now;
saveName = strcat("dataFiles/"+saveNamePre,jetsonSN,'_Set',setNum,'_',...
                num2str(year(dateTime),'%04.f'),'_',num2str(month(dateTime),'%02.f'),'_',num2str(day(dateTime),'%02.f'),'_',...
                num2str(hour(dateTime),'%02.f'),'_',num2str(minute(dateTime),'%02.f'),'_',num2str(second(dateTime),'%02.f'),...
                '.mat')
end

