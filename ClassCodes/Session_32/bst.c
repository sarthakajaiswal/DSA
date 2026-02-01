/*
    @GOAL:      BST implementation 
    @DATE:      26 Jan 2026 
    @AUTHOR:    Sarthak A Jaiswal 
*/ 

#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <assert.h> 

enum status 
{
    SUCCESS                         = 1, 
    TRUE                            = 1, 
    FALSE                           = 0, 
    BST_EMPTY                       = -1, 
    BST_DATA_NOT_FOUND              = -2, 
    BST_NO_PREORDER_PREDECESSOR     = -3, 
    BST_NO_PREORDER_SUCCESSOR       = -4, 
    BST_NO_INORDER_PREDECESSOR      = -5, 
    BST_NO_INORDER_SUCCESSOR        = -6, 
    BST_NO_POSTORDER_PREDECESSOR    = -7, 
    BST_NO_POSTORDER_SUCCESSOR      = -8, 
}; 

typedef int             data_t; 
typedef enum status     status_t; 
typedef struct bst_node bst_node_t; 
typedef struct bst      bst_t;

struct bst_node 
{
    int data; 
    struct bst_node* parent; 
    struct bst_node* left; 
    struct bst_node* right; 
};  

struct bst 
{
    struct bst_node* root_node; 
    size_t nr_elements; 
}; 

// interface functions 
bst_t* create_bst(void); 

status_t insert_bst(bst_t* p_bst, data_t new_data); 
status_t remove_bst(bst_t* p_bst, data_t r_data); 

status_t inorder_predecessor(bst_t* p_bst, data_t existing_data, data_t* p_pred_data); 
status_t inorder_successor(bst_t* p_bst, data_t existing_data, data_t* p_succ_data); 
status_t preorder_predecessor(bst_t* p_bst, data_t existing_data, data_t* p_pred_data); 
status_t preorder_successor(bst_t* p_bst, data_t existing_data, data_t* p_succ_data); 
status_t postorder_predecessor(bst_t* p_bst, data_t existing_data, data_t* p_pred_data); 
status_t postorder_successor(bst_t* p_bst, data_t existing_data, data_t* p_succ_data); 

status_t max_bst(bst_t* p_bst, data_t* p_max_data); 
status_t min_bst(bst_t* p_bst, data_t* p_min_data); 

void preorder(bst_t* p_bst); 
void inorder(bst_t* p_bst); 
void postorder(bst_t* p_bst); 

void inorder_nrc(bst_t* p_bst); 
void preorder_nrc(bst_t* p_bst); 
void postorder_nrc(bst_t* p_bst); 

status_t search_bst(bst_t* p_bst, data_t search_data); 
status_t is_empty(bst_t* p_bst); 

status_t destroy_bst(bst_t** pp_bst); 

// nodelevel routines 
bst_node_t* search_nodelevel(bst_node_t* p_root_node, data_t search_data); 
void destroy_nodelevel(bst_node_t* p_root_node); 

bst_node_t* inorder_nodelevel(bst_node_t* p_root_node); 
bst_node_t* preorder_nodelevel(bst_node_t* p_root_node); 
bst_node_t* postorder_nodelevel(bst_node_t* p_root_node); 

bst_node_t* inorder_predecessor_nodelevel(bst_node_t* p_root_node); 
bst_node_t* inorder_successor_nodelevel(bst_node_t* p_root_node); 
bst_node_t* preorder_predecessor_nodelevel(bst_node_t* p_root_node); 
bst_node_t* preorder_successor_nodelevel(bst_node_t* p_root_node); 
bst_node_t* postorder_predecessor_nodelevel(bst_node_t* p_root_node); 
bst_node_t* postorder_successor_nodelevel(bst_node_t* p_root_node); 

bst_node_t* max_bst_nodelevel(bst_node_t* p_bst_node); 
bst_node_t* min_bst_nodelevel(bst_node_t* p_bst_node); 

