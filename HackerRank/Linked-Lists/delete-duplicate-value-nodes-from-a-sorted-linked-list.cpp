Node *RemoveDuplicates(Node *head)
{
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
