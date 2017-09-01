Node* RemoveDuplicates(Node *head)
{
  // This is a "method-only" submission. 
  // You only need to complete this method. 
  
  if (head == nullptr)
    return head;
  
  Node *node = head;
  while (node != nullptr) {
    Node *nextNode = node->next;
    while (nextNode != nullptr && nextNode->data == node->data) {
      nextNode = nextNode->next;
    }
    node->next = nextNode;
    
    node = node->next;
  }
  
  return head;
}
