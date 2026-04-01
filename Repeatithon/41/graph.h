#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <assert.h> 

#define TRUE    1 
#define FALSE   0 
#define SUCCESS 1 

#define G_INVALID_VERTEX    -1 
#define G_VERTEX_EXISTS     -2 
#define G_INVALID_EDGE      -3 
#define G_EDGE_EXISTS       -4 

typedef int status_t; 
typedef int vertex_t; 
typedef struct hnode hnode_t; 
typedef hnode_t hlist_t; 
typedef struct vnode vnode_t; 
typedef vnode_t vlist_t; 
typedef struct graph graph_t; 

struct hnode 
{
    vertex_t v; 
    struct hnode* h_prev; 
    struct hnode* h_next; 
}; 

struct vnode 
{
    vertex_t v; 
    hlist_t* ph_head_node; 
    struct vnode* v_prev; 
    struct vnode* v_next; 
};  

struct graph 
{
    vlist_t* pv_head_node; 
    size_t number_of_vertices; 
    size_t number_of_edges; 
}; 

graph_t* create_graph(void); 

status_t insert_vertex(graph_t* g, vertex_t new_vertex); 
status_t remove_vertex(graph_t* g, vertex_t r_vertex); 
status_t insert_edge(graph_t* g, vertex_t v_start, vertex_t v_end); 
status_t remove_edge(graph_t* g, vertex_t v_start, vertex_t v_end); 

void show_graph(graph_t* g, const char* msg); 
status_t destroy_graph(graph_t** pp_g); 

vlist_t* v_create_list(void); 
status_t v_insert_end(vlist_t* pv_list, vertex_t new_vertex); 

void v_generic_insert(vnode_t* pv_start, vnode_t* pv_mid, vnode_t* pv_end); 
void v_generic_delete(vnode_t* pv_delete_node); 
vnode_t* v_search_node(vlist_t* pv_list, vertex_t v); 
vnode_t* v_get_list_node(vertex_t v); 

hlist_t* h_create_list(void); 
status_t h_insert_end(hlist_t* ph_list, vertex_t new_vertex); 

void h_generic_insert(hnode_t* ph_start, hnode_t* ph_mid, hnode_t* ph_end); 
void h_generic_delete(hnode_t* ph_delete_node); 
hnode_t* h_search_node(hlist_t* ph_list, vertex_t v); 
hnode_t* h_get_list_node(vertex_t v); 

void* xmalloc(size_t size_in_bytes); 

// ========================================================= 

#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <assert.h> 

#define TRUE    1 
#define FALSE   0 
#define SUCCESS 1 

#define G_INVALID_VERTEX    -1 
#define G_VERTEX_EXISTS     -2 
#define G_INVALID_EDGE      -3 
#define G_EDGE_EXISTS       -4 

typedef int status_t; 
typedef int vertex_t; 
typedef struct hnode hnode_t; 
typedef hnode_t hlist_t; 
typedef struct vnode vnode_t; 
typedef vnode_t vlist_t; 
typedef struct graph graph_t; 

struct hnode 
{
    vertex_t v; 
    struct hnode* h_prev; 
    struct hnode* h_next; 
}; 

struct vnode 
{
    vertex_t v; 
    hlist_t* ph_head_node; 
    struct vnode* v_prev; 
    struct vnode* v_next; 
};  

struct graph 
{
    vlist_t* pv_head_node; 
    size_t number_of_vertices; 
    size_t number_of_edges; 
}; 

graph_t* create_graph(void); 

status_t insert_vertex(graph_t* g, vertex_t new_vertex); 
status_t remove_vertex(graph_t* g, vertex_t r_vertex); 
status_t insert_edge(graph_t* g, vertex_t v_start, vertex_t v_end); 
status_t remove_edge(graph_t* g, vertex_t v_start, vertex_t v_end); 

void show_graph(graph_t* g, const char* msg); 
status_t destroy_graph(graph_t** pp_g); 

vlist_t* v_create_list(void); 
status_t v_insert_end(vlist_t* pv_list, vertex_t new_vertex); 

