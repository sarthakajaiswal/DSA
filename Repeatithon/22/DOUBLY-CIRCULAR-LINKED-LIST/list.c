#include "list.h" 
#include "list.h" 
#include "list.h" 
#include "list.h" 
#include "list.h" 

list_t* create_list(void) 
{
    list_t* p_new_list = NULL; 

    p_new_list = get_node(0); 
    p_new_list->prev = p_new_list; 
    p_new_list->next = p_new_list; 

    return (p_new_list); 
} 

list_t* create_list(void) 
{
    list_t* p_new_list = NULL; 

    p_new_list = get_node(0); 
    p_new_list->prev = p_new_list; 
    p_new_list->next = p_new_list; 

    return (p_new_list); 
} 

list_t* create_list(void) 
{
    list_t* p_new_list = NULL; 

    p_new_list = get_node(0); 
    p_new_list->prev = p_new_list; 
    p_new_list->next = p_new_list; 

    return (p_new_list); 
} 

list_t* create_list(void) 
{
    list_t* p_new_list = NULL; 

    p_new_list = get_node(0); 
    p_new_list->prev = p_new_list; 
    p_new_list->next = p_new_list; 

    return (p_new_list); 
} 

list_t* create_list(void) 
{
    list_t* p_new_list = NULL; 

    p_new_list = get_node(0); 
    p_new_list->next = p_new_list; 
    p_new_list->prev = p_new_list; 

    return (p_new_list); 
} 

// insertion functions 
status_t insert_start(list_t* p_list, data_t new_data) 
{
    generic_insert(p_list, get_node(new_data), p_list->next); 
    return (SUCCESS); 
} 

status_t insert_start(list_t* p_list, data_t new_data) 
{
    generic_insert(p_list, get_node(new_data), p_list->next); 
    return (SUCCESS); 
} 

status_t insert_start(list_t* p_list, data_t new_data) 
{
    generic_insert(p_list, get_node(new_data), p_list->next); 
    return (SUCCESS); 
} 

status_t insert_start(list_t* p_list, data_t new_data) 
{
    generic_insert(p_list, get_node(new_data), p_list->next); 
    return (SUCCESS); 
} 

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

status_t insert_end(list_t* p_list, data_t new_data) 
{
    generic_insert(p_list->prev, get_node(new_data), p_list); 
    return (SUCCESS); 
} 

status_t insert_end(list_t* p_list, data_t new_data) 
{
    generic_insert(p_list->prev, get_node(new_data), p_list); 
    return (SUCCESS); 
} 

status_t insert_end(list_t* p_list, data_t new_data) 
{
    generic_insert(p_list->prev, get_node(new_data), p_list); 
    return (SUCCESS); 
} 

status_t insert_end(list_t* p_list, data_t new_data) 
{
    generic_insert(p_list->prev, get_node(new_data), p_list); 
    return (SUCCESS); 
} 

status_t insert_after(list_t* p_list, data_t existing_data, data_t new_data) 
{
    node_t* p_existing_node = NULL; 

    p_existing_node = search_node(p_list, existing_data); 

    if(NULL == p_existing_node) 
        return (LIST_DATA_NOT_FOUND); 

    generic_insert(p_existing_node, get_node(new_data), p_existing_node->next); 
    return (SUCCESS); 
} 

status_t insert_after(list_t* p_list, data_t existing_data, data_t new_data) 
{
    node_t* p_existing_node = NULL; 

    p_existing_node = search_node(p_list, existing_data); 

    if(NULL == p_existing_node) 
        return (LIST_DATA_NOT_FOUND); 

    generic_insert(p_existing_node, get_node(new_data), p_existing_node->next); 
    return (SUCCESS); 
} 

status_t insert_after(list_t* p_list, data_t existing_data, data_t new_data) 
{
    node_t* p_existing_node = NULL; 

    p_existing_node = search_node(p_list, existing_data); 

    if(NULL == p_existing_node) 
        return (LIST_DATA_NOT_FOUND); 

    generic_insert(p_existing_node, get_node(new_data), p_existing_node->next); 
    return (SUCCESS); 
} 

