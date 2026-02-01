/*
    @GOAL:      BST implementation 
    @DATE:      31 Jan 2026 
    @AUTHOR:    Sarthak A Jaiswal 
*/ 

#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <assert.h> 
#include <time.h> 

enum status 
{
    SUCCESS                             = 1, 
    TRUE                                = 1, 
    FALSE                               = 0, 
    
    BST_DATA_NOT_FOUND                  = -1, 
    BST_EMPTY                           = -2, 
    BST_NO_INORDER_PREDECESSOR          = -3, 
    BST_NO_INORDER_SUCCESSOR            = -4, 
    BST_NO_PREORDER_PREDECESSOR         = -5, 
    BST_NO_PREORDER_SUCCESSOR           = -6, 
    BST_NO_POSTORDER_PREDECESSOR        = -7, 
    BST_NO_POSTORDER_SUCCESSOR          = -8, 

    STACK_EMPTY                         = -11, 
    
    LIST_EMPTY                          = -21, 
}; 

typedef enum status         status_t; 
typedef struct bst_node     bst_node_t; 
typedef struct bst          bst_t; 
typedef struct bstptr_node  bstptr_node_t; 
typedef bstptr_node_t       bstptr_list_t; 
typedef bstptr_list_t       bstptr_stack_t; 
typedef int                 data_t; 

struct bst_node 
{
    data_t data; 
    struct bst_node* parent; 
    struct bst_node* left; 
    struct bst_node* right; 
}; 

struct bst 
{
    struct bst_node* root_node; 
    size_t nr_elements; 
};  

struct bstptr_node 
{
    bst_node_t* data; 
    struct bstptr_node* next; 
    struct bstptr_node* prev; 
}; 

// =====================================================================

bst_t* create_bst(void); 

status_t insert_bst(bst_t* p_bst, data_t new_data); 
status_t remove_bst(bst_t* p_bst, data_t r_data); 

status_t inorder_predecessor(bst_t* p_bst, data_t existing_data, data_t* p_pred_data); 
status_t inorder_successor(bst_t* p_bst, data_t existing_data, data_t* p_succ_data); 

status_t min_bst(bst_t* p_bst, data_t* p_min_data); 
status_t max_bst(bst_t* p_bst, data_t* p_max_data); 

status_t is_empty(bst_t* p_bst); 
status_t search_bst(bst_t* p_bst, data_t f_data); 

void inorder(bst_t* p_bst); 
void preorder(bst_t* p_bst); 
void postorder(bst_t* p_bst); 

status_t destroy_bst(bst_t** pp_bst); 

// =====================================================================

// nodelevel functions interface 
bst_node_t* get_node(data_t new_data);

bst_node_t* search_bst_nodelevel(bst_node_t* root_node, data_t f_data); 

bst_node_t* inorder_predecessor_nodelevel(bst_node_t* existing_node); 
bst_node_t* inorder_successor_nodelevel(bst_node_t* exisiting_node); 

void inorder_nodelevel(bst_node_t* root_node); 
void preorder_nodelevel(bst_node_t* root_node); 
void postorder_nodelevel(bst_node_t* root_node); 

bst_node_t* get_min_bst_nodelevel(bst_node_t* p_bst); 
bst_node_t* get_max_bst_nodelevel(bst_node_t* p_bst); 

status_t destroy_nodelevel(bst_node_t* root_node); 

// =====================================================================

// stack interface routines 
bstptr_stack_t* create_stack(void); 

status_t push(bstptr_stack_t* p_stack, bst_node_t* data);
status_t pop(bstptr_stack_t* p_stack, bst_node_t** p_popped_data); 
status_t top(bstptr_stack_t* p_stack, bst_node_t** p_top_data); 

void show_stack(bstptr_stack_t* p_stack, const char* msg); 
status_t is_stack_empty(bstptr_stack_t* p_stack); 
size_t get_stack_size(bstptr_stack_t* p_stack); 

status_t destroy_stack(bstptr_stack_t** pp_stack); 

// =====================================================================
// list interface 
bstptr_list_t* create_list(void); 

status_t insert_end(bstptr_list_t* p_list, bst_node_t* new_data); 
status_t pop_end(bstptr_list_t* p_list, bst_node_t** p_popped_data); 
status_t get_end(bstptr_list_t* p_list, bst_node_t** p_end_data); 

void show_list(bstptr_list_t* p_list, const char* msg); 
status_t is_list_empty(bstptr_list_t* p_list); 
size_t get_list_length(bstptr_list_t* p_list); 

