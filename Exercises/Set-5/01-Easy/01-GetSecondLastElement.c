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
    data_t data_elements[] = {10, 20, 30, 40}; 
    data_t data = -1; 

    list = to_list(data_elements, 4); 
    // list = create_list(); 
    // insert_start(list, 10); 
    // insert_start(list, 20); 
    
    show_list(list, "before get_second_last():"); 
    assert(get_second_last(list, &data) == SUCCESS); 
    printf("second last data = %d\n", data); 

    destroy_list(&list); 
} 

void test_2(void) 
{
    list_t* p_list = NULL; 
    data_t data = 0; 

    p_list = create_list(); 
    show_list(p_list, "test_2():"); 
    assert(get_second_last(p_list, &data) == LIST_INSUFFICIENT_ELEMENTS); 
} 

void test_3(void) 
{
    list_t* p_list = NULL; 
    data_t data; 

    p_list = create_list(); 
    insert_start(p_list, 10); 

    assert(get_second_last(p_list, &data) == LIST_INSUFFICIENT_ELEMENTS); 
    show_list(p_list, "test_3(): "); 
} 

