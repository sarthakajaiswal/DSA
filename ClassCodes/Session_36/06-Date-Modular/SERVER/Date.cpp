#include "date.hpp" 

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