void v_generic_insert(vnode_t* pv_start, vnode_t* pv_mid, vnode_t* pv_end); 
void v_generic_delete(vnode_t* pv_delete_node); 
vnode_t* v_search_node(vlist_t* pv_list, vertex_t v); 
vnode_t* v_get_list_node(vertex_t v); 

hlist_t* h_create_list(void); 
status_t h_insert_end(hlist_t* ph_list, vertex_t new_vertex); 

void h_generic_insert(hnode_t* ph_start, hnode_t* ph_mid, hnode_t* ph_end); 
void h_generic_delete(hnode_t* ph_delete_node); 
hnode_t* h_search_node(hlist_t* ph_list, vertex_t v); 
hnode_t* h_get_list_node(vertex_t v); 

void* xmalloc(size_t size_in_bytes); 

// =========================================================

#include <stdio.h> 
#include <stdlib.h> 
#include <assert.h> 
#include <string.h> 

#define TRUE    1 
#define FALSE   0 
#define SUCCESS 1 

#define G_INVALID_VERTEX    -2 
#define G_VERTEX_EXISTS     -3 
#define G_INVALID_EDGE      -4 
#define G_EDGE_EXISTS       -5 

typedef int     vertex_t; 
typedef int     status_t; 
typedef struct hnode    hnode_t; 
typedef hnode_t         hlist_t; 
typedef struct vnode    vnode_t; 
typedef vnode_t         vlist_t; 
typedef struct graph    graph_t; 

struct hnode 
{
    vertex_t v; 
    struct hnode* h_prev; 
    struct hnode* h_next; 
}; 

struct vnode 
{
    vertex_t v; 
    hlist_t* ph_head_node; 
    struct vnode_t* v_prev; 
    struct vnode_t* v_next; 
}; 

struct graph 
{
    vlist_t* pv_head_node; 
    size_t nr_vertices; 
    size_t nr_edges; 
}; 

// interface functions 
// creation 
graph_t* create_graph(void); 

// addition and removal 
status_t add_vertex(graph_t* g, vertex_t v); 
status_t add_edge(graph_t* g, vertex_t v_start, vertex_t v_end); 
status_t remove_vertex(graph_t* g, vertex_t v); 
status_t remove_edge(graph_t* g, vertex_t v_start, vertex_t v_end); 

void show_graph(graph_t* g, const char* msg); 
status_t destroy_graph(graph_t** pp_g); 

vlist_t* v_create_list(void); 
status_t v_insert_end(vlist_t* pv_list, vertex_t v); 

void v_generic_insert(vnode_t* pv_start, vnode_t* pv_mid, vnode_t* pv_end); 
void v_generic_delete(vnode_t* pv_delete_node); 
vnode_t* v_search_node(vlist_t pv_list, vertex_t v); 
vnode_t* v_get_list_node(vertex_t v); 

hlist_t* h_create_list(void); 
status_t h_insert_end(hlist_t* ph_list, vertex_t v); 

void h_generic_insert(hnode_t* ph_start, hnode_t* ph_mid, hnode_t* ph_end); 
void h_generic_delete(hnode_t* ph_delete_node); 
hnode_t* h_search_node(hlist_t* ph_list, vertex_t v); 
hnode_t* h_get_list_node(vertex_t v); 

void* xmalloc(size_t size_in_bytes); 

// =========================================================

#include <stdio.h> 
#include <stdlib.h> 
#include <assert.h> 
#include <string.h> 

#define TRUE    1 
#define FALSE   0 
#define SUCCESS 1 

#define G_INVALID_VERTEX    -2 
#define G_VERTEX_EXISTS     -3 
#define G_INVALID_EDGE      -4 
#define G_EDGE_EXISTS       -5 

typedef int     status_t; 
typedef int     vertex_t; 
typedef struct hnode    hnode_t; 
typedef hnode_t         hlist_t; 
typedef struct vnode    vnode_t; 
typedef vnode_t         vlist_t; 
typedef struct graph    graph_t; 

struct hnode 
{
    vertex_t v; 
    struct hnode* h_prev; 
    struct hnode* h_next; 
}; 

struct vnode 
{
    vertex_t v; 
    hlist_t* ph_head_node; 
    struct vnode* v_prev;  
    struct vnode* v_next;
}; 

