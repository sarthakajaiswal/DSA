/* 
    @GOAL:  study why and how to define class functions outside the class 
    @DATE:  01 February 2026 
*/ 

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

/* 
// this will be c like global function 
int getDay() 
{} 
*/ 

Date::Date(int init_day, int init_month, int init_year) 
{
    this->day = init_day; 
    this->month = init_year; 
    this->year = init_year; 
} 

int Date::getDay() 
{
    return this->day; 
} 

int Date::getMonth() 
{
    return this->month; 
} 

int Date::getYear() 
{
    return this->year; 
} 

void Date::setDay(int newDay) 
{
    this->day = newDay; 
} 

void Date::setMonth(int newMonth) 
{
    this->month = newMonth; 
} 

void Date::setYear(int newYear) 
{
    this->year = newYear; 
} 

void Date::show() 
{
    std::cout << day << "/" << month << "/" << year << std::endl; 
} 

int main() 
{
    Date myDate(31, 1, 2024); 

    myDate.show(); 
    myDate.setMonth(4); 
    myDate.show(); 

    int year = myDate.getYear(); 
    std::cout << "year = " << year << std::endl; 

    return EXIT_SUCCESS; 
} 
