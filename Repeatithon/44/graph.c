// #include <stdio.h> 
// #include <stdlib.h> 
// #include <assert.h> 
// #include "graph.h" 

// graph_t* create_graph(void) 
// {
//     graph_t* g = NULL; 

//     g = (graph_t*)xmalloc(sizeof(graph_t)); 
//     g->pv_head_node = v_create_list(); 
//     g->nr_vertices = 0; 
//     g->nr_edges = 0; 

//     return (g); 
// } 

// status_t add_vertex(graph_t* g, vertex_t new_vertex) 
// {
//     vnode_t* p = NULL; 

//     p = v_search_node(g->pv_head_node, new_vertex); 
//     if(p != NULL) 
//         return (G_VERTEX_EXISTS); 

//     assert(v_insert_end(g->pv_head_node, new_vertex) == SUCCESS); 
//     g->nr_vertices += 1; 

//     return (SUCCESS); 
// } 

// status_t remove_vertex(graph_t* g, vertex_t r_vertex) 
// {
//     vnode_t* pv_delete= NULL; 
//     vnode_t* pv_h_in_vlist = NULL; 

//     hnode_t* ph_delete_node_in_adj_list = NULL;
//     hnode_t* ph_run = NULL; 
//     hnode_t* ph_run_next = NULL; 

//     pv_delete = v_search_node(g->pv_head_node, r_vertex); 
//     if(NULL == pv_delete) 
//         return (G_INVALID_VERTEX); 

//     ph_run = pv_delete->ph_head_node->h_next; 
//     while(ph_run != pv_delete->ph_head_node) 
//     {
//         ph_run_next = ph_run->h_next; 
//         pv_h_in_vlist = v_search_node(g->pv_head_node, ph_run->v); 
//         ph_delete_node_in_adj_list = h_search_node(pv_h_in_vlist->ph_head_node, r_vertex); 
//         h_generic_delete(ph_delete_node_in_adj_list); 
//         free(ph_run); 
//         g->nr_vertices -= 1; 
//         ph_run = ph_run_next; 
//     } 
//     free(g->pv_head_node); 
//     v_generic_delete(pv_delete); 
//     pv_delete = NULL; 

//     g->nr_vertices -= 1; 

//     return (SUCCESS); 
// } 

// status_t add_edge(graph_t* g, vertex_t v_start, vertex_t v_end) 
// {
//     vnode_t* pv_start = NULL; 
//     vnode_t* pv_end = NULL; 
//     hnode_t* ph_start_in_end = NULL; 
//     hnode_t* ph_end_in_start = NULL; 
//     status_t status; 

//     pv_start = v_search_node(g->pv_head_node, v_start); 
//     if(pv_start == NULL) 
//         return (G_INVALID_VERTEX); 
    
//     pv_end = v_search_node(g->pv_head_node, v_end); 
//     if(pv_end == NULL) 
//         return (G_INVALID_VERTEX); 

//     ph_end_in_start = h_search_node(pv_start->ph_head_node, v_end); 
//     if(ph_end_in_start != NULL) 
//         return (G_EDGE_EXISTS); 
    
//     ph_start_in_end = h_search_node(pv_start->ph_head_node, v_start); 
//     if(ph_start_in_end != NULL) 
//         return (G_EDGE_EXISTS); 

//     assert(h_insert_end(pv_start->ph_head_node, v_end) == SUCCESS); 
//     assert(h_insert_end(pv_end->ph_head_node, v_start) == SUCCESS); 
//     g->nr_edges += 1; 

//     return (SUCCESS); 
// } 

// status_t remove_edge(graph_t* g, vertex_t v_start, vertex_t v_end) 
// { 
//     vnode_t* pv_start = NULL; 
//     vnode_t* pv_end = NULL; 
//     hnode_t* ph_end_in_start = NULL; 
//     hnode_t* ph_start_in_end = NULL; 

//     pv_start = v_search_node(g->pv_head_node, v_start); 
//     if(NULL == pv_start) 
//         return (G_INVALID_VERTEX); 

//     pv_end = v_search_node(g->pv_head_node, v_end); 
//     if(NULL == pv_end) 
//         return (G_INVALID_VERTEX); 

//     ph_end_in_start = h_search_node(pv_start->ph_head_node, v_end); 
//     if(NULL == ph_end_in_start) 
//         return (G_INVALID_EDGE); 

//     ph_start_in_end = h_search_node(pv_end->ph_head_node, v_start); 
//     if(NULL == ph_start_in_end) 
//         return (G_INVALID_EDGE); 

//     h_generic_delete(ph_end_in_start); 
//     h_generic_delete(ph_start_in_end); 
//     g->nr_edges -= 1; 

//     return (SUCCESS); 
// } 

// void show_graph(graph_t* g, const char* msg) 
// {
//     vnode_t* pv_run = NULL; 
//     hnode_t* ph_run = NULL; 

//     if(msg) 
//         puts(msg); 

//     for(pv_run = g->pv_head_node->v_next; pv_run != g->pv_head_node; pv_run = pv_run->v_next) 
//     {
//         printf("[%d]\t->\t", pv_run->v); 
//         for(ph_run = pv_run->ph_head_node->h_next; ph_run != pv_run->ph_head_node; ph_run = ph_run->h_next) 
//         {
//             printf("[%d]->", ph_run->v); 
//         }
//         puts("[END]"); 
//     } 

//     puts("---------------------------------------------------------------------------------------"); 
// } 

// status_t destroy_graph(graph_t** pp_g) 
// {
//     vnode_t* pv_run = NULL; 
//     vnode_t* pv_run_next = NULL; 

//     hnode_t* ph_run = NULL; 
//     hnode_t* ph_run_next = NULL; 

//     graph_t* g = NULL; 

//     g = *pp_g; 
    
//     for(pv_run = g->pv_head_node->v_next; pv_run != g->pv_head_node; pv_run = pv_run->v_next) 
//     {
//         pv_run_next = pv_run->v_next; 

//         for(ph_run = pv_run->ph_head_node->h_next; ph_run != pv_run->ph_head_node; ph_run = ph_run_next) 
//         {
//             ph_run_next = ph_run->h_next; 
//             free(ph_run); 
//         } 
//         free(pv_run->ph_head_node); 
//         free(pv_run); 

//         pv_run = pv_run_next; 
//     } 

//     free(g->pv_head_node); 
//     free(g); 

//     *pp_g = NULL; 

//     return (SUCCESS); 
// } 

// void dfs(graph_t* g) 
// {
//     vnode_t* pv_run = NULL; 

//     reset(g); 

//     printf("[START]->"); 
//     for(pv_run = g->pv_head_node->v_next; pv_run != g->pv_head_node; pv_run = pv_run->v_next) 
//     {
//         if(pv_run->color == WHITE) 
//             dfs_visit(g, pv_run); 
//     } 
//     puts("[END]"); 
// } 

// void bfs(graph_t* g, vertex_t v) 
// {
//     vnode_t* pv_node = NULL; 
//     vnode_t* pv = NULL; 
//     vnode_t* pv_h_in_vlist = NULL; 
//     hnode_t* ph_run = NULL; 
//     queue_node_t* p_queue = NULL; 
//     status_t status; 

