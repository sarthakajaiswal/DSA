/*
    @GOAL: doubly linked list using modular approach 
    @DATE: 06 Dec 2025 
    @AUTHOR: Sarthak A. Jaiswal 
*/

#include "list.h" 

// create list function 
list_t* create_list(void) 
{
    list_t* p_list = NULL; 

    p_list = get_node(0); 
    return (p_list); 
} 

// data addition functions 
status_t insert_start(list_t* p_list, data_t new_data) 
{
    generic_insert(p_list, get_node(new_data), p_list->next); 
    return (SUCCESS); 
} 

status_t insert_end(list_t* p_list, data_t new_data) 
{
    generic_insert(p_list->prev, get_node(new_data), p_list); 
    return (SUCCESS); 
} 

status_t insert_after(list_t* p_list, data_t existing_data, data_t new_data) 
{ 
    struct node* existing_node = NULL; 

    existing_node = search_node(p_list, existing_data); 
    if(existing_node == NULL) 
        return (LIST_DATA_NOT_FOUND); 

    generic_insert(existing_node, get_node(new_data), existing_node->next); 
    return (SUCCESS); 
}

status_t insert_before(list_t* p_list, data_t existing_data, data_t new_data) 
{
    node_t* existing_node = NULL; 

    existing_node = search_node(p_list, existing_data); 
    if(NULL == existing_node) 
        return (LIST_DATA_NOT_FOUND); 

    generic_insert(existing_node->prev, get_node(new_data), existing_node); 
    return (SUCCESS); 
} 

// get and pop functions 
status_t get_start(list_t* p_list, data_t* p_start_data) 
{
    if(is_list_empty(p_list)) 
        return (LIST_EMPTY); 

    *p_start_data = p_list->next->data; 
    return (SUCCESS); 
} 

status_t get_end(list_t* p_list, data_t* p_end_data) 
{
    if(is_list_empty(p_list)) 
        return (LIST_EMPTY); 

    *p_end_data = p_list->prev->data; 
    return (SUCCESS); 
} 

status_t pop_start(list_t* p_list, data_t* p_start_data) 
{
    struct node* delete_node = NULL; 

    if(is_list_empty(p_list) == TRUE) 
        return (LIST_EMPTY); 

    *p_start_data = p_list->next->data; 
    generic_delete(p_list->next); 
    return(SUCCESS); 
} 

status_t pop_end(list_t* p_list, data_t* p_end_data) 
{
    node_t* delete_node = NULL; 

    if(is_list_empty(p_list)) 
        return (LIST_EMPTY); 

    *p_end_data = p_list->prev->data; 
    generic_delete(p_list->prev); 
    return (SUCCESS); 
} 

// remove functions 
status_t remove_start(list_t* p_list) 
{
    node_t* delete_node = NULL; 

    if(is_list_empty(p_list)) 
        return (LIST_EMPTY); 

    generic_delete(p_list->prev); 
    return (SUCCESS); 
} 

status_t remove_end(list_t* p_list) 
{
    node_t* delete_node = NULL; 

    if(is_list_empty(p_list)) 
        return (LIST_EMPTY); 

    generic_delete(p_list->prev); 
    return (SUCCESS); 
} 

status_t remove_data(list_t* p_list, data_t r_data) 
{
    node_t* delete_node = NULL; 
    node_t* run = NULL; 

    delete_node = search_node(p_list, r_data); 
    if(delete_node == NULL) 
        return (LIST_DATA_NOT_FOUND); 

    generic_delete(delete_node); 
    return (SUCCESS); 
} 

// miscalleneous functions 
status_t find(list_t* p_list, data_t f_data) 
{
    node_t* f_node = NULL; 

    f_node = search_node(p_list, f_data); 
    return (f_node != NULL); 
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

// Helper functions 
void generic_insert(node_t* start_node, node_t* mid_node, node_t* end_node) 
{
    mid_node->prev = start_node; 
    mid_node->next = end_node; 
    start_node->next = mid_node; 
    end_node->prev = mid_node; 
} 

void generic_delete(node_t* delete_node) 
{
    delete_node->prev->next = delete_node->next; 
    delete_node->next->prev = delete_node->prev; 
    free(delete_node); 
    delete_node = NULL; 
} 

node_t* search_node(list_t* p_list, data_t search_data) 
{
    node_t* run = NULL; 

    run = p_list->next; 
    while(run != p_list) 
    {
        if(run->data == search_data) 
            return (run); 
        run = run->next; 
    }
    return (NULL); 
} 

node_t* get_node(data_t new_data) 
{
    node_t* new_node = NULL; 

    new_node = (node_t*)xmalloc(sizeof(node_t)); 
    new_node->data = new_data; 
    new_node->prev = new_node; 
    new_node->next = new_node; 

    return (new_node); 
} 

void* xmalloc(size_t size) 
{
    void* ptr = NULL; 

    ptr = malloc(size); 
    if(NULL == ptr) 
    {
        puts("fatal: out of memory"); 
        exit(EXIT_FAILURE); 
    }
    return (ptr); 
}