struct graph 
{
    vlist_t* pv_head_node; 
    size_t nr_vertices; 
    size_t nr_edges; 
}; 

graph_t* create_graph(void); 

status_t insert_vertex(graph_t* g, vertex_t new_vertex); 
status_t insert_edge(graph_t* g, vertex_t v_start, vertex_t v_end); 
status_t remove_vertex(graph_t* g, vertex_t r_vertex); 
status_t remove_edge(graph_t* g, vertex_t v_start, vertex_t v_end); 

void show_grapg(graph_t* g, const char* msg); 
status_t destroy_graph(graph_t** pp_g); 

// vertical list management functions 
vlist_t* v_create_list(void); 
status_t v_insert_end(vlist_t* pv_list, vertex_t new_vertex); 

void v_generic_insert(vnode_t* pv_start, vnode_t* pv_mid, vnode_t* pv_end); 
void v_generic_delete(vnode_t* pv_delete_node); 
vnode_t* v_search_node(vlist_t* pv_list, vertex_t v); 
vnode_t* v_get_list_node(vertex_t v); 

// horizontal list management functions 
hlist_t* h_create_list(void); 
status_t h_insert_end(hlist_t* ph_list, vertex_t new_vertex); 

void h_generic_insert(hnode_t* ph_start, hnode_t* ph_mid, hnode_t* ph_end); 
void h_generic_delete(hnode_t* ph_delete_node); 
hnode_t* h_search_node(hlist_t* ph_list, vertex_t v); 
hnode_t* h_get_list_node(vertex_t v); 

void* xmalloc(size_t size_in_bytes); 

// =========================================================

#include <stdio.h> 
#include <stdlib.h> 
#include <assert.h> 
#include <string.h> 

#define TRUE    1 
#define FALSE   0 
#define SUCCESS 1 

#define G_INVALID_VERTEX    -2 
#define G_VERTEX_EXISTS     -3 
#define G_INVALID_EDGE      -4 
#define G_EDGE_EXISTS       -5 

typedef int     status_t; 
typedef int     vertex_t; 
typedef struct hnode    hnode_t; 
typedef hnode_t         hlist_t; 
typedef struct vnode    vnode_t; 
typedef vnode_t         vlist_t; 
typedef struct graph    graph_t; 

struct hnode 
{
    vertex_t v; 
    struct hnode* h_prev; 
    struct hnode* h_next; 
}; 

struct vnode 
{
    vertex_t v; 
    hlist_t* ph_head_node; 
    struct vnode* v_prev; 
    struct vnode* v_next; 
}; 

struct graph 
{
    vlist_t* pv_head_node; 
    size_t nr_vertices; 
    size_t nr_edges; 
}; 

graph_t* create_graph(void); 

status_t insert_vertex(graph_t* g, vertex_t new_vertex); 
status_t insert_edge(graph_t* g, vertex_t v_start, vertex_t v_end); 
status_t remove_vertex(graph_t* g, vertex_t r_vertex); 
status_t remove_edge(graph_t* g, vertex_t v_start, vertex_t v_end); 

void show_graph(graph_t* g, const char* msg); 
status_t destroy_graph(graph_t** pp_g); 

// vertical list 
vlist_t* v_create_list(void); 
status_t v_insert_end(vlist_t* pv_list, vertex_t new_vertex); 

void v_generic_insert(vnode_t* pv_start, vnode_t* pv_mid, vnode_t* pv_end); 
void v_generic_delete(vnode_t* pv_delete_node); 
vnode_t* v_search_node(vlist_t* pv_list, vertex_t s_vertex); 
vnode_t* v_get_list_node(vertex_t v); 

// horizontal list 
hlist_t* h_create_list(void); 
status_t h_insert_end(hlist_t* ph_list, vertex_t new_vertex); 

void h_generic_insert(hnode_t* ph_start, hnode_t* ph_mid, hnode_t* ph_end); 
void h_generic_delete(hnode_t* ph_delete_ndoe); 
hnode_t* h_search_node(hlist_t* ph_list, vertex_t s_vertex); 
hnode_t* h_get_list_node(vertex_t v); 

void* xmalloc(size_t size_in_bytes); 

// =========================================================

