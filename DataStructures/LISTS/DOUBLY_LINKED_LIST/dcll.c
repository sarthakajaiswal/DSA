/****************************************************************
 * 
 *      DOUBLY LINKED LIST 
 * 
 * Author:  Sarthak A. Jaiswal 
 * Date:    06 Dec 2025 
 * 
 ******************************************************************/

#include <stdio.h> 
#include "dcll.h" 

list_t* create_list(void) 
{
    return (get_node(0)); 
} 

status_t insert_start(list_t* p_list, data_t new_data) 
{
    generic_insert(p_list, get_node(new_data), p_list->next); 
    return (SUCCESS); 
} 

status_t insert_end(list_t* p_list, data_t new_data) 
{
    node_t* p_run = NULL; 

    p_run = p_list; 
    while(p_run->next != NULL) 
        p_run = p_run->next; 

    generic_insert(p_run, get_node(new_data), p_run->next); 
    return (SUCCESS); 
} 

status_t insert_after(list_t* p_list, data_t existing_data, data_t new_data) 
{
    node_t* p_enode = NULL; 

    p_enode = search_node(p_list, existing_data); 
    if(p_enode == NULL) 
        return (LIST_DATA_NOT_FOUND); 

    generic_insert(p_enode, get_node(new_data), p_enode->next); 
    return (SUCCESS); 
} 

status_t insert_before(list_t* p_list, data_t existing_data, data_t new_data) 
{
    node_t* p_enode = NULL; 

    p_enode = search_node(p_list, existing_data); 
    if(NULL == p_enode) 
        return (LIST_DATA_NOT_FOUND); 

    generic_insert(p_enode->prev, get_node(new_data), p_enode); 
    return (SUCCESS); 
} 

status_t get_start(list_t* p_list, data_t* p_start_data) 
{
    if(is_empty(p_list) == TRUE) 
        return (LIST_EMPTY); 

    *p_start_data = p_list->next->data; 
    return (SUCCESS); 
} 

status_t get_end(list_t* p_list, data_t* p_end_data) 
{
    node_t* p_run = NULL; 

    if(is_empty(p_list) == TRUE) 
        return (LIST_EMPTY); 

    p_run = p_list; 
    while(p_run->next != NULL) 
        p_run = p_run->next; 

    *p_end_data = p_run->data; 
    return (SUCCESS); 
} 

status_t pop_start(list_t* p_list, data_t* p_start_data) 
{
    if(is_empty(p_list) == TRUE) 
        return (LIST_EMPTY); 

    *p_start_data = p_list->next->data; 
    generic_delete(p_list->next); 

    return (SUCCESS); 
} 

status_t pop_end(list_t* p_list, data_t* p_end_data) 
{
    node_t* p_run = NULL; 

    if(is_empty(p_list) == TRUE) 
        return (LIST_EMPTY); 

    p_run = p_list->next; 
    while(p_run->next != NULL) 
        p_run = p_run->next; 

    generic_delete(p_run); 
    return (SUCCESS); 
} 

status_t remove_start(list_t* p_list) 
{
    if(is_empty(p_list) == TRUE) 
        return (LIST_EMPTY); 

    generic_delete(p_list->next); 
    return (SUCCESS); 
} 

status_t remove_end(list_t* p_list) 
{
    node_t* p_run = NULL; 

    if(is_empty(p_list) == TRUE) 
        return (LIST_EMPTY); 

    p_run = p_list->next; 
    while(p_run->next != NULL) 
        p_run = p_run->next; 

    generic_delete(p_run); 
    return (SUCCESS); 
} 

status_t remove_data(list_t* p_list, data_t r_data) 
{
    node_t* p_node = NULL; 

    p_node = search_node(p_list, r_data); 
    if(p_node == NULL) 
        return (LIST_DATA_NOT_FOUND); 

    generic_delete(p_node); 
    return (SUCCESS); 
} 

status_t clear_list(list_t* p_list) 
{
    node_t* p_run = NULL; 
    node_t* p_run_next = NULL; 

    p_run = p_list->next; 
    while(p_run != NULL) 
    {
        p_run_next = p_run->next; 
        free(p_run); 
        p_run = p_run_next; 
    }  

    p_list->next = NULL; 
    return (SUCCESS); 
} 

status_t is_empty(list_t* p_list) 
{
    return (p_list->next == NULL); 
} 

status_t find_in_list(list_t* p_list, data_t f_data) 
{
    node_t* p_node = NULL; 

    p_node = search_node(p_list, f_data); 
    return (p_node != NULL); 
} 

len_t get_list_length(list_t* p_list) 
{
    node_t* p_run = NULL; 
    len_t len; 

    p_run = p_list->next; 
    while(p_run != NULL) 
    {
        len = len + 1; 
        p_run = p_run->next; 
    } 

    return (len); 
} 

void show_list(list_t* p_list, const char* msg) 
{
    node_t* p_run = NULL; 

    if(msg) 
        puts(msg); 

    printf("[START]<->"); 
    p_run = p_list->next; 
    while(p_run != NULL) 
    {
        printf("[%d]<->", p_run->data); 
        p_run = p_run->next; 
    } 
    puts("[END]"); 
} 

status_t destroy_list(list_t** pp_list) 
{
    list_t* p_list = *pp_list; 
    clear_list(p_list); 

    free(p_list); 
    p_list = NULL; 
    *pp_list = NULL; 

    return (SUCCESS); 
}

/* Interlist routines */
list_t* get_concated_list(list_t* p_list_1, list_t* p_list_2) 
{} 

status_t concat_list(list_t* p_list_1, list_t** pp_list_2) 
{} 

list_t* get_reversed_list(list_t* p_list) 
{} 

status_t reverse_list(list_t* p_list) 
{} 

list_t* merge_lists(list_t* p_list_1, list_t* p_list_2) 
{} 

/* List auxilliary functions */
static void generic_insert(node_t* p_beg, node_t* p_mid, node_t* p_end) 
{
    p_mid->prev = p_beg; 
    p_mid->next = p_end; 
    if(p_beg != NULL) 
        p_beg->next = p_mid; 
    if(p_end != NULL) 
        p_end->prev = p_mid; 
} 

static void generic_delete(node_t* p_delete_node) 
{
    if(p_delete_node == NULL) 
        return; 

    if(p_delete_node->prev != NULL) 
        p_delete_node->prev->next = p_delete_node->next; 
    if(p_delete_node->next != NULL) 
        p_delete_node->next->prev = p_delete_node->prev; 

    free(p_delete_node); 
    p_delete_node = NULL; 
} 

static node_t* search_node(list_t* p_list, data_t s_data) 
{
    node_t* p_run = NULL; 

    p_run = p_list->next; 
    while(p_run != NULL) 
    {
        if(p_run->data == s_data) 
            return (p_run); 
        
        p_run = p_run->next; 
    } 

    return (NULL); 
} 

static node_t* get_node(data_t new_data) 
{
    node_t* new_node = NULL; 

    new_node = (node_t*)xcalloc(1, sizeof(node_t)); 
    new_node->data = new_data; 
    new_node->next = NULL; 
    new_node->prev = NULL; 

    return (new_node); 
} 

/* auxilliary functions */
static void* xcalloc(size_t nr_elements, size_t size_per_element) 
{
    void* p = NULL;

    p = malloc(nr_elements * size_per_element); 
    if(p == NULL) 
    {
        fprintf(stderr, "calloc(): fatal: out of memory"); 
        exit(EXIT_FAILURE); 
    } 

    return (p); 
} 
