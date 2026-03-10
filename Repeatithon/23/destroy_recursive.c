void destroy(list_t* p_list, node_t* p_node) 
{
    node_t* p_node_prev = NULL; 

    if(p_node == p_list) 
    {
        free(p_node); 
        return; 
    } 
    p_node_prev = p_node->prev; 
    free(p_node); 
    destroy(p_list, p_node_prev); 
} 

void destroy_list(list_t* p_list, node_t* p_node) 
{
    node_t* p_node_prev = NULL; 

    if(p_node == p_list) 
    {
        free(p_list); 
        return; 
    } 

    p_node_prev = p_node->prev; 
    free(p_node); 
    destroy_list(p_list, p_node_prev); 
} 

void destroy_list(list_t* p_list, node_t* p_node) 
{
    node_t* p_node_prev = NULL; 

    if(p_node == p_list) 
    {
        free(p_list); 
        return; 
    } 

    p_node_prev = p_node->prev; 
    free(p_node); 
    destroy_list(p_list, p_node_prev); 
} 

void destroy_list(list_t* p_list, node_t* p_node) 
{
    node_t* p_node_prev = NULL; 

    if(p_node == p_list) 
    {
        free(p_list); 
        return; 
    } 

    p_node_prev = p_node->prev; 
    free(p_node); 
    destroy_list(p_list, p_node_prev); 
} 

void destroy_list(list_t* p_list, node_t* p_node) 
{
    node_t* p_node_prev = NULL; 

    if(p_node == p_list) 
    {
        free(p_list); 
        return; 
    } 

    p_node_prev = p_node->prev; 
    free(p_node); 
    destroy_list(p_list, p_node_prev); 
} 

void destroy_list(list_t* p_list, node_t* p_node) 
{
    node_t* p_run_prev = NULL; 

    if(p_node == p_list) 
    {
        free(p_node); 
        return; 
    } 

    p_run_prev = p_node->prev; 
    free(p_node); 
    destroy_list(p_list, p_run_prev); 
} 

// trigger call: 
destroy_list(p_list, p_list->prev); 
destroy_list(p_list, p_list->prev); 
destroy_list(p_list, p_list->prev); 
destroy_list(p_list, p_list->prev); 
destroy_list(p_list, p_list->prev); 
destroy_list(p_list, p_list->prev); 


