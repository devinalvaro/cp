/*
    Delete Node at a given position in a linked list
    Node is defined as

    struct Node
    {
        int data;
        struct Node *next;
    }
*/

Node *Delete(Node *head, int position)
{
    // Complete this method

    if (position == 0)
        return head->next;

    int i = 1;
    Node *prev = head;
    while (i < position) {
        i++;
        prev = prev->next;
    }

    prev->next = prev->next->next;

    return head;
}
