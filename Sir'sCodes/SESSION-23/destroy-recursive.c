//  doubly circular linked list destroy - intuitive version 
//  may require some corrections 

void destroy(list_t* p_list, node_t* pNode)
{
    node_t* pNode_prev; 

    if(pNode == p_list)
    {
        free(pNode); 
        return; 
    }

    pNode_prev = pNode->prev; 
    free(pNode); 
    destroy(p_list, pNode_prev); 

}

// Trigger call 
// destroy(p_list->prev); 