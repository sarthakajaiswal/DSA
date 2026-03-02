#include <stdio.h> 
#include <assert.h> 
#include <time.h> 

// #include "03-DoublyLinkedList\dll.h" 
#include "04-DoublyCircularLinkedList\dcll.h" 

#define NR_ELEMENTS_LIST1   50000
#define NR_ELEMENTS_LIST2   100000  

int main(int argc, char* argv) 
{
    void test(void); 
    void test_on_more_data(void); 

    test(); 
    // test_on_more_data(); 

    fprintf(stdout, "---- list testing completed successfully ----\n"); 
    
    return (0); 
} 

void test(void) 
{
    list_t* p_list = NULL; 
    data_t start_data, end_data, data; 
    len_t length; 
    status_t status; 

    // create_list() 
    p_list = create_list(); 
    printf("Testing assertions on list just after creation:\n"); 
    assert(p_list != NULL); 
    assert(get_start(p_list, &start_data) == LIST_EMPTY); 
    assert(get_end(p_list, &end_data) == LIST_EMPTY); 
    assert(pop_start(p_list, &start_data) == LIST_EMPTY); 
    assert(pop_end(p_list, &end_data) == LIST_EMPTY); 
    assert(remove_start(p_list) == LIST_EMPTY); 
    assert(remove_end(p_list) == LIST_EMPTY); 
    assert(get_list_length(p_list) == 0); 
    printf("Assertions on empty list successfull\n"); 

    show_list(p_list, "After creation: "); 

    puts("-------------------------"); 

    // data insertion 
    for(data = 0; data < 5; ++data) 
        assert(insert_start(p_list, data) == SUCCESS); 
    show_list(p_list, "After insert_start(): "); 

    for(data = 5; data < 10; ++data) 
        assert(insert_end(p_list, data) == SUCCESS); 
    show_list(p_list, "After insert_end(): "); 

    assert(
        insert_after(p_list, -10, 100) == 
        LIST_DATA_NOT_FOUND
    ); 

    assert(
        insert_before(p_list, 300, 200) == 
        LIST_DATA_NOT_FOUND
    ); 

    assert(insert_after(p_list, 0, 100) == SUCCESS); 
    show_list(p_list, "After insert_after(): "); 
    assert(insert_before(p_list, 0, 200) == SUCCESS); 
    show_list(p_list, "After insert_before(): "); 

    puts("----------------------------"); 

    // get_list_length() 
    assert(get_list_length(p_list) > 0); 
    data = -1; 
    assert(get_start(p_list, &data) == SUCCESS); 
    printf("Start data = %d\n", data); 
    show_list(p_list, "After get_start():"); 

    puts("----------------------------");  

    // get() and pop() 
    data = -1; 
    assert(get_end(p_list, &data) == SUCCESS); 
    printf("end data: %d\n", data); 
    show_list(p_list, "After get_end():"); 

    data = -1; 
    assert(pop_start(p_list, &data) == SUCCESS); 
    printf("start data = %d\n", data); 
    show_list(p_list, "After pop_start():"); 

    data = -1; 
    assert(pop_end(p_list, &data) == SUCCESS); 
    printf("end data = %d\n", data); 
    show_list(p_list, "After pop_end():"); 

    puts("----------------------------"); 

    // data removal 
    assert(remove_start(p_list) == SUCCESS); 
    show_list(p_list, "after remove_start():"); 

    assert(remove_end(p_list) == SUCCESS); 
    show_list(p_list, "after remove_end(): "); 

    assert(remove_data(p_list, 23) == LIST_DATA_NOT_FOUND); 
    assert(remove_data(p_list, 0) == SUCCESS); 
    show_list(p_list, "after remove_data():"); 

    printf("Length = %llu\n", get_list_length(p_list)); 

    puts("----------------------------"); 

    // find() & is_empty() 
    assert(is_list_empty(p_list) == FALSE); 

    assert(find_in_list(p_list, -10) == FALSE);  
    assert(find_in_list(p_list, 100) == TRUE); 
    puts("assertions true\n"); 

    puts("----------------------------"); 

    // to list and to array 
    data_t arr[] = {5, 10, 15, 20, 25}; 
    destroy_list(&p_list); 

    p_list = to_list(arr, 5);   
    show_list(p_list, "list from to_list(): "); 

    size_t N = -1; 
    data_t* p_arr = NULL; 
    
    p_arr = to_array(p_list, &N); 
    for(int i = 0; i < N; ++i) 
        printf("p_arr[%d] = %d\n", i, p_arr[i]); 

    puts("----------------------------"); 

    // reversal 
    list_t* reversed_list = NULL; 
    
    assert(clear_list(p_list) == SUCCESS); 
    assert(get_list_length(p_list) == 0); 
    show_list(p_list, "p_list :"); 
    reversed_list = get_reversed_list(p_list); 
    show_list(reversed_list, "reversed_list: "); 
    assert(destroy_list(&reversed_list) == SUCCESS); 

    for(int i = 0; i < 10; ++i) 
        insert_end(p_list, i); 
    show_list(p_list, "p_list: "); 
    reversed_list = get_reversed_list(p_list); 
    show_list(reversed_list, "reversed_list: "); 
    assert(destroy_list(&reversed_list) == SUCCESS); 

    show_list(p_list, "p_list: "); 
    reverse_list(p_list); 
    show_list(p_list, "p_reversed_list: "); 

    puts("----------------------------"); 
    // ---------------- 

    // concatenation 
    list_t* p_list_1 = NULL; 
    list_t* p_list_2 = NULL; 
    list_t* concated_list = NULL; 
    
    p_list_1 = create_list(); 
    p_list_2 = create_list(); 

    concated_list = get_concated_list(p_list_1, p_list_2); 
    assert(get_list_length(concated_list) == 0); 

    for(int i = 0; i < 100; i += 10) 
        assert(insert_end(p_list_1, i) == SUCCESS); 
    for(int i = 0; i < 50; i += 5) 
        assert(insert_start(p_list_2, i) == SUCCESS); 

    show_list(p_list_1, "p_list_1: "); 
    show_list(p_list_2, "p_list_2: "); 

    concated_list = get_concated_list(p_list_1, p_list_2); 
    show_list(concated_list, "concated_list: "); 

    // inplace concatenation 
    assert(clear_list(p_list_2) == SUCCESS); 

    show_list(p_list_1, "p_list_1: "); 
    concat_lists(p_list_1, &p_list_2); 
    assert(p_list_2 == NULL); 
    show_list(p_list_1, "concat_list() : p_list_1 + p_list_2(empty) > "); 

    p_list_2 = create_list(); 
    for(int i = 0; i < 50; i += 5) 
        assert(insert_start(p_list_2, i) == SUCCESS); 

    show_list(p_list_1, "Before concat_list(): p_list_1 :");
    show_list(p_list_2, "Before concat_list(): p_list_2 :");  
    concat_lists(p_list_1, &p_list_2); 
    show_list(p_list_1, "After concat_list(): p_list_1: "); 
    assert(p_list_2 == NULL); 

    assert(destroy_list(&p_list_1) == SUCCESS); 
    assert(destroy_list(&concated_list) == SUCCESS); 

    puts("----------------------------"); 
    // ------------------ 

    // merging 
    list_t* p_merged_list = NULL; 
    
    p_list_1 = create_list(); 
    p_list_2 = create_list(); 

    for(int i = 0; i < 100; i += 10) 
        assert(insert_end(p_list_2, i) == SUCCESS); 

    show_list(p_list_1, "before merging, p_list_1: "); 
    show_list(p_list_2, "before merging, p_list_2: "); 
    p_merged_list = merge_lists(p_list_1, p_list_2); 
    show_list(p_merged_list, "merged list: "); 
    destroy_list(&p_merged_list); 

    for(int i = 0; i < 100; i += 5) 
        assert(insert_end(p_list_1, i) == SUCCESS); 
    show_list(p_list_1, "before mrege_list() > p_list_1: "); 
    show_list(p_list_2, "before mrege_list() > p_list_2: "); 
    p_merged_list = merge_lists(p_list_1, p_list_2); 
    show_list(p_merged_list, "merged_list: "); 

    assert(destroy_list(&p_list_1) == SUCCESS); 
    assert(destroy_list(&p_list_2) == SUCCESS); 
    assert(destroy_list(&p_merged_list) == SUCCESS); 

    puts("----------------------------"); 
    // ------------------- 

    destroy_list(&p_list); 
    assert(p_list == NULL); 
} 