//     pv_node = v_search_node(g->pv_head_node, v); 
//     if(pv_node == NULL) 
//         return; 

//     reset(g); 
//     pv_node->color = GREY; 

//     p_queue = create_queue(); 
//     assert(enqueue(p_queue, pv_node) == SUCCESS); 

//     printf("[START]->"); 

//     while(is_queue_empty(p_queue) != TRUE) 
//     {
//         pv = NULL; 
//         assert(dequeue(p_queue, &pv) == SUCCESS); 

//         printf("[%d]->", pv->v); 

//         for(ph_run = pv->ph_head_node->h_next; ph_run != pv->ph_head_node; ph_run = ph_run->h_next) 
//         {
//             pv_h_in_vlist = v_search_node(g->pv_head_node, ph_run->v); 
//             if(pv_h_in_vlist->color == WHITE) 
//             {
//                 pv_h_in_vlist->color = GREY; 
//                 enqueue(p_queue, pv_h_in_vlist); 
//             } 
//         } 

//         pv->color = BLACK; 
//     } 

//     puts("[END]"); 

//     assert(destroy_queue(p_queue) == SUCCESS); 
//     p_queue = NULL; 
// } 

// /* Graph helper routines */ 
// void reset(graph_t* g) 
// {
//     vnode_t* pv_run = NULL; 

//     for(pv_run = g->pv_head_node->v_next; pv_run != g->pv_head_node; pv_run = pv_run->v_next) 
//         pv_run->color = WHITE; 
// } 

// void dfs_visit(graph_t* g, vnode_t* pv_start_node) 
// {
//     hnode_t* ph_run = NULL; 
//     vnode_t* pv_h_in_vlist = NULL; 

//     pv_start_node->color = GREY; 
//     printf("[%d]->", pv_start_node->v); 

//     for(ph_run = pv_start_node->ph_head_node->h_next; ph_run != pv_start_node->ph_head_node; ph_run = ph_run->h_next) 
//     {
//         pv_h_in_vlist = v_search_node(g->pv_head_node, ph_run->v); 
//         if(pv_h_in_vlist->color == WHITE) 
//             dfs_visit(g, pv_h_in_vlist); 
//     } 
//     pv_start_node->color = BLACK; 
// } 

// /* Graph helper routines */ 
// queue_node_t* create_queue(void) 
// {
//     queue_node_t* p_new_queue = NULL; 
    
//     p_new_queue = q_get_node(0); 
//     p_new_queue->q_next = p_new_queue; 
//     p_new_queue->q_prev = p_new_queue; 

//     return (p_new_queue); 
// } 

// status_t enqueue(queue_node_t* p_queue, vnode_t* pv_node) 
// {
//     q_generic_insert(p_queue->q_prev, q_get_node(pv_node), p_queue); 
//     return (SUCCESS); 
// } 

// status_t dequeue(queue_node_t* p_queue, vnode_t** pp_v_node) 
// {
//     if(is_queue_empty(p_queue) == TRUE) 
//     {
//         *pp_v_node = NULL; 
//         return (QUEUE_EMPTY); 
//     } 

//     *pp_v_node = p_queue->q_next->pv_node; 
//     q_generic_delete(p_queue->q_next); 
//     return (SUCCESS); 
// } 

// int is_queue_empty(queue_node_t* p_queue) 
// {
//     return (p_queue->q_next == p_queue && p_queue->q_prev == p_queue); 
// } 

// status_t destroy_queue(queue_node_t* p_queue) 
// {
//     queue_node_t* pq_run = NULL; 
//     queue_node_t* pq_run_next = NULL; 

//     for(pq_run = p_queue->q_next; pq_run != p_queue; pq_run = pq_run->q_next) 
//     {
//         pq_run_next = pq_run->q_next; 
//         free(pq_run); 
//     } 

//     free(p_queue); 
//     return (SUCCESS); 
// } 

// // queue helpers 
// void q_generic_insert(queue_node_t* p_beg, queue_node_t* p_mid, queue_node_t* p_end) 
// {
//     p_mid->q_prev = p_beg; 
//     p_mid->q_next = p_end; 
//     p_beg->q_next = p_mid; 
//     p_end->q_prev = p_mid; 
// } 

// void q_generic_delete(queue_node_t* p_delete_node) 
// {
//     p_delete_node->q_prev->q_next = p_delete_node->q_next; 
//     p_delete_node->q_next->q_prev = p_delete_node->q_prev; 
//     free(p_delete_node); 
// } 

// queue_node_t* q_get_node(vnode_t* new_pv_node) 
// {
//     queue_node_t* p_new_node = NULL; 

//     p_new_node = (queue_node_t*)xmalloc(sizeof(queue_node_t)); 
//     p_new_node->pv_node = new_pv_node; 
//     p_new_node->q_prev = NULL; 
//     p_new_node->q_next = NULL;

//     return (p_new_node); 
// } 

// /* Vertical list management */ 
// // interface 
// vlist_t* v_create_list(void) 
// {
//     vlist_t* pv_head_node = NULL; 

//     pv_head_node = (vlist_t*)xmalloc(sizeof(vlist_t)); 
//     pv_head_node->ph_head_node = NULL; 
//     pv_head_node->v_prev = pv_head_node; 
//     pv_head_node->v_next = pv_head_node; 

//     return (pv_head_node); 
// } 

// status_t v_insert_end(vlist_t* pv_list, vertex_t new_vertex) 
// {
//     v_generic_insert(pv_list->v_prev, v_get_list_node(new_vertex), pv_list); 
//     return (SUCCESS); 
// } 

// // helpers 
// void v_generic_insert(vnode_t* pv_beg, vnode_t* pv_mid, vnode_t* pv_end) 
// {
//     pv_mid->v_prev = pv_beg; 
//     pv_mid->v_next = pv_end; 
//     pv_end->v_prev = pv_mid; 
//     pv_beg->v_next = pv_mid; 
// } 

// void v_generic_delete(vnode_t* pv_delete_node) 
// {
//     pv_delete_node->v_next->v_prev = pv_delete_node->v_prev; 
//     pv_delete_node->v_prev->v_next = pv_delete_node->v_next; 
//     free(pv_delete_node); 
// } 

// vnode_t* v_search_node(vlist_t* pv_list, vertex_t search_vertex) 
// {
//     vnode_t* pv_run = NULL; 

//     for(pv_run = pv_list->v_next; pv_run != pv_list; pv_run = pv_run->v_next) 
//         if(pv_run->v == search_vertex) 
//             return (pv_run); 
//     return (NULL); 
// } 

// vnode_t* v_get_list_node(vertex_t new_vertex) 
// {
//     vnode_t* pv_new_node = NULL; 

//     pv_new_node = (vnode_t*)xmalloc(sizeof(vnode_t)); 
//     pv_new_node->v = new_vertex; 
//     pv_new_node->ph_head_node = h_create_list(); 
//     pv_new_node->v_prev = NULL; 
//     pv_new_node->v_next = NULL; 