status_t insert_after(list_t* p_list, data_t existing_data, data_t new_data) 
{
    node_t* p_existing_node = NULL; 

    p_existing_node = search_node(p_list, existing_data); 

    if(NULL == p_existing_node) 
        return (LIST_DATA_NOT_FOUND); 

    generic_insert(p_existing_node, get_node(new_data), p_existing_node->next); 
    return (SUCCESS); 
} 

status_t insert_after(list_t* p_list, data_t existing_data, data_t new_data) 
{
    node_t* p_existing_node = NULL; 

    p_existing_node = search_node(p_list, existing_data); 

    if(NULL == p_existing_node)  
        return (LIST_DATA_NOT_FOUND); 
    
    generic_insert(p_existing_node, get_node(new_data), p_existing_node->next); 
    return (SUCCESS); 
} 

status_t insert_after(list_t* p_list, data_t existing_data, data_t new_data) 
{
    node_t* p_existing_node = NULL; 

    p_existing_node = search_node(p_list, existing_data); 

    if(NULL == p_existing_node) 
        return (LIST_DATA_NOT_FOUND); 

    generic_insert(p_existing_node, get_node(new_data), p_existing_node->next); 
    return (SUCCESS); 
} 

status_t insert_before(list_t* p_list, data_t existing_data, data_t new_data) 
{
    node_t* p_existing_node = NULL; 

    p_existing_node = search_node(p_list, existing_data); 

    if(NULL == p_existing_node) 
        return (LIST_DATA_NOT_FOUND); 

    generic_insert(p_existing_node->prev, get_node(new_data), p_existing_node); 
    return (SUCCESS); 
} 

status_t insert_before(list_t* p_list, data_t existing_data, data_t new_data) 
{
    node_t* p_existing_node = NULL; 

    p_existing_node = search_node(p_list, existing_data); 

    if(NULL == p_existing_node) 
        return (LIST_DATA_NOT_FOUND); 

    generic_insert(p_existing_node->prev, get_node(existing_data), p_existing_node); 
    return (SUCCESS); 
} 

status_t insert_before(list_t* p_list, data_t existing_data, data_t new_data) 
{
    node_t* p_existing_node = NULL; 

    p_existing_node = search_node(p_list, existing_data); 

    if(NULL == p_existing_node) 
        return (LIST_DATA_NOT_FOUND);
         
    generic_insert(p_existing_node->prev, get_node(new_data), p_existing_node); 
    return (SUCCESS); 
} 

status_t insert_before(list_t* p_list, data_t existing_data, data_t new_data) 
{
    node_t* p_existing_node = NULL; 

    p_existing_node = search_node(p_list, existing_data); 

    if(NULL == p_existing_node) 
        return (LIST_DATA_NOT_FOUND); 

    generic_insert(p_existing_node->prev, get_node(new_data), p_existing_node); 
    return (SUCCESS); 
} 

status_t insert_before(list_t* p_list, data_t existing_data, data_t new_data) 
{
    node_t* p_existing_node = NULL; 

    p_existing_node = search_node(p_list, existing_data); 

    if(NULL == p_existing_node) 
        return (LIST_DATA_NOT_FOUND);
         
    generic_insert(p_existing_node->prev, get_node(new_data), p_existing_node); 
    return (SUCCESS); 
} 

status_t get_start(list_t* p_list, data_t* p_start_data) 
{
    if(is_list_empty(p_list) == TRUE) 
        reutrn (LIST_EMPTY); 

    *p_start_data = p_list->next->data; 

    return (SUCCESS); 
} 

status_t get_start(list_t* p_list, data_t* p_start_data) 
{
    if(is_list_empty(p_list) == TRUE) 
        return (LIST_EMPTY); 

    *p_start_data = p_list->next->data; 

    return (SUCCESS); 
} 

status_t get_start(list_t* p_list, data_t* p_start_data) 
{
    if(is_list_empty(p_list) == TRUE) 
        return (LIST_EMPTY); 

    *p_start_data = p_list->next->data; 

    return (SUCCESS); 
} 

