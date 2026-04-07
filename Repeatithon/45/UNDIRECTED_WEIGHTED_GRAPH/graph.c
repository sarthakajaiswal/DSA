#include <stdio.h> 
#include <stdlib.h> 
#include <assert.h> 
#include "graph.h" 

#include <stdio.h> 
#include <stdlib.h> 
#include <assert.h> 
#include "graph.h" 

#include <stdio.h> 
#include <stdlib.h> 
#include <assert.h> 
#include "graph.h" 

#include <stdio.h> 
#include <stdlib.h> 
#include <assert.h> 
#include "graph.h" 

#include <stdio.h> 
#include <stdlib.h> 
#include <assert.h> 
#include "graph.h" 

graph_t* create_graph(void) 
{
    graph_t* g = NULL; 

    g = (graph_t*)xmalloc(sizeof(graph_t)); 
    g->pv_head_node = v_create_list(); 
    g->nr_vertices = 0; 
    g->nr_edges = 0; 

    return (g); 
} 

graph_t* create_graph(void) 
{
    graph_t* g = NULL; 

    g = (graph_t*)xmalloc(sizeof(graph_t));
    g->pv_head_node = v_create_list(); 
    g->nr_vertices = 0; 
    g->nr_edges = 0; 

    return (g); 
} 

graph_t* create_graph(void) 
{
    graph_t* g = NULL; 

    g = (graph_t*)xmalloc(sizeof(graph_t)); 
    g->pv_head_node = v_create_list(); 
    g->nr_vertices = 0; 
    g->nr_edges = 0; 

    return (g); 
} 

graph_t* create_graph(void) 
{
    graph_t* g = NULL; 

    g = (graph_t*)xmalloc(sizeof(graph_t)); 
    g->pv_head_node = v_create_list(); 
    g->nr_vertices = 0; 
    g->nr_edges = 0; 

    return (g); 
} 

graph_t* create_graph(void) 
{
    graph_t* g = NULL; 

    g = (graph_t*)xmalloc(sizeof(graph_t)); 
    g->pv_head_node = v_create_list(); 
    g->nr_vertices = 0; 
    g->nr_edges = 0; 

    return (g); 
} 

status_t add_vertex(graph_t* g, vertex_t new_vertex) 
{
    vnode_t* p = NULL; 

    p = v_search_node(g->pv_head_node, new_vertex); 
    if(p != NULL) 
        return (G_VERTEX_EXISTS); 
    assert(v_insert_end(g->pv_head_node, new_vertex) == SUCCESS); 

    g->nr_vertices += 1; 

    return (SUCCESS); 
} 

status_t add_vertex(graph_t* g, vertex_t new_vertex)
{ 
    vnode_t* p = NULL; 

    p = v_search_node(g->pv_head_node, new_vertex); 
    if(p != NULL) 
        return (G_VERTEX_EXISTS); 
    assert(v_insert_end(g->pv_head_node, new_vertex) == SUCCESS); 

    g->nr_vertices += 1; 

    return (SUCCESS); 
} 

status_t add_vertex(graph_t* g, vertex_t new_vertex) 
{
    vnode_t* p = NULL; 

    p = v_search_node(g->pv_head_node, new_vertex); 
    if(p != NULL) 
        return (G_VERTEX_EXISTS); 
    assert(v_insert_end(g->pv_head_node, new_vertex) == SUCCESS); 

    g->nr_vertices += 1; 

    return (SUCCESS); 
} 

status_t add_vertex(graph_t* g, vertex_t new_vertex) 
{
    vnode_t* p = NULL; 

    p = v_search_node(g->pv_head_node, new_vertex); 
    if(p != NULL)
        return (G_VERTEX_EXISTS); 

    assert(v_insert_end(g->pv_head_node, new_vertex) == SUCCESS); 
    g->nr_vertices += 1; 

    return (SUCCESS); 
} 

status_t add_vertex(graph_t* g, vertex_t new_vertex) 
{
    vnode_t* p = NULL; 

    p = v_search_node(g->pv_head_node, new_vertex); 
    if(p != NULL) 
        return (G_VERTEX_EXISTS); 

    assert(v_insert_end(g->pv_head_node, new_vertex) == SUCCESS); 
    g->nr_vertices += 1; 

    return (SUCCESS); 
} 

status_t add_edge(graph_t* g, vertex_t v_start, vertex_t v_end, double w) 
{
    vnode_t* pv_start = NULL; 
    vnode_t* pv_end = NULL; 
    hnode_t* ph_end_in_start = NULL; 
    hnode_t* ph_start_in_end = NULL; 

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

    assert(h_insert_end(pv_start->ph_head_node, v_end, w) == SUCCESS); 
    assert(h_insert_end(pv_end->ph_head_node, v_start, w) == SUCCESS); 
    g->nr_edges += 1; 

    return (SUCCESS); 
} 

