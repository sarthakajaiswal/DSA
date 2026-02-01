/* 
    @GOAL:  To study idea behind 'class'
    @DATE:  31 January 2026 
*/ 

#include <iostream> 
#include <cstdio> 
#include <cstdlib> 
#include "Date.hpp" 

Date* allocateDate(int day, int month, int year) 
{
    Date* pNewDate = (Date*)malloc(sizeof(Date)); 
    if(NULL == pNewDate) 
    {
        fprintf(stderr, "allocateDate():malloc():out of memory\n"); 
        return NULL; 
    } 

    pNewDate->day = day; 
    pNewDate->month = month; 
    pNewDate->year = year; 
} 

void releaseDate(Date** ppDate) 
{
    free(*ppDate); 
    *ppDate = NULL; 
} 

int getDay(Date* pDate) 
{
    return pDate->day; 
} 

int getMonth(Date* pDate) 
{
    return pDate->month; 
} 

int getYear(Date* pDate) 
{
    return pDate->year; 
} 

void setDay(Date* pDate, int day) 
{
    pDate->day = day; 
} 

void setMonth(Date* pDate, int month) 
{
    pDate->month = month; 
} 

void setYear(Date* pDate, int year) 
{
    pDate->year = year; 
} 

void showDate(Date* pDate) 
{
    std::cout << pDate->day << "/" << pDate->month << "/" << pDate->year << std::endl; 
} 
