// Array to list conversion 
// prototype1 
list_t* to_list(data_t* p_array, len_t array_length); 

void test(void) 
{
    list_t* p_list = NULL; 

    data_t* p_array = NULL; 
    len_t array_len = 0; 

    // allocate and populate the array 
    p_list = to_list(p_array, array_len); 
} 

// prototype2 
status_t to_list(data_t* p_array, len_t array_len, list_t** pp_list); 

void test(void) 
{
    list_t* p_list = NULL; 

    data_t* p_array = NULL; 
    len_t array_len = 0; 

    // allocate and populate the array 
    status_t status = to_list(p_array, array_len, &p_list); 
}

// Linked list reversal 
// version1 
// prototype1 
list_t* get_reversed_list(list_t* p_list); 

void test(void) 
{
    list_t* p_reversed_list = NULL; 
    list_t* p_list = NULL; 

    // create and populate p_list 
    p_reversed_list = get_reversed_list(p_list); 
} 

// prototype2 
status_t get_reversed_list(list_t* p_list, list_t** pp_reversed_list) 

void test(void) 
{
    list_t* p_list = NULL; 
    list_t* p_reversed_list = NULL; 
    status_t status; 
    
    status = get_reversed_list(p_list, &reversed_list); 
} 

// Version2 
status_t reverse_list(list_t* p_list) 
 
void test(void) 
{
    struct node* p_list = NULL; 
    
    // create and populate list 
    status_t status = reverse_list(p_list); 
} 

