//
//  1006_Sign_In_and_Sign_Out.cpp
//  PTA&PAT_note&code
//
//  Created by Groveking Li on 2021/1/25.
//

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <vector>
using namespace std;
int toTimeStamp(string& timeStr)
{
    int timeStamp = 0;
    int hour = atoi(timeStr.substr(0, 2).c_str());
    int minute = atoi(timeStr.substr(3, 2).c_str());
    int second = atoi(timeStr.substr(6, 2).c_str());
    timeStamp = hour * 60 * 60 + minute * 60 + second;
    return timeStamp;
}
string toTimeStr(int timeStamp)
{
    string timeStr = "00:00:00";
    int hour = timeStamp/3600;
    int minute = (timeStamp%3600)/60;
    int second = (timeStamp%3600)%60;
    
    string hourStr = timeStamp < 10 ? '0' + std::to_string(hour) : std::to_string(hour);
    string minuteStr = timeStamp < 10 ? '0' + std::to_string(minute) : std::to_string(minute);
    string secondStr = timeStamp < 10 ? '0' + std::to_string(second) : std::to_string(second);
    
    timeStr = hourStr + ":" + minuteStr + ":" + secondStr;
    return  timeStr;
}
void Sign_In_and_Sign_Out()
{
    int recordNum = 0;
    int start = 3600 * 24 - 1;
    int end = 0;
    string startUser, endUser;
    cin >> recordNum;
    for (int i = 0; i < recordNum; i++)
    {
        string userId, inTime, outTime;
        cin >> userId >> inTime >> outTime;
        int inTimeStamp = toTimeStamp(inTime);
        int outTimeStamp = toTimeStamp(outTime);
        if (inTimeStamp <= start)
        {
            startUser = userId;
            start = inTimeStamp;
        }
        if (outTimeStamp >= end)
        {
            endUser = userId;
            end = outTimeStamp;
        }
    }
    
    cout << startUser << ' ' << endUser << endl;
}
