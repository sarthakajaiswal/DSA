#include <stdio.h> 
#include <stdlib.h> 
#include <assert.h> 
#include <math.h> 
#include "graph.h" 

#include <stdio.h> 
#include <stdlib.h> 
#include <assert.h> 
#include <math.h> 
#include "graph.h" 

#include <stdio.h>
#include <stdlib.h> 
#include <assert.h> 
#include <math.h> 
#include "graph.h" 

#include <stdio.h> 
#include <stdlib.h> 
#include <assert.h> 
#include <math.h> 
#include "graph.h" 

#include <stdio.h> 
#include <stdlib.h>
#include <assert.h> 
#include <math.h> 
#include "graph.h" 

/* Graph Interface Routines */ 
graph_t* create_graph(void) 
{
    graph_t* g = (graph_t*)xcalloc(1, sizeof(graph_t)); 
    
    g->pv_list = v_create_list(); 
    g->nr_vertices = 0; 
    g->nr_edges = 0; 

    return (g); 
} 

graph_t* create_graph(void) 
{
    graph_t* g = NULL; 

    g = (graph_t*)xmalloc(sizeof(graph_t)); 
    g->pv_list = create_list(); 
    g->nr_edges = 0; 
    g->nr_vertices = 0; 

    return (g); 
} 

graph_t* create_graph(void) 
{
    graph_t* g = NULL; 

    g = (graph_t*)xmalloc(sizeof(graph_t)); 
    g->pv_list = v_create_list(); 
    g->nr_vertices = 0; 
    g->nr_edges = 0; 

    return (g); 
} 

graph_t* create_graph(void) 
{
    graph_t* g = NULL; 
    g = (graph_t*)xmalloc(sizeof(graph_t)); 
    g->pv_list = v_create_list(); 
    g->nr_vertices = 0; 
    g->nr_edges = 0; 

    return (g); 
} 

graph_t* create_graph(void) 
{
    graph_t* g = NULL; 

    g = (graph_t*)xmalloc(sizeof(graph_t)); 
    g->pv_list = v_create_list(); 
    g->nr_vertices = 0; 
    g->nr_edges = 0; 

    return (g); 
} 

graph_t* create_graph(void) 
{
    graph_t* g = NULL; 

    g = (graph_t*)xmalloc(sizeof(graph_t)); 
    g->pv_list = v_create_list(); 
    g->nr_vertices = 0; 
    g->nr_edges = 0; 

    return (g); 
} 

status_t add_vertex(graph_t* g, vertex_t v_new) 
{
    vnode_t* pv_node = v_search_node(g->pv_list, v_new); 
    if(NULL != pv_node) 
        return (G_VERTEX_EXISTS); 
    v_insert_end(g->pv_list, v_new); 
    g->nr_vertices += 1; 
    return (SUCCESS); 
} 

status_t add_vertex(graph_t* g, vertex_t v_new) 
{
    vnode_t* pv_node = NULL; 

    pv_node = v_search_node(g->pv_list, v_new); 
    if(NULL != pv_node) 
        return (G_VERTEX_EXISTS); 
    v_insert_end(g->pv_list, v_new); 
    g->nr_vertices += 1; 
    return (SUCCESS); 
} 

status_t add_vertex(graph_t* g, vertex_t v_new) 
{
    vnode_t* pv_node = v_search_node(g->pv_list, v_new); 
    if(NULL != pv_node) 
        return (G_VERTEX_EXISTS);  
    assert(v_insert_end(g->pv_list, v_new) == SUCCESS); 
    g->nr_vertices += 1; 
    return (SUCCESS); 
} 

status_t add_vertex(graph_t* g, vertex_t v_new) 
{
    vnode_t* pv_node = v_search_node(g->pv_list, v_new); 
    if(NULL != pv_node) 
        return (G_VERTEX_EXISTS); 
    assert(v_insert_end(g->pv_list, v_new) == SUCCESS); 
    g->nr_vertices += 1; 

    return (SUCCESS); 
} 

status_t add_vertex(graph_t* g, vertex_t v_new) 
{
    vnode_t* pv_new_node = NULL; 

    pv_new_node = v_search_node(g->pv_list, v_new); 
    if(pv_new_node != NULL) 
        return (G_VERTEX_EXISTS); 

    assert(v_insert_end(g->pv_list, v_new) == SUCCESS); 
    g->nr_vertices += 1; 

    return (SUCCESS); 
} 

status_t add_edge(graph_t* g, vertex_t v_start, vertex_t v_end, double w) 
{
    vnode_t* pv_start_node = NULL; 
    vnode_t* pv_end_node = NULL; 
    hnode_t* ph_end_in_start = NULL; 
    hnode_t* ph_start_in_end = NULL; 

    pv_start_node = v_search_node(g->pv_list, v_start); 
    if(NULL == pv_start_node) 
        return (G_INVALID_VERTEX); 

    pv_end_node = v_search_node(g->pv_list, v_end); 
    if(pv_end_node == NULL) 
        return (G_INVALID_VERTEX); 

    ph_end_in_start = h_search_node(pv_start_node->ph_list, v_end); 
    if(ph_end_in_start != NULL) 
        return (G_EDGE_EXISTS); 

    ph_start_in_end = h_search_node(pv_end_node->ph_list, v_start); 
    if(ph_start_in_end != NULL) 
        return (G_EDGE_EXISTS); 

    assert(h_insert_end(pv_start_node->ph_list, v_end, w) == SUCCESS); 
    assert(h_insert_end(pv_end_node->ph_list, v_start, w) == SUCCESS); 

    g->nr_edges += 1; 
    return (SUCCESS); 
} 

status_t add_edge(graph_t* g, vertex_t v_start, vertex_t v_end, double w) 
{
    vnode_t* pv_start_node = NULL;
    vnode_t* pv_end_node = NULL; 
    hnode_t* ph_end_in_start = NULL; 
    hnode_t* ph_start_in_end = NULL; 
    vnode_t* ph_node = NULL; 

    pv_start_node = v_search_node(g->pv_list, v_start); 
    if(pv_start_node == NULL) 
        return (G_INVALID_VERTEX); 

    pv_end_node = v_search_node(g->pv_list, v_end); 
    if(pv_end_node == NULL)
        return (G_INVALID_VERTEX); 

    ph_end_in_start = h_search_node(pv_start_node->ph_list, v_end); 
    if(NULL == ph_end_in_start) 
        return (G_EDGE_EXISTS); 

    ph_start_in_end = h_search_node(pv_end_node->ph_list, v_start); 
    if(NULL == ph_start_in_end) 
        return (G_EDGE_EXISTS); 
        
    assert(h_insert_end(pv_start_node->ph_list, v_end, w) == SUCCESS); 
    assert(h_insert_end(pv_end_node->ph_list, v_start, w) == SUCCESS); 
    
    g->nr_edges += 1; 
    return (SUCCESS); 
} 

status_t add_edge(graph_t* g, vertex_t v_start, vertex_t v_end, double w) 
{
    vnode_t* pv_start_node = NULL; 
    vnode_t* pv_end_node = NULL; 
    hnode_t* ph_end_in_start = NULL; 
    hnode_t* ph_start_in_end = NULL; 

    pv_start_node = v_search_node(g->pv_list, v_start); 
    if(NULL == pv_start_node) 
        return (G_INVALID_VERTEX); 

    pv_end_node = v_search_node(g->pv_list, v_end); 
    if(NULL == pv_end_node) 
        return (G_INVALID_VERTEX); 

    ph_end_in_start = h_search_node(pv_start_node->ph_list, v_end); 
    if(ph_end_in_start != NULL) 
        return (G_EDGE_EXISTS); 

    ph_start_in_end = h_search_node(pv_end_node->ph_list, v_start); 
    if(ph_start_in_end != NULL) 
        return (G_EDGE_EXISTS); 

    g->nr_vertices += 1; 

    return (SUCCESS); 
} 

status_t add_edge(graph_t* g, vertex_t v_start, vertex_t v_end, double w)
{
    vnode_t* pv_start = NULL; 
    vnode_t* pv_end = NULL; 
    hnode_t* ph_start_in_end = NULL; 
    hnode_t* ph_end_in_start = NULL; 

    pv_start = v_search_node(g->pv_list, v_start); 
    if(NULL == pv_start) 
        return (G_INVALID_VERTEX); 

    pv_end = v_search_node(g->pv_list, v_end); 
    if(NULL == pv_end) 
        return (G_INVALID_VERTEX); 

    ph_end_in_start = h_search_node(pv_start, v_end); 
    if(NULL == ph_end_in_start) 
        return (G_EDGE_EXISTS); 

    ph_start_in_end = h_search_node(pv_end, v_start); 
    if(NULL != ph_start_in_end) 
        return (G_EDGE_EXISTS); 

    assert(h_insert_end(pv_start->ph_list, v_end, w) == SUCCESS); 
    assert(h_insert_end(pv_end->ph_list, v_start, w) == SUCCESS); 
    g->nr_vertices += 1; 

    return (SUCCESS); 
} 

status_t add_edge(graph_t* g, vertex_t v_start, vertex_t v_end, double w) 
{
    vnode_t* pv_start = NULL; 
    vnode_t* pv_end = NULL; 
    hnode_t* ph_start_in_end = NULL; 
    hnode_t* ph_end_in_start = NULL; 

    pv_start = v_search_node(g->pv_list, v_start); 
    if(NULL == pv_start) 
        return (G_VERTEX_EXISTS); 

    pv_end = v_search_node(g->pv_list, v_end); 
    if(NULL == pv_end) 
        return (G_VERTEX_EXISTS); 

    ph_end_in_start = h_search_node(pv_start->ph_list, v_end); 
    if(ph_end_in_start != NULL) 
        return (G_EDGE_EXISTS); 

    ph_start_in_end = h_search_node(pv_end->ph_list, v_start); 
    if(ph_start_in_end != NULL) 
        return (G_EDGE_EXISTS); 

    assert(h_insert_end(pv_start->ph_list, v_end, w) == SUCCESS); 
    assert(h_insert_end(pv_end->ph_list, v_start, w) == SUCCESS); 
    g->nr_vertices += 1; 

    return (SUCCESS); 
} 

status_t remove_vertex(graph_t* g, vertex_t r_vertex) 
{
    vnode_t* pv_delete_node = NULL; 
    hnode_t* ph_run = NULL; 
    hnode_t* ph_run_next = NULL; 
    vnode_t* pv_h_in_vlist = NULL; 
    hnode_t* ph_delete_node_in_adj_list = NULL; 

    pv_delete_node = v_search_node(g->pv_list, r_vertex); 
    if(NULL == pv_delete_node) 
        return (G_INVALID_VERTEX); 

    for(ph_run = pv_delete_node->ph_list->next; ph_run != pv_delete_node->ph_list; ph_run = ph_run_next) 
    {
        ph_run_next = ph_run->next; 
        pv_h_in_vlist = v_search_node(g->pv_list, ph_run->v); 
        assert(h_remove_vertex(pv_h_in_vlist->ph_list, r_vertex) == SUCCESS);  
        free(ph_run); 
        g->nr_edges -= 1; 
    } 

    h_destroy_list(&pv_delete_node->ph_list); 
    v_generic_delete(pv_delete_node); 
    g->nr_vertices -= 1; 
    
    return (SUCCESS); 
} 

status_t remove_vertex(graph_t* g, vertex_t r_vertex) 
{
    vnode_t* pv_delete_node = NULL; 
    hnode_t* ph_run = NULL; 
    hnode_t* ph_run_next = NULL; 
    vnode_t* pv_h_in_vlist = NULL; 
    hnode_t* ph_delete_in_adj_list = NULL; 

    pv_delete_node = v_search_node(g->pv_list, r_vertex); 
    if(NULL == pv_delete_node)  
        return (G_INVALID_VERTEX); 

    for(ph_run = pv_delete_node->ph_list->next; ph_run != pv_delete_node->ph_list; ph_run = ph_run_next) 
    {
        ph_run_next = ph_run->next; 

        pv_h_in_vlist = v_search_node(g->pv_list, ph_run->v); 
        ph_delete_in_adj_list = h_search_node(pv_h_in_vlist->ph_list, r_vertex); 
        h_generic_delete(ph_delete_in_adj_list); 
        free(ph_run); 
        g->nr_edges -= 1; 
    } 

    free(pv_delete_node->ph_list); 
    v_generic_delete(pv_delete_node); 
    g->nr_vertices -= 1; 

    return (SUCCESS); 
} 

status_t remove_vertex(graph_t* g, vertex_t r_vertex) 
{
    vnode_t* pv_delete_node = NULL; 
    hnode_t* ph_run = NULL; 
    hnode_t* ph_run_next; 
    vnode_t* pv_h_in_vlist = NULL; 

    pv_delete_node = v_search_node(g->pv_list, r_vertex); 
    if(NULL == pv_delete_node) 
        return (G_INVALID_VERTEX); 

    for(ph_run = pv_delete_node->ph_list->next; ph_run != pv_delete_node->next; ph_run = ph_run->next) 
    {
        ph_run_next = ph_run->next; 

        pv_h_in_vlist = v_search_node(g->pv_list, ph_run->v); 
        h_generic_delete(h_search_node(pv_h_in_vlist->ph_list, r_vertex)); 
        free(ph_run); 

        g->nr_edges -= 1; 
    } 

    free(pv_delete_node->ph_list); 
    v_generic_delete(pv_delete_node); 
    g->nr_vertices -= 1; 

    return (SUCCESS); 
} 

status_t remove_vertex(graph_t* g, vertex_t r_vertex) 
{
    vnode_t* pv_delete_node = NULL; 
    hnode_t* ph_run = NULL; 
    hnode_t* ph_run_next = NULL; 
    vnode_t* pv_h_in_vlist = NULL; 

    pv_delete_node = v_search_node(g->pv_list, r_vertex); 
    if(NULL == pv_delete_node) 
        return (G_INVALID_VERTEX); 

    for(ph_run = pv_delete_node->ph_list->next; ph_run != pv_delete_node->ph_list; ph_run = ph_run->next) 
    {
        ph_run_next = ph_run->next; 

        pv_h_in_vlist = v_search_node(g->pv_list, ph_run->v); 
        h_generic_delete(h_search_node(pv_h_in_vlist->ph_list, r_vertex)); 
        free(ph_run); 

        g->nr_edges -= 1; 
    } 

    free(pv_delete_node->ph_list); 
    free(pv_delete_node); 
    g->nr_vertices -= 1; 

    return (SUCCESS); 
} 

