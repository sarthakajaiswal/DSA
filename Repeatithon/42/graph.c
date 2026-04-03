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
    