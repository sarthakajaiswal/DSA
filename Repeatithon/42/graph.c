#ifndef _GRAPH_H 
#define _GRAPH_H 

#include <stdio.h> 
#include <stdlib.h> 
#include <assert.h> 

#define TRUE    1 
#define FALSE   0 
#define SUCCESS 1 

#define G_VERTEX_EXISTS     -1 
#define G_INVALID_VERTEX    -2 
#define G_EDGE_EXISTS       -3 
#define G_INVALID_EDGE      -4 

typedef int     vertex_t; 
typedef int     status_t; 
typedef struct hnode    hnode_t; 
typedef hnode_t         hlist_t; 
typedef struct vnode    vnode_t; 
typedef vnode_t         vlist_t; 
typedef struct graph    graph_t;
typedef enum color      color_t;  
typedef enum color      color_t; 
typedef enum color      color_t; 
typedef enum color      color_t; 
typedef enum color      color_t; 

enum color {WHITE=0, GREY, BLACK}; 
enum color { WHITE=0, GREY, BLACK }; 
enum color { WHITE=0, GREY, BLACK }; 
enum color { WHITE=0, GREY, BLACK }; 
enum color { WHITE=0, GREY, BLACK }; 

struct hnode 
{
    vertex_t v; 
    struct hnode* h_next; 
    struct hnode* h_prev; 
}; 

struct vnode 
{
    vertex_t v; 
    hlist_t* ph_head_node; 
    color_t color; 
    struct vnode* v_next; 
    struct vnode* v_prev; 
}; 

struct graph 
{
    vlist_t* pv_head_node; 
    size_t nr_vertices; 
    size_t nr_edges; 
}; 

/* Graph interface routines */ 
// creation 
graph_t* create_graph(void); 

// addition and removal 
status_t add_vertex(graph_t* g, vertex_t v); 
status_t remove_vertex(graph_t* g, vertex_t v); 
status_t add_edge(graph_t* g, vertex_t v_start, vertex_t v_end); 
status_t remove_edge(graph_t* g, vertex_t v_start, vertex_t v_end); 

// show 
void show_graph(graph_t* g, const char* msg); 

// destroy 
status_t destroy_graph(graph_t** pp_g); 

/* Graph helper functions */ 
/* vertical list management */ 
/* vertical list interface routines */ 
vlist_t* v_create_list(void); 
status_t v_insert_end(vlist_t* pv_list, vertex_t new_vertex); 

/* vertical list helper routines */ 
void v_generic_insert(vnode_t* pv_beg, vnode_t* pv_mid, vnode_t* pv_end); 
void v_generic_delete(vnode_t* pv_delete_node); 
vnode_t* v_search_node(vlist_t* pv_list, vertex_t s_vertex); 
vnode_t* v_get_list_node(vertex_t new_vertex); 

/* Horizontal list management */ 
/* horizontal list interface routines */ 
hlist_t* h_create_list(void); 
status_t h_insert_end(hlist_t* ph_list, vertex_t new_vertex); 

/* horizontal list helper routines */ 
void h_generic_insert(hnode_t* ph_beg, hnode_t* ph_mid, hnode_t* ph_end); 
void h_generic_delete(hnode_t* ph_delete_node); 
hnode_t* h_search_node(hlist_t* ph_list, vertex_t s_vertex); 
hnode_t* h_get_list_node(vertex_t new_vertex); 

/* Graph General perpose helper functions */ 
void* xmalloc(size_t size_in_bytes); 

#endif /* _GRAPH_H */ 

#ifndef _GRAPH_H 
#define _GRAPH_H 

#include <stdio.h> 
#include <stdlib.h> 
#include <assert.h> 
#include "graph.h" 

#define TRUE    1 
#define FALSE   0 
#define SUCCESS 1 

#define G_VERTEX_EXISTS     -1 
#define G_INVALID_VERTEX    -2 
#define G_EDGE_EXISTS       -3 
#define G_INVALID_EDGE      -4 

typedef int     vertex_t; 
typedef int     status_t; 
typedef struct vnode    vnode_t; 
typedef vnode_t         vlist_t; 
typedef struct hnode    hnode_t; 
typedef hnode_t         hlist_t; 
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

/* Graph interface routines */ 
// creation 
graph_t* create_graph(void); 

// addition and removal 
status_t add_vertex(graph_t* g, vertex_t new_vertex); 
status_t remove_vertex(graph_t* g, vertex_t r_vertex); 
status_t add_edge(graph_t* g, vertex_t v_start, vertex_t v_end); 
status_t remove_edge(graph_t* g, vertex_t v_start, vertex_t v_end); 

// show 
void show_graph(graph_t* g, const char* msg); 

// destruction 
status_t destroy_graph(graph_t** pp_g); 

/* Graph helper routines */ 
/* Vertical list management */ 
/* vertical list interface functions */ 
vlist_t* v_create_list(void); 
status_t v_insert_end(vlist_t* pv_list, vertex_t new_vetex); 

/* vertical list helper functions */ 
void v_generic_insert(vnode_t* pv_beg, vnode_t* pv_mid, vnode_t* pv_end); 
void v_generic_delete(vnode_t* pv_delete_node); 
vnode_t* v_search_node(vlist_t* pv_list, vertex_t s_vertex); 
vnode_t* v_get_list_node(vertex_t new_vertex); 

/* Horizontal list management */ 
/* horizontal list interface functions */ 
hlist_t* h_create_list(void); 
status_t h_insert_end(hlist_t* ph_list, vertex_t new_vertex); 

/* horizontal list helper funtions */ 
void h_generic_insert(hnode_t* ph_beg, hnode_t* ph_mid, hnode_t* ph_end); 
void h_generic_delete(hnode_t* ph_delete_node); 
hnode_t* h_search_node(hlist_t* ph_list, vertex_t s_vertex); 
hnode_t* h_get_list_node(vertex_t new_vertex); 

/* Graph general purpose routines */ 
void* xmalloc(size_t size_in_bytes); 

#endif /* _GRAPH_H */ 

#ifndef _GRAPH_H 
#define _GRAPH_H 

#include <stdio.h> 
#include <stdlib.h> 
#include <assert.h> 
#include "graph.h" 

#define TRUE    1 
#define FALSE   0 
#define SUCCESS 1 

#define G_VERTEX_EXISTS     -1 
#define G_INVALID_VERTEX    -2 
#define G_EDGE_EXISTS       -3 
#define G_INVALID_EDGE      -4  

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
    struct vnode* v_next; 
    struct vnode* v_prev; 
}; 

struct graph 
{
    vlist_t* pv_head_node; 
    unsigned long nr_edges; 
    unsigned long nr_vertices; 
}; 

/* Graph Interface Functions */ 
// creation 
graph_t* create_graph(void); 

// addition and removal 
status_t add_vertex(graph_t* g, vertex_t new_vertex); 
status_t remove_vertex(graph_t* g, vertex_t remove_vertex); 
status_t add_edge(graph_t* g, vertex_t v_start, vertex_t v_end); 
status_t remove_edge(graph_t* g, vertex_t v_start, vertex_t v_end); 

// show 
void show_graph(graph_t* g, const char* msg); 

// destruction 
status_t destroy_graph(graph_t** pp_g); 

/* graph helper functions */ 
/* Vertical list management */ 
/* vertical list interface functions */ 
vlist_t* v_create_list(void); 
status_t v_insert_end(vlist_t* pv_list, vertex_t new_vertex); 

/* vertical list helper functions */ 
void v_generic_insert(vnode_t* pv_beg, vnode_t* pv_mid, vnode_t* pv_end); 
void v_generic_delete(vnode_t* pv_delete_node); 
vnode_t* v_search_node(vlist_t* pv_list, vertex_t s_vertex); 
vnode_t* v_get_list_node(vertex_t new_vertex); 

/* Horizontal list management */ 
/* horizontal list interface functions */ 
hlist_t* h_create_list(void); 
status_t h_insert_end(hlist_t* ph_list, vertex_t new_vertex); 

/* horizontal list helper functions */ 
void h_generic_insert(hnode_t* ph_beg, hnode_t* ph_mid, hnode_t* ph_end); 
void h_generic_delete(hnode_t* ph_delete_node); 
hnode_t* h_search_node(hlist_t* ph_list, vertex_t s_vertex); 
hnode_t* h_get_list_node(vertex_t new_vertex); 

/* general purpose helper functions */ 
void* xmalloc(size_t size_in_butes); 

#endif /* _GRAPH_H */ 

#ifndef _GRAPH_H 
#define _GRAPH_H 

#include <stdio.h> 
#include <stdlib.h> 
#include <assert.h> 
#include "graph.h" 

#define TRUE    1 
#define FALSE   0 
#define SUCCESS 1 

#define G_VERTEX_EXISTS     -1 
#define G_INVALID_VERTEX    -2 
#define G_EDGE_EXISTS       -3 
#define G_INVALID_EDGE      -4 

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
    struct hnode h_prev; 
    struct hnode h_next; 
}; 

struct vnode 
{
    vertex_t v; 
    hlist_t* ph_head_node; 
    struct vnode* pv_next; 
    struct vnode* pv_prev; 
}; 

struct graph 
{
    vlist_t* pv_head_node; 
    size_t nr_vertices; 
    size_t nr_edges; 
}; 

/* Graph interface functions */ 
// creation 
graph_t* create_graph(void); 

// addition and removal 
status_t add_vertex(graph_t* g, vertex_t new_vertex); 
status_t remove_vertex(graph_t* g, vertex_t r_vertex); 
status_t add_edge(graph_t* g, vertex_t v_start, vertex_t v_end); 
status_t remove_edge(graph_t* g, vertex_t v_start, vertex_t v_end); 

// show 
void show_graph(graph_t* g, const char* msg); 

// destruction 
status_t destroy_graph(graph_t** pp_g); 

/* Graph helper functions */ 
/* vertical list management */ 
/* vertical list interface functions */ 
vlist_t* v_create_list(void); 
status_t v_insert_end(vlist_t* pv_list, vertex_t new_vertex); 

/* vertical list helper functions */ 
void v_generic_insert(vnode_t* pv_beg, vnode_t* pv_mid, vnode_t* pv_end); 
void v_generic_delete(vnode_t* pv_delete_node);
vnode_t* v_search_node(vlist_t* pv_list, vertex_t s_vertex);  
vnode_t* v_get_list_node(vertex_t new_vertex); 

/* Horizontal list management */ 
/* Horizontal list interface functions */ 
hlist_t* h_create_list(void); 
status_t h_insert_end(hlist_t* ph_list, vertex_t new_vertex); 

/* Horizontal list helper functions */ 
void h_generic_insert(hnode_t* ph_beg, hnode_t* ph_mid, hnode_t* ph_end); 
void h_generic_delete(hnode_t* ph_delete_node); 
hnode_t* h_search_node(hlist_t* ph_list, vertex_t new_vertex); 
hnode_t* h_get_list_node(vertex_t new_vertex); 

/* general purpose helper functions */ 
void* xmalloc(size_t size_in_bytes); 

#endif /* _GRAPH_H */ 

#ifndef _GRAPH_H 
#define _GRAPH_H 

#include <stdio.h> 
#include <stdlib.h> 
#include <assert.h> 
#include "graph.h" 

#define TRUE    1 
#define FALSE   0 
#define SUCCESS 1 
#define G_VERTEX_EXISTS     -1 
#define G_INALID_VERTEX     -2 
#define G_EDGE_EXISTS       -3 
#define G_INVALID_EDGE      -4 

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
    struct hnode h_prev; 
    struct hnode h_next; 
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

/* Graph interface functions */
// creation 
graph_t* create_graph(void); 

