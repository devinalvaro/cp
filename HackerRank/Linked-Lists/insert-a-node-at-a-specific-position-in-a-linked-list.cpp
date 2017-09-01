/*
    Insert Node at a given position in a linked list
    head can be NULL
    First element in the linked list is at position 0
    Node is defined as

    struct Node
    {
        int data;
        struct Node *next;
    }
*/

Node *InsertNth(Node *head, int data, int position)
{
    // Complete this method only
    // Do not write main function.

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
