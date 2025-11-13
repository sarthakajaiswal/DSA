#include <stdio.h> // for declaration of printf() 
#include <stdlib.h> // for declaration of malloc(), free() and exit() 
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
    // step1: declare a pointer and initialize it to NULL 
    int* ptr = NULL; 

    // step2: Allocate dynamic memory using malloc() and do the validation check 
    ptr = (int*)malloc(sizeof(int)); 
    if(NULL == ptr) 
    {
        puts("Out of memory"); 
        exit(EXIT_FAILURE); 
    } 

    // step3: initialize allocated instance to 0 
    memset(ptr, 0, sizeof(int)); 

    // step 4-5: Read/Write on dynamically allocated instance 
    *ptr = 100;                     // write operation 
    int n = *ptr;                   // Read Operation 
    printf("*ptr = %d\n", *ptr);    // Read operation 

    // step6: When dynamic instance is no longer wanted, release it and make pointer NULL again 
    free(ptr); 
    ptr = NULL; 
} 

void dynamic_user_defined_date(void) 
{
    // step1: 
    struct Date* newDate = NULL; 

    // step2: 
    newDate = (struct Date*)malloc(sizeof(struct Date)); 
    if(NULL == newDate) 
    {
        puts("Out of memory"); 
        exit(EXIT_FAILURE); 
    } 

    // step3 
    memset(newDate, 0, sizeof(struct Date)); 

    // step 4/5 
    newDate->day = 27; 
    newDate->month = 9; 
    newDate->year = 2025; 

    printf("%d/%d/%d\n", newDate->day, newDate->month, newDate->year); 

    // step6 
    free(newDate); 
    newDate = NULL; 
} 

void dynamic_user_defined_array(void) 
{
    struct array* p_array = NULL; 

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
        p_array->a[i] = (i+1) * 10; 

    puts("Showing array: "); 
    for(i = 0; i < p_array->N; ++i) 
        printf("p_array->a[%d]: %d\n", i, p_array->a[i]); 

    free(p_array->a); 
    p_array->a = NULL; 

    free(p_array); 
    p_array = NULL; 
} 

// ================ 

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

//==== 

int main(void) 
{
    dynamic_builtin(); 
    dynamic_suer_defined_date(); 
    dynamic_user_defined_array(); 

    return (0); 
}

// 1 
int main(void) 
{
    dynamic_builtin(); 
    dynamic_user_defined_date(); 
    dynamic_user_defined_array(); 

    return (0); 
}

// 2 
int main(void) 
{
    dynamic_builtin(); 
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
    dynamci_user_defined_date(); 
    dynamic_user_defined_array(); 

    return (0); 
} 

//====== 
// 1 
void dynamic_buitin(void) 
{
    // step 1 
    int* ptr = NULL; 

    // step 2 
    ptr = (int*)malloc(sizeof(int)); 
    if(NULL == ptr) 
    {
        puts("Out of memory"); 
        exit(EXIT_FAILURE); 
    } 

    // step 3 
    memset(ptr, 0, sizeof(int)); 

    // step4/5 
    *ptr = 100; 
    int n = *ptr; 
    printf("n = %d, *ptr = %d\n", n, *ptr); 

    // step 6 
    free(ptr); 
    ptr = NULL; 
} 

// 2 
void dynamic_builtin(void) 
{
    //step 1 
    int* ptr = NULL; 

    // step2 
    ptr = (int*)malloc(sizeof(int)); 
    if(NULL == ptr) 
    {
        puts("Out of memory"); 
        exit(EXIT_FAILURE); 
    } 

    // step 3 
    memset(ptr, 0, sizeof(int)); 

    // step 4 
    *ptr = 100; 
    int n = *ptr; 
    printf("n = %d *ptr = %d\n", n, *ptr); 

    // step6: 
    free(ptr); 
    ptr = NULL; 
} 

// 3 
void dynamic_builtin(void) 
{
    // step1 
    int* ptr = NULL; 

    // step2: 
    ptr = (int*)malloc(sizeof(int)); 
    if(NULL == ptr) 
    {
        puts("Out of memory"); 
        exit(EXIT_FAILURE); 
    } 

    // step 3 
    memset(ptr, 0, sizeof(int)); 

    // step 4/5 
    *ptr = 100; 
    int n = *ptr; 
    printf("n = %d *ptr = %d\n", n, *ptr); 

    // step6: 
    free(ptr); 
    ptr = NULL; 
} 

