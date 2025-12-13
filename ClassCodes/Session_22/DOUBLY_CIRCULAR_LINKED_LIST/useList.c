/*
    @GOAL: doubly linked list using modular approach 
    @DATE: 06 Dec 2025 
    @AUTHOR: Sarthak A. Jaiswal 
*/

#include "list.h" 

int main(void) 
{
    list_t* p_list = NULL; 
    data_t data; 
    data_t start_data; 
    data_t end_data; 
    status_t status; 

    p_list = create_list(); 

    assert(is_list_empty(p_list) == TRUE); 
    assert(get_start(p_list, &start_data) == LIST_EMPTY); 
    assert(get_end(p_list, &end_data) == LIST_EMPTY); 
    assert(pop_start(p_list, &start_data) == LIST_EMPTY); 
    assert(pop_end(p_list, &end_data) == LIST_EMPTY); 
    assert(remove_start(p_list) == LIST_EMPTY); 
    assert(remove_end(p_list) == LIST_EMPTY); 
    assert(get_list_length(p_list) == 0); 

    show(p_list, "Empty list (Just after creation(): "); 

    // insert data at start 
    for(data = 1; data <= 5; data++) 
        assert(insert_start(p_list, data*10) == SUCCESS); 
    show(p_list, "After insert_start():"); 

    // insert data at end 
    for(data = 6; data < 10; ++data) 
        assert(insert_end(p_list, data*10) == SUCCESS); 
    show(p_list, "After insert_end():"); 

    // insert after: wrong data 
    assert(insert_after(p_list, -100, 100) == LIST_DATA_NOT_FOUND); 

    // insert before: wrong data 
    assert(insert_before(p_list, -300, 2000) == LIST_DATA_NOT_FOUND); 

    // insert after and insert before: success cases 
    assert(insert_after(p_list, 50, 1000) == SUCCESS); 
    show(p_list, "After successfull insert_start():"); 

    assert(insert_before(p_list, 50, 2000) == SUCCESS); 
    show(p_list, "after successfull insert_before():"); 

    // get and pop functions 
    show(p_list, "Before get_start():"); 
    assert(get_start(p_list, &start_data) == SUCCESS); 
    printf("Start data = %d\n", start_data); 
    show(p_list, "After get_start():"); 

    show(p_list, "Before get_end():"); 
    assert(get_end(p_list, &end_data) == SUCCESS); 
    printf("End data = %d\n", end_data); 
    show(p_list, "After get_end():"); 

    show(p_list, "Before pop_start():"); 
    assert(pop_start(p_list, &start_data) == SUCCESS); 
    printf("start data = %d\n", start_data); 
    show(p_list, "After pop_start():"); 

    show(p_list, "Before pop_end():"); 
    assert(pop_end(p_list, &end_data) == SUCCESS); 
    printf("End data = %d\n", end_data); 
    show(p_list, "After pop_end():"); 

    // remove functions 
    show(p_list, "Before remove_start():"); 
    assert(remove_start(p_list) == SUCCESS); 
    show(p_list, "After remove_start():"); 

    show(p_list, "Before remove_end():"); 
    assert(remove_end(p_list) == SUCCESS); 
    show(p_list, "After remove_end():"); 

    // miscalleneous functions 
    // find 
    status = find(p_list, -700); 
    if(status == LIST_DATA_NOT_FOUND) 
        puts("-700 is not found in list"); 
    else 
        puts("find(): unexpected error: -700"); 

    status = find(p_list, 1000); 
    if(status == SUCCESS) 
        puts("1000 is found in list"); 
    else 
        puts("find(): unexpected error: 1000"); 

    // length functions 
    len_t length = -1; 
    printf("length of non-empty list = %d\n", get_list_length(p_list)); 

    // list empty 
    assert(is_list_empty(p_list) == FALSE); 
    puts("List is not empty at this point"); 

    // destroy_list 
    status = destroy_list(&p_list); 
    assert(status == SUCCESS); 

    puts("List destroyed and tested successfully"); 

    return (EXIT_SUCCESS); 
} 