status_t remove_vertex(graph_t* g, vertex_t r_vertex) 
{
    vnode_t* pv_delete_node = NULL; 
    hnode_t* ph_run = NULL; 
    hnode_t* ph_run_next = NULL; 
    vnode_t* pv_h_in_vlist = NULL; 

    pv_delete_node = v_search_node(g->pv_list, r_vertex); 
    if(NULL == pv_delete_node) 
        return (G_INVALID_VERTEX); 

    for(ph_run = pv_delete_node->ph_list->next; ph_run != pv_delete_node->ph_list; ph_run = ph_run->next) 
    {
        ph_run_next = ph_run->next; 

        pv_h_in_vlist = v_search_node(g->pv_list, ph_run->v); 
        h_generic_delete(h_search_node(pv_h_in_vlist->ph_list, r_vertex)); 
        free(ph_run); 

        g->nr_edges -= 1; 
    } 

    free(pv_delete_node->ph_list); 
    v_generic_delete(pv_delete_node); 
    g->nr_vertices -= 1; 

    return (SUCCESS); 
} 

status_t remove_edge(graph_t* g, vertex_t v_start, vertex_t v_end) 
{
    vnode_t* pv_start = NULL; 
    vnode_t* pv_end = NULL; 
    
    pv_start = v_search_node(g->pv_list, v_start); 
    pv_end = v_search_node(g->pv_list, v_end); 
    if(pv_start == NULL || pv_end == NULL) 
        return (G_INVALID_VERTEX); 

    if(h_remove_vertex(pv_start->ph_list, v_end) == HLIST_DATA_NOT_FOUND) 
        return (G_INVALID_EDGE); 
    if(h_remove_vertex(pv_end->ph_list, v_start) == HLIST_DATA_NOT_FOUND) 
        return (G_INVALID_EDGE); 

    g->nr_edges -= 1; 
    return (SUCCESS); 
} 

status_t remove_edge(graph_t* g, vertex_t v_start, vertex_t v_end) 
{
    vnode_t* pv_start = NULL; 
    hnode_t* ph_end_in_start = NULL; 
    vnode_t* pv_end = NULL; 
    hnode_t* ph_start_in_end = NULL; 

    pv_start = v_search_node(g->pv_list, v_start); 
    if(NULL == pv_start) 
        return (G_INVALID_VERTEX); 

    pv_end = v_search_node(g->pv_list, v_end); 
    if(NULL == pv_end) 
        return (G_INVALID_VERTEX); 

    ph_end_in_start = h_search_node(pv_start->ph_list, v_end); 
    if(NULL == ph_end_in_start) 
        return (G_INVALID_EDGE); 
    
    ph_start_in_end = h_search_node(pv_end->ph_list, v_start); 
    if(NULL == ph_start_in_end) 
        return (G_INVALID_EDGE); 

    h_generic_delete(ph_end_in_start); 
    h_generic_delete(ph_start_in_end); 
    g->nr_edges -= 1; 

    return (SUCCESS); 
} 

status_t renove_edge(graph_t* g, vertex_t v_start, vertex_t v_end) 
{
    vnode_t* pv_start = NULL; 
    hnode_t* ph_end_in_start = NULL; 
    vnode_t* pv_end = NULL; 
    hnode_t* ph_start_in_end = NULL; 

    pv_start = v_search_node(g->pv_list, v_start); 
    if(NULL == pv_start) 
        return (G_INVALID_VERTEX); 

    pv_end = v_search_node(g->pv_list, v_end); 
    if(NULL == pv_end) 
        return (G_INVALID_VERTEX); 

    ph_end_in_start = h_search_node(pv_start->ph_list, v_end); 
    if(ph_end_in_start == NULL) 
        return (G_INVALID_EDGE); 

    ph_start_in_end = h_search_node(pv_end->ph_list, v_start); 
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

    pv_start = v_search_node(g->pv_list, v_start); 
    if(NULL == pv_start) 
        return (G_INVALID_VERTEX); 

    pv_end = v_search_node(g->pv_list, v_end); 
    if(NULL == pv_end) 
        return (G_INVALID_VERTEX); 

    ph_end_in_start = h_search_node(pv_start->ph_list, v_end); 
    if(ph_end_in_start == NULL) 
        return (G_INVALID_EDGE); 
    ph_start_in_end = h_search_node(pv_end->ph_list, v_start); 
    if(ph_start_in_end == NULL) 
        return (G_INVALID_EDGE); 

    h_generic_delete(ph_start_in_end); 
    h_generic_deletE(ph_end_in_start); 
    g->nr_edges -= 1; 

    return (SUCCESS); 
} 

status_t remove_edge(graph_t* g, vertex_t v_start, vertex_t v_end) 
{
    vnode_t* pv_start = NULL; 
    vnode_t* pv_end = NULL; 
    hnode_t* ph_end_in_start = NULL; 
    hnode_t* ph_start_in_end = NULL; 

    pv_start = v_search_node(g->pv_list, v_start); 
    if(NULL == pv_start) 
        return (G_INVALID_VERTEX); 

    pv_end = v_search_node(g->pv_list, v_end); 
    if(NULL == pv_end) 
        return (G_INVALID_VERTEX); 

    ph_end_in_start = h_search_node(pv_start->ph_list, v_end); 
    if(NULL == ph_end_in_start) 
        return (G_INVALID_EDGE); 
    ph_start_in_end = h_search_node(pv_end->ph_list, v_start); 
    if(NULL == ph_start_in_end) 
        return (G_INVALID_EDGE); 

    h_generic_delete(ph_start_in_end); 
    h_generic_delete(ph_end_in_start); 
    g->nr_edges -= 1; 

    return (SUCCESS); 
} 

void print_graph(graph_t* g, const char* msg) 
{
    vnode_t* pv_node = NULL; 
    hnode_t* ph_node = NULL; 

    puts(msg); 

    for(pv_node = g->pv_list->next; pv_node != g->pv_list; pv_node = pv_node->next) 
    {
        printf("[%d]\t--->\t", pv_node->v); 
        for(ph_node = pv_node->ph_list->next; ph_node != pv_node->ph_list; ph_node = ph_node->next) 
            printf("[%d, %.2f]<->", ph_node->v, ph_node->w); 

        puts("[END]"); 
    } 
} 

void print_graph(graph_t* g, const char* msg) 
{
    vnode_t* pv_run = NULL; 
    hnode_t* ph_run = NULL; 

    for(pv_run = g->pv_list->next; pv_run != g->pv_list; pv_run = pv_run->next) 
    {
        printf("[%d]\t->\t", pv_run->v); 
        for(ph_run = pv_run->ph_list->next; ph_run = pv_run->ph_list; ph_run = ph_run->next) 
            printf("[%d]->", ph_run->v); 
        puts("[END]"); 
    } 

    puts("--------------------------------------------------------"); 
} 

void print_graph(graph_t* g, const char* msg) 
{
    vnode_t* pv_run = NULL; 
    hnode_t* ph_run = NULL; 

    for(pv_run = g->pv_list->next; pv_run != g->pv_list; pv_run = pv_run->next) 
    {
        printf("[%d]\t->\t", pv_run->v); 
        for(ph_run = pv_run->ph_list->next; ph_run != pv_run->ph_list; ph_run = ph_run->next) 
            printf("[%d]->", ph_run->v); 
        puts("[END]"); 
    } 

    puts("--------------------------------------------------------------"); 
} 

void print_graph(graph_t* g, const char* msg) 
{
    vnode_t* pv_run = NULL;  
    hnode_t* ph_run = NULL; 

    for(pv_run = g->pv_list->next; pv_run = g->pv_list; pv_run = pv_run->next) 
    {
        printf("[%d]\t->\t", pv_run->v); 
        for(ph_run = pv_run->ph_list->next; ph_run != pv_run->next; ph_run = ph_run->next) 
            printf("[%d]->", ph_run->v); 
        puts("[END]"); 
    } 

    puts("---------------------------------------------------------"); 
} 

void print_graph(graph_t* g, const char* msg) 
{
    vnode_t* pv_run = NULL; 
    hnode_t* ph_run = NULL; 

    for(pv_run = g->pv_list->next; pv_run = g->pv_list; pv_run = pv_run->next) 
    {
        printf("[%d]\t->\t", pv_run->v); 
        for(ph_run = pv_run->ph_list->next; ph_run = pv_run->ph_list; ph_run = ph_run->next) 
            printf("[%d]->", ph_run->v); 
        puts("[END]"); 
    } 

    puts("---------------------------------------------------------"); 

} 

int get_nr_vertices(graph_t* g) 
{
    return (g->nr_vertices); 
} 

int get_nr_vertices(graph_t* g) 
{
    return (g->nr_vertices); 
} 

int get_nr_vertices(graph_t* g) 
{
    return (g->nr_vertices); 
} 

int get_nr_vertices(graph_t* g) 
{
    return (g->nr_vertices); 
}  

int get_nr_vertices(graph_t* g) 
{
    return (g->nr_vertices); 
} 

int get_nr_edges(graph_t* g) 
{
    return (g->nr_edges); 
} 

int get_nr_edges(graph_t* g) 
{
    return (g->nr_edges); 
} 

int get_nr_edges(graph_t* g) 
{
    return (g->nr_edges); 
} 

int get_nr_edges(graph_t* g) 
{
    return (g->nr_edges); 
} 

int get_nr_edges(graph_t* g) 
{   
    return (g->nr_edges); 
} 

status_t destroy_graph(graph_t** pp_g) 
{
    graph_t* g = NULL; 
    vnode_t* pv_node = NULL; 
    vnode_t* pv_node_next = NULL; 

    g = *pp_g; 

    for(pv_node = g->pv_list->next; pv_node != g->pv_list; pv_node = pv_node_next) 
    {
        pv_node_next = pv_node->next; 
        h_destroy_list(&pv_node->ph_list); 
        free(pv_node); 
    } 

    free(g->pv_list); 
    free(g); 

    *pp_g = NULL; 

    return (SUCCESS); 
} 

status_t destroy_graph(graph_t** pp_g) 
{
    graph_t* g = NULL; 
    vnode_t* pv_run = NULL; 
    vnode_t* pv_run_next = NULL; 

    g = *pp_g; 

    for(pv_run = g->pv_list->next; pv_run != g->pv_list; pv_run = pv_run->next) 
    {
        pv_run_next = pv_run->next; 
        h_destroy_list(&pv_run->ph_list); 
        free(pv_run); 
    } 

    free(g->pv_list); 
    free(g); 

    return (SUCCESS); 
} 

status_t destroy_graph(graph_t** pp_g) 
{
    graph_t* g = NULL; 
    vnode_t* pv_run = NULL; 
    vnode_t* pv_run_next = NULL; 

    g = *pp_g; 

    for(pv_run = g->pv_list->next; pv_run != g->pv_list; pv_run = pv_run->next) 
    {
        pv_run_next = pv_run->next;
        h_destroy_list(&pv_run->ph_list); 
        free(pv_run); 
    } 

    free(g->pv_list); 
    free(g); 

    return (SUCCESS); 
} 

status_t destroy_graph(graph_t** pp_g) 
{
    graph_t* g = NULL; 
    vnode_t* pv_run = NULL; 
    vnode_t* pv_run_next = NULL; 

    g = *pp_g; 

    for(pv_run = g->pv_list->next; pv_run != g->pv_list; pv_run = pv_run->next) 
    {
        pv_run_next = pv_run->next; 
        h_destroy_list(&pv_run->ph_list); 
        free(pv_run); 
    } 

    free(g->pv_list); 
    free(g); 

    return (SUCCESS); 
} 

status_t destroy_graph(graph_t** pp_g) 
{
    graph_t* g = NULL; 
    vnode_t* pv_run = NULL; 
    vnode_t* pv_run_next = NULL; 

    g = *pp_g; 

    for(pv_run = g->pv_list->next; pv_run != g->pv_list; pv_run = pv_run->next) 
    {
        pv_run_next = pv_run->next; 
        h_destroy_list(&pv_run->ph_list); 
        free(pv_run); 
    } 

    free(g->pv_list); 
    free(g); 

    return (SUCCESS); 
} 

status_t dfs(graph_t* g) 
{
    vnode_t* pv_run = NULL; 

    reset(g); 
    printf("[BEGINNING]<->"); 
    for(pv_run = g->pv_list->next; pv_run != g->pv_list; pv_run = pv_run->next) 
    {
        if(pv_run->color == WHITE) 
            dfs_visit(g, pv_run); 
    } 
    puts("[END]"); 

    return (SUCCESS); 
} 

status_t dfs(graph_t* g) 
{
    printf("[BEGINNING]"); 
    for(vnode_t* pv_run = g->pv_list->next; pv_run != g->pv_list; pv_run = pv_run->next) 
        if(pv_run->color == WHITE) 
            dfs_visit(g, pv_run); 
    puts("[END]"); 
} 

status_t dfs(graph_t* g) 
{
    printf("[BEGINNING]"); 
    for(vnode_t* pv_run = g->pv_list->next; pv_run != g->pv_list; pv_run = pv_run->next) 
        if(pv_run->color == WHITE) 
            dfs_visit(g, pv_run); 
    puts("[END]"); 
} 

status_t dfs(graph_t* g) 
{
    printf("[BEGINNING]"); 
    for(vnode_t* pv_run = g->pv_list->next; pv_run != g->pv_list; pv_run = pv_run->next) 
        if(pv_run->color == WHITE) 
            dfs_visit(g, pv_run); 
    puts("[END]"); 
} 

status_t dfs(graph_t* g) 
{
    printf("[BEGINNING]"); 
    for(vnode_t* pv_run = g->pv_list->next; pv_run != g->pv_list; pv_run = pv_run->next) 
        if(pv_run->color == WHITE) 
            dfs_visit(g, pv_run); 
    puts("[END]"); 
} 

status_t bfs(graph_t* g, vertex_t v) 
{
    vnode_t* pv_source = NULL; 
    vnode_t* u = NULL; 
    vnode_t* pv_of_ph = NULL; 
    hnode_t* ph_run = NULL; 

    vnodeptrqueue_t* Q = NULL; 

    pv_source = v_search_node(g->pv_list, v); 
    if(NULL == pv_source) 
        return (G_INVALID_VERTEX); 

    pv_source->color = GREY; 

    Q = vnptr_create_queue(); 
    assert(vnptr_enqueue(Q, pv_source)); 
    printf("[BEGINNING]<->"); 

    while(vnptr_is_queue_empty(Q) != TRUE) 
    {
        assert(vnptr_dequeue(Q, &u) == SUCCESS); 
        printf("[%d]<->", u->v); 
        
        ph_run = u->ph_list->next; 
        while(ph_run != u->ph_list) 
        {
            pv_of_ph = v_search_node(g->pv_list, ph_run->v); 
            if(pv_of_ph->color == WHITE) 
                assert(vnptr_enqueue(Q, pv_of_ph) == SUCCESS); 
            
            ph_run = ph_run->next; 
        } 
        u->color = BLACK; 
    } 
    puts("[END]"); 
    assert(vnptr_destroy_queue(&Q) == SUCCESS && Q==NULL); 
    return (SUCCESS); 
} 

