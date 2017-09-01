Node *Delete(Node *head, int position)
{
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
