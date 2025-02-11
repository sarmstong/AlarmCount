/**
 * @file analytics.h
 * @author Sam Armstrong
 * @brief analytics header file
 * @version 0.1
 * @date 2025-02-01
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#ifndef ANALYTICS_H
#define ANALYTICS_H

#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <cctype>
#include <sstream>

using namespace std;



struct AlarmData
{
    string fileName;
    int courseNumber;
    int failedFeed;
    int fiberPull;
};

void readCSV(string s, vector <AlarmData> &g);


#endif
//create a vector of AlarmData entries
//each file is its own row in the vector
//at the end take the data from the vectors and display the results
