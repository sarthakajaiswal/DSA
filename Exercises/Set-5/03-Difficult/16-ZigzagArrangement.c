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

    show_list(p_list, "Before zigzag_arragement(): "); 
    zigzag_arrangement(p_list); 
    show_list(p_list, "After zigzag_arragement(): "); 
    
    destroy_list(&p_list); 
} 

void test_2(void) 
{
    list_t* p_list = NULL; 
    data_t data_elements1[] = {1, 2, 4, 5, 7}; 

    puts("In test2():"); 
    p_list = to_list(data_elements1, sizeof(data_elements1)/sizeof(data_elements1[0])); 

    show_list(p_list, "Before zigzag_arragement(): "); 
    zigzag_arrangement(p_list); 
    show_list(p_list, "After zigzag_arragement(): "); 
    
    destroy_list(&p_list); 
} 

void test_3(void) 
{
    list_t* p_list = NULL; 
    data_t data_elements1[] = {1, 2}; 

    puts("In test3():"); 
    p_list = to_list(data_elements1, sizeof(data_elements1)/sizeof(data_elements1[0])); 

    show_list(p_list, "Before zigzag_arragement(): "); 
    zigzag_arrangement(p_list); 
    show_list(p_list, "After zigzag_arragement(): "); 
    
    destroy_list(&p_list); 
} 

void test_4(void) 
{
    list_t* p_list = NULL; 
    data_t data_elements1[] = {1}; 

    puts("In test4():"); 
    p_list = to_list(data_elements1, sizeof(data_elements1)/sizeof(data_elements1[0])); 

    show_list(p_list, "Before zigzag_arragement(): "); 
    zigzag_arrangement(p_list); 
    show_list(p_list, "After zigzag_arragement(): "); 
    
    destroy_list(&p_list); 
} 

void test_5(void) 
{
    list_t* p_list = NULL; 

    puts("In test5():"); 
    p_list = create_list(); 

    show_list(p_list, "Before zigzag_arragement(): "); 
    zigzag_arrangement(p_list); 
    show_list(p_list, "After zigzag_arragement(): "); 
    
    destroy_list(&p_list); 
} 

