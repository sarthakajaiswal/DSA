/*
    @GOAL:      Date modular implementation 
    @AUTHOR:    Sarthak A Jaiswal 
*/ 

#ifndef _DATE_H 
#define _DATE_H 

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

void showDate(struct Date* pDate); 

void releaseDate(struct Date** ppDate); 

#endif /* _DATE_H */ 