//     return (pv_new_node); 
// } 

// /* Horizontal list management */ 
// // interface 
// hlist_t* h_create_list(void) 
// {
//     hnode_t* ph_list = NULL; 

//     ph_list = h_get_list_node(-1); 
//     ph_list->h_prev = ph_list; 
//     ph_list->h_next = ph_list; 

//     return (ph_list); 
// } 

// status_t h_insert_end(hlist_t* ph_list, vertex_t new_vertex) 
// {
//     h_generic_insert(ph_list->h_prev, h_get_list_node(new_vertex), ph_list); 
//     return (SUCCESS); 
// } 

// // helpers 
// void h_generic_insert(hnode_t* ph_beg, hnode_t* ph_mid, hnode_t* ph_end) 
// {
//     ph_mid->h_next = ph_end; 
//     ph_mid->h_prev = ph_beg; 
//     ph_beg->h_next = ph_mid; 
//     ph_end->h_prev = ph_mid; 
// } 

// void h_generic_delete(hnode_t* ph_delete_node) 
// {
//     ph_delete_node->h_prev->h_next = ph_delete_node->h_next; 
//     ph_delete_node->h_next->h_prev = ph_delete_node->h_prev; 
//     free(ph_delete_node); 
// } 

// hnode_t* h_search_node(hlist_t* ph_list, vertex_t search_vertex)
// {
//     hnode_t* ph_run = NULL; 

//     for(ph_run = ph_list->h_next; ph_run != ph_list; ph_run = ph_run->h_next)
//         if(ph_run->v == search_vertex) 
//             return (ph_run); 

//     return (NULL); 
// } 

// hnode_t* h_get_list_node(vertex_t new_vertex) 
// {
//     hnode_t* ph_new_node = NULL; 

//     ph_new_node = (hnode_t*)xmalloc(sizeof(hnode_t)); 
//     ph_new_node->v = new_vertex; 
//     ph_new_node->h_prev = NULL; 
//     ph_new_node->h_next = NULL; 

//     return (ph_new_node); 
// } 

// /* Graph helper routines */ 
// void* xmalloc(size_t nr_bytes) 
// {
//     void* p = NULL; 

//     p = malloc(nr_bytes); 
//     if(NULL == p) 
//     {
//         fprintf(stderr, "Out of virtual memory\n"); 
//         exit(EXIT_FAILURE); 
//     } 

//     return (p); 
// } 

// // ===============================================================================

// #include "graph.h" 

// graph_t* create_graph(void) 
// {
//     graph_t* g = NULL; 

//     g = (graph_t*)xmalloc(sizeof(graph_t)); 
//     g->pv_head_node = v_create_list(); 
//     g->nr_vertices = 0; 
//     g->nr_edges = 0; 

//     return (g); 
// } 

// status_t add_vertex(graph_t* g, vertex_t new_vertex) 
// {
//     vnode_t* pv_node = NULL; 

//     pv_node = v_search_node(g->pv_head_node, new_vertex); 
//     if(pv_node != NULL) 
//         return (G_VERTEX_EXISTS); 

//     assert(v_insert_end(g->pv_head_node, new_vertex) == SUCCESS); 
//     g->nr_vertices += 1; 

//     return (SUCCESS); 
// } 

// status_t remove_vertex(graph_t* g, vertex_t r_vertex) 
// {
//     vnode_t* pv_remove_node = NULL; 
//     vnode_t* pv_h_in_vlist = NULL; 

//     hnode_t* ph_run = NULL; 
//     hnode_t* ph_run_next = NULL; 
//     hnode_t* ph_delete_node_in_adj_list = NULL; 

//     pv_remove_node = v_search_node(g->pv_head_node, r_vertex); 
//     if(pv_remove_node == NULL) 
//         return (G_INVALID_VERTEX); 

//     ph_run = pv_remove_node->ph_head_node->h_next; 
//     while(ph_run != pv_remove_node->ph_head_node) 
//     {
//         ph_run_next = ph_run->h_next; 

//         pv_h_in_vlist = v_search_node(g->pv_head_node, ph_run->v); 
//         ph_delete_node_in_adj_list = h_search_node(pv_h_in_vlist->ph_head_node, r_vertex); 
//         h_generic_delete(ph_delete_node_in_adj_list); 
//         free(ph_run); 
//         g->nr_edges -= 1; 
//         ph_run = ph_run_next; 
//     } 
//     free(pv_remove_node->ph_head_node); 
//     v_generic_delete(pv_remove_node); 
//     g->nr_vertices -= 1; 

//     return (SUCCESS); 
// } 

// status_t add_edge(graph_t* g, vertex_t v_start, vertex_t v_end) 
// {
//     vnode_t* pv_start = NULL; 
//     vnode_t* pv_end = NULL; 
//     hnode_t* ph_start_in_end = NULL; 
//     hnode_t* ph_end_in_start = NULL; 

//     pv_start = v_search_node(g->pv_head_node, v_start); 
//     if(NULL == pv_start) 
//         return (G_INVALID_VERTEX); 
//     pv_end = v_search_node(g->pv_head_node, v_end); 
//     if(NULL == pv_end) 
//         return (G_INVALID_VERTEX); 

//     ph_end_in_start = h_search_node(pv_start->ph_head_node, v_end); 
//     if(ph_end_in_start != NULL) 
//         return (G_EDGE_EXISTS); 
//     ph_start_in_end = h_search_node(pv_end->ph_head_node, v_start); 
//     if(ph_start_in_end != NULL) 
//         return (G_EDGE_EXISTS); 

//     assert(h_insert_end(pv_start->ph_head_node, v_end) == SUCCESS); 
//     assert(h_insert_end(pv_end->ph_head_node, v_start) == SUCCESS); 
//     g->nr_edges += 1; 

//     return (SUCCESS); 
// } 

// status_t remove_edge(graph_t* g, vertex_t v_start, vertex_t v_end) 
// {
//     vnode_t* pv_start = NULL; 
//     vnode_t* pv_end = NULL; 
//     hnode_t* ph_end_in_start = NULL; 
//     hnode_t* ph_start_in_end = NULL; 

//     pv_start = v_search_node(g->pv_head_node, v_start); 
//     if(NULL == pv_start) 
//         return (G_INVALID_VERTEX); 
//     pv_end = v_search_node(g->pv_head_node, v_end); 
//     if(NULL == pv_end) 
//         return (G_INVALID_VERTEX); 

//     ph_end_in_start = h_search_node(pv_start->ph_head_node, v_end); 
//     if(NULL == ph_end_in_start) 
//         return (G_INVALID_EDGE); 
//     ph_start_in_end = h_search_node(pv_end->ph_head_node, v_start); 
//     if(NULL == ph_start_in_end) 
//         return (G_INVALID_EDGE); 

//     h_generic_delete(ph_end_in_start); 
//     h_generic_delete(ph_start_in_end); 
//     g->nr_vertices -= 1; 

//     return (SUCCESS); 
// } 

