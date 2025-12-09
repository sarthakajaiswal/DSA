#include "list.h"

int main(void)
{
    list_t* p_list = NULL; 
    data_t data; 
    data_t first_data; 
    data_t last_data; 
    status_t status; 

    p_list = create_list(); 
    assert(p_list != NULL); 

    assert(is_list_empty(p_list) == TRUE); 
    assert(get_start(p_list, &first_data) == LIST_EMPTY);
    assert(get_end(p_list, &last_data) == LIST_EMPTY); 
    assert(pop_start(p_list, &first_data) == LIST_EMPTY); 
    assert(pop_end(p_list, &last_data) == LIST_EMPTY); 
    assert(remove_start(p_list) == LIST_EMPTY);
    assert(remove_end(p_list) == LIST_EMPTY); 
    assert(get_list_length(p_list) == 0); 
    
    show(p_list, "Empty list(just after creation):"); 

    //  Insert data at start 
    for(data = 1; data <= 5; ++data)
        assert(insert_start(p_list, data*10) == SUCCESS); 
    show(p_list, "After insert_start():");

    //  Insert data at end 
    for(data = 6; data <= 10; ++data)
        assert(insert_end(p_list, data*10) == SUCCESS); 
    show(p_list, "After insert_end():"); 
    
    //  Insert after : wrong data 
    assert(insert_after(p_list, -100, 1000) == LIST_DATA_NOT_FOUND);
    
    //  Insert before : wrong data 
    assert(insert_before(p_list, -300, 2000) == LIST_DATA_NOT_FOUND); 

    //  Insert after and insert before : SUCCESS cases 
    assert(insert_after(p_list, 50, 1000) == SUCCESS); 
    show(p_list, "After successful insert_after():"); 

    assert(insert_before(p_list, 50, 2000) == SUCCESS); 
    show(p_list, "After successful insert_before():"); 

    //  Get & pop functions 
    show(p_list, "Before get_start():");
    status = get_start(p_list, &first_data);
    assert(status == SUCCESS); 
    printf("Start data = %d\n", first_data); 
    show(p_list, "After get_start():"); 
    
    show(p_list, "Before get_end():"); 
    status = get_end(p_list, &last_data); 
    assert(status == SUCCESS); 
    printf("Last data = %d\n", last_data); 
    show(p_list, "After get_end():"); 

    show(p_list, "Before pop_start():"); 
    status = pop_start(p_list, &first_data); 
    assert(status == SUCCESS); 
    printf("Start data = %d\n", first_data); 
    show(p_list, "After pop_start():"); 

    show(p_list, "Before pop_end():"); 
    status = pop_end(p_list, &last_data); 
    assert(status == SUCCESS); 
    printf("Last data = %d\n", last_data); 
    show(p_list, "After pop_end():"); 

    //  Remove functions 
    show(p_list, "Before remove_start():"); 
    assert(remove_start(p_list) == SUCCESS); 
    show(p_list, "After remove_start():"); 

    show(p_list, "Before remove_end():");
    assert(remove_end(p_list) == SUCCESS); 
    show(p_list, "After remove_end():"); 

    //  remove_data() : Wrong case 
    assert(remove_data(p_list, -200) == LIST_DATA_NOT_FOUND); 
    //  remove_data(): SUCCESS case 
    show(p_list, "Before remove_data():");
    assert(remove_data(p_list, 20) == SUCCESS);
    show(p_list, "After remove_data():"); 

    //  Miscallaneous functions 

    //  find : Wrong case 
    status = find(p_list, -700); 
    if(status == FALSE)
        puts("-700 is not found in list"); 
    else 
        puts("find():unexpected error:-700"); 

    //  find : SUCCESS case 
    status = find(p_list, 1000); 
    if(status == SUCCESS)
        puts("1000 is found in list");
    else 
        puts("find():unexpected error:1000"); 

    //  Length function 
    len_t length = get_list_length(p_list); 
    printf("Length of non-empty list = %d\n", length); 


    //  is empty test 
    assert(is_list_empty(p_list) == FALSE); 
    puts("List is not empty at this point"); 

    //  List destruction 
    status = destroy_list(&p_list); 
    assert(status == SUCCESS && p_list == NULL); 

    puts("List destroyed and tested successfully"); 

    return (EXIT_SUCCESS); 
}