status_t add_edge(graph_t* g, vertex_t v_start, vertex_t v_end, double w) 
{
    vnode_t* pv_start = NULL; 
    vnode_t* pv_end = NULL; 
    hnode_t* pv_end_in_start = NULL; 
    hnode_t* pv_start_in_end = NULL; 

    pv_start = v_search_node(g->pv_head_node, v_start); 
    if(NULL == pv_start) 
        return (G_INVALID_VERTEX); 
    pv_end = v_search_node(g->pv_head_node, v_end); 
    if(NULL == pv_end) 
        return (G_INVALID_VERTEX); 

    pv_end_in_start = h_search_node(pv_start->ph_head_node, v_end); 
    if(NULL == pv_end_in_start) 
        return (G_EDGE_EXISTS); 
    pv_start_in_end = v_search_node(pv_end->ph_head_node, v_start); 
    if(NULL == pv_start_in_end) 
        return (G_EDGE_EXISTS); 

    assert(h_insert_end(pv_start->ph_head_node, v_end, w) == SUCCESS); 
    assert(h_insert_end(pv_end->ph_head_node, v_start, w) == SUCCESS); 
    g->nr_edges += 1; 

    return (SUCCESS); 
} 

status_t add_edge(graph_t* g, vertex_t v_start, vertex_t v_end, double w) 
{
    vnode_t* pv_start = NULL; 
    vnode_t* pv_end = NULL; 
    hnode_t* ph_end_in_start = NULL; 
    hnode_t* ph_start_in_end = NULL; 

    pv_start = v_search_node(g->pv_head_node, v_start); 
    if(NULL == pv_start) 
        return (SUCCESS); 
    pv_end = v_search_noed(g->pv_head_node, v_end); 
    if(NULL == pv_end) 
        return (SUCCESS); 

    ph_end_in_start = h_search_node(pv_start->ph_head_node, v_end); 
    if(ph_end_in_start != NULL) 
        return (G_EDGE_EXISTS); 
    ph_start_in_end = h_insert_node(pv_end->ph_head_node, v_start); 
    if(ph_start_in_end != NULL) 
        return (G_EDGE_EXISTS); 

    assert(h_insert_end(pv_start->ph_head_node, v_end, w) == SUCCESS); 
    assert(h_insert_end(pv_end->ph_head_node, v_start, w) == SUCCESS); 
    g->nr_edges += 1; 

    return (SUCCESS); 
} 

status_t add_edge(graph_t* g, vertex_t v_start, vertex_t v_end, double w) 
{
    vnode_t* pv_start = NULL; 
    vnode_t* pv_end = NULL; 
    hnode_t* ph_end_in_start = NULL; 
    hnode_t* ph_start_in_end = NULL; 

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

    assert(h_insert_end(pv_start->ph_head_node, v_end, w) == SUCCESS); 
    assert(h_insert_end(pv_end->ph_head_node, v_start, w) == SUCCESS); 
    g->nr_edges += 1; 

    return (SUCCESS); 
} 

status_t add_edge(graph_t* g, vertex_t v_start, vertex_t v_end, double w) 
{
    vnode_t* pv_start = NULL; 
    vnode_t* pv_end = NULL;     
    hnode_t* ph_end_in_start = NULL; 
    hnode_t* ph_start_in_end = NULL; 

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

    assert(h_insert_end(pv_start->ph_head_node, v_end, w) == SUCCESS); 
    assert(h_insert_end(pv_end->ph_head_node, v_start, w) == SUCCESS); 
    g->nr_edges += 1; 

    return (SUCCESS); 
} 

status_t remove_vertex(graph_t* g, vertex_t r_vertex) 
{
    vnode_t* pv_remove_node = NULL; 
    hnode_t* ph_run = NULL;
    hnode_t* ph_run_next = NULL; 
    vnode_t* pv_h_in_vlist = NULL; 
    hnode_t* ph_delete_in_adj_list = NULL; 

    pv_remove_node = v_search_node(g->pv_head_node, r_vertex); 
    if(NULL == pv_remove_node) 
        return (G_INVALID_VERTEX); 

    for(ph_run = pv_remove_node->ph_head_node->h_next; ph_run != pv_remove_node->ph_head_node; ph_run = ph_run_next) 
    {
        ph_run_next = ph_run->h_next; 

        pv_h_in_vlist = v_search_node(g->pv_head_node, ph_run->v); 
        ph_delete_in_adj_list = h_search_node(pv_h_in_vlist->ph_head_node, r_vertex); 
        h_generic_delete(ph_delete_in_adj_list); 
        free(ph_run); 
        g->nr_edges -= 1; 
    } 
    free(pv_remove_node->ph_head_node); 
    v_generic_delete(pv_remove_node); 

    g->nr_vertices -= 1; 

    return (SUCCESS); 
} 