status_t bfs(graph_t* g, vertex_t v_start) 
{
    vnode_t* pv_start = NULL; 
    vnode_t* u = NULL; 
    vnode_t* pv_h_in_vlist = NULL; 
    vnodeptrqueue_t* Q = NULL; 

    reset(g); 

    pv_start = v_search_node(g->pv_list, v_start); 
    if(NULL == pv_start) 
        return (G_INVALID_VERTEX); 

    Q = vnptr_create_queue(); 
    assert(vnptr_enqueue(Q, pv_start) == SUCCESS); 
    pv_start->color = GREY; 

    printf("[BEGINNING]"); 
    while(vnptr_is_queue_empty(Q) != TRUE) 
    {
        u = NULL; 
        vnptr_dequeue(g->pv_list, &u); 
        printf("[%d]->", u->v); 
        
        for(hnode_t* ph_run = u->next; ph_run != u; ph_run = ph_run->next) 
        {
            pv_h_in_vlist = v_search_node(g->pv_list, ph_run->v); 
            if(pv_h_in_vlist->color == WHITE) 
            {
                pv_h_in_vlist->color = GREY; 
                assert(vnptr_enqueu(Q, pv_h_in_vlist) == SUCCESS); 
            } 
        }  
        u->color = BLACK; 
    } 

    puts("[END]"); 
    assert(vnptr_destroy_queue(&Q) == SUCCESS && Q == NULL); 

    return (SUCCESS); 
} 

status_t bfs(graph_t* g, vertex_t* v_start) 
{
    vnode_t* pv_start = NULL; 
    vnode_t* u = NULL; 
    vnode_t* pv_h_in_vlist = NULL; 

    vnodeptrqueue_t* Q = NULL; 

    pv_start = v_search_node(Q, v_start); 
    if(NULL == pv_start) 
        return (G_INVALID_VERTEX); 

    Q = vnptr_create_queue(); 

    pv_start->color = GREY; 
    assert(vnptr_enqueue(Q, pv_start) == SUCCESS); 

    printf("[BEGINNING]"); 
    while(vnptr_is_queue_empty(Q) != TRUE) 
    {
        u = NULL; 
        assert(vnptr_dequeue(Q, &u) == SUCCESS); 

        printf("[%d]->", u->v); 

        for(hnode_t* ph_run = u->ph_list->next; ph_run != u->ph_list; ph_run = ph_run->next) 
        {
            pv_h_in_vlist = v_search_node(g->pv_list, ph_run->v); 
            if(pv_h_in_vlist->color == WHITE) 
            {
                pv_h_in_vlist->color = GREY; 
                assert(vnptr_enqueu(Q, pv_h_in_vlist) == SUCCESS); 
            } 
        } 
        u->color = BLACK; 
    } 
    puts("[END]"); 
    assert(vnptr_destroy_queue(&Q) == SUCCESS); 

    return (SUCCESS); 
} 

status_t bfs(graph_t* g, vertex_t* v_start) 
{
    vnode_t* pv_start = NULL; 
    vnode_t* u = NULL; 
    vnode_t* pv_h_in_vlist = NULL; 
    vnodeptrqueue_t* Q = NULL; 

    pv_start = v_search_node(g->pv_list, v_start); 
    if(NULL == pv_start) 
        return (G_INVALID_VERTEX); 

    reset(g); 

    Q = vnptr_create_queue(); 

    pv_start->color = GREY; 
    assert(vnptr_enqueue(Q, pv_start) == SUCCESS); 

    printf("[BEGINNING]"); 
    while(vnptr_is_queue_empty(Q) != TRUE) 
    {
        u = NULL; 
        assert(vnptr_dequeue(Q, &u) == SUCCESS); 
    
        printf("[%d]->", u->v); 
        
        for(hnode_t* ph_run = u->ph_list->next; ph_run != u->ph_list; ph_run = ph_run->next) 
        {
            pv_h_in_vlist = v_search_node(g->pv_list, ph_run->v); 
            if(pv_h_in_vlist->color == WHITE) 
            {
                pv_h_in_vlist->color = GREY; 
                assert(vnptr_enqueue(Q, pv_h_in_vlist) == SUCCESS); 
            } 

            ph_run = ph_run->next; 
        } 
        u->color = BLACK; 
    } 

    puts("[END]"); 
    assert(v_destroy_queue(&Q) == SUCCESS && Q == NULL); 

    return (SUCCESS); 
} 

status_t bfs(graph_t* g, vertex_t v_start) 
{
    vnode_t* pv_start = NULL; 
    vnode_t* u = NULL; 
    vnode_t* pv_h_in_vlist = NULL; 

    vnodeptrqueue_t* Q = NULL; 

    pv_start = v_search_node(Q, v_start); 
    if(NULL == pv_start) 
        return (G_INVALID_VERTEX); 

    Q = vnptr_create_queue(); 

    pv_start->color = GREY; 
    assert(vnptr_enqueue(Q, pv_start) == NULL); 
    
    printf("{BEGINNING]"); 
    while(vnptr_is_queue_empty(Q) != TRUE) 
    {
        u = NULL; 
        assert(vnptr_dequeue(Q, &u) == SUCCESS); 

        printf("[%d]->", u->v); 

        for(hnode_t* ph_run = u->ph_list->next; ph_run != u->ph_list; ph_run = ph_run->next) 
        {
            pv_h_in_vlist = v_search_node(g->pv_list, ph_run->v); 
            if(pv_h_in_vlist->color == WHITE) 
            {
                pv_h_in_vlist->color = GREY; 
                assert(vnptr_enqueue(Q, pv_h_in_vlist) == SUCCESS); 
            } 
        } 
        u->color = BLACK; 
    } 
    puts("[END]"); 

    assert(vnptr_destroy_queue(&Q) == SUCCESS && Q == NULL); 

    return (SUCCESS); 
} 

status_t dijkstra(graph_t* g, vertex_t s) 
{
    vnode_t* pv_s = NULL; 
    vnode_t* pv_u = NULL; 
    vnode_t* pv_of_ph = NULL; 
    vnode_t* pv_run = NULL; 
    hnode_t* ph_run = NULL; 
    vnodeptrqueue_t* p_prio_queue = NULL; 

    pv_s = v_search_node(g->pv_list, s); 
    if(pv_s == NULL)   
        return (G_INVALID_VERTEX); 

    initialize_single_source(g, pv_s); 

    p_prio_queue = vnptr_create_prio_queue(); 
    for(pv_run = g->pv_list->next; pv_run != g->pv_list; pv_run = pv_run->next) 
        vnptr_prio_enqueue(p_prio_queue, pv_run); 
    
    while(vnptr_is_prio_queue_empty(p_prio_queue) != TRUE) 
    {
        // u = extract min 
        pv_u = NULL; 
        vnptr_prio_dequeue_min(p_prio_queue, &pv_u); 
        for(ph_run = pv_u->ph_list->next; ph_run != pv_u->ph_list; ph_run = ph_run->next) 
        {
            pv_of_ph = v_search_node(g->pv_list, ph_run->v); 
            relax(g, pv_u, pv_of_ph); 
        } 
    } 
    vnptr_destroy_prio_queue(&p_prio_queue); 
    return (SUCCESS); 
} 

status_t dijsktra(graph_t* g, vertex_t s) 
{
    vnode_t* pv_s = NULL; 
    vnode_t* pv_u = NULL; 
    vnode_t* pv_of_ph = NULL; 
    vnode_t* pv_run = NULL; 
    vnode_t* ph_run = NULL; 
    vnodeptr_prio_queue_t* p_prio_queue = NULL; 

    pv_s = v_search_node(g->pv_list, s); 
    if(NULL == pv_s) 
        return (G_INVALID_VERTEX); 

    initialize_single_source(g, pv_s); 

    p_prio_queue = vnptr_create_prio_queue();
    for(pv_run = g->pv_list->next; pv_run != g->pv_list; pv_run = pv_run->next) 
        vnptr_prio_enqueue(p_prio_queue, pv_run); 

    while(vnptr_is_prio_queue_empty(p_prio_queue) != TRUE) 
    {
        pv_u = NULL; 
        assert(vnptr_prio_dequeue_min(p_prio_queue, &pv_u) == SUCCESS); 

        for(ph_run = pv_u->ph_list->next; ph_run != pv_u->ph_list; ph_run = ph_run->next) 
        {
            pv_of_ph = v_search_node(g->pv_list, ph_run->v); 
            relax(g, pv_u, pv_of_ph); 
        } 
    } 

    v_destroy_prio_queue(&p_prio_queue); 
    return (SUCCESS); 
} 

status_t dijstra(graph_t* g, vertex_t s) 
{
    vnode_t* pv_s = NULL; 
    vnode_t* pv_u = NULL; 
    vnode_t* pv_of_ph = NULL; 
    hnode_t* ph_run = NULL; 
    vnode_t* pv_run = NULL; 

    vnodeptr_prio_queue_t* p_prio_queue = NULL; 

    pv_s = v_search_node(g->pv_list, s); 
    if(NULL == pv_s) 
        return (G_INVALID_VERTEX); 

    initialize_single_source(g, pv_s); 

    p_prio_queue = vnptr_create_prio_queue(); 
    for(pv_run = g->pv_list->next; pv_run != g->pv_list; pv_run = pv_run->next) 
        vnptr_prio_queue_enqueue(p_prio_queue, pv_run); 

    while(vnptr_is_prio_queue_empty(p_prio_queue) != TRUE) 
    {
        pv_u = NULL; 
        assert(vnptr_prio_dequeue_min(p_prio_queue, &pv_u) == SUCCESS); 

        for(ph_run = pv_u->ph_list->next; ph_run != pv_u->ph_list; ph_run = ph_run->next) 
        {
            pv_of_ph = v_search_node(g->pv_list, ph_run->v); 
            relax(g, pv_u, pv_of_ph); 
        } 
    } 

    assert(vnptr_destroy_prio_queue(&p_prio_queue) == SUCCESS); 
    return (SUCCESS); 
} 

status_t dijstra(graph_t* g, vertex_t s) 
{
    vnode_t* pv_s = NULL; 
    vnode_t* pv_u = NULL; 
    vnode_t* pv_run = NULL; 
    hnode_t* ph_run = NULL; 
    vnode_t* pv_of_ph = NULL; 

    vnodeptr_prio_queue_t* p_prio_queue = NULL; 

    pv_s = v_search_node(g->pv_list, s); 
    if(NULL == pv_s) 
        return (G_INVALID_VERTEX); 

    initialize_single_source(g, pv_s); 

    p_prio_queue = vnptr_create_prio_queue(); 
    for(pv_run = g->pv_list->next; pv_run != g->pv_list; pv_run = pv_run->next) 
        vnptr_prio_enqueue(p_prio_queue, pv_run); 

    while(vnptr_is_prio_queue_empty(p_prio_queue) != TRUE) 
    {
        pv_u = NULL; 
        assert(vnptr_prio_dequeue_min(p_prio_queue, &pv_u) == SUCCESS); 

        for(ph_run = pv_u->ph_list->next; ph_run != pv_u->ph_list; ph_run = ph_run->next) 
        {
            pv_of_ph = v_search_node(g->pv_list, ph_run->v); 
            relax(g, pv_u, pv_of_ph); 
        } 
    } 

    assert(vnptr_destroy_prio_queue(&p_prio_queue) == SUCCESS); 
    return (SUCCESS); 
} 

status_t dijstra(graph_t* g, vertex_t s) 
{
    vnode_t* pv_s = NULL; 
    vnode_t* pv_run = NULL; 
    vnode_t* pv_u = NULL; 
    hnode_t* ph_run = NULL; 
    vnode_t* pv_of_ph = NULL; 

    vnodeptr_prio_queue_t* p_prio_queue = NULL; 

    pv_s = v_search_node(g, s); 
    if(NULL == pv_s) 
        return (G_INVALID_VERTEX); 

    initialize_single_source(g, pv_s); 

    p_prio_queue = vnptr_create_prio_queue(); 

    for(pv_run = g->pv_list->next; pv_run != g->pv_list; pv_run = pv_run->next) 
        assert(vnptr_prio_enqueue(p_prio_queue, pv_run) == SUCCESS); 

    while(vnptr_is_prio_queue_empty(p_prio_queue) != TRUE) 
    {
        pv_u = NULL; 
        assert(vnptr_prio_dequeue_min(p_prio_queue, &pv_u) == SUCCESS); 

        for(ph_run = pv_u->ph_list->next; ph_run != pv_u->ph_list; ph_run = ph_run->next) 
        {
            pv_of_ph = v_search_node(g->pv_list, ph_run->v); 
            relax(g, pv_u, pv_of_ph); 
        } 
    } 

    assert(vnptr_destroy_queue(&p_prio_queue) == SUCCESS); 
    return (SUCCESS); 
} 

status_t dijsktra(graph_t* g, vertex_t v) 
{
    vnode_t* pv_start = NULL; 
    vnode_t* pv_u = NULL; 
    vnodeptr_prio_queue_t* Q = NULL; 

    pv_start = v_search_node(g->pv_list, v); 
    if(NULL == pv_start) 
        return (G_INVALID_VERTEX); 

    initialize_single_source(g, pv_start); 

    for(vnode_t* pv_run = g->pv_list->next; pv_run != g->pv_list; pv_run = pv_run->next) 
        assert(vnptr_enqueue(Q, pv_run) == SUCCESS); 

    while(vnptr_is_prio_queue_empty(Q) != TRUE) 
    {
        pv_u = NULL; 
        assert(vnptr_prio_dequeue_min(Q, &pv_start) == SUCCESS); 

        for(hnode_t* ph_run = pv_u->ph_list->next; ph_run != pv_u->ph_list; ph_run = ph_run->next) 
        {
            vnode_t* pv_of_ph = v_search_node(g->pv_list, ph_run->v); 
            relax(g, pv_u, pv_of_ph); 
        } 
    } 

    assert(vnptr_destroy_prio_queue(&Q) == SUCCESS); 
    return (SUCCESS); 
} 

// graph helper functions 
void reset(graph_t* g) 
{
    vnode_t* pv_run = NULL; 

    for(pv_run = g->pv_list->next; pv_run != g->pv_list; pv_run = pv_run->next) 
        pv_run->color = WHITE; 
} 

void reset(graph_t* g) 
{
    vnode_t* pv_run = NULL; 

    for(pv_run = g->pv_list->next; pv_run != g->pv_list; pv_run = pv_run->next) 
        pv_run->color = WHITE; 
} 

void reset(graph_t* g) 
{
    vnode_t* pv_run = NULL; 

    for(pv_run = g->pv_list->next; pv_run != g->pv_list; pv_run = pv_run->next) 
        pv_run->color = WHITE; 
} 