status_t destroy_list(bstptr_list_t** pp_list); 

// list helper routines 
bstptr_node_t* get_bstptr_node(bst_node_t* new_data); 
void generic_insert(bstptr_node_t* p_beg, bstptr_node_t* p_mid, bstptr_node_t* p_end); 
void generic_delete(bstptr_node_t* p_beg, bstptr_node_t* p_mid, bstptr_node_t* p_end); 
// =====================================================================

// general purpose routines interface 
void* xmalloc(size_t size); 

// =====================================================================

int main(int argc, char* argv[]) 
{
    bst_t* p_bst = NULL; 
    status_t status; 
    data_t element; 
    data_t* data; 
    data_t non_existent_data[10] = {-10, -23, -45, -28, -2, -75, -34, -62, 37, 87}; 
    size_t N; 
    size_t index; 

    // ------------- FILLING DATA ARRAY ----------------- 
    if(argc != 2) 
    {
        printf("Usage error.\n" \
            "correct-usage: app NR_ELEMENTS\n"); 
        return (0); 
    } 
    N = atoi(argv[1]); 

    data = xmalloc(N * sizeof(data_t)); 
    srand(time(0)); 
    for(index = 0; index < N; ++index) 
        data[index] = rand(); 

    // ------------- EMPTY BST TESTING ----------------- 
    p_bst = create_bst(); 
    assert(p_bst != NULL); 
    assert(is_empty(p_bst) == TRUE); 
    element = 100; 
    assert(search_bst(p_bst, element) == FALSE);  
    printf("Just after creation:\n"); 
    printf("Number of elements=%lld\n", p_bst->nr_elements); 
    preorder(p_bst); 
    inorder(p_bst); 
    postorder(p_bst); 
    assert(min_bst(p_bst, &element) == BST_EMPTY);
    assert(max_bst(p_bst, &element) == BST_EMPTY); 

    for(index = 0; index < N; ++index) 
        assert(inorder_predecessor(p_bst, data[index], &element) == BST_DATA_NOT_FOUND); 

    // ------------- INSERTION ----------------- 
    puts("Inserting data..."); 
    for(index = 0; index < N; ++index) 
    {
        assert(insert_bst(p_bst, data[index]) == SUCCESS); 
        // printf("data %d successfully inserted\n", data[index]); 
    } 
    puts("Data insertion completed successufully"); 
    printf("Number of elements=%lld\n", p_bst->nr_elements); 
    preorder(p_bst); 
    inorder(p_bst); 
    postorder(p_bst); 

    // ------------- PREDECESSOR AND SUCCESSOR ----------------- 
    inorder(p_bst); 
    for(index = 0; index < N; ++index) 
    {
        status = inorder_predecessor(p_bst, data[index], &element); 
        if(status == SUCCESS) 
            printf("inorder_predecessor(%d)=%d\n", data[index], element); 
        else if(status == BST_DATA_NOT_FOUND) 
            printf("input data %d not present\n", data[index]); 
        else if(status == BST_NO_INORDER_PREDECESSOR) 
            printf("inorder_predecessor(%d)=NO_INORDER_PREDECESSOR\n", data[index]); 

        status = inorder_successor(p_bst, data[index], &element); 
        if(status == SUCCESS) 
            printf("inorder_successor(%d)=%d\n", data[index], element); 
        else if(status == BST_DATA_NOT_FOUND) 
            printf("input data %d not present\n", data[index]); 
        else if(status == BST_NO_INORDER_SUCCESSOR) 
            printf("inorder_successor(%d)=NO_INORDER_SUCCESSOR\n", data[index]); 
    } 

    // ------------- MIN AND MAX ----------------- 
    assert(min_bst(p_bst, &element) == SUCCESS); 
    printf("min_data=%d\n", element); 
    assert(max_bst(p_bst, &element) == SUCCESS); 
    printf("max data=%d\n", element); 

    // ------------- SEARCH ----------------- 
    puts("Searching data..."); 
    for(index = 0; index < 10; ++index) 
        assert(search_bst(p_bst, non_existent_data[index]) == FALSE); 

    index = 0; 
    while(index < N/2) 
    {
        assert(search_bst(p_bst, data[rand()%N]) == SUCCESS); 
        index = index+1; 
    } 
    puts("Search successfull"); 

    // ------------------- DELETION ------------------- 
    puts("deleting data..."); 
    // for(index = 0; index < N; ++index) 
    // {
        assert(remove_bst(p_bst, data[5]) == SUCCESS); 
        printf("After deleting %d | nrElements=%lld\n", data[5], p_bst->nr_elements); 
        inorder(p_bst); 
        assert(remove_bst(p_bst, data[2]) == SUCCESS); 
        printf("After deleting %d | nrElements=%lld\n", data[2], p_bst->nr_elements); 
        inorder(p_bst); 
        assert(remove_bst(p_bst, data[1]) == SUCCESS); 
        printf("After deleting %d | nrElements=%lld\n", data[1], p_bst->nr_elements); 
        inorder(p_bst); 
        assert(remove_bst(p_bst, data[4]) == SUCCESS); 
        printf("After deleting %d | nrElements=%lld\n", data[4], p_bst->nr_elements); 
        inorder(p_bst); 
        assert(remove_bst(p_bst, data[6]) == SUCCESS); 
        printf("After deleting %d | nrElements=%lld\n", data[6], p_bst->nr_elements); 
        inorder(p_bst); 
        assert(remove_bst(p_bst, data[7]) == SUCCESS); 
        printf("After deleting %d | nrElements=%lld\n", data[7], p_bst->nr_elements); 
        inorder(p_bst); 
        assert(remove_bst(p_bst, data[3]) == SUCCESS); 
        printf("After deleting %d | nrElements=%lld\n", data[3], p_bst->nr_elements); 
        inorder(p_bst); 
        assert(remove_bst(p_bst, data[0]) == SUCCESS); 
        printf("After deleting %d | nrElements=%lld\n", data[0], p_bst->nr_elements); 
        inorder(p_bst); 
        assert(remove_bst(p_bst, data[8]) == SUCCESS); 
        printf("After deleting %d | nrElements=%lld\n", data[8], p_bst->nr_elements); 
        inorder(p_bst); 
        assert(remove_bst(p_bst, data[9]) == SUCCESS); 
        printf("After deleting %d | nrElements=%lld\n", data[9], p_bst->nr_elements); 
        inorder(p_bst); 
    // }  
    puts("Data deletion completed..."); 

    // -------------------- DESTROY BST ----------------------- 
    puts("Destroying BST..."); 
    assert(destroy_bst(&p_bst) == SUCCESS); 
    printf("BST destroyed succesfull\n"); 

    free(data); 
    data = NULL; 

    /* 
    // ========================== STACK CLIENT ==========================
    bstptr_stack_t* p_stack = NULL; 
    p_stack = create_stack(); 
    assert(p_stack != NULL); 
    puts("Stack created successfully"); 

    puts("Inserting data into stack..."); 
    for(int i = 0; i < 10; ++i) 
    {
        bst_node_t* node = get_node(10); 
        push(p_stack, node); 
        printf("%p pushed successfully\n", node); 
        show_stack(p_stack, NULL);  
    } 
    puts("Insertion complete"); 

    puts("destroying stack..."); 
    assert(destroy_stack(&p_stack) == SUCCESS && p_stack == NULL); 
    puts("Stack destroyed succesfully\n"); 
    */ 

    return (0); 
} 

