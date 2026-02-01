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
    myDate.day = 1; 
    myDate.month = 1; 
    myDate.year = 1970; 
    test(); 
    return (0); 
} 

void test(void) 
{
    struct Date* pDate = (struct Date*)malloc(sizeof(struct Date)); 
    if(NULL == pDate) 
    {
        fprintf(stderr, "test():malloc(): failure in memory allocation\n"); 
        exit(EXIT_FAILURE); 
    } 

    pDate->day = 1; 
    pDate->month = 1; 
    pDate->year = 1970; 

    free(pDate); 
    pDate = NULL; 
} 

void testDate() 
{
    struct Date D; 
    struct Date* myDate = allocateDate(25, 1, 2026); 
    myDate->day = 28; 
} 

// ================ 
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
    myDate.day = 1; 
    myDate.month = 1; 
    myDate.year = 1970; 
    test(); 
    return (0); 
} 

void test(void) 
{
    struct Date* pDate = NULL; 

    pDate = (struct Date*)malloc(sizeof(struct Date)); 
    if(NULL == pDate) 
    {
        fprintf(stderr, "test():malloc(): failed to allocate memory\n"); 
        exit(EXIT_FAILURE); 
    } 

    pDate->day = 10; 
    pDate->month = 2; 
    pDate->year = 2025; 

    free(pDate); 
    pDate = NULL; 
} 

void testDate(void) 
{
    struct Date D; 
    struct Date* date = allocateDate(25, 1, 2025); 
    date->day = 28; 
} 

// ============ 
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
    struct Date today; 
    today.day = 1; 
    today.month = 1; 
    today.year = 1970; 
    test(); 
    return (0); 
} 

void test(void) 
{
    struct Date* p = NULL; 
    p = (struct Date*)malloc(sizeof(struct Date)); 
    if(NULL == p) 
    {
        fprintf(stderr, "test():malloc() > failed to allocate memory\n"); 
        exit(EXIT_FAILURE); 
    } 

    p->day = 1; 
    p->month = 1; 
    p->year = 1970; 

    free(p); 
    p = NULL; 
} 

//============= 
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
    struct Date d; 
    d.day = 1; 
    d.month = 1; 
    d.year = 1970; 
    test(); 
    return (0); 
} 

void test(void) 
{
    struct Date* p = NULL;
    p = (struct Date*)malloc(sizeof(struct Date)); 
    if(NULL == p) 
    {
        fprintf(stderr, "test():malloc() > memory allocation failed\n"); 
        exit(EXIT_FAILURE); 
    } 

    p->day = 1; 
    p->month = 1; 
    p->year = 1970; 

    free(p); 
    p = NULL; 
} 

// =========== 
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
    struct Date d = {1, 1, 1970}; 
    d.day = 1; 
    d.month = 10; 
    d.year = 2010; 
    test(); 
    return (0); 
} 

void test(void) 
{
    struct Date* p = NULL; 
    p = (struct Date*)malloc(sizeof(struct Date)); 
    if(NULL == p) 
    {
        fprintf(stderr, "test():malloc() > memory allocation failure\n"); 
        exit(EXIT_FAILURE); 
    } 

    p->day = 10; 
    p->month = 1; 
    p->year = 2026; 

    free(p); 
    p = NULL; 
} 
