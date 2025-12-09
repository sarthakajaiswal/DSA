#include "list.h"

list_t* create_list(void)
{
    list_t* p_list = NULL; 

    p_list = get_node(0); 
    p_list->prev = p_list; 
    p_list->next = p_list; 

    return (p_list); 
}

//  Insertion functions 
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
    node_t* existing_node = NULL;
    
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
    if(existing_node == NULL)
        return (LIST_DATA_NOT_FOUND); 
    
    generic_insert(existing_node->prev, get_node(new_data), existing_node); 
    
    return (SUCCESS); 
}

//  Get and pop functions 
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
    node_t* delete_node = NULL; 

    if(p_list->prev == p_list && p_list->next == p_list)
        return (LIST_EMPTY); 
    
    *p_start_data = p_list->next->data; 

    generic_delete(p_list->next); 

    return (SUCCESS); 
}

status_t pop_end(list_t* p_list, data_t* p_end_data)
{
    node_t* delete_node = NULL; 

    if(p_list->prev == p_list && p_list->next == p_list)
        return (LIST_EMPTY); 

    *p_end_data = p_list->prev->data; 

    generic_delete(p_list->prev); 

    return (SUCCESS); 
}

//  Remove functions 
status_t remove_start(list_t* p_list)
{
    node_t* delete_node = NULL; 

    if(p_list->next == p_list && p_list->prev == p_list)
        return (LIST_EMPTY); 

    generic_delete(p_list->next); 

    return (SUCCESS); 
}

status_t remove_end(list_t* p_list)
{
    node_t* delete_node = NULL; 

    if(p_list->prev == p_list && p_list->next == p_list)
        return (LIST_EMPTY); 

    generic_delete(p_list->prev); 

    return (SUCCESS); 
}

status_t remove_data(list_t* p_list, data_t e_data)
{
    node_t* run = NULL; 
    node_t* delete_node = NULL; 

    delete_node = search_node(p_list, e_data); 
    if(delete_node == NULL)
        return (LIST_DATA_NOT_FOUND); 

    generic_delete(delete_node); 
    
    return (SUCCESS); 
}

//  Miscallaneous functions 
status_t find(list_t* p_list, data_t search_data)
{
    node_t* f_node = NULL; 

    f_node = search_node(p_list, search_data); 
    return (f_node != NULL); 
}

status_t is_list_empty(list_t* p_list)
{
    return (p_list->prev == p_list && p_list->next == p_list); 
}

len_t get_list_length(list_t* p_list)
{
    len_t length = 0; 
    node_t* run = NULL; 

    run = p_list->next; 
    while(run != p_list) 
    {
        length += 1; 
        run = run->next; 
    }

    return (length); 
}

void show(list_t* p_list, const char* msg)
{
    node_t* run = NULL; 

    if(msg)
        printf("%s:", msg); 

    printf("[START]<->"); 
    run = p_list->next; 
    while(run != p_list)
    {
        printf("[%d]<->", run->data); 
        run = run->next; 
    }
    printf("[END]\n"); 
}

//  Destroy function 
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

//  Helper functions 
void generic_insert(node_t* start_node, node_t* mid_node, node_t* end_node)
{
    mid_node->next = end_node; 
    mid_node->prev = start_node; 
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
    new_node->prev = NULL; 
    new_node->next = NULL; 

    return (new_node);
}

void* xmalloc(size_t size)
{
    void* ptr = NULL; 

    ptr = malloc(size); 
    if(NULL == ptr)
    {
        puts("xmalloc():fatal:out of memory"); 
        exit(EXIT_FAILURE); 
    }

    return (ptr); 
}
