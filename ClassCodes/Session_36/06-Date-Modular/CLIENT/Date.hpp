#ifndef DATE_HPP 
#define DATE_HPP 

#include <iostream> 

class Date 
{
    private: 
        int day; 
        int month; 
        int year; 

    public: 
        Date(int init_day, int init_month, int init_year); 
        int getDay(); 
        int getMonth(); 
        int getYear(); 
        void setDay(int newDay); 
        void setMonth(int newMonth); 
        void setYear(int newYear); 
        void show(); 
};

#endif // DATE_HPP 
