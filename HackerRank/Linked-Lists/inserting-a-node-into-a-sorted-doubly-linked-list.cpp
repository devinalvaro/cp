Node *SortedInsert(Node *head, int data)
{
    if (!head) {
        head = new Node;
        head->data = data;

        return head;
    }

    Node *node = head;
    while (node->next && node->next->data < data) {
        node = node->next;
    }

    Node *add = new Node;
    add->data = data;

    if (node->data > data) {
        add->next = node;
        add->prev = node->prev;

        node->prev = add;

        head = add;
    } else {
        add->next = node->next;
        add->prev = node;

        node->next = add;
    }

    return head;
}