// general purpose routines 
bst_node_t* get_bst_node(data_t new_data); 
void* xmalloc(size_t size); 

// ================ client side ================= 
void test_bst_normal(void); 
void test_bst_extreme(void); 

int main(void) 
{
    test_bst_normal(); 

    #ifdef EXTREME_TESTING 
    test_bst_extreme(); 
    #endif /* EXTREME TESTING */ 

    return (EXIT_SUCCESS); 
} 

void test_bst_normal(void) 
{
    bst_t* p_bst = NULL; 
    status_t status = SUCCESS; 
    data_t data[] = {100, 50, 25, 150, 75, 125, 200, 65, 130}; 
    data_t non_existent_data[] = {-200, 34, 68, 98, 0xaabb, 0xf0f0f0f0f0}; 
    data_t succ_data, pred_data; 

    size_t index; 

    p_bst = create_bst(); 

    for(index = 0; index < sizeof(data)/sizeof(data[0]); ++index) 
    {
        status = insert_bst(p_bst, data[index]); 
        assert(status == SUCCESS); 
        printf("insert_bst() for [%d] is successful\n", data[index]); 
    } 

    preorder(p_bst); 
    inorder(p_bst); 
    postorder(p_bst); 

    for(index = 0; index < sizeof(data)/sizeof(data[0]); ++index) 
    {
        status = search_bst(p_bst, data[index]); 
        assert(status == TRUE); 
        printf("search for %d is succesfull\n", data[index]); 
    } 

    for(index = 0; index < sizeof(non_existent_data)/sizeof(non_existent_data[0]); ++index) 
    {
        status = search_bst(p_bst, non_existent_data[index]); 
        assert(status == FALSE); 
        printf("search for %d failed successfully\n", non_existent_data[index]); 
    } 

    for(index = 0; index < sizeof(data)/sizeof(data[0]); ++index) 
    {
        status = inorder_predecessor(p_bst, data[index], &pred_data); 
        switch(status) 
        {
            case SUCCESS: 
                printf("inorder-predecessor(%d) = %d\n", data[index], pred_data); 
                break; 

            case BST_DATA_NOT_FOUND: 
                printf("input data %d not found in bst\n", data[index]); 
                break; 

            case BST_NO_INORDER_PREDECESSOR: 
                printf("no inorder predecessor for input data %d\n", data[index]); 
                break; 

            default: 
                break; 
        } 

        status = inorder_successor(p_bst, data[index], &succ_data); 
        switch(status) 
        {
            case SUCCESS: 
                printf("inorder-successor(%d) = %d\n", data[index], succ_data); 
                break; 

            case BST_NO_INORDER_SUCCESSOR: 
                printf("no inorder successor of %d\n", data[index]); 
                break; 
            
            case BST_DATA_NOT_FOUND: 
                printf("input data %d not present in bst\n", data[index]); 
                break; 

            default: 
                break; 
        } 
    } 

    puts("Inorder traversal before removing data\n"); 
    inorder(p_bst); 

    for(index = 0; index < sizeof(data)/sizeof(data[0]); ++index) 
    {
        status = remove_bst(p_bst, data[index]); 
        assert(status == SUCCESS); 
        printf("%d removed succesfully\n", data[index]); 
    } 

    assert(p_bst->root_node == NULL); 

    status = destroy_bst(&p_bst); 
    assert(status == SUCCESS && p_bst == NULL); 

    puts("BST destroyed successfully\n"); 
    puts("--------- Normal Testing Completed ---------------"); 
}

void test_bst_extreme(void) 
{} 

bst_t* create_bst(void) 
{
    bst_t* p_bst = NULL; 

    p_bst = (bst_t*)xmalloc(sizeof(bst_t)); 
    p_bst->root_node = NULL; 
    p_bst->nr_elements = 0; 

    return (p_bst); 
} 