void test_graph(void); 

int main(void) 
{
    test_graph(); 
    return (0); 
} 

void test_graph(void) 
{

} 

void test_graph(void); 

int main(void) 
{
    test_graph(); 
    return (0); 
} 

void test_graph(void) 
{

} 

void test_graph(void); 

int main(void) 
{
    test_graph(); 
    return (0); 
} 

void test_graph(void) 
{

} 

void test_graph(void); 

int main(void) 
{
    test_graph(); 
    return (0); 
} 

void test_graph(void) 
{

} 

void test_graph(void); 

int main(void) 
{
    test_graph(); 
    return (0); 
} 

void test_graph(void) 
{

} 

//==========================================

graph_t* create_graph(void) 
{

} 

status_t add_vertex(graph_t* g, vertex_t v) 
{

} 

status_t remove_vertex(graph_t* g, vertex_t v) 
{

} 

status_t add_edge(graph_t* g, vertex_t v_start, vertex_t v_end) 
{

} 

status_t remove_edge(graph_t* g, vertex_t v_start, vertex_t v_end) 
{

} 

void show_graph(graph_t* g, const char* msg) 
{

} 

status_t destroy_graph(graph_t** pp_g) 
{

} 

vlist_t* v_create_list(void) 
{

} 

status_t v_insert_end(graph_t* g, vertex_t v) 
{

} 

void v_generic_insert(vnode_t* pv_start, vnode_t* pv_mid, vnode_t* pv_end) 
{

} 

void v_generic_delete(vnode_t* pv_delete_node) 
{

} 

vnode_t* v_search_node(graph_t* g, vertex_t v) 
{

} 

vnode_t* v_get_list_node(vertex_t v) 
{

} 

hlist_t* h_create_list(void) 
{

} 

status_t h_insert_end(hlist_t* ph_list, vertex_t new_vertex) 
{

} 

void h_generic_insert(hnode_t* ph_start, hnode_t* ph_mid, hnode_t* ph_end) 
{

} 

hnode_t* h_search_node(hlist_t* ph_list, vertex_t v) 
{

} 

hnode_t* h_get_list_node(vertex_t v) 
{
    hnode_t* ph_new_node = NULL; 

    ph_new_node = (hnode_t*)xmalloc(sizeof(hnode_t)); 
    ph_new_node->v = v; 
    ph_new_node->h_prev = NULL; 
    ph_new_node->h_next = NULL; 
} 

void* xmalloc(size_t size_in_bytes) 
{
    void* p = NULL; 

    p = malloc(size_in_bytes); 
    if(NULL == p) 
    {
        puts("malloc() failed"); 
        exit(EXIT_FAILURE); 
    } 
    return (p); 
} 

//==========================================

graph_t* create_graph(void) 
{

} 

status_t add_vertex(graph_t* g, vertex_t new_vertex) 
{

} 

status_t remove_vertex(graph_t* g, vertex_t r_vertex) 
{

} 

status_t add_edge(graph_t* g, vertex_t v_start, vertex_t v_end) 
{

} 

status_t remove_edge(graph_t* g, vertex_t v_start, vertex_t v_end) 
{

} 

void show_graph(graph_t* g, const char* msg) 
{

} 

status_t destroy_graph(graph_t** pp_g) 
{

} 

vlist_t* v_create_list(void) 
{

} 

status_t v_insert_end(vlist_t* pv_list, vertex_t new_vertex) 
{

} 

void v_generic_insert(vnode_t* pv_start, vnode_t* pv_mid, vnode_t* pv_end) 
{

} 

void v_generic_delete(vnode_t* pv_delete_node) 
{

} 

vnode_t* v_search_node(vlist_t* pv_list, vertex_t v) 
{ 

} 

vnode_t* v_get_list_node(vertex_t v) 
{

} 

hlist_t* h_create_list(void) 
{

} 

status_t h_insert_end(hlist_t* ph_list, vertex_t v_end) 
{

} 

void h_generic_insert(hnode_t* ph_start, hnode_t* ph_mid, hnode_t* ph_end) 
{

} 

void h_generic_delete(hnode_t* ph_delete_node) 
{

} 