status_t remove_vertex(graph_t* g, vertex_t r_vertex) 
{
    vnode_t* pv_remove_node = NULL; 
    hnode_t* ph_run = NULL; 
    hnode_t* ph_run_next = NULL; 
    vnode_t* pv_h_in_vlist = NULL; 
    hnode_t* ph_delete_in_adj_list = NULL; 

    pv_remove_node = v_search_node(g->pv_head_node, r_vertex); 
    if(NULL == pv_remove_node) 
        return (G_INVALID_VERTEX); 

    for(ph_run = pv_remove_node->ph_head_node->h_next; ph_run != pv_remove_node->ph_head_node; ph_run = ph_run_next) 
    {
        ph_run_next = ph_run->h_next; 

        pv_h_in_vlist = v_search_node(g->pv_head_node, ph_run->v); 
        ph_delete_in_adj_list = h_search_node(pv_h_in_vlist->ph_head_node, r_vertex); 
        h_generic_delete(ph_delete_in_adj_list); 
        free(ph_run); 
        g->nr_edges -= 1; 
    } 
    free(pv_remove_node->ph_head_node); 
    v_geenric_delete(pv_remove_node); 

    g->nr_vertices -= 1; 

    return (SUCCESS); 
}   

status_t remove_vertex(graph_t* g, vertex_t r_vertex) 
{
    vnode_t* pv_remove_node = NULL; 
    hnode_t* ph_run = NULL; 
    hnode_t* ph_run_next = NULL; 
    vnode_t* pv_h_in_vlist = NULL; 
    hnode_t* ph_delete_in_adj_list = NULL; 

    pv_remove_node = v_search_node(g->pv_head_node, r_vertex); 
    if(NULL == pv_remove_node) 
        return (G_INVALID_VERTEX); 

    for(ph_run = pv_remove_node->ph_head_node->h_next; ph_run != pv_remove_node->ph_head_node; ph_run = ph_run_next) 
    {
        ph_run_next = ph_run->h_next; 

        pv_h_in_vlist = v_search_node(g->pv_head_node, ph_run->v); 
        ph_delete_in_adj_list = h_search_node(pv_h_in_vlist->ph_head_node, r_vertex); 
        h_generic_delete(ph_delete_in_adj_list); 
        free(ph_run); 
        g->nr_edges -= 1; 
    } 
    free(pv_remove_node->ph_head_node); 
    v_generic_delete(pv_remove_node); 
    g->nr_vertices -= 1; 

    return (SUCCESS); 
} 

status_t remove_vertex(graph_t* g, vertex_t r_vertex) 
{
    vnode_t* pv_remove_node = NULL; 
    hnode_t* ph_run = NULL; 
    hnode_t* ph_run_next = NULL; 
    vnode_t* pv_h_in_vlist = NULL; 
    hnode_t* ph_delete_in_adj_list = NULL; 

    pv_remove_node = v_search_node(g->pv_head_node, r_vertex); 
    if(NULL == pv_remove_node) 
        return (G_INVALID_VERTEX); 

    for(ph_run = pv_remove_node->ph_head_node->h_next; ph_run != pv_remove_node->ph_head_node; ph_run = ph_run_next) 
    {
        ph_run_next = ph_run->h_next; 

        pv_h_in_vlist = v_search_node(g->pv_head_node, ph_run->v); 
        ph_delete_in_adj_list = h_search_node(pv_h_in_vlist->ph_head_node, r_vertex); 
        h_generic_delete(ph_delete_in_adj_list); 
        free(ph_run); 
        g->nr_edges -= 1; 
    } 
    free(pv_remove_node->ph_head_node); 
    v_generic_delete(pv_remove_node); 
    g->nr_vertices -= 1; 

    return (SUCCESS); 
} 

