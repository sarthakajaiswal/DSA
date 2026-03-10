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
    list_t* list1 = NULL; 
    list_t* list2 = NULL; 
    data_t data_elements[] = {10, 20, 30, 40}; 

    puts("In test1():"); 

    list1 = to_list(data_elements, sizeof(data_elements)/sizeof(data_elements[0])); 
    show_list(list1, "list1 before split_into_halves():"); 
    list2 = split_into_halves(list1); 
    show_list(list1, "list1 after split_into_halves():"); 
    show_list(list2, "list2 after split_into_halves():"); 

    destroy_list(&list1); 
    destroy_list(&list2); 
} 

void test_2(void) 
{
    list_t* p_list1 = NULL; 
    list_t* p_list2 = NULL; 
    data_t data_elements[] = {10, 20, 30, 40, 50}; 

    puts("In test2():"); 

    p_list1 = to_list(data_elements, sizeof(data_elements)/sizeof(data_elements[0])); 
    show_list(p_list1, "list1 before split_into_halves():"); 
    p_list2 = split_into_halves(p_list1); 
    show_list(p_list1, "list1 after split_into_halves():"); 
    show_list(p_list2, "list2 after split_into_halves():"); 

    destroy_list(&p_list1); 
    destroy_list(&p_list2); 
} 

void test_3(void) 
{
    list_t* p_list1 = NULL; 
    list_t* p_list2 = NULL; 

    puts("In test3():"); 

    p_list1 = create_list(); 
    insert_start(p_list1, 100); 

    show_list(p_list1, "list1 before split_into_halves():"); 
    p_list2 = split_into_halves(p_list1); 
    show_list(p_list1, "list1 after split_into_halves():"); 
    show_list(p_list2, "list2 after split_into_halves():"); 

    destroy_list(&p_list1); 
    destroy_list(&p_list2); 
} 

void test_4(void) 
{
    list_t* p_list1 = NULL; 
    list_t* p_list2 = NULL; 

    puts("In test4():"); 

    p_list1 = create_list();  

    show_list(p_list1, "list1 before split_into_halves():"); 
    p_list2 = split_into_halves(p_list1); 
    assert(p_list2 == NULL); 
    show_list(p_list1, "list1 after split_into_halves():");

    destroy_list(&p_list1); 
} 