bst_t* create_bst(void) 
{
    bst_t* p_bst = NULL; 

    p_bst = xmalloc(sizeof(bst_t)); 
    p_bst->root_node = NULL; 
    p_bst->nr_elements = 0; 

    return (p_bst); 
} 

status_t insert_bst(bst_t* p_bst, data_t new_data) 
{
    bst_node_t* run = NULL; 
    bst_node_t* new_node = NULL; 

    new_node = get_node(new_data); 

    if(p_bst->root_node == NULL)
    {
        /* CASE I : Empty BST*/
        p_bst->root_node = new_node; 
        p_bst->nr_elements += 1; 
        return (SUCCESS); 
    }

    run = p_bst->root_node;
    while(TRUE)
    {
        if(new_data <= run->data)
        {
            if(run->left == NULL)
            {
                run->left = new_node; 
                run->left->parent = run; 
                break; 
            }

            run = run->left; 
        }
        else 
        {
            if(run->right == NULL)
            {
                run->right = new_node; 
                run->right->parent = run; 
                break; 
            }
            run = run->right; 
        }
    }

    p_bst->nr_elements += 1; 
    return (SUCCESS); 
} 

status_t remove_bst(bst_t* p_bst, data_t r_data) 
{
    bst_node_t* remove_node = NULL; 
    bst_node_t* replace_node = NULL; 

    remove_node = search_bst_nodelevel(p_bst->root_node, r_data); 
    if(NULL == remove_node) 
        return (BST_DATA_NOT_FOUND); 

    if(remove_node->left == NULL) 
    {
        if(remove_node->parent == NULL)
            p_bst->root_node = remove_node->right; 
        else if(remove_node == remove_node->parent->left) 
            remove_node->parent->left = remove_node->right; 
        else 
            remove_node->parent->right = remove_node->right; 

        if(remove_node->right != NULL) 
            remove_node->right->parent = remove_node->parent; 
    } 

    else if(remove_node->right == NULL) 
    {
        if(remove_node->parent == NULL) 
            p_bst->root_node = remove_node->left; 
        else if(remove_node == remove_node->parent->right) 
            remove_node->parent->right = remove_node->left; 
        else 
            remove_node->parent->left = remove_node->left; 

        remove_node->left->parent = remove_node->parent; 
    } 
    
    else 
    {
        replace_node = get_min_bst_nodelevel(remove_node->right); 

        if(replace_node != remove_node->right) 
        {
            replace_node->parent->left = replace_node->right; 
            if(replace_node->right != NULL) 
                replace_node->right->parent = replace_node->parent; 

            replace_node->right = remove_node->right; 
            replace_node->right->parent = replace_node; 
        } 

        replace_node->left = remove_node->left; 
        replace_node->left->parent = replace_node; 

        // setting with parent 
        if(remove_node->parent == NULL) 
            p_bst->root_node = replace_node; 
        else if(remove_node == remove_node->parent->left)
            remove_node->parent->left = replace_node; 
        else 
            remove_node->parent->right = replace_node; 

        replace_node->parent = remove_node->parent; 
    } 

    free(remove_node); 
    remove_node = NULL; 
    p_bst->nr_elements -= 1; 

    return (SUCCESS); 
} 

