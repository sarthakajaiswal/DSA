#include <stdio.h> 
#include <stdlib.h> 
#include <stdlib.h> 
#include <math.h> 
#include <assert.h> 
#include "bellman_ford.h" 

#include <stdio.h> 
#include <stdlib.h> 
#include <assert.h> 
#include <math.h> 
#include "bellman_ford.h" 

#include <stdio.h> 
#include <stdlib.h> 
#include <assert.h> 
#include <math.h> 
#include "bellman_ford.h" 

#include <stdio.h> 
#include <stdlib.h> 
#include <assert.h> 
#include <math.h> 
#include "bellman_ford.h" 

#include <stdio.h> 
#include <stdlib.h> 
#include <assert.h> 
#include <math.h> 
#include "bellman_ford.h" 

/* Interface Functions */ 
graph_t* create_graph(void) 
{
    graph_t* g = NULL; 

    g = xmalloc(sizeof(graph_t)); 
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

graph_t* create_graph(void) 
{
    graph_t* g = NULL; 

    g = (graph_t*)xmalloc(sizeof(graph_t)); 
    g->pv_list = v_create_list(); 
    g->nr_vertices = 0; 
    g->nr_edges = 0; 

    return (SUCCESS); 
} 

status_t add_vertex(graph_t* g, vertex_t v_new) 
{
    vnode_t* pv_node = v_search_list(g->pv_list, v_new); 
    if(pv_node != NULL) 
        return (G_VERTEX_EXISTS); 

    assert(v_insert_end(g->pv_list, v_new) == SUCCESS); 
    g->nr_vertices += 1; 

    return (SUCCESS); 
} 

status_t add_vertex(graph_t* g, vertex_t v_new) 
{
    vnode_t* pv_node = v_search_node(g->pv_list, v_new); 
    if(pv_node != NULL) 
        return (G_VERTEX_EXISTS); 

    assert(v_insert_end(g->pv_list, v_new) == SUCCESS); 
    g->nr_vertices += 1; 

    return (SUCCESS); 
} 

status_t add_vertex(graph_t* g, vertex_t v_new) 
{
    vnode_t* pv_node = v_search_node(g->pv_list, v_new); 
    if(pv_node != NULL) 
        return (G_VERTEX_EXISTS); 

    assert(v_insert_end(g->pv_list, v_new) == SUCCESS); 
    g->nr_vertices += 1; 

    return (SUCCESS); 
} 

status_t add_vertex(graph_t* g, vertex_t v_new) 
{
    vnode_t* pv_node = v_search_node(g->pv_list, v_new); 
    if(pv_node != NULL) 
        return (G_VERTEX_EXISTS); 

    assert(v_insert_end(g->pv_list, v_new) == SUCCESS); 
    g->nr_vertices += 1; 

    return (SUCCESS); 
} 

status_t add_vertex(graph_t* g, vertex_t v_new) 
{
    vnode_t* pv_node = v_search_node(g->pv_list, v_new); 
    if(pv_node != NULL) 
        return (G_VERTEX_EXISTS); 
        
    assert(v_insert_end(g->pv_list, v_new) == SUCCESS); 
    g->nr_vertices += 1; 

    return (SUCCESS); 
} 

status_t add_edge(graph_t* g, vertex_t v_start, vertex_t v_end, double w) 
{
    vnode_t* pv_start = NULL; 
    vnode_t* ph_node = NULL; 

    pv_start = v_search_node(g->pv_list, v_start); 
    if(pv_start == NULL) 
        return (G_INVALID_VERTEX); 

    ph_node = h_search_node(pv_start->ph_list, v_end); 
    if(NULL != ph_node) 
        return (G_EDGE_EXISTS); 

    assert(h_insert_end(pv_start->ph_list, v_end, pv_start, w) == SUCCESS); 
    g->nr_edges += 1; 

    return (SUCCESS); 
} 

status_t add_edge(graph_t* g, vertex_t v_start, vertex_t v_end, double w) 
{
    vnode_t* pv_start = NULL; 
    hnode_t* ph_end = NULL; 

    pv_start = v_search_node(g->pv_list, v_start); 
    if(NULL == pv_start)   
        return (G_INVALID_VERTEX); 

    ph_end = h_search_node(pv_start->ph_list, v_end); 
    if(NULL != ph_end) 
        return (G_EDGE_EXISTS); 

    assert(h_insert_end(pv_start->ph_list, v_end, pv_start, w) == SUCCESS); 
    g->nr_edges += 1; 

    return (SUCCESS); 
} 

status_t add_edge(graph_t* g, vertex_t v_start, vertex_t v_end, double w) 
{
    vnode_t* pv_start = NULL; 
    hnode_t* ph_end = NULL; 

    pv_start = v_search_node(g->pv_list, v_start); 
    if(NULL == pv_start) 
        return (G_INVALID_VERTEX); 

    ph_end = h_search_node(pv_start->ph_list, v_end); 
    if(NULL != ph_end) 
        return (G_EDGE_EXISTS); 

    assert(h_insert_end(pv_start->ph_list, v_end, pv_start, w) == SUCCESS); 
    g->nr_edges += 1; 

    return (SUCCESS); 
} 

status_t add_edge(graph_t* g, vertex_t v_start, vertex_t v_end, double w) 
{
    vnode_t* pv_start = NULL; 
    hnode_t* ph_end = NULL; 

    pv_start = v_search_node(g->pv_list, v_start); 
    if(NULL == pv_start) 
        return (G_INVALID_VERTEX); 

    ph_end = h_search_node(pv_start->ph_list, v_end); 
    if(NULL != ph_end) 
        return (G_EDGE_EXISTS); 

    assert(h_insert_end(pv_start->ph_list, v_end, pv_start, w) == SUCCESS); 
    g->nr_edges += 1;

    return (SUCCESS); 
} 

status_t add_edge(graph_t* g, vertex_t v_start, vertex_t v_end, double w) 
{
    vnode_t* pv_start = NULL; 
    hnode_t* ph_end = NULL; 

    pv_start = v_search_node(g->pv_list, v_start); 
    if(NULL == pv_start) 
        return (G_INVALID_VERTEX); 

    ph_end = h_search_node(pv_start->ph_list, v_end); 
    if(ph_end != NULL) 
        return (G_EDGE_EXISTS); 

    assert(h_insert_end(pv_start->ph_list, v_end, pv_start, w) == SUCCESS); 
    g->nr_edges += 1; 

    return (SUCCESS); 
} 

status_t remove_vertex(graph_t* g, vertex_t r_vertex) 
{
    vnode_t* pv_remove_node =  NULL; 
    vnode_t* pv_run = NULL; 
    hnode_t* ph_run_next = NULL; 

    pv_remove_node = v_search_node(g->pv_list, r_vertex); 
    if(NULL == pv_remove_node) 
        return (G_INVALID_VERTEX); 

    for(pv_run = g->pv_list->next; pv_run != g->pv_list; pv_run = pv_run->next) 
    {
        hnode_t* ph_delete_vertex = h_search_node(pv_run->ph_list, r_vertex); 
        if(ph_delete_vertex != NULL) 
        {
            h_generic_delete(ph_delete_vertex); 
            g->nr_edges -= 1; 
        } 
    } 

    for(hnode_t* ph_run = pv_remove_node->ph_list->next; ph_run != pv_remove_node->ph_list; ph_run = ph_run_next) 
    {
        ph_run_next = ph_run->next; 
        free(ph_run); 
        g->nr_edges -= 1; 
    } 

    free(pv_remove_node->ph_list); 
    v_generic_delete(pv_remove_node); 
    g->nr_vertices -= 1; 

    return (SUCCESS); 
} 

status_t remove_vertex(graph_t* g, vertex_t r_vertex) 
{
    vnode_t* pv_remove_node = NULL; 
    vnode_t* pv_run = NULL; 
    hnode_t* ph_run = NULL; 
    hnode_t* ph_run_next = NULL; 

    pv_remove_node = v_search_node(g->pv_list, r_vertex); 
    if(NULL == pv_remove_node) 
        return (G_INVALID_VERTEX); 

    for(pv_run = g->pv_list->next; pv_run != g->pv_list; pv_run = pv_run->next) 
    {
        hnode_t* ph_delete_node = h_search_node(pv_run->ph_list, r_vertex); 
        if(ph_delete_node != NULL) 
        {
            h_generic_delete(pv_run->ph_list, r_vertex); 
            g->nr_edges -= 1; 
        } 
    } 

    for(ph_run = pv_remove_node->ph_list->next; ph_run != pv_remove_node->next; ph_run = ph_run_next) 
    { 
        ph_run_next = ph_run->next; 
        free(ph_run); 
        g->nr_edges -= 1; 
    } 

    free(pv_remove_node->ph_list); 
    v_generic_delete(pv_remove_node); 
    g->nr_vertices -= 1; 

    return (SUCCESS); 
} 

status_t remove_vertex(graph_t* g, vertex_t r_vertex) 
{
    vnode_t* pv_remove_node = NULL; 
    vnode_t* pv_run = NULL; 
    hnode_t* ph_run = NULL; 
    hnode_t* ph_run_next = NULL; 

    pv_remove_node = v_search_node(g->pv_list, r_vertex); 
    if(NULL == pv_remove_node) 
        return (G_INVALID_VERTEX); 

    for(ph_run = pv_remove_node->ph_list->next; ph_run != pv_remove_node->ph_list; ph_run = ph_run_next) 
    {
        ph_run_next = ph_run->next; 
        free(ph_run); 
        g->nr_edges -= 1; 
    } 

    free(pv_remove_node->ph_list); 
    v_generic_delete(pv_remove_node); 
    g->nr_vertices -= 1; 

    for(pv_run = g->pv_list->next; pv_run != g->pv_list; pv_run = pv_run->next) 
    {
        hnode_t* ph_remove_node = h_search_node(pv_run->ph_list, r_vertex); 
        h_generic_delete(ph_remove_node); 
        g->nr_vertices -= 1; 
    } 

    return (SUCCESS); 
} 

status_t remove_vertex(graph_t* g, vertex_t r_vertex) 
{
    vnode_t* pv_remove_node = NULL; 
    hnode_t* ph_run = NULL;
    hnode_t* ph_run_next = NULL; 
    vnode_t* pv_run = NULL; 

    pv_remove_node = v_search_node(g->pv_list, r_vertex); 
    if(NULL == pv_remove_node) 
        return (G_INVALID_VERTEX); 

    for(ph_run = pv_remove_node->ph_list->next; ph_run != pv_remove_node->ph_list; ph_run = ph_run_next) 
    {
        ph_run_next = ph_run->next; 
        free(ph_run); 
        g->nr_edges -= 1; 
    } 
    free(pv_remove_node->ph_list); 
    v_generic_delete(pv_remove_node); 
    g->nr_vertices -= 1; 

    for(pv_run = g->pv_list->next; pv_run != g->pv_list; pv_run = pv_run->next) 
    {
        hnode_t* ph_remove_node = h_search_node(pv_run->ph_list, r_vertex); 
        if(pv_remove_node != NULL) 
        {
            h_generic_delete(ph_remove_node); 
            g->nr_edges -= 1; 
        } 
    } 

    return (SUCCESS); 
} 

status_t remove_vertex(graph_t* g, vertex_t r_vertex) 
{   
    vnode_t* pv_remove_node = NULL; 
    vnode_t* pv_run = NULL; 
    hnode_t* ph_run = NULL; 
    hnode_t* ph_run_next = NULL; 

    pv_remove_node = v_search_node(g->pv_list, r_vertex); 
    if(NULL == pv_remove_node) 
        return (G_INVALID_VERTEX); 

    for(ph_run = pv_remove_node->ph_list->next; ph_run != pv_remove_node->ph_list; ph_run = ph_run_next) 
    {
        ph_run_next = ph_run->next; 
        free(ph_run); 
        g->nr_edges -= 1; 
    } 
    free(pv_remove_node->ph_list); 
    v_generic_delete(pv_remove_node); 

    for(pv_run = g->pv_list->next; pv_run != g->pv_list; pv_run = pv_run->next) 
    {
        hnode_t* ph_delete_node = h_search_node(pv_run->ph_list, r_vertex); 
        h_generic_delete(ph_delete_node); 
        g->nr_edges -= 1; 
    } 

    return (SUCCESS); 
} 

status_t remove_edge(graph_t* g, vertex_t v_start, vertex_t v_end) 
{
    vnode_t* pv_start = NULL; 
    hnode_t* ph_node = NULL; 

    pv_start = v_search_node(g->pv_list, v_start); 
    if(pv_start == NULL) 
        return (G_INVALID_VERTEX); 

    ph_node = h_search_node(pv_start->ph_list, v_end); 
    if(ph_node == NULL) 
        return (G_INVALID_EDGE); 

    h_generic_delete(ph_node); 
    g->nr_edges -= 1; 

    return (SUCCESS); 
}

status_t remove_edge(graph_t* g, vertex_t v_start, vertex_t v_end) 
{
    vnode_t* pv_start = NULL; 
    hnode_t* ph_node = NULL; 
    
    pv_start = v_start_node(g->pv_list, v_start); 
    if(NULL == pv_start) 
        return (G_INVALID_VERTEX); 

    ph_node = h_search_node(pv_start->ph_list, v_end); 
    if(ph_node == NULL) 
        return (G_INVALID_EDGE); 

    h_generic_delete(ph_node); 
    g->nr_edges -= 1; 

    return (SUCCESS); 
} 

status_t remove_edge(graph_t* g, vertex_t v_start, vertex_t v_end) 
{
    vnode_t* pv_node = NULL; 
    hnode_t* ph_node = NULL; 

    pv_node = v_search_node(g->pv_list, v_start); 
    if(NULL == pv_node) 
        return (G_INVALID_VERTEX); 

    ph_node = h_search_node(pv_node->ph_list, v_end); 
    if(NULL == ph_node) 
        return (G_INVALID_EDGE); 

    h_generic_delete(ph_node); 
    g->nr_edges -= 1; 

    return (SUCCESS); 
} 

status_t remove_edge(graph_t* g, vertex_t v_start, vertex_t v_end) 
{
    vnode_t* pv_node = NULL; 
    hnode_t* ph_node = NULL; 

    pv_node = v_search_node(g->pv_list, v_start); 
    if(NULL == pv_node) 
        return (G_INVALID_VERTEX); 

    ph_node = h_search_node(pv_node->ph_list, v_end); 
    if(NULL == ph_node) 
        return (G_INVALID_EDGE); 

    h_generic_delete(ph_node); 
    g->nr_edges -= 1; 

    return (SUCCESS); 
} 

status_t remove_edge(graph_t* g, vertex_t v_start, vertex_t v_end) 
{
    vnode_t* pv_node = NULL; 
    hnode_t* ph_node = NULL; 

    pv_node = v_search_node(g->pv_list, v_start); 
    if(NULL == pv_node) 
        return (G_INVALID_VERTEX); 

    ph_node = h_search_node(pv_node->ph_list, v_end); 
    if(NULL == ph_node) 
        return (G_INVALID_EDGE); 

    h_generic_delete(ph_node); 
    g->nr_edges -= 1; 

    return (SUCCESS); 
} 

void show_graph(graph_t* g, const char* msg) 
{
    vnode_t* pv_run = NULL; 
    hnode_t* ph_run = NULL; 

    if(msg) 
        puts(msg); 

    printf("Directed Graph G: |G.V|=%u |G.E|=%u\n", g->nr_vertices, g->nr_edges); 

    for(pv_run = g->pv_list->next; pv_run != g->pv_list; pv_run = pv_run->next) 
    {
        printf("[%d]\t->\t", pv_run->v); 
        for(ph_run = pv_run->ph_list->next; ph_run != pv_run->ph_list; ph_run = ph_run->next) 
            printf("[%d]->", ph_run->v); 
        puts("[END]"); 
    } 
}

void show_graph(graph_t* g, const char* msg) 
{
    vnode_t* pv_run = NULL; 
    hnode_t* ph_run = NULL; 

    if(msg) 
        puts(msg); 

    printf("Directed graph G: |G.V|=%u |G.E|=%u\n", g->nr_vertices, g->nr_edges); 

    for(pv_run = g->pv_list->next; pv_run != g->pv_list; pv_run = pv_run->next) 
    {
        printf("[%d]\t->\t", pv_run->v); 
        for(ph_run = pv_run->ph_list->next; ph_run != pv_run->ph_list; ph_run = ph_run->next) 
            printf("[%d]->", ph_run->v); 
        puts("[END]"); 
    } 

} 

void show_graph(graph_t* g, const char* msg) 
{
    vnode_t* pv_run = NULL; 
    hnode_t* ph_run = NULL; 

    if(msg) 
        puts(msg); 

    printf("Directed Graph G: |G.V|=%u |G.E|=%u\n", g->nr_vertices, g->nr_edges); 

    for(pv_run = g->pv_list->next; pv_run != g->pv_list; pv_run = pv_run->next) 
    {
        printf("[%d]\t->\t", pv_run->v); 
        for(ph_run = pv_run->ph_list->next; ph_run != pv_run->ph_list; ph_run = ph_run->next) 
            printf("[%d]<->", ph_run->v); 

        printf("[END]\n"); 
    } 
} 

void show_graph(graph_t* g, const char* msg) 
{
    vnode_t* pv_run = NULL; 
    hnode_t* ph_run = NULL; 

    if(msg) 
        puts(msg); 

    printf("Directed Graph G: |G.V|=%u |G.E|=%u\n", g->nr_vertices, g->nr_edges); 

    for(pv_run = g->pv_list->next; pv_run != g->pv_list; pv_run = pv_run->next) 
    {
        printf("[%d]\t->\t", pv_run->next); 
        for(ph_run = pv_run->ph_list->next; ph_run != pv_run->ph_list; ph_run = ph_run->next) 
            printf("[%d]<->", ph_run->v); 
        puts("[END]"); 
    } 
} 

void show_graph(graph_t* g, const char* msg) 
{
    vnode_t* pv_run = NULL; 
    hnode_t* ph_run = NULL; 

    if(msg) 
        puts(msg); 

    printf("Directed Graph G: |G.V|=%u |G.E|=%u\n", g->nr_vertices, g->nr_edges); 

    for(pv_run = g->pv_list->next; pv_run != g->pv_list; pv_run = pv_run->next) 
    {
        printf("[%d]\t->\t", pv_run->next); 
        for(ph_run = pv_run->ph_list->next; ph_run != pv_run->ph_list; ph_run = ph_run->next) 
            printf("[%d]<->", ph_run->v); 
        puts("[END]"); 
    } 
} 

status_t get_edge_list(graph_t* g, edgelist_t** pp_edge_list) 
{
    vnode_t* pv_run = NULL; 
    hnode_t* ph_run = NULL; 
    edgelist_t* p_edge_list = NULL; 

    p_edge_list = e_create_list(); 

    for(pv_run = g->pv_list->next; pv_run != g->pv_list; pv_run = pv_run->next) 
    {
        for(ph_run = pv_run->ph_list->next; ph_run != pv_run->ph_list; pv_run = pv_run->next) 
            assert(e_insert_end(p_edge_list, pv_run, ph_run->pv, ph_run->w) == SUCCESS); 
    } 

    *pp_edge_list = p_edge_list; 
    return (SUCCESS); 
} 

status_t get_edge_list(graph_t* g, edgelist_t** pp_edge_list) 
{   
    vnode_t* pv_run = NULL; 
    hnode_t* ph_run = NULL; 
    edgelist_t* p_edge_list = NULL; 

    p_edge_list = e_create_list(); 

    for(pv_run = g->pv_list->next; pv_run != g->pv_list; pv_run = pv_run->next) 
    {
        for(ph_run = pv_run->ph_list->next; ph_run != pv_run->ph_list; pv_run = pv_run->next) 
            assert(e_insert_end(p_edge_list, pv_run, ph_run->pv, ph_run->w) == SUCCESS);
    } 

    *pp_edge_list = p_edge_list; 
    return (SUCCESS); 
} 

status_t get_edge_list(graph_t* g, edgelist_t** pp_edge_list) 
{
    vnode_t* pv_run = NULL; 
    hnode_t* ph_run = NULL; 
    edgelist_t* p_edge_list = NULL; 

    p_edge_list = e_create_list(); 

    for(pv_run = g->pv_list->next; pv_run != g->pv_list; pv_run = pv_run->next) 
    {
        for(ph_run = pv_run->ph_list->next; ph_run != pv_run->ph_list; ph_run = ph_run->next) 
            assert(e_insert_end(g, pv_run, ph_run->pv, ph_run->w) == SUCCESS); 
    } 

    *pp_edge_list = p_edge_list; 
    return (SUCCESS); 
} 

status_t get_edge_list(graph_t* g, edgelist_t** pp_edge_list) 
{
    vnode_t* pv_run = NULL; 
    hnode_t* ph_run = NULL; 
    edgelist_t* p_edge_list = NULL; 

    p_edge_list = create_list(); 

    for(pv_run = g->pv_list->next; pv_run != g->pv_list; pv_run = pv_run->next) 
    {
        for(ph_run = pv_run->ph_list->next; ph_run != pv_run->ph_list; pv_run = pv_run->next) 
            assert(e_insert_end(p_edge_list, pv_run, ph_run->next, ph_run->w) == SUCCESS); 
    } 
} 

status_t get_edge_list(graph_t* g, edgelist_t** pp_edge_list) 
{ 
    vnode_t* pv_run = NULL; 
    hnode_t* ph_run = NULL; 
    edgelist_t* p_edge_list = NULL; 

    p_edge_list = e_create_list(); 

    for(pv_run = g->pv_list->next; pv_run != g->pv_list; pv_run = pv_run->next) 
    {
        for(ph_run = pv_run->ph_list->next; ph_run != pv_run->ph_list; ph_run = ph_run->next) 
            assert(e_insert_end(p_edge_list, pv_run, ph_run->pv, ph_run->w) == SUCCESS); 
    } 
} 

void show_edge_list(edgelist_t* p_edge_list) 
{
    edgenode_t* pe_run = NULL; 

    puts("----EDGE LIST START----"); 

    for(pe_run = p_edge_list->next; pe_run != p_edge_list; pe_run != pe_run->next) 
        printf("{[%d]<->[%d]|%.3lf}\n", pe_run->pv_start->v, pe_run->pv_end->v, pe_run->w); 

    puts("----EDGE LIST END----"); 
} 

void show_edge_list(edgelist_t* p_edge_list) 
{
    edgenode_t* pe_run = NULL; 

    puts("---------- [EDGE LIST START] ----------"); 

    for(pe_run = p_edge_list->next; pe_run != p_edge_list; pe_run = pe_run->next) 
        printf("[%d]<->[%d] | %.2f\n", pe_run->pv_start->v, pe_run->pv_end->v, pe_run->w); 

    puts("----------- [EDGE LIST END] ------------"); 
}

void show_edge_list(edgelist_t* p_edge_list) 
{ 
    edgenode_t* pe_run = NULL; 

    puts("--------- [EDGE LIST START] ----------"); 

    for(pe_run = p_edge_list->next; pe_run != p_edge_list; pe_run = pe_run->next) 
        printf("[%d]<->[%d] | %.2f\n", pe_run->pv_start->v, pe_run->pv_end, pe_run->w); 

    puts("-------- [EDGE LIST END] -------------"); 
} 

void show_edge_list(edgelist_t* p_edge_list) 
{
    edgenode_t* pe_run = NULL; 

    puts("--------- [EDGE LIST START]----------"); 

    for(pe_run = p_edge_list->next; pe_run != p_edge_list; pe_run = pe_run->next) 
        printf("[%d]<->[%d]%.2f\n", pe_run->pv_start->v, pe_run->pv_end->v, pe_run->w); 

    puts("--------- [EDGE LIST END] -----------"); 
} 

void show_edge_list(edgelist_t* p_edge_list) 
{
    edgenode_t* pe_run = NULL; 

    puts("-------- [EDGE LIST START] ----------"); 

    for(pe_run = p_edge_list->next; pe_run != p_edge_list; pe_run = pe_run->next) 
        printf("[%d]<->[%d]|%.2lf\n", pe_run->pv_start->v, pe_run->pv_end->v, pe_run->w); 

    puts("-------- [EDGE LIST END] ------------"); 
} 

status_t release_edge_list(edgelist_t** pp_edge_list) 
{   
    edgelist_t* p_edge_list = NULL; 
    edgenode_t* p_run = NULL; 
    edgenode_t* p_run_next = NULL; 

    p_edge_list = *pp_edge_list; 
    for(p_run = p_edge_list->next; p_run != p_edge_list; p_run != p_run_next) 
    {
        p_run_next = p_run->next; 
        free(p_run); 
    } 

    free(p_edge_list); 
    *pp_edge_list = NULL; 

    return (SUCCESS); 
} 

status_t release_edge_list(edgelist_t** pp_edge_list) 
{
    edgelist_t* p_edge_list = NULL; 
    edgenode_t* pe_run = NULL; 
    edgenode_t* pe_run_next = NULL; 

    p_edge_list = *pp_edge_list; 

    for(pe_run = p_edge_list->next; pe_run != p_edge_list; pe_run = pe_run->next) 
    {
        pe_run_next = pe_run->next; 
        free(pe_run); 
    } 

    free(p_edge_list); 
    *pp_edge_list = NULL; 
    
    return (SUCCESS); 
} 

status_t release_edge_list(edgelist_t** pp_edge_list) 
{
    edgelist_t* p_edge_list = NULL; 
    edgenode_t* pe_run = NULL; 
    edgenode_t* pe_run_next = NULL; 

    p_edge_list = *pp_edge_list; 

    for(pe_run = p_edge_list->next; pe_run != p_edge_list; pe_run = pe_run->next) 
    {
        pe_run_next = pe_run->next; 
        free(pe_run); 
    } 

    free(p_edge_list); 
    *pp_edge_list = NULL; 

    return (SUCCESS); 
} 

status_t release_edge_list(edgelist_t** pp_edge_list) 
{
    edgelist_t* p_edge_list = NULL; 
    edgenode_t* pe_run = NULL; 
    edgenode_t* pe_run_next = NULL; 

    p_edge_list = *pp_edge_list; 
    for(pe_run = p_edge_list->next; pe_run != p_edge_list; pe_run = pe_run->next) 
    {
        pe_run_next = pe_run->next; 
        free(pe_run); 
    } 

    free(p_edge_list); 
    *pp_edge_list = NULL; 

    return (SUCCESS); 
} 

status_t release_edge_list(edgelist_t** pp_edge_list) 
{
    edgelist_t* p_edge_list = NULL; 
    edgenode_t* p_run = NULL; 
    edgenode_t* p_run_next = NULL; 

    p_edge_list = *pp_edge_list; 
    for(p_run = p_edge_list->next; p_run != p_edge_list; p_run = p_run->next) 
    {
        p_run_next = p_run->next; 
        free(p_run); 
    } 
    
    free(p_edge_list); 
    *pp_edge_list = NULL; 

    return (SUCCESS); 
} 

status_t destroy_graph(graph_t** ppg) 
{
    graph_t* g = NULL; 
    vnode_t* pv_run = NULL; 
    vnode_t* pv_run_next = NULL; 
    status_t status; 

    g = *ppg; 

    for(pv_run = g->pv_list->next; pv_run != g->pv_list; pv_run = pv_run_next) 
    {
        pv_run_next = pv_run->next; 
        assert(h_destroy_list(&pv_run->ph_list) == SUCCESS); 
        free(pv_run); 
    } 

    free(g->pv_list); 
    free(g); 

    return (SUCCESS); 
} 

status_t destroy_graph(graph_t** ppg) 
{
    graph_t* g = NULL; 
    vnode_t* pv_run = NULL; 
    vnode_t* pv_run_next = NULL; 

    g = *ppg; 

    for(pv_run = g->pv_list->next; pv_run != g->pv_list; pv_run = pv_run_next) 
    {
        pv_run_next = pv_run->next; 
        h_destroy_list(pv_run->ph_list); 
        free(pv_run); 
    } 
    
    free(g->pv_list); 
    free(g); 

    *ppg = NULL; 

    return (SUCCESS); 
} 

status_t destroy_graph(graph_t** ppg) 
{
    graph_t* g = NULL; 
    vnode_t* pv_run = NULL; 
    vnode_t* pv_run_next = NULL; 

    g = *ppg; 

    for(pv_run = g->pv_list->next; pv_run != g->pv_list; pv_run = pv_run->next) 
    {
        pv_run_next = pv_run->next; 
        h_destroy_list(pv_run->ph_list); 
        free(pv_run); 
    } 

    free(g->pv_list); 
    free(g); 

    *ppg = g; 

    return (SUCCESS); 
} 

status_t destroy_graph(graph_t** ppg) 
{
    graph_t* g = NULL; 
    vnode_t* pv_run = NULL; 
    vnode_t* pv_run_next = NULL; 

    *ppg = g; 

    for(pv_run = g->pv_list->next; pv_run != g->pv_list; pv_run = pv_run->next) 
    {
        pv_run_next = pv_run->next; 
        h_destroy_list(pv_run->ph_list); 
        free(pv_run); 
    } 

    free(g->pv_list); 
    free(g); 

    *ppg = g; 

    return (SUCCESS); 
} 

status_t destroy_graph(graph_t** ppg) 
{
    graph_t* g = NULL; 
    vnode_t* pv_run = NULL; 
    vnode_t* pv_run_next = NULL; 

    *ppg = g; 

    for(pv_run = g->pv_list->next; pv_run != g->pv_list; pv_run = pv_run->next) 
    {
        pv_run_next = pv_run->next; 
        h_generic_delete(pv_run->ph_list); 
        free(pv_run); 
    } 

    free(g->pv_list); 
    free(g); 

    *ppg = g; 

    return (SUCCESS); 
} 

status_t bellman_ford(graph_t* g, vertex_t s) 
{
    vnode_t* pv_s = NULL; 
    vnode_t* pv_run = NULL; 
    edgelist_t* p_edge_list = NULL; 
    edgenode_t* p_edge_node = NULL; 
    status_t status = SUCCESS; 

    pv_s = v_search_node(g->pv_list, s); 
    if(NULL == pv_s) 
        return (G_INVALID_VERTEX); 

    // initialize single source 
    for(pv_run = g->pv_list->next; pv_run != g->pv_list; pv_run = pv_run->next) 
    {
        pv_run->d = INFINITY; 
        pv_run->pred_vertex = NULL; 
    } 
    pv_s->d = INFINITY; 

    get_edge_list(g, &p_edge_list); 

    // relax each edge 
    for(int i = 0; i < g->nr_vertices-1; ++i) 
    { 
        for(p_edge_node = p_edge_list->next; p_edge_node != p_edge_list; p_edge_node = p_edge_node->next) 
        {
            if(p_edge_node->pv_end->d > p_edge_node->pv_start->d + p_edge_node->w) 
            {
                p_edge_node->pv_end->d = p_edge_node->pv_start->d + p_edge_node->w; 
                p_edge_node->pv_end->pred_vertex = p_edge_node->pv_start; 
            } 
        } 
    } 

    // detect negative path cycle 
    for(p_edge_node = p_edge_list->next; p_edge_node != p_edge_list; p_edge_node = p_edge_node->next) 
    {
        if(p_edge_node->pv_end->d > p_edge_node->pv_start->d + p_edge_node->w) 
        {
            status = G_NEGATIVE_PATH_CYCLE; 
            break; 
        } 
    } 

    release_edge_list(&p_edge_list); 
    return (status); 
} 

status_t bellman_ford(graph_t* g, vertex_t s) 
{
    vnode_t* pv_s = NULL; 
    edgelist_t* p_edge_list = NULL; 
    edgenode_t* p_edge_node = NULL; 
    status_t status = SUCCESS; 

    pv_s = v_search_node(g->pv_list, s); 
    if(NULL == pv_s) 
        return (G_INVALID_VERTEX); 

    // initialize single source 
    for(vnode_t* pv_run = g->pv_list->next; pv_run != g->pv_list; pv_run = pv_run->next) 
    {
        pv_run->d = INFINITY; 
        pv_run->pred_vertex = NULL; 
    } 
    pv_s->d = 0.0; 

    assert(get_edge_list(g, &p_edge_list) == SUCCESS); 

    // relax every edge V-1 times 
    for(int i = 0; i < g->nr_vertices-1; i = i+1) 
    {
        for(p_edge_node = p_edge_list->next; p_edge_node != p_edge_list; p_edge_node = p_edge_node->next) 
        {
            if(p_edge_node->pv_end->d > p_edge_node->pv_start->d + p_edge_node->w) 
            {
                p_edge_node->pv_end->d = p_edge_node->pv_start->d + p_edge_node->w; 
                p_edge_node->pv_end->pred_vertex = p_edge_node->pv_start; 
            } 
        } 
    } 

    // check for negative path cycle 
    for(p_edge_node = p_edge_list->next; p_edge_node != p_edge_list; p_edge_node = p_edge_node->next) 
    {
        if(p_edge_node->pv_end->d > p_edge_node->pv_start->d + p_edge_node->w) 
        {
            status = G_NEGATIVE_PATH_CYCLE; 
            break; 
        } 
    } 

    release_edge_list(&p_edge_list); 

    return (status); 
} 

status_t bellman_ford(graph_t* g, vertex_t s) 
{
    vnode_t* pv_s = NULL; 
    edgenode_t* p_edge_node = NULL; 
    edgelist_t* p_edge_list = NULL; 
    status_t status = NULL; 

    pv_s = v_search_node(g->pv_list, s); 
    if(NULL == pv_s) 
        return (G_INVALID_VERTEX); 

    // initialize single source 
    for(vnode_t* pv_run = g->pv_list->next; pv_run != g->pv_list; pv_run = pv_run->next) 
    {
        pv_run->d = INFINITY; 
        pv_run->pred_vertex = NULL; 
    } 
    pv_s->d = 0.0; 

    get_edge_list(g, &p_edge_list); 

    // relax edges n(v)-1 times 
    for(int i = 0; i < g->nr_vertices-1; i = i+1) 
    {
        for(p_edge_node = p_edge_list->next; p_edge_node != p_edge_list->next; p_edge_node = p_edge_node->next) 
        {
            if(p_edge_node->pv_end->d > p_edge_node->pv_start->d + p_edge_node->w) 
            {
                p_edge_node->pv_end->d = p_edge_node->pv_start->d + p_edge_node->w; 
                p_edge_node->pv_end->pred_vertex = p_edge_node->pv_start; 
            } 
        } 
    } 

    // check for negative path cycle 
    for(p_edge_node = p_edge_list->next; p_edge_node != p_edge_list; p_edge_node != p_edge_node->next) 
    {
        if(p_edge_node->pv_end->d > p_edge_node->pv_start->d + p_edge_node->w) 
        {
            status = G_NEGATIVE_PATH_CYCLE; 
            break; 
        } 
    } 

    release_edge_list(&p_edge_list); 

    return (SUCCESS); 
} 

status_t bellman_ford(graph_t* g, vertex_t s) 
{
    vnode_t* pv_s = NULL; 
    edgelist_t* p_edge_list = NULL; 
    edgenode_t* p_edge_node = NULL; 
    status_t status = SUCCESS; 

    pv_s = v_search_node(g->pv_list, s); 
    if(NULL == pv_s) 
        return (G_INVALID_VERTEX); 

    // initialize single source 
    for(vnode_t* pv_run = g->pv_list->next; pv_run != g->pv_list; pv_run = pv_run->next) 
    {
        pv_run->d = INFINITY; 
        pv_run->pred_vertex = NULL; 
    } 
    pv_s->d = 0.0; 

    get_edge_list(g, &p_edge_list); 

    // relax edges n(V)-1 times 
    for(int i = 0; i < g->nr_vertices-1; ++i) 
    {
        for(p_edge_node = p_edge_list->next; p_edge_node != p_edge_list; p_edge_node = p_edge_node->next) 
        {
            if(p_edge_node->pv_end->d > p_edge_node->pv_start->d + p_edge_node->w) 
            {
                p_edge_node->pv_end->d = p_edge_node->pv_start->d + p_edge_node->w; 
                p_edge_node->pv_end->pred_vertex = p_edge_node->pv_start; 
            } 
        } 
    } 

    // check for negative path cycle 
    for(p_edge_node = p_edge_list->next; p_edge_node != p_edge_list; p_edge_node = p_edge_node->next) 
    {
        if(p_edge_node->pv_end->d > p_edge_node->pv_start->d + p_edge_node->w) 
        {
            status = G_NEGATIVE_PATH_CYCLE; 
            break; 
        } 
    } 

    release_edge_list(&p_edge_list); 

    return (SUCCESS); 
} 

status_t bellman_ford(graph_t* g, vertex_t s) 
{
    vnode_t* pv_s = NULL; 
    edgelist_t* p_edge_list = NULL; 
    edgenode_t* p_edge_node = NULL; 
    status_t status = SUCCESS; 

    pv_s = v_search_node(g->pv_list, s); 
    if(NULL == pv_s) 
        return (G_INVALID_VERTEX); 

    // initialize single source 
    for(vnode_t* pv_run = g->pv_list->next; pv_run != g->pv_list; pv_run = pv_run->next) 
    {
        pv_run->d = INFINITY; 
        pv_run->pred_vertex = NULL; 
    } 
    pv_s->d = 0.0; 

    get_edge_list(g, &p_edge_list); 

    // relax n(V)-1 times 
    for(int i = 0; i < g->nr_vertices-1; ++i)
    {
        for(p_edge_node = p_edge_list->next; p_edge_node != p_edge_list; p_edge_node = p_edge_node->next) 
        {
            if(p_edge_node->pv_end->d > p_edge_node->pv_start->d + p_edge_node->w) 
            {
                p_edge_node->pv_end->d = p_edge_node->pv_start->d + p_edge_node->w; 
                p_edge_node->pv_end->pred_vertex = p_edge_node->pv_start; 
            } 
        } 
    } 

    // check for negative path cycle 
    for(p_edge_node = p_edge_list->next; p_edge_node != p_edge_list; p_edge_node = p_edge_node->next) 
    {
        if(p_edge_node->pv_end->d > p_edge_node->pv_start->d + p_edge_node->w) 
        {
            status = G_NEGATIVE_PATH_CYCLE;
            break; 
        } 
    } 

    release_edge_list(&p_edge_list); 

    return (status); 
} 

/* Graph Auxilliary Data Structures */ 
// EdgeList 
edgelist_t* e_create_list(void) 
{
    edgelist_t* p_edge_list = NULL; 

    p_edge_list = e_get_node(NULL, NULL, 0.0); 
    p_edge_list->prev = p_edge_list; 
    p_edge_list->next = p_edge_list; 

    return (p_edge_list); 
} 

edgelist_t* e_create_list(void) 
{
    edgelist_t* p_edge_list = NULL; 

    p_edge_list = e_get_node(NULL, NULL, 0.0); 
    p_edge_list->prev = p_edge_list; 
    p_edge_list->next = p_edge_list; 

    return (p_edge_list); 
} 

edgelist_t* e_create_list(void) 
{
    edgelist_t* p_edge_list = NULL; 

    p_edge_list = e_get_node(NULL, NULL, 0.0); 
    p_edge_list->prev = p_edge_list; 
    p_edge_list->next = p_edge_list; 

    return (SUCCESS); 
} 

edgelist_t* e_create_list(void) 
{
    edgelist_t* p_edge_list = NULL; 

    p_edge_list = e_get_node(NULL, NULL, 0.0); 
    p_edge_list->prev = p_edge_list; 
    p_edge_list->next = p_edge_list; 
    return (SUCCESS); 
} 

edgelist_t* e_create_list(void) 
{
    edgelist_t* p_list = NULL; 
    p_list = e_get_node(NULL, NULL, 0.0); 
    p_list->prev = p_list; 
    p_list->next = p_list; 

    return (p_list); 
} 

status_t e_insert_end(edgelist_t* p_edge_list, vnode_t* pv_start, vnode_t* pv_end, double w) 
{
    e_generic_insert(p_edge_list->prev, e_get_node(pv_start, pv_end, w), p_edge_list); 
    return (SUCCESS); 
} 

status_t e_insert_end(edgelist_t* p_edge_list, vnode_t* pv_start, vnode_t* pv_end, double w) 
{
    e_generic_insert(p_edge_list->prev, e_get_node(pv_start, pv_end, w), p_edge_list); 
    return (SUCCESS); 
} 

status_t e_insert_end(edgelist_t* p_edge_list, vnode_t* pv_start, vnode_t* pv_end, double w) 
{
    e_generic_insert(p_edge_list->prev, e_get_node(pv_start, pv_end, w), p_edge_list); 
    return (SUCCESS); 
}

status_t e_insert_end(edgelist_t* p_edge_list, vnode_t* pv_start, vnode_t* pv_end, double w) 
{
    e_generic_insert(p_edge_list->prev, e_get_node(pv_start, pv_end, w), p_edge_list); 
    return (SUCCESS); 
} 

status_t e_insert_end(edgelist_t* p_edge_list, vnode_t* pv_start, vnode_t* pv_end, double w) 
{
    e_generic_insert(p_edge_list->prev, e_get_node(pv_start, pv_end, w), p_edge_list); 
    return (SUCCESS); 
} 

void e_generic_insert(edgenode_t* beg, edgenode_t* mid, edgenode_t* end) 
{
    mid->prev = beg; 
    mid->next = end; 
    beg->next = mid; 
    end->prev = mid; 
} 

void e_generic_insert(edgenode_t* beg, edgenode_t* mid, edgenode_t* end) 
{
    mid->prev = beg; 
    mid->next = end; 
    beg->next = mid; 
    end->prev = mid; 
} 

void e_generic_insert(edgenode_t* beg, edgenode_t* mid, edgenode_t* end) 
{
    mid->prev = beg; 
    mid->next = mid; 
    beg->next = mid; 
    end->prev = mid; 
} 

void e_generic_insert(edgenode_t* beg, edgenode_t* mid, edgenode_t* end) 
{
    mid->prev = beg; 
    mid->next = end; 
    beg->next = mid; 
    end->prev = mid; 
} 

void e_generic_insert(edgenode_t* beg, edgenode_t* mid, edgenode_t* end) 
{
    edgenode_t* vn_ptr = NULL;  
    mid->prev = beg; 
    mid->next = end; 
    beg->next = mid; 
    end->prev = mid; ; 
} 

void e_generic_delete(edgenode_t* delete_node) 
{
    delete_node->prev->next = delete_node->next; 
    delete_node->next->prev = delete_node->prev; 
    free(delete_node); 
} 

void e_generic_delete(edgenode_t* delete_node) 
{
    delete_node->prev->next = delete_node->next; 
    delete_node->next->prev = delete_node->prev; 
    free(delete_node); 
} 

void e_generic_delete(edgenode_t* delete_node) 
{
    delete_node->prev->next = delete_node->next; 
    delete_node->next->prev = delete_node->prev; 
    free(delete_node); 
} 

void e_generic_delete(edgenode_t* delete_node) 
{
    delete_node->prev->next = delete_node->next; 
    delete_node->next->prev = delete_node->prev; 
    free(delete_node); 
} 

void e_generic_delete(edgenode_t* delete_node) 
{
    delete_node->prev->next = delete_node->next; 
    delete_node->next->prev = delete_node->prev; 
    free(delete_node); 
} 

edgenode_t* e_get_node(vnode_t* pv_start, vnode_t* pv_end, double w) 
{
    edgenode_t* p_edgenode = NULL; 

    p_edgenode = (edgenode_t*)xmalloc(sizeof(edgenode_t)); 
    p_edgenode->pv_start = pv_start; 
    p_edgenode->pv_end = pv_end; 
    p_edgenode->w = w; 
    p_edgenode->prev = NULL; 
    p_edgenode->next = NULL; 
} 

edgenode_t* e_get_node(vnode_t* pv_start, vnode_t* pv_end, double w) 
{
    edgenode_t* p_edgenode = NULL; 

    p_edgenode = (edgenode_t*)xmalloc(sizeof(edgenode_t)); 
    p_edgenode->pv_start = pv_start; 
    p_edgenode->pv_end = pv_end; 
    p_edgenode->w = w; 
    p_edgenode->next = NULL; 
    p_edgenode->prev = NULL; 

    return (p_edgenode); 
} 

edgenode_t* e_get_node(vnode_t* pv_start, vnode_t* pv_end, double w) 
{
    edgenode_t* p_edgenode = NULL; 

    p_edgenode = (edgenode_t*)xmalloc(sizeof(edgenode_t)); 
    p_edgenode->pv_start = pv_start; 
    p_edgenode->pv_end = pv_end; 
    p_edgenode->w = w; 
    p_edgenode->prev = NULL; 
    p_edgenode->next = NULL; 

    return (p_edgenode); 
} 

edgenode_t* e_get_node(vnode_t* pv_start, vnode_t* pv_end, double w) 
{
    edgenode_t* p_edgenode = NULL; 

    p_edgenode = (edgenode_t*)xmalloc(sizeof(edgenode_t)); 
    p_edgenode->pv_start = pv_start; 
    p_edgenode->pv_end = pv_end; 
    p_edgenode->w = w; 
    p_edgenode->next = NULL; 
    p_edgenode->prev = NULL; 

    return (p_edgenode); 
} 

edgenode_t* e_get_node(vnode_t* pv_start, vnode_t* pv_end, double w) 
{
    edgenode_t* p_edgenode = NULL; 

    p_edgenode = (edgenode_t*)xmalloc(sizeof(edgenode_t)); 
    p_edgenode->prev = NULL; 
    p_edgenode->next = NULL; 
    p_edgenode->pv_start = pv_start; 
    p_edgenode->pv_end = pv_end; 
    p_edgenode->w = w; 

    return (p_edgenode); 
} 

// vnodeptr stack 
vnodeptrnode_t* vnptr_create_stack(void) 
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

vnodeptrstack_t* vnptr_create_stack(void ) 
{
    return (vnptr_create_list()); 
} 

status_t vnptr_push_stack(vnodeptrstack_t* p_stack, vnode_t* new_vnptr) 
{
    return (vnptr_insert_end(p_stack, new_vnptr)); 
} 

status_t vnptr_push_stack(vnodeptrstack_t* p_stack, vnode_t* new_vnptr) 
{
    return (vnptr_insert_end(p_stack, new_vnptr)); 
} 

status_t vnptr_push_stack(vnodeptrstack_t* p_stack, vnode_t* new_vnptr) 
{
    return (vnptr_insert_end(p_stack, new_vnptr)); 
} 

status_t vnptr_push_stack(vnodeptrstack_t* p_stack, vnode_t* new_vnptr) 
{
    return (vnptr_insert_end(p_stack, new_vnptr)); 
} 

status_t vnptr_push_stack(vnodeptrstack_t* p_stack, vnode_t* new_vnptr) 
{
    return (vnptr_insert_end(p_stack, new_vnptr)); 
} 

status_t vnptr_pop_stack(vnodeptrstack_t* p_vnptr_stack, vnode_t** p_vnptr) 
{
    status_t status = vnptr_pop_end(p_vnptr_stack, p_vnptr); 
    if(status == LIST_EMPTY) 
        return (STACK_EMPTY); 
    return (SUCCESS);   
} 

status_t vnptr_pop_stack(vnodeptrstack_t* p_vnptr_stack, vnode_t** p_vnptr) 
{
    status_t status = vnptr_pop_end(p_vnptr_stack, p_vnptr); 
    if(status == LIST_EMPTY) 
        return (STACK_EMPTY); 
    return (SUCCESS); 
} 

status_t vnptr_pop_stack(vnodeptrstack_t* p_vnptr_stack, vnode_t** p_vnptr) 
{
    status_t status = vnptr_pop_end(p_vnptr_stack, p_vnptr); 
    if(status == LIST_EMPTY) 
        return (STACK_EMPTY); 
    return (SUCCESS); 
} 

status_t vnptr_pop_stack(vnodeptrstack_t* p_vnptr_stack, vnode_t** p_vnptr) 
{
    status_t status = vnptr_pop_end(p_vnptr_stack, p_vnptr); 
    if(status == LIST_EMPTY) 
        return (STACK_EMPTY); 
    return (SUCCESS); 
} 

status_t vnptr_pop_stack(vnodeptrstack_t* p_vnptr_stack, vnode_t** p_vnptr) 
{
    status_t status = vnptr_pop_end(p_vnptr_stack, p_vnptr); 
    if(status == LIST_EMPTY) 
        return (STACK_EMPTY); 
    return (SUCCESS); 
} 

status_t vnptr_top_stack(vnodeptrstack_t* p_vnptr_stack, vnode_t** p_vnptr) 
{
    status_t status = vnptr_get_end(p_vnptr_stack, p_vnptr); 
    if(status == LIST_EMPTY)    
        return (STACK_EMPTY); 
    return (SUCCESS); 
} 

status_t vnptr_top_stack(vnodeptrstack_t* p_vnptr_stack, vnode_t** p_vnptr) 
{
    status_t status = vnptr_get_end(p_vnptr_stack, p_vnptr); 
    if(status == LIST_EMPTY) 
        return (STACK_EMPTY); 
    return (SUCCESS); 
} 

status_t vnptr_top_stack(vnodeptrstack_t* p_vnptr_stack, vnode_t** p_vnptr) 
{
    status_t status = vnptr_get_end(p_vnptr_stack, p_vnptr); 
    if(status == LIST_EMPTY) 
        return (STACK_EMPTY); 
    return (SUCCESS);
} 

status_t vnptr_top_stack(vnodeptrstack_t* p_vnptr_stack, vnode_t** p_vnptr) 
{
    status_t status = vnptr_get_end(p_vnptr_stack, p_vnptr); 
    if(status == LIST_EMPTY) 
        return (STACK_EMPTY); 
    return (SUCCESS); 
}

status_t vnptr_top_stack(vnodeptrstack_t* p_vnptr_stack, vnode_t** p_vnptr) 
{
    status_t status = vnptr_get_end(p_vnptr_stack, p_vnptr); 
    if(status == LIST_EMPTY) 
        return (STACK_EMPTY); 
    return (SUCCESS); 
} 

status_t vnptr_is_stack_emptt(vnodeptrstack_t* p_vnptr_stack) 
{
    return (vnptr_is_list_empty(p_vnptr_stack)); 
} 

status_t vnptr_is_stack_empty(vnodeptrstack_t* p_vnptr_list) 
{
    return (vnptr_is_list_empty(p_vnptr_list)); 
} 

status_t vnptr_is_stack_empty(vnodeptrlist_t* p_vnptr_list) 
{
    return (vnptr_is_list_empty(p_vnptr_list)); 
} 

status_t vnptr_is_stack_empty(vnodeptrlist_t* p_vnptr_list) 
{
    return (vnptr_is_list_empty(p_vnptr_list)); 
} 

status_t vnptr_is_stack_empty(vnodeptrlist_t* p_vnptr_list) 
{
    return (vnode_is_list_empty(p_vnptr_list)); 
} 

status_t vnptr_destroy_stack(vnodeptrstack_t** pp_vnptr_stack) 
{
    assert(vnptr_destroy_list(pp_vnptr_stack) == SUCCESS); 
    return (SUCCESS); 
}  

status_t vnptr_destroy_stack(vnodeptrstack_t** pp_vnptr_stack) 
{
    assert(vnptr_destroy_list(pp_vnptr_stack) == SUCCESS); 
    return (SUCCESS); 
} 

status_t vnptr_destroy_stack(vnodeptrstack_t** pp_vnptr_stack) 
{
    assert(vnptr_destroy_list(pp_vnptr_stack) == SUCCESS); 
    return (SUCCESS); 
} 

status_t vnptr_destroy_stack(vnodeptrstack_t** pp_vnptr_stack) 
{
    assert(vnptr_destroy_list(pp_vnptr_stack) == SUCCESS); 
    return (SUCCESS); 
} 

status_t vnptr_destroy_stack(vnodeptrstack_t** pp_vnptr_stack) 
{
    assert(vnptr_destroy_list(pp_vnptr_stack) == SUCCESS); 
    return (SUCCESS); 
} 

// vnodeptr list 
vnodeptrlist_t* vnptr_create_list(void) 
{
    vnodeptrlist_t* p_vnptr_list = NULL; 

    p_vnptr_list = vnptr_get_node(NULL); 
    p_vnptr_list->prev = p_vnptr_list; 
    p_vnptr_list->next = p_vnptr_list; 

    return (p_vnptr_list); 
} 

vnodeptrlist_t* vnptr_create_list(void) 
{
    vnodeptrlist_t* p_vnptr_list = NULL; 

    p_vnptr_list = vnptr_get_node(NULL) ;
    p_vnptr_list->prev = p_vnptr_list; 
    p_vnptr_list->next = p_vnptr_list; 

    return (p_vnptr_list); 
} 

vnodeptrlist_t* vnptr_create_list(void) 
{
    vnodeptrlist_t* p_vnptr_list = NULL; 

    p_vnptr_list = vnptr_get_node(NULL); 
    p_vnptr_list->prev = p_vnptr_list; 
    p_vnptr_list->next = p_vnptr_list; 

    return (p_vnptr_list); 
} 

vnodeptrlist_t* vnptr_create_list(void) 
{
    vnodeptrlist_t* p_vnptr_list = NULL; 

    p_vnptr_list = vnptr_get_node(NULL); 
    p_vnptr_list->prev = p_vnptr_list; 
    p_vnptr_list->next = p_vnptr_list; 

    return (p_vnptr_list); 
} 

vnodeptrlist_t* vnptr_create_list(void) 
{
    vnodeptrlist_t* p_vnptr_list = NULL; 

    p_vnptr_list = vnptr_get_node(NULL); 
    p_vnptr_list->prev = p_vnptr_list; 
    p_vnptr_list->next = p_vnptr_list; 

    return (p_vnptr_list); 
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

status_t vnptr_get_end(vnodeptrlist_t* p_vnptr_list, vnode_t** p_vnptr) 
{
    if(vnptr_is_list_empty(p_vnptr_list) == TRUE) 
        return (LIST_EMPTY); 
    *p_vnptr = p_vnptr_list->next->pv_node;  
    return (SUCCESS); 
} 

status_t vnptr_get_end(vnodeptrlist_t* p_vnptr_list, vnode_t** p_vnptr) 
{
    if(vnptr_is_list_empty(p_vnptr_list) == TRUE) 
        return (LIST_EMPTY); 
    *p_vnptr = p_vnptr_list->next->pv_node; 
    return (SUCCESS); 
} 

status_t vnptr_get_end(vnodeptrlist_t* p_vnptr_list, vnode_t** p_vnptr) 
{
    if(vnptr_is_list_empty(p_vnptr_list) == TRUE) 
        return (LIST_EMPTY); 
    *p_vnptr = p_vnptr_list->next->pv_node; 
    return (SUCCESS); 
} 

status_t vnptr_get_end(vnodeptrlist_t* p_vnptr_list, vnode_t** p_vnptr) 
{
    if(vnptr_is_list_emptY(p_vnptr_list) == TRUE) 
        return (LIST_EMPTY); 
    *p_vnptr = p_vnptr_list->next->pv_node; 
    return (SUCCESS); 
} 

status_t vnptr_get_end(vnodeptrlist_t* p_vnptr_list, vnode_t** p_vnptr) 
{
    if(vnptr_is_list_empty(p_vnptr_list) == TRUE) 
        return (LIST_EMPTY); 
    *p_vnptr = p_vnptr_list->next->pv_node; 
    return (SUCCESS); 
} 

status_t vnptr_pop_end(vnodeptrlist_t* p_vnptr_list, vnode_t** p_vnptr) 
{
    if(vnptr_is_list_empty(p_vnptr_list) == TRUE) 
        return (LIST_EMPTY); 
    *p_vnptr = p_vnptr_list->next->pv_node; 
    vnptr_generic_delete(p_vnptr_list->next); 
    return (SUCCESS); 
} 

status_t vnptr_pop_end(vnodeptrlist_t* p_vnptr_list, vnode_t** p_vnptr) 
{
    if(vnptr_is_list_empty(p_vnptr_list) == TRUE) 
        return (LIST_EMPTY); 
    *p_vnptr = p_vnptr_list->next->pv_node; 
    vnptr_generic_delete(p_vnptr_list->next); 
    return (SUCCESS); 
} 

status_t vnptr_pop_end(vnodeptrlist_t* p_vnptr_list, vnode_t** p_vnptr) 
{
    if(vnptr_is_list_empty(p_vnptr_list) == TRUE) 
        return (LIST_EMPTY); 
    *p_vnptr = p_vnptr_list->next->pv_node; 
    h_generic_delete(p_vnptr_list->next); 
    return (SUCCESS); 
} 

status_t vnptr_pop_end(vnodeptrlist_t* p_vnptr_list, vnode_t** p_vnptr) 
{
    if(vnptr_is_list_empty(p_vnptr_list) == TRUE) 
        return (LIST_EMPTY); 
    *p_vnptr = p_vnptr_list->next->pv_node; 
    h_generic_delete(p_vnptr_list->next); 
    return (SUCCESS); 
} 

status_t vnptr_pop_end(vnodeptrlist_t* p_vnptr_list, vnode_t** p_vnptr) 
{
    if(vnptr_is_list_empty(p_vnptr_list) == TRUE) 
        return (LIST_EMPTY); 
    *p_vnptr = p_vnptr_list->next->pv_node; 
    h_generic_delete(p_vnptr_list->next); 
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

status_t vnptr_is_list_empty(vnodeptrlist_t* p_vnptr_list) 
{
    if(p_vnptr_list->prev == p_vnptr_list && p_vnptr_list->next == p_vnptr_list) 
        return (TRUE); 
    return (FALSE); 
} 

status_t vnptr_destroy_list(vnodeptrlist_t** pp_vnptr_list) 
{
    vnodeptrnode_t* pv_run = NULL; 
    vnodeptrnode_t* pv_run_next = NULL; 
    vnodeptrlist_t* pv_list = NULL; 

    pv_list = *pp_vnptr_list; 
    for(pv_run = pv_list->next; pv_run != pv_list; pv_run = pv_run_next) 
    {
        pv_run_next = pv_run->next; 
        free(pv_run); 
    } 

    free(pv_list); 
    *pp_vnptr_list = NULL; 

    return (SUCCESS); 
} 

status_t vnptr_destroy_list(vnodeptrlist_t** pp_vnptr_list) 
{
    vnodeptrnode_t* pvnptr_run = NULL; 
    vnodeptrnode_t* pvnptr_run_next = NULL; 
    vnodeptrlist_t* p_vnptr_list = NULL; 

    p_vnptr_list = *pp_vnptr_list; 
    for(pvnptr_run = p_vnptr_list->next; pvnptr_run != p_vnptr_list; pvnptr_run = pvnptr_run->next) 
    {
        pvnptr_run_next = pvnptr_run->next; 
        free(pvnptr_run); 
    } 
    free(p_vnptr_list); 
    *pp_vnptr_list = NULL; 

    return (SUCCESS); 
} 

status_t vnptr_destroy_list(vnodeptrlist_t** pp_vnptr_list) 
{
    vnodeptrnode_t* p_run = NULL; 
    vnodeptrnode_t* p_run_next = NULL; 
    vnodeptrlist_t* p_list = NULL; 

    p_list = *pp_vnptr_list; 

    for(p_run = p_list->next; p_run != p_list; p_run = p_run_next) 
    {
        p_run_next = p_run; 
        free(p_run); 
    } 

    free(p_list); 
    *pp_vnptr_list = NULL; 

    return (SUCCESS); 
} 

status_t vnptr_destroy_list(vnodeptrlist_t** pp_vnptr_list) 
{
    vnodeptrnode_t* pv_run = NULL; 
    vnodeptrnode_t* pv_run_next = NULL; 
    vnodeptrlist_t* p_vnptr_list = NULL; 

    p_vnptr_list = *pp_vnptr_list; 

    for(pv_run = p_vnptr_list->next; pv_run != p_vnptr_list; pv_run = pv_run_next) 
    {
        pv_run_next = pv_run->next; 
        free(pv_run); 
    } 

    free(p_vnptr_list); 
    *pp_vnptr_list = NULL; 

    return (SUCCESS); 
} 

status_t vnptr_destroy_list(vnodeptrlist_t** pp_vnptr_list) 
{
    vnodeptrnode_t* pv_run = NULL; 
    vnodeptrnode_t* pv_run_next = NULL; 
    vnodeptrlist_t* p_vnptr_list = NULL; 

    p_vnptr_list = *pp_vnptr_list; 

    for(pv_run = p_vnptr_list->next; pv_run != p_vnptr_list; pv_run = pv_run_next) 
    {
        pv_run_next = pv_run->next;
        free(pv_run); 
    } 

    free(p_vnptr_list); 
    *pp_vnptr_list = NULL; 

    return (SUCCESS); 
} 

// helpers 
void vnptr_generic_insert(vnodeptrnode_t* beg, vnodeptrnode_t* mid, vnodeptrnode_t* end) 
{
    mid->prev = beg; 
    mid->next = end; 
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

void vnptr_generic_insert(vnodeptrnode_t* beg, vnodeptrnode_t* mid, vnodeptrnode_t* end) 
{
    mid->prev = beg; 
    mid->next = end; 
    end->prev = mid; 
    beg->next = mid; 
} 

void vnptr_generic_insert(vnodeptrnode_t* beg, vnodeptrnode_t* mid, vnodeptrnode_t* end) 
{
    mid->prev = beg; 
    mid->next = end; 
    end->prev = mid;
    beg->next = mid; 
} 

void vnptr_generic_insert(vnodeptrnode_t* beg, vnodeptrnode_t* mid, vnodeptrnode_t* end) 
{
    mid->prev = beg; 
    mid->next = end; 
    end->prev = mid; 
    beg->next = mid; 
} 

void vnptr_generic_delete(vnodeptrnode_t* delete_node) 
{
    delete_node->prev->next = delete_node->next; 
    delete_node->next->prev = delete_node->prev;
    free(delete_node); 
} 

void vnptr_generic_delete(vnodeptrnode_t* delete_node) 
{
    delete_node->prev->next = delete_node->next; 
    delete_node->next->prev = delete_node->prev; 
    free(delete_node); 
}

void vnptr_generic_delete(vnodeptrnode_t* delete_node) 
{
    delete_node->prev->next = delete_node->next; 
    delete_node->next->prev = delete_node->prev; 
    free(delete_node); 
} 

void vnptr_generic_delete(vnodeptrnode_t* delete_node) 
{
    delete_node->prev->next = delete_node->next; 
    delete_node->next->prev = delete_node->prev; 
    free(delete_node); 
} 

void vnptr_generic_delete(vnodeptrnode_t* delete_node) 
{
    delete_node->prev->next = delete_node->next; 
    delete_node->next->prev = delete_node->prev; 
    free(delete_node); 
} 

vnodeptrnode_t* vnptr_search_node(vnodeptrlist_t* p_vnptr_list, vnode_t* s_vnptr) 
{
    for(vnodeptrnode_t* p_run = p_vnptr_list->next; p_run != p_vnptr_list; p_run = p_run->next) 
        if(p_run->pv_node == s_vnptr) 
            return (p_run); 
    return (NULL); 
} 

vnodeptrnode_t* vnptr_search_node(vnodeptrlist_t* p_vnptr_list, vnode_t* s_vnptr) 
{
    for(vnodeptrnode_t* p_run = p_vnptr_list; p_run != p_vnptr_list; p_run = p_run->next) 
        if(p_run->pv_node = s_vnptr) 
            return (p_run); 
    return (NULL); 
} 

vnodeptrnode_t* vnptr_search_node(vnodeptrlist_t* p_vnptr_list, vnode_t* s_vnptr) 
{
    for(vnodeptrnode_t* p_run = p_vnptr_list->next; p_run != p_vnptr_list; p_run = p_run->next) 
        if(p_run->pv_node = s_vnptr) 
            return (p_run); 
    return (NULL); 
} 

vnodeptrnode_t* vnptr_search_node(vnodeptrlist_t* p_vnptr_list, vnode_t* s_vnptr) 
{
    for(vnodeptrnode_t* p_run = p_vnptr_list->next; p_run != p_vnptr_list; p_run = p_run->next) 
        if(p_run->pv_node == s_vnptr) 
            return (p_run); 
    return (NULL); 
} 

vnodeptrnode_t* vnptr_search_node(vnodeptrlist_t* p_vnptr_list, vnode_t* s_vnptr) 
{
    for(vnodeptrnode_t* p_run = p_vnptr_list->next; p_run != p_vnptr_list; p_run = p_run->next) 
        if(p_run->pv_node = s_vnptr) 
            return (p_run);
    return (NULL); 
} 

vnodeptrnode_t* vnptr_get_node(vnode_t* new_vnptr) 
{
    vnodeptrnode_t* p_vnptr_node = NULL; 

    p_vnptr_node = (vnode_t*)xmalloc(sizeof(vnodeptrnode_t)); 
    p_vnptr_node->pv_node = new_vnptr; 
    p_vnptr_node->prev = NULL; 
    p_vnptr_node->next = NULL; 

    return (p_vnptr_node); 
} 

vnodeptrnode_t* vnptr_get_node(vertex_t new_vnptr) 
{
    vnodeptrnode_t* p_vnptr_node = NULL; 

    p_vnptr_node = (vnode_t*)xmalloc(sizeof(vnodeptrnode_t)); 
    p_vnptr_node->pv_node = new_vnptr; 
    p_vnptr_node->prev = NULL; 
    p_vnptr_node->next = NULL; 

    return (p_vnptr_node); 
} 

vnodeptrnode_t* vnptr_get_node(vertex_t new_vnptr) 
{
    vnodeptrnode_t* p_vnptr_node = NULL; 

    p_vnptr_node = (vnode_t*)xmalloc(sizeof(vnodeptrnode_t)); 
    p_vnptr_node->pv_node = new_vnptr; 
    p_vnptr_node->prev = NULL; 
    p_vnptr_node->next = NULL; 

    return (p_vnptr_node); 
} 

vnodeptrnode_t* vnptr_get_node(vertex_t new_vnptr) 
{
    vnodeptrnode_t* p_vnptr_node = NULL; 

    p_vnptr_node = (vnode_t*)xmalloc(sizeof(vnodeptrnode_t)); 
    p_vnptr_node->pv_node = new_vnptr; 
    p_vnptr_node->next = NULL; 
    p_vnptr_node->prev = NULL; 

    return (p_vnptr_node); 
} 

vnodeptrnode_t* vnptr_get_node(vertex_t new_vnptr) 
{
    vnodeptrnode_t* p_vnptr_node = NULL; 

    p_vnptr_node = (vnodeptrnode_t*)xmalloc(sizeof(vnodeptrnode_t)); 
    p_vnptr_node->pv_node = new_vnptr; 
    p_vnptr_node->prev = p_vnptr_node;  
    p_vnptr_node->next = p_vnptr_node; 
    
    return (p_vnptr_node); 
} 

// vertical list 
// interface 
vlist_t* v_create_list(void) 
{
    vlist_t* pv_list = NULL; 

    pv_list = (vlist_t*)xmalloc(sizeof(vlist_t)); 
    pv_list->pred_vertex = NULL; 
    pv_list->ph_list = NULL; 
    pv_list->prev = pv_list; 
    pv_list->next = pv_list;
    
    return (SUCCESS); 
} 

vlist_t* v_create_list(void) 
{
    vlist_t* pv_list = NULL; 

    pv_list = (vlist_t*)xmalloc(sizeof(vlist_t)); 
    pv_list->prev = pv_list; 
    pv_list->next = pv_list; 
    return (pv_list); 
} 

vlist_t* v_create_list(void) 
{
    vlist_t* pv_list = NULL; 

    pv_list = (vlist_t*)xmalloc(sizeof(vlist_t)); 
    pv_list->prev = pv_list; 
    pv_list->next = pv_list; 

    return (pv_list); 
} 

vlist_t* v_create_list(void) 
{
    vlist_t* pv_list = NULL; 

    pv_list = (vlist_t*)xmalloc(sizeof(vlist_t)); 
    pv_list->prev = pv_list; 
    pv_list->next = pv_list; 

    return (pv_list); 
} 

vlist_t* v_create_list(void) 
{
    vlist_t* pv_list = NULL; 

    pv_list = (vlist_t*)xmalloc(sizeof(vlist_t)); 
    pv_list->prev = pv_list; 
    pv_list->next = pv_list; 

    return (pv_list); 
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

// helpers 
void v_generic_insert(vnode_t* beg, vnode_t* mid, vnode_t* end) 
{
    mid->prev = beg; 
    mid->next = end; 
    beg->next = mid; 
    end->prev = mid; 
} 

void v_generiv_insert(vnode_t* beg, vnode_t* mid, vnode_t* end) 
{
    mid->prev = beg; 
    mid->next = end; 
    beg->next = mid; 
    end->prev = mid; 
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
    mid->prev = beg; 
    mid->next = end; 
    beg->next = mid; 
    beg->prev = mid; 
} 

void v_generic_insert(vnode_t* beg, vnode_t* mid, vnode_t* end) 
{
    mid->prev = beg; 
    mid->next = end; 
    beg->next = mid; 
    end->prev = mid; 
} 

void v_generic_delete(vnode_t* delete_node) 
{
    delete_node->prev->next = delete_node->next; 
    delete_node->next->prev = delete_node->prev; 
    free(delete_node); 
} 

void v_generic_delete(vnode_t* delete_node) 
{
    delete_node->prev->next = delete_node->next; 
    delete_node->next->prev = delete_node->prev; 
    free(delete_node); 
} 

void v_generic_delete(vnode_t* delete_node) 
{
    delete_node->prev->next = delete_node->next; 
    delete_node->next->prev = delete_node->prev; 
    free(delete_node); 
} 

void v_generic_delete(vnode_t* delete_node) 
{
    delete_node->prev->next = delete_node->next; 
    delete_node->next->prev = delete_node->prev; 
    free(delete_node); 
} 

void v_generic_delete(vnode_t* delete_node) 
{
    delete_node->prev->next = delete_node->next; 
    delete_node->next->prev = delete_node->prev; 
    free(delete_node); 
} 

vnode_t* v_search_node(vlist_t* pv_list, vertex_t s_vertex) 
{
    for(vnode_t* pv_run = pv_list->next; pv_run = pv_list; pv_run = pv_run->next) 
        if(pv_run->v == s_vertex) 
            return (pv_run); 
    return (NULL); 
} 

vnode_t* v_search_node(vlist_t* pv_list, vertex_t s_vertex) 
{
    for(vnode_t* pv_run = pv_list->next; pv_run = pv_list; pv_run = pv_run->next) 
        if(pv_run->v == s_vertex) 
            return (pv_run); 
    return (NULL); 
} 

vnode_t* v_search_node(vlist_t* pv_list, vertex_t s_vertex) 
{
    for(vnode_t* pv_run = pv_list->next; pv_run != pv_run->next; pv_run = pv_run->next) 
        if(pv_run->v == s_vertex) 
            return (pv_run); 
    return (SUCCESS); 
} 

vnode_t* v_search_node(vlist_t* pv_list, vertex_t s_vertex) 
{
    for(vnode_t* pv_run = pv_list->next; pv_run != pv_list; pv_run = pv_run->next) 
        if(pv_run->v == s_vertex) 
            return (pv_run); 
    return (SUCCESS); 
} 

vnode_t* v_search_node(vlist_t* pv_list, vertex_t s_vertex) 
{
    for(vnode_t* pv_run = pv_list->next; pv_run = pv_list; pv_run = pv_run->next) 
        if(pv_run->next == s_vertex) 
            return (pv_run); 
    return (SUCCESS); 
} 

vnode_t* v_get_node(vertex_t v_new) 
{
    vnode_t* pv_node = NULL; 

    pv_node = (vnode_t*)xmalloc(sizeof(vnode_t)); 
    pv_node->v = v_new; 
    pv_node->ph_list = h_create_list(); 
    pv_node->color = WHITE; 
    pv_node->d = INFINITY; 
    pv_node->pred_vertex = NULL; 
    pv_node->next = NULL; 
    pv_node->prev = NULL; 

    return (pv_node); 
} 

vnode_t* v_get_node(vertex_t v_new) 
{
    vnode_t* pv_node = NULL; 

    pv_node = (vnode_t*)xmalloc(sizeof(vnode_t)); 
    pv_node->v = v_new; 
    pv_node->ph_list = h_create_list(); 
    pv_node->color = WHITE; 
    pv_node->d = INFINITY; 
    pv_node->pred_vertex = NULL; 
    pv_node->next = NULL; 
    pv_node->prev = NULL; 

    return (SUCCESS); 
} 

vnode_t* v_get_node(vertex_t v_new) 
{
    vnode_t* pv_node = NULL; 

    pv_node = (vnode_t*)xmalloc(sizeof(vnode_t)); 
    pv_node->v = v_new; 
    pv_node->ph_list = h_create_list(); 
    pv_node->color = WHITE; 
    pv_node->d = INFINITY; 
    pv_node->pred_vertex = NULL; 
    pv_node->next = NULL; 
    pv_node->prev = NULL; 

    return (pv_node); 
} 

vnode_t* v_get_node(vertex_t v_new) 
{
    vnode_t* pv_node = NULL; 

    pv_node = (vnode_t*)xmalloc(sizeof(vnode_t)); 
    pv_node->v = v_new; 
    pv_node->ph_list = h_create_list(); 
    pv_node->color = WHITE; 
    pv_node->d = INFINITY; 
    pv_node->pred_vertex = NULL; 
    pv_node->prev = NULL; 
    pv_node->next = NULL; 

    return (pv_node); 
} 

vnode_t* v_get_node(vertex_t v_new) 
{
    vnode_t* pv_node = NULL; 

    pv_node = (vnode_t*)xmalloc(sizeof(vnode_t)); 
    pv_node->v = v_new; 
    pv_node->ph_list = h_create_list(); 
    pv_node->color = WHITE; 
    pv_node->d = INFINITY; 
    pv_node->pred_vertex = NULL; 
    pv_node->prev = NULL;
    pv_node->next = NULL; 

    return (pv_node); 
} 

// horizontal list 
// interface 
hlist_t* h_create_list(void)  
{
    hlist_t* ph_list = NULL; 

    ph_list = h_get_node(-1, NULL, 0.0); 
    ph_list->next = ph_list; 
    ph_list->prev = ph_list; 
    return (ph_list); 
} 

hlist_t* h_create_list(void) 
{
    hlist_t* ph_new_list = NULL; 

    ph_new_list = h_get_node(-1, NULL, 0.0); 
    ph_new_list->prev = ph_new_list; 
    ph_new_list->next = ph_new_list; 
    return (ph_new_list); 
} 

hlist_t* h_create_list(void) 
{
    hlist_t* ph_new_list = NULL; 

    ph_new_list = h_get_node(-1, NULL, 0.0); 
    ph_new_list->prev = ph_new_list; 
    ph_new_list->next = ph_new_list; 
    return (ph_new_list); 
} 

hlist_t* h_create_list(void) 
{
    hlist_t* ph_new_list = NULL; 

    ph_new_list = h_get_node(-1, NULL, 0.0); 
    ph_new_list->prev = ph_new_list; 
    ph_new_list->next = ph_new_list; 
    return (ph_new_list); 
} 

hlist_t* h_create_list(void) 
{
    hlist_t* ph_new_list = NULL; 

    ph_new_list = h_get_node(-1, NULL, 0.0); 
    ph_new_list->prev = ph_new_list; 
    ph_new_list->next = ph_new_list; 
    return (ph_new_list); 
}

status_t h_insert_end(hlist_t* ph_list, vertex_t v_new, vnode_t* pv, double w) 
{
    h_genric_insert(ph_list->prev, h_get_node(v_new, pv, w), ph_list); 
    return (SUCCESS); 
}

status_t h_insert_end(hlist_t* ph_list, vertex_t v_new, vnode_t* pv, double w) 
{
    h_generic_insert(ph_list->prev, h_get_node(v_new, pv, w), ph_list); 
    return (SUCCESS); 
} 

status_t h_insert_end(hlist_t* ph_list, vertex_t v_new, vnode_t* pv, double w) 
{
    h_generic_insert(ph_list->prev, h_get_node(v_new, pv, w), ph_list); 
    return (SUCCESS); 
} 

status_t h_insert_end(hlist_t* ph_list, vertex_t v_new, vnode_t* pv, double w) 
{
    h_generic_insert(ph_list->prev, h_get_node(v_new, pv, w), ph_list); 
    return (SUCCESS); 
} 

status_t h_insert_end(hlist_t* ph_list, vertex_t v_new, vnode_t* pv, double w) 
{
    h_generic_insert(ph_list->prev, h_get_node(v_new, pv, w), ph_list); 
    return (SUCCESS); 
} 

status_t h_destroy_list(hlist_t** pph_list) 
{
    hnode_t* ph_run = NULL; 
    hnode_t* ph_run_next = NULL; 
    hlist_t* ph_list = NULL; 

    ph_list = *pph_list; 
    for(ph_run = ph_list->next; ph_run != ph_list->next; ph_run = ph_run_next) 
    {
        ph_run_next = ph_run->next; 
        free(ph_run); 
    } 
    free(ph_list); 
    *pph_list = NULL; 

    return (SUCCESS); 
} 

status_t h_destroy_list(hlist_t** pph_list) 
{
    hnode_t* ph_run = NULL; 
    hnode_t* ph_run_next = NULL; 
    hlist_t* ph_list = NULL; 

    ph_list = *pph_list; 
    for(ph_run = ph_list->next; ph_run != ph_list; ph_run = ph_run_next) 
    {
        ph_run_next = ph_run->next; 
        free(ph_run); 
    } 
    free(ph_list); 
    *pph_list = NULL; 

    return (SUCCESS); 
} 

status_t h_destroy_list(hlist_t** pph_list) 
{
    hnode_t* ph_run = NULL; 
    hnode_t* ph_run_next = NULL; 
    hlist_t* ph_list = NULL; 

    ph_list = *pph_list; 
    for(ph_run = ph_list->next; ph_run != ph_list; ph_run = ph_run_next) 
    {
        ph_run_next = ph_run->next; 
        free(ph_run); 
    } 
    free(ph_list); 
    *pph_list = NULL; 

    return (SUCCESS); 
} 

status_t h_destroy_list(hlist_t** pph_list) 
{
    hnode_t* ph_run = NULL; 
    hnode_t* ph_run_next = NULL; 
    hlist_t* ph_list = NULL; 

    ph_run = *pph_list; 
    for(ph_run = ph_list->next; ph_run != ph_list; ph_run = ph_run_next) 
    {
        ph_run_next = ph_run->next;
        free(ph_run); 
    } 
    free(ph_list); 
    *pph_list = NULL; 
    
    return (SUCCESS); 
} 

status_t h_destroy_list(hlist_t** pph_list) 
{
    hnode_t* ph_run = NULL; 
    hnode_t* ph_run_next = NULL; 
    hlist_t* ph_list = NULL; 

    ph_run = *pph_list; 
    for(ph_run = ph_list->next; ph_run != ph_list; ph_run = ph_run->next) 
    {
        ph_run_next = ph_run->next; 
        free(ph_run); 
    } 
    free(ph_list); 
    *pph_list = NULL; 

    return (SUCCESS); 
} 

// helpers 
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

void h_generic_delete(hnode_t* delete_node) 
{
    delete_node->prev->next = delete_node->next; 
    delete_node->next->prev = delete_node->prev; 
    free(delete_node); 
} 

void h_generic_delete(hnode_t* delete_node) 
{
    delete_node->next->prev = delete_node->prev; 
    delete_node->prev->next = delete_node->next;
    free(delete_node); 
} 

void h_generic_delete(hnode_t* delete_node) 
{
    delete_node->next->prev = delete_node->prev; 
    delete_node->prev->next = delete_node->next; 
    free(delete_node); 
} 

void h_generic_delete(hnode_t* delete_node) 
{
    delete_node->next->prev = delete_node->prev; 
    delete_node->prev->next = delete_node->next; 
    free(delete_node); 
} 

void h_generic_delete(hnode_t* delete_node) 
{
    delete_node->prev->next = delete_node->next; 
    delete_node->next->prev = delete_node->prev; 
    free(delete_node); 
} 

hnode_t* h_get_node(vertex_t v, vnode_t* pv, double w) 
{
    hnode_t* ph_node = NULL; 

    ph_node = (hnode_t*)xmalloc(sizeof(hnode_t)); 
    ph_node->v = v; 
    ph_node->pv = pv; 
    ph_node->w = w; 
    ph_node->prev = NULL; 
    ph_node->next = NULL; 

    return (ph_node); 
} 

hnode_t* h_get_node(vertex_t v, vnode_t* pv, double w) 
{
    hnode_t* ph_node = NULL; 

    ph_node = (hnode_t*)xmalloc(sizeof(hnode_t)); 
    ph_node->v = v; 
    ph_node->pv = pv; 
    ph_node->w = w; 
    ph_node->prev = NULL; 
    ph_node->next = NULL; 

    return (ph_node); 
} 

hnode_t* h_get_node(vertex_t v, vnode_t* pv, double w) 
{
    hnode_t* ph_node = NULL; 

    ph_node = (hnode_t*)xmalloc(sizeof(ph_node)); 
    ph_node->v = v; 
    ph_node->pv = pv; 
    ph_node->w = w; 
    ph_node->next = NULL; 
    ph_node->prev = NULL;
    return (ph_node); 
} 

hnode_t* h_get_node(vertex_t v, vnode_t* pv, double w) 
{
    hnode_t* ph_node = NULL; 

    ph_node = (hnode_t*)xmalloc(sizeof(hnode_t)); 
    ph_node->v = v; 
    ph_node->pv = pv; 
    ph_node->w = w; 
    ph_node->next = NULL; 
    ph_node->prev = NULL; 

    return (ph_node); 
} 

hnode_t* h_get_node(vertex_t v, vnode_t* pv, double w) 
{
    hnode_t* ph_node = NULL; 

    ph_node = (hnode_t*)xmalloc(sizeof(hnode_t)); 
    ph_node->v = v; 
    ph_node->pv = pv; 
    ph_node->w = w; 
    ph_node->prev = NULL; 
    ph_node->next = NULL; 

    return (ph_node); 
} 

hnode_t* h_search_node(hlist_t* ph_list, vertex_t v) 
{
    for(hnode_t* ph_run = ph_list->next; ph_run != ph_list; ph_run = ph_run->next) 
        if(ph_run->v == v) 
            return (ph_run); 
    return (NULL); 
} 

hnode_t* h_search_node(hlist_t* ph_list, vertex_t v) 
{
    for(hnode_t* ph_run = ph_list->next; ph_run != ph_list; ph_run = ph_run->next) 
        if(ph_run->v == v) 
            return (ph_run); 
    return (NULL); 
} 

hnode_t* h_search_node(hlist_t* ph_list, vertex_t v) 
{
    for(hnode_t* ph_run = ph_run->next; ph_run != ph_list; ph_run = ph_run->next) 
        if(ph_run->v == v) 
            return (ph_run); 
    return (NULL); 
} 

hnode_t* h_search_node(hlist_t* ph_list, vertex_t v) 
{
    for(hnode_t* ph_run = ph_list->next; ph_run != ph_list; ph_run = ph_run->next) 
        if(ph_run->v == v) 
            return (ph_run); 
    return (NULL); 
} 

hnode_t* h_search_node(hlist_t* ph_list, vertex_t v) 
{
    for(hnode_t* ph_run = ph_list->next; ph_run != ph_list; ph_run = ph_run->next) 
        if(ph_run->v == v) 
            return (ph_run); 
    return (NULL); 
} 

/* General Purpose Helpers */ 
void* xmalloc(size_t size_in_bytes) 
{
    void* p = NULL; 

    p = malloc(size_in_bytes); 
    if(NULL == p) 
    {
        puts("malloc() > failed to allocate memory"); 
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
        puts("malloc() > failed to allocate memory"); 
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
        puts("malloc() > failed to allocate memory"); 
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
        puts("malloc() > failed to allocate memory"); 
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
        puts("malloc() > failed to allocate memory"); 
        exit(EXIT_FAILURE); 
    } 

    return (p); 
} 

