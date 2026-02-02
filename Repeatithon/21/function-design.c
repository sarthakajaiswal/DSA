void get_last_node(list_t* p_list, list_t** pp_list) 
{
    struct node* run = NULL; 

    run = p_list; 
    while(run->next != NULL) 
        run = run->next; 

    *pp_list = run; 
} 

void insert_end(void) 
{
    struct node* p_list; 
    struct node* last_node = NULL; 

    get_last_node(p_list, &last_node); 
    generic_insert(last_node, get_node(data), last_node->next); 
} 

// ====================== 

void get_last_node(list_t* p_list, list_t** pp_list) 
{
    node_t* run = NULL; 
    run = p_list; 
    while(run->next != NULL) 
        run = run->next; 

    *pp_list = run; 
} 

void insert_end(void) 
{
    struct node* p_list; 
    struct node* last_node = NULL; 

    get_last_node(p_list, &last_node); 
    generic_insert(last_node, get_node(data), last_node->next); 
} 

// ===================== 

void get_last_node(list_t* p_list, list_t** pp_list) 
{
    node_t* run = NULL; 

    run = p_list; 
    while(run->next != NULL) 
        run = run->next; 

    *pp_list = run; 
} 

void insert_end(void)
{
    list_t* list = NULL; 
    node_t* last_node = NULL; 

    get_last_node(list, &last_node); 
    insert_end(last_node, get_node(data), last_node->next); 
} 

//========== 

void get_last_node(list_t* p_list, node_t** pp_list) 
{
    node_t* run = NULL; 

    run = p_list; 
    while(run->next != NULL) 
        run = run->next; 

    *pp_list = run; 
} 

void insert_end(list_t* p_list, data_t new_data) 
{
    node_t* last_node = NULL; 

    get_last_node(p_list, &last_node); 
    generic_insert(last_node, get_new_node(new_data), last_node->next); 
}  

// ====== 

void get_last_node(list_t* p_list, list_t** pp_list) 
{
    node_t* run = NULL; 

    run = p_list; 
    while(run->next != NULL) 
        run = run->next; 
    
    *pp_list = run; 
} 

void insert_end(list_t* p_list, data_t new_data) 
{
    node_t* last_node = NULL; 

    get_last_node(p_list, &last_node); 
    generic_insert(last_node, get_new_node(new_data), last_node->next); 
} 

//========================== 
void get_last_node_and_its_predecessor(list_t* p_list, node_t* pp_second_last_node, node_t** pp_last_node) 
{
    node_t* run = NULL; 
    node_t* run_prev = NULL; 

    run = p_list; 
    while(run->next != NULL) 
    {
        run_prev = run; 
        run = run->next; 
    } 

    *pp_last_node = run; 
    *pp_second_last_node = run_prev; 
} 

void caller() 
{
    node_t* p_last_node = NULL; 
    node_t* p_second_last_node = NULL; 

    get_last_node_and_its_predecessor(p_list, &p_second_last_node, &p_last_node); 
} 

// 2 
void get_last_node_and_predecessor(list_t* p_list, node_t** pp_last_second_node, node_t** pp_last_node) 
{
    node_t* run = NULL; 
    node_t* run_prev = NULL; 

    run = p_list; 
    while(run->next != NULL) 
    {
        run_prev = run; 
        run = run->next; 
    } 

    *pp_last_node = run; 
    *pp_last_second_node = run_prev; 
} 

void caller() 
{
    list_t* list; 
    node_t* last_node = NULL, *last_second_node = NULL; 

    get_last_node_and_predecessor(p_list, &last_second_node, &last_node); 
} 

// 3 
void get_last_node_and_predecessor(list_t* p_list, node_t** pp_second_last_node, node_t** pp_last_node) 
{
    node_t* run = NULL; 
    node_t* run_prev = NULL; 

    run = p_list; 
    while(run != NULL) 
    {
        run_prev = run; 
        run = run->next; 
    } 

    *pp_last_node = run; 
    *pp_second_last_node = run_prev; 
} 

void caller() 
{
    list_t* p_list; 
    node_t* last_node = NULL; 
    node_t* second_last_node = NULL; 

    get_last_node_and_predecessor(p_list, &second_last_node, &last_node); 
} 

// 4 
void get_last_node_and_predecessor(list_t* p_list, node_t** pp_last_node, node_t** pp_second_last_node) 
{
    node_t* run = NULL; 
    node_t* run_prev = NULL; 

    run = p_list; 
    while(run->next != NULL) 
    {
        run_prev = run; 
        run = run->next; 
    } 

    *pp_last_node = run; 
    *pp_second_last_node = run_prev; 
} 