// addition and removal 
status_t add_vertex(graph_t* g, vertex_t new_vertex); 
status_t remove_vertex(graph_t* g, vertex_t r_vertex); 
status_t add_edge(graph_t* g, vertex_t v_start, vertex_t v_end); 
status_t remove_edge(graph_t* g, vertex_t v_start, vertex_t v_end); 

// show 
void show_graph(graph_t* g, const char* msg); 

// destruction 
status_t destroy_graph(graph_t** pp_g); 

/* Graph Helper functions */ 
/* Vertical list management functions */ 
/* Vertical list interface */ 
vlist_t* v_create_list(void); 
status_t v_insert_end(vlist_t* pv_list, vertex_t new_vertex); 

/* vertical list helpers */ 
void v_generic_insert(vnode_t* pv_beg, vnode_t* pv_mid, vnode_t* pv_end); 
void v_generic_delete(vnode_t* pv_delete_node); 
vnode_t* v_search_node(vlist_t* pv_list, vertex_t search_vertex); 
vnode_t* v_get_list_node(vertex_t new_vertex); 

/* Horizontal list management functions */ 
/* horizontal list interface */ 
hlist_t* h_create_list(void); 
status_t h_insert_end(hlist_t* ph_list, vertex_t new_vertex); 

/* horizontal list helpers */ 
void h_generic_insert(hnode_t* ph_beg, hnode_t* ph_mid, hnode_t* ph_end); 
void h_generic_delete(hnode_t* ph_delete_node); 
status_t h_search_node(hlist_t* ph_list, vertex_t s_vertex); 
status_t h_get_list_node(vertex_t new_vertex); 

/* general purpose helper routines */ 
void* xmalloc(size_t size_in_bytes); 

#endif /* _GRAPH_H */ 

#include "graph.h" 
#include "graph.h" 
#include "graph.h" 
#include "graph.h" 
#include "graph.h" 

graph_t* create_graph(void) 
{
    graph_t* g = NULL; 

    g = xmalloc(sizeof(graph_t)); 
    g->pv_head_node = v_create_list(); 
    g->nr_vertices = 0; 
    g->nr_edges = 0; 

    return (g); 
} 

graph_t* create_graph(void) 
{
    graph_t* g = NULL; 

    g = xmalloc(sizeof(graph_t)); 
    g->pv_head_node = v_create_list(); 
    g->nr_vertices = 0; 
    g->nr_edges = 0; 

    return (g); 
} 

graph_t* create_graph(void) 
{
    graph_t* g = NULL; 

    g = xmalloc(sizeof(graph_t)); 
    g->pv_head_node = NULL; 
    g->nr_vertices = 0; 
    g->nr_edges = 0; 

    return (g); 
} 

graph_t* create_graph(void) 
{
    graph_t* g = NULL; 

    g = xmalloc(sizeof(graph_t)); 
    g->pv_head_node = v_create_list(); 
    g->nr_vertices = 0; 
    g->nr_edges = 0; 

    return (g); 
} 

graph_t* create_graph(void) 
{
    graph_t* g = NULL; 

    g = xmalloc(sizeof(graph_t)); 
    g->pv_head_node = v_create_list(); 
    g->nr_vertices = 0; 
    g->nr_edges = 0; 

    return (g); 
} 

status_t add_vertex(graph_t* g, vertex_t new_vertex) 
{
    vnode_t* p = NULL; 
    status_t status; 

    p = v_search_node(g->pv_head_node, new_vertex); 
    if(p != NULL) 
        return (G_VERTEX_EXISTS); 

    status = v_insert_end(g->pv_head_node, new_vertex); 
    assert(status == SUCCESS); 

    g->nr_vertices += 1; 
    return (SUCCESS); 
} 

status_t add_vertex(graph_t* g, vertex_t new_vertex) 
{
    vnode_t* p = NULL; 
    
    p = v_search_node(g->pv_head_node, new_vertex);
    if(p != NULL) 
        return (G_VERTEX_EXISTS); 

    assert(insert_end(g->pv_head_node, new_vertex) == SUCCESS); 
    g->nr_vertices += 1; 

    return (SUCCESS); 
} 

status_t add_vertex(graph_t* g, vertex_t new_vertex) 
{
    vnode_t* p = NULL; 

    p = v_search_node(g->pv_head_node, new_vertex); 
    if(p != NULL) 
        return (G_VERTEX_EXISTS); 

    assert(insert_end(g->pv_head_node, new_vertex) == SUCCESS); 
    g->nr_vertices += 1; 

    return (SUCCESS); 
} 

status_t add_vertex(graph_t* g, vertex_t new_vertex) 
{
    vnode_t* p = NULL; 

    p = v_search_node(g->pv_head_node, new_vertex); 
    if(NULL == p) 
        return (G_VERTEX_EXISTS); 

    assert(v_insert_end(g->pv_head_node, new_vertex) == SUCCESS); 
    g->nr_vertices += 1; 

    return (SUCCESS); 
} 

status_t add_vertex(graph_t* g, vertex_t new_vertex) 
{
    vnode_t* p = NULL; 

    p = v_search_node(g->pv_head_node, new_vertex); 
    if(NULL == p) 
        return (G_VERTEX_EXISTS); 

    assert(v_insert_end(g->pv_head_node, new_vertex) == SUCCESS); 
    g->nr_vertices += 1; 

    return (SUCCESS); 
} 

status_t remove_vertex(graph_t* g, vertex_t r_vertex) 
{
    vnode_t* pv_delete = NULL; 
    vnode_t* pv_h_in_vlist = NULL; 

    hnode_t* ph_delete_node_in_adj_list = NULL; 
    hnode_t* ph_run = NULL; 
    hnode_t* ph_run_next = NULL; 

    pv_delete = v_search_node(g->pv_head_node, r_vertex); 
    if(NULL == pv_delete) 
        return (G_INVALID_VERTEX); 

    ph_run = pv_delete->ph_head_node->h_next; 
    while(ph_run != pv_delete->ph_head_node) 
    {
        ph_run_next = ph_run->h_next; 
        pv_h_in_vlist = v_search_node(g->pv_head_node, ph_run->v); 
        ph_delete_node_in_adj_list = h_search_node(pv_h_in_vlist, r_vertex); 
        h_generic_delete(ph_delete_node_in_adj_list); 

        free(ph_run); 
        g->nr_edges -= 1; 
        ph_run = ph_run_next; 
    } 

    free(pv_delete->ph_head_node); 
    v_generic_delete(pv_delete); 
    g->nr_vertices -= 1; 

    return (SUCCESS); 
} 

status_t remove_vertex(graph_t* g, vertex_t r_vertex) 
{
    vnode_t* pv_delete = NULL; 
    vnode_t* pv_h_in_vlist = NULL; 
    hnode_t* ph_run = NULL; 
    hnode_t* ph_run_next = NULL; 
    hnode_t* ph_delete_node_in_adj_list = NULL; 

    pv_delete = v_search_node(g->pv_head_node, r_vertex); 
    if(pv_delete != NULL) 
        return (G_INVALID_VERTEX); 

    ph_run = pv_delete->ph_head_node->h_next; 
    while(ph_run != pv_delete->ph_head_node) 
    {
        ph_run_next = ph_run->h_next; 
        pv_h_in_vlist = v_search_node(g->pv_head_node, ph_run->v); 
        ph_delete_node_in_adj_list = h_search_node(pv_h_in_vlist->ph_head_node, r_vertex); 
        h_generic_delete(ph_delete_node_in_adj_list); 
        free(ph_run); 
        g->nr_edges -= 1; 
        ph_run = ph_run_next; 
    } 

    free(pv_delete->ph_head_node); 
    generic_delete(pv_delete); 
    g->nr_vertices -= 1;

    return (SUCCESS); 
} 

status_t remove_vertex(graph_t* g, vertex_t r_vertex) 
{
    vnode_t* pv_delete = NULL; 
    vnode_t* pv_h_in_vlist = NULL; 
    hnode_t* ph_run = NULL; 
    hnode_t* ph_run_next = NULL; 
    hnode_t* ph_delete_node_in_adj_list = NULL; 

    pv_delete = v_search_node(g->pv_head_node, r_vertex); 
    if(NULL == pv_delete) 
        return (G_INVALID_VERTEX); 

    ph_run = pv_delete->ph_head_node->h_next; 
    while(ph_run != pv_delete->ph_head_node) 
    {
        ph_run_next = ph_run->h_next; 
        pv_h_in_vlist = v_search_node(g->pv_head_node, ph_run->v); 
        ph_delete_node_in_adj_list = h_search_node(pv_h_in_vlist->ph_head_node, r_vertex); 
        h_generic_delete(ph_delete_node_in_adj_list); 
        free(ph_run); 
        g->nr_edges -= 1; 
        ph_run = ph_run_next; 
    } 

    free(pv_delete->ph_head_node); 
    v_generic_delete(pv_delete); 
    g->nr_vertices -= 1; 

    return (SUCCESS); 
} 

status_t remove_vertex(graph_t* g, vertex_t r_vertex) 
{
    vnode_t* pv_delete = NULL; 
    hnode_t* ph_run = NULL; 
    hnode_t* ph_run_next = NULL; 
    vnode_t* pv_h_in_vlist = NULL; 
    hnode_t* ph_delete_node_in_adj_list = NULL; 
    
    pv_delete = v_search_node(g->pv_head_node, r_vertex); 
    if(pv_delete == NULL) 
        return (G_INVALID_VERTEX); 

    ph_run = pv_delete->ph_head_node->h_next; 
    while(ph_run != pv_delete->ph_head_node) 
    {
        ph_run_next = ph_run->h_next; 
        pv_h_in_vlist = v_search_node(g->pv_head_node, ph_run->v); 
        ph_delete_node_in_adj_list = h_search_node(pv_h_in_vlist->ph_head_node, r_vertex); 
        generic_delete(ph_delete_node_in_adj_list); 
        free(ph_run); 
        g->nr_edges -= 1; 
        ph_run = ph_run_next; 
    } 

    free(pv_delete->ph_head_node); 
    v_generic_delete(pv_delete); 
    g->nr_vertices -= 1; 

    return (SUCCESS); 
} 

status_t remove_vertex(graph_t* g, vertex_t r_vertex) 
{
    vnode_t* pv_delete = NULL; 
    hnode_t* ph_run = NULL; 
    hnode_t* ph_run_next = NULL; 
    vnode_t* pv_h_in_vlist = NULL; 
    hnode_t* ph_delete_node_in_adj_list = NULL; 

    pv_delete = v_search_node(g->pv_head_node, r_vertex); 
    if(pv_delete == NULL) 
        return (G_INVALID_VERTEX); 

    ph_run = pv_delete->ph_head_node->h_next; 
    while(ph_run != pv_delete->ph_head_node) 
    {
        ph_run_next = ph_run->h_next; 
        pv_h_in_vlist = v_search_node(g->pv_head_node, ph_run->v); 
        ph_delete_node_in_adj_list = h_search_node(pv_h_in_vlist->ph_head_node, r_vertex); 
        h_generic_delete(ph_delete_node_in_adj_list); 
        free(ph_run); 
        g->nr_edges -= 1; 
        ph_run = ph_run_next; 
    } 

    free(pv_delete->ph_head_node); 
    v_generic_delete(pv_delete); 
    g->nr_vertices -= 1; 

    return (SUCCESS); 
} 