hnode_t* h_search_node(hlist_t* ph_list, vertex_t s_vertex) 
{

} 

hnode_t* h_get_list_node(vertex_t v) 
{
    hnode_t* ph_new_node = NULL; 

    ph_new_node = (hnode_t*)xmalloc(sizeof(hnode_t)); 
    ph_new_node->v = v; 
    ph_new_node->h_prev = NULL; 
    ph_new_node->h_next = NULL; 

    return (ph_new_node); 
} 

void* xmalloc(size_t nr_bytes) 
{
    void* p = NULL; 

    p = malloc(nr_bytes); 
    if(NULL == p) 
    {
        puts("failed to allocate memory"); 
        exit(EXIT_FAILURE); 
    } 

    return (p); 
} 

//==========================================

graph_t* create_graph(void) 
{

} 

status_t add_vertex(graph_t* g, vertex_t new_vertex) 
{

} 

status_t remove_vertex(graph_t* g, vertex_t r_vertex) 
{

} 

status_t remove_vertex(graph_t* g, vertex_t r_vertex) 
{

} 

status_t remove_edge(graph_t* g, vertex_t v_start, vertex_t v_end) 
{

} 

void show_graph(graph_t* g, const char* msg) 
{

} 

status_t destroy_graph(graph_t** pp_g) 
{

} 

vlist_t* v_create_list(void) 
{

} 

status_t v_insert_end(vlist_t* pv_list, vertex_t new_vertex) 
{

} 

void v_generic_insert(vnode_t* pv_start, vnode_t* pv_mid, vnode_t* pv_end) 
{

} 

void v_generic_delete(vnode_t* pv_delete_node) 
{

} 

vnode_t* v_search_node(vlist_t* pv_list, vertex_t s_vertex) 
{

} 

vnode_t* v_get_list_node(vertex_t v) 
{
    vnode_t* pv_new_node = NULL; 

    pv_new_node = (vnode_t*)xmalloc(sizeof(vnode_t)); 
    pv_new_node->data = v; 
    pv_new_node->v_prev = NULL; 
    pv_new_node->v_next = NULL; 

    return (pv_new_node); 
} 

void* xmalloc(size_t size_in_bytes) 
{
    void* p = NULL; 

    p = malloc(size_in_bytes); 
    if(NULL == p) 
    {
        puts("malloc():fatal:out of memory"); 
        exit(EXIT_FAILURE); 
    } 

    return (p); 
} 

hlist_t* h_create_list(void) 
{

} 

status_t h_insert_end(hlist_t* ph_list, vertex_t new_vertex) 
{

} 

void h_generic_insert(hnode_t* ph_start, hnode_t* ph_mid, hnode_t* ph_end) 
{

} 

void h_generic_delete(hnode_t* ph_delete_node) 
{

} 

hnode_t* h_search_node(hlist_t* ph_list, vertex_t s_vertex) 
{

} 

hnode_t* h_get_list_node(vertex_t new_vertex) 
{
    hnode_t* ph_new_node = NULL; 

    ph_new_node = (hnode_t*)xmalloc(sizeof(hnode_t)); 
    ph_new_node->v = new_vertex; 
    ph_new_node->h_prev = NULL; 
    ph_new_node->h_next = NULL; 

    return (ph_new_node); 
} 

void* xmalloc(size_t size_in_bytes) 
{
    void* p = NULL; 

    p = malloc(size_in_bytes); 
    if(NULL == p) 
    {
        puts("malloc():fatal:out of memory"); 
        exit(EXIT_FAILURE); 
    } 
    
    return (p); 
} 

//==========================================

graph_t* create_graph(void) 
{

} 

status_t add_vertex(graph_t* g, vertex_t new_vertex) 
{

} 

status_t remove_vertex(graph_t* g, vertex_t r_vertex) 
{

} 

status_t add_edge(graph_t* g, vertex_t v_start, vertex_t v_end) 
{

} 

status_t remove_edge(graph_t* g, vertex_t v_start, vertex_t v_end) 
{

} 

void show_graph(graph_t* g, const char* msg) 
{

} 

status_t destroy_graph(graph_t** pp_g) 
{

} 

vlist_t* v_create_list(void) 
{

} 