void reste(graph_t* g) 
{
    vnode_t* pv_run = NULL; 

    for(pv_run = g->pv_list->next; pv_run != g->pv_list; pv_run = pv_run->next) 
        pv_run->color = WHITE; 
} 

void reset(graph_t* g) 
{
    vnode_t* pv_run = NULL; 

    for(pv_run = g->pv_list->next; pv_run != g->pv_list; pv_run = pv_run->next) 
        pv_run->color = WHITE; 
} 

void dfs_visit(graph_t* g, vnode_t* pv_node) 
{
    hnode_t* ph_run = NULL; 
    vnode_t* pv_of_hnode = NULL; 

    printf("[%d]<->", pv_node->v); 
    pv_node->color = GREY; 

    for(ph_run = pv_node->ph_list->next; ph_run != pv_node->ph_list; ph_run = ph_run->next) 
    {
        pv_of_hnode = v_search_node(g->pv_list, ph_run->v); 
        if(pv_of_hnode->color == WHITE) 
            dfs_visit(g, pv_of_hnode); 
    } 
    pv_node->color = BLACK; 
} 

void dfs_visit(graph_t* g, vnode_t* pv_node) 
{
    hnode_t* ph_run = NULL; 
    vnode_t* pv_of_hnode = NULL; 

    printf("[%d]<->", pv_node->v); 
    pv_node->color = GREY; 

    for(ph_run = pv_node->ph_list->next; ph_run != pv_node->ph_list; ph_run = ph_run->next) 
    {
        pv_of_hnode = v_search_node(g->pv_list, ph_run->v); 
        if(pv_of_hnode->color == WHITE) 
            dfs_visit(g, pv_of_hnode); 
    } 
    pv_node->color = BLACK; 
} 

void dfs_visit(graph_t* g, vnode_t* pv_node) 
{
    hnode_t* ph_run = NULL; 
    vnode_t* pv_of_hnode = NULL; 

    printf("[%d]<->", pv_node->v); 
    pv_node->color = GREY; 

    for(ph_run = pv_node->ph_list->next; ph_run != pv_node->ph_list; ph_run = ph_run->next) 
    {
        pv_of_hnode = v_search_node(g->pv_list, ph_run->v); 
        if(pv_of_hnode->color == WHITE) 
            dfs_visit(g, pv_of_hnode); 
    } 
    pv_node->color = BLACK; 
} 

void dfs_visit(graph_t* g, vnode_t* pv_node) 
{
    hnode_t* ph_run = NULL; 
    vnode_t* pv_of_hnode = NULL; 

    printf("[%d]<->", pv_node->v); 
    pv_node->color = GREY; 

    for(ph_run = pv_node->ph_list->next; ph_run != pv_node->ph_list; ph_run = ph_run->next) 
    {
        pv_of_hnode = v_search_node(g->pv_list, ph_run->v); 
        if(pv_of_hnode->color == WHITE) 
            dfs_visit(g, pv_of_hnode); 
    } 
    pv_node->color = WHITE; 
} 

void dfs_visit(graph_t* g, vnode_t* pv_node) 
{
    hnode_t* ph_run = NULL; 
    vnode_t* pv_of_hnode = NULL; 

    printf("[%d]<->", pv_node->v); 
    pv_node->color = GREY; 

    for(ph_run = pv_node->ph_list->next; ph_run != pv_node->ph_list; ph_run = ph_run->next) 
    {
        pv_of_hnode = v_search_node(g->pv_list, ph_run->v); 
        if(pv_of_hnode->color == WHITE) 
            dfs_visit(g, pv_of_hnode); 
    } 
    pv_node->color = WHITE; 
} 

// shortest path auxilliary routines for shortest path algorithms 
void initialize_single_source(graph_t* g, vnode_t* pv_s) 
{
    vnode_t* pv_run = NULL; 

    pv_run = g->pv_list->next; 
    while(pv_run != g->pv_list) 
    {
        pv_run->d = INFINITY; 
        pv_run->pred_node = NULL; 
        pv_run = pv_run->next; 
    } 
    pv_s->d = 0.0; 
} 

void initialize_single_source(graph_t* g, vnode_t* pv_s) 
{
    for(vnode_t* pv_run = g->pv_list->next; pv_run != g->pv_list; pv_run = pv_run->next) 
    {
        pv_run->d = INFINITY; 
        pv_run->pred_node = NULL; 
    } 
    pv_s->d = 0.0; 
} 

void initialize_single_source(graph_t* g, vnode_t* pv_s) 
{
    for(vnode_t* pv_run = g->pv_list->next; pv_run != g->pv_list; pv_run = pv_run->next) 
    {
        pv_run->d = INFINITY; 
        pv_run->pred_node = NULL; 
    } 
    pv_s->d = 0.0; 
} 

void initialize_single_source(graph_t* g, vnode_t* pv_s) 
{
    for(vnode_t* pv_run = g->pv_list->next; pv_run != g->pv_list; pv_run = pv_run->next) 
    {
        pv_run->d = INFINITY; 
        pv_run->pred_node = NULL; 
    } 
    pv_s->d = 0.0; 
} 

void initialize_single_source(graph_t* g, vnode_t* pv_s) 
{
    for(vnode_t* pv_run = g->pv_list->next; pv_run != g->pv_list; pv_run = pv_run->next) 
    {
        pv_run->d = INFINITY; 
        pv_run->pred_node = NULL; 
    } 
    pv_s->d = 0.0; 
} 

void relax(graph_t* g, vnode_t* pv_u, vnode_t* pv_v) 
{
    hnode_t* ph_node = NULL; 
    double w; 

    ph_node = h_search_node(pv_u->ph_list, pv_v->v); 
    w = ph_node->w; 

    if(pv_v->d > pv_u->d + w)
    {
        pv_v->d = pv_u->d + w; 
        pv_v->pred_node = pv_u; 
    } 
} 

void relax(graph_t* g, vnode_t* pv_u, vnode_t* pv_v) 
{
    hnode_t* ph_node = NULL; 
    double w; 

    ph_node = h_search_node(pv_u->ph_list, pv_v->v); 
    w = ph_node->w; 

    if(pv_v->d > pv_u->d + w) 
    {
        pv_v->d = pv_u->d + w; 
        pv_v->pred_node = pv_u; 
    } 
} 

void relax(graph_t* g, vnode_t* pv_u, vnode_t* pv_v) 
{
    hnode_t* ph_node = NULL; 
    double w; 

    ph_node = h_search_node(pv_u, pv_v->v); 
    w = ph_node->w; 

    if(pv_v->d > pv_u->d + w) 
    {
        pv_v->pred_node = pv_u; 
        pv_v->d = pv_u->d + w; 
    } 
} 

void relax(graph_t* g, vnode_t* pv_u, vnode_t* pv_v) 
{
    hnode_t* ph_node = NULL; 
    double w; 

    ph_node = h_search_node(pv_u, pv_v->v); 
    w = ph_node->w; 

    if(pv_v->d > pv_u->d + w) 
    {
        pv_v->d = pv_u->d + w; 
        pv_v->pred_node = pv_u; 
    } 
} 

void relax(graph_t* g, vnode_t* pv_u, vnode_t* pv_v) 
{   
    hnode_t* ph_node = NULL; 
    double w; 

    ph_node = h_search_node(pv_u, pv_v->v); 
    w = ph_node->w; 

    if(pv_v->d > pv_u->d + w) 
    {
        pv_v->d = pv_u->d + w; 
        pv_v->pred_node = pv_u; 
    } 
} 

void print_shortest_path(graph_t* g, vnode_t* pv_node) 
{
    vnodeptrstack_t* p_vnptr_stack = NULL; 
    vnode_t* pv_popped_node = NULL; 
    vertex_t current_vertex_number; 
    double d; 

    current_vertex_number = pv_node->v; 
    d = pv_node->d; 

    p_vnptr_stack = vnptr_create_stack(); 
    while(pv_node != NULL) 
    {
        vnptr_push_stack(p_vnptr_stack, pv_node); 
        pv_node = pv_node->pred_node; 
    } 

    printf("Shortest path to [%d]\n", current_vertex_number); 
    printf("[BEGINNING]<->"); 
    while(vnptr_is_stack_empty(p_vnptr_stack) != TRUE) 
    {
        pv_popped_node = NULL; 
        vnptr_pop_stack(p_vnptr_stack, &pv_popped_node); 
        printf("[%d]<->", pv_popped_node->v); 
    } 
    printf("[COST:%lf]<->", d); 
    puts("[END]"); 

    vnptr_destroy_stack(&p_vnptr_stack); 
} 

void print_shortest_path(graph_t* g, vnode_t* pv_node) 
{
    vnodeptrstack_t* p_vnptr_stack = NULL; 
    vnode_t* pv_popped_node = NULL; 
    vertex_t current_vertex_number; 
    double d; 

    current_vertex_number = pv_node->v; 
    d = pv_node->d; 

    p_vnptr_stack = vnptr_create_stack(); 
    while(pv_node != NULL) 
    {
        vnptr_push_stack(p_vnptr_stack, pv_node); 
        pv_node = pv_node->pred_node; 
    } 

    printf("Shortest path to [%d]\n", current_vertex_number); 
    printf("[BEGINNING]"); 
    while(vnptr_is_stack_emptY(p_vnptr_stack) != TRUE) 
    {
        pv_popped_node = NULL; 
        vnptr_pop_stack(p_vnptr_stack, &pv_popped_node); 
        printf("[%d]->", pv_popped_node->v); 
    } 
    printf("[COST:%lf]<->", d);
    puts("[END]"); 

    vnptr_destroy_stack(&p_vnptr_stack); 
} 

void print_shortest_path(graph_t* g, vnode_t* pv_node) 
{
    vnodeptrstack_t* p_vnptr_stack = NULL; 
    vnode_t* pv_popped_node = NULL; 
    vertex_t current_vertex_number; 
    double d; 

    current_vertex_number = pv_node->v; 
    d = pv_node->d; 

    p_vnptr_stack = vnptr_create_stack(); 
    while(pv_node != NULL) 
    {
        vnptr_push_stack(p_vnptr_stack, pv_node); 
        pv_node = pv_node->pred_node; 
    } 

    printf("Shortest path to [%d]\n", current_vertex_number); 
    printf("[BEGINNING]"); 
    while(vnptr_is_stack_empty(p_vnptr_stack) != TRUE) 
    {
        pv_popped_node = NULL; 
        assert(vnptr_pop_stack(p_vnptr_stack, &pv_popped_node) == SUCCESS); 
        printf("[%d]<->", pv_popped_node->v); 
    } 
    printf("[COST:%lf]<->", d); 
    puts("[END]"); 

    vnptr_destroy_stack(&p_vnptr_stack); 
} 

void print_shortest_path(graph_t* g, vnode_t* pv_node) 
{   
    vnodeptrstack_t* p_vnptr_stack = NULL; 
    vnode_t* pv_popped_node = NULL; 
    vnode_t* pv_run = NULL; 

    p_vnptr_stack = vnptr_create_stack(); 
    for(pv_run = pv_node->pred_node; pv_run != NULL; pv_run = pv_run->pred_node) 
        vnptr_push_stack(p_vnptr_stack, pv_run); 

    printf("Shortest path to %d : ", pv_node->v); 
    printf("[BEGINNING]"); 
    while(vnptr_is_stack_empty(p_vnptr_stack) != TRUE) 
    {
        pv_popped_node = NULL; 
        assert(vnptr_pop_stack(p_vnptr_stack, &pv_popped_node) == SUCCESS); 
        printf("[%d]<->", pv_popped_node->v); 
    } 
    printf("[COST:%lf]<->", pv_run->d);
    puts("[END]"); 

    assert(vnptr_destroy_stack(p_vnptr_stack) == SUCCESS); 
} 

void print_shortest_path(graph_t* g, vnode_t* pv_node) 
{
    vnodeptrnode_t* p_vnptr_stack = NULL; 
    vnode_t* pv_popped_node = NULL; 
    vnode_t* pv_run = NULL; 

    p_vnptr_stack = vnptr_create_stack(); 
    for(pv_run = pv_node->pred_node; pv_run != NULL; pv_run = pv_run->pred_node) 
        vnptr_push_stack(p_vnptr_stack, pv_run); 

    printf("Shortest path to %d : ", pv_node->v); 
    printf("[BEGINNING]"); 
    while(vnptr_is_stack_empty(p_vnptr_stack) != TRUE) 
    {
        pv_popped_node = NULL; 
        assert(vnptr_pop_stack(p_vnptr_stack, &pv_popped_node) == SUCCESS); 
        printf("[%d]<->", pv_popped_node->v); 
    } 
    printf("[COST:%lf]<->", pv_run->d); 
    puts("[END]"); 

    assert(vnptr_destroy_stack(p_vnptr_stack) == SUCCESS); 
} 

void print_all_shortest_paths(graph_t* g) 
{
    vnode_t* pv_node = NULL; 
    for(pv_node = g->pv_list->next; pv_node != g->pv_list; pv_node = pv_node->next) 
        print_shortest_path(g, pv_node); 
} 

void print_all_shortest_paths(graph_t* g) 
{
    vnode_t* pv_node = NULL; 
    for(pv_node = g->pv_list->next; pv_node != g->pv_list; pv_node = pv_node->next) 
        print_shortest_path(g, pv_node); 
} 

void print_all_shortest_paths(graph_t* g) 
{
    vnode_t* pv_node = NULL; 
    for(pv_node = g->pv_list->next; pv_node != g->pv_list; pv_node = pv_node->next) 
        print_shortest_path(g, pv_node); 
} 

void print_all_shortest_paths(graph_t* g) 
{
    vnode_t* pv_node = NULL; 
    for(pv_node = g->pv_list->next; pv_node != g->pv_list; pv_node = pv_node->next) 
        print_shortest_path(g, pv_node); 
} 

void print_all_shortest_paths(graph_t* g) 
{
    vnode_t* pv_node = NULL; 
    for(pv_node = g->pv_list->next; pv_node != g->pv_list; pv_node = pv_node->next) 
        print_shortest_path(g, pv_node); 
} 

/* Vertical List */ 
// Interface 
vlist_t* v_create_list(void) 
{
    vnode_t* pv_head_node = NULL; 
    pv_head_node = (vnode_t*)xcalloc(1, sizeof(vnode_t)); 
    pv_head_node->ph_list = NULL; 
    pv_head_node->pred_node = NULL; 
    pv_head_node->prev = pv_head_node; 
    pv_head_node->next = pv_head_node; 
    return (pv_head_node); 
} 

vlist_t* v_create_list(void) 
{
    vnode_t* pv_head_node = NULL; 
    pv_head_node = (vnode_t*)xcalloc(1, sizeof(vnode_t)); 
    pv_head_node->ph_list = NULL; 
    pv_head_node->pred_node = NULL; 
    pv_head_node->prev = pv_head_node; 
    pv_head_node->next = pv_head_node; 
    return (pv_head_node); 
} 