status_t add_edge(graph_t* g, vertex_t v_start, vertex_t v_end) 
{
    vnode_t* pv_start = NULL; 
    vnode_t* pv_end = NULL; 
    hnode_t* ph_start_in_end = NULL; 
    hnode_t* ph_end_in_start = NULL; 
    status_t status; 

    pv_start = v_search_node(g->pv_head_node, v_start); 
    if(pv_start == NULL) 
        return (G_INVALID_VERTEX); 
    pv_end = v_search_node(g->pv_head_node, v_end); 
    if(pv_end == NULL) 
        return (G_INVALID_VERTEX); 

    ph_end_in_start = h_search_node(pv_start->ph_head_node, v_end); 
    if(ph_end_in_start != NULL) 
        return (G_EDGE_EXISTS); 
    ph_start_in_end = h_search_node(pv_end->ph_head_node, v_start); 
    if(ph_start_in_end != NULL) 
        return (G_EDGE_EXISTS); 
        
    status = h_insert_end(pv_start->ph_head_node, v_end); 
    assert(status == SUCCESS); 
    status = h_insert_end(pv_end->ph_head_node, v_start); 
    assert(status == SUCCESS); 

    g->nr_edges += 1; 

    return (SUCCESS); 
} 

status_t add_edge(graph_t* g, vertex_t v_start, vertex_t v_end) 
{
    vnode_t* pv_start = NULL; 
    vnode_t* pv_end = NULL; 
    hnode_t* ph_start_in_end = NULL; 
    hnode_t* ph_end_in_start = NULL; 

    pv_start = v_search_node(g->pv_head_node, v_start); 
    if(pv_start == NULL) 
        return (G_INVALID_VERTEX); 
    pv_end = v_search_node(g->pv_head_node, v_end); 
    if(pv_end == NULL) 
        return (G_INVALID_VERTEX); 

    ph_end_in_start = h_search_node(pv_start->ph_head_node, v_end); 
    if(ph_end_in_start != NULL) 
        return (G_EDGE_EXISTS); 
    ph_start_in_end = h_search_node(pv_end->ph_head_node, v_start); 
    if(ph_start_in_end != NULL) 
        return (G_EDGE_EXISTS); 

    assert(h_insert_end(pv_start->ph_head_node, v_end) == SUCCESS); 
    assert(h_insert_end(pv_end->ph_head_node, v_start) == SUCCESS); 

    return (SUCCESS); 
} 

status_t add_edge(graph_t* g, vertex_t v_start, vertex_t v_end) 
{
    vnode_t* pv_start   = NULL; 
    vnode_t* pv_end     = NULL; 
    hnode_t* ph_start_in_end = NULL; 
    hnode_t* ph_end_in_start = NULL; 

    pv_start = v_search_node(g->pv_head_node, v_start); 
    if(NULL == pv_start) 
        return (G_INVALID_VERTEX); 
    
    pv_end = v_search_node(g->pv_head_node, v_end); 
    if(NULL == pv_end) 
        return (G_INVALID_VERTEX); 

    ph_end_in_start = h_search_node(pv_start->ph_head_node, v_end); 
    if(ph_end_in_start != NULL) 
        return (G_EDGE_EXISTS); 
    ph_start_in_end = h_search_node(pv_end->ph_head_node, v_start); 
    if(ph_start_in_end != NULL) 
        return (G_EDGE_EXISTS); 

    assert(h_insert_end(pv_start->ph_head_node, v_end) == SUCCESS); 
    assert(h_insert_end(pv_end->ph_head_node, v_start) == SUCCESS); 

    g->nr_edges += 1; 

    return (SUCCESS); 
} 

status_t add_edge(graph_t* g, vertex_t v_start, vertex_t v_end) 
{ 
    vnode_t* pv_start = NULL; 
    vnode_t* pv_end = NULL; 
    hnode_t* ph_start_in_end = NULL; 
    hnode_t* ph_end_in_start = NULL; 

    pv_start = v_search_node(g->pv_head_node, v_start); 
    if(pv_start == NULL) 
        return (G_INVALID_VERTEX); 
    pv_end = v_search_node(g->pv_head_node, v_end); 
    if(pv_end == NULL) 
        return (G_INVALID_VERTEX); 

    ph_end_in_start = h_search_node(pv_start->ph_head_node, v_end); 
    if(ph_end_in_start != NULL) 
        return (G_EDGE_EXISTS); 
    ph_start_in_end = h_search_node(pv_end->ph_head_node, v_start); 
    if(ph_start_in_end != NULL) 
        return (G_EDGE_EXISTS); 

    assert(h_insert_end(pv_start->ph_head_node, v_end) == SUCCESS); 
    assert(h_insert_end(pv_end->ph_head_node, v_start) == SUCCESS); 

    g->nr_edges += 1; 

    return (SUCCESS); 
} 

status_t add_edge(graph_t* g, vertex_t v_start, vertex_t v_end) 
{
    vnode_t* pv_start = NULL; 
    vnode_t* pv_end = NULL; 
    hnode_t* ph_start_in_end = NULL; 
    hnode_t* ph_end_in_start = NULL; 

    pv_start = v_search_node(g->pv_head_node, v_start); 
    if(NULL == pv_start) 
        return (G_INVALID_VERTEX); 

    pv_end = v_search_node(g->pv_head_node, v_end); 
    if(NULL == pv_end) 
        return (G_INVALID_VERTEX); 

    ph_start_in_end = h_search_node(pv_end->ph_head_node, v_start); 
    if(ph_start_in_end != NULL) 
        return (G_EDGE_EXISTS); 
    ph_end_in_start = h_search_node(pv_start->ph_head_node, v_end); 
    if(ph_end_in_start != NULL) 
        return (G_EDGE_EXISTS); 

    assert(h_insert_end(pv_start->ph_head_node, v_end) == SUCCESS); 
    assert(h_insert_end(pv_end->ph_head_node, v_start) == SUCCESS); 

    g->nr_edges += 1; 

    return (SUCCESS); 
} 

status_t remove_edge(graph_t* g, vertex_t v_start, vertex_t v_end) 
{
    vnode_t* pv_start = NULL; 
    vnode_t* pv_end = NULL; 
    hnode_t* ph_start_in_end = NULL; 
    hnode_t* ph_end_in_start = NULL; 

    pv_start = v_search_node(g->pv_head_node, v_start); 
    if(pv_start == NULL) 
        return (G_INVALID_VERTEX); 
    pv_end = v_search_node(g->pv_head_node, v_end); 
    if(pv_end == NULL) 
        return (G_INVALID_VERTEX); 

    ph_start_in_end = v_search_node(pv_end->ph_head_node, v_start); 
    if(ph_start_in_end == NULL) 
        return (G_INVALID_EDGE); 
    ph_end_in_start = v_search_node(pv_start->ph_head_node, v_end); 
    if(ph_end_in_start == NULL) 
        return (G_INVALID_EDGE); 

    h_generic_delete(ph_start_in_end); 
    h_generic_delete(ph_end_in_start); 

    g->nr_edges -= 1; 

    return (SUCCESS); 
} 

status_t remove_edge(graph_t* g, vertex_t v_start, vertex_t v_end) 
{
    vnode_t* pv_start = NULL; 
    vnode_t* pv_end = NULL; 
    hnode_t* ph_start_in_end = NULL; 
    hnode_t* ph_end_in_start = NULL; 

    pv_start = v_search_node(g->pv_head_node, v_start); 
    if(NULL == pv_start) 
        return (G_INVALID_VERTEX); 
    pv_end = v_search_node(g->pv_head_node, v_end); 
    if(pv_end == NULL) 
        return (G_INVALID_VERTEX); 

    ph_end_in_start = h_search_node(pv_start->ph_head_node, v_end); 
    if(ph_end_in_start == NULL) 
        return (G_INVALID_EDGE); 
    ph_start_in_end = h_search_node(pv_end->ph_head_node, v_start); 
    if(ph_start_in_end == NULL) 
        return (G_INVALID_EDGE); 

    h_generic_delete(ph_end_in_start); 
    h_generic_delete(ph_start_in_end); 

    g->nr_edges -= 1; 

    return (SUCCESS); 
} 

status_t remove_edge(graph_t* g, vertex_t v_start, vertex_t v_end) 
{
    vnode_t* pv_start = NULL; 
    vnode_t* pv_end = NULL; 
    hnode_t* ph_start_in_end = NULL; 
    hnode_t* ph_end_in_start = NULL; 

    pv_start = v_search_node(g->pv_head_node, v_start); 
    if(pv_start == NULL) 
        return (G_INVALID_VERTEX); 
    pv_end = v_search_node(g->pv_head_node, v_end); 
    if(pv_end == NULL) 
        return (G_INVALID_VERTEX); 

    ph_end_in_start = h_search_node(pv_start->ph_head_node, v_end); 
    if(ph_end_in_start == NULL) 
        return (G_INVALID_EDGE); 
    ph_start_in_end = h_search_node(pv_end->ph_head_node, v_start); 
    if(ph_start_in_end == NULL) 
        return (G_INVALID_EDGE); 

    h_generic_delete(ph_end_in_start); 
    h_generic_delete(ph_start_in_end); 

    g->nr_edges -= 1; 

    return (SUCCESS); 
} 

status_t remove_edge(graph_t* g, vertex_t v_start, vertex_t v_end) 
{
    vnode_t* pv_start = NULL; 
    vnode_t* pv_end = NULL; 
    hnode_t* ph_end_in_start = NULL; 
    hnode_t* ph_start_in_end = NULL; 

    pv_start = v_search_node(g->pv_head_node, v_start); 
    if(pv_start == NULL) 
        return (G_INVALID_VERTEX); 
    pv_end = v_search_node(g->pv_head_node, v_end); 
    if(pv_end == NULL) 
        return (G_INVALID_VERTEX); 

    ph_end_in_start = h_search_node(pv_start->ph_head_node, v_end); 
    if(ph_end_in_start == NULL) 
        return (G_INVALID_EDGE); 
    ph_start_in_end = h_search_node(pv_end->ph_head_node, v_start); 
    if(ph_start_in_end == NULL) 
        return (G_INVALID_EDGE); 

    h_generic_delete(ph_start_in_end); 
    h_generic_delete(ph_end_in_start); 

    g->nr_edges -= 1; 

    return (SUCCESS); 
} 

status_t remove_edge(graph_t* g, vertex_t v_start, vertex_t v_end) 
{
    vnode_t* pv_start = NULL; 
    vnode_t* pv_end = NULL; 
    hnode_t* ph_end_in_start = NULL; 
    hnode_t* ph_start_in_end = NULL; 

    pv_start = v_search_node(g->pv_head_node, v_start); 
    if(pv_start == NULL) 
        return (G_INVALID_VERTEX); 
    pv_end = v_search_node(g->pv_head_node, v_end); 
    if(pv_end == NULL) 
        return (G_INVALID_VERTEX);

    ph_end_in_start = h_search_node(pv_start->ph_head_node, v_end); 
    if(ph_end_in_start == NULL) 
        return (G_INVALID_EDGE); 
    ph_start_in_end = h_search_node(pv_end->ph_head_node, v_start); 
    if(ph_start_in_end == NULL) 
        return (G_INVALID_EDGE); 

    h_generic_delete(ph_end_in_start); 
    h_generic_delete(ph_start_in_end); 

    g->nr_edges -= 1; 
    
    return (SUCCESS); 
} 

void show_graph(graph_t* g, const char* msg) 
{
    vnode_t* pv_run = NULL; 
    hnode_t* ph_run = NULL; 

    if(msg) 
        puts(msg); 

    for(pv_run = g->pv_head_node->v_next; pv_run != g->pv_head_node; pv_run = pv_run->v_next) 
    {
        printf("[%d]\t->\t", pv_run->v); 
        for(ph_run = pv_run->ph_head_node->h_next; ph_run != pv_run->ph_head_node; ph_run = ph_run->h_next) 
            printf("[%d]<->", ph_run->v); 

        puts("[END]"); 
    } 

    puts("---------------------------------------"); 
} 

