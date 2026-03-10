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

    list = to_list(data_elements, sizeof(data_elements)/sizeof(data_elements[0])); 
    show_list(list, "test1() > Before delete_second_last():"); 
    delete_second_last(list); 
    show_list(list, "test1() > After delete_second_last(list):"); 

    destroy_list(&list); 
} 

void test_2(void) 
{
    list_t* p_list = NULL; 
    data_t data = 0; 

    p_list = create_list(); 
    show_list(p_list, "test_2():"); 
    assert(delete_second_last(p_list) == LIST_EMPTY); 
    puts("test2() > assertion in test2() true"); 

    destroy_list(&p_list); 
} 

void test_3(void) 
{
    list_t* p_list = NULL; 
    data_t data; 

    p_list = create_list(); 
    insert_start(p_list, 10); 

    show_list(p_list, "test_3() > Before delete_second_last(): "); 
    assert(delete_second_last(p_list) == LIST_INSUFFICIENT_ELEMENTS); 
    puts("test3() > assertion in test3() true"); 

    destroy_list(&p_list); 
} 


