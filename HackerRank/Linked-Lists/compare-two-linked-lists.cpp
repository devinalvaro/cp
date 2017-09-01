int CompareLists(Node *headA, Node *headB)
{
    // This is a "method-only" submission.
    // You only need to complete this method

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