// void show_graph(graph_t* g, const char* msg) 
// {
//     vnode_t* pv_run = NULL; 
//     hnode_t* ph_run = NULL; 

//     pv_run = g->pv_head_node->v_next; 
//     while(pv_run != g->pv_head_node) 
//     {
//         printf("[%d]\t->\t", pv_run->v); 

//         ph_run = pv_run->ph_head_node->h_next; 
//         while(ph_run != pv_run->ph_head_node) 
//         {
//             printf("[%d]->", ph_run->v); 
//             ph_run = ph_run->h_next; 
//         } 
//         puts("[END]"); 

//         pv_run = pv_run->v_next; 
//     } 

//     puts("--------------------------------------------------------------"); 
// } 

// // traversal 
// void dfs(graph_t* g) 
// {
//     vnode_t* pv_run = NULL; 

//     reset(g); 

//     printf("[START]->"); 
//     for(pv_run = g->pv_head_node->v_next; pv_run != g->pv_head_node; pv_run = pv_run->v_next) 
//         if(pv_run->color == WHITE) 
//             dfs_visit(g, pv_run); 
//     puts("[END]"); 
// } 

// void bfs(graph_t* g, vertex_t v) 
// { 
//     vnode_t* pv_node = NULL; 
//     vnode_t* pv = NULL; 
//     vnode_t* pv_h_in_vlist = NULL; 
//     hnode_t* ph_run = NULL; 
//     queue_node_t* p_queue = NULL; 
//     status_t status; 

//     pv_node = v_search_node(g->pv_head_node, v); 
//     if(pv_node == NULL) 
//         return; 

//     reset(g); 
//     pv_node->color = GREY; 

//     p_queue = create_queue(); 
//     assert(enqueue(p_queue, pv_node) == SUCCESS); 

//     printf("[START]->"); 
//     while(is_queue_empty(p_queue) == FALSE) 
//     {
//         pv = NULL; 
//         assert(dequeue(p_queue, &pv) == SUCCESS); 

//         printf("[%d]->", pv->v); 

//         for(ph_run = pv->ph_head_node->h_next; ph_run != ph_run->h_next; ph_run = ph_run->h_next) 
//         {
//             pv_h_in_vlist = v_search_node(g->pv_head_node, ph_run->v); 
//             if(pv_h_in_vlist->color == WHITE) 
//             {
//                 pv_h_in_vlist->color = GREY; 
//                 enqueue(p_queue, pv_h_in_vlist); 
//             } 
//         } 
//         pv->color = BLACK; 
//     } 

//     puts("[END]"); 

//     assert(destroy_queue(p_queue) == SUCCESS); 
//     p_queue = NULL; 
// }

// // destruction 
// status_t destroy_graph(graph_t** pp_g) 
// {
//     vnode_t* pv_run = NULL; 
//     vnode_t* pv_run_next = NULL; 
//     hnode_t* ph_run = NULL; 
//     hnode_t* ph_run_next = NULL; 
//     graph_t* g = NULL; 

//     g = *pp_g; 

//     pv_run = g->pv_head_node->v_next; 
//     while(pv_run != g->pv_head_node) 
//     {
//         pv_run_next = pv_run->v_next; 

//         ph_run = pv_run->ph_head_node->h_next; 
//         while(ph_run != pv_run->ph_head_node) 
//         {
//             free(ph_run); 
//             ph_run = ph_run_next; 
//         } 
//         free(pv_run->ph_head_node); 
//         free(pv_run); 

//         pv_run = pv_run_next; 
//     } 

//     free(g->pv_head_node); 
//     free(g); 

//     *pp_g = NULL; 

//     return (SUCCESS); 
// } 

// /* Graph Helper functions */ 
// void reset(graph_t* g) 
// {
//     vnode_t* pv_run = NULL; 

//     pv_run = g->pv_head_node->v_next; 
//     while(pv_run != g->pv_head_node) 
//     {
//         pv_run->color = WHITE; 
//         pv_run = pv_run->v_next; 
//     }  
// } 

// void dfs_visit(graph_t* g, vnode_t* pv_start_vertex) 
// {
//     hnode_t* ph_run = NULL;
//     vnode_t* pv_h_in_vlist = NULL;  

//     printf("[%d]->", pv_start_vertex->v); 
//     pv_start_vertex->color = GREY; 

//     ph_run = pv_start_vertex->ph_head_node->h_next; 
//     while(ph_run != pv_start_vertex->ph_head_node) 
//     {
//         pv_h_in_vlist = v_search_node(g->pv_head_node, ph_run->v); 
//         if(pv_h_in_vlist->color == WHITE) 
//             dfs_visit(g, pv_h_in_vlist); 

//         ph_run = ph_run->h_next; 
//     } 

//     pv_start_vertex->color = BLACK; 
// } 

// /* Queue management */ 
// // interface 
// queue_node_t* create_queue(void) 
// {
//     queue_node_t* p_queue = NULL; 

//     p_queue = q_get_node(0); 
//     p_queue->q_prev = p_queue; 
//     p_queue->q_next = p_queue; 

//     return (p_queue); 
// } 

// status_t enqueue(queue_node_t* p_queue, vlist_t* new_pv_node) 
// {
//     q_generic_insert(p_queue->q_prev, q_get_node(new_pv_node), p_queue); 
//     return (SUCCESS); 
// } 

// status_t dequeue(queue_node_t* p_queue, vnode_t** ppv_node) 
// {
//     if(is_queue_empty(p_queue) == TRUE) 
//         return (QUEUE_EMPTY); 

//     *ppv_node = p_queue->q_next->pv_node; 
//     q_generic_delete(p_queue->q_next); 

//     return (SUCCESS); 
// } 

// status_t is_queue_empty(queue_node_t* p_queue) 
// {
//     if(p_queue->q_prev == p_queue && p_queue->q_next == p_queue) 
//         return (TRUE); 
//     return (FALSE); 
// } 

// status_t destroy_queue(queue_node_t* p_queue) 
// {
//     queue_node_t* pq_run = NULL; 
//     queue_node_t* pq_run_next = NULL; 

//     pq_run = p_queue->q_next; 
//     while(pq_run != p_queue) 
//     {
//         pq_run_next = pq_run->q_next; 
//         free(pq_run); 
//         pq_run = pq_run_next; 
//     } 
//     free(p_queue); 

//     return (SUCCESS); 
// } 

// // helpers 
// void q_generic_insert(queue_node_t* p_beg, queue_node_t* p_mid, queue_node_t* p_end) 
// {
//     p_mid->q_prev = p_beg; 
//     p_mid->q_next = p_end; 
//     p_beg->q_next = p_mid; 
//     p_end->q_prev = p_mid; 
// } 

// void q_generic_delete(queue_node_t* p_delete_node) 
// {
//     p_delete_node->q_next->q_prev = p_delete_node->q_prev; 
//     p_delete_node->q_prev->q_next = p_delete_node->q_next; 
//     free(p_delete_node); 
// } 

// queue_node_t* q_get_node(vnode_t* new_pv_node) 
// {
//     queue_node_t* p_new_node = NULL; 