void show_graph(graph_t* g, const char* msg) 
{
    vnode_t* pv_run = NULL; 
    hnode_t* ph_run = NULL; 

    if(msg) 
        puts(msg); 

    for(pv_run = g->pv_head_node->v_next; pv_run != g->pv_head_node; pv_run = pv_run->v_next) 
    {
        printf("[%d]\t<->\t", pv_run->v); 
        for(ph_run = pv_run->ph_head_node->h_next; ph_run != pv_run->ph_head_node; ph_run = ph_run->h_next) 
            printf("[%d]<->", ph_run->v); 

        puts("[END]"); 
    } 

    puts("-----------------------------------------"); 
}

void show_graph(graph_t* g, const char* msg) 
{
    vnode_t* pv_run = NULL; 
    hnode_t* ph_run = NULL; 

    if(msg) 
        puts(msg); 

    for(pv_run = g->pv_head_node->v_next; pv_run != g->pv_head_node; pv_run = pv_run->v_next) 
    {
        printf("[%d]\t<->\t", pv_run->v); 
        for(ph_run = pv_run->ph_head_node->h_next; ph_run != pv_run->ph_head_node; ph_run = ph_run->h_next) 
            printf("[%d]<->", ph_run->v); 

        puts("[END]"); 
    } 

    puts("-----------------------------------------"); 
} 

void show_graph(graph_t* g, const char* msg) 
{
    vnode_t* pv_run = NULL; 
    hnode_t* ph_run = NULL; 

    for(pv_run = g->pv_head_node->v_next; pv_run != g->pv_head_node; pv_run = pv_run->v_next) 
    {
        printf("[%d]\t<->\t", pv_run->v); 
        for(ph_run = pv_run->ph_head_node->h_next; ph_run != pv_run->ph_head_node; ph_run = ph_run->h_next) 
            printf("[%d]<->", ph_run->v); 

        puts("[END]"); 
    }  

    puts("-------------------------------------------"); 
} 

void show_graph(graph_t* g, const char* msg) 
{
    vnode_t* pv_run = NULL; 
    hnode_t* ph_run = NULL; 

    for(pv_run = g->pv_head_node->v_next; pv_run != g->pv_head_node; pv_run = pv_run->v_next) 
    {
        printf("[%d]\t<->\t", pv_run->v); 
        for(ph_run = pv_run->ph_head_node->h_next; ph_run != pv_run->ph_head_node; ph_run = ph_run->h_next) 
            printf("[%d]<->", ph_run->v); 

        puts("[END]"); 
    } 

    puts("-----------------------------------------"); 
} 

status_t destroy_graph(graph_t** pp_g) 
{
    graph_t* g = NULL; 

    vnode_t* pv_run = NULL; 
    vnode_t* pv_run_next = NULL; 

    hnode_t* ph_run = NULL; 
    hnode_t* ph_run_next = NULL; 

    g = *pp_g; 

    for(pv_run = g->pv_head_node->v_next; pv_run != g->pv_head_node; pv_run = pv_run_next) 
    {
        pv_run_next = pv_run->v_next; 

        for(ph_run = pv_run->ph_head_node->h_next; ph_run != pv_run->ph_head_node; ph_run = ph_run_next) 
        {
            ph_run_next = ph_run->h_next; 
            free(ph_run); 
        } 
        free(pv_run->ph_head_node); 
        free(pv_run); 
    } 

    free(g->pv_head_node); 
    free(g); 

    *pp_g = NULL; 

    return (SUCCESS); 
} 

status_t destroy_graph(graph_t** pp_g) 
{
    vnode_t* pv_run = NULL; 
    vnode_t* pv_run_next = NULL; 

    hnode_t* ph_run = NULL; 
    hnode_t* ph_run_next = NULL; 

    graph_t* g = *pp_g; 

    for(pv_run = g->pv_head_node->v_next; pv_run != g->pv_head_node; pv_run = pv_run_next) 
    {
        pv_run_next = pv_run->v_next; 
        for(ph_run = pv_run->ph_head_node->h_next; ph_run != pv_run->ph_head_node; ph_run = ph_run_next) 
        {
            ph_run_next = ph_run->h_next; 
            free(ph_run); 
        } 
        free(pv_run->ph_head_node); 
        free(pv_run); 
    } 

    free(g->pv_head_node); 
    free(g); 

    *pp_g = NULL; 

    return (SUCCESS); 
} 

status_t destroy_graph(graph_t** pp_g) 
{
    vnode_t* pv_run = NULL; 
    vnode_t* pv_run_next = NULL; 

    hnode_t* ph_run = NULL; 
    hnode_t* ph_run_next = NULL; 

    graph_t* g = *pp_g; 

    for(pv_run = g->pv_head_node->v_next; pv_run != g->pv_head_node; pv_run = pv_run_next) 
    {
        pv_run_next = pv_run->v_next; 

        ph_run = pv_run->ph_head_node->h_next; 
        while(ph_run != pv_run->ph_head_node) 
        {
            ph_run_next = ph_run->h_next; 
            free(ph_run); 
            ph_run = ph_run_next; 
        } 
        free(pv_run->ph_head_node); 
        free(pv_run); 
    } 

    free(g->pv_head_node);  
    free(g); 

    *pp_g = NULL; 

    return (SUCCESS); 
} 

status_t destroy_graph(graph_t** pp_g) 
{
    vnode_t* pv_run = NULL; 
    vnode_t* pv_run_next = NULL; 

    hnode_t* ph_run = NULL; 
    hnode_t* ph_run_next = NULL; 

    graph_t* g = *pp_g; 

    for (pv_run = g->pv_head_node->v_next; pv_run != g->pv_head_node; pv_run = pv_run_next) 
    {
        pv_run_next = pv_run->v_next; 

        for(ph_run = pv_run->ph_head_node->h_next; ph_run != pv_run->ph_head_node; ph_run = ph_run_next) 
        {
            ph_run_next = ph_run->h_next; 
            free(ph_run); 
        } 
        free(pv_run->ph_head_node); 
        free(pv_run); 
    } 

    free(g->pv_head_node); 
    free(g); 

    *pp_g = NULL; 

    return (SUCCESS); 
} 

status_t destroy_graph(graph_t** pp_g) 
{
    vnode_t* pv_run = NULL; 
    vnode_t* pv_run_next = NULL; 

    hnode_t* ph_run = NULL; 
    hnode_t* ph_run_next = NULL; 

    graph_t* g = *pp_g; 

    for (pv_run = g->pv_head_node->v_next; pv_run != g->pv_head_node; pv_run = pv_run_next) 
    {
        pv_run_next = pv_run->v_next; 
        for (ph_run = pv_run->ph_head_node->h_next; ph_run != pv_run->ph_head_node; ph_run = ph_run_next) 
        {
            ph_run_next = ph_run->h_next; 
            free(ph_run); 
        } 
        free(pv_run->ph_head_node); 
        free(pv_run); 
    } 

    free(g->pv_head_node); 
    free(g);
     
    *pp_g = NULL; 

    return (SUCCESS); 
} 

void dfs(graph_t* g) 
{
    vnode_t* pv_run = NULL; 

    reset(g); 

    printf("[START]<->"); 
    for(pv_run = g->pv_head_node->v_next; pv_run != g->pv_head_node; pv_run=pv_run->v_next) 
        if(pv_run->color == WHITE) 
            dfs_visit(g, pv_run); 
    printf("{END]\n"); 
} 

void dfs(graph_t* g) 
{
    vnode_t* pv_run = NULL; 

    reset(g); 

    printf("[START]<->"); 
    for(pv_run = g->pv_head_node->v_next; pv_run != pv_run->v_next; pv_run = pv_run->v_next) 
        if(pv_run->color == WHITE) 
            dfs_visit(g, pv_run); 
    printf("[END]"); 
} 

void dfs(graph_t* g) 
{
    vnode_t* pv_run = NULL; 

    reset(g); 

    printf("[START]<->"); 
    for(pv_run = g->pv_head_node->v_next; pv_run != pv_run->v_next; pv_run = pv_run->v_next) 
        if(pv_run->color == WHITE) 
            dfs_visit(g, pv_run); 
    printf("[END]"); 
} 

void dfs(graph_t* g) 
{
    vnode_t* pv_run = NULL; 

    reset(g); 

    printf("[START]<->"); 
    for(pv_run = g->pv_head_node->v_next; pv_run != pv_run->v_next; pv_run = pv_run->v_next) 
        if(pv_run->color == WHITE) 
            dfs_visit(g, pv_run); 
    printf("[END]"); 
} 

void dfs(graph_t* g) 
{
    vnode_t* pv_run = NULL; 

    reset(g); 

    printf("[START]<->"); 
    for(pv_run = g->pv_head_node->v_next; pv_run != pv_run->v_next; pv_run = pv_run->v_next) 
        if(pv_run->color == WHITE) 
            dfs_visit(g, pv_run); 
    printf("[END]"); 
} 

void bfs(graph_t* g, vertex_t v) 
{
    vnode_t* pv_node = NULL; 
    vnode_t* pv = NULL; 
    vnode_t* pv_h_in_vlist = NULL; 
    hnode_t* ph_run = NULL; 
    queue_node_t* p_queue = NULL; 

    pv_node = v_search_node(g->pv_head_node, v); 
    if(NULL == pv_node) 
        return (G_INVALID_VERTEX); 

    reset(g); 
    pv_node->color = GREY; 

    p_queue = create_queue(); 
    assert(enqueue(p_queue, pv_node) == SUCCESS); 

    printf("[START]<->"); 

    while(is_queue_empty(p_queue) != TRUE) 
    {
        pv = NULL; 
        assert(dequeue(p_queue, &pv) == SUCCESS); 

        printf("[%d]->", pv->v); 

        for(ph_run = pv->ph_head_node->h_next; ph_run != pv->ph_head_node; ph_run = ph_run->h_next) 
        {
            pv_h_in_vlist = v_search_node(g->pv_head_node, ph_run->v); 
            if(pv_h_in_vlist->color == WHITE) 
            {
                pv_h_in_vlist->color = GREY; 
                enqueue(p_queue, pv_h_in_vlist); 
            } 
        } 

        pv->color = BLACK; 
    } 

    printf("[END]"); 

    assert(destroy_queue(p_queue) == SUCCESS); 
    p_queue = NULL; 
} 

void bfs(graph_t* g, vertex_t v) 
{
    vnode_t* pv_node = NULL; 
    vnode_t* pv = NULL; 
    vnode_t* pv_h_in_vlist = NULL; 
    hnode_t* ph_run = NULL; 
    queue_node_t* p_queue = NULL; 

    pv_node = v_search_node(g->pv_head_node, v); 
    if(pv_node == NULL) 
        return (G_INVALID_VERTEX); 

    reset(g); 
    pv_node->color = GREY; 

    p_queue = create_queue(); 
    assert(enqueue(p_queue, pv_node) == SUCCESS); 

    while(is_queue_empty(p_queue) == FALSE) 
    {
        pv = NULL; 
        assert(dequeue(p_queue, &pv) == SUCCESS); 
        printf("[%d]->", pv->v); 

        for(ph_run = pv->ph_head_node->h_next; pv != pv->ph_head_node; ph_run = ph_run->h_next) 
        {
            pv_h_in_vlist = v_search_node(g->pv_head_node, ph_run->v); 
            if(pv_h_in_vlist->color == WHITE) 
            {
                pv_h_in_vlist->color = GREY; 
                assert(enqueue(p_queue, pv_h_in_vlist) == SUCCESS); 
            } 
        } 

        pv->color = BLACK; 
    } 

    printf("[END]"); 

    assert(destroy_queue(p_queue) == SUCCESS); 
    p_queue = NULL; 
} 