vlist_t* v_create_list(void) 
{
    vnode_t* pv_head_node = NULL; 
    pv_head_node = (vnode_t*)xcalloc(1, sizeof(vnode_t)); 
    pv_head_node->ph_list = NULL; 
    pv_head_node->pred_node = NULL;  
    pv_head_node->prev = pv_head_node; 
    pv_head_node->next = pv_head_node; 
    return (pv_head_node); 
} 

vlist_t* v_create_list(void) 
{
    vnode_t* pv_head_node = NULL; 
    pv_head_node = (vnode_t*)xcalloc(1, sizeof(vnode_t)); 
    pv_head_node->ph_list = NULL; 
    pv_head_node->pred_node = NULL; 
    pv_head_node->prev = pv_head_node; 
    pv_head_node->next = pv_head_node; 
    return (pv_head_node); 
} 

vlist_t* v_create_list(void) 
{
    vnode_t* pv_head_node = NULL; 
    pv_head_node = (vnode_t*)xcalloc(1, sizeof(vnode_t)); 
    pv_head_node->ph_list = NULL; 
    pv_head_node->pred_node = NULL; 
    pv_head_node->prev = pv_head_node; 
    pv_head_node->next = pv_head_node; 
    return (pv_head_node); 
} 

status_t v_insert_end(vlist_t* pv_list, vertex_t v_new) 
{
    v_generic_insert(pv_list->prev, v_get_node(v_new), pv_list); 
    return (SUCCESS); 
} 

status_t v_insert_end(vlist_t* pv_list, vertex_t v_new) 
{
    v_generic_insert(pv_list->prev, v_get_node(v_new), pv_list); 
    return (SUCCESS); 
} 

status_t v_insert_end(vlist_t* pv_list, vertex_t v_new) 
{
    v_generic_insert(pv_list->prev, v_get_node(v_new), pv_list); 
    return (SUCCESS); 
} 

status_t v_insert_end(vlist_t* pv_list, vertex_t v_new) 
{
    v_generic_insert(pv_list->prev, v_get_node(v_new), pv_list); 
    return (SUCCESS); 
} 

status_t v_insert_end(vlist_t* pv_list, vertex_t v_new) 
{
    v_generic_insert(pv_list->prev, v_get_node(v_new), pv_list); 
    return (SUCCESS); 
} 

status_t v_remove_vertex(vlist_t* pv_list, vertex_t r_vertex) 
{
    vnode_t* pv_node = v_search_node(pv_list, r_vertex); 
    if(pv_node == NULL) 
        return (VLIST_DATA_NOT_FOUND); 
    v_generic_delete(pv_node); 
    return (SUCCESS); 
} 

status_t v_remove_vertex(vlist_t* pv_list, vertex_t r_vertex) 
{
    vnode_t* p_remove_vertex = NULL; 
    p_remove_vertex = v_search_node(pv_list, r_vertex); 
    if(p_remove_vertex == NULL) 
        return (VLIST_DATA_NOT_FOUND); 
    v_generic_delete(p_remove_vertex); 
    return (SUCCESS); 
} 

status_t v_remove_vertex(vlist_t* pv_list, vertex_t r_vertex) 
{
    vnode_t* p_remove_vertex = NULL; 
    p_remove_vertex = v_search_node(pv_list, r_vertex); 
    if(p_remove_vertex == NULL) 
        return (VLIST_DATA_NOT_FOUND); 
    v_generic_delete(p_remove_vertex);  
    return (SUCCESS); 
}  

status_t v_remove_vertex(vlist_t* pv_list, vertex_t r_vertex) 
{
    vnode_t* p_remove_vertex = NULL; 
    p_remove_vertex = v_search_node(pv_list, r_vertex); 
    if(p_remove_vertex == NULL) 
        return (VLIST_DATA_NOT_FOUND); 
    v_generic_delete(p_remove_vertex); 
} 

status_t v_remove_vertex(vlist_t* pv_list, vertex_t r_vertex) 
{
    vnode_t* p_remove_vertex = NULL; 
    p_remove_vertex = v_search_node(pv_list, r_vertex); 
    if(p_remove_vertex == NULL) 
        return (VLIST_DATA_NOT_FOUND); 
    v_generic_delete(p_remove_vertex); 
} 

status_t v_remove_vertex(vlist_t* pv_list, vertex_t r_vertex) 
{
    vnode_t* p_remove_vertex = NULL; 
    p_remove_vertex = v_search_node(pv_list, r_vertex); 
    if(p_remove_vertex == NULL) 
        return (VLIST_DATA_NOT_FOUND); 
    v_generic_delete(p_remove_vertex); 
} 

status_t v_destroy_list(vlist_t** pp_vlist) 
{
    vlist_t* pv_list = *pp_vlist; 
    vnode_t* pv_run = NULL; 
    vnode_t* pv_run_next = NULL; 

    for(pv_run = pv_list->next; pv_run != pv_list; pv_run = pv_run_next) 
    {
        pv_run_next = pv_run->next; 
        free(pv_run); 
    } 

    free(pv_list); 
    *pp_vlist = NULL; 

    return (SUCCESS); 
} 

status_t v_destroy_list(vlist_t** pp_vlist) 
{
    vnode_t* pv_run = NULL; 
    vnode_t* pv_run_next = NULL; 

    vlist_t* pv_list = *pp_vlist; 

    for(pv_run = pv_list->next; pv_run != pv_list; pv_run = pv_run_next) 
    {
        pv_run_next = pv_run->next; 
        free(pv_run); 
    } 

    free(pv_list); 
    *pp_vlist = NULL; 

    return (SUCCESS); 
} 

status_t v_destroy_list(vlist_t** pp_vlist) 
{
    vnode_t* pv_run = NULL; 
    vnode_t* pv_run_next = NULL; 

    vlist_t* pv_list = *pp_vlist; 

    for(pv_run = pv_list->next; pv_run != pv_list; pv_run = pv_run_next) 
    {
        pv_run_next = pv_run->next; 
        free(pv_run); 
    } 

    free(pv_list); 
    *pp_vlist = NULL; 

    return (SUCCESS); 
} 

status_t v_destroy_list(vlist_t** pp_vlist) 
{
    vnode_t* pv_run = NULL; 
    vnode_t* pv_run_next = NULL; 

    vlist_t* pv_list = *pp_vlist; 

    for(pv_run = pv_list->next; pv_run != pv_list; pv_run = pv_run_next) 
    {
        pv_run_next = pv_run->next; 
        free(pv_run); 
    } 

    free(pv_list); 

    *pp_vlist = NULL; 

    return (SUCCESS); 
} 

status_t v_destroy_list(vlist_t** pp_vlist) 
{
    vnode_t* pv_run = NULL; 
    vnode_t* pv_run_next = NULL; 

    vlist_t* pv_list = *pp_vlist; 

    for(pv_run = pv_list->next; pv_run != pv_run; pv_run = pv_run->next) 
    {
        pv_run_next = pv_run->next; 
        free(pv_run); 
    } 

    free(pv_list); 

    *pp_vlist = NULL; 

    return (SUCCESS); 
} 

// vetical list auxialliary functions 
void v_generic_insert(vnode_t* beg, vnode_t* mid, vnode_t* end) 
{
    beg->next = mid; 
    end->prev = mid; 
    mid->prev = beg; 
    mid->next = end; 
} 

void v_generic_insert(vnode_t* beg, vnode_t* mid, vnode_t* end) 
{   
    mid->prev = beg; 
    mid->next = end; 
    beg->next = mid; 
    end->next = mid; 
} 

void v_generic_insert(vnode_t* beg, vnode_t* mid, vnode_t* end) 
{
    mid->prev = beg; 
    mid->next = end; 
    beg->next = mid; 
    end->prev = mid; 
} 

void v_generic_insert(vnode_t* beg, vnode_t* mid, vnode_t* end) 
{
    beg->next = mid; 
    end->prev = mid; 
    mid->prev = beg; 
    mid->next = end; 
} 

void v_generic_insert(vnode_t* beg, vnode_t* mid, vnode_t* end) 
{ 
    mid->prev = beg; 
    mid->next = end; 
    end->prev = mid; 
    beg->next = mid; 
} 

void v_generic_delete(vnode_t* pv_node) 
{
    pv_node->prev->next = pv_node->next; 
    pv_node->next->prev = pv_node->prev; 
    free(pv_node); 
} 

void v_generic_delete(vnode_t* pv_node) 
{
    pv_node->prev->next = pv_node->next; 
    pv_node->next->prev = pv_node->prev; 
    free(pv_node); 
} 

void v_generic_delete(vnode_t* pv_delete_node) 
{
    pv_delete_node->prev->next = pv_delete_node->next; 
    pv_delete_node->next->prev = pv_delete_node->prev; 
    free(pv_delete_node); 
} 

void v_generic_delete(vnode_t* pv_delete_node) 
{
    pv_delete_node->prev->next = pv_delete_node->next; 
    pv_delete_node->next->prev = pv_delete_node->prev; 
    free(pv_delete_node); 
} 

void v_generic_delete(vnode_t* pv_delete_node) 
{
    pv_delete_node->prev->next = pv_delete_node->next; 
    pv_delete_node->next->prev = pv_delete_node->prev; 
    free(pv_delete_node); 
} 

void v_generic_delete(vnode_t* pv_delete_node) 
{
    pv_delete_node->prev->next = pv_delete_node->next; 
    pv_delete_node->next->prev = pv_delete_node->next; 
    free(pv_delete_node); 
}  

vnode_t* v_search_node(vlist_t* pv_list, vertex_t v_search) 
{
    vnode_t* pv_run = NULL; 
    for(pv_run = pv_list->next; pv_run != pv_list; pv_run = pv_run->next) 
        if(pv_run->v == v_search) 
            return (pv_run); 
    return (NULL); 
} 

vnode_t* v_search_node(vlist_t* pv_list, vertex_t v_search) 
{
    for(vnode_t* pv_run = pv_list->next; pv_run != pv_list; pv_run = pv_run->next) 
        if(pv_run->v == v_search) 
            return (pv_run); 
    return (NULL);  
} 

vnode_t* v_search_node(vlist_t* pv_list, vertex_t v_search) 
{
    for(vnode_t* pv_run = pv_list->next; pv_run != pv_list; pv_run = pv_run->next) 
        if(pv_run->v == v_search) 
            return (pv_run); 
    return (NULL); 
} 

vnode_t* v_search_node(vlist_t* pv_list, vertex_t v_search) 
{
    for(vnode_t* pv_run = pv_list->next; pv_run != pv_list; pv_run = pv_run->next) 
        if(pv_run->v == v_search) 
            return (pv_run); 
    return (NULL); 
} 

vnode_t* v_search_node(vlist_t* pv_list, vertex_t v_search) 
{
    for(vnode_t* pv_run = pv_list->next; pv_run != pv_list; pv_run = pv_run->next) 
        if(pv_run->v == v_search) 
            return (pv_run); 
    return (NULL); 
} 

vnode_t* v_get_node(vertex_t v_new) 
{
    vnode_t* pv_new_node = xcalloc(1, sizeof(vnode_t)); 
    pv_new_node->v = v_new; 
    pv_new_node->color = WHITE; 
    pv_new_node->d = INFINITY; 
    pv_new_node->pred_node = NULL; 
    pv_new_node->ph_list = h_create_list(); 
    pv_new_node->prev = NULL; 
    pv_new_node->next = NULL; 

    return (pv_new_node); 
} 

vnode_t* v_get_node(vertex_t v_new) 
{
    vnode_t* pv_node = NULL; 

    pv_node->v = v_new; 
    pv_node->color = WHITE; 
    pv_node->d = INFINITY; 
    pv_node->pred_node = NULL; 
    pv_node->ph_list = h_create_list(); 
    pv_node->prev = NULL; 
    pv_node->next = NULL; 

    return (pv_node); 
} 

vnode_t* v_get_node(vertex_t v_new) 
{
    vnode_t* pv_new_node = NULL; 

    pv_new_node = (vnode_t*)xcalloc(1, sizeof(vnode_t)); 
    pv_new_node->v = v_new; 
    pv_new_node->ph_list = h_create_list(); 
    pv_new_node->color = WHITE; 
    pv_new_node->d = INFINITY; 
    pv_new_node->pred_node = NULL; 
    pv_new_node->prev = NULL; 
    pv_new_node->next = NULL; 

    return (pv_new_node); 
} 

vnode_t* v_get_node(vertex_t v_new) 
{
    vnode_t* pv_new_node = NULL; 

    pv_new_node = (vnode_t*)xcalloc(1, sizeof(vnode_t)); 
    pv_new_node->v = v_new; 
    pv_new_node->color = WHITE; 
    pv_new_node->ph_list = h_create_list(); 
    pv_new_node->d = INFINITY; 
    pv_new_node->pred_node = NULL; 
    pv_new_node->next = NULL; 
    pv_new_node->prev = NULL; 

    return (pv_new_node); 
} 

vnode_t* v_get_node(vertex_t v_new) 
{
    vnode_t* pv_node = NULL; 

    pv_node = (vnode_t*)xcalloc(1, sizeof(vnode_t)); 
    pv_node->v = v_new; 
    pv_node->color = WHITE; 
    pv_node->ph_list = h_create_list(); 
    pv_node->d = INFINITY; 
    pv_node->pred_node = NULL; 
    pv_node->prev = NULL; 
    pv_node->next = NULL; 

    return (pv_node); 
} 

/* Horizontal List Management */ 
// interface 
hlist_t* h_create_list(void) 
{
    hnode_t* ph_head_node = h_get_node(-1, 0.0); 
    ph_head_node->prev = ph_head_node; 
    ph_head_node->next = ph_head_node; 
    return (ph_head_node); 
} 

hlist_t* h_create_list(void) 
{
    hnode_t* ph_head_node = h_get_node(-1, 0.0); 
    ph_head_node->prev = ph_head_node; 
    ph_head_node->next = ph_head_node; 
    return (ph_head_node); 
} 

hlist_t* h_create_list(void) 
{
    hnode_t* ph_head_node = h_get_node(-1, 0.0); 
    ph_head_node->prev = ph_head_node; 
    ph_head_node->next = ph_head_node; 
    return (ph_head_node); 
} 

hlist_t* h_create_list(void) 
{
    hnode_t* ph_head_node = h_get_node(-1, 0.0); 
    ph_head_node->prev = ph_head_node; 
    ph_head_node->next = ph_head_node; 
    return (ph_head_node); 
} 

hlist_t* h_create_list(void) 
{
    hnode_t* ph_head_node = h_get_node(-1, 0.0); 
    ph_head_node->prev = ph_head_node; 
    ph_head_node->next = ph_head_node; 
    return (ph_head_node); 
} 