status_t destroy_bst(bst_t** pp_bst) 
{
    bst_t* p_bst = NULL; 
    p_bst = *pp_bst; 

    destroy_nodelevel(p_bst->root_node); 
    *pp_bst = NULL; 
    return (SUCCESS); 
} 

status_t insert_bst(bst_t* p_bst, data_t new_data) 
{
    bst_node_t* run = NULL; 
    bst_node_t* new_node = NULL; 

    new_node = get_bst_node(new_data); 
    
    if(p_bst->root_node == NULL) 
    {
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

status_t search_bst(bst_t* p_bst, data_t search_data) 
{
    bst_node_t* run = NULL; 

    run = search_nodelevel(p_bst->root_node, search_data); 
    return (run != NULL); 
} 

status_t is_empty(bst_t* p_bst) 
{
    return (p_bst->root_node == NULL); 
} 

status_t remove_bst(bst_t* p_bst, data_t r_data) 
{
    bst_node_t* z = NULL; // for storing address of node to be deleted 

    z = search_nodelevel(p_bst->root_node, r_data); 
    if(NULL == z)
        return (BST_DATA_NOT_FOUND); 

    if(z->left == NULL)                     /* CASE I: Left subtree of z is empty, right subtree may or may not be empty */ 
    {
        if(z->parent == NULL)               /* Node to be deleted is root node */ 
            p_bst->root_node = z->right;    /* Make right node a root node of entire bst */ 
        else if(z->parent->left == z)       /* z has a parent and it is left child of his parent */ 
            z->parent->left = z->right;     /* Delegate responsibility of right child to left pointer of parent */ 
        else                                /* z has parent and it is right child of his parent */ 
            z->parent->right = z->right;    /* Delegate responsibility of right child to right pointer of parent */ 

        if(z->right != NULL)                /* z->right may or may not be empty, so the test */ 
            z->right->parent = z->parent;   /* make z->parent a parent of root of right subtree of z */ 
    } 

    else if(z->right == NULL)               /* CASE II: Left subtree of z is not empty and right subtree of z is empty */ 
    {
        if(z->parent == NULL)               /* Node to be itself is a root node */  
            p_bst->root_node = z->left;     /* Make left subtree of z root node of entire BST */ 
        else if(z->parent->left == z)       /* z has parent and it is left child of its parent */ 
            z->parent->left = z->left;      /* Delegate responsibility of left child to left pointer of parent */ 
        else if(z->parent->right == z)      /* z has parent and it is the right child of its parent */ 
            z->parent->right = z->left;     /* Delegate responsibility of left child to right pointer of parent */ 

        z->left->parent = z->parent;        /* we know that z->left is not NULL therefore, unconditionally set its parent to z->parent */ 
    } 

    /* CASE III: Both subtree of node to be deleted are not NULL */ 
    else 
    {
        bst_node_t* u = z->right; 
        while(u->left != NULL) 
            u = u->left; 
        /* After the loop, u is now the inorder successor of z */ 

        if(z->right != u) 
        {
            /* 
                if inorder successor 'u' of node to be deleted 'z' is a right child of z then 
                we *do not* delegate responsibility of u to its parent and we do not take 
                hold of right subtree of z because u itself is a right subtree of z. 
            */ 
            /* 
                If inorder successor 'u' of node to be deleted 'z' is not a right child f z then 
                delegate responsibility of right child of u to the parent of u if right child of 
                u is npt NULL 
            */ 
            u->parent->left = u->right;         /* Delegate u->right to u's parent */ 
            if(u->right != NULL)                
                u->right->parent = u->parent;   /* Make u->right accept u's parent as its parent */ 
            
            /* take hold of right subtree of z */ 
            u->right = z->right;                /* right subtree of z is now right subtree of u */ 
            z->right->parent = u;               /* Make left subtree of 'z' accept 'u' as its parent */ 
        } 

        // take hold of left subtree of z 
        u->left = z->left;                      /* left subtree of z is not a left subtree of u */ 
        u->left->parent = u;                    /* Make left subtree of z accept 'u' as its parent */ 

        /* Do setting with parent */ 
        if(z->parent == NULL)           /* z is a root node */ 
            p_bst->root_node = u;       /* make successor of z i.e. u root node of entire BST */ 
        else if(z == z->parent->left)   /* Z has parent and it is left subtree of its parent */ 
            z->parent->left = u;        /* Delegate responsibility of u to the left pointer of parent */ 
        else if(z == z->parent->right)  /* z has parent and it it right subtree of its parent */ 
            z->parent->right = u;       /* Delegate responsibility of u to the right pointer of parent */ 

        u->parent = z->parent;     
    } 

    free(z);    /* Release memory associated with the removed node */ 
    z = NULL;   /* z is not dangeling pointer now */ 
    p_bst->nr_elements -= 1; /* Decrement element count by 1 */ 

    return (SUCCESS); 
} 

void preorder(bst_t* p_bst) 
{
    printf("[START]->"); 
    preorder_nodelevel(p_bst->root_node); 
    puts("[END]");  
} 

void inorder(bst_t* p_bst) 
{
    printf("[START]->"); 
    inorder_nodelevel(p_bst->root_node); 
    puts("[END]"); 
} 

void postorder(bst_t* p_bst) 
{
    printf("[START]->"); 
    postorder_nodelevel(p_bst->root_node); 
    puts("[END]"); 
} 

status_t inorder_predecessor(bst_t* p_bst, data_t existing_data, data_t* p_pred_data) 
{
    bst_node_t* p_existing_node = NULL; 
    bst_node_t* p_pred_node = NULL; 

    p_existing_node = search_nodelevel(p_bst->root_node, existing_data); 
    if(p_existing_node == NULL) 
        return (BST_DATA_NOT_FOUND); 

    p_pred_node = inorder_predecessor_nodelevel(p_existing_node); 
    if(p_pred_node == NULL) 
        return (BST_NO_INORDER_PREDECESSOR); 

    *p_pred_data = p_pred_node->data; 
    return (SUCCESS); 
} 

status_t inorder_successor(bst_t* p_bst, data_t existing_data, data_t* p_succ_data) 
{
    bst_node_t* p_existing_node = NULL; 
    bst_node_t* p_succ_node = NULL; 

    p_existing_node = search_nodelevel(p_bst->root_node, existing_data); 
    if(NULL == p_existing_node) 
        return (BST_DATA_NOT_FOUND); 

    p_succ_node = inorder_successor_nodelevel(p_existing_node); 
    if(p_succ_node == NULL) 
        return (BST_NO_INORDER_SUCCESSOR); 

    *p_succ_data = p_succ_node->data; 
    return (SUCCESS); 
} 

status_t preorder_predecessor(bst_t* p_bst, data_t existing_data, data_t* p_pred_data) 
{

} 

status_t preorder_successor(bst_t* p_bst, data_t existing_data, data_t* p_succ_data) 
{

} 

status_t postorder_predecessor(bst_t* p_bst, data_t existing_data, data_t* p_pred_data) 
{

} 

status_t postorder_successor(bst_t* p_bst, data_t existing_data, data_t* p_succ_data) 
{

} 

// minimum and maximum 
status_t min_bst(bst_t* p_bst, data_t* p_min_data) 
{
    bst_node_t* min_data_node = NULL; 

    if(p_bst->root_node == NULL) 
        return (BST_EMPTY); 

    min_data_node = min_bst_nodelevel(p_bst->root_node); 
    *p_min_data = min_data_node->data; 
}

status_t max_bst(bst_t* p_bst, data_t* p_max_data) 
{
    bst_node_t* max_data_node = NULL; 

    if(p_bst->root_node == NULL) 
        return (BST_EMPTY); 

    max_data_node = max_bst_nodelevel(p_bst->root_node); 
    *p_max_data = max_data_node->data; 
} 

void preorder_nrc(bst_t* p_bst) 
{

} 

void inorder_nrc(bst_t* p_bst) 
{

} 

void postorder_nrc(bst_t* p_bst) 
{

} 

// aucilliary functions 
void destroy_nodelevel(bst_node_t* root_node) 
{
    if(root_node != NULL) 
    {
        destroy_nodelevel(root_node->left); 
        destroy_nodelevel(root_node->right); 
        free(root_node); 
        root_node = NULL; 
    } 
} 

bst_node_t* search_nodelevel(bst_node_t* root_node, data_t search_data) 
{
    bst_node_t* run = NULL; 

    run = root_node; 
    while(run != NULL) 
    {
        if(search_data < run->data) 
            run = run->left; 
        else if(search_data > run->data) 
            run = run->right; 
        else 
            break; 
    } 

    return (run); 
} 

bst_node_t* preorder_nodelevel(bst_node_t* root_node) 
{
    if(root_node != NULL) 
    {
        printf("[%d]->", root_node->data); 
        preorder_nodelevel(root_node->left); 
        preorder_nodelevel(root_node->right); 
    } 
} 

bst_node_t* postorder_nodelevel(bst_node_t* root_node) 
{
    if(root_node != NULL) 
    {
        postorder_nodelevel(root_node->left); 
        postorder_nodelevel(root_node->right); 
        printf("[%d]->", root_node->data); 
    } 
} 

bst_node_t* inorder_nodelevel(bst_node_t* root_node) 
{
    if(root_node != NULL) 
    {
        inorder_nodelevel(root_node->left); 
        printf("[%d]->", root_node->data); 
        inorder_nodelevel(root_node->right); 
    } 
} 

bst_node_t* inorder_predecessor_nodelevel(bst_node_t* existing_node) 
{
    bst_node_t* x = NULL; 
    bst_node_t* y = NULL; 

    if(existing_node->left != NULL) 
        return (min_bst_nodelevel(existing_node->left)); 

    x = existing_node; 
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

    if(existing_node->right != NULL)
        return (min_bst_nodelevel(existing_node->right)); 

    x = existing_node; 
    y = x->parent; 
    while(y != NULL && y->right == x) 
    {
        x = y; 
        y = y->parent; 
    } 

    return (y); 
} 

bst_node_t* preorder_predecessor_nodelevel(bst_node_t* existing_node) 
{

} 

bst_node_t* preorder_successor_nodelevel(bst_node_t* existing_node) 
{

}  

bst_node_t* postorder_predecessor_nodelevel(bst_node_t* existing_node) 
{

} 

bst_node_t* postorder_successor_nodelevel(bst_node_t* existing_node) 
{

} 

bst_node_t* max_bst_nodelevel(bst_node_t* root_node) 
{
    while(root_node->right != NULL) 
        root_node = root_node->right; 

    return(root_node); 
} 

bst_node_t* min_bst_nodelevel(bst_node_t* root_node) 
{
    while(root_node->left != NULL) 
        root_node = root_node->left; 
    return (root_node); 
} 

// auxilliary functions 
bst_node_t* get_bst_node(data_t new_data) 
{
    bst_node_t* new_node = NULL; 

    new_node = (bst_node_t*)xmalloc(sizeof(bst_node_t)); 
    new_node->data = new_data; 
    new_node->left = NULL; 
    new_node->right = NULL; 
    new_node->parent = NULL; 

    return (new_node); 
} 

void* xmalloc(size_t size) 
{
    void* ptr = NULL; 

    ptr = malloc(size); 
    if(NULL == ptr) 
    {
        puts("malloc():fatal:out of memory"); 
        exit(EXIT_FAILURE); 
    } 

    return (ptr); 
} 


