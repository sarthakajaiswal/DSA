/*
    @GOAL:      To study dynamic memory allocation using example 
    @DATE:      08 OCT 2025 
    @AUTHOR:    Sarthak A. Jaiswal 
*/

#include <stdio.h> // for declaration of printf() 
#include <stdlib.h> // for declaration ofmalloc(), free(), exit() 
#include <string.h> // for declaration of memset() 

// structure definitions 
struct Date 
{
    int day; 
    int month; 
    int year; 
}; 

struct array
{
    int* a; 
    int N; 
}; 

int main(void) 
{
    // function prototypes 
    void dynamic_builtin(void); 
    void dynamic_user_defined_date(void); 
    void dynamic_user_defined_array(void); 

    // code 
    dynamic_builtin(); 
    dynamic_user_defined_date(); 
    dynamic_user_defined_array(); 

    return (0); 
} 

void dynamic_builtin(void) 
{
    // variable declarations 
    // (1) declare an pointer and initialize it to NULL 
    int* ptr = NULL; 

    // code 
    // (2) allocate memory using malloc() and do validation check 
    ptr = (int*)malloc(sizeof(int)); 
    if(NULL == ptr) 
    {
        puts("Out of memory"); 
        exit(EXIT_FAILURE); 
    } 

    // (3) initialize the allocated instance to 0 
    memset((void*)ptr, 0, sizeof(int)); 

    // (3-4) Read/Write on dynamically allocated instance 
    *ptr = 100;     // write operation 
    int n = *ptr;   // read operation 
    printf("n = %d\n", n); 

    // (6) when dynamic instance is no longer wanted release it and make pointer NULL 
    free(ptr); 
    ptr = NULL; 
}

void dynamic_user_defined_date(void) 
{
    // variable declarations 
    struct Date* newDate = NULL; // (1) 
    
    // code
    // (2) 
    newDate = (struct Date*)malloc(sizeof(struct Date)); 
    if(newDate == NULL) 
    {
        printf("Out of memory\n"); 
        exit(EXIT_FAILURE); 
    } 

    memset((void*)newDate, 0, sizeof(struct Date)); // (3) 

    // (4/5) 
    newDate->day = 27;  // (*newDate).day = 27 
    newDate->month = 9; // (*newDate).month = 9 
    newDate->year = 2025; // (*newDate).year = 2025 

    printf("%d/%d/%d\n", newDate->day, newDate->month, newDate->year); 

    // (6) 
    free(newDate); 
    newDate = NULL; 
} 

void dynamic_user_defined_array(void) 
{
    // variable declarations 
    struct array* p_array = NULL; 

    // code 
    p_array = (struct array*)malloc(sizeof(struct array)); 
    if(NULL == p_array) 
    {
        puts("Out of memory"); 
        exit(EXIT_FAILURE); 
    } 

    p_array->N = 8; 
    p_array->a = (int*)malloc(p_array->N * sizeof(int)); 
    if(NULL == p_array->a) 
    {
        puts("Out of memory"); 
        exit(EXIT_FAILURE); 
    } 

    int i; 
    for(i = 0; i < p_array->N; ++i) 
        p_array->a[i] = (i + 1) * 10; 

    puts("Showing array:"); 
    for(i = 0; i < p_array->N; ++i) 
        printf("p_array->a[%d]: %d\n", i, p_array->a[i]); 

    free(p_array->a); 
    p_array->a = NULL; 

    free(p_array); 
    p_array = NULL; 
} 

