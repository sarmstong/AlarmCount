/**
 * @file analytics.cpp
 * @author Sam Armstrong
 * @brief 
 * @version 0.1
 * @date 2025-02-01
 * 
 * @copyright Copyright (c) 2025
 * 
 */

 #include "alarms.h"
 /**
  * @brief Reads csv into fstream, assign columns of csv to attributes of struct
  * 
  * @param s 
  * @param g 
  */

  //TODO
  //handle logs in which the number of courses goes backwards (restarts layer)
    //current calc ignores those and only takes max - first
  //handle logs in which operator has restarted the same ppg
    //log starts with in progress print i.e. C-600
    //print finishes at C-900
    //operator prints the same program (no log) until C-300
    //calculates to -300 courses


 void readCSV(string s, vector <AlarmData> &g)
 {
 
     
     ifstream inputFile;
     string line;
     AlarmData fileData;
    
     inputFile.open(s);
     if (!inputFile)
     {
         cout << "Error opening file" << endl;
         exit(1);
     }
     
     getline(inputFile,line);
     bool firstRun = true;

     int courseNumber;
     int failedFeeds;
     int fiberPulls;
     int minCourseNumber;
     int minfailedFeeds;
     int minfiberPulls;
 
     while (inputFile.peek() != EOF)
     {
         char delim = ','; 

         string line;

         if (firstRun)
         {
            int headerLines = 30; 
            int totalLinesToSkip = headerLines + 1;
            for(int i = 0; i < totalLinesToSkip; i++) 
            {
                getline(inputFile, line);
            }
         }

         string skipcol;
         getline(inputFile,skipcol,',');
         getline(inputFile,skipcol,',');
         inputFile >> courseNumber >> delim;
         
         //int skipToAlarms = 38; //If FOV column included
         int skipToAlarms = 37; //If no FOV column

         for(int i = 0; i < skipToAlarms; i++)
         {
            getline(inputFile,skipcol,',');
         }
        inputFile >> failedFeeds >> delim;
        inputFile >> fiberPulls >> delim;
        getline(inputFile, skipcol);
        //cout << courseNumber << " " << failedFeeds << " " << fiberPulls << endl;
        if(firstRun)
        {
            minCourseNumber = courseNumber;
            minfailedFeeds = failedFeeds;
            minfiberPulls = fiberPulls;
            firstRun = false;
        }
        
    }
    int totalCourses = courseNumber - minCourseNumber;
    int totalFailedFeeds = failedFeeds - minfailedFeeds;
    int totalFiberPulls = fiberPulls - minfiberPulls;

    fileData.fileName = s;
    fileData.courseNumber = totalCourses;
    fileData.failedFeed = totalFailedFeeds;
    fileData.fiberPull = totalFiberPulls;
    g.push_back(fileData);

    // cout << "Total courses: " << (courseNumber - minCourseNumber) << endl;
    // cout << "Failed feeds: " << (failedFeeds - minfailedFeeds) << endl;
    // cout << "Fiber pulls: " << (fiberPulls - minfiberPulls) << endl;

}