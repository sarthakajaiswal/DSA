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
    assert(check_if_sum_of_first_and_last_equals_target(list, 50) == TRUE); 
    assert(check_if_sum_of_first_and_last_equals_target(list, 0) == FALSE); 
    destroy_list(&list); 

    puts("test1 successfull"); 
} 

void test_2(void) 
{
    list_t* p_list = NULL; 
    data_t data = 0; 

    p_list = create_list(); 
    assert(check_if_sum_of_first_and_last_equals_target(p_list, 0) == TRUE); 
    assert(check_if_sum_of_first_and_last_equals_target(p_list, 1) == FALSE); 
    destroy_list(&p_list); 

    puts("test2 successfull"); 
} 

void test_3(void) 
{
    list_t* p_list = NULL; 
    data_t data; 

    p_list = create_list(); 
    insert_start(p_list, 10); 
    assert(check_if_sum_of_first_and_last_equals_target(p_list, 20) == TRUE); 
    assert(check_if_sum_of_first_and_last_equals_target(p_list, 0) == FALSE); 
    destroy_list(&p_list); 

    puts("test3 successfull"); 
} 

