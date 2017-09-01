Node* Reverse(Node *head)
{
  // Complete this method
  
  if (head == nullptr)
    return head;
  
  Node *reverseNode = new Node, *prevReverseNode = new Node;
  reverseNode->data = head->data;
  
  head = head->next;
  while (head != nullptr) {
    prevReverseNode = reverseNode;
    
    reverseNode = new Node;
    reverseNode->data = head->data;
    reverseNode->next = prevReverseNode;
    
    head = head->next;
  }
  
  return reverseNode;
}
