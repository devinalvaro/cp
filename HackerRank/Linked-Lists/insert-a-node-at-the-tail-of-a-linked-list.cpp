Node *Insert(Node *head, int data)
{
    Node *node = new Node;
    node->data = data;

    if (head == nullptr) {
        return node;
    } else {
        Node *last = head;

        while (last->next != nullptr) {
            last = last->next;
        }

        last->next = node;
    }

    return head;
}