status_t v_insert_end(vlist_t* pv_list, vertex_t new_vertex) 
{

} 

void v_generic_insert(vnode_t* pv_start, vnode_t* pv_mid, vnode_t* pv_end) 
{

} 

void v_generic_delete(vnode_t* pv_delete_node) 
{

} 

vnode_t* v_search_node(vlist_t* pv_list, vertex_t s_vertex) 
{

}

vnode_t* v_get_list_node(vertex_t new_vertex) 
{

} 

hlist_t* h_create_list(void) 
{

} 

status_t h_insert_end(hlist_t* ph_list, vertex_t new_vertex) 
{

} 

void h_generic_insert(hnode_t* ph_start, hnode_t* ph_end, hnode_t* ph_end) 
{

} 

void h_generic_delete(hnode_t* ph_delete_node) 
{

} 

hnode_t* h_search_node(hlist_t* ph_list, vertex_t s_vertex) 
{

} 

hnode_t* h_get_list_node(vertex_t new_vertex) 
{
    hnode_t* ph_new_node = NULL; 

    ph_new_node = (hnode_t*)xmalloc(sizeof(hnode_t)); 
    ph_new_node->v = new_vertex; 
    ph_new_node->h_prev = NULL; 
    ph_new_node->h_next = NULL; 

    return (ph_new_node); 
}

void* xmalloc(size_t size_in_bytes) 
{
    void* p = NULL; 

    p = malloc(size_in_bytes); 
    if(NULL == p) 
    {
        puts("malloc():fatal:out of memory"); 
        exit(EXIT_FAILURE); 
    } 

    return (p); 
} 

//==========================================

graph_t* create_graph(void) 
{ 

} 

status_t add_vertex(graph_t* g, vertex_t new_vertex) 
{

} 

status_t add_edge(graph_t* g, vertex_t v_start, vertex_t v_end) 
{ 

} 

status_t remove_vertex(graph_t* g, vertex_t r_vertex) 
{

} 

status_t remove_edge(graph_t* g, vertex_t v_start, vertex_t v_end) 
{
    
} 

vlist_t* v_create_list(void) 
{

} 

status_t v_insert_end(vlist_t* pv_list, vertex_t new_vertex) 
{

} 

void v_generic_insert(vnode_t* pv_start, vnode_t* pv_mid, vnode_t* pv_end) 
{

} 

void v_generic_delete(vnode_t* pv_delete_node) 
{

} 

vnode_t* v_search_node(vlist_t* pv_list, vertex_t v) 
{

} 

vnode_t* v_get_list_node(vertex_t new_vertex) 
{
    
} 

hlist_t* h_create_list(void) 
{

} 

status_t h_insert_end(hlist_t* ph_list, vertex_t new_vertex) 
{

} 

void h_generic_insert(hnode_t* ph_start, hnode_t* ph_mid, hnode_t* ph_end) 
{

} 

void h_generic_delete(hnode_t* ph_delete_node) 
{

} 

hnode_t* h_search_node(hlist_t* ph_list, vertex_t s_vertex) 
{

} 

hnode_t* h_get_list_node(vertex_t v) 
{
    hnode_t* ph_new_node = NULL; 

    ph_new_node = (hnode_t*)xmalloc(sizeof(hnode_t)); 
    ph_new_node->v = v; 
    ph_new_node->h_prev = NULL; 
    ph_new_node->h_next = NULL; 

    return (ph_new_node); 
} 

void* xmalloc(size_t nr_bytes) 
{
    void* p = NULL; 

    p = malloc(nr_bytes); 
    if(NULL == p) 
    {
        puts("malloc()::fatal:out of memory"); 
        exit(EXIT_FAILURE); 
    } 

    return (p); 
} 

//==========================================

graph_t* create_graph(void) 
{

} 

status_t add_vertex(graph_t* g, vertex_t new_vertex) 
{

} 

status_t add_edge(graph_t* g, vertex_t v_start, vertex_t v_end) 
{

} 

status_t remove_vertex(graph_t* g, vertex_t r_vertex) 
{

}

status_t remove_edge(graph_t* g, vertex_t v_start, vertex_t v_end) 
{

} 

//==========================================