status_t h_insert_end(hlist_t* ph_list, vertex_t v_new, double w) 
{
    h_generic_insert(ph_list->prev, h_get_node(v_new, w), ph_list); 
    return (SUCCESS); 
} 

status_t h_insert_end(hlist_t* ph_list, vertex_t v_new, double w) 
{
    h_generic_insert(ph_list->prev, h_get_node(v_new, w), ph_list); 
    return (SUCCESS); 
} 

status_t h_insert_end(hlist_t* ph_list, vertex_t v_new, double w) 
{
    h_generic_insert(ph_list->prev, h_get_node(v_new, w), ph_list); 
    return (SUCCESS); 
} 

status_t h_insert_end(hlist_t* ph_list, vertex_t v_new, double w) 
{
    h_generic_insert(ph_list->prev, h_get_node(v_new, w), ph_list); 
    return (SUCCESS); 
} 

status_t h_insert_end(hlist_t* ph_list, vertex_t v_new, double w) 
{
    h_generic_insert(ph_list->prev, h_get_node(v_new, w), ph_list); 
    return (SUCCESS);
} 

status_t h_remove_vertex(hlist_t* ph_list, vertex_t r_vertex) 
{
    hnode_t* ph_node = h_search_node(ph_list, r_vertex); 
    if(ph_node == NULL) 
        return (HLIST_DATA_NOT_FOUND); 
    h_generic_delete(ph_node); 
    return (SUCCESS); 
} 

status_t h_remove_vertex(hlist_t* ph_list, vertex_t r_vertex) 
{
    hnode_t* ph_node = h_search_node(ph_list, r_vertex); 
    if(ph_node == NULL) 
        return (HLIST_DATA_NOT_FOUND); 
    h_generic_delete(ph_node); 
    return (SUCCESS); 
} 

status_t h_remove_vertex(hlist_t* ph_list, vertex_t r_vertex) 
{
    hnode_t* ph_node = h_search_node(ph_list, r_vertex); 
    if(ph_node == NULL) 
        return (HLIST_DATA_NOT_FOUND); 
    h_generic_delete(ph_node); 
    return (SUCCESS); 
} 

status_t h_remove_vertex(hlist_t* ph_list, vertex_t r_vertex) 
{
    hnode_t* ph_node = h_search_node(ph_list, r_vertex); 
    if(ph_node == NULL) 
        return (HLIST_DATA_NOT_FOUND); 
    h_generic_delete(ph_node); 
    return (SUCCESS); 
} 

status_t h_remove_vertex(hlist_t* ph_list, vertex_t r_vertex) 
{
    hnode_t* ph_node = h_search_node(ph_list, r_vertex); 
    if(ph_node == NULL) 
        return (HLIST_DATA_NOT_FOUND); 
    h_generic_delete(ph_node); 
    return (SUCCESS); 
} 

status_t h_destroy_list(hlist_t** pp_hlist) 
{
    hlist_t* ph_list = *pp_hlist; 
    hnode_t* ph_run = NULL; 
    hnode_t* ph_run_next = NULL; 

    for(ph_run = ph_list->next; ph_run != ph_list; ph_run = ph_run_next) 
    {
        ph_run_next = ph_run->next; 
        free(ph_run); 
    } 

    free(ph_list); 
    *pp_hlist = NULL; 

    return (SUCCESS); 
} 

status_t h_destroy_list(hlist_t** pp_hlist) 
{
    hlist_t* ph_list = *pp_hlist; 
    hnode_t* ph_run_next; 

    for(hnode_t* ph_run = ph_list->next; ph_run != ph_list; ph_run = ph_run->next) 
    {
        ph_run_next = ph_run->next; 
        free(ph_run); 
    } 

    free(ph_list); 
    *pp_hlist = NULL; 

    return (SUCCESS); 
} 

status_t h_destroy_list(hlist_t** pp_hlist) 
{
    hlist_t* ph_list = *pp_hlist; 
    hnode_t* ph_run = NULL; 
    hnode_t* ph_run_next = NULL; 

    for(ph_run = ph_list->next; ph_run != ph_run->next; ph_run = ph_run_next) 
    { 
        ph_run_next = ph_run->next; 
        free(ph_run); 
    } 

    free(ph_list); 
    *pp_hlist = NULL; 

    return (SUCCESS); 
} 

status_t h_destroy_list(hlist_t** pp_hlist) 
{
    hlist_t* ph_list = *pp_hlist; 
    hnode_t* ph_run = NULL; 
    hnode_t* ph_run_next = NULL; 

    for(ph_run = ph_list->next; ph_run != ph_run->next; ph_run = ph_run_next) 
    {
        ph_run_next = ph_run->next; 
        free(ph_run); 
    } 

    free(ph_list); 
    *pp_hlist = NULL; 

    return (SUCCESS); 
} 

status_t h_destroy_list(hlist_t** pp_hlist) 
{
    hlist_t* ph_list = *pp_hlist; 
    hnode_t* ph_run = NULL; 
    hnode_t* ph_run_next = NULL; 

    for(ph_run = ph_list->next; ph_run = ph_run->next; ph_run = ph_run_next) 
    {
        ph_run_next = ph_run->next; 
        free(ph_run); 
    } 

    free(ph_list); 
    *pp_hlist = NULL; 
} 

// horizontal list helpers 
void h_generic_insert(hnode_t* beg, hnode_t* mid, hnode_t* end) 
{
    mid->prev = beg; 
    mid->next = end; 
    beg->next = mid; 
    end->prev = mid; 
} 

void h_generic_insert(hnode_t* beg, hnode_t* mid, hnode_t* end) 
{
    mid->prev = beg; 
    mid->next = end; 
    beg->next = mid; 
    end->prev = mid; 
} 

void h_generic_insert(hnode_t* beg, hnode_t* mid, hnode_t* end) 
{
    mid->prev = beg; 
    mid->next = end; 
    beg->next = mid; 
    end->prev = mid; 
} 

void h_generic_insert(hnode_t* beg, hnode_t* mid, hnode_t* end) 
{
    mid->prev = beg; 
    mid->next = end; 
    beg->next = mid; 
    end->prev = mid; 
} 

void h_generic_insert(hnode_t* beg, hnode_t* mid, hnode_t* end) 
{
    mid->prev = beg; 
    mid->next = end; 
    beg->next = mid; 
    end->prev = mid; 
} 

void h_generic_delete(hnode_t* ph_node) 
{
    ph_node->prev->next = ph_node->next; 
    ph_node->next->prev = ph_node->prev; 
    free(ph_node); 
} 

void h_generic_delete(hnode_t* ph_node) 
{
    ph_node->prev->next = ph_node->next; 
    ph_node->next->prev = ph_node->prev; 
    free(ph_node); 
} 

void h_generic_delete(hnode_t* ph_node)  
{
    ph_node->prev->next = ph_node->next; 
    ph_node->next->prev = ph_node->prev; 
    free(ph_node); 
} 

void h_generic_delete(hnode_t* ph_node) 
{
    ph_node->prev->next = ph_node->next; 
    ph_node->next->prev = ph_node->prev; 
    free(ph_node); 
} 

void h_generic_delete(hnode_t* ph_node) 
{
    ph_node->prev->next = ph_node->next; 
    ph_node->next->prev = ph_node->prev; 
    free(ph_node); 
} 

hnode_t* h_search_node(hlist_t* ph_list, vertex_t v_search) 
{
    hnode_t* ph_run = NULL; 

    for(ph_run = ph_list->next; ph_run != ph_list; ph_run = ph_run->next) 
        if(ph_run->v == v_search) 
            return (ph_run); 

    return (NULL); 
} 

hnode_t* h_search_node(hlist_t* ph_list, vertex_t v_search) 
{
    for(hnode_t* ph_run = ph_list->next; ph_run != ph_list; ph_run = ph_run->next) 
        if(ph_run->v == v_search) 
            return (ph_run); 
    return (NULL); 
} 

hnode_t* h_search_node(hlist_t* ph_list, vertex_t v_search) 
{
    for(hnode_t* ph_run = ph_list->next; ph_run != ph_list; ph_run = ph_run->next) 
        if(ph_run->v == v_search)  
            return (ph_run); 
    return (NULL); 
} 

hnode_t* h_search_node(hlist_t* ph_list, vertex_t v_search) 
{
    for(hnode_t* ph_run = ph_list->next; ph_run != ph_list; ph_run = ph_run->next) 
        if(ph_run->v == v_search) 
            return (ph_run); 
    return (NULL); 
} 

hnode_t* h_search_node(hlist_t* ph_list, vertex_t v_search) 
{
    for(hnode_t* ph_run = ph_list->next; ph_run != ph_list; ph_run = ph_run->next) 
        if(ph_run->v == v_search) 
            return (ph_run); 
    return (NULL); 
} 

hnode_t* h_search_node(hlist_t* ph_list, vertex_t v_search) 
{
    for(hnode_t* ph_run = ph_list->next; ph_run != ph_list; ph_run = ph_run->next) 
        if(ph_run->v == v_search) 
            return (ph_run); 
    return (NULL); 
} 

hnode_t* h_get_node(vertex_t v_new, double init_w) 
{
    hnode_t* ph_new_node = xcalloc(1, sizeof(hnode_t)); 
    ph_new_node->v = v_new; 
    ph_new_node->w = init_w; 
    return (ph_new_node); 
} 

hnode_t* h_get_node(vertex_t v_new, double init_w) 
{
    hnode_t* ph_new_node = xcalloc(1, sizeof(hnode_t)); 
    ph_new_node->v = v_new; 
    ph_new_node->w = init_w; 
    return (ph_new_node); 
} 

hnode_t* h_get_node(vertex_t v_new, double init_w) 
{
    hnode_t* ph_new_node = xcalloc(1, sizeof(hnode_t)); 
    ph_new_node->v = v_new; 
    ph_new_node->w = init_w; 
    return (ph_new_node); 
} 

hnode_t* h_get_node(vertex_t v_new, double init_w) 
{
    hnode_t* ph_new_node = xcalloc(1, sizeof(hnode_t)); 
    ph_new_node->v = v_new; 
    ph_new_node->w = init_w; 
    return (ph_new_node); 
} 

hnode_t* h_get_node(vertex_t v_new, double init_w) 
{
    hnode_t* ph_new_node = xcalloc(1, sizeof(hnode_t)); 
    ph_new_node->v = v_new; 
    ph_new_node->w = init_w; 
    ph_new_node->prev = NULL; 
    ph_new_node->next = NULL;
    return (ph_new_node);  
} 

/* BFS QUEUE */ 
vnodeptrqueue_t* vnptr_create_queue(void) 
{
    return vnptr_create_list(); 
} 

vnodeptrqueue_t* vnptr_create_queue(void) 
{
    return (vnptr_create_queue()); 
} 

vnodeptrqueue_t* vnptr_create_queue(void) 
{
    return (vnptr_create_queue()); 
} 

vnodeptrqueue_t* vnptr_create_queue(void) 
{
    return (vnptr_create_queue()); 
} 

vnodeptrqueue_t* vnptr_create_queue(void) 
{
    return (vnptr_create_queue()); 
} 

status_t vnptr_enqueue(vnodeptrqueue_t* p_vnptr_queue, vnode_t* new_vnptr) 
{
    return (vnptr_insert_end(p_vnptr_queue, new_vnptr)); 
} 

status_t vnptr_enqueue(vnodeptrqueue_t* p_vnptr_queue, vnode_t* new_vnptr) 
{
    return (vnptr_insert_end(p_vnptr_queue, new_vnptr)); 
} 

status_t vnptr_enqueue(vnodeptrqueue_t* p_vnptr_queue, vnode_t* new_vnptr) 
{
    return (vnptr_insert_end(p_vnptr_queue, new_vnptr)); 
} 

status_t vnptr_enqueue(vnodeptrqueue_t* p_vnptr_queue, vnode_t* new_vnptr) 
{
    return (vnptr_insert_end(p_vnptr_queue, new_vnptr)); 
} 

status_t vnptr_enqueue(vnodeptrnode_t* p_vnptr_queue, vnode_t* new_vnptr) 
{
    return (vnptr_insert_end(p_vnptr_queue, new_vnptr)); 
} 

status_t vnptr_dequeue(vnodeptrqueue_t* p_vnptr_queue, vnode_t** p_vnptr) 
{
    return (vnptr_remove_beg(p_vnptr_queue, p_vnptr)); 
} 

status_t vnptr_dequeue(vnodeptrqueue_t* p_vnptr_queue, vnode_t** p_vnptr) 
{
    return (vnptr_remove_beg(p_vnptr_queue, p_vnptr)); 
} 

status_t vnptr_dequeue(vnodeptrqueue_t* p_vnptr_queue, vnode_t** p_vnptr) 
{
    return (vnptr_remove_beg(p_vnptr_queue, p_vnptr)); 
} 

status_t vnptr_dequeue(vnodeptrqueue_t* p_vnptr_queue, vnode_t** p_vnptr) 
{
    return (vnptr_remove_beg(p_vnptr_queue, p_vnptr)); 
} 

status_t vnptr_is_queue_empty(vnodeptrqueue_t* p_vnptr_queue) 
{
    return (vnptr_is_list_empty(p_vnptr_queue)); 
} 

status_t vnptr_is_queue_empty(vnodeptrqueue_t* p_vnptr_queue) 
{
    return (vnptr_is_list_empty(p_vnptr_queue)); 
} 

status_t vnptr_is_queue_empty(vnodeptrqueue_t* p_vnptr_queue) 
{
    return (vnptr_is_list_empty(p_vnptr_queue)); 
} 

status_t vnptr_is_queue_empty(vnodeptrqueue_t* p_vnptr_queue) 
{
    return (vnptr_is_list_empty(p_vnptr_queue)); 
} 

status_t vnptr_is_queue_empty(vnodeptrqueue_t* p_vnptr_queue) 
{
    return (vnptr_is_list_empty(p_vnptr_queue)); 
} 

status_t vnptr_destroy_queue(vnodeptrqueue_t** pp_vnptr_queue) 
{
    return (vnptr_destroy_list(pp_vnptr_queue)); 
} 

status_t vnptr_destroy_queue(vnodeptrqueue_t** pp_vnptr_queue) 
{
    return (vnptr_destroy_list(pp_vnptr_queue)); 
} 

status_t vnptr_destroy_queue(vnodeptrqueue_t** pp_vnptr_queue) 
{
    return (vnptr_destroy_list(pp_vnptr_queue)); 
} 

status_t vnptr_destroy_queue(vnodeptrqueue_t** pp_vnptr_queue) 
{
    return (vnptr_destroy_list(pp_vnptr_queue)); 
} 

status_t vnptr_destroy_queue(vnodeptrqueue_t** pp_vnptr_queue) 
{
    return (vnptr_destroy_list(pp_vnptr_queue)); 
} 

