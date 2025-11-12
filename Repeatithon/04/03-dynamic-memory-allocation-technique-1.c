#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 

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

void dynamic_builtin(void); 
void dynamic_user_defined_date(void); 
void dynamic_user_defined_array(void); 

int main(void) 
{
    dynamic_builtin(); 
    dynamic_user_defined_date(); 
    dynamic_user_defined_array(); 

    return (0); 
} 

void dynamic_builtin(void) 
{
    // step1: Declare a pointer and initialize to NULL 
    int* ptr = NULL; 

    // ste2: Allocate dynamic memory using malloc() and do the validation check 
    ptr = (int*)malloc(sizeof(int)); 
    if(NULL == ptr) 
    {
        puts("Out of memory"); 
        exit(EXIT_FAILURE); 
    } 

    // step3: initialize allocated memory 
    memset(ptr, 0, sizeof(int)); 

    // step4-5: Read/write on dynamically allocated instance 
    *ptr = 100; 
    int n = *ptr; 
    printf("*ptr = %d\n", *ptr); 

    // step 6: When dynamic instance is no longer wanted, release it and make pointer NULL again 
    free(ptr); 
    ptr = NULL; 
}

void dynamic_user_defined_date(void) 
{
} 

void dynamic_user_defined_array(void) 
{
}

//============ 
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 

#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 

#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 

#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 

#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 

#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 

struct Date 
{
    int day; 
    int month; 
    int year; 
}; 

struct Date 
{
    int day; 
    int month; 
    int year; 
}; 

struct Date 
{
    int day; 
    int month; 
    int year; 
}; 

struct Date 
{
    int day; 
    int month; 
    int year; 
}; 

struct Date 
{
    int day; 
    int month; 
    int year; 
}; 

struct array
{
    int* a; 
    int size; 
}; 

struct array 
{
    int* a; 
    int N; 
}; 

struct array 
{
    int* a; 
    int N; 
}; 

struct array 
{
    int* a; 
    int N; 
}; 

struct array 
{
    int* a; 
    int N; 
}; 

void dynamic_builtin(void); 
void dynamic_user_defined_date(void); 
void dynamic_user_defined_array(void); 

void dynamic_builtin(void); 
void dynamic_user_defined_date(void); 
void dynamic_user_defined_array(void); 

void dynamic_builtin(void); 
void dynamic_user_defined_date(void); 
void dynamic_user_defined_array(void); 

void dynamic_builtin(void); 
void dynamic_user_defined_date(void); 
void dynamic_user_defined_array(void); 

void dynamic_builtin(void); 
void dynamic_user_defined_date(void); 
void dynamic_user_defined_array(void); 

void dynamic_builtin(void); 
void dynamic_user_defined_date(void); 
void dynamic_user_defined_array(void); 

// =========== 
// 1 
int main(void) 
{
    dynamic_builtin(); 
    dynamic_user_defined_date(); 
    dynamic_use_defined_array(); 

    return (0); 
} 

// 2
int main(void) 
{
    dynamic_buitin(); 
    dynamic_user_defined_date(); 
    dynamic_user_defined_array(); 

    return (0); 
} 

// 3 
int main(void) 
{
    dynamic_builtin(); 
    dynamic_user_defined_date(); 
    dynamic_user_defined_array(); 

    return (0); 
} 

// 4
int main(void) 
{
    dynamic_builtin(); 
    dynamic_user_defined_date(); 
    dynamic_user_defined_array(); 

    return (0); 
} 

// 5 
int main(void) 
{
    dynamic_builtin(); 
    dynamic_user_defined_date(); 
    dynamic_user_defined_array(); 

    return (0); 
} 

// ============= 
void dynamic_builtin(void) 
{
    int* ptr = NULL; 

    ptr = (int*)malloc(sizeof(int)); 
    if(NULL == ptr) 
    {
        puts("Out of memory"); 
        exit(EXIT_FAILURE); 
    } 

    memset(ptr, 0, sizeof(int)); 

    *ptr = 100; 
    int n = *ptr; 
    printf("*ptr = %d\n", *ptr); 

    free(ptr); 
    ptr = NULL; 
} 

void dynamic_builtin(void) 
{
    int* ptr = NULL; 

    ptr = (int*)malloc(sizeof(int)); 
    if(NULL == ptr) 
    {
        puts("Out of memory"); 
        exit(EXIT_FAILURE); 
    } 

    memset(ptr, 0, sizeof(int)); 

    *ptr = 100; 
    int n = *ptr; 
    printf("*ptr = %d\n", *ptr); 

    free(ptr); 
    ptr = NULL; 
} 

void dynamic_builtin(void) 
{
    int* ptr = NULL; 

    ptr = (int*)malloc(sizeof(int)); 
    if(NULL == ptr) 
    {
        puts("Out of memory"); 
        exit(EXIT_FAILURE); 
    } 

    memset(ptr, 0, sizeof(int)); 

    *ptr = 100; 
    int n = *ptr; 
    printf("*ptr = %d\n", *ptr); 

    free(ptr); 
    ptr = NULL; 
} 

void dynamic_builtin(void) 
{
    int* ptr = NULL; 

    ptr = (int*)malloc(sizeof(int)); 
    if(NULL == ptr) 
    {
        puts("Out of memory"); 
        exit(EXIT_FAILURE); 
    } 

    memset(ptr, 0, sizeof(ptr)); 

    *ptr = 100; 
    int n = *ptr; 
    printf("*ptr = %d\n", *ptr); 

    free(ptr); 
    ptr = NULL; 
} 

void dynamic_builtin(void) 
{
    int* ptr = NULL; 

    ptr = (int*)malloc(sizeof(int)); 
    if(NULL == ptr) 
    {
        puts("Out of memory"); 
        exit(EXIT_FAILURE); 
    } 

    memset(ptr, 0, sizeof(int)); 

    *ptr = 100; 
    int n = *ptr; 
    printf("ptr = %d\n", *ptr); 

    free(ptr); 
    ptr = NULL; 
} 

