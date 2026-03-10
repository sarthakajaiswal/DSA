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
    list_t* p_list1 = NULL; 
    list_t* p_list2 = NULL; 
    data_t data_elements1[] = {10, 20, 30, 40}; 
    data_t data_elements2[] = {100, 200, 300, 400}; 

    puts("In test1():"); 

    p_list1 = to_list(data_elements1, sizeof(data_elements1)/sizeof(data_elements1[0])); 
    p_list2 = to_list(data_elements2, sizeof(data_elements2)/sizeof(data_elements2[0])); 
    
    show_list(p_list1, "list1 before interleave_lists():"); 
    show_list(p_list2, "list2 before interleave_lists():"); 
    
    interleave_lists(p_list1, &p_list2); 
    assert(p_list2 == NULL); 

    show_list(p_list1, "list1 after interleave_lists():"); 

    destroy_list(&p_list1); 
} 

void test_2(void) 
{
    list_t* p_list1 = NULL; 
    list_t* p_list2 = NULL; 
    data_t data_elements1[] = {10, 20, 30, 40}; 
    data_t data_elements2[] = {100}; 

    puts("In test2():"); 

    p_list1 = to_list(data_elements1, sizeof(data_elements1)/sizeof(data_elements1[0])); 
    p_list2 = to_list(data_elements2, sizeof(data_elements2)/sizeof(data_elements2[0])); 
    
    show_list(p_list1, "list1 before interleave_lists():"); 
    show_list(p_list2, "list2 before interleave_lists():"); 
    
    interleave_lists(p_list1, &p_list2); 
    assert(p_list2 == NULL); 

    show_list(p_list1, "list1 after interleave_lists():"); 

    destroy_list(&p_list1); 
} 

void test_3(void) 
{
    list_t* p_list1 = NULL; 
    list_t* p_list2 = NULL; 
    data_t data_elements1[] = {10}; 
    data_t data_elements2[] = {100, 200, 300, 400}; 

    puts("In test3():"); 

    p_list1 = to_list(data_elements1, sizeof(data_elements1)/sizeof(data_elements1[0])); 
    p_list2 = to_list(data_elements2, sizeof(data_elements2)/sizeof(data_elements2[0])); 
    
    show_list(p_list1, "list1 before interleave_lists():"); 
    show_list(p_list2, "list2 before interleave_lists():"); 
    
    interleave_lists(p_list1, &p_list2); 
    assert(p_list2 == NULL); 

    show_list(p_list1, "list1 after interleave_lists():"); 

    destroy_list(&p_list1); 
} 

void test_4(void) 
{
    list_t* p_list1 = NULL; 
    list_t* p_list2 = NULL; 
    
    puts("In test4():"); 

    p_list1 = create_list(); 
    p_list2 = create_list(); 
    
    show_list(p_list1, "list1 before interleave_lists():"); 
    show_list(p_list2, "list2 before interleave_lists():"); 
    
    interleave_lists(p_list1, &p_list2); 
    assert(p_list2 == NULL); 

    show_list(p_list1, "list1 after interleave_lists():"); 

    destroy_list(&p_list1); 
} 