// 4 
void dynamic_buitin(void) 
{
    // step 1 
    int* ptr = NULL; 

    // step 2 
    ptr = (int*)malloc(sizeof(int)); 
    if(NULL == ptr) 
    {
        puts("Out of memory"); 
        exit(EXIT_FAILURE); 
    } 

    // step 3 
    memset(ptr, 0, sizeof(int)); 

    // step 4/5 
    *ptr = 100; 
    int n = *ptr; 
    printf("n = %d *ptr = %d\n", n, *ptr); 

    // step6 
    free(ptr); 
    ptr = NULL; 
} 

// 5 
void dynamic_builtin(void) 
{
    // step 1: 
    int* ptr = NULL; 

    // step2: 
    ptr = (int*)malloc(sizeof(int)); 
    if(NULL == ptr) 
    {
        puts("Out of memory"); 
        exit(EXIT_FAILURE); 
    } 

    // step3: 
    memset(ptr, 0, sizeof(int)); 

    // step 4/5 
    *ptr = 100; 
    int n = *ptr; 
    printf("n = %d *ptr = %d\n", n, *ptr); 

    // step 6 
    free(ptr); 
    ptr = NULL; 
} 

//============ 
//1 
void dynaic_user_defined_date(void) 
{
    //step1: 
    struct Date* newDate = NULL; 

    // step2: 
    newDate = (struct Date*)malloc(sizeof(struct Date)); 
    if(NULL == newDate) 
    {
        puts("Out of memory"); 
        exit(EXIT_FAILURE); 
    } 

    // step 3 
    memset(newDate, 0, sizeof(struct Date)); 

    // step 4/5 
    newDate->day = 1; 
    newDate->month = 1; 
    newDate->year = 1970; 

    printf("%d/%d/%d\n", newDate->day, newDate->month, newDate->year); 

    // step 6 
    free(newDate); 
    newDate = NULL; 
} 

// 2 
void dynamic_user_defined_date(void) 
{
    // step 1 
    struct Date* newDate = NULL; 

    // step2 
    newDate = (struct Date*)malloc(sizeof(struct Date)); 
    if(NULL == newDate) 
    {
        puts("Out of memory"); 
        exit(EXIT_FAILURE); 
    } 

    // step 3 
    memset(newDate, 0, sizeof(struct Date)); 

    // step 4/5 
    newDate->day = 10; 
    newDate->month = 12; 
    newDate->year = 2025; 

    printf("%d/%d/%d\n", newDate->day, newDate->month, newDate->year); 

    // step6 
    free(newDate); 
    newDate = NULL; 
} 

// 3 
void dynamic_user_defined_date(void) 
{
    //step1: 
    struct Date* newDate = NULL; 

    // step2: 
    newDate = (struct Date*)malloc(sizeof(struct Date)); 
    if(NULL == newDate) 
    {
        puts("Out of memory"); 
        exit(EXIT_FAILURE); 
    } 

    // step3: 
    memset(newDate, 0, sizeof(struct Date)); 

    // step4/5 
    newDate->day = 1; 
    newDate->month = 1; 
    newDate->year = 1970; 

    printf("%d/%d/%d\n", newDate->day, newDate->month, newDate->year); 

    // step 6: 
    free(newDate); 
    newDate = NULL; 
} 

// 4 
void dynamic_user_defined_date(void) 
{
    // step1: 
    struct Date* newDate = NULL; 

    // step2: 
    newDate = (struct Date*)malloc(sizeof(struct Date)); 
    if(NULL == newDate) 
    {
        puts("Out of memory"); 
        exit(EXIT_FAILURE); 
    } 

    // step3 
    memset(newDate, 0, sizeof(struct Date)); 

    // step 4/5 
    newDate->day = 1; 
    newDate->month = 1; 
    newDate->year = 1970; 

    printf("%d/%d/%d\n", newDate->day, newDate->month, newDate->year); 

    // step 6 
    free(newDate); 
    newDate = NULL; 
} 

// 5 
void dynamic_user_defined_date(void) 
{
    // step 1 
    struct Date* newDate = NULL; 

    // step 2: 
    newDate = (struct Date*)malloc(sizeof(struct Date));
    if(newDate == NULL)
    {
        puts("Out of memory"); 
        exit(EXIT_FAILURE); 
    } 

    // step 3: 
    memset(newDate, 0, sizeof(struct Date)); 
    
    // step 4/5 
    newDate->day = 12; 
    newDate->month = 12; 
    newDate->year= 2025; 

    printf("%d/%d/%d\n", newDate->day, newDate->month, newDate->year); 

    // step6 
    free(newDate); 
    newDate = NULL; 
} 

