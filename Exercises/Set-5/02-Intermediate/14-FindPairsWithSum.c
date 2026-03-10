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
    data_t data_elements1[] = {1, 2, 4, 5, 7, 8}; 

    puts("In test1():"); 
    p_list = to_list(data_elements1, sizeof(data_elements1)/sizeof(data_elements1[0])); 
    show_list(p_list, "list1():"); 
    
    find_pairs_with_sum(p_list, 9); 
    
    destroy_list(&p_list); 
} 

void test_2(void) 
{
    list_t* p_list = NULL; 
    data_t data_elements1[] = {1, 2, 4, 5, 7, 8}; 

    puts("In test2():"); 
    p_list = to_list(data_elements1, sizeof(data_elements1)/sizeof(data_elements1[0])); 
    show_list(p_list, "list1():"); 
    
    find_pairs_with_sum(p_list, 10); 
    
    destroy_list(&p_list); 
} 

void test_3(void) 
{
    list_t* p_list = NULL; 
    data_t data_elements1[] = {1, 2, 4, 5, 4, 8}; 

    puts("In test3():"); 
    p_list = to_list(data_elements1, sizeof(data_elements1)/sizeof(data_elements1[0])); 
    show_list(p_list, "list1():"); 
    
    find_pairs_with_sum(p_list, 9); 
    
    destroy_list(&p_list); 
} 

void test_4(void) 
{
    list_t* p_list = NULL; 
    data_t data_elements1[] = {1, 2, 5, 3, 4}; 

    puts("In test4():"); 
    p_list = to_list(data_elements1, sizeof(data_elements1)/sizeof(data_elements1[0])); 
    show_list(p_list, "list1():"); 
    
    find_pairs_with_sum(p_list, 5); 
    
    destroy_list(&p_list); 
} 