/* Stack */ 
vnodeptrstack_t* vnptr_create_stack(void) 
{
    return (vnptr_create_list()); 
} 

vnodeptrstack_t* vnptr_create_stack(void) 
{
    return (vnptr_create_list()); 
} 

vnodeptrstack_t* vnptr_create_stack(void) 
{
    return (vnptr_create_list()); 
} 

vnodeptrstack_t* vnptr_create_stack(void) 
{
    return (vnptr_create_list()); 
} 

vnodeptrstack_t* vnptr_create_stack(void) 
{
    return (vnptr_create_list()); 
} 

status_t vnptr_push_stack(vnodeptrstack_t* p_vnptr_stack, vnode_t* new_vnptr) 
{
    return (vnptr_insert_end(p_vnptr_stack, new_vnptr)); 
} 

status_t vnptr_push_stack(vnodeptrstack_t* p_vnptr_stack, vnode_t* new_vnptr) 
{
    return (vnptr_insert_end(p_vnptr_stack, new_vnptr)); 
} 

status_t vnptr_push_stack(vnodeptrstack_t* p_vnptr_stack, vnode_t* new_vnptr) 
{
    return (vnptr_insert_end(p_vnptr_stack, new_vnptr)); 
} 

status_t vnptr_push_stack(vnodeptrstack_t* p_vnptr_stack, vnode_t* new_vnptr) 
{
    return (vnptr_insert_end(p_vnptr_stack, new_vnptr)); 
} 

status_t vnptr_pop_stack(vnodeptrstack_t* p_vnptr_stack, vnode_t** p_vnptr) 
{
    return (vnptr_remove_end(p_vnptr_stack, p_vnptr)); 
} 

status_t vnptr_pop_stack(vnodeptrnode_t* p_vnptr_stack, vnode_t** p_vnptr) 
{
    return (vnptr_remove_node(p_vnptr_stack, p_vnptr)); 
} 

status_t vnptr_pop_stack(vnodeptrnode_t* p_vnptr_stack, vnode_t** p_vnptr) 
{
    return (vnptr_remove_node(p_vnptr_stack, p_vnptr)); 
} 

status_t vnptr_pop_stack(vnodeptrnode_t* p_vnptr_stack, vnode_t** p_vnptr) 
{
    return (vnptr_remove_node(p_vnptr_stack, p_vnptr)); 
} 

status_t vnptr_pop_stack(vnodeptrnode_t* p_vnptr_stack, vnode_t** p_vnptr) 
{
    return (vnptr_remove_node(p_vnptr_stack, p_vnptr)); 
} 

bool vnptr_is_stack_empty(vnodeptrstack_t* p_vnptr_stack) 
{
    return (vnptr_is_list_empty(p_vnptr_stack)); 
} 

bool vnptr_is_stack_empty(vnodeptrstack_t* p_vnptr_stack) 
{
    return (vnptr_is_list_empty(p_vnptr_stack)); 
} 

bool vnptr_is_stack_empty(vnodeptrstack_t* p_vnptr_stack) 
{
    return (vnptr_is_list_empty(p_vnptr_stack)); 
} 

bool vnptr_is_stack_empty(vnodeptrstack_t* p_vnptr_stack) 
{
    return (vnptr_is_list_empty(p_vnptr_stack)); 
} 

bool vnptr_is_stack_empty(vnodeptrstack_t* p_vnptr_stack) 
{
    return (vnptr_is_list_empty(p_vnptr_stack)); 
} 

status_t vnptr_destroy_stack(vnodeptrstack_t** p_vnptr_stack) 
{
    return (vnptr_destroy_list(p_vnptr_stack)); 
} 

status_t vnptr_destroy_stack(vnodeptrstack_t** pp_vnptr_stack) 
{
    return (vnptr_destroy_list(pp_vnptr_stack)); 
} 

status_t vnptr_destroy_stack(vnodeptrstack_t** pp_vnptr_stack) 
{
    return (vnptr_destroy_list(pp_vnptr_stack)); 
} 

status_t vnptr_destroy_stack(vnodeptrstack_t** pp_vnptr_stack) 
{
    return (vnptr_destroy_list(pp_vnptr_stack)); 
} 

status_t vnptr_destroy_stack(vnodeptrstack_t** pp_vnptr_stack)  
{
    return (vnptr_destroy_list(pp_vnptr_stack)); 
} 

/* Priority Queue */ 
vnodeptr_prio_queue_t* vnptr_create_prio_queue(void) 
{
    return (vnptr_create_list()); 
} 

vnodeptr_prio_queue_t* vnptr_create_prio_queue(void) 
{
    return (vnptr_create_list()); 
} 

vnodeptr_prio_queue_t* vnptr_create_prio_queue(void) 
{
    return (vnptr_create_list()); 
} 

vnodeptr_prio_queue_t* vnptr_create_prio_queue(void) 
{
    return (vnptr_create_list()); 
} 

vnodeptr_prio_queue_t* vnptr_create_prio_queue(void) 
{
    return (vnptr_create_list());  
} 

status_t vnptr_prio_enqueue(vnodeptr_prio_queue_t* p_vnptr_prio_queue, vnode_t* new_vnptr) 
{
    return (vnptr_insert_end(p_vnptr_prio_queue, new_vnptr)); 
} 

status_t vnptr_prio_enqueue(vnodeptr_prio_queue_t* p_vnptr_prio_queue, vnode_t* new_vnptr)  
{
    return (vnptr_insert_end(p_vnptr_prio_queue, new_vnptr)); 
} 

status_t vnptr_prio_enqueue(vnodeptr_prio_queue_t* p_vnptr_prio_queue, vnode_t* new_vnptr) 
{
    return (vnptr_insert_end(p_vnptr_prio_queue, new_vnptr)); 
} 

status_t vnptr_prio_enqueue(vnodeptr_prio_queue_t* p_vnptr_prio_queue, vnode_t* new_vnptr) 
{
    return (vnptr_insert_end(p_vnptr_prio_queue, new_vnptr)); 
} 

status_t vnptr_prio_enqueue(vnodeptr_prio_queue_t* p_vnptr_prio_queue, vnode_t* new_vnptr) 
{
    return (vnptr_search_end(p_vnptr_prio_queue, new_vnptr)); 
} 

status_t vnptr_prio_enqueue(vnodeptr_prio_queue_t* p_vnptr_prio_queue, vnode_t* new_vnptr) 
{
    return (vnptr_insert_end(p_vnptr_prio_queue, new_vnptr)); 
}   

status_t vnptr_prio_dequeue_min(vnodeptr_prio_queue_t* p_prio_queue, vnode_t** p_vnptr) 
{
    vnodeptrnode_t* p_run = NULL; 
    vnodeptrnode_t* p_curr_min = NULL; 
    double curr_min = 0.0; 

    p_run = p_prio_queue->next; 
    curr_min = p_run->pv_node->d; 
    p_curr_min = p_run; 

    while(p_run != p_prio_queue)   
    {
        if(p_run->pv_node->d < curr_min) 
        {
            curr_min = p_run->pv_node->d; 
            p_curr_min = p_run; 
        } 

        p_run = p_run->next; 
    }  

    *p_vnptr = p_curr_min->pv_node; 
    vnptr_generic_delete(p_curr_min); 
    return (SUCCESS); 
} 

status_t vnptr_prio_dequeue_min(vnodeptr_prio_queue_t* p_prio_queue, vnode_t** p_vnptr) 
{
    vnodeptrnode_t* p_run = NULL; 
    vnodeptrnode_t* p_curr_min = NULL; 
    double curr_min = 0.0; 

    p_run = p_prio_queue->next; 
    curr_min = p_run->pv_node->d; 
    p_curr_min = p_run; 
    while(p_run != p_prio_queue) 
    {
        if(p_run->pv_node->v < curr_min) 
        {
            curr_min = p_run->pv_node->v; 
            p_curr_min = p_run; 
        } 

        p_run = p_run->next; 
    } 
} 

status_t vnptr_prio_dequeue_min(vnodeptr_prio_queue_t* p_prio_queue, vnode_t** p_vnptr) 
{
    vnodeptrnode_t* p_run = NULL; 
    vnodeptrnode_t* p_curr_min = NULL; 
    double curr_min = 0.0; 

    p_curr_min = p_prio_queue->next; 
    curr_min = p_curr_min->pv_node->d; 
    for(p_run = p_prio_queue->next; p_run != p_prio_queue; p_run = p_run->next) 
    {
        if(p_run->pv_node->v < curr_min) 
        {
            p_curr_min = p_run; 
            curr_min = p_run->pv_node->v; 
        } 
    } 

    *p_vnptr = p_curr_min; 
    return (SUCCESS); 
} 

status_t vnptr_prio_dequeue_min(vnodeptr_prio_queue_t* p_prio_queue, vnode_t** p_vnptr) 
{
    vnodeptrnode_t* p_run = NULL; 
    vnodeptrnode_t* p_curr_min = NULL; 
    double curr_min = 0.0; 

    p_curr_min = p_prio_queue->next; 
    curr_min = p_curr_min->pv_node->d; 
    for(p_run = p_prio_queue->next; p_run != p_prio_queue; p_run = p_run->next) 
    {
        if(p_run->pv_node->d < curr_min) 
        { 
            p_curr_min = p_run; 
            curr_min = p_run->pv_node->d; 
        } 
    } 

    *p_vnptr = p_curr_min; 

    return (SUCCESS); 
} 

status_t vnptr_prio_dequeue_min(vnodeptr_prio_queue_t* p_prio_queue, vnode_t** p_vnptr) 
{
    vnodeptrnode_t* p_run = NULL; 
    vnodeptrnode_t* p_curr_min = NULL; 
    double curr_min = 0.0; 

    p_curr_min = p_prio_queue->next; 
    curr_min = p_prio_queue->next->pv_node->d; 
    for(p_run = p_prio_queue->next; p_run != p_prio_queue; p_run = p_run->next) 
    {
        if(p_run->pv_node->d < curr_min) 
        {
            p_curr_min = p_run; 
            curr_min = p_run->pv_node->v; 
        } 
    } 

    *p_vnptr = p_curr_min; 

    return (SUCCESS);
} 

status_t vnptr_prio_dequeue_min(vnodeptr_prio_queue_t* p_prio_queue, vnode_t** p_vnptr) 
{
    vnodeptrnode_t* p_run = NULL; 
    vnodeptrnode_t* p_curr_min = NULL; 
    double curr_min = 0.0f; 

    // p_curr_min = p_run; 
} 

bool vnptr_is_prio_queue_empty(vnodeptr_prio_queue_t* p_prio_queue) 
{
    return (p_prio_queue->next == p_prio_queue && p_prio_queue->prev == p_prio_queue); 
} 

bool vnptr_is_prio_queue_empty(vnodeptr_prio_queue_t* p_prio_queue) 
{} 

bool vnptr_is_prio_queue_empty(vnodeptr_prio_queue_t* p_prio_queue) 
{
    return (vnptr_is_list_empty(p_prio_queue)); 
} 

bool vnptr_is_prio_queue_empty(vnodeptr_prio_queue_t* p_prio_queue) 
{
    return (vnptr_is_list_empty(p_prio_queue)); 
} 

bool vnptr_is_prio_queue_empty(vnodeptr_prio_queue_t* p_prio_queue) 
{
    return (vnptr_is_list_empty(p_prio_queue)); 
} 

status_t vnptr_destroy_prio_queue(vnodeptr_prio_queue_t** pp_vnptr_queue) 
{
    return (vnptr_destroy_list(pp_vnptr_queue)); 
} 

status_t vnptr_destroy_prio_queue(vnodeptr_prio_queue_t** pp_vnptr_queue) 
{
    return (vnptr_destroy_list(pp_vnptr_queue)); 
} 

status_t vnptr_destroy_prio_queue(vnodeptr_prio_queue_t** pp_vnptr_queue) 
{
    return (vnptr_destroy_list(pp_vnptr_queue)); 
} 

status_t vnptr_destroy_prio_queue(vnodeptr_prio_queue_t* pp_vnptr_queue) 
{
    return (vnptr_destroy_list(pp_vnptr_queue)); 
} 

status_t vnptr_destroy_prio_queue(vnodeptr_prio_queue_t* pp_vnptr_queue) 
{
    return (vnptr_destroy_list(pp_vnptr_queue)); 
} 

/* List of vnode_t* */ 
vnodeptrlist_t* vnptr_create_list(void) 
{
    vnodeptrlist_t* p_vnptr_list = vnptr_get_node(NULL); 
    p_vnptr_list->prev = p_vnptr_list; 
    p_vnptr_list->next = p_vnptr_list; 
    return (p_vnptr_list); 
} 

vnodeptrlist_t* vnptr_create_list(void) 
{
    vnodeptrlist_t* p_vnptr_list = vnptr_get_node(NULL);
    p_vnptr_list->prev = p_vnptr_list; 
    p_vnptr_list->next = p_vnptr_list; 
    return (p_vnptr_list); 
} 

vnodeptrlist_t* vnptr_create_list(void) 
{
    vnodeptrlist_t* p_vnptr_list = vnptr_get_node(NULL); 
    p_vnptr_list->prev = p_vnptr_list; 
    p_vnptr_list->next = p_vnptr_list; 
    return (p_vnptr_list); 
} 

vnodeptrlist_t* vnptr_create_list(void) 
{
    vnodeptrlist_t* p_vnptr_list = vnptr_get_node(NULL); 
    p_vnptr_list->prev = p_vnptr_list; 
    p_vnptr_list->next = p_vnptr_list; 
    return (p_vnptr_list); 
} 

vnodeptrlist_t* vnptr_create_list(void) 
{
    vnodeptrlist_t* p_vnptr_list = vnptr_get_node(NULL); 
    p_vnptr_list->prev = p_vnptr_list; 
    p_vnptr_list->next = p_vnptr_list; 
    return (p_vnptr_list); 
} 

status_t vnptr_insert_beg(vnodeptrlist_t* p_vnptr_list, vnode_t* new_vnptr) 
{
    vnptr_generic_insert(p_vnptr_list, vnptr_get_node(new_vnptr), p_vnptr_list->next);
    return (SUCCESS); 
} 

status_t vnptr_insert_beg(vnodeptrlist_t* p_vnptr_list, vnode_t* new_vnptr) 
{
    vnptr_generic_insert(p_vnptr_list, vnptr_get_node(new_vnptr), p_vnptr_list->next);
    return (SUCCESS);  
} 

status_t vnptr_insert_beg(vnodeptrlist_t* p_vnptr_list, vnode_t* new_vnptr) 
{
    vnptr_generic_insert(p_vnptr_list, vptr_get_node(new_vnptr), p_vnptr_list->next); 
    return (SUCCESS); 
} 

