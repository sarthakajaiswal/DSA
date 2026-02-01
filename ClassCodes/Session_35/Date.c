/* 
    @GOAL:  Base code for studying journey of struct -> class 
    @DATE:  31 January 2026 
*/ 

#include <stdio.h> 
#include <stdlib.h> 

struct Date 
{
    int day; 
    int month; 
    int year; 
};  

void test(void); 

int main(void) 
{
    struct Date myDate; 
    myDate.day = 25; 
    myDate.month = 1; 
    myDate.year = 2026; 

    test(); 

    return (0); 
} 

void test(void) 
{
    struct Date* pDate = (struct Date*)malloc(sizeof(struct Date)); 
    if(NULL == pDate) 
    {
        fprintf(stderr, "test():malloc():fatal:out of memory"); 
        exit(EXIT_FAILURE); 
    } 

    pDate->day = 25; 
    pDate->month = 1; 
    pDate->year = 2026; 

    free(pDate); 
    pDate = NULL; 
} 

void testDate() 
{
    struct Date* myDate = allocateDate(25, 1, 2026); 

    myDate->day = 28; 
} 