// ============ 
// 1 
void dynamic_user_defined_array(void) 
{
    struct array* p_array = NULL; 

    p_array = (struct array*)malloc(sizeof(struct array)); 
    if(NULL == p_array) 
    {
        puts("Out of memory"); 
        exit(EXIT_FAILURE); 
    } 

    p_array->N = 5; 
    p_array->a = (int*)malloc(p_array->N * sizeof(int));    
    if(p_array->a == NULL)
    {
        puts("Out of memory"); 
        exit(EXIT_FAILURE); 
    } 

    int i; 
    for(i = 0; i < p_array->N; ++i) 
        p_array->a[i] = (i+1) * 10; 

    puts("Showing array"); 
    for(int i = 0; i < p_array->N; ++i) 
        printf("p_array->a[%d]: %d\n", i, p_array->a[i]); 

    free(p_array->a); 
    p_array->a = NULL; 

    free(p_array); 
    p_array = NULL; 
} 

// 2 
void dynamic_user_defined_array(void) 
{
    struct array* p_array = NULL; 

    p_array = (struct array*)malloc(sizeof(struct array)); 
    if(NULL == p_array) 
    {
        puts("Out of memory"); 
        exit(EXIT_FAILURE); 
    } 

    p_array->N = 10; 
    p_array->a = (int*)malloc(p_array->N * sizeof(int)); 
    if(NULL == p_array->a)
    {
        puts("Out of memory"); 
        exit(EXIT_FAILURE); 
    } 

    int i; 
    for(i = 0; i < p_array->N; ++i) 
        p_array->a[i] = (i+1) * 100; 

    printf("Showing array"); 
    for(i = 0; i < p_array->N; ++i) 
        printf("p_array->a[%d]: %d\n", i, p_array->a[i]); 

    free(p_array->a); 
    p_array->a = NULL; 

    free(p_array); 
    p_array = NULL; 
} 

// 3 
void dynamic_user_defined_array(void) 
{
    struct array* p_array = NULL; 

    p_array = (struct array*)malloc(sizeof(struct array)); 
    if(NULL == p_array) 
    {
        puts("Out of memory"); 
        exit(EXIT_FAILURE); 
    } 

    p_array->N = 5; 
    p_array->a = (int*)malloc(p_array->N * sizeof(int)); 
    if(NULL == p_array->a) 
    {
        puts("Out of memory"); 
        exit(EXIT_FAILURE); 
    } 

    int i; 
    for(i = 0; i < p_array->N; ++i) 
        p_array->a[i] = (i+1) * 10; 

    for(i = 0; i < p_array->N; ++i) 
        printf("p_array->a[%d]: %d\n", i, p_array[i]); 

    free(p_array->a); 
    p_array->a = NULL; 

    free(p_array); 
    p_array = NULL; 
} 

// 4 
void dynamic_user_defined_array(void) 
{
    struct array* p_array = NULL; 

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

    for(i = 0; i < p_array->N; ++i) 
        printf("p_array->a[%d]: %d\n", i, p_array[i]); 

    free(p_array->a); 
    p_array->a = NULL; 

    free(p_array); 
    p_array = NULL; 
} 

// 5 
void dynamic_user_defined_array(void) 
{
    struct array* p_array = NULL; 

    p_array = (struct array*)malloc(sizeof(struct array)); 
    if(NULL == p_array) 
    {
        puts("Out of memory"); 
        exit(EXIT_FAILURE); 
    }

    p_array->N = 7; 
    p_array->a = (int*)malloc(p_array->N * sizeof(int)); 
    if(NULL == p_array->a) 
    {
        puts("Out of memory"); 
        exit(EXIT_FAILURE); 
    } 

    int i; 
    for(i = 0; i < p_array->N; ++i) 
        p_array->a[i] = (i + 1) * 100; 

    for(i = 0; i < p_array->N; ++i) 
        printf("p_array->a[%d]: %d\n", i, p_array->a[i]); 

    free(p_array->a); 
    p_array->a = NULL; 

    free(p_array); 
    p_array = NULL; 
} 


