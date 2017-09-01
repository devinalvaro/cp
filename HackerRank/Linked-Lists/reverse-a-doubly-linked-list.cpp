Node* Reverse(Node* head)
{
    // Complete this function
    // Do not write the main method. 
    
    if (!head)
        return head;
    
    Node *node = head;
    while (node->next) {
        Node *tempNext = node->next;
        
        node->next = node->prev;
        node->prev = tempNext;
        
        node = tempNext;
    }
    
    node->next = node->prev;
    node->prev = nullptr;
    
    return node;
}