status_t inorder_predecessor(bst_t* p_bst, data_t existing_data, data_t* p_pred_data) 
{
    bst_node_t* p_pred_node = NULL; 
    bst_node_t* existing_node = NULL; 

    existing_node = search_bst_nodelevel(p_bst->root_node, existing_data); 
    if(NULL == existing_node) 
        return (BST_DATA_NOT_FOUND); 

    p_pred_node = inorder_predecessor_nodelevel(existing_node); 
    if(p_pred_node == NULL) 
        return (BST_NO_INORDER_PREDECESSOR); 
    
    *p_pred_data = p_pred_node->data; 
    return (SUCCESS); 
} 

status_t inorder_successor(bst_t* p_bst, data_t existing_data, data_t* p_succ_data) 
{
    bst_node_t* p_succ_node = NULL; 
    bst_node_t* existing_node = NULL; 

    existing_node = search_bst_nodelevel(p_bst->root_node, existing_data); 
    if(NULL == existing_node) 
        return (BST_DATA_NOT_FOUND); 

    p_succ_node = inorder_successor_nodelevel(existing_node); 
    if(p_succ_node == NULL) 
        return (BST_NO_INORDER_SUCCESSOR); 

    *p_succ_data = p_succ_node->data; 
    return (SUCCESS); 
} 

status_t min_bst(bst_t* p_bst, data_t* p_min_data) 
{
    bst_node_t* max_node = NULL; 
    
    max_node = get_min_bst_nodelevel(p_bst->root_node); 
    if(max_node == NULL) 
        return (BST_EMPTY); 
    
    *p_min_data = max_node->data; 
    return (SUCCESS); 
} 

status_t max_bst(bst_t* p_bst, data_t* p_max_data) 
{
    bst_node_t* max_node = NULL; 

    max_node = get_max_bst_nodelevel(p_bst->root_node); 
    if(NULL == max_node) 
        return (BST_EMPTY); 
    
    *p_max_data = max_node->data; 
    return (SUCCESS); 
} 

status_t is_empty(bst_t* p_bst) 
{
    return (p_bst->root_node == NULL); 
} 

status_t search_bst(bst_t* p_bst, data_t f_data) 
{
    bst_node_t* f_node = NULL; 
    
    f_node = search_bst_nodelevel(p_bst->root_node, f_data); 
    return(f_node != NULL); 
} 

void inorder(bst_t* p_bst) 
{
    printf("inorder > [START]->"); 
    inorder_nodelevel(p_bst->root_node); 
    puts("[END]"); 
} 

