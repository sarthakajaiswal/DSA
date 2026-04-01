struct node 
{
    int data; 
    struct node* prev; 
    struct node* next; 
}; 

/* 
    Description: 
        @input: 
            @data: new data value 
            @return: address of newly and dynamically aloocated instance of struct node 
                    whose data member is initialized by parameter @data 
                    prev and next links should be initialized to zero.  
*/ 
struct node* get_node(int new_data); 

/* 
    Description: 
        @start_node and @end_node are adjescent in a double linked list
        @mid_nde is a newly allocated node which is not a part of any linked list 

        Insert node pointed by @mid_node between the nodes pointer by @start_node and 
        @end_node. 

        Also handle the following cases: 
        end_node may be NULL. 
        start_node NEVER NULL.  
*/ 
void generic_insert(struct node* start_node, struct node* mid_node, struct node* end_node); 

/* 
    Description: 
        @delete_node pointe to a NON_DUMMY node in a linked list 
        (to be explicit delete_node != head_node)
        
        The function should detach node pointed by @delete_node from the 
        linked list and release its memory. The function should do these activities
        in such a way that rest of nodes in linked list remain intact. 
*/ 
void generic_delete(struct node* delete_node); 

/* 
    Desription: 
        searcg for search_data in linked list pointed by 
        @head_node 

        The function should return first node having occurence of search_data 
        if @search_data is not present in any of the node then NULL should be returned. 
*/ 
struct node* search_node(struct node* head_node, int search_data); 