void bfs(graph_t* g, vertex_t v) 
{
    vnode_t* pv_node = NULL; 
    vnode_t* pv = NULL; 
    vnode_t* pv_h_in_vlist = NULL; 
    hnode_t* ph_run = NULL; 
    queue_node_t* p_queue = NULL; 

    pv_node = v_search_node(g->pv_head_node, v); 
    if(pv_node == NULL) 
        return (G_INVALID_VERTEX); 

    resetg(g); 

    pv_node->color = GREY; 

    p_queue = create_queue(); 
    assert(enqueue(p_queue, pv_node) == SUCCESS); 

    printf("[START]"); 

    while(is_queue_empty(p_queue) == FALSE) 
    {
        pv = NULL; 
        assert(dequeue(p_queue, &pv) == SUCCESS); 

        printf("[%d]->", pv->v); 

        for(ph_run = pv->ph_head_node->h_next; ph_run != pv->ph_head_node; ph_run = ph_run->h_next) 
        {
            pv_h_in_vlist = v_search_node(g->pv_head_node, ph_run->v); 
            if(pv_h_in_vlist->color == WHITE) 
            {
                pv_h_in_vlist->color = GREY; 
                assert(enqueue(p_queue, pv_h_in_vlist) == SUCCESS); 
            } 
        } 

        pv->color = BLACK; 
    } 

    pv->color = BLACK; 
} 

void bfs(graph_t* g, vertex_t v) 
{
    vnode_t* pv_node = NULL; 
    vnode_t* pv = NULL; 
    vnode_t* pv_h_in_vlist = NULL; 
    hnode_t* ph_run = NULL; 
    queue_node_t* p_queue = NULL; 

    pv_node = v_search_node(g->pv_head_node, v); 
    if(NULL == pv_node) 
        return (G_INVALID_VERTEX); 

    reset(g); 

    pv_node->color = GREY; 
    p_queue = create_queue(); 
    enqueue(p_queue, pv_node); 

    printf("[START]->"); 

    while(is_queue_empty(p_queue) == FALSE) 
    {
        pv = NULL; 
        assert(dequeue(p_queue, &pv) == SUCCESS); 

        printf("[%d]->", pv->v); 

        for(ph_run = pv->ph_head_node->h_next; ph_run != pv->ph_head_node; ph_run = ph_run->h_next) 
        {
            pv_h_in_vlist = v_search_node(g->pv_head_node, ph_run->v); 
            if(pv_h_in_vlist->color == WHITE) 
            {
                pv_h_in_vlist->color = GREY; 
                enqueue(p_queue, pv_h_in_vlist); 
            } 
        } 

        pv->color = BLACK; 
    } 

    printf("[END]"); 

    destroy_queue(p_queue); 
    p_queue = NULL; 
} 

void bfs(graph_t* g, vertex_t v) 
{
    vnode_t* pv_node = NULL; 
    vnode_t* pv = NULL; 
    vnode_t* pv_h_in_vlist = NULL; 
    hnode_t* ph_run = NULL; 
    queue_node_t* p_queue = NULL; 

    pv_node = v_search_node(g->pv_head_node, v); 
    if(NULL == pv_node) 
        return (G_INVALID_VERTEX); 

    reset(g); 

    p_queue = create_queue(); 
    pv_node->color = GREY; 
    assert(enqueue(p_queue, pv_node) == SUCCESS); 

    printf("[START]->"); 

    while(is_queue_empty(p_queue) != TRUE) 
    {
        pv = NULL; 
        assert(dequeue(p_queue, &pv) == SUCCESS); 

        printf("[%d]->", pv->v); 

        for(ph_run = pv->ph_head_node->h_next; ph_run != pv->ph_head_node; ph_run = ph_run->h_next) 
        {
            pv_h_in_vlist = v_search_node(g->pv_head_node, ph_run->v); 
            if(pv_h_in_vlist->color == WHITE) 
            {
                pv_h_in_vlist->color = GREY; 
                enqueue(p_queue, pv_h_in_vlist); 
            } 
        } 

        pv->color = BLACK; 
    } 

    printf("[END]"); 

    assert(destroy_queue(p_queue) == SUCCESS); 
    p_queue = NULL; 
} 

// graph helper functions 
void reset(graph_t* g) 
{
    vnode_t* pv_run = NULL; 

    for(pv_run = g->pv_head_node->v_next; pv_run != g->pv_head_node; pv_run = pv_run->v_next) 
        pv_run->color = WHITE; 
} 

void reset(graph_t* g) 
{
    for(vnode_t* pv_run = g->pv_head_node->v_next; pv_run != g->pv_head_node; pv_run = pv_run->v_next) 
        pv_run->color = WHITE; 
} 

void reset(graph_t* g) 
{
    for(vnode_t* pv_run = g->pv_head_node->v_next; pv_run != g->pv_head_node; pv_run = pv_run->v_next) 
        pv_run->color = WHITE; 
} 

void reset(graph_t* g) 
{   
    for(vnode_t* pv_run = g->pv_head_node->v_next; pv_run != g->pv_head_node; pv_run = pv_run->v_next) 
        pv_run->color = WHITE; 
} 

void reset(graph_t* g) 
{
    for(vnode_t* pv_run = g->pv_head_node->v_next; pv_run != g->pv_head_node; pv_run = pv_run->v_next) 
        pv_run->color = WHITE; 
} 

void dfs_visit(graph_t* g, vnode_t* pv_node) 
{
    hnode_t* ph_run = NULL; 
    vnode_t* pv_h_in_vlist = NULL; 

    pv_node->color = GREY; 
    printf("[%d]<->", ph_run->v); 

    for(ph_run = pv_node->ph_head_node->h_next; ph_run != pv_node->ph_head_node; ph_run = ph_run->h_next) 
    {
        pv_h_in_vlist = v_search_node(g, ph_run->v); 
        if(pv_h_in_vlist->color == WHITE) 
            dfs_visit(g, pv_h_in_vlist); 
    } 
    pv_node->color = BLACK; 
} 

void dfs_visit(graph_t* g, vnode_t* pv_node) 
{
    hnode_t* ph_run = NULL; 
    vnode_t* pv_h_in_vlist = NULL; 

    pv_node->color = GREY; 
    printf("[%d]<->", pv_node->v); 

    for(ph_run = pv_node->ph_head_node->h_next; ph_run != pv_node->ph_head_node; ph_run = ph_run->h_next) 
    {
        pv_h_in_vlist = v_search_node(g, ph_run->v); 
        if(pv_h_in_vlist->color == WHITE)   
            dfs_visit(g, pv_h_in_vlist); 
    } 

    pv_node->color = BLACK; 
} 

void dfs_visit(graph_t* g, vnode_t* pv_node) 
{
    hnode_t* ph_run = NULL; 
    vnode_t* pv_h_in_vlist = NULL; 

    pv_node->color = GREY; 
    printf("[%d]<->", pv_node->v); 

    for(ph_run = pv_node->ph_head_node->h_next; ph_run != pv_node->ph_head_node; ph_run = ph_run->h_next) 
    {
        pv_h_in_vlist = v_search_node(g, ph_run->v); 
        if(pv_h_in_vlist->color == WHITE) 
            dfs_visit(g, pv_h_in_vlist); 
    } 

    pv_node->color = BLACK; 
} 

void dfs_visit(graph_t* g, vnode_t* pv_node) 
{
    hnode_t* ph_run = NULL; 
    vnode_t* pv_h_in_vlist = NULL; 

    pv_node->color = GREY; 
    printf("[%d]<->", pv_node->v); 

    for(ph_run = pv_node->ph_head_node->h_next; ph_run != pv_node->ph_head_node; ph_run = ph_run->h_next) 
    {
        pv_h_in_vlist = v_search_node(g, ph_run->v); 
        if(pv_h_in_vlist->color == WHITE) 
            dfs_visit(g, pv_h_in_vlist); 
    } 

    pv_node->color = BLACK; 
} 

void dfs_visit(graph_t* g, vnode_t* pv_node) 
{
    hnode_t* ph_run = NULL; 
    vnode_t* pv_h_in_vlist = NULL; 

    pv_node->color = GREY; 
    printf("[%d]<->", pv_node->v); 

    for(ph_run = pv_node->ph_head_node->h_next; ph_run != pv_node->ph_head_node; ph_run = ph_run->h_next) 
    {
        pv_h_in_vlist = v_search_node(g, ph_run->v); 
        if(pv_h_in_vlist->color == WHITE) 
            dfs_visit(g, pv_h_in_vlist); 
    } 

    pv_node->color = BLACK; 
} 

/* Graph helper routines */ 
/* Queue */ 
queue_node_t* create_queue(void) 
{
    queue_node_t* p_new_queue = NULL; 

    p_new_queue = q_get_node(0); 
    p_new_queue->q_prev = p_new_queue; 
    p_new_queue->q_next = p_new_queue; 

    return (p_new_queue); 
} 

queue_node_t* create_queue(void) 
{
    queue_node_t* p_new_queue = NULL; 

    p_new_queue = q_get_node(0); 
    p_new_queue->q_prev = p_new_queue; 
    p_new_queue->q_next = p_new_queue; 

    return (p_new_queue); 
} 

queue_node_t* create_queue(void) 
{
    queue_node_t* p_new_queue = NULL; 

    p_new_queue = q_get_node(0); 
    p_new_queue->q_prev = p_new_queue; 
    p_new_queue->q_next = p_new_queue; 

    return (p_new_queue); 
} 

queue_node_t* create_queue(void) 
{
    queue_node_t* p_new_queue = NULL; 

    p_new_queue = q_get_node(0); 
    p_new_queue->q_prev = p_new_queue; 
    p_new_queue->q_next = p_new_queue; 

    return (p_new_queue); 
} 

queue_node_t* create_queue(void) 
{
    queue_node_t* p_new_queue = NULL; 

    p_new_queue = q_get_node(0); 
    p_new_queue->q_prev = p_new_queue; 
    p_new_queue->q_next = p_new_queue; 

    return (p_new_queue); 
} 

status_t enqueue(queue_node_t* p_queue, vnode_t* pv_node) 
{
    q_generic_insert(p_queue->q_prev, q_get_node(pv_node), p_queue); 
    return (SUCCESS); 
} 

status_t enqueue(queue_node_t* p_queue, vnode_t* pv_node) 
{
    q_generic_insert(p_queue->q_prev, q_get_node(pv_node), p_queue); 
    return (SUCCESS); 
} 

status_t enqueue(queue_node_t* p_queue, vnode_t* pv_node) 
{
    q_generic_insert(p_queue->q_prev, q_get_node(pv_node), p_queue); 
    return (SUCCESS); 
} 

status_t enqueue(queue_node_t* p_queue, vnode_t* pv_node) 
{
    q_generic_insert(p_queue->q_prev, q_get_node(pv_node), p_queue); 
    return (SUCCESS); 
} 

status_t enqueue(queue_node_t* p_queue, vnode_t* pv_node) 
{
    q_generic_insert(p_queue->q_prev, q_get_node(pv_node), p_queue); 
    return (SUCCESS); 
} 

status_t dequeue(queue_node_t* p_queue, vnode_t** ppv_node) 
{
    if(is_queue_empty(p_queue) == TRUE) 
    {
        *ppv_node = NULL; 
        return (QUEUE_EMPTY); 
    } 

    *ppv_node = p_queue->q_prev->pv; 
    q_generic_delete(p_queue->q_prev); 
    return (SUCCESS); 
} 

status_t dequeue(queue_node_t* p_queue, vnode_t** ppv_node) 
{
    if(is_queue_empty(p_queue) == TRUE) 
    {
        *ppv_node = NULL; 
        return (QUEUE_EMPTY); 
    } 

    *ppv_node = p_queue->q_prev->pv; 
    q_generic_delete(p_queue->q_prev); 
    return (SUCCESS); 
} 

