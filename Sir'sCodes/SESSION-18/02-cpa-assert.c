#include <stdio.h> 
#include <stdlib.h> 
#include <assert.h> 

#define CPA_ASSERT(cond)        if(!(cond))\
                                {\
                                    fprintf(stderr, "assertio failed,"#cond"file:%s, line:%d\n", __FILE__, __LINE__);\
                                    abort();\
                                }


void test_library_assert(void); 
void test_cpa_assert(void); 

int main(void)
{
    test_library_assert(); 
    test_cpa_assert(); 
    return (0); 
}

void test_library_assert(void)
{
    int nr, dr, q; 

    printf("Enter numerator:"); 
    scanf("%d", &nr); 

    printf("Enter denomenator:"); 
    scanf("%d", &dr); 

    assert(dr != 0); 

    q = nr / dr; 

    printf("q = %d\n", q); 
}

void test_cpa_assert(void)
{
    int nr, dr, q; 

    printf("Enter numerator:"); 
    scanf("%d", &nr); 

    printf("Enter denomenator:"); 
    scanf("%d", &dr); 

    CPA_ASSERT(dr != 0); 

    q = nr / dr; 

    printf("q = %d\n", q); 
}