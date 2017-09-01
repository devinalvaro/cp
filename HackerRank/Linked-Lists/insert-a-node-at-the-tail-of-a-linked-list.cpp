/*
    Insert Node at the end of a linked list
    head pointer input could be NULL as well for empty list
    Node is defined as

    struct Node
    {
        int data;
        struct Node *next;
    }
*/

Node *Insert(Node *head, int data)
{
    // Complete this method

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