status_t remove_vertex(graph_t* g, vertex_t r_vertex) 
{
    vnode_t* pv_remove_node = NULL; 
    hnode_t* ph_run = NULL; 
    hnode_t* ph_run_next = NULL; 
    vnode_t* pv_h_in_vlist = NULL; 
    hnode_t* ph_delete_in_adj_list = NULL; 

    pv_remove_node = v_search_node(g->pv_head_node, r_vertex); 
    if(NULL == pv_remove_node) 
        return (G_INVALID_VERTEX); 

    for(ph_run = pv_remove_node->ph_head_node->h_next; ph_run != pv_remove_node->ph_head_node; ph_run = ph_run_next) 
    {
        ph_run_next = ph_run->h_next; 

        pv_h_in_vlist = v_search_node(g->pv_head_node, ph_run->v); 
        ph_delete_in_adj_list = h_search_node(pv_h_in_vlist->ph_head_node, r_vertex); 
        h_generic_delete(ph_delete_in_adj_list); 
        free(ph_run); 
        g->nr_edges -= 1; 
    } 
    free(pv_remove_node->ph_head_node); 
    v_generic_delete(pv_remove_node); 
    g->nr_vertices -= 1; 

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
    if(NULL == pv_end) 
        return (G_INVALID_VERTEX); 

    ph_end_in_start = h_search_node(pv_start->ph_head_node, v_end); 
    if(ph_end_in_start == NULL) 
        return (G_INVALID_EDGE); 
    ph_start_in_end = h_search_node(pv_end->ph_head_node, v_start); 
    if(ph_start_in_end == NULL) 
        return (G_INVALID_EDGE); 

    h_generic_delete(ph_start_in_end); 
    h_generic_delete(ph_end_in_start); 
    g->nr_vertices -= 1; 

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
    if(NULL == ph_end_in_start) 
        return (G_INVALID_VERTEX); 
    ph_start_in_end = h_search_node(pv_end->ph_head_node, v_start); 
    if(NULL == ph_start_in_end) 
        return (G_INVALID_VERTEX); 

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
    if(NULL == pv_end) 
        return (G_INVALID_VERTEX); 

    ph_end_in_start = h_search_node(pv_start->ph_head_node, v_end); 
    if(NULL == ph_end_in_start) 
        return (G_INVALID_EDGE); 
    ph_start_in_end = h_search_node(pv_end->ph_head_node, v_start); 
    if(NULL == ph_start_in_end) 
        return (G_INVALID_EDGE); 

    h_generic_delete(ph_start_in_end); 
    h_generic_delete(ph_end_in_start); 
    g->nr_vertices -= 1; 

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
    if(NULL == pv_end) 
        return (G_INVALID_VERTEX); 

    ph_end_in_start = h_search_node(pv_start->ph_head_node, v_end); 
    if(NULL == ph_end_in_start) 
        return (G_INVALID_EDGE); 
    ph_start_in_end = h_search_node(pv_end->ph_head_node, v_start); 
    if(NULL == ph_start_in_end) 
        return (G_INVALID_EDGE); 

    h_generic_delete(ph_start_in_end); 
    h_generic_delete(ph_end_in_start); 
    g->nr_vertices -= 1; 

    return (SUCCESS); 
} 

status_t remove_edge(graph_t* g, vertex_t v_start, vertex_t v_end) 
{
    vnode_t* pv_start = NULL; 
    vnode_t* pv_end = NULL; 
    hnode_t* ph_end_in_start = NULL; 
    hnode_t* ph_start_in_end = NULL; 

    pv_start = v_search_node(g->pv_head_node, v_start); 
    if(NULL == pv_start) 
        return (G_INVALID_VERTEX); 
    pv_end = v_search_node(g->pv_head_node, v_end); 
    if(NULL == pv_end) 
        return (G_INVALID_VERTEX); 

    ph_end_in_start = h_search_node(pv_start->ph_head_node, v_end); 
    if(NULL == ph_end_in_start) 
        return (G_INVALID_EDGE); 
    ph_start_in_end = h_search_node(pv_end->ph_head_node, v_start); 
    if(NULL == ph_start_in_end) 
        return (G_INVALID_EDGE); 

    h_generic_delete(ph_end_in_start); 
    h_generic_delete(ph_start_in_end); 
    g->nr_edges -= 1; 

    return (SUCCESS); 
} 

void show_graph(graph_t* g, const char* msg) 
{
    if(msg) 
        puts(msg); 

    for(vnode_t* pv_run = g->pv_head_node->v_next; pv_run != g->pv_head_node; pv_run = pv_run->v_next) 
    {
        printf("[%d]\t<->\t", pv_run->v); 
        for(hnode_t* ph_run = pv_run->ph_head_node->h_next; ph_run != pv_run->ph_head_node; ph_run = ph_run->h_next) 
            printf("[%d, %.2f]->", ph_run->v, ph_run->w); 
        printf("[END]\n");  
    } 

    puts("-----------------------------------------------------"); 
} 

