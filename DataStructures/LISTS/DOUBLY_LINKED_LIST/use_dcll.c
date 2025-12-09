#include <stdio.h> 
#include <assert.h> 

#include "dcll.h" 

int main(void) 
{
    list_t* p_list = NULL; 
    data_t start_data, end_data, data; 
    len_t length; 
    status_t status; 

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

    assert(get_list_length(p_list) > 0); 
    data = -1; 
    assert(get_start(p_list, &data) == SUCCESS); 
    printf("Start data = %d\n", data); 
    show_list(p_list, "After get_start():"); 

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

    assert(remove_start(p_list) == SUCCESS); 
    show_list(p_list, "after remove_start():"); 

    assert(remove_end(p_list) == SUCCESS); 
    show_list(p_list, "after remove_end(): "); 

    assert(remove_data(p_list, 23) == LIST_DATA_NOT_FOUND); 
    assert(remove_data(p_list, 0) == SUCCESS); 
    show_list(p_list, "after remove_data():"); 

    printf("Length = %llu\n", get_list_length(p_list)); 

    assert(is_empty(p_list) == FALSE); 

    assert(find_in_list(p_list, -10) == FALSE);  
    assert(find_in_list(p_list, 100) == TRUE); 

    show_list(p_list, "p_list before imutable reversal: get_reversed_list():"); 

    destroy_list(&p_list); 

    return (0); 
} 

