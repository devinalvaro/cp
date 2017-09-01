int CompareLists(Node *headA, Node *headB)
{
    while (headA != nullptr && headB != nullptr) {
        if (headA->data != headB->data)
            return 0;

        headA = headA->next;
        headB = headB->next;
    }

    if (headA == nullptr ^ headB == nullptr)
        return 0;

    return 1;
}
