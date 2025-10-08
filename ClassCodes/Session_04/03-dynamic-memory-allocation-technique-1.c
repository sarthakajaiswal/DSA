/*
    @GOAL:      To study dynamic memory allocation using example 
    @DATE:      08 OCT 2025 
    @AUTHOR:    Sarthak A. Jaiswal 
*/

#include <stdio.h> // for declaration of printf() 
#include <stdlib.h> // for declaration of malloc(), free(), exit() 
#include <string.h> // for declaration of memset() 

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
    // (1) Declare a pointer and initialize it to NULL 
    int* ptr = NULL; 

    // code 
    // (2) allocate memory using malloc() and do validation check 
    ptr = (int*)malloc(sizeof(int)); 
    if(ptr == NULL) 
    {
        puts("Out of memory"); 
        exit(EXIT_FAILURE); 
    }     

    // (3) Initialise allocated instance to 0 
    memset((void*)ptr, 0, sizeof(int)); 

    // (4-5) Read/write on dynamically allocated instance 
    *ptr = 100;         // write operation 
    int n = *ptr;       // read operation 
    printf("n = %d\n", n); 

    // (6) when dynamic instance is no longer wanted release it and make pointer NULL again 
    free(ptr); 
    ptr = NULL; 
} 

void dynamic_user_defined_date(void) 
{
    // code 
} 

void dynamic_user_defined_array(void) 
{
    // code 
} 
