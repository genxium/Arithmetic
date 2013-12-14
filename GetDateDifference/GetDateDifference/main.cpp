//
//  main.cpp
//  GetDateDifference
//
//  Created by Wing on 15/8/13.
//  Copyright (c) 2013 Wing. All rights reserved.
//

#include <iostream>
#include <string>
#include <time.h>
using namespace std;

// Gregorian calendar
int secsPerDay = 86400;
int daysPerFourHundredYears= 146097;
int daysPerHundredYears= 36524;
int daysPerFourYears= 1461;
int daysPerYear= 365;

bool isLeapYear(int year){
    if(year%400==0) return true;
    else if(year%4==0 && year%100!=0) return true;
    else return false;
}

__int64_t getDayFromOrigin(string date){
    
    int year = atoi(date.substr(0,4).c_str());
    int month = atoi(date.substr(5,2).c_str());
    int day = atoi(date.substr(8,2).c_str());

    __int64_t ret=0;
    int r0=year;
    int q1=r0/400, r1=r0%400;
    ret+=(__int64_t)q1*daysPerFourHundredYears;
    int q2=r1/100, r2=r1%100;
    ret+=(__int64_t)q2*daysPerHundredYears;
    int q3=r2/4, r3=r2%4;
    ret+=(__int64_t)q3*daysPerFourYears+(__int64_t)r3*daysPerYear;
    
    for(int i=1;i<month;++i){
        if(i==1||i==3||i==5||i==7||i==8||i==10||i==12){
            ret+=(__int64_t)31;
        }
        else if(i==4||i==6||i==9||i==11){
            ret+=(__int64_t)30;
        }
        else{ // i==2
            if(isLeapYear(year)) {ret+=29.0;}
            else {ret+=(__int64_t)28;}
        }
    }
    ret+=(__int64_t)(day-1);
    return ret;
}

int main(int argc, const char * argv[])
{
    string date1="2005-03-01";
    string date2="1900-01-01";
    __int64_t ans=getDayFromOrigin(date1)-getDayFromOrigin(date2);
    printf("date difference from %s to %s is %lld day(s)\n", date1.c_str(), date2.c_str(),ans);
    return 0;
}