void preorder(bst_t* p_bst) 
{
    printf("preorder > [START]->"); 
    preorder_nodelevel(p_bst->root_node); 
    puts("[END]"); 
} 

void postorder(bst_t* p_bst) 
{
    printf("postorder > [START]->"); 
    postorder_nodelevel(p_bst->root_node); 
    puts("[END]"); 
} 

status_t destroy_bst(bst_t** pp_bst) 
{
    bst_t* p_bst = *pp_bst; 

    assert(destroy_nodelevel(p_bst->root_node) == SUCCESS); 
    free(p_bst); 
    *pp_bst = NULL;  

    return (SUCCESS); 
} 

// nodelevel interface functions 
bst_node_t* get_node(data_t new_data) 
{
    bst_node_t* new_node = NULL; 

    new_node = xmalloc(sizeof(bst_node_t)); 
    new_node->data = new_data; 
    new_node->parent = NULL; 
    new_node->left = NULL; 
    new_node->right = NULL; 

    return (new_node); 
} 

bst_node_t* inorder_predecessor_nodelevel(bst_node_t* existing_node) 
{
    bst_node_t* x = NULL; 
    bst_node_t* y = NULL; 
    bst_node_t* z = NULL; 
    
    z = existing_node; 
    if(z->left != NULL) 
        return (get_max_bst_nodelevel(z->left)); 

    x = z; 
    y = x->parent; 
    while(y != NULL && y->left == x) 
    {
        x = y; 
        y = y->parent; 
    } 

    return (y); 
} 

bst_node_t* inorder_successor_nodelevel(bst_node_t* existing_node) 
{
    bst_node_t* x = NULL; 
    bst_node_t* y = NULL; 
    bst_node_t* z = NULL; 

    z = existing_node; 
    if(z->right != NULL) 
        return (get_min_bst_nodelevel(existing_node->right)); 

    x = z; 
    y = x->parent; 
    while(y != NULL && y->right == x) 
    {
        x = y; 
        y = y->parent; 
    } 

    return (y); 
} 

bst_node_t* get_min_bst_nodelevel(bst_node_t* root_node) 
{
    if(root_node == NULL) 
        return (NULL); 

    while(root_node->left != NULL) 
        root_node = root_node->left; 
    return (root_node); 
} 

bst_node_t* get_max_bst_nodelevel(bst_node_t* root_node) 
{
    if(root_node == NULL) 
        return (NULL); 

    while(root_node->right != NULL) 
        root_node = root_node->right; 
    return (root_node); 
} 

bst_node_t* search_bst_nodelevel(bst_node_t* root_node, data_t f_data) 
{
    while(root_node != NULL) 
    {
        if(root_node->data == f_data) 
            break; 
        else if(f_data < root_node->data) 
            root_node = root_node->left; 
        else    
            root_node = root_node->right; 
    } 

    return (root_node); 
} 

status_t destroy_nodelevel(bst_node_t* root_node) 
{
    if(root_node != NULL)
    {
        assert(destroy_nodelevel(root_node->left) == SUCCESS); 
        assert(destroy_nodelevel(root_node->right) == SUCCESS); 
        free(root_node); 
        root_node = NULL; 
    }
    
    return (SUCCESS); 
} 

void preorder_nodelevel(bst_node_t* root_node) 
{
    if(root_node != NULL) 
    {
        printf("[%d]->", root_node->data); 
        preorder_nodelevel(root_node->left); 
        preorder_nodelevel(root_node->right); 
    } 
} 

void inorder_nodelevel(bst_node_t* root_node) 
{
    if(root_node != NULL) 
    {
        inorder_nodelevel(root_node->left); 
        printf("[%d]->", root_node->data); 
        inorder_nodelevel(root_node->right); 
    } 
} 

void postorder_nodelevel(bst_node_t* root_node) 
{
    if(root_node != NULL) 
    {
        postorder_nodelevel(root_node->left); 
        postorder_nodelevel(root_node->right); 
        printf("[%d]->", root_node->data); 
    } 
} 

// ======================== STACK Server ============================= 

bstptr_stack_t* create_stack(void) 
{
    bstptr_stack_t* p_stack = NULL; 

    p_stack = create_list(); 
    return (p_stack); 
} 

status_t push(bstptr_stack_t* p_stack, bst_node_t* new_data) 
{
    return (insert_end(p_stack, new_data)); 
}

