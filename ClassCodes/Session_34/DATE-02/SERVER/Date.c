/*
    @GOAL:      Date modular implementation - server side  
    @AUTHOR:    Sarthak A Jaiswal 
*/ 

#include "Date.h" 

struct Date* allocateDate(int init_day, int init_month, int init_year) 
{
    struct Date* pDate = (struct Date*)malloc(sizeof(struct Date)); 
    if(NULL == pDate) 
    {
        puts("allocation error"); 
        exit(EXIT_FAILURE); 
    } 

    pDate->day = init_day; 
    pDate->month = init_month; 
    pDate->year = init_year; 

    return (pDate); 
} 

int getDay(struct Date* pDate) 
{
    return (pDate->day); 
} 

int getMonth(struct Date* pDate) 
{
    return (pDate->month); 
} 

int getYear(struct Date* pDate) 
{
    return (pDate->year); 
} 

void setDay(struct Date* pDate, int newDay) 
{
    pDate->day = newDay; 
} 

void setMonth(struct Date* pDate, int newMonth) 
{
    pDate->month = newMonth; 
} 

void setYear(struct Date* pDate, int newYear) 
{
    pDate->year = newYear; 
} 

void showDate(struct Date* pDate) 
{
    printf("%d/%d/%d\n", pDate->day, pDate->month, pDate->year); 
} 

void releaseDate(struct Date** ppDate) 
{
    free(*ppDate); 
    *ppDate = NULL; 
} 