//     p_new_node = (queue_node_t*)xmalloc(sizeof(queue_node_t)); 
//     p_new_node->pv_node = new_pv_node; 
//     p_new_node->q_next = NULL; 
//     p_new_node->q_prev = NULL; 

//     return (p_new_node); 
// } 

// /* Vertical list management */ 
// // interface 
// vlist_t* v_create_list(void) 
// { 
//     vlist_t* pv_list = NULL; 

//     pv_list = (vlist_t*)xmalloc(sizeof(vlist_t)); 
//     pv_list->ph_head_node = NULL; 
//     pv_list->v_prev = pv_list; 
//     pv_list->v_next = pv_list; 

//     return (pv_list); 
// } 

// status_t v_insert_end(vlist_t* pv_list, vertex_t new_vertex) 
// {
//     v_generic_insert(pv_list->v_prev, v_get_list_node(new_vertex), pv_list); 
//     return (SUCCESS); 
// } 

// // helpers 
// void v_generic_insert(vlist_t* pv_beg, vlist_t* pv_mid, vlist_t* pv_end) 
// {
//     pv_mid->v_prev = pv_beg; 
//     pv_mid->v_next = pv_end; 
//     pv_beg->v_next = pv_mid; 
//     pv_end->v_prev = pv_mid; 
// } 

// void v_generic_delete(vnode_t* pv_delete_node) 
// {
//     pv_delete_node->v_prev->v_next = pv_delete_node->v_next; 
//     pv_delete_node->v_next->v_prev = pv_delete_node->v_prev; 
//     free(pv_delete_node); 
// } 

// vnode_t* v_get_list_node(vertex_t new_vertex) 
// {
//     vnode_t* p_new_node = NULL; 

//     p_new_node = (vnode_t*)xmalloc(sizeof(vnode_t)); 
//     p_new_node->v = new_vertex; 
//     p_new_node->ph_head_node = h_create_list(); 
//     p_new_node->color = WHITE; 
//     p_new_node->v_next = NULL; 
//     p_new_node->v_prev = NULL; 

//     return (p_new_node); 
// } 

// vnode_t* v_search_node(vlist_t* pv_list, vertex_t s_vertex) 
// {
//     vnode_t* pv_run = NULL; 

//     pv_run = pv_list->v_next; 
//     while(pv_run != pv_list) 
//     {
//         if(pv_run->v == s_vertex) 
//             return (pv_run); 
//         pv_run = pv_run->v_next; 
//     } 
//     return (NULL); 
// } 

// /* Horizontal list management */ 
// // interface 
// hlist_t* h_create_list(void) 
// {
//     hlist_t* p_list = NULL; 

//     p_list = (hlist_t*)h_get_list_node(-1); 
//     p_list->h_prev = p_list; 
//     p_list->h_next = p_list; 

//     return (p_list); 
// } 

// status_t h_insert_end(hlist_t* ph_list, vertex_t v) 
// {
//     h_generic_insert(ph_list->h_prev, h_get_list_node(v), ph_list); 
//     return (SUCCESS); 
// } 

// // helpers 
// void h_generic_insert(hnode_t* ph_beg, hnode_t* ph_mid, hnode_t* ph_end) 
// {
//     ph_mid->h_prev = ph_beg; 
//     ph_mid->h_next = ph_end; 
//     ph_end->h_prev = ph_mid; 
//     ph_beg->h_next = ph_mid; 
// } 

// void h_generic_delete(hnode_t* ph_delete_node) 
// {
//     ph_delete_node->h_prev->h_next = ph_delete_node->h_next; 
//     ph_delete_node->h_next->h_prev = ph_delete_node->h_prev; 
//     free(ph_delete_node); 
// } 

// hnode_t* h_search_node(hlist_t* ph_list, vertex_t search_vertex) 
// {
//     hnode_t* ph_run = NULL; 

//     ph_run = ph_list->h_next; 
//     while(ph_run != ph_list) 
//     {
//         if(ph_run->v == search_vertex) 
//             return (ph_run); 
//         ph_run = ph_run->h_next; 
//     } 

//     return (NULL); 
// } 

// hnode_t* h_get_list_node(vertex_t new_vertex) 
// {
//     hnode_t* ph_new_node = NULL; 

//     ph_new_node = (hnode_t*)xmalloc(sizeof(hnode_t)); 
//     ph_new_node->v = new_vertex; 
//     ph_new_node->h_prev = NULL; 
//     ph_new_node->h_next = NULL; 

//     return (ph_new_node); 
// } 

// /* General purpose helpers */ 
// void* xmalloc(size_t nr_bytes) 
// {
//     void* p = NULL; 

//     p = malloc(nr_bytes); 
//     if(NULL == p) 
//     {
//         puts("malloc():fatal:out of memory"); 
//         exit(EXIT_FAILURE); 
//     } 

//     return (p); 
// } 

// ==============================================================================================================

#include <stdio.h> 
#include <stdlib.h> 
#include <assert.h> 
#include "graph.h" 

/* Graph Interface routines */ 
// creation 
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
    g->pv_head_node = NULL; 
    g->nr_vertices = 0; 
    g->nr_edges = 0; 

    return (g); 
} 

graph_t* create_graph(void) 
{
    graph_t* g = NULL; 
    g->pv_head_node = NULL; 
    g->nr_vertices = 0; 
    g->nr_edges = 0; 

    return (g); 
} 

// addition and removal 
status_t add_vertex(graph_t* g, vertex_t new_vertex) 
{
    vnode_t* pv_existing_node = NULL; 

    pv_existing_node = v_search_node(g->pv_head_node, new_vertex); 
    if(pv_existing_node != NULL) 
        return (G_VERTEX_EXISTS); 

    assert(v_insert_end(g->pv_head_node, new_vertex) == SUCCESS); 
    g->nr_vertices += 1; 

    return (SUCCESS); 
} 

status_t add_vertex(graph_t* g, vertex_t new_vertex) 
{
    vnode_t* pv_existing_node = NULL; 

    pv_existing_node = v_search_node(g->pv_head_node, new_vertex); 
    if(pv_existing_node != NULL) 
        return (G_VERTEX_EXISTS); 

    assert(v_insert_end(g->pv_head_node, new_vertex) == SUCCESS); 
    g->nr_vertices += 1; 

    return (SUCCESS); 
} 

status_t add_vertex(graph_t* g, vertex_t new_vertex) 
{
    vnode_t* pv_existing_node = NULL; 

    pv_existing_node = v_search_node(g->pv_head_node, new_vertex); 
    if(pv_existing_node != NULL) 
        return (G_VERTEX_EXISTS); 

    assert(v_insert_end(g->pv_head_node, new_vertex) == SUCCESS); 
    g->nr_vertices += 1; 

    return (SUCCESS); 
} 

