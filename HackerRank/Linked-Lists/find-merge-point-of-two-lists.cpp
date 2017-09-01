int FindMergeNode(Node *headA, Node *headB)
{
    // Complete this function
    // Do not write the main method. 
    
    int n = 0;
    Node *nodeA = headA;
    while (nodeA) {
        nodeA = nodeA->next;
        n++;
    }
    
    int m = 0;
    Node *nodeB = headB;
    while (nodeB) {
        nodeB = nodeB->next;
        m++;
    }
    
    nodeA = headA;
    nodeB = headB;
    
    while (n != m) {
        if (n > m) {
            nodeA = nodeA->next;
            n--;
        } else {
            nodeB = nodeB->next;
            m--;
        }
    }
    
    while (nodeA != nodeB) {
        nodeA = nodeA->next;
        nodeB = nodeB->next;
    }
    
    return nodeA->data;
}
