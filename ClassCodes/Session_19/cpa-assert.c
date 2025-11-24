/*
    @GOAL: to implement our assert macro 
    @DATE: 23 Nov 2025 
    @AUTHOR: Sarthak A. Jaiswal 
*/

#include <stdio.h> 
#include <stdlib.h> 
#include <assert.h> 

#define MY_ASSERT(cond)    if(!(cond)) \
                                {\
                                    fprintf(stderr, "assertion failed: "#cond", file %s, line %d\n", __FILE__, __LINE__); \
                                    abort(); \
                                }

void test_library_assert(void); 
void test_my_assert(void); 

int main(void) 
{
    test_library_assert(); 
    test_my_assert(); 
    return (0); 
} 

void test_library_assert(void) 
{
    int nr, dr, q; 

    printf("Enter numerator: "); 
    scanf("%d", &nr); 

    printf("Enter denominator: "); 
    scanf("%d", &dr); 

    assert(dr != 0); 

    q = nr/dr; 

    printf("q = %d\n", q); 
} 

void test_my_assert(void) 
{
    int nr, dr, q; 

    printf("Enter numerator: "); 
    scanf("%d", &nr); 

    printf("Enter denominator: ");
    scanf("%d", &dr); 

    MY_ASSERT(dr != 0); 

    q = nr/dr; 

    printf("q = %d\n", q); 
} 

