/*
    @GOAL: singly circular linked list using modular approach  
    @DATE: 07 Dec 2025 
    @AUTHOR: Sarthak A. Jaiswal 
*/

#include "list.h" 

// create list function 
list_t* create_list(void) 
{
    list_t* p_list = NULL; 

    p_list = (node_t*)malloc(sizeof(node_t)); 
    if(NULL == p_list) 
    { 
        puts("create_list(): malloc(): failed"); 
        exit(EXIT_FAILURE); 
    } 
    p_list->data = 0; 
    p_list->next = p_list; 

    return (p_list); 
}

// data addition functions 
status_t insert_start(list_t* p_list, data_t new_data) 
{
    node_t* new_node = NULL; 

    new_node = (node_t*)malloc(sizeof(node_t)); 
    if(NULL == new_node) 
    { 
        puts("insert_start(): malloc(): failed"); 
        exit(EXIT_FAILURE); 
    } 
    new_node->data = new_data; 

    new_node->next = p_list->next; 
    p_list->next = new_node; 

    return (SUCCESS); 
}

status_t insert_end(list_t* p_list, data_t new_data) 
{
    struct node* new_node = NULL; 
    struct node* run = NULL; 

    new_node = (node_t*)malloc(sizeof(node_t)); 
    if(NULL == new_node) 
    { 
        puts("insert_end(): malloc(): failed"); 
        exit(EXIT_FAILURE); 
    } 
    new_node->data = new_data; 

    run = p_list->next; 
    while(run->next != p_list) 
        run = run->next; 

    // in case of empty list: run == p_list 
    // in case of non-empty list: run == last node with data 
    new_node->next = run->next; 
    run->next = new_node; 

    return (SUCCESS); 
}

status_t insert_after(list_t* p_list, data_t existing_data, data_t new_data) 
{
    struct node* run = NULL; 
    struct node* existing_node = NULL; 
    struct node* new_node = NULL; 

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
        puts("insert_after(): malloc(): failed"); 
        exit(EXIT_FAILURE); 
    } 
    new_node->data = new_data; 

    new_node->next = existing_node->next; 
    existing_node->next = new_node; 

    return (SUCCESS); 
}

status_t insert_before(list_t* p_list, data_t existing_data, data_t new_data) 
{
    struct node* run = NULL; 
    struct node* run_previous = NULL; 
    struct node* existing_node = NULL; 
    struct node* existing_node_previous = NULL; 
    struct node* new_node = NULL; 

    run_previous = p_list; 
    run = p_list->next; 
    while(run != p_list) 
    {
        if(run->data == existing_data) 
            break; 
        run_previous = run; 
        run = run->next; 
    } 

    if(run == p_list) 
        return (LIST_DATA_NOT_FOUND); 

    existing_node = run; 
    existing_node_previous = run_previous; 
    new_node = (node_t*)malloc(sizeof(node_t)); 
    if(NULL == new_node) 
    { 
        puts("insert_before(): malloc(): failed"); 
        exit(EXIT_FAILURE); 
    } 
    new_node->data = new_data; 

    new_node->next = existing_node; 
    existing_node_previous->next = new_node; 

    return (SUCCESS); 
}

// get and pop functions 
status_t get_start(list_t* p_list, data_t* p_start_data) 
{
    if(p_list->next == p_list) 
        return (LIST_EMPTY); 

    *p_start_data = p_list->next->data; 
    return (SUCCESS); 
}

status_t get_end(list_t* p_list, data_t* p_end_data) 
{
    struct node* run = NULL; 

    if(p_list->next == p_list) 
        return (LIST_EMPTY); 

    run = p_list->next; 
    while(run->next != p_list) 
        run = run->next; 
    
    *p_end_data = run->data; 

    return (SUCCESS); 
}

status_t pop_start(list_t* p_list, data_t* p_start_data) 
{
    struct node* delete_node = NULL; 
    struct node* delete_node_previous = NULL; 

    if(p_list->next == p_list) 
        return (LIST_EMPTY); 

    *p_start_data = p_list->next->data; 

    delete_node_previous = p_list; 
    delete_node = p_list->next; 

    delete_node_previous->next = delete_node->next; 
    free(delete_node); 
    delete_node = NULL; 

    return (SUCCESS); 
}

status_t pop_end(list_t* p_list, data_t* p_end_data) 
{
    struct node* run = NULL; 
    struct node* run_previous = NULL; 

    if(p_list->next == p_list) 
        return (LIST_EMPTY); 

    run_previous = p_list; 
    run = p_list->next; 
    while(run->next != p_list) 
    {
        run_previous = run; 
        run = run->next; 
    } 
    
    *p_end_data = run->data;
    
    run_previous->next = run->next; 
    free(run); 
    run = NULL; 

    return (SUCCESS); 
}

// remove functions 
status_t remove_start(list_t* p_list) 
{
    struct node* delete_node = NULL; 
    struct node* delete_node_previous = NULL; 

    if(p_list->next == p_list) 
        return (LIST_EMPTY); 

    delete_node_previous = p_list; 
    delete_node = p_list->next; 

    delete_node_previous->next = delete_node->next; 
    free(delete_node); 
    delete_node = NULL; 

    return (SUCCESS); 
}

status_t remove_end(list_t* p_list) 
{
    struct node* run = NULL; 
    struct node* run_previous = NULL; 

    if(p_list->next == p_list) 
        return (LIST_EMPTY); 

    run_previous = p_list; 
    run = p_list->next; 
    while(run->next != p_list) 
    {
        run_previous = run; 
        run = run->next; 
    } 
    
    run_previous->next = run->next; 
    free(run); 
    run = NULL; 

    return (SUCCESS); 
}

status_t remove_data(list_t* p_list, data_t r_data) 
{
    struct node* run = NULL; 
    struct node* run_previous = NULL; 

    run_previous = p_list; 
    run = p_list->next; 
    while(run != p_list) 
    {
        if(run->data == r_data) 
            break; 

        run_previous = run; 
        run = run->next; 
    } 
    if(run == p_list) 
        return (LIST_DATA_NOT_FOUND); 

    run_previous->next = run->next; 
    free(run); 
    run = NULL; 

    return (SUCCESS); 
}

// miscalleneous functions 
status_t find(list_t* p_list, data_t f_data) 
{
    struct node* run = NULL; 

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
    return (p_list->next == p_list); 
}

len_t get_list_length(list_t* p_list) 
{
    struct node* run = NULL; 
    len_t length = 0; 

    run = p_list->next; 
    while(run != p_list) 
    {
        length = length+1; 
        run = run->next; 
    }

    return (length); 
}

void show(list_t* p_list, const char* msg) 
{
    struct node* run = NULL; 

    if(msg) 
        puts(msg); 

    printf("[START]->"); 
    run = p_list->next; 
    while(run != p_list) 
    {
        printf("[%d]->", run->data); 
        run = run->next; 
    }
    puts("[END]"); 
}

// destroy list 
status_t destroy_list(list_t** pp_list) 
{
    struct node* p_list = NULL; 
    struct node* run = NULL; 
    struct node* run_next = NULL; 

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