status_t dequeue(queue_node_t* p_queue, vnode_t** ppv_node) 
{
    if(is_queue_empty(p_queue) == TRUE) 
    {
        *ppv_node = NULL; 
        return (QUEUE_EMPTY); 
    } 

    *ppv_node = p_queue->q_prev->pv;
    q_generic_delete(p_queue->q_prev); 
    return (SUCCESS); 
} 

status_t dequeue(queue_node_t* p_queue, vnode_t** ppv_node) 
{
    if(is_queue_empty(p_queue) == TRUE) 
    {
        *ppv_node = NULL; 
        return (QUEUE_EMPTY); 
    } 

    *ppv_node = p_queue->q_prev->pv; 
    q_generic_delete(p_queue->q_prev); 
    return (SUCCESS); 
} 

status_t dequeue(queue_node_t* p_queue, vnode_t** ppv_node) 
{
    if(is_queue_empty(p_queue) == TRUE) 
    {
        *ppv_node = NULL; 
        return (QUEUE_EMPTY); 
    } 

    *ppv_node = p_queue->q_prev->pv; 
    q_generic_delete(p_queue->q_prev); 
    return (SUCCESS); 
} 

int is_queue_empty(queue_node_t* p_queue) 
{
    return (p_queue->q_next==p_queue && p_queue->q_prev==p_queue); 
} 

int is_queue_empty(queue_node_t* p_queue) 
{
    return (p_queue->q_next == p_queue && p_queue->q_prev == p_queue); 
} 

int is_queue_empty(queue_node_t* p_queue) 
{
    return (p_queue->q_next == p_queue && p_queue->q_prev == p_queue); 
} 

int is_queue_empty(queue_node_t* p_queue) 
{
    return (p_queue->q_prev == p_queue && p_queue->q_next == p_queue); 
} 

int is_queue_empty(queue_node_t* p_queue) 
{
    return (p_queue->q_prev == p_queue && p_queue->q_next == p_queue); 
} 

status_t destroy_queue(queue_node_t* p_queue) 
{
    queue_node_t* pq_run = NULL; 
    queue_node_t* pq_run_next = NULL; 

    for(pq_run = p_queue->q_next; pq_run != p_queue; pq_run = pq_run_next) 
    {
        pq_run_next = pq_run->q_next; 
        free(pq_run); 
    } 

    free(p_queue); 
    return (SUCCESS); 
} 

status_t destroy_queue(queue_node_t* p_queue) 
{
    queue_node_t* pq_run = NULL; 
    queue_node_t* pq_run_next = NULL; 

    for(pq_run = p_queue->q_next; pq_run != p_queue; pq_run = pq_run->q_next) 
    {
        pq_run_next = pq_run->q_next; 
        free(pq_run); 
    } 

    free(p_queue); 
    return (SUCCESS); 
} 

status_t destroy_queue(queue_node_t* p_queue) 
{
    queue_node_t* pq_run = NULL; 
    queue_node_t* pq_run_next = NULL; 

    for(pq_run = p_queue->q_next; pq_run != p_queue; pq_run = pq_run->q_next) 
    {
        pq_run_next = pq_run->q_next; 
        free(pq_run); 
    } 

    free(p_queue); 
    return (SUCCESS); 
} 

status_t destroy_queue(queue_node_t* p_queue) 
{
    queue_node_t* pq_run = NULL; 
    queue_node_t* pq_run_next = NULL; 

    for(pq_run = p_queue->q_next; pq_run != p_queue; pq_run = pq_run_next) 
    {
        pq_run_next = pq_run->q_next; 
        free(pq_run); 
    } 
    free(p_queue); 

    return (SUCCESS); 
} 

status_t destroy_queue(queue_node_t* p_queue) 
{
    queue_node_t* pq_run = NULL; 
    queue_node_t* pq_run_next = NULL; 

    for(pq_run = p_queue->q_next; pq_run != p_queue; pq_run = pq_run->q_next) 
    {
        pq_run_next = pq_run->q_next; 
        free(pq_run); 
    } 
    free(p_queue); 

    return (SUCCESS); 
} 

void q_generic_insert(queue_node_t* pq_begin, queue_node_t* pq_mid, queue_node_t* pq_end) 
{
    pq_mid->q_next = pq_end; 
    pq_mid->q_prev = pq_begin; 
    pq_begin->q_next = pq_mid; 
    pq_end->q_prev = pq_mid; 
} 

void q_generic_insert(queue_node_t* pq_begin, queue_node_t* pq_mid, queue_node_t* pq_end) 
{
    pq_mid->q_next = pq_end; 
    pq_mid->q_prev = pq_begin; 
    pq_begin->q_next = pq_mid; 
    pq_end->q_prev = pq_mid; 
} 

void q_generic_insert(queue_node_t* pq_begin, queue_node_t* pq_mid, queue_node_t* pq_end) 
{
    pq_mid->q_prev = pq_begin; 
    pq_mid->q_next = pq_end; 
    pq_begin->q_next = pq_mid; 
    pq_end->q_prev = pq_mid; 
} 

void q_generic_insert(queue_node_t* pq_begin, queue_node_t* pq_mid, queue_node_t* pq_end) 
{
    pq_mid->q_prev = pq_begin; 
    pq_mid->q_next = pq_end; 
    pq_begin->q_next = pq_mid; 
    pq_end->q_prev = pq_mid; 
} 

void q_geenric_insert(queue_node_t* pq_begin, queue_node_t* pq_mid, queue_node_t* pq_end) 
{
    pq_mid->q_prev = pq_begin; 
    pq_mid->q_next = pq_end; 
    pq_begin->q_next = pq_mid; 
    pq_end->q_prev = pq_mid; 
} 

void q_generic_delete(queue_node_t* pq_delete_node) 
{
    pq_delete_node->q_next->q_prev = pq_delete_node->q_prev; 
    pq_delete_node->q_prev->q_next = pq_delete_node->q_next; 
    free(pq_delete_node); 
} 

void q_generic_delete(queue_node_t* pq_delete_node) 
{
    pq_delete_node->q_next->q_prev = pq_delete_node->q_prev; 
    pq_delete_node->q_prev->q_next = pq_delete_node->q_next; 
    free(pq_delete_node); 
} 

void q_generic_delete(queue_node_t* pq_delete_node) 
{
    pq_delete_node->q_next->q_prev = pq_delete_node->q_prev; 
    pq_delete_node->q_prev->q_next = pq_delete_node->q_next; 
    delete(pq_delete_node); 
} 

void q_generic_delete(queue_node_t* pq_delete_node) 
{
    pq_delete_node->q_next->q_prev = pq_delete_node->q_prev; 
    pq_delete_node->q_prev->q_next = pq_delete_node->q_next; 
    free(pq_delete_node); 
} 

void q_generic_delete(queue_node_t* pq_delete_node) 
{
    pq_delete_node->q_prev->q_next = pq_delete_node->q_next; 
    pq_delete_node->q_next->q_prev = pq_delete_node->q_prev; 
    free(pq_delete_node); 
} 

void q_generic_delete(queue_node_t* pq_delete_node) 
{
    pq_delete_node->q_prev->q_next = pq_delete_node->q_next; 
    pq_delete_node->q_next->q_prev = pq_delete_node->q_prev; 
    free(pq_delete_node); 
} 

queue_node_t* q_get_node(vnode_t* pv_node) 
{
    queue_node_t* pq_new_node = NULL; 

    pq_new_node = (queue_node_t*)xmalloc(sizeof(queue_node_t)); 
    pq_new_node->pv = pv_node; 
    pq_new_node->q_prev = NULL; 
    pq_new_node->q_next = NULL; 

    return (pq_new_node); 
} 

queue_node_t* q_get_node(vnode_t* pv_node) 
{
    queue_node_t* pq_new_node = NULL; 

    pq_new_node = (queue_node_t*)xmalloc(sizeof(queue_node_t)); 
    pq_new_node->pv = pv_node; 
    pq_new_node->q_prev = NULL; 
    pq_new_node->q_next = NULL; 

    return (pq_new_node); 
} 

queue_node_t* q_get_node(vnode_t* new_pv_node) 
{
    queue_node_t* pq_new_node = NULL; 

    pq_new_node = (queue_node_t*)xmalloc(sizeof(queue_node_t)); 
    pq_new_node->pv = new_pv_node; 
    pq_new_node->q_prev = pq_new_node; 
    pq_new_node->q_next = pq_new_node; 
    
    return (pq_new_node); 
} 

queue_node_t* q_get_node(vnode_t* new_pv_node) 
{
    queue_node_t* pq_new_node = NULL; 

    pq_new_node = (queue_node_t*)xmalloc(sizeof(queue_node_t)); 
    pq_new_node->pv = new_pv_node; 
    pq_new_node->q_next = NULL; 
    pq_new_node->q_prev = NULL; 

    return (pq_new_node); 
} 

queue_node_t* q_get_node(vnode_t* new_pv_node) 
{
    queue_node_t* pq_new_node = NULL; 

    pq_new_node = (queue_node_t*)xmalloc(sizeof(queue_node_t)); 
    pq_new_node->pv = new_pv_node; 
    pq_new_node->q_next = pq_new_node; 
    pq_new_node->q_prev = pq_new_node; 

    return (pq_new_node); 
} 

/* Vertical list */ 
vlist_t* v_create_list(void) 
{
    vlist_t* p_new_list = NULL; 

    p_new_list = (vnode_t*)xmalloc(sizeof(vnode_t)); 
    p_new_list->ph_head_node = NULL; 
    p_new_list->color = WHITE; 
    p_new_list->v_next = NULL; 
    p_new_list->v_prev = NULL; 

    return (p_new_list); 
} 

vlist_t* v_create_list(void) 
{
    vlist_t* p_new_list = NULL; 

    p_new_list = (vnode_t*)xmalloc(sizeof(vnode_t)); 
    p_new_list->ph_head_node = NULL; 
    p_new_list->v_next = NULL; 
    p_new_list->v_prev = NULL; 

    return (p_new_list); 
} 

vlist_t* v_create_list(void) 
{
    vlist_t* p_new_list = NULL; 

    p_new_list = (vnode_t*)xmalloc(sizeof(vnode_t)); 
    p_new_list->ph_head_node = NULL; 
    p_new_list->v_next = NULL; 
    p_new_list->v_prev = NULL; 

    return (p_new_list); 
} 

vlist_t* v_create_list(void) 
{
    vlist_t* p_new_list = NULL; 

    p_new_list = (vnode_t*)xmalloc(sizeof(vnode_t)); 
    p_new_list->ph_head_node = NULL; 
    p_new_list->v_next = NULL; 
    p_new_list->v_prev = NULL; 

    return (p_new_list); 
} 

vlist_t* v_create_list(void) 
{
    vnode_t* pv_head_node = NULL; 

    pv_head_node = (vnode_t*)xmalloc(sizeof(vnode_t)); 
    pv_head_node->ph_head_node = NULL; 
    pv_head_node->v_next = NULL; 
    pv_head_node->v_prev = NULL; 

    return (pv_head_node); 
} 

status_t v_insert_end(vlist_t* pv_list, vertex_t new_vertex) 
{
    v_generic_insert(pv_list->v_prev, v_get_list_node(new_vertex), pv_list); 
    return (SUCCESS); 
} 

status_t v_insert_end(vlist_t* pv_list, vertex_t new_vertex) 
{
    v_generic_insert(pv_list->v_prev, v_get_list_node(new_vertex), pv_list); 
    return (SUCCESS); 
} 

status_t v_insert_end(vlist_t* pv_list, vertex_t new_vertex) 
{
    v_generic_insert(pv_list->v_prev, v_get_list_node(new_vertex), pv_list); 
    return (SUCCESS); 
} 

