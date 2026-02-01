/* 
    @GOAL:  To study idea behind 'class'
    @DATE:  31 January 2026 
*/ 

#ifndef _DATE_HPP 
#define _DATE_HPP 

class Date 
{
private: 
    int day; 
    int month; 
    int year; 
public: 
    Date* allocateDate(int day, int month, int year); 
    void releaseDate(Date** ppDate); 

    int getDay(Date* pDate); 
    int getMonth(Date* pDate); 
    int getYear(Date* pDate); 

    void setDay(Date* pDate, int day); 
    void setMonth(Date* pDate, int month); 
    void setYear(Date* pDate, int year); 
}; 

Date* allocateDate(int day, int month, int year); 
void releaseDate(Date** ppDate); 

int getDay(Date* pDate); 
int getMonth(Date* pDate); 
int getYear(Date* pDate); 

void setDay(Date* pDate, int day); 
void setMonth(Date* pDate, int month); 
void setYear(Date* pDate, int year); 

void showDate(Date* pDate); 

#endif // _DATE_HPP  