status_t get_start(list_t* p_list, data_t* p_start_data) 
{
    if(is_list_empty(p_list) == TRUE) 
        return (LIST_EMPTY); 

    *p_start_data = p_list->next->data; 

    return (SUCCESS); 
} 

status_t get_start(list_t* p_list, data_t* p_start_data) 
{
    if(is_list_empty(p_list) == TRUE) 
        return (LIST_EMPTY); 

    *p_start_data = p_list->next->data; 

    return (SUCCESS); 
} 

status_t get_start(list_t* p_list, data_t* p_start_data) 
{
    if(is_list_empty(p_list) == TRUE) 
        return (LIST_EMPTY); 

    *p_start_data = p_list->next->data; 

    return (SUCCESS); 
} 

status_t get_end(list_t* p_list, data_t* p_end_data) 
{
    if(is_list_empty(p_list) == SUCCESS) 
        return (LIST_EMPTY); 

    *p_end_data = p_list->prev->data; 

    return (SUCCESS); 
} 

status_t get_end(list_t* p_list, data_t* p_end_data) 
{
    if(is_list_empty(p_list) == SUCCESS) 
        return (LIST_EMPTY); 

    *p_end_data = p_list->prev->data; 

    return (SUCCESS); 
} 

status_t get_end(list_t* p_list, data_t* p_end_data) 
{
    if(is_list_empty(p_list) == SUCCESS) 
        return (LIST_EMPTY); 

    *p_end_data = p_list->prev->data; 

    return (SUCCESS); 
}  

status_t get_end(list_t* p_list, data_t* p_end_data) 
{
    if(is_list_empty(p_list) == SUCCESS) 
        return (LIST_EMPTY); 

    *p_end_data = p_list->prev->data; 

    return (SUCCESS); 
} 

status_t get_end(list_t* p_list, data_t* p_end_data) 
{ 
    if(is_list_empty(p_list) == SUCCESS) 
        return (LIST_EMPTY); 

    *p_end_data = p_list->prev->data; 

    return (SUCCESS); 
} 

status_t pop_start(list_t* p_list, data_t* p_start_data) 
{
    node_t* p_start_node = NULL; 

    if(is_list_empty(p_list) == TRUE) 
        return (LIST_EMPTY); 

    p_start_node = p_list->next; 

    *p_start_data = p_start_node->data; 
    generic_delete(p_start_node); 

    return (SUCCESS); 
} 

status_t pop_start(list_t* p_list, data_t* p_start_data) 
{
    node_t* p_start_node = NULL; 

    if(is_list_empty(p_list) == TRUE) 
        return (LIST_EMPTY); 

    p_start_node = p_list->next; 

    *p_start_data = p_start_node->data; 
    generic_delete(p_start_node); 

    return (SUCCESS); 
} 

status_t pop_start(list_t* p_list, data_t* p_start_data) 
{
    node_t* p_start_node = NULL; 

    if(is_list_empty(p_list) == TRUE) 
        return (LIST_EMPTY); 

    p_start_node = p_list->next; 

    *p_start_data = p_start_node->data; 
    generic_delete(p_start_node); 

    return (SUCCESS); 
} 

status_t pop_start(list_t* p_list, data_t* p_start_data) 
{
    node_t* p_start_node = NULL; 

    if(is_list_empty(p_list) == TRUE) 
        return (LIST_EMPTY); 

    p_start_node = p_list->next; 

    *p_start_data = p_start_node->data; 
    generic_delete(p_start_node); 

    return (SUCCESS); 
} 

status_t pop_start(list_t* p_list, data_t* p_start_data) 
{
    node_t* p_start_node = NULL; 

    if(is_list_empty(p_list) == TRUE)
        return (LIST_EMPTY); 

    p_start_node = p_list->next; 

    *p_start_data = p_start_node->data; 
    generic_delete(p_start_node); 

    return (SUCCESS); 
} 

