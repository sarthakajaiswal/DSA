//  Helper 
//  Doubly linked list 
//  remove_end() | pop_end() | insert_end() 
//  These three functions require an address of the last node. 
//  last node is defined as follows: 
//  if the list is not empty then the last node with data whose next pointer is NULL is the last node. 
//  if the list is empty then the dummy node is the last node. \

//  Design and implement a helper function which fetches the "LAST NODE" of the list (last node is defined in the above sense)
void get_last_node(list_t* p_list, node_t** pp_last_node)
{
    node_t* run = NULL; 

    run = p_list; 
    while(run->next != NULL)
        run = run->next; 

    *pp_last_node = run; 
}

void insert_end(list_t* p_list, data_t new_data)
{
    node_t* p_last_node = NULL; 

    get_last_node(p_list, &p_last_node); 
    generic_insert(p_last_node, get_node(new_data), p_last_node->next);
}


//////////// Helper function for singly linked list/////////////////////
//  In singly linked list, we require last node and its previous node (when the linked list is not empty)
void get_last_node_and_its_predecessor(list_t* p_list, node_t** pp_second_to_last_node, node_t** pp_last_node)
{
    node_t* run = p_list; 
    node_t* run_previous = NULL; 

    while(run->next != NULL)
    {
        run_previous = run; 
        run = run->next; 
    }

    *pp_second_to_last_node = run_previous;  
    *pp_last_node = run; 
}

void caller()
{
    node_t* p_last_node = NULL; 
    node_t* p_second_to_last_node = NULL; 

    get_last_node_and_its_predecessor(p_list, &p_second_to_last_node, &p_last_node); 
    // now 
    p_last_node -> last node in the linked list 
    p_second_to_last_node -> pen-ultimate node in the linked list 
}

//  Sometimes we are require a node having a given data and its previous node. 
void get_node_with_given_data_and_its_predecessor(
        list_t* p_list, 
        data_t existing_data, 
        node_t** pp_existing_node, 
        node_t** pp_existing_node_previous
    )
{
    node_t* run = NULL; 
    node_t* run_previous = NULL; 

    run = p_list->next; 
    while(run != NULL)
    {
        if(run->data == existing_data)
        {
            *pp_existing_node = run; 
            *pp_existing_node_previous = run_previous; 
            return; 
        }
        run_previous = run; 
        run = run->next; 
    }

    *pp_existing_node = NULL; 
    *pp_existing_node_previous = NULL; 
}

void caller() 
{
    node_t* p_existing_node = NULL; 
    node_t* p_existing_node_previous = NULL; 

    get_node_with_given_data_and_its_predecessor(p_list, 100, &p_existing_node, &p_existing_node_previous)
}

//  Design and implement function for each of the above requirement 


// MASSIVE HINT: Node pointer should not be a return value 

int pthread_create(pthread_t* thread_id, pthread_attr_t* thread_attrs, void*(*thread_function)(void*), void* data); 

pthread_join(pthread_t thread_id, void** data); 

void test(void)
{
    pthread_t thread_id; 
    void** data; 

    pthread_create(&thread_id, NULL, thread_function, NULL); 

    pthread_join(thread_id, data);  // ERROR
                                    // You-Know walyanche error 

    void* data = NULL; 
    or 
    T* data = NULL; 

    pthread_join(thread_id, (void**)&data); // MOST PERFECT 
}



