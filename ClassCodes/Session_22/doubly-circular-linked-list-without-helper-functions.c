/*
	@GOAL:      to implement Doubly Circular Linked list without using any helper functions (modular/reusable approach)  
	@DATE:	    06 Dec 2025 
	@AUTHOR: Sarthak A. Jaiswal 
*/

// header files 
#include <stdio.h> 
#include <stdlib.h> 
#include <assert.h> 

// Symbolic constants 
enum status 
{
    SUCCESS         = 1, 
    TRUE            = 1, 
    FALSE           = 0, 
    LIST_DATA_NOT_FOUND = 2, 
    LIST_EMPTY      = 3 
}; 

// typedefs 
typedef int             data_t; 
typedef int             len_t; 
typedef enum status     status_t; 
typedef struct node     node_t; 
typedef node_t          list_t; 

// node layout definition 
struct node 
{
    data_t data; 
    struct node* prev; 
    struct node* next; 
}; 

// declarations of interface functions 

// create list function 
list_t* create_list(void); 

// data addition functions 
status_t insert_start(list_t* p_list, data_t new_data); 
status_t insert_end(list_t* p_list, data_t new_data); 
status_t insert_before(list_t* p_list, data_t existing_data, data_t new_data); 
status_t insert_after(list_t* p_list, data_t existing_data, data_t new_data); 

// get and pop functions 
status_t get_start(list_t* p_list, data_t* p_start_data); 
status_t get_end(list_t* p_list, data_t* p_end_data); 
status_t pop_start(list_t* p_list, data_t* p_start_data); 
status_t pop_end(list_t* p_list, data_t* p_end_data); 

// remove functions 
status_t remove_start(list_t* p_list); 
status_t remove_end(list_t* p_list); 
status_t remove_data(list_t* p_list, data_t r_data); 

// miscalleneous functions 
status_t find(list_t* p_list, data_t f_data); 
status_t is_list_empty(list_t* p_list); 
len_t get_list_length(list_t* p_list); 
void show(list_t* p_list, const char* msg); 

// destroy list 
status_t destroy_list(list_t** pp_list); 

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

// create list function 
list_t* create_list(void) 
{
    list_t* p_list = NULL; 

    p_list = (list_t*)malloc(sizeof(list_t)); 
    if(NULL == p_list) 
    {
        puts("create_list(): malloc(): failed"); 
        exit(EXIT_FAILURE); 
    } 
    p_list->data = 0; 
    p_list->next = p_list; 
    p_list->prev = p_list; 

    return (p_list); 
} 

// data addition functions 
status_t insert_start(list_t* p_list, data_t new_data) 
{
    node_t* new_node = NULL; 

    new_node = (node_t*)malloc(sizeof(node_t)); 
    if(NULL == new_node) 
    {
        puts("insert_start():malloc(): failed"); 
        exit(EXIT_FAILURE); 
    } 
    new_node->data = new_data; 
    new_node->next = p_list->next; 
    new_node->prev = p_list; 
    p_list->next->prev = new_node; 
    p_list->next = new_node; 

    return (SUCCESS); 
} 

status_t insert_end(list_t* p_list, data_t new_data) 
{
    node_t* new_node = NULL; 

    new_node = (node_t*)malloc(sizeof(node_t)); 
    if(NULL == new_node) 
    {
        puts("insert_end(): malloc(): failed"); 
        exit(EXIT_FAILURE); 
    }
    
    new_node->data = new_data; 

    new_node->next = p_list; 
    new_node->prev = p_list->prev; 
    p_list->prev->next = new_node; 
    p_list->prev = new_node; 

    return (SUCCESS); 
} 

status_t insert_after(list_t* p_list, data_t existing_data, data_t new_data) 
{
    node_t* new_node = NULL;    
    struct node* existing_node = NULL; 
    struct node* run = NULL; 

    run = p_list->next; 
    while(run != p_list) 
    {
        if(run->data == existing_data) 
            break; 

        run = run->next; 
    }

    if(run == p_list) 
        return (LIST_DATA_NOT_FOUND); 

    existing_node = run; 
    new_node = (struct node*)malloc(sizeof(struct node)); 
    if(NULL == new_node)
    {
        puts("insert_after():malloc():failed"); 
        exit(EXIT_FAILURE); 
    } 
    new_node->data = new_data; 

    new_node->next = existing_node->next; 
    new_node->prev = existing_node; 
    existing_node->next->prev = new_node; 
    existing_node->next = new_node; 

    return (SUCCESS); 
}