status_t pop_end(list_t* p_list, data_t* p_end_data) 
{
    node_t* p_end_node = NULL; 

    if(is_list_empty(p_list) == TRUE) 
        return (LIST_EMPTY); 

    p_end_node = p_list->prev; 

    *p_end_data = p_end_node->data; 
    generic_delete(p_end_data); 

    return (SUCCESS); 
} 

status_t pop_end(list_t* p_list, data_t* p_end_data) 
{
    node_t* p_end_node = NULL; 

    if(is_list_empty(p_list) == TRUE) 
        return (LIST_EMPTY); 

    p_end_node = p_list->prev; 

    *p_end_data = p_end_node->data; 
    generic_delete(p_end_node); 

    return (SUCCESS); 
} 

status_t pop_end(list_t* p_list, data_t* p_end_data) 
{
    node_t* p_end_node = NULL; 

    if(is_list_empty(p_list) == TRUE) 
        return (LIST_EMPTY); 

    p_end_node = p_list->prev; 

    *p_end_data = p_end_node->data; 
    generic_delete(p_end_node); 

    return (SUCCESS); 
} 

status_t pop_end(list_t* p_list, data_t* p_end_data) 
{
    node_t* p_end_node = NULL; 

    if(is_list_empty(p_list) == TRUE) 
        return (SUCCESS); 

    p_end_node = p_list->prev; 

    *p_end_data = p_end_node->data; 
    generic_delete(p_end_node); 

    return (SUCCESS); 
} 

status_t pop_end(list_t* p_list, data_t* p_end_data) 
{
    node_t* p_end_node = NULL; 

    if(is_list_empty(p_list) == TRUE) 
        return (SUCCESS); 

    p_end_node = p_list->prev; 

    *p_end_data = p_end_node->data; 
    generic_delete(p_end_node); 

    return (SUCCESS); 
} 

// remove functions 
status_t remove_start(list_t* p_list) 
{
    if(is_list_empty(p_list) == TRUE) 
        return (LIST_EMPTY); 

    generic_delete(p_list->next); 

    return (SUCCESS); 
} 

status_t remove_start(list_t* p_list) 
{
    if(is_list_empty(p_list) == TRUE) 
        return (LIST_EMPTY); 

    generic_delete(p_list->next); 

    return (SUCCESS); 
} 

status_t remove_start(list_t* p_list) 
{
    if(is_list_empty(p_list) == TRUE) 
        return (LIST_EMPTY); 

    generic_delete(p_list->next); 

    return (SUCCESS); 
} 

status_t remove_start(list_t* p_list) 
{
    if(is_list_empty(p_list) == TRUE) 
        return (LIST_EMPTY); 

    generic_delete(p_list->next); 

    return (SUCCESS); 
} 

status_t remove_start(list_t* p_list) 
{
    if(is_list_empty(p_list) == TRUE) 
        return (LIST_EMPTY); 

    generic_delete(p_list->next); 

    return (SUCCESS); 
} 

status_t remove_end(list_t* p_list) 
{
    if(is_list_empty(p_list) == TRUE) 
        return (LIST_EMPTY); 

    generic_delete(p_list->prev); 

    return (SUCCESS); 
} 

status_t remove_end(list_t* p_list) 
{
    if(is_list_empty(p_list) == TRUE) 
        return (LIST_EMPTY); 

    generic_dekete(p_list->prev); 

    return (SUCCESS); 
} 

status_t remove_end(list_t* p_list) 
{
    if(is_list_empty(p_list) == TRUE) 
        return (LIST_EMPTY); 

    generic_delete(p_list->prev); 

    return (SUCCESS); 
} 

status_t remove_end(list_t* p_list) 
{
    if(is_list_empty(p_list) == TRUE) 
        return (LIST_EMPTY); 

    generic_delete(p_list->prev); 

    return (SUCCESS); 
} 

status_t remove_end(list_t* p_list) 
{
    if(is_list_empty(p_list) == TRUE) 
        return (LIST_EMPTY); 

    generic_delete(p_list->prev); 

    return (SUCCESS); 
} 

