/*
    @GOAL: To do repeatithon of pop_start() and pop_end() 
    @DATE: 23 Nov 2025
    @AUTHOR: Sarthak A. Jaiswal 
*/

int pop_start(struct node* p_list, int* p_start_data) 
{
    struct node* delete_previous = NULL; 
    struct node* delete_node = NULL; 
    struct node* delete_next = NULL; 

    if(p_list->next == NULL) 
        return (LIST_EMPTY);  

    *p_start_data = p_list->next->data; 

    delete_previous = p_list; 
    delete_node = p_list->next; 
    delete_next = p_list->next->next; 

    delete_previous->next = delete_node; 

    free(delete_node); 
    delete_node = NULL; 

    return (SUCCESS); 
} 

int pop_start(struct node* p_list, int* p_start_data) 
{
    struct node* delete_previous = NULL; 
    struct node* delete_node = NULL; 
    struct node* delete_next = NULL; 

    if(p_list->next == NULL) 
        return (LIST_EMPTY); 

    *p_start_data = p_list->next->data; 

    delete_previous = p_list; 
    delete_node = p_list->next; 
    delete_next = p_list->next->next; 

    delete_previous->next = delete_next; 

    free(delete_node); 
    delete_node = NULL; 

    return (SUCCESS); 
} 

int pop_start(struct node* p_list, int* p_start_data) 
{
    struct node* delete_previous = NULL; 
    struct node* delete_node = NULL; 
    struct node* delete_next = NULL; 

    if(p_list->next == NULL) 
        return (LIST_EMPTY); 

    *p_start_data = p_list->next->data; 

    delete_previous = p_list; 
    delete_node = p_list->next; 
    delete_next = p_list->next->next; 

    delete_previous->next = delete_node; 

    free(delete_node); 
    delete_node = NULL; 
} 

int pop_start(struct node* p_list, int* p_start_data) 
{
    struct node* delete_previous = NULL; 
    struct node* delete_node = NULL; 
    struct node* delete_next = NULL; 

    if(p_list->next == NULL)
        return (LIST_EMPTY); 

    *p_start_data = p_list->next->data; 

    delete_previous = p_list; 
    delete_node = p_list->next; 
    delete_next = p_list->next->next; 

    delete_previous->next = delete_next; 

    free(delete_node); 
    delete_node = NULL; 

    return (SUCCESS); 
} 

int pop_start(struct node* p_list, int* p_start_data) 
{
    struct node* delete_previous = NULL; 
    struct node* delete_node = NULL; 
    struct node* delete_next = NULL; 

    if(p_list->next == NULL) 
        return (LIST_EMPTY); 

    *p_start_data = p_list->next->data; 

    delete_previous = p_list; 
    delete_node = p_list->next; 
    delete_next = p_list->next->next; 

    delete_previous->next = delete_next; 

    free(delete_node); 
    delete_node = NULL; 

    return (SUCCESS); 
} 

int pop_end(struct node* p_list, int* p_end_data) 
{
    struct node* run = NULL; 
    struct node* run_previous = NULL; 

    if(p_list->next == NULL) 
        return (LIST_EMPTY); 

    run = p_list->next; 
    run_previous = p_list; 
    while(run->next != NULL) 
    {
        run_previous = run; 
        run = run->next; 
    } 

    *p_end_data = run->data; 
    
    free(run); 
    run = NULL; 
    run_previous->next = NULL; 

    return (SUCCESS); 
} 

int pop_end(struct node* p_list, int* p_end_data) 
{
    struct node* run = NULL; 
    struct node* run_previous = NULL;
     
    if(p_list->next == NULL) 
        return (LIST_EMPTY); 

    run = p_list->next; 
    run_previous = p_list; 
    while(run->next != NULL) 
    {
        run_previous = run; 
        run = run->next; 
    } 

    *p_end_data = run->data; 

    free(run); 
    run = NULL; 
    run_previous->next = NULL; 

    return (SUCCESS); 
} 

int pop_end(struct node* p_list, int* p_end_data) 
{
    struct node* run = NULL; 
    struct node* run_previous = NULL; 

    if(p_list->next == NULL) 
        return (LIST_EMPTY); 

    run = p_list->next; 
    run = p_list; 
    while(p_list->next != NULL) 
    {
        run_previous = run; 
        run = run->next; 
    } 

    *p_end_data = run->data; 

    free(run); 
    run = NULL; 
    run_previous = NULL; 

    return (SUCCESS); 
} 