status_t add_edge(graph_t* g, vertex_t v_start, vertex_t v_end) 
{
    vnode_t* pv_start = NULL; 
    vnode_t* pv_end = NULL; 

    hnode_t* ph_start_in_end = NULL; 
    hnode_t* ph_end_in_start = NULL; 

    pv_start = v_search_node(g->pv_head_node, v_start); 
    if(pv_end == NULL) 
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

    assert(h_insert_end(pv_start->ph_head_node, v_end) == SUCCESS); 
    assert(h_insert_end(pv_end->ph_head_node, v_start) == SUCCESS); 
    g->nr_edges += 1; 

    return (SUCCESS); 
} 

status_t add_edge(graph_t* g, vertex_t v_start, vertex_t v_end) 
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

    assert(h_insert_end(pv_start->ph_head_node, v_end) == SUCCESS); 
    assert(h_insert_end(pv_end->ph_head_node, v_start) == SUCCESS); 
    g->nr_edges += 1; 

    return (SUCCESS); 
} 

status_t remove_vertex(graph_t* g, vertex_t r_vertex) 
{
    vnode_t* pv_delete = NULL; 
    vnode_t* pv_h_in_vlist = NULL; 
    hnode_t* ph_run = NULL; 
    hnode_t* ph_run_next = NULL; 
    hnode_t* ph_delete_in_adj_list = NULL; 

    pv_delete = v_search_node(g->pv_head_node, r_vertex); 
    if(pv_delete == NULL) 
        return (G_INVALID_VERTEX); 

    for(ph_run = pv_delete->ph_head_node->h_next; ph_run != pv_delete->ph_head_node; ph_run = ph_run_next) 
    {
        ph_run_next = ph_run->h_next; 

        pv_h_in_vlist = v_search_node(g->pv_head_node, ph_run->v); 
        ph_delete_in_adj_list = h_search_node(pv_h_in_vlist->ph_head_node, r_vertex); 
        h_generic_delete(ph_delete_in_adj_list); 
        free(ph_run); 
        g->nr_edges -= 1; 
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
    hnode_t* ph_delete_in_adj_list = NULL; 

    pv_delete = v_search_node(g->pv_head_node, r_vertex); 
    if(pv_delete == NULL) 
        return (G_INVALID_VERTEX); 

    for(ph_run = pv_delete->ph_head_node->h_next; ph_run != pv_delete->ph_head_node; ph_run = ph_run->h_next) 
    {
        ph_run_next = ph_run->h_next; 

        pv_h_in_vlist = v_search_node(g->pv_head_node, ph_run->v); 
        ph_delete_in_adj_list = h_search_node(pv_h_in_vlist->ph_head_node, r_vertex); 
        h_geenric_delete(ph_delete_in_adj_list); 
        free(ph_run); 

        g->nr_edges -= 1; 
    } 

    free(pv_delete->ph_head_node); 
    v_generic_delete(pv_delete); 
    pv_delete = NULL; 
    g->nr_vertices -= 1; 

    return (SUCCESS); 
} 

status_t remove_vertex(graph_t* g, vertex_t r_vertex) 
{
    vnode_t* pv_delete = NULL; 
    vnode_t* pv_h_in_vlist = NULL; 
    hnode_t* ph_run = NULL; 
    hnode_t* ph_run_next = NULL; 
    hnode_t* ph_delete_in_adj_list = NULL; 

    pv_delete = v_search_node(g->pv_head_node, r_vertex); 
    if(pv_delete == NULL) 
        return (G_INVALID_VERTEX); 

    for(ph_run = pv_delete->ph_head_node->h_next; ph_run != pv_delete->ph_head_node; ph_run = ph_run->h_next) 
    {
        ph_run_next = ph_run->h_next; 

        pv_h_in_vlist = v_search_node(g->pv_head_node, ph_run->v); 
        ph_delete_in_adj_list = h_search_node(pv_h_in_vlist->ph_head_node, r_vertex); 
        h_generic_delete(ph_delete_in_adj_list); 
        free(ph_run); 

        g->nr_edges -= 1; 
    } 

    free(pv_delete->ph_head_node); 
    v_generic_delete(pv_delete); 
    pv_delete = NULL; 

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

// show 
void show(graph_t* g, const char* msg) 
{
    vnode_t* pv_run = NULL; 
    hnode_t* ph_run = NULL; 

    if(msg) 
        puts(msg); 

    for(pv_run = g->pv_head_node->v_next; pv_run != g->pv_head_node; pv_run = pv_run->v_next)
    {
        printf("[%d]\t<->\t", pv_run->v); 
        for(ph_run = pv_run->ph_head_node->h_next; ph_run != pv_run->ph_head_node; ph_run = ph_run->h_next) 
            printf("[%d]->", ph_run->v); 
        puts("[END]"); 
    } 

    puts("---------------------------------------------------------------------------"); 
} 

void show(graph_t* g, const char* msg) 
{
    vnode_t* pv_run = NULL; 
    hnode_t* ph_run = NULL; 

    if(msg) 
        puts(msg); 

    for(pv_run = g->pv_head_node->v_next; pv_run != g->pv_head_node; pv_run = pv_run->v_next) 
    {
        printf("[%d]\t<->\t", pv_run->v); 
        for(ph_run = pv_run->ph_head_node->h_next; ph_run != pv_run->ph_head_node; ph_run = ph_run->h_next) 
            printf("[%d]->", ph_run->v); 
        puts("[END]"); 
    } 

    puts("-----------------------------------------------------------------------------------------"); 
} 

void show(graph_t* g, const char* msg) 
{
    vnode_t* pv_run = NULL; 
    hnode_t* ph_run = NULL; 

    if(msg) 
        puts(msg); 

    for(pv_run = g->pv_head_node->v_next; pv_run != g->pv_head_node; pv_run = pv_run->v_next) 
    {
        printf("[%d]\t<->\t", pv_run->v); 
        for(ph_run = pv_run->ph_head_node->h_next; ph_run != pv_run->ph_head_node; ph_run = ph_run->h_next) 
            printf("[%d]->", ph_run->v); 
        puts("[END]"); 
    } 

    puts("----------------------------------------------------------------------------------------"); 
} 

// destroy 
status_t destroy_graph(graph_t** pp_g) 
{
    vnode_t* pv_run = NULL; 
    vnode_t* pv_run_next = NULL; 

    hnode_t* ph_run = NULL; 
    hnode_t* ph_run_next = NULL; 

    graph_t* g = *pp_g; 

    for(pv_run = g->pv_head_node->v_next; pv_run != g->pv_head_node; pv_run = pv_run->v_next) 
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

    for(pv_run = g->pv_head_node->v_next; pv_run != g->pv_head_node; pv_run = pv_run->v_next) 
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

    for(pv_run = g->pv_head_node->v_next; pv_run != g->pv_head_node; pv_run = pv_run->v_next) 
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

    return (SUCCESS); 
} 

// traversal 
void dfs(graph_t* g) 
{
    vnode_t* pv_run = NULL; 

    reset(g); 

    printf("[START]->"); 
    for(pv_run = g->pv_head_node->v_next; pv_run != g->pv_head_node; pv_run = pv_run->v_next); 
        if(pv_run->color == WHITE) 
            dfs_visit(g, pv_run); 
    printf("[END]"); 
} 

void dfs(graph_t* g) 
{
    vnode_t* pv_run = NULL; 

    reset(g); 

    printf("[START]->"); 
    for(pv_run = g->pv_head_node->v_next; pv_run != g->pv_head_node; pv_run = pv_run->v_next) 
        if(pv_run->color == WHITE) 
            dfs_visit(g, pv_run); 
    puts("[END]"); 
} 

void dfs(graph_t* g) 
{
    vnode_t* pv_run = NULL; 

    reset(g); 

    printf("[START]->"); 
    for(pv_run = g->pv_head_node->v_next; pv_run != g->pv_head_node; pv_run = pv_run->v_next) 
        if(pv_run->color == WHITE) 
            dfs_visit(g, pv_run); 
    puts("[END]"); 
} 

void bfs(graph_t* g, vertex_t start_vertex) 
{
    vnode_t* pv_node = NULL; 
    vnode_t* pv = NULL; 
    vnode_t* pv_h_in_vlist = NULL; 
    hnode_t* ph_run = NULL; 
    queue_node_t* p_queue = NULL; 
    status_t status; 

    pv_node = v_search_node(g->pv_head_node, start_vertex); 
    if(pv_node == NULL) 
        return (G_INVALID_VERTEX); 

    reset(g); 
    pv_node->color = GREY; 

    p_queue = create_queue(); 
    status = enqueue(p_queue, pv_node); 

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

    printf("[END]"); 

    assert(destroy_queue(p_queue) == SUCCESS); 
    p_queue = NULL; 
} 

void bfs(graph_t* g, vertex_t start_vertex) 
{
    vnode_t* pv_h_in_vlist = NULL; 
    vnode_t* pv_node = NULL; 
    vnode_t* pv = NULL; 
    hnode_t* ph_run = NULL; 
    queue_node_t* p_queue = NULL; 
    
    pv_node = v_search_node(g->pv_head_node, start_vertex); 
    if(NULL == pv_node) 
        return (G_INVALID_VERTEX); 

    reset(g); 

    p_queue = create_queue(); 
    pv_node->color = GREY; 
    assert(enqueue(p_queue, pv_node) == SUCCESS); 

    printf("[START]<->"); 

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

    printf("[END]\n");  
    assert(destroy_queue(p_queue) == SUCCESS); 
    p_queue = NULL; 
} 

void bfs(graph_t* g, vertex_t start_vertex) 
{
    vnode_t* pv_node = NULL; 
    vnode_t* pv = NULL; 
    vnode_t* pv_h_in_vlist = NULL; 
    hnode_t* ph_run = NULL; 
    queue_node_t* p_queue = NULL; 

    pv_node = v_search_node(g->pv_head_node, start_vertex); 
    if(NULL == pv_node) 
        return (G_INVALID_VERTEX); 

    p_queue = create_queue(); 
    pv_node->color = GREY; 
    assert(enqueue(p_queue, pv_node) == SUCCESS); 

    printf("[START]<->"); 

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
    puts("[END]"); 

    assert(destroy_queue(&p_queue) == SUCCESS); 
} 

/* Graph helper routines */ 
void dfs_visit(graph_t* g, vnode_t* pv_start_node) 
{
    hnode_t* ph_run = NULL; 
    vnode_t* pv_h_in_vlist = NULL; 

    pv_start_node->color = GREY; 
    printf("[%d]->", pv_start_node->v); 

    for(ph_run = pv_start_node->ph_head_node->h_next; ph_run != pv_start_node->ph_head_node; ph_run = ph_run->h_next) 
    {
        pv_h_in_vlist = v_search_node(g->pv_head_node, ph_run->v); 
        if(pv_h_in_vlist->color == WHITE) 
            dfs_visit(g, pv_h_in_vlist); 
    } 
    pv_start_node->color = BLACK; 
} 

void dfs_visit(graph_t* g, vnode_t* pv_start_node) 
{
    hnode_t* ph_run = NULL; 
    vnode_t* pv_h_in_vlist = NULL; 

    pv_start_node->color = GREY; 
    printf("[%d]->", pv_start_node->v); 

    for(ph_run = pv_start_node->ph_head_node->h_next; ph_run != pv_start_node->ph_head_node; ph_run = ph_run->h_next) 
    {
        pv_h_in_vlist = v_search_node(g->pv_head_node, ph_run->v); 
        if(pv_h_in_vlist->color == WHITE) 
            dfs_visit(g, pv_h_in_vlist); 
    } 

    pv_start_node->color = BLACK; 
} 

void dfs_visit(graph_t* g, vnode_t* pv_start_node) 
{
    hnode_t* ph_run = NULL; 
    vnode_t* pv_h_in_vlist = NULL; 

    pv_start_node->color = GREY; 
    printf("[%d]->", pv_start_node->v); 

    for(ph_run = pv_start_node->ph_head_node->h_next; ph_run != pv_start_node->ph_head_node; ph_run != ph_run->h_next) 
    {
        pv_h_in_vlist = v_search_node(g->pv_head_node, ph_run->v); 
        if(pv_h_in_vlist->color == WHITE) 
            dfs_visit(g, pv_h_in_vlist); 
    } 

    pv_h_in_vlist->color = BLACK; 
} 

void reset(graph_t* g) 
{
    vnode_t* pv_run = NULL; 

    for(pv_run = g->pv_head_node->v_next; pv_run != g->pv_head_node; pv_run = pv_run->v_next) 
        pv_run->color = WHITE; 
} 

void reset(graph_t* g) 
{
    vnode_t* pv_run = NULL; 

    for(pv_run = g->pv_head_node->v_next; pv_run != g->pv_head_node; pv_run = pv_run->v_next) 
        pv_run->color = WHITE; 
} 

void reset(graph_t* g) 
{
    vnode_t* pv_run = NULL; 

    for(pv_run = g->pv_head_node->v_next; pv_run != g->pv_head_node; pv_run = pv_run->v_next) 
        pv_run->color = WHITE; 
} 

/* Queue of vnode_t */ 
queue_node_t* create_queue(void) 
{
    queue_node_t* p_queue = NULL; 

    p_queue = q_get_node(NULL); 
    p_queue->q_next = NULL; 
    p_queue->q_prev = NULL; 
} 

status_t enqueue(queue_node_t* p_queue, vnode_t* new_pv_node) 
{
    q_generic_insert(p_queue->q_prev, q_get_node(new_pv_node), p_queue); 
    return (SUCCESS); 
} 

status_t dequeue(queue_node_t* p_queue, vnode_t** pp_node) 
{
    if(is_queue_empty(p_queue) == TRUE) 
    {
        *pp_node = NULL; 
        return (QUEUE_EMPTY); 
    } 

    *pp_node = p_queue->q_next->pv_node; 
    q_generic_delete(p_queue->q_next); 
    return (SUCCESS); 
} 

int is_queue_empty(queue_node_t* p_queue) 
{
    return (p_queue->q_next == p_queue && p_queue->q_prev == p_queue); 
} 

status_t destroy_queue(queue_node_t* p_queue) 
{
    queue_node_t* pq_run = NULL; 
    queue_node_t* pq_run_next = NULL; 

    for(pq_run = p_queue->q_next; pq_run != p_queue; pq_run = pq_run->q_next) 
    {
        pq_run_next = pq_run; 
        free(pq_run); 
        pq_run = pq_run->q_next; 
    } 
    free(p_queue); 
    return (SUCCESS); 
} 

void q_generic_insert(queue_node_t* pq_beg, queue_node_t* pq_mid, queue_node_t* pq_end) 
{
    pq_mid->q_prev = pq_beg; 
    pq_mid->q_next = pq_end; 
    pq_end->q_prev = pq_mid; 
    pq_beg->q_next = pq_mid; 
} 

void q_generic_delete(queue_node_t* p_delete_node) 
{
    p_delete_node->q_prev->q_next = p_delete_node->q_next; 
    p_delete_node->q_next->q_prev = p_delete_node->q_prev; 
    free(p_delete_node); 
} 

queue_node_t* get_queue_node(vnode_t* pv_node) 
{
    queue_node_t* pq_new_node = NULL; 

    pq_new_node = (queue_node_t*)xmalloc(sizeof(queue_node_t)); 
    pq_new_node->pv_node = pv_node; 
    pq_new_node->q_prev = NULL; 
    pq_new_node->q_next = NULL; 

    return (pq_new_node); 
} 

/* Vertical list interface */ 
vlist_t* v_create_list(void) 
{
    vlist_t* pv_new_list = NULL; 

    pv_new_list = v_get_list_node(0); 
    pv_new_list->ph_head_node = NULL; 
    pv_new_list->v_next = pv_new_list; 
    pv_new_list->v_prev = pv_new_list; 
    
    return (pv_new_list); 
} 

vlist_t* v_create_list(void) 
{
    vlist_t* pv_new_list = NULL; 

    pv_new_list = v_get_list_node(0); 
    pv_new_list->ph_head_node = NULL; 
    pv_new_list->v_next = pv_new_list; 
    pv_new_list->v_prev = pv_new_list; 

    return (pv_new_list); 
} 

vlist_t* v_create_list(void) 
{
    vlist_t* pv_new_list = NULL; 

    pv_new_list = v_get_list_node(0); 
    pv_new_list->ph_head_node = NULL; 
    pv_new_list->v_next = pv_new_list; 
    pv_new_list->v_prev = pv_new_list; 

    return (pv_new_list); 
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

vnode_t* v_get_list_node(vertex_t new_vertex) 
{
    vnode_t* pv_new_node = NULL; 
    pv_new_node = (vnode_t*)xmalloc(sizeof(vnode_t)); 
    pv_new_node->color = WHITE; 
    pv_new_node->ph_head_node = NULL; 
    pv_new_node->v = new_vertex; 
    pv_new_node->v_next = NULL; 
    pv_new_node->v_prev = NULL; 

    return (pv_new_node); 
} 

vnode_t* v_get_list_node(vertex_t new_vertex) 
{
    vnode_t* pv_new_node = NULL; 

    pv_new_node = (vnode_t*)xmalloc(sizeof(vnode_t)); 
    pv_new_node->color = WHITE; 
    pv_new_node->ph_head_node = NULL; 
    pv_new_node->v = new_vertex; 
    pv_new_node->v_next = NULL; 
    pv_new_node->v_prev = NULL; 

    return (pv_new_node); 
} 

vnode_t* v_get_list_node(vertex_t new_vertex) 
{
    vnode_t* pv_new_node = NULL; 

    pv_new_node = (vnode_t*)xmalloc(sizeof(vnode_t)); 
    pv_new_node->color = WHITE; 
    pv_new_node->ph_head_node = NULL; 
    pv_new_node->v = new_vertex; 
    pv_new_node->v_prev = NULL; 
    pv_new_node->v_next = NULL; 

    return (pv_new_node); 
} 

/* Horizontal list interface */ 
hlist_t* h_create_list(void) 
{
    hnode_t* ph_head_node = NULL; 

    ph_head_node = h_get_list_node(-1); 
    ph_head_node->h_next = ph_head_node; 
    ph_head_node->h_prev = ph_head_node; 

    return (ph_head_node); 
} 

hlist_t* h_create_list(void) 
{
    hnode_t* ph_head_node = NULL; 

    ph_head_node = h_get_list_node(-1); 
    ph_head_node->h_next = ph_head_node; 
    ph_head_node->h_prev = ph_head_node; 

    return (ph_head_node); 
} 

hlist_t* h_create_list(void) 
{
    hnode_t* ph_head_node = NULL; 

    ph_head_node = h_get_list_node(-1); 
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

// helpers 
void h_generic_insert(hnode_t* ph_beg, hnode_t* ph_mid, hnode_t* ph_end) 
{   
    ph_mid->h_prev = ph_beg; 
    ph_mid->h_next = ph_beg; 
    ph_beg->h_next = ph_mid; 
    ph_end->h_prev = ph_mid; 
} 

void h_generic_insert(hnode_t* ph_beg, hnode_t* ph_mid, hnode_t* ph_end) 
{
    ph_mid->h_prev = ph_beg; 
    ph_mid->h_next = ph_end; 
    ph_end->h_prev = ph_beg; 
    ph_beg->h_next = ph_mid; 
} 

void h_generic_insert(hnode_t* ph_beg, hnode_t* ph_mid, hnode_t* ph_end) 
{
    ph_mid->h_prev = ph_beg; 
    ph_mid->h_next = ph_end; 
    ph_end->h_prev = ph_mid; 
    ph_beg->h_next = ph_mid; 
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

hnode_t* h_search_node(hlist_t* ph_list, vertex_t s_vertex) 
{
    for(hnode_t* ph_run = ph_list->h_next; ph_run != ph_list; ph_run = ph_run->h_next) 
        if(ph_run->v == s_vertex) 
            return (ph_run); 
    return (NULL); 
} 

hnode_t* h_search_node(hlist_t* ph_list, vertex_t s_vertex) 
{
    for(hnode_t* ph_run = ph_list->h_next; ph_run != ph_list; ph_run=ph_run->h_next) 
        if(ph_run->v == s_vertex) 
            return (ph_run); 
    return (NULL); 
} 

hnode_t* h_search_node(hlist_t* ph_list, vertex_t s_vertex) 
{
    for(hnode_t* ph_run = ph_list->h_next; ph_run != ph_list; ph_run = ph_run->h_next) 
        if(ph_run->v == s_vertex) 
            return (ph_run); 
    return (NULL); 
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
    ph_new_node->v == new_vertex; 
    ph_new_node->h_prev = NULL; 
    ph_new_node->h_next = NULL; 

    return (ph_new_node); 
} 

hnode_t* h_get_list_node(vertex_t new_vertex) 
{
    hnode_t* ph_new_node = NULL; 

    ph_new_node = (hnode_t*)xmalloc(sizeof(hnode_t)); 
    ph_new_node->v == new_vertex; 
    ph_new_node->h_prev = NULL; 
    ph_new_node->h_next = NULL; 

    return (ph_new_node); 
} 

/* General purpose helper routines */ 
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