status_t pop(bstptr_stack_t* p_stack, bst_node_t** p_new_data) 
{
    return (pop_end(p_stack, p_new_data)); 
} 

status_t top(bstptr_stack_t* p_stack, bst_node_t** p_end_data) 
{
    status_t status; 
    status = get_end(p_stack, p_end_data); 
    if(status == LIST_EMPTY) 
        return (STACK_EMPTY); 
    else 
        return (SUCCESS); 
} 

status_t is_stack_empty(bstptr_stack_t* p_stack) 
{
    return (is_list_empty(p_stack)); 
} 

void show_stack(bstptr_stack_t* p_stack, const char* msg) 
{
    show_list(p_stack, msg); 
} 

size_t get_stack_size(bstptr_stack_t* p_stack) 
{
    return (get_list_length(p_stack)); 
} 

status_t destroy_stack(bstptr_stack_t** pp_stack) 
{
    return (destroy_list(pp_stack)); 
} 

// ======================== LIST Server ============================== 

bstptr_list_t* create_list(void) 
{
    bstptr_list_t* p_list = NULL;

    p_list = (bstptr_list_t*)xmalloc(sizeof(bstptr_node_t)); 
    p_list->data = NULL; 
    p_list->next = p_list; 
    p_list->prev = p_list; 

    return (p_list); 
} 

status_t insert_end(bstptr_list_t* p_list, bst_node_t* new_data) 
{
    generic_insert(p_list->prev, get_bstptr_node(new_data), p_list); 
    return (SUCCESS); 
} 

status_t get_end(bstptr_list_t* p_list, bst_node_t** p_end_data) 
{
    if(is_list_empty(p_list) == TRUE) 
        return (LIST_EMPTY); 
        
    *p_end_data = p_list->prev->data; 
    return (SUCCESS); 
} 

status_t pop_end(bstptr_list_t* p_list, bst_node_t** p_popped_data) 
{
    if(is_list_empty(p_list) == TRUE) 
        return (LIST_EMPTY); 

    *p_popped_data = p_list->prev->data; 
    generic_delete(p_list->prev->prev, p_list->prev, p_list); 

    return (SUCCESS); 
} 

status_t is_list_empty(bstptr_list_t* p_list) 
{
    return (p_list->prev == p_list && p_list->next == NULL); 
} 

size_t get_list_length(bstptr_list_t* p_list) 
{
    bstptr_node_t* run = NULL; 
    size_t len = 0; 
    
    run = p_list->next; 
    while(run != p_list) 
    {
        len += 1; 
        run = run->next; 
    }  

    return (len); 
} 

void show_list(bstptr_list_t* p_list, const char* msg) 
{
    bstptr_node_t* run = NULL; 

    if(msg) 
        puts(msg); 

    printf("[START]<->"); 
    run = p_list->next; 
    while(run != p_list) 
    {
        printf("[%p]<->", run->data); 
        run = run->next; 
    } 
    puts("[END]"); 
} 

status_t destroy_list(bstptr_list_t** pp_list) 
{
    bstptr_list_t* p_list = NULL; 
    bstptr_node_t* run = NULL; 
    bstptr_node_t* run_next = NULL; 

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

// list auxilliary functions 
bstptr_node_t* get_bstptr_node(bst_node_t* new_data) 
{
    bstptr_node_t* new_node = NULL; 

    new_node = (bstptr_node_t*)xmalloc(sizeof(bstptr_node_t)); 
    new_node->data = new_data; 
    new_node->prev = NULL; 
    new_node->next = NULL; 

    return (new_node); 
} 

void generic_insert(bstptr_node_t* p_beg, bstptr_node_t* p_mid, bstptr_node_t* p_end) 
{
    p_mid->prev = p_beg; 
    p_mid->next = p_end; 
    p_beg->next = p_mid; 
    p_end->prev = p_mid; 
} 

void generic_delete(bstptr_node_t* p_beg, bstptr_node_t* p_mid, bstptr_node_t* p_end) 
{
    p_beg->next = p_end; 
    p_end->prev = p_beg; 
    free(p_mid); 
    p_mid = NULL; 
} 

// =========================================================== 

// general purpose functions 
void* xmalloc(size_t size) 
{
    void* p = NULL; 

    p = malloc(size); 
    if(NULL == p) 
    {
        fprintf(stderr, "xmalloc() > error in allocating memory\n"); 
        exit(EXIT_FAILURE); 
    } 

    return (p); 
} 