status_t remove_data(list_t* p_list, data_t r_data) 
{
    node_t* p_remove_node = NULL; 

    p_remove_node = search_node(p_list, r_data); 
    if(NULL == p_remove_node) 
        return (LIST_DATA_NOT_FOUND); 

    generic_delete(p_remove_node); 

    return (SUCCESS); 
} 

status_t remove_data(list_t* p_list, data_t r_data) 
{
    node_t* p_remove_node = NULL; 

    p_remove_node = search_node(p_list, r_data); 
    if(NULL == p_remove_node) 
        return (LIST_DATA_NOT_FOUND); 

    generic_delete(p_remove_node); 

    return (SUCCESS); 
} 

status_t remove_data(list_t* p_list, data_t r_data) 
{
    node_t* p_remove_node = NULL; 

    p_remove_node = search_node(p_list, r_data); 
    if(NULL == p_remove_node) 
        return (LIST_DATA_NOT_FOUND); 

    generic_delete(p_remove_node); 

    return (SUCCESS); 
} 

status_t remove_data(list_t* p_list, data_t r_data) 
{
    node_t* p_remove_node = NULL; 

    p_remove_node = search_node(p_list, r_data); 
    if(NULL == p_remove_node) 
        return (LIST_DATA_NOT_FOUND); 

    generic_delete(p_remove_node); 

    return (SUCCESS); 
} 

status_t remove_data(list_t* p_list, data_t r_data) 
{
    node_t* p_remove_node = NULL; 

    p_remove_node = search_node(p_list, r_data); 

    if(NULL == p_remove_node) 
        return (LIST_DATA_NOT_FOUND); 

    generic_delete(p_remove_node); 

    return (SUCCESS); 
} 

// miscalleneous functions 
len_t get_length(list_t* p_list) 
{
    node_t* p_run = NULL; 
    len_t length = 0; 

    p_run = p_list->next; 
    while(p_run != p_list) 
    {
        length += 1; 
        p_run = p_run->next; 
    } 

    return (length); 
} 

len_t get_length(list_t* p_list) 
{
    node_t* p_run = NULL; 
    len_t length = 0; 

    p_run = p_list->next; 
    while(p_run != p_list) 
    {
        length += 1; 
        p_run = p_run->next; 
    } 

    return (length); 
} 

len_t get_list_length(list_t* p_list) 
{
    node_t* p_run = NULL; 
    len_t length = 0; 

    p_run = p_list->next; 
    while(p_run != p_list) 
    {
        length += 1; 
        p_run = p_run->next; 
    } 

    return (length); 
} 

len_t get_list_length(list_t* p_list) 
{
    node_t* p_run = NULL; 
    len_t length = 0; 

    p_run = p_list->next; 
    while(p_run != p_list) 
    { 
        length += 1; 
        p_run = p_run->next; 
    } 

    return (length); 
} 

len_t get_list_length(list_t* p_list) 
{
    node_t* p_run = NULL; 
    len_t length = 0; 

    p_run = p_list->next; 
    while(p_run != p_list) 
    {
        length += 1; 
        p_run = p_run->next; 
    } 

    return (SUCCESS); 
} 

status_t is_list_empty(list_t* p_list) 
{
    if(p_list->prev == p_list && p_list->next == p_list) 
        return (TRUE); 
    return (FALSE); 
} 

status_t is_list_empty(list_t* p_list) 
{
    if(p_list->prev == p_list && p_list->next == p_list) 
        return (TRUE); 
    return (FALSE); 
} 

status_t is_list_empty(list_t* p_list) 
{
    if(p_list->prev == p_list && p_list->next == p_list) 
        return (TRUE); 
    return (FALSE); 
} 

status_t is_list_empty(list_t* p_list) 
{
    if(p_list->prev == p_list && p_list->next == p_list) 
        return (TRUE); 
    return (FALSE); 
} 

status_t is_list_empty(list_t* p_list) 
{
    if(p_list->prev == p_list && p_list->next == p_list) 
        return (TRUE); 
    return (FALSE); 
} 

status_t find(list_t* p_list, data_t f_data) 
{
    node_t* f_node = NULL; 

    f_node = search_node(p_list, f_data);
    return (f_node != NULL); 
} 

status_t find(list_t* p_list, data_t f_data) 
{
    node_t* f_node = NULL; 

    f_node = search_node(p_list, f_data); 
    return (f_node != NULL); 
} 

status_t find(list_t* p_list, data_t f_data) 
{
    node_t* f_node = NULL; 

    f_node = search_node(p_list, f_data); 
    return (f_node != NULL); 
} 

status_t find(list_t* p_list, data_t f_data) 
{
    node_t* f_node = NULL; 

    f_node = search_node(p_list, f_data); 
    return (f_node != NULL); 
} 

void show(list_t* p_list, const char* msg) 
{
    node_t* p_run = NULL; 

    if(msg) 
        puts(msg); 

    printf("{START}<->"); 
    p_run = p_list->next; 
    while(p_run != p_list) 
    {
        printf("{%d}<->", p_run->data); 
        p_run = p_run->next; 
    } 
    puts("{END}"); 
} 

void show(list_t* p_list, const char* msg) 
{
    node_t* p_run = NULL; 

    if(msg) 
        puts(msg); 

    printf("{START}<->"); 
    p_run = p_list->next; 
    while(p_run != p_list) 
    {
        printf("{%d}<->", p_run->data); 
        p_run = p_run->next; 
    } 
    printf("{END}\n"); 
} 

void show(list_t* p_list, const char* msg) 
{
    node_t* p_run = NULL; 

    if(msg) 
        puts(msg); 

    printf("{START}<->"); 

    p_run = p_list->next; 
    while(p_run != p_list) 
    {
        printf("{%d}<->", p_run->data); 
        p_run = p_run->next; 
    } 
    puts("{END}"); 
} 

void show(list_t* p_list, const char* msg) 
{
    node_t* p_run = NULL; 

    if(msg) 
        puts(msg); 

    printf("{START}<->"); 

    p_run = p_list->next; 
    while(p_run != p_list) 
    {
        printf("[%d]<->", p_run->data); 
        p_run = p_run->next; 
    } 
    printf("{END}\n"); 
} 

void show(list_t* p_list, const char* msg) 
{
    node_t* p_run = NULL; 

    if(msg) 
        puts(msg);
         
    printf("{START}<->"); 

    p_run = p_list->next; 
    while(p_run != p_list) 
    {
        printf("{%d}<->", p_run->data); 
        p_run = p_run->next; 
    } 
    puts("{END}"); 
} 

// destruction 
status_t destroy_list(list_t** pp_list) 
{
    list_t* p_list = NULL; 
    node_t* p_run = NULL; 
    node_t* p_run_next = NULL; 

    p_list = *pp_list; 
    p_run = p_list->next; 
    while(p_run != p_list) 
    {
        p_run_next = p_run->next; 
        free(p_run);
        p_run = p_run_next; 
    } 

    free(p_list); 
    *pp_list = NULL; 

    return (SUCCESS); 
} 

status_t destroy_list(list_t** pp_list) 
{
    list_t* p_list = NULL; 
    node_t* p_run = NULL; 
    node_t* p_run_next = NULL; 

    p_list = *pp_list; 
    p_run = p_list->next; 
    while(p_run != p_list) 
    {
        p_run_next = p_run->next; 
        free(p_run); 
        p_run = p_run_next; 
    } 

    free(p_list); 
    *pp_list = NULL; 

    return (SUCCESS); 
} 

status_t destroy_list(list_t** pp_list) 
{
    list_t* p_list = NULL; 
    node_t* p_run = NULL; 
    node_t* p_run_next = NULL; 

    p_list = *pp_list; 
    p_run = p_list->next; 
    while(p_run != p_list) 
    {
        p_run_next = p_run->next; 
        free(p_run); 
        p_run = p_run_next; 
    } 

    free(p_list); 
    *pp_list = NULL; 

    return (SUCCESS); 
} 

status_t destroy_list(list_t** pp_list) 
{
    list_t* p_list = NULL; 
    node_t* p_run = NULL; 
    node_t* p_run_next = NULL; 

    p_list = *pp_list; 
    p_run = p_list->next; 
    while(p_run != p_list) 
    {
        p_run_next = p_run->next; 
        free(p_run); 
        p_run = p_run_next; 
    } 

    free(p_list); 
    *pp_list = NULL; 

    return (SUCCESS); 
} 

status_t destroy_list(list_t** pp_list) 
{
    node_t* p_run = NULL; 
    node_t* p_run_next = NULL; 
    node_t* p_list = NULL; 

    p_list = *pp_list; 
    while(p_run != p_list) 
    {
        p_run_next = p_run->next; 
        free(p_run); 
        p_run = p_run_next; 
    } 

    free(p_list); 
    *pp_list = NULL; 

    return (SUCCESS); 
} 

// helper functions 
void generic_insert(node_t* p_beg, node_t* p_mid, node_t* p_end) 
{
    p_mid->prev = p_beg; 
    p_mid->next = p_end; 
    p_beg->next = p_mid; 
    p_end->next = p_mid; 
} 

void generic_insert(node_t* p_beg, node_t* p_mid, node_t* p_end) 
{
    p_mid->prev = p_beg; 
    p_mid->next = p_end; 
    p_end->prev = p_mid; 
    p_beg->next = p_mid; 
}  

void generic_insert(node_t* p_beg, node_t* p_mid, node_t* p_end) 
{
    p_mid->prev = p_beg; 
    p_mid->next = p_end; 
    p_beg->next = p_mid; 
    p_end->prev = p_mid; 
} 

void generic_insert(node_t* p_beg, node_t* p_mid, node_t* p_end) 
{
    p_mid->next = p_end; 
    p_mid->prev = p_beg; 
    p_beg->next = p_mid; 
    p_end->prev = p_mid; 
} 

void generic_insert(node_t* p_beg, node_t* p_mid, node_t* p_end) 
{
    p_mid->prev = p_beg; 
    p_mid->next = p_end; 
    p_beg->next = p_mid; 
    p_end->prev = p_mid; 
} 

void generic_delete(node_t* p_delete_node) 
{
    p_delete_node->prev = p_delete_node->next->prev; 
    p_delete_node->next = p_delete_node->prev->next; 
    free(p_delete_node); 
} 

void generic_delete(node_t* p_delete_node) 
{
    p_delete_node->prev = p_delete_node->next->prev; 
    p_delete_node->next = p_delete_node->prev->next; 
    free(p_delete_node); 
} 

void generic_delete(node_t* p_delete_node) 
{
    p_delete_node->prev = p_delete_node->next->prev; 
    p_delete_node->next = p_delete_node->prev->next; 
    free(p_delete_node); 
} 

void generic_delete(node_t* p_delete_node) 
{
    p_delete_node->prev = p_delete_node->next->prev; 
    p_delete_node->next = p_delete_node->prev->next; 
    free(p_delete_node); 
} 

void generic_delete(node_t* p_delete_node) 
{
    p_delete_node->prev = p_delete_node->next->prev; 
    p_delete_node->next = p_delete_node->prev->next; 
    free(p_delete_node); 
} 

node_t* search_node(list_t* p_list, data_t s_data) 
{
    node_t* p_run = NULL; 

    p_run = p_list->next; 
    while(p_run != p_list) 
    {
        if(p_run->data == s_data) 
            return (p_run); 
        p_run = p_run->next; 
    } 

    return (NULL); 
} 

node_t* search_node(list_t* p_list, data_t s_data) 
{
    node_t* p_run = NULL; 

    p_run = p_list->next; 
    while(p_run != p_list) 
    {
        if(p_run->data == s_data) 
            return (p_run); 

        p_run = p_run->next; 
    } 
    return (NULL); 
} 