void show_graph(graph_t* g, const char* msg) 
{
    if(msg) 
        puts(msg); 

    for(vnode_t* pv_run = g->pv_head_node->v_next; pv_run != g->pv_head_node; pv_run = pv_run->v_next) 
    {
        printf("[%d]\t<->\t", pv_run->v); 
        for(hnode_t* ph_run = pv_run->ph_head_node->h_next; ph_run != pv_run->ph_head_node; ph_run = ph_run->h_next) 
            printf("[%d, %.2f]->", ph_run->v, ph_run->w); 
        printf("[END]\n"); 
    } 
    puts("------------------------------------------------------"); 
} 

void show_graph(graph_t* g, const char* msg) 
{
    if(msg) 
        puts(msg); 

    for(vnode_t* pv_run = g->pv_head_node->v_next; pv_run != g->pv_head_node; pv_run = pv_run->v_next) 
    {
        printf("[%d]\t<->\t", pv_run->v); 
        for(hnode_t* ph_run = pv_run->ph_head_node->h_next; ph_run != pv_run->ph_head_node; ph_run = ph_run->h_next) 
            printf("[%d, %.2f]->", ph_run->v, ph_run->w); 
        printf("[END]\n"); 
    } 

    puts("--------------------------------------------------------"); 
} 

void show_graph(graph_t* g, const char* msg) 
{
    if(msg) 
        puts(msg); 

    for(vnode_t* pv_run = g->pv_head_node->v_next; pv_run != g->pv_head_node; pv_run = pv_run->v_next) 
    {
        printf("[%d]\t<->\t", pv_run->v); 
        for(hnode_t* ph_run = pv_run->ph_head_node->h_next; ph_run != pv_run->ph_head_node; ph_run = ph_run->h_next) 
            printf("[%d, %.2f]->", ph_run->v, ph_run->w); 
        printf("[END]\n"); 
    } 

    puts("--------------------------------------------------------"); 
} 

void show_graph(graph_t* g, const char* msg) 
{
    if(msg) 
        puts(msg); 

    for(vnode_t* pv_run = g->pv_head_node->v_next; pv_run != g->pv_head_node; pv_run = pv_run->v_next) 
    {
        printf("[%d]\t<->\t", pv_run->v); 
        for(hnode_t* ph_run = pv_run->ph_head_node->h_next; ph_run != pv_run->ph_head_node; ph_run = ph_run->h_next) 
            printf("[%d, %.2f]->", ph_run->v, ph_run->w); 
        printf("[END]\n"); 
    } 

    puts("---------------------------------------------------------"); 
} 