void test_on_more_data(void) 
{
    list_t* p_list_1 = NULL; 
    list_t* p_list_2 = NULL; 
    list_t* reversed_list = NULL; 
    list_t* merged_list = NULL; 
    list_t* concated_list = NULL; 

    p_list_1 = create_list(); 
    p_list_2 = create_list(); 

    srand(time(0)); 

    for(int i = 0; i < NR_ELEMENTS_LIST1; ++i) 
        assert(insert_start(p_list_1, rand()) == SUCCESS);  

    for(int i = 0; i < NR_ELEMENTS_LIST2; ++i) 
        assert(insert_end(p_list_2, rand()) == SUCCESS); 

    assert(get_list_length(p_list_1) == NR_ELEMENTS_LIST1); 
    assert(get_list_length(p_list_2) == NR_ELEMENTS_LIST2); 

    reversed_list = get_reversed_list(p_list_1); 
    assert(get_list_length(reversed_list) == NR_ELEMENTS_LIST1); 

    assert(reverse_list(p_list_1) == SUCCESS); 

    concated_list = get_concated_list(p_list_1, p_list_2); 
    assert(get_list_length(concated_list) == (NR_ELEMENTS_LIST1+NR_ELEMENTS_LIST2)); 

    assert(concat_lists(p_list_1, &p_list_2) == SUCCESS); 
    assert(p_list_2 == NULL); 

    destroy_list(&p_list_1); 
    destroy_list(&reversed_list); 
    destroy_list(&merged_list); 
    destroy_list(&concated_list); 
}   