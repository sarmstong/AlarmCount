/**
 * @file main.cpp
 * @author Sam Armstrong
 * @brief Program reads a csv, applies the info to a vector of structs
 *        and displays based on user selection
 * @version 0.1
 * @date 2025-02-01
 * 
 * @copyright Copyright (c) 2025
 * 
 */

 #include <iostream>
 #include <fstream>
 #include <vector>
 #include "alarms.h"
 #include <filesystem>
 #include <cstdio>

 
 
 using namespace std;


 int main()
 {
    ifstream currentCSV;
    vector <AlarmData> allAlarmData;
    string folderPath = "MercuryPrintLogs_noFOV";

    
    int runningCourses = 0;
    int runningFeeds = 0;
    int runningPulls = 0;

    for (const auto& entry : filesystem::directory_iterator(folderPath)) 
    {
        
        string csvFile = entry.path().string();
        cout << "file is: " << csvFile << endl;
        readCSV(csvFile, allAlarmData);
    }

    for(size_t i = 0; i < allAlarmData.size(); i++)
    {
        runningCourses += allAlarmData[i].courseNumber;
        runningFeeds += allAlarmData[i].failedFeed;
        runningPulls += allAlarmData[i].fiberPull;
        // cout << "File is: " << allAlarmData[i].fileName << endl;
        // cout << "Running Courses: " << runningCourses << endl;
        // cout << "Total Failed Feeds: " << runningFeeds << endl;
        // cout << "Total Fiber Pulls: " << runningPulls << endl;
    }

    cout << "Running Courses: " << runningCourses << endl;
    cout << "Total Failed Feeds: " << runningFeeds << endl;
    cout << "Total Fiber Pulls: " << runningPulls << endl;
 

     return(0);
 }