void caller() 
{
    list_t* p_list; 
    node_t* last_node = NULL; 
    node_t* second_last_node = NULL; 
    get_last_node_and_predecessor(p_list, &second_last_node, &last_node); 
} 

// ================ 
void get_node_with_data_and_its_predecessor(
    list_t* p_list, 
    data_t existing_data, 
    node_t** pp_existing_node, 
    node_t** pp_existing_node_previous 
) 
{
    node_t* run = NULL;
    node_t* run_prev = NULL; 

    run = p_list->next; 
    while(run != NULL) 
    {
        if(run->data == existing_data) 
        {
            *pp_existing_node = run; 
            *pp_existing_node_previous = run_prev; 
            return; 
        } 

        run_prev = run; 
        run = run->next; 
    } 

    *pp_existing_node = NULL; 
    *pp_existing_node_previous = NULL; 
} 

void caller(void) 
{
    node_t* existing_node = NULL; 
    node_t* existing_node_prev = NULL; 

    get_node_with_data_and_its_predecessor(p_list, 100, &p_existing_node_prev, &p_existing_node); 
} 

// 2 
void get_node_with_data_and_its_predecessor(
    list_t* p_list, 
    data_t existing_data, 
    node_t** pp_existing_data, 
    node_t** pp_existing_data_previous 
) 
{
    node_t* run = NULL; 
    node_t* run_prev = NULL; 

    run = p_list->next; 
    while(run != NULL) 
    {
        run_prev = run; 
        run = run->next; 
    } 

    *pp_existing_data = NULL; 
    *pp_existing_data_previous = NULL; 
} 

void caller(void) 
{
    node_t* existing_node = NULL; 
    node_t* existing_node_previous = NULL; 

    get_last_node_and_its_predecessor(p_list, 100, &existing_node, &existing_node_previous); 
} 

// 3 
void get_node_with_data_and_predecessor(llist_t* p_list, data_t existing_data, node_t** pp_existing_node, node_t** pp_existing_node_previous) 
{
    node_t* run = NULL; 
    node_t* run_prev = NULL; 

    run = p_list->next; 
    while(run != NULL) 
    {
        if(run->data == existing_data) 
        {
            *pp_existing_node = run; 
            *pp_existing_node_previous = run_prev; 
            return ; 
        } 

        run_prev = run; 
        run = run->next; 
    } 

    *pp_existing_node = NULL; 
    *pp_existing_node_previous = NULL; 
} 

void caller(void) 
{
    node_t* existing_node = NULL; 
    node_t* existing_node_previous = NULL; 

    get_last_node_and_its_predecessor(p_list, 100, &existing_node_previous, &existing_node); 
} 

// 4 
void get_last_node_and_its_predecessor(
    list_t* p_list,
    data_t existing_data, 
    node_t** pp_last_node_previous, 
    node_t** pp_last_node
) 
{
    node_t* run = NULL; 
    
    run = p_list; 
    while(run != NULL) 
    {
        if(run->data = existing_data) 
        {
            *pp_existing_node = run; 
            *pp_existing_node_previous = run_prev; 
            return; 
        } 

        run_prev = run; 
        run = run->next; 
    } 

    *pp_existing_node = NULL; 
    *pp_existing_node_previous = NULL; 
}  

void caller(void) 
{
    node_t* existing_node = NULL; 
    node_t* existing_node_previous = NULL; 

    get_last_node_and_its_predecessor(p_list, 100, &existing_node, &existing_node_previous); 
} 

// 5 
void get_last_node_with_data_and_its_predecessor(
    list_t* p_list, 
    data_t existing_data, 
    node_t** pp_existing_node, 
    node_t** pp_existing_node_prev 
) 
{
    node_t* run = NULL; 
    node_t* run_prev = NULL; 

    run = p_list->next; 
    while(run != NULL) 
    {
        if(run->data == existing_data) 
        {
            *pp_existing_node = run; 
            *pp_existing_node_previous = run_prev; 
            return; 
        } 

        run_prev = run; 
        run = run->next; 
    } 

    *pp_existing_node = NULL; 
    *pp_existing_node_previous = NULL; 
} 

void caller(void) 
{
    node_t* existing_node = NULL; 
    node_t* existing_node_previous = NULL; 

    get_last_node_and_its_predecessor(p_list, 100, &existing_node, &existing_node_previous); 
} 



