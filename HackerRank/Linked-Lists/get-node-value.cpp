int GetNode(Node *head,int positionFromTail)
{
  // This is a "method-only" submission. 
  // You only need (to complete this method. 
  
  Node *node = head;
  int i = 0;
  while (i < positionFromTail) {
    node = node->next;
    i++;
  }
  
  Node *prev = head;
  while (node->next != nullptr) {
    node = node->next;
    prev = prev->next;
  }
  
  return prev->data;
}