status_t insert_before(list_t* p_list, data_t existing_data, data_t new_data) 
{
    struct node* existing_node = NULL; 
    struct node* new_node = NULL; 
    struct node* run = NULL; 

    run = p_list->next; 
    while(run != p_list) 
    {
        if(run->data == existing_data) 
            break; 
        run = run->next; 
    } 

    if(run == p_list) 
        return (LIST_DATA_NOT_FOUND); 

    existing_node = run; 
    new_node = (node_t*)malloc(sizeof(node_t)); 
    if(NULL == new_node) 
    {
        puts("insert_before():malloc(): failed"); 
        exit(EXIT_FAILURE); 
    } 
    new_node->data = new_data; 

    new_node->next = existing_node; 
    new_node->prev = existing_node->prev; 
    existing_node->prev->next = new_node; 
    existing_node->prev = new_node; 

    return (SUCCESS); 
} 

// get and pop functions 
status_t get_start(list_t* p_list, data_t* p_start_data) 
{
    if(p_list->prev == p_list && p_list->next == p_list) 
        return (LIST_EMPTY); 

    *p_start_data = p_list->next->data; 
    return (SUCCESS); 
} 

status_t get_end(list_t* p_list, data_t* p_end_data) 
{
    if(p_list->prev == p_list && p_list->next == p_list) 
        return (LIST_EMPTY); 

    *p_end_data = p_list->prev->data; 
    return (SUCCESS); 
} 

status_t pop_start(list_t* p_list, data_t* p_start_data) 
{
    struct node* delete_node = NULL; 

    if(p_list->prev == p_list && p_list->next == p_list) 
        return (LIST_EMPTY); 

    *p_start_data = p_list->next->data; 

    delete_node = p_list->next; 
    delete_node->prev->next = delete_node->next; 
    delete_node->next->prev = delete_node->prev; 

    free(delete_node); 

    return(SUCCESS); 
} 

status_t pop_end(list_t* p_list, data_t* p_end_data) 
{
    node_t* delete_node = NULL; 

    if(p_list->prev == p_list && p_list->next == p_list) 
        return (LIST_EMPTY); 

    *p_end_data = p_list->prev->data; 

    delete_node = p_list->prev; 
    delete_node->prev->next = delete_node->next; 
    delete_node->next->prev = delete_node->prev; 

    free(delete_node); 

    return (SUCCESS); 
} 

// remove functions 
status_t remove_start(list_t* p_list) 
{
    node_t* delete_node = NULL; 

    if(p_list->next == p_list && p_list->prev == p_list) 
        return (LIST_EMPTY); 

    delete_node = p_list->next; 

    delete_node->next->prev = delete_node->prev; 
    delete_node->prev->next = delete_node->next; 

    free(delete_node); 

    return (SUCCESS); 
} 

status_t remove_end(list_t* p_list) 
{
    node_t* delete_node = NULL; 

    if(p_list->next == p_list && p_list->prev == p_list) 
        return (LIST_EMPTY); 

    delete_node = p_list->prev; 

    delete_node->prev->next = delete_node->next; 
    delete_node->next->prev = delete_node->prev; 

    free(delete_node); 

    return (SUCCESS); 
} 

status_t remove_data(list_t* p_list, data_t r_data) 
{
    node_t* delete_node = NULL; 
    node_t* run = NULL; 

    run = p_list->next; 
    while(run != p_list) 
    {
        if(run->data == r_data) 
            break; 

        run = run->next; 
    } 

    delete_node = run; 
    delete_node->prev->next = delete_node->next; 
    delete_node->next->prev = delete_node->prev; 

    free(delete_node); 

    return (SUCCESS); 
} 

// miscalleneous functions 
status_t find(list_t* p_list, data_t f_data) 
{
    node_t* run = NULL; 

    run = p_list->next; 
    while(run != p_list) 
    {
        if(run->data == f_data) 
            return (TRUE); 
        run = run->next; 
    } 

    return (FALSE); 
} 

status_t is_list_empty(list_t* p_list) 
{
    return (p_list->prev == p_list && p_list->next == p_list); 
} 

len_t get_list_length(list_t* p_list) 
{
    node_t* run = NULL; 
    len_t len = 0; 

    run = p_list->next; 
    while(run != p_list) 
    {
        len = len + 1; 
        run = run->next; 
    }
    
    return (len);   
} 

void show(list_t* p_list, const char* msg) 
{
    node_t* p_run = NULL; 

    if(msg) 
        printf("%s : ", msg); 

    printf("[START]<->"); 
    p_run = p_list->next; 
    while(p_run != p_list) 
    {
        printf("[%d]<->", p_run->data); 
        p_run = p_run->next; 
    }
    puts("[END]"); 
} 

// destroy list 
status_t destroy_list(list_t** pp_list) 
{
    list_t* p_list = NULL; 
    node_t* run = NULL; 
    node_t* run_next = NULL; 

    p_list = *pp_list; 
    run = p_list->next; 
    while(run != p_list) 
    {
        run_next = run->next; 
        free(run); 
        run = run_next; 
    } 

    free(p_list); 
    p_list = NULL; 
    *pp_list = NULL; 

    return (SUCCESS); 
}