status_t v_insert_end(vlist_t* pv_list, vertex_t new_vertex) 
{
    v_generic_insert(pv_list->v_prev, v_get_list_node(new_vertex), pv_list); 
    return (SUCCESS); 
} 

status_t v_insert_end(vlist_t* pv_list, vertex_t new_vertex) 
{
    v_generic_inserT(pv_list->v_prev, v_get_list_node(new_vertex), pv_list); 
    return (SUCCESS); 
} 

// helper routines 
void v_generic_insert(vnode_t* pv_beg, vnode_t* pv_mid, vnode_t* pv_end) 
{
    pv_mid->v_prev = pv_beg; 
    pv_mid->v_next = pv_end; 
    pv_beg->v_next = pv_mid; 
    pv_end->v_prev = pv_mid; 
}  

void v_generic_insert(vnode_t* pv_beg, vnode_t* pv_mid, vnode_t* pv_end) 
{
    pv_mid->v_prev = pv_beg; 
    pv_mid->v_next = pv_end;
    pv_beg->v_next = pv_mid; 
    pv_end->v_prev = pv_mid; 
} 

void v_generic_insert(vnode_t* pv_beg, vnode_t* pv_mid, vnode_t* pv_end) 
{
    pv_mid->v_prev = pv_beg; 
    pv_mid->v_next = pv_end; 
    pv_beg->v_next = pv_mid; 
    pv_end->v_prev = pv_mid; 
} 

void v_generic_insert(vnode_t* pv_beg, vnode_t* pv_mid, vnode_t* pv_end) 
{
    pv_mid->v_prev = pv_beg; 
    pv_mid->v_next = pv_end; 
    pv_beg->v_next = pv_mid; 
    pv_end->v_prev = pv_beg; 
} 

void v_generic_insert(vnode_t* pv_beg, vnode_t* pv_mid, vnode_t* pv_end) 
{
    pv_mid->v_prev = pv_beg; 
    pv_mid->v_next = pv_end; 
    pv_beg->v_next = pv_mid; 
    pv_end->v_prev = pv_mid; 
} 

void v_generic_delete(vnode_t* pv_delete_node) 
{
    pv_delete_node->v_next->v_prev = pv_delete_node->v_prev; 
    pv_delete_node->v_prev->v_next = pv_delete_node->v_next; 
    free(pv_delete_node); 
} 

void v_generic_delete(vnode_t* pv_delete_node) 
{
    pv_delete_node->v_next->v_prev = pv_delete_node->v_prev; 
    pv_delete_node->v_prev->v_next = pv_delete_node->v_next; 
    free(pv_delete_node); 
    pv_delete_node = NULL; 
} 

void v_generic_delete(vnode_t* pv_delete_node) 
{
    pv_delete_node->v_next->v_prev = pv_delete_node->v_prev; 
    pv_delete_node->v_prev->v_next = pv_delete_node->v_next; 
    free(pv_delete_node); 
} 

void v_generic_delete(vnode_t* pv_delete_node) 
{
    pv_delete_node->v_next->v_prev = pv_delete_node->v_prev; 
    pv_delete_node->v_prev->v_next = pv_delete_node->v_next; 
    free(pv_delete_node); 
} 

void v_generic_delete(vnode_t* pv_delete_node) 
{
    pv_delete_node->v_next->v_prev = pv_delete_node->v_prev; 
    pv_delete_node->v_prev->v_next = pv_delete_node->v_next; 
    free(pv_delete_node); 
} 

vnode_t* v_search_vertex(vlist_t* pv_list, vertex_t v) 
{
    for(vnode_t* pv_run = pv_list->v_next; pv_run != pv_list; pv_run = pv_run->v_next) 
        if(pv_run->v == v) 
            return (pv_run); 
    return (NULL); 
} 

vnode_t* v_search_vertex(vlist_t* pv_list, vertex_t search_vertex) 
{
    for(vnode_t* pv_run = pv_list->v_next; pv_run != pv_list; pv_run = pv_run->v_next) 
        if(pv_run->v == search_vertex) 
            return (pv_run); 
    return (NULL); 
} 

vnode_t* v_search_vertex(vlist_t* pv_list, vertex_t search_vertex) 
{
    for(vnode_t* pv_run = pv_list->v_next; pv_run != pv_list; pv_run = pv_run->v_next) 
        if(pv_run->v == search_vertex) 
            return (pv_run); 
    return (NULL); 
} 

vnode_t* v_search_vertex(vlist_t* pv_list, vertex_t search_vertex) 
{
    for(vnode_t* pv_run = pv_list->v_next; pv_run != pv_list; pv_run = pv_run->v_next) 
        if(pv_run->v == search_vertex) 
            return (pv_run); 
    return (NULL); 
} 

vnode_t* v_search_vertex(vlist_t* pv_list, vertex_t search_vertex) 
{
    for(vnode_t* pv_run = pv_list->v_next; pv_run != pv_list; pv_run = pv_list->v_next) 
        if(pv_run->v == search_vertex) 
            return (pv_run); 
    return (NULL); 
} 

vnode_t* v_get_list_node(vertex_t v) 
{
    vnode_t* pv_new_node = NULL; 

    pv_new_node = (vnode_t*)xmalloc(sizeof(vnode_t)); 
    pv_new_node->v = v; 
    pv_new_node->color = WHITE; 
    pv_new_node->ph_head_node = NULL; 
    pv_new_node->v_next = NULL; 
    pv_new_node->v_prev = NULL; 

    return (pv_new_node); 
} 

vnode_t* v_get_list_node(vertex_t v) 
{
    vnode_t* pv_new_node = NULL; 

    pv_new_node = (vnode_t*)xmalloc(sizeof(vnode_t)); 
    pv_new_node->color = WHITE; 
    pv_new_node->ph_head_node = NULL; 
    pv_new_node->v_prev = NULL; 
    pv_new_node->v_next = NULL; 

    return (pv_new_node); 
} 

vnode_t* v_get_list_node(vertex_t v) 
{
    vnode_t* pv_new_node = NULL; 

    pv_new_node = (vnode_t*)xmalloc(sizeof(vnode_t)); 
    pv_new_node->color = WHITE; 
    pv_new_node->ph_head_node = NULL; 
    pv_new_node->v_prev = NULL; 
    pv_new_node->v_next = NULL; 

    return (pv_new_node); 
} 

vnode_t* v_get_list_node(vertex_t v) 
{
    vnode_t* pv_new_node = NULL; 

    pv_new_node = (vnode_t*)xmalloc(sizeof(vnode_t)); 
    pv_new_node->color = WHITE; 
    pv_new_node->ph_head_node = NULL; 
    pv_new_node->v_prev = NULL; 
    pv_new_node->v_next = NULL; 

    return (pv_new_node); 
} 

vnode_t* v_get_list_node(vertex_t v) 
{
    vnode_t* pv_new_node = NULL; 

    pv_new_node = (vnode_t*)xmalloc(sizeof(vnode_t)); 
    pv_new_node->color = WHITE; 
    pv_new_node->ph_head_node = NULL; 
    pv_new_node->v_prev = NULL; 
    pv_new_node->v_next = NULL; 

    return (pv_new_node); 
} 

/* Horizontal list */ 
hlist_t* h_create_list(void) 
{
    hnode_t* ph_head_node = NULL; 

    ph_head_node = h_get_list_node(0); 
    ph_head_node->h_next = ph_head_node; 
    ph_head_node->h_prev = ph_head_node; 

    return (ph_head_node); 
} 

hlist_t* h_create_list(void) 
{
    hnode_t* ph_list = NULL; 

    ph_list = h_get_list_node(0); 
    ph_list->h_prev = ph_list; 
    ph_list->h_next = ph_list; 

    return (ph_list); 
} 

hlist_t* h_create_list(void) 
{
    hnode_t* ph_list = NULL; 

    ph_list = h_get_list_node(0); 
    ph_list->h_next = ph_list; 
    ph_list->h_prev = ph_list; 

    return (ph_list); 
} 

hlist_t* h_create_list(void) 
{
    hnode_t* ph_list = NULL; 

    ph_list = h_get_list_node(0); 
    ph_list->h_prev = ph_list; 
    ph_list->h_next = ph_list; 

    return (ph_list); 
} 

hlist_t* h_create_list(void) 
{
    hnode_t* ph_head_node = NULL; 

    ph_head_node = h_get_list_node(0); 
    ph_head_node->h_prev = ph_head_node; 
    ph_head_node->h_next = ph_head_node; 

    return (ph_head_node); 
} 

status_t h_insert_end(hlist_t* ph_list, vertex_t new_vertex) 
{
    h_generic_insert(ph_list->h_prev, h_get_list_node(new_vertex), ph_list); 
    return (SUCCESS); 
} 

status_t h_insert_end(hlist_t* ph_list, vertex_t new_vertex) 
{
    h_generic_insert(ph_list->h_prev, h_get_list_node(new_vertex), ph_list); 
    return (SUCCESS); 
} 

status_t h_insert_end(hlist_t* ph_list, vertex_t new_vertex) 
{
    h_generic_insert(ph_list->h_prev, h_get_list_node(new_vertex), ph_list); 
    return (SUCCESS); 
} 

status_t h_insert_end(hlist_t* ph_list, vertex_t new_vertex) 
{ 
    h_generic_insert(ph_list->h_prev, h_get_list_node(new_vertex), ph_list); 
    return (SUCCESS); 
} 

status_t h_insert_end(hlist_t* ph_list, vertex_t new_vertex) 
{
    h_generic_insert(ph_list->h_prev, h_get_list_node(new_vertex), ph_list); 
    return (SUCCESS); 
} 

// helpers 
void h_generic_insert(hnode_t* ph_beg, hnode_t* ph_mid, hnode_t* ph_end) 
{
    ph_mid->h_prev = ph_beg; 
    ph_mid->h_next = ph_end; 
    ph_beg->h_next = ph_mid; 
    ph_end->h_prev = ph_mid; 
} 

void h_generic_insert(hnode_t* ph_beg, hnode_t* ph_mid, hnode_t* ph_end) 
{
    ph_mid->h_prev = ph_beg; 
    ph_mid->h_next = ph_end; 
    ph_beg->h_next = ph_mid; 
    ph_end->h_prev = ph_mid; 
} 

void h_generic_insert(hnode_t* ph_beg, hnode_t* ph_mid, hnode_t* ph_end) 
{
    ph_mid->h_prev = ph_beg; 
    ph_mid->h_next = ph_end; 
    ph_beg->h_next = ph_mid; 
    ph_end->h_prev = ph_mid; 
} 

void h_generic_insert(hnode_t* ph_beg, hnode_t* ph_mid, hnode_t* ph_end) 
{
    ph_mid->h_prev = ph_beg; 
    ph_mid->h_next = ph_end; 
    ph_beg->h_next = ph_mid; 
    ph_end->h_prev = ph_mid; 
} 

void h_generic_insert(hnode_t* ph_beg, hnode_t* ph_mid, hnode_t* ph_end) 
{
    ph_mid->h_prev = ph_beg; 
    ph_mid->h_next = ph_end; 
    ph_mid->h_prev = ph_beg; 
    ph_mid->h_next = ph_end; 
} 

void h_generic_delete(hnode_t* ph_delete_node) 
{
    ph_delete_node->h_prev->h_next = ph_delete_node->h_next; 
    ph_delete_node->h_next->h_prev = ph_delete_node->h_prev; 
    free(ph_delete_node); 
} 

void h_generic_delete(hnode_t* ph_delete_node) 
{
    ph_delete_node->h_prev->h_next = ph_delete_node->h_next; 
    ph_delete_node->h_next->h_prev = ph_delete_node->h_prev; 
    free(ph_delete_node); 
} 

