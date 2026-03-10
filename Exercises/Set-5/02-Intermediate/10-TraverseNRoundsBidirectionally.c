#include "../dcll.h" 

void test_1(void); 
void test_2(void); 
void test_3(void); 

int main(void) 
{
    test_1(); 
    test_2(); 
    test_3(); 

    puts("Testing completed succesfully"); 

    return (0); 
} 

void test_1(void) 
{
    list_t* list = NULL; 
    data_t data_elements[] = {10, 20, 30, 40}; 

    puts("In test1():"); 

    list = to_list(data_elements, sizeof(data_elements)/sizeof(data_elements[0])); 
    traverse_n_rounds_alternate(list, 4); 

    destroy_list(&list); 
} 

void test_2(void) 
{
    list_t* p_list = NULL; 
    data_t data = 0; 

    puts("In test2():"); 

    p_list = create_list(); 
    traverse_n_rounds_alternate(p_list, 2); 
    
    destroy_list(&p_list); 
} 

void test_3(void) 
{
    list_t* p_list = NULL; 
    data_t data; 

    puts("In test3():"); 

    p_list = create_list(); 
    insert_start(p_list, 10); 
    traverse_n_rounds_alternate(p_list, 0); 

    destroy_list(&p_list); 
} 


