/*
    @GOAL:      Date class implementation 
    @AUTHOR:    Sarthak A Jaiswal 
*/ 

#include <stdio.h> 
#include <stdlib.h> 

struct Date 
{
    int day; 
    int month; 
    int year; 
}; 

struct Date* allocateDate(int init_dat, int init_month, int init_year) ; 

int getDay(struct Date* pDate); 
int getMonth(struct Date* pDate); 
int getYear(struct Date* pDate); 
void setDay(struct Date* pDate, int newDay); 
void setMonth(struct Date* pDate, int newMonth); 
void setYear(struct Date* pDate, int newYear); 

void shpwDate(struct Date* pDate); 

void releaseDate(struct Date** ppDatE); 

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

void shpwDate(struct Date* pDate) 
{
    printf("%d/%d/%d\n", pDate->day, pDate->month, pDate->year); 
} 

void releaseDate(struct Date** ppDate) 
{
    free(*ppDate); 
    *ppDate = NULL; 
} 