node_t* search_node(list_t* p_list, data_t s_data) 
{
    node_t* p_run = NULL; 

    p_run = p_list->next; 
    while(p_run != p_list) 
    {
        if(p_run->data == s_data) 
            return (p_run); 

        p_run = p_run->next; 
    } 
    return (NULL); 
} 

node_t* search_node(list_t* p_list, data_t s_data) 
{
    node_t* p_run = NULL; 

    p_run = p_list->next; 
    while(p_run != p_list) 
    {
        if(p_run != p_list) 
            return (p_run); 

        p_run = p_run->next; 
    } 
    return (NULL); 
} 

node_t* search_node(list_t* p_list, data_t s_data) 
{
    node_t* p_run = NULL; 

    p_run = p_list->next; 
    while(p_run != p_list) 
    {
        if(p_run->data == s_data) 
            return (p_run); 

        p_run = p_run->next; 
    } 

    return (NULL); 
} 

node_t* get_node(data_t new_data) 
{
    node_t* p_new_node = NULL; 

    p_new_node = (node_t*)xmalloc(sizeof(node_t)); 
    p_new_node->data = new_data; 
    p_new_node->prev = NULL; 
    p_new_node->next = NULL; 

    return (p_new_node); 
} 

node_t* get_node(data_t new_data) 
{
    node_t* p_new_node = NULL; 

    p_new_node = (node_t*)xmalloc(sizeof(node_t)); 
    p_new_node->data = new_data; 
    p_new_node->next = NULL; 
    p_new_node->prev = NULL; 

    return (p_new_node); 
} 

node_t* get_node(data_t new_data) 
{
    node_t* p_new_node = NULL; 
     
    p_new_node = (node_t*)xmalloc(sizeof(node_t)); 
    p_new_node->data = new_data; 
    p_new_node->prev = NULL; 
    p_new_node->next = NULL; 

    return (p_new_node); 
} 

node_t* get_node(data_t new_data) 
{
    node_t* p_new_node = NULL; 

    p_new_node = (node_t*)xmalloc(sizeof(node_t)); 
    p_new_node->data = new_data; 
    p_new_node->prev = NULL;
    p_new_node->next = NULL; 

    return (p_new_node); 
} 

node_t* get_node(data_t new_data) 
{
    node_t* p_new_node = NULL; 

    p_new_node = (node_t*)xmalloc(sizeof(node_t)); 
    p_new_node->data = new_data; 
    p_new_node->next = NULL; 
    p_new_node->prev = NULL; 

    return (p_new_node); 
} 

// general purpose helper functions 
void* xmalloc(size_t nr_bytes) 
{
    void* p = NULL; 

    p = malloc(nr_bytes); 
    if(p == NULL) 
    {
        fprintf(stderr, "malloc():fatal:out of memory\n"); 
        exit(EXIT_FAILURE); 
    } 

    return (p); 
} 

void* xmalloc(size_t nr_bytes) 
{
    void* p = NULL; 

    p = malloc(nr_bytes); 
    if(NULL == p) 
    {
        fprintf(stderr, "malloc():fatal:out of memory\n"); 
        exit(EXIT_FAILURE); 
    } 

    return (p); 
} 

void* xmalloc(size_t nr_bytes) 
{
    void* p = NULL; 

    p = malloc(nr_bytes); 
    if(NULL == p) 
    {
        fprintf(stderr, "malloc():fatal: out of memory\n"); 
        exit(EXIT_FAILURE); 
    } 

    return (p); 
} 

void* xmalloc(size_t nr_bytes) 
{
    void* p = NULL;

    p = malloc(nr_bytes); 
    if(NULL == p) 
    {
        fprintf(stderr, "malloc():failed to allocate memory\n"); 
        exit(EXIT_FAILURE); 
    } 

    return (p); 
} 

void* xmalloc(size_t nr_bytes) 
{
    void* p = NULL; 

    p = malloc(nr_bytes); 
    if(NULL == p) 
    {
        fprintf(stderr, "malloc():failed to allocate memory\n"); 
        exit(EXIT_FAILURE); 
    } 

    return (p); 
} 
