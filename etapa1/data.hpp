#pragma once


#include<string>
#include<iostream>
#include <time.h>



class Data {    
    public:
        Data(): t(time(0)){}
        Data(time_t time): t(time){}
        Data(int year, int month, int day, int hour, int min){
            struct tm tm;

            tm.tm_year = year - 1900;
            tm.tm_mon = month - 1;
            tm.tm_mday = day;
            tm.tm_hour = hour;
            tm.tm_min = min;
            tm.tm_isdst = -1;
            t = mktime(&tm);
        }

        inline time_t get_full_date() const { return t; }

    private:
        time_t t;

};
std::ostream& operator<<(std::ostream&, const Data&);