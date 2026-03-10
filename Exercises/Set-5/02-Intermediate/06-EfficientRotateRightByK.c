#include "../dcll.h" 

void test_1(void); 
void test_2(void); 
void test_3(void); 

int main(void) 
{
    test_1(); 
    test_2(); 
    test_3(); 

    return (0); 
} 

void test_1(void) 
{
    list_t* list = NULL; 
    data_t data_elements[] = {10, 20, 30, 40, 50}; 
    data_t data = -1; 

    list = to_list(data_elements, sizeof(data_elements)/sizeof(data_elements[0])); 
    show_list(list, "test1() > Before rotate_right_by_k():"); 
    rotate_right_by_k(list, 3); 
    show_list(list, "test1() > After rotate_right_by_k(p_list, 3):"); 

    destroy_list(&list); 
} 

void test_2(void) 
{
    list_t* p_list = NULL; 
    data_t data = 0; 

    p_list = create_list(); 
    show_list(p_list, "test_2():"); 
    assert(rotate_right_by_k(p_list, 3) == LIST_INSUFFICIENT_ELEMENTS); 
    puts("test2() > assertion in test2() true"); 

    destroy_list(&p_list); 
} 

void test_3(void) 
{
    list_t* p_list = NULL; 
    data_t data; 

    p_list = create_list(); 
    insert_start(p_list, 10); 
    show_list(p_list, "test_3() > Before rotate_right_by_k(): "); 
    rotate_right_by_k(p_list, 1); 
    show_list(p_list, "test3() > After rotate_right_by_k(p_list, 1):"); 

    assert(rotate_right_by_k(p_list, 2) == LIST_INSUFFICIENT_ELEMENTS); 

    destroy_list(&p_list); 
} 

