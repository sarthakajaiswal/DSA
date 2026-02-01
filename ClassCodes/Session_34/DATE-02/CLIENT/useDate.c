/*
    @GOAL:      Date modular implementation - client side  
    @AUTHOR:    Sarthak A Jaiswal 
*/ 

#include "Date.h" 

void testDate(void); 

int main(void) 
{
    testDate(); 
    return (0); 
} 

void testDate(void) 
{
    struct Date* myDate = allocateDate(24, 1, 2026); 

    int day = getDay(myDate); 
    int month = getMonth(myDate); 
    int year = getYear(myDate); 

    printf("%d/%d/%d\n", day, month, year); 

    showDate(myDate); 

    setDay(myDate, 27); 
    setYear(myDate, 4); 
    setYear(myDate, 2029); 

    showDate(myDate); 

    releaseDate(&myDate); 
} 
