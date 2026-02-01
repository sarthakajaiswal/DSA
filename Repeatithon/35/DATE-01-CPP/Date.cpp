#include "Date.hpp" 
#include <stdio.h> 
#include <stdlib.h> 

Date* allocateDateInstance(int init_day, int init_month, int init_year) 
{
    Date* newDate = NULL; 

    newDate = (Date*)malloc(sizeof(Date)); 
    if(newDate == NULL) 
    {
        fprintf(stderr, "allocateDateInstance(): malloc() > memory allocation failed\n"); 
        exit(EXIT_FAILURE); 
    } 

    newDate->day = init_day; 
    newDate->month = init_month; 
    newDate->year = init_year; 

    return (p); 
} 

int getDay(Date* pDate) 
{
    return (pDate->day); 
} 

int getMonth(Date* pDate) 
{
    return (pDate->month); 
} 

int getYear(Date* pDate) 
{
    return (pDate->year); 
} 

void setDay(Date* pDate, int new_day) 
{
    pDate->day = new_day; 
} 

void setMonth(Date* pDate, int new_month) 
{
    pDate->month = new_month; 
} 

void show(Date* pDate) 
{
    printf("%d-%d-%d\n", pDate->day, pDate->month, pDate->year); 
} 

void releaseDateInstance(Date* pDate) 
{
    if(pDate) 
    {
        free(pDate); 
        pDate = NULL; 
    } 
} 

// ============== 
#include <stdio.h> 
#include <stdlib.h> 
#include "Date.hpp" 

Date* allocateDateInstance(int init_day, int init_month, int init_year) 
{
    Date* p = NULL; 

    p = (Date*)malloc(sizeof(Date)); 
    if(NULL == p) 
    {
        fprintf(stderr, "allocateDateInstance(): malloc() > failed to allocate memory\n"); 
        exit(EXIT_FAILURE); 
    } 

    p->day = init_day; 
    p->month = init_month; 
    p->year = init_year; 

    return (p); 
} 

int getDay(Date* pDate) 
{
    return (pDate->day); 
} 

int getMonth(Date* pDate) 
{
    return (pDate->month); 
} 

int getYear(Date* pDate) 
{
    return (pDate->year); 
} 

void setDay(Date* pDate, int new_day) 
{
    pDate->day = new_day; 
} 

void setMonth(Date* pDate, int new_month) 
{
    pDate->month = new_month; 
} 

void setYear(Date* pDate, int new_year) 
{
    pDate->year = new_year; 
} 

void show(Date* pDate) 
{
    printf("%d-%d-%d\n", pDate->day, pDate->month, pDate->year); 
} 

void releaseDateInstance(Date* pDate) 
{
    if(pDate) 
    {
        free(pDate); 
        pDate = NULL; 
    } 
} 

//======= 
#include "Date.hpp"
#include <stdio.h> 
#include <stdlib.h> 

Date* allocateDateInstance(int new_day, int new_month, int new_year) 
{
    Date* p = NULL; 

    p = (Date*)malloc(sizeof(Date)); 
    if(NULL == p) 
    {
        fprintf(stderr, "allocateDateInstance(): malloc() > failed to allocate memory\n"); 
        exit(EXIT_FAILURE); 
    } 

    p->day = new_day; 
    p->month = new_month; 
    p->year = new_year; 

    return (p); 
} 

int getDay(Date* pDate) 
{
    return (pDate->day); 
} 

int getMonth(Date* pDate) 
{
    return (pDate->month); 
} 

int getYear(Date* pDate) 
{
    return (pDate->year); 
} 

void setDay(Date* pDate, int new_day) 
{
    pDate->day = new_day; 
} 

void setMonth(Date* pDate, int new_month) 
{
    pDate->month = new_month; 
} 

void setYear(Date* pDate, int new_year) 
{
    pDate->year = new_year; 
} 

void showDate(Date* pDate) 
{
    printf("%d-%d-%d\n", pDate->day, pDate->month, pDate->year); 
} 

void releaseDateInstance(Date* pDate) 
{
    if(pDate) 
    {
        free(pDate); 
        pDate = NULL; 
    } 
} 

// =================
#include <stdio.h> 
#include <stdlib.h> 
#include "Date.hpp"  

Date* allocateDateInstance(int day, int month, int year) 
{
    Date* p = NULL; 

    p = (Date*)malloc(sizeof(Date)); 
    if(NULL == p) 
    {
        fprintf(stderr, "allocateDateInstance(): malloc() > failed to allocate memory\n"); 
        exit(EXIT_FAILURE); 
    } 
    p->day = day; 
    p->month = month; 
    p->year = year; 

    return (p); 
}  

int getDay(Date* pDate) 
{
    return (pDate->day); 
} 

int getMonth(Date* pDate) 
{
    return (pDate->month); 
} 

int getYear(Date* pDate) 
{
    return (pDate->year); 
} 

void setDay(Date* pDate, int new_day) 
{
    pDate->day = new_day; 
} 

void setMonth(Date* pDate, int new_month) 
{
    pDate->month = new_month; 
} 

void setYear(Date* pDate, int new_year) 
{
    pDate->year = new_year; 
} 

void show(Date* pDate) 
{
    printf("%d-%d-%d\n", pDate->day, pDate->month, pDate->year); 
} 

void releaseDateInstance(Date* pDate) 
{
    if(pDate) 
    {
        free(pDate); 
        pDate = NULL; 
    } 
} 

// ============= 
#include <stdio.h> 
#include <stdlib.h> 
#include "Date.hpp" 

Date* allocateDateInstance(int day, int month, int year) 
{
    Date* p = NULL; 

    p = (Date*)malloc(sizeof(Date)); 
    if(NULL == p) 
    {
        fprintf(stderr, "allocateDateInstance(): malloc(): error in allocating memory\n"); 
        exit(EXIT_FAILURE); 
    } 

    p->day = day; 
    p->month = month; 
    p->year = year; 

    return (p); 
} 

int getDay(Date* pDate) 
{
    return (pDate->day); 
} 

int getMonth(Date* pDate) 
{
    return (pDate->month); 
} 

int getYear(Date* pDate) 
{
    return (pDate->year); 
} 

void setDay(Date* pDate, int new_day) 
{
    pDate->day = new_day; 
} 

void set_month(Date* pDate, int new_month) 
{
    pDate->month = new_month; 
} 

void set_year(Date* pDate, int new_year) 
{
    pDate->year = new_year; 
} 

void showDate(Date* pDate) 
{
    printf("%d-%d-%d\n", pDate->day, pDate->month, pDate->year); 
} 

void releaseDateInstance(Date* pDate) 
{
    if(pDate) 
    {
        free(pDate); 
        pDate = NULL; 
    } 
} 