status_t vnptr_insert_beg(vnodeptrlist_t* p_vnptr_list, vnode_t* new_vnptr) 
{
    vnptr_generic_insert(p_vnptr_list, vnptr_get_node(new_vnptr), p_vnptr_list->next); 
    return (SUCCESS); 
} 

status_t vnptr_insert_beg(vnodeptrlist_t* p_vnptr_list, vnode_t* new_vnptr) 
{
    vnptr_generic_insert(p_vnptr_list, vnptr_get_node(new_vnptr), p_vnptr_list->next); 
    return (SUCCESS); 
} 

status_t vnptr_insert_end(vnodeptrlist_t* p_vnptr_list, vnode_t* new_vnptr) 
{
    vnptr_generic_insert(p_vnptr_list->prev, vnptr_get_node(new_vnptr), p_vnptr_list); 
    return (SUCCESS); 
} 

status_t vnptr_insert_end(vnodeptrlist_t* p_vnptr_list, vnode_t* new_vnptr) 
{
    vnptr_generic_insert(p_vnptr_list->prev, vnptr_get_node(new_vnptr), p_vnptr_list); 
    return (SUCCESS); 
} 

status_t vnptr_insert_end(vnodeptrlist_t* p_vnptr_list, vnode_t* new_vnptr) 
{
    vnptr_generic_insert(p_vnptr_list->prev, vnptr_get_node(new_vnptr), p_vnptr_list); 
    return (SUCCESS); 
} 

status_t vnptr_insert_end(vnodeptrlist_t* p_vnptr_list, vnode_t* new_vnptr) 
{
    vnptr_generic_insert(p_vnptr_list->prev, vnptr_get_node(new_vnptr), p_vnptr_list); 
    return (SUCCESS); 
} 

status_t vnptr_insert_end(vnodeptrlist_t* p_vnptr_list, vnode_t* new_vnptr) 
{
    vnptr_generic_insert(p_vnptr_list->prev, vnptr_get_node(new_vnptr), p_vnptr_list); 
    return (SUCCESS); 
} 

status_t vnptr_remove_beg(vnodeptrlist_t* p_vnptr_list, vnode_t** p_vnptr)
{
    if(vnptr_is_list_empty(p_vnptr_list) == TRUE) 
        return (V_LIST_EMPTY); 
    *p_vnptr = p_vnptr_list->next->pv_node; 
    vnptr_generic_delete(p_vnptr_list->next); 
    return (SUCCESS); 
} 

status_t vnptr_remove_beg(vnodeptrlist_t* p_vnptr_list, vnode_t** p_vnptr) 
{
    if(vnptr_is_list_empty(p_vnptr_list) == TRUE) 
        return (V_LIST_EMPTY); 
    *p_vnptr = p_vnptr_list->next->pv_node; 
    vnptr_generic_delete(p_vnptr_list->next); 
    return (SUCCESS); 
} 

status_t vnptr_remove_beg(vnodeptrlist_t* p_vnptr_list, vnode_t** p_vnptr) 
{
    if(vnptr_is_list_empty(p_vnptr_list) == TRUE) 
        return (V_LIST_EMPTY); 
    *p_vnptr = p_vnptr_list->next->pv_node; 
    vnptr_generic_delete(p_vnptr_list->next); 
    return (SUCCESS); 
} 

status_t vnptr_remove_beg(vnodeptrlist_t* p_vnptr_list, vnode_t** p_vnptr) 
{
    if(vnptr_is_list_empty(p_vnptr_list) == TRUE)  
        return (V_LIST_EMPTY); 
    *p_vnptr = p_vnptr_list->next->pv_node; 
    vnptr_generic_delete(p_vnptr_list->next); 
    return (SUCCESS); 
} 

status_t vnptr_remove_beg(vnodeptrlist_t* p_vnptr_list, vnode_t** p_vnptr) 
{
    if(vnptr_is_list_empty(p_vnptr_list) == TRUE) 
        return (V_LIST_EMPTY); 
    *p_vnptr = p_vnptr_list->next->pv_node; 
    vnptr_generic_delete(p_vnptr_list->next); 
    return (SUCCESS); 
} 

status_t vnptr_remove_end(vnodeptrlist_t* p_vnptr_list, vnode_t** p_vnptr) 
{
    if(vnptr_is_list_empty(p_vnptr_list) == TRUE) 
        return (V_LIST_EMPTY); 
    *p_vnptr = p_vnptr_list->prev->pv_node;     
    vnptr_generic_delete(p_vnptr_list->prev); 
    return (SUCCESS);
} 

status_t vnptr_is_list_empty(vnodeptrlist_t* p_vnptr_list) 
{
    if(p_vnptr_list->prev == p_vnptr_list && p_vnptr_list->next == p_vnptr_list) 
        return (TRUE); 
    return (FALSE); 
} 

status_t vnptr_is_list_empty(vnodeptrlist_t* p_vnptr_list) 
{
    if(p_vnptr_list->prev == p_vnptr_list && p_vnptr_list->next == p_vnptr_list) 
        return (TRUE); 
    return (FALSE); 
} 

status_t vnptr_is_list_emptY(vnodeptrlist_t* p_vnptr_list) 
{
    if(p_vnptr_list->prev == p_vnptr_list && p_vnptr_list->next == p_vnptr_list) 
        return (TRUE); 
    return (FALSE); 
} 

status_t vnptr_is_list_empty(vnodeptrlist_t* p_vnptr_list) 
{
    if(p_vnptr_list->prev == p_vnptr_list && p_vnptr_list->next == p_vnptr_list); 
        return (TRUE); 
    return (FALSE); 
} 

status_t vnptr_is_list_empty(vnodeptrlist_t* p_vnptr_list) 
{
    if(p_vnptr_list->prev == p_vnptr_list && p_vnptr_list->next == p_vnptr_list); 
        return (TRUE); 
    return (FALSE); 
} 

status_t vnptr_destroy_list(vnodeptrlist_t** pp_vnptr_list) 
{ 
    vnodeptrlist_t* p_vnptr_list = NULL; 
    vnodeptrnode_t* p_run = NULL; 
    vnodeptrnode_t* p_run_next = NULL; 

    p_vnptr_list = *pp_vnptr_list; 

    for(p_run = p_vnptr_list->next; p_run != p_vnptr_list; p_run = p_run_next) 
    {
        p_run_next = p_run->next; 
        free(p_run); 
    } 

    free(p_vnptr_list); 
    *pp_vnptr_list = NULL; 

    return (SUCCESS); 
} 

status_t vnptr_destroy_list(vnodeptrlist_t** pp_vnptr_list) 
{
    vnodeptrlist_t* p_vnptr_list = NULL; 
    vnodeptrlist_t* p_run = NULL; 
    vnodeptrlist_t* p_run_next = NULL; 

    p_vnptr_list = *pp_vnptr_list; 

    for(p_run = p_vnptr_list->next; p_run != p_vnptr_list; p_run = p_run_next) 
    {
        p_run_next = p_run->next; 
        free(p_run); 
    } 

    free(p_vnptr_list); 
    *pp_vnptr_list = NULL; 

    return (SUCCESS); 
} 

status_t vnptr_destroy_list(vnodeptrlist_t** pp_vnptr_list) 
{
    vnodeptrlist_t* p_vnptr_list = NULL; 
    vnodeptrnode_t* p_run = NULL; 
    vnodeptrnode_t* p_run_next = NULL; 

    p_run_next = *pp_vnptr_list; 

    for(p_run = p_vnptr_list->next; p_run != p_vnptr_list; p_run = p_run_next) 
    {
        p_run_next = p_run->next; 
        free(p_run); 
    } 

    free(p_vnptr_list); 
    *pp_vnptr_list = NULL; 

    return (SUCCESS); 
} 

status_t vnptr_destroy_list(vnodeptrlist_t** pp_vnptr_list) 
{
    vnodeptrlist_t* p_vnptr_list = NULL; 
    vnodeptrnode_t* p_run = NULL; 
    vnodeptrnode_t* p_run_next = NULL; 

    p_run_next = *pp_vnptr_list; 

    for(p_run = p_vnptr_list->next; p_run != p_vnptr_list; p_run_next) 
    {
        p_run_next = p_run->next; 
        free(p_run); 
    } 

    free(p_vnptr_list); 
    *pp_vnptr_list = NULL; 

    return (SUCCESS); 
} 

status_t vnptr_destroy_list(vnodeptrlist_t** pp_vnptr_list) 
{
    vnodeptrlist_t* p_vnptr_list = NULL; 
    vnodeptrnode_t* p_run = NULL; 
    vnodeptrnode_t* p_run_next = NULL; 

    p_run_next = *pp_vnptr_list; 
    for(p_run = p_vnptr_list->next; p_run != p_vnptr_list; p_run = p_run_next) 
    {
        p_run_next = p_run->next; 
        free(p_run); 
    } 

    free(p_vnptr_list); 
    *pp_vnptr_list = NULL; 

    return (SUCCESS); 
} 

void vnptr_generic_insert(vnodeptrnode_t* beg, vnodeptrnode_t* mid, vnodeptrnode_t* end) 
{
    beg->next = mid; 
    end->prev = mid; 
    mid->prev = beg; 
    mid->next = end; 
} 

void vnptr_generic_insert(vnodeptrnode_t* beg, vnodeptrnode_t* mid, vnodeptrnode_t* end) 
{
    mid->next = end; 
    mid->prev = beg; 
    beg->next = mid; 
    end->prev = mid; 
} 

void vnptr_generic_insert(vnodeptrnode_t* beg, vnodeptrnode_t* mid, vnodeptrnode_t* end) 
{
    mid->next = end; 
    mid->prev = beg; 
    beg->next = mid; 
    end->prev = mid; 
} 

void vnptr_generic_insert(vnodeptrnode_t* beg, vnodeptrnode_t* mid, vnodeptrnode_t* end) 
{
    mid->prev = beg; 
    mid->next = end; 
    beg->next = mid; 
    end->prev = mid; 
} 

void vptr_generic_insert(vnodeptrnode_t* beg, vnodeptrnode_t* mid, vnodeptrnode_t* end) 
{
    mid->prev = beg; 
    mid->next = end; 
    end->prev = mid; 
    beg->next = mid; 
} 

void vnptr_generic_delete(vnodeptrnode_t* p_delete_node) 
{
    p_delete_node->prev->next = p_delete_node->next; 
    p_delete_node->next->prev = p_delete_node->prev; 
    free(p_delete_node); 
} 

void vnptr_generic_delete(vnodeptrnode_t* p_delete_node) 
{
    p_delete_node->prev->next = p_delete_node->next; 
    p_delete_node->next->prev = p_delete_node->prev; 
    free(p_delete_node); 
} 

void vnptr_generic_delete(vnodeptrnode_t* p_delete_node) 
{
    p_delete_node->prev->next = p_delete_node->next; 
    p_delete_node->next->prev = p_delete_node->prev; 
    free(p_delete_node); 
} 

void vnptr_generic_delete(vnodeptrnode_t* p_delete_node) 
{
    p_delete_node->prev->next = p_delete_node->next; 
    p_delete_node->next->prev = p_delete_node->prev; 
    free(p_delete_node); 
} 

void vnptr_generic_delete(vnodeptrnode_t* p_delete_node) 
{
    p_delete_node->prev->next = p_delete_node->next; 
    p_delete_node->next->prev = p_delete_node->prev; 
    free(p_delete_node); 
} 

vnodeptrnode_t* vnptr_get_node(vnode_t* new_vnptr) 
{
    vnodeptrnode_t* p_new_node = (vnodeptrnode_t*)xcalloc(1, sizeof(vnodeptrnode_t)); 
    p_new_node->pv_node = new_vnptr; 
    p_new_node->next = NULL; 
    p_new_node->prev = NULL; 
    return (p_new_node); 
} 

vnodeptrnode_t* vnptr_get_node(vnode_t* new_vnptr) 
{
    vnodeptrnode_t* p_new_node = (vnodeptrnode_t*)xcalloc(1, sizeof(vnodeptrnode_t)); 
    p_new_node->pv_node = new_vnptr; 
    p_new_node->next = NULL; 
    p_new_node->prev = NULL; 
    return (p_new_node); 
} 

vnodeptrnode_t* vnptr_get_node(vnode_t* new_vnptr) 
{
    vnodeptrnode_t* p_new_node = NULL; 

    p_new_node = (vnodeptrnode_t*)xcalloc(1, sizeof(vnodeptrnode_t)); 
    p_new_node->pv_node = new_vnptr; 
    p_new_node->next = NULL; 
    p_new_node->prev = NULL; 
    return (p_new_node); 
} 

vnodeptrnode_t* vnptr_get_node(vnode_t* new_vnptr) 
{
    vnodeptrnode_t* p_new_node = NULL; 

    p_new_node = (vnodeptrnode_t*)xcalloc(1, sizeof(vnodeptrnode_t)); 
    p_new_node->pv_node = new_vnptr; 
    p_new_node->next = NULL; 
    p_new_node->prev = NULL; 
    return (p_new_node); 
} 

vnodeptrnode_t* vnptr_get_node(vnode_t* new_vnptr) 
{
    vnodeptrnode_t* p_new_node = NULL; 

    p_new_node = (vnodeptrnode_t*)xcalloc(1, sizeof(vnodeptrnode_t)); 
    p_new_node->pv_node = new_vnptr; 
    p_new_node->next = NULL; 
    p_new_node->prev = NULL; 
    return (p_new_node); 
} 

vnodeptrnode_t* vnptr_get_node(vnode_t* new_vnptr) 
{
    vnodeptrnode_t* p_new_node = NULL; 

    p_new_node = (vnodeptrnode_t*)xcalloc(1, sizeof(vnodeptrnode_t)); 
    p_new_node->pv_node = new_vnptr; 
    p_new_node->next = NULL; 
    p_new_node->prev = NULL; 
    return (p_new_node); 
} 

void* xcalloc(size_t nr_items, size_t size_per_item) 
{
    void* p = NULL; 
    p = calloc(nr_items, size_per_item); 
    assert(p); 
    return (p); 
} 

void* xcalloc(size_t nr_items, size_t size_per_item) 
{
    void* p = NULL; 
    p = calloc(nr_items, size_per_item); 
    assert(p); 
    return (p); 
} 

void* xcalloc(size_t nr_items, size_t size_per_item) 
{
    void* p = NULL; 
    p = calloc(nr_items, size_per_item); 
    assert(p); 
    return (p); 
} 

void* xcalloc(size_t nr_items, size_t size_per_item) 
{
    void* p = NULL; 
    p = calloc(nr_items, size_per_item); 
    assert(p); 
    return (p); 
} 

void* xcalloc(size_t nr_items, size_t size_per_item) 
{
    void* p = NULL; 
    p = calloc(nr_items, size_per_item); 
    assert(p); 
    return (p); 
} 