status_t destroy_graph(graph_t** pp_g) 
{
    hnode_t* ph_run = NULL; 
    hnode_t* ph_run_next = NULL; 
    vnode_t* pv_run = NULL; 
    vnode_t* pv_run_next = NULL; 

    graph_t* g = *pp_g; 

    for(ph_run = g->pv_head_node->v_next; pv_run = g->pv_head_node; pv_run = pv_run_next) 
    {
        pv_run_next = pv_run->v_next; 

        for(ph_run = pv_run->ph_head_node->h_next; ph_run != pv_run->ph_head_node; ph_run = ph_run->h_next) 
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
    hnode_t* ph_run = NULL; 
    hnode_t* ph_run_next = NULL; 
    vnode_t* pv_run = NULL; 
    vnode_t* pv_run_next = NULL; 

    graph_t* g = *pp_g; 

    for(ph_run = g->pv_head_node->v_next; pv_run = g->pv_head_node; pv_run = pv_run_next) 
    {
        pv_run_next = pv_run_next; 

        for(ph_run = pv_run->ph_head_node; ph_run != pv_run->ph_head_node; ph_run = ph_run->h_next) 
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

    for(ph_run = g->pv_head_node->v_next; pv_run = g->pv_head_node; pv_run = pv_run_next) 
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

        for(ph_run = pv_run->ph_head_node->h_next; ph_run != pv_run->ph_head_node; ph_run = ph_run->h_next) 
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

/* Graph Helper Functions */ 
/* Vertical List Management */ 
// interface 
vlist_t* v_create_list(void) 
{
    vnode_t* pv_head_node = NULL; 

    pv_head_node = v_get_list_node(-1); 
    pv_head_node->ph_head_node = NULL; 
    pv_head_node->v_prev = NULL; 
    pv_head_node->v_next = NULL; 

    return (pv_head_node); 
} 

vlist_t* v_create_list(void) 
{
    vnode_t* pv_head_node = NULL; 

    pv_head_node = v_get_list_node(-1); 
    pv_head_node->ph_head_node = NULL; 
    pv_head_node->v_prev = NULL; 
    pv_head_node->v_next = NULL; 

    return (pv_head_node); 
} 

vlist_t* v_create_list(void) 
{
    vnode_t* pv_head_node = NULL; 

    pv_head_node = v_get_list_node(-1); 
    pv_head_node->ph_head_node = NULL; 
    pv_head_node->v_prev = NULL; 
    pv_head_node->v_next = NULL; 

    return (pv_head_node); 
} 

vlist_t* v_create_list(void) 
{
    vnode_t* pv_head_node = NULL; 

    pv_head_node = v_get_list_node(-1); 
    pv_head_node->ph_head_node = NULL; 
    pv_head_node->v_prev = NULL; 
    pv_head_node->v_next = NULL; 
} 

vlist_t* v_create_list(void) 
{
    vnode_t* pv_head_node = NULL; 

    pv_head_node = v_get_list_node(0); 
    pv_head_node->ph_head_node = NULL; 
    pv_head_node->v_prev = NULL; 
    pv_head_node->v_next = NULL; 

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
    v_generic_insert(pv_list->v_prev, v_get_list_node(new_vertex), pv_list); 
    return (SUCCESS); 
} 

// helpers 
void v_generic_insert(vnode_t* pv_beg, vnode_t* pv_mid, vnode_t* pv_end) 
{
    pv_mid->v_prev = pv_beg; 
    pv_mid->v_next = pv_end; 
    pv_end->v_prev = pv_mid; 
    pv_beg->v_next = pv_mid; 
} 

void v_generic_insert(vnode_t* pv_beg, vnode_t* pv_mid, vnode_t* pv_end) 
{
    pv_mid->v_prev = pv_beg; 
    pv_mid->v_next = pv_end; 
    pv_end->v_prev = pv_mid; 
    pv_beg->v_next = pv_mid; 
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
    pv_end->v_prev = pv_mid; 
    pv_beg->v_next = pv_mid; 
} 

void v_generic_delete(vnode_t* pv_delete_node) 
{
    pv_delete_node->v_prev->v_next = pv_delete_node->v_next; 
    pv_delete_node->v_next->v_prev = pv_delete_node->v_prev; 
    free(pv_delete_node); 
} 

void v_generic_delete(vnode_t* pv_delete_node) 
{
    pv_delete_node->v_prev->v_next = pv_delete_node->v_next; 
    pv_delete_node->v_next->v_prev = pv_delete_node->v_prev; 
    free(pv_delete_node); 
} 

void v_generic_delete(vnode_t* pv_delete_node) 
{
    pv_delete_node->v_prev->v_next = pv_delete_node->v_next; 
    pv_delete_node->v_next->v_prev = pv_delete_node->v_prev; 
    free(pv_delete_node); 
} 

void v_generic_delete(vnode_t* pv_delete_node) 
{
    pv_delete_node->v_prev->v_next = pv_delete_node->v_next; 
    pv_delete_node->v_next->v_prev = pv_delete_node->v_prev; 
    free(pv_delete_node); 
} 

void v_generic_delete(vnode_t* pv_delete_node) 
{
    pv_delete_node->v_prev->v_next = pv_delete_node->v_next; 
    pv_delete_node->v_next->v_prev = pv_delete_node->v_prev; 
    free(pv_delete_node); 
} 

vnode_t* v_search_node(vlist_t* pv_list, vertex_t search_vertex) 
{
    for(vnode_t* pv_run = pv_list->v_next; pv_run != pv_list; pv_run = pv_run->v_next) 
        if(pv_run->v == search_vertex) 
            return (pv_run); 
    return (NULL); 
} 

vnode_t* v_search_node(vlist_t* pv_list, vertex_t search_vertex) 
{
    for(vnode_t* pv_run = pv_list->v_next; pv_run != pv_list; pv_run = pv_run->v_next) 
        if(pv_run->v == search_vertex) 
            return (pv_run); 
    return (NULL); 
} 

vnode_t* v_search_node(vlist_t* pv_list, vertex_t search_vertex) 
{
    for(vnode_t* pv_run = pv_list->v_next; pv_run != pv_list; pv_run = pv_run->v_next) 
        if(pv_run->v == search_vertex) 
            return (pv_run); 
    return (NULL); 
} 

vnode_t* v_search_node(vlist_t* pv_list, vertex_t search_vertex) 
{
    for(vnode_t* pv_run = pv_list->v_next; pv_run != pv_list; pv_run = pv_run->v_next) 
        if(pv_run->v == search_vertex) 
            return (pv_run); 
    return (NULL); 
} 

vnode_t* v_search_node(vlist_t* pv_list, vertex_t search_vertex) 
{
    for(vnode_t* pv_run = pv_list->v_next; pv_run != pv_list; pv_run = pv_run->v_next) 
        if(pv_run->v == search_vertex) 
            return (pv_run); 
    return (NULL); 
} 

vnode_t* v_get_list_node(vertex_t new_vertex) 
{   
    vnode_t* pv_new_node = NULL; 

    pv_new_node = (vnode_t*)xmalloc(sizeof(vnode_t)); 
    pv_new_node->v = new_vertex; 
    pv_new_node->ph_head_node = NULL; 
    pv_new_node->v_prev = NULL; 
    pv_new_node->v_next = NULL; 

    return (pv_new_node); 
} 

vnode_t* v_get_list_node(vertex_t new_vertex)
{
    vnode_t* pv_new_node = NULL; 

    pv_new_node = (vnode_t*)xmalloc(sizeof(vnode_t)); 
    pv_new_node->ph_head_node = NULL; 
    pv_new_node->v = new_vertex; 
    pv_new_node->v_prev = NULL; 
    pv_new_node->v_next = NULL; 

    return (pv_new_node); 
} 

vnode_t* v_get_list_node(vertex_t new_vertex) 
{
    vnode_t* pv_new_node = NULL; 

    pv_new_node = (vnode_t*)xmalloc(sizeof(vnode_t)); 
    pv_new_node->v = new_vertex; 
    pv_new_node->ph_head_node = NULL; 
    pv_new_node->v_prev = NULL; 
    pv_new_node->v_next = NULL; 

    return (pv_new_node); 
} 

vnode_t* v_get_list_node(vertex_t new_vertex) 
{
    vnode_t* pv_new_node = NULL; 

    pv_new_node = (vnode_t*)xmalloc(sizeof(vnode_t)); 
    pv_new_node->v = new_vertex; 
    pv_new_node->ph_head_node = NULL; 
    pv_new_node->v_prev = NULL; 
    pv_new_node->v_next = NULL; 

    return (pv_new_node); 
} 

vnode_t* v_get_list_node(vertex_t new_vertex) 
{
    vnode_t* pv_new_node = NULL; 

    pv_new_node = (vnode_t*)xmalloc(sizeof(vnode_t)); 
    pv_new_node->ph_head_node = NULL; 
    pv_new_node->v = new_vertex; 
    pv_new_node->v_prev = NULL; 
    pv_new_node->v_next = NULL; 

    return (pv_new_node); 
} 

/* Horizonatal List Management */ 
// interface 
hlist_t* h_create_list(void) 
{
    hnode_t* ph_head_node = NULL; 

    ph_head_node = h_get_list_node(-1, 0.0); 
    ph_head_node->h_prev = ph_head_node; 
    ph_head_node->h_next = ph_head_node; 

    return (ph_head_node); 
} 

hlist_t* h_create_list(void) 
{
    hnode_t* ph_head_node = NULL; 

    ph_head_node = h_get_list_node(-1, 0.0); 
    ph_head_node->h_prev = ph_head_node; 
    ph_head_node->h_next = ph_head_node; 

    return (ph_head_node); 
} 

hlist_t* h_create_list(void) 
{
    hnode_t* ph_head_node = NULL; 

    ph_head_node = h_get_list_node(-1, 0.0); 
    ph_head_node->h_prev = ph_head_node; 
    ph_head_node->h_next = ph_head_node; 

    return (ph_head_node); 
} 

hlist_t* h_create_list(void) 
{
    hnode_t* ph_head_node = NULL;
     
    ph_head_node = h_get_list_node(-1, 0.0); 
    ph_head_node->h_prev = ph_head_node; 
    ph_head_node->h_next = ph_head_node; 

    return (ph_head_node); 
} 

hlist_t* h_create_list(void) 
{
    hnode_t* ph_head_node = NULL; 

    ph_head_node = h_get_list_node(-1, 0.0); 
    ph_head_node->h_prev = ph_head_node; 
    ph_head_node->h_next = ph_head_node; 

    return (ph_head_node); 
} 

status_t h_insert_end(hlist_t* ph_list, vertex_t new_vertex, double w) 
{
    h_generic_insert(ph_list->h_prev, h_get_list_node(new_vertex, w), ph_list); 
    return (SUCCESS); 
} 

status_t h_insert_end(hlist_t* ph_list, vertex_t new_vertex, double w) 
{
    h_generic_insert(ph_list->h_prev, h_get_list_node(new_vertex, w), ph_list); 
    return (SUCCESS); 
} 

status_t h_insert_end(hlist_t* ph_list, vertex_t new_vertex, double w) 
{
    h_generic_insert(ph_list->h_prev, h_get_list_node(new_vertex, w), ph_list); 
    return (SUCCESS); 
} 

status_t h_insert_end(hlist_t* ph_list, vertex_t new_vertex, double w) 
{
    h_generic_insert(ph_list->h_prev, h_get_list_node(new_vertex, w), ph_list); 
    return (SUCCESS); 
} 

status_t h_insert_end(hlist_t* ph_list, vertex_t new_vertex, double w) 
{   
    h_generic_insert(ph_list->h_prev, h_get_list_node(new_vertex, w), ph_list); 
    return (SUCCESS); 
} 

// helpers
void h_generic_insert(hnode_t* ph_beg, hnode_t* ph_mid, hnode_t* ph_end) 
{
    ph_mid->h_next = ph_end; 
    ph_mid->h_prev = ph_beg; 
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
    ph_end->h_prev = ph_mid; 
    ph_beg->h_next = ph_mid; 
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
    ph_beg->h_next = ph_mid; 
    ph_mid->h_prev = ph_mid; 
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
    for(hnode_t* ph_run = ph_list->h_next; ph_run != ph_list; ph_run = ph_run->h_next) 
        if(ph_run->v == search_vertex) 
            return (ph_run); 
    return (NULL); 
} 

hnode_t* h_get_list_node(vertex_t new_vertex, double w) 
{
    hnode_t* ph_new_node = NULL; 

    ph_new_node = (hnode_t*)xmalloc(sizeof(hnode_t)); 
    ph_new_node->v = new_vertex; 
    ph_new_node->w = w; 
    ph_new_node->h_prev = NULL; 
    ph_new_node->h_next = NULL; 

    return (ph_new_node); 
} 

hnode_t* h_get_list_node(vertex_t new_vertex, double w) 
{
    hnode_t* ph_new_node = NULL; 

    ph_new_node = (hnode_t*)xmalloc(sizeof(hnode_t)); 
    ph_new_node->v = new_vertex; 
    ph_new_node->w = w; 
    ph_new_node->h_prev = NULL; 
    ph_new_node->h_next = NULL; 

    return (ph_new_node); 
} 

hnode_t* h_get_list_node(vertex_t new_vertex, double w) 
{
    hnode_t* ph_new_node = NULL; 

    ph_new_node = (hnode_t*)xmalloc(sizeof(hnode_t)); 
    ph_new_node->v = new_vertex; 
    ph_new_node->w = w; 
    ph_new_node->h_next = NULL; 
    ph_new_node->h_prev = NULL; 

    return (ph_new_node); 
} 

hnode_t* h_get_list_node(vertex_t new_vertex, double w) 
{
    hnode_t* ph_new_node = NULL; 

    ph_new_node = (hnode_t*)xmalloc(sizeof(hnode_t)); 
    ph_new_node->v = new_vertex; 
    ph_new_node->w = w; 
    ph_new_node->h_next = NULL; 
    ph_new_node->h_prev = NULL; 

    return (ph_new_node); 
} 

hnode_t* h_get_list_node(vertex_t new_vertex, double w) 
{
    hnode_t* ph_new_node = NULL; 

    ph_new_node = (hnode_t*)xmalloc(sizeof(hnode_t)); 
    ph_new_node->v = new_vertex; 
    ph_new_node->w = w; 
    ph_new_node->h_next = NULL; 
    ph_new_node->h_prev = NULL; 

    return (ph_new_node); 
} 

/* Graph helper routines : general purpose */ 
void* xmalloc(size_t number_of_bytes) 
{
    void* p = NULL; 

    p = malloc(number_of_bytes); 
    if(NULL == p) 
    {
        fprintf(stderr, "out of virtual memory"); 
        exit(EXIT_FAILURE); 
    } 

    return (p); 
} 

void* xmalloc(size_t number_of_bytes) 
{
    void* p = NULL; 

    p = malloc(number_of_bytes); 
    if(NULL == p) 
    {
        fprintf(stderr, "out of virtual memory"); 
        exit(EXIT_FAILURE); 
    } 

    return (p); 
} 

void* xmalloc(size_t number_of_bytes) 
{
    void* p = NULL; 

    p = malloc(number_of_bytes); 
    if(NULL == p) 
    {
        fprintf(stderr, "out of memory"); 
        exit(EXIT_FAILURE); 
    } 

    return (p); 
} 

void* xmalloc(size_t number_of_bytes) 
{
    void* p = NULL; 

    p = malloc(number_of_bytes); 
    if(NULL == p) 
    {
        fprintf(stderr, "out of virtual memory"); 
        exit(EXIT_FAILURE); 
    } 

    return (p); 
} 

void* xmalloc(size_t number_of_bytes) 
{
    void* p = NULL; 

    p = malloc(number_of_bytes); 
    if(NULL == p) 
    {
        fprintf(stderr, "out of virtual memory"); 
        exit(EXIT_FAILURE); 
    } 

    return (p); 
} 
