#include "../dcll.h" 

void test_1(void); 
void test_2(void); 
void test_3(void); 
void test_4(void); 

int main(void) 
{
    test_1(); 
    test_2(); 
    test_3(); 
    test_4(); 

    puts("Testing completed succesfully"); 

    return (0); 
} 

void test_1(void) 
{
    list_t* p_list = NULL; 
    data_t data_elements1[] = {10, 20, 20, 10}; 

    puts("In test1():"); 
    p_list = to_list(data_elements1, sizeof(data_elements1)/sizeof(data_elements1[0])); 
    show_list(p_list, "list1():"); 
    
    if(is_list_symmetric(p_list) == TRUE) 
        fprintf(stderr, "List is symmetric\n"); 
    else 
        fprintf(stderr, "List is unsymmetric\n"); 
    
    destroy_list(&p_list); 
} 

void test_2(void) 
{
    list_t* p_list = NULL; 
    data_t data_elements1[] = {10, 20, 30, 20, 10}; 

    puts("In test2():"); 
    p_list = to_list(data_elements1, sizeof(data_elements1)/sizeof(data_elements1[0])); 
    show_list(p_list, "list1():"); 
    
    if(is_list_symmetric(p_list) == TRUE) 
        fprintf(stderr, "List is symmetric\n"); 
    else 
        fprintf(stderr, "List is unsymmetric\n"); 
    
    destroy_list(&p_list); 
} 

void test_3(void) 
{
    list_t* p_list = NULL;  
    data_t data_elements1[] = {0, 20, 30, 40}; 

    puts("In test3():"); 
    p_list = to_list(data_elements1, sizeof(data_elements1)/sizeof(data_elements1[0])); 
    show_list(p_list, "list1():"); 
    
    if(is_list_symmetric(p_list) == TRUE) 
        fprintf(stderr, "List is symmetric\n"); 
    else 
        fprintf(stderr, "List is unsymmetric\n"); 
    
    destroy_list(&p_list); 
} 

void test_4(void) 
{
    list_t* p_list = NULL;  

    puts("In test4():"); 
    p_list = create_list(); 
    show_list(p_list, "list1():"); 
    
    if(is_list_symmetric(p_list) == TRUE) 
        fprintf(stderr, "List is symmetric\n"); 
    else 
        fprintf(stderr, "List is unsymmetric\n"); 
    
    destroy_list(&p_list); 
} 

