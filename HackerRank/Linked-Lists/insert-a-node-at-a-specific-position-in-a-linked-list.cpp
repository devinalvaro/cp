Node *InsertNth(Node *head, int data, int position)
{
    Node *node = new Node;
    node->data = data;

    if (position == 0) {
        node->next = head;

        return node;
    }

    int i = 1;
    Node *prev = head;
    while (i < position) {
        i++;
        prev = prev->next;
    }

    node->next = prev->next;
    prev->next = node;

    return head;
}