void h_generic_delete(hnode_t* ph_delete_node) 
{
    ph_delete_node->h_prev->h_next = ph_delete_node->h_next; 
    ph_delete_node->h_next->h_prev = ph_delete_node->h_prev; 
    free(ph_delete_node); 
} 

void h_generic_delete(hnode_t* ph_delete_node) 
{
    ph_delete_node->h_prev->h_next = ph_delete_node->h_next; 
    ph_delete_node->h_next->h_prev = ph_delete_node->h_prev; 
    free(ph_delete_node); 
} 

void h_generic_delete(hnode_t* ph_delete_node) 
{
    ph_delete_node->h_prev->h_next = ph_delete_node->h_next; 
    ph_delete_node->h_next->h_prev = ph_delete_node->h_prev; 
    free(ph_delete_node); 
} 

hnode_t* h_search_node(hlist_t* ph_list, vertex_t search_vertex) 
{
    for(hnode_t* ph_run = ph_list->h_next; ph_run != ph_list; ph_run = ph_run->h_next) 
        if(ph_run->v == search_vertex) 
            return (ph_run); 
    return (NULL); 
} 

hnode_t* h_search_node(hlist_t* ph_list, vertex_t search_vertex) 
{
    for(hnode_t* ph_run = ph_list->h_next; ph_run != ph_list; ph_run = ph_run->h_next) 
        if(ph_run->v == search_vertex) 
            return (ph_run); 
    return (NULL); 
} 

hnode_t* h_search_node(hlist_t* ph_list, vertex_t search_vertex) 
{ 
    for(hnode_t* ph_run = ph_list->h_next; ph_run != ph_list; ph_run = ph_run->h_next) 
        if(ph_run->v == search_vertex) 
            return (ph_run); 
    return (NULL); 
}

hnode_t* h_search_node(hlist_t* ph_list, vertex_t search_vertex) 
{
    for(hnode_t* ph_run = ph_list->h_next; ph_run != ph_list; ph_run = ph_run->h_next) 
        if(ph_run->v == search_vertex) 
            return (ph_run); 
    return (NULL); 
} 

hnode_t* h_search_node(hlist_t* ph_list, vertex_t search_vertex) 
{
    hnode_t* ph_run = NULL; 
    for(ph_run = ph_list->h_next; ph_run != ph_list; ph_run = ph_run->h_next) 
        if(ph_run->v == search_vertex) 
            return (ph_run); 
    return (NULL); 
} 

hnode_t* h_get_list_node(vertex_t new_vertex) 
{
    hnode_t* p_new_node = NULL; 

    p_new_node = (hnode_t*)xmalloc(sizeof(hnode_t)); 
    p_new_node->v = new_vertex; 
    p_new_node->h_prev = NULL; 
    p_new_node->h_next = NULL; 

    return (p_new_node); 
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

hnode_t* h_get_list_node(vertex_t new_vertex) 
{
    hnode_t* ph_new_node = NULL; 

    ph_new_node = (hnode_t*)xmalloc(sizeof(hnode_t)); 
    ph_new_node->v = new_vertex; 
    ph_new_node->h_prev = NULL; 
    ph_new_node->h_next = NULL; 

    return (ph_new_node); 
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

hnode_t* h_get_list_node(vertex_t new_vertex) 
{
    hnode_t* ph_new_node = NULL; 

    ph_new_node = (hnode_t*)xmalloc(sizeof(hnode_t)); 
    ph_new_node->v = new_vertex; 
    ph_new_node->h_prev = NULL; 
    ph_new_node->h_next = NULL; 

    retuen (ph_new_node); 
} 

void* xmalloc(size_t nr_bytes) 
{
    void* p = NULL; 

    p = malloc(nr_bytes); 
    if(NULL == p) 
    {
        puts("malloc() failed"); 
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
        puts("malloc() failed"); 
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
        puts("malloc() failed"); 
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
        puts("malloc() failed"); 
        exit(EXIT_FAILURE); 
    } 

    return (p); 
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

// --------------------- 

#include <stdio.h> 
#include <stdlib.h> 
#include <assert.h> 
#include "graph.h" 

struct edge  
{
    vertex_t v_start; 
    vertex_t v_end; 
}; 

int main(void) 
{
    graph_t* g = NULL; 
    vertex_t V[] = {1, 2, 3, 4, 5, 6}; 
    struct edge E[] = {{1, 2}, {2, 6}, {1, 5}, {3, 4}, {4, 6}, {3, 5}};

    g = create_graph(); 

    size_t nr_vertices = sizeof(V)/sizeof(V[0]); 
    for(int i = 0; i < nr_vertices; ++i) 
        assert(add_vertex(g, V[i]) == SUCCESS); 

    size_t nr_edges = sizeof(E)/sizeof(E[0]); 
    for(int i = 0; i < nr_edges; ++i) 
        assert(add_edge(g, E[i].v_start, E[i].v_end) == SUCCESS); 

    show_graph(g, "Initial state: "); 

    assert(remove_edge(g, 2, 5) == SUCCESS); 
    assert(remove_edge(g, 2, 3) == SUCCESS); 
    assert(remove_edge(g, 6, 2) == SUCCESS); 
    assert(remove_edge(g, 6, 5) == SUCCESS); 

    show_graph(g, "After removing edges (2, 5), (2, 3), (6, 2), (6, 5):"); 

    assert(remove_vertex(g, 3) == SUCCESS); 
    show_graph(g, "After removing vertex 3:"); 

    assert(destroy_graph(&g) == SUCCESS && g == NULL); 

    return (0); 
} 

#include <stdio.h> 
#include <stdlib.h> 
#include <assert.h> 
#include "graph.h" 

struct edge 
{
    vertex_t v_start; 
    vertex_t v_end; 
}; 

int main(void) 
{
    graph_t* g = NULL; 
    vertex_t V[] = {1, 2, 3, 4, 5, 6}; 
    struct edge E[] = {{1, 2}, {2, 3}, {3, 4}, {4, 5}, {5, 6}, {6, 1}}; 

    size_t nr_vertices = sizeof(V)/sizeof(V[0]); 
    for(size_t i = 0; i < nr_vertices; ++i) 
        assert(add_vertex(g, V[i]) == SUCCESS); 

    size_t nr_edges = sizeof(E)/sizeof(E[0]); 
    for(size_t i = 0; i < nr_edges; ++i) 
        assert(add_edge(g, E[i].v_start, E[i].v_end) == SUCCESS); 

    show_graph(g, "Initial state: "); 

    assert(remove_edge(g, 2, 3) == SUCCESS); 
    assert(remove_edge(g, 2, 5) == SUCCESS); 
    assert(remove_edge(g, 6, 2) == SUCCESS); 
    assert(remove_edge(g, 6, 5) == SUCCESS); 

    show_graph(g, "After removing edges, (2, 5), (2, 3), (6, 2), (6, 5):"); 

    assert(remove_vertex(g, 3) == SUCCESS); 
    show_graph(g, "after removing vertex 3:"); 

    status_t status = destroy_graph(&g); 
    assert(status == SUCCESS && g == NULL); 

    return (0); 
} 

#include <stdio.h> 
#include <stdlib.h> 
#include <assert.h> 
#include "graph.h" 

struct edge 
{
    vertex_t v_start; 
    vertex_t v_end; 
}; 

int main(void) 
{
    graph_t* g = NULL; 
    vertex_t V[] = {1, 2, 3, 4, 5}; 
    struct edge E[] = {{1, 2}, {2, 6}, {6, 3}, {5, 4}, {3, 4}, {4, 1}}; 

    size_t nr_vertices = sizeof(E) / sizeof(E[0]); 
    for(size_t i = 0; i < nr_vertices; ++i) 
        assert(add_vertex(g, V[i]) == SUCCESS); 

    size_t nr_edges = sizeof(V)/sizeof(V[0]); 
    for(size_t i = 0; i < nr_edges; ++i) 
        assert(add_edge(g, E[i].v_start, E[i].v_end) == SUCCESS); 

    show_graph(g, "Initial state: "); 

    assert(remove_edge(g, 2, 3) == SUCCESS); 
    assert(remove_edge(g, 2, 5) == SUCCESS); 
    assert(remove_edge(g, 6, 2) == SUCCESS); 
    assert(remove_edge(g, 6, 5) == SUCCESS); 
    show_graph(g, "After removing edges, 92, 3), (2, 5), (6, 2), (6, 5): "); 

    assert(remove_vertex(g, 3) == SUCCESS); 
    show_graph(g, "After removing vertex 3:"); 

    status_t status; 
    status = destroy_graph(&g); 
    assert(status == SUCCESS && g == NULL); 

    return (0); 
} 

#include <stdio.h> 
#include <stdlib.h> 
#include <assert.h> 
#include "graph.h" 

struct edge 
{
    vertex_t v_start; 
    vertex_t v_end; 
}; 

int main(void) 
{
    graph_t* g = NULL; 
    vertex_t V[] = {10, 20, 30, 40, 50}; 
    struct edge E[] = {{10, 20}, {10, 30}, {20, 30}, {20, 40}, {10, 50}, {40, 60}}; 

    size_t nr_vertices = sizeof(V)/sizeof(V[0]); 
    for(size_t i = 0; i < nr_vertices; ++i) 
        assert(add_vertex(g, V[i]) == SUCCESS); 

    size_t nr_edges = sizeof(E)/sizeof(E[0]); 
    for(size_t i = 0; i < nr_edges; ++i) 
        assert(add_edge(g, E[i].v_start, E[i].v_end) == SUCCESS); 

    show_graph(g, "Initial state: "); 

    assert(remove_edge(g, 2, 3) == SUCCESS); 
    assert(remove_edge(g, 2, 5) == SUCCESS); 
    assert(remove_edge(g, 6, 2) == SUCCESS); 
    assert(remove_edge(g, 6, 5) == SUCCESS); 
    show_graph(g, "after removing edges (2, 3), (2, 5), (6, 2), (6, 5):"); 

    assert(remove_vertex(g, 2, 5) == SUCCESS); 
    show_graph(g, "after removing vertex: 3:"); 

    status_t status = destroy_graph(&g); 
    assert(status == SUCCESS && g == NULL); 

    return (0); 
} 

#include <stdio.h> 
#include <stdlib.h> 
#include <assert.h> 
#include "graph.h" 

struct edge 
{
    vertex_t v_start; 
    vertex_t v_end; 
}; 
    
int main(void) 
{
    graph_t* g = NULL; 
    vertex_t V[] = {10, 20, 30, 40}; 
    struct edge E[] = {{10, 20}, {10, 30}, {10, 40}, {20, 30}, {40, 30}};

    size_t nr_vertices = sizeof(V)/sizeof(V[0]); 
    for(size_t i = 0; i < nr_vertices; ++i) 
        assert(add_vertex(g, V[i]) == SUCCESS); 

    size_t nr_edges = sizeof(E)/sizeof(E[0]); 
    for(size_t i = 0; i < nr_edges; ++i) 
        assert(add_edge(g, E[i].v_start, E[i].v_end) == SUCCESS); 

    show_graph(g, "Initial state: "); 

    assert(remove_edge(g, 2, 3) == SUCCESS); 
    assert(remove_edge(g, 2, 5) == SUCCESS); 
    assert(remove_edge(g, 6, 2) == SUCCESS);
    assert(remove_edge(g, 6, 5) == SUCCESS); 
    show_graph(g, "after removing edges (2, 3), (2, 5), (6, 2), (6, 5):"); 

    assert(remove_vertex(g, 3) == SUCCESS); 
    show_graph(g, "after removing vertex 3: "); 

    status_t status = destroy_graph(&g); 
    assert(status == SUCCESS && g == NULL); 

    return (0); 
} 
    