Node* MergeLists(Node *headA, Node* headB)
{
  // This is a "method-only" submission. 
  // You only need to complete this method
  
  if (headA == nullptr)
    return headB;
  if (headB == nullptr)
    return headA;
  
  if (headA->data < headB->data) {
    headA->next = MergeLists(headA->next, headB);
    
    return headA;
  } else {
    headB->next = MergeLists(headA, headB->next);
    
    return headB;
  }
}
