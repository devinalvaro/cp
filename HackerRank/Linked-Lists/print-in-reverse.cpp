void ReversePrint(Node *head)
{
    if (head == nullptr)
        return;

    Node *reverseNode = new Node, *prevReverseNode = new Node;
    reverseNode->data = head->data;

    head = head->next;
    while (head != nullptr) {
        prevReverseNode = reverseNode;

        reverseNode = new Node;
        reverseNode->data = head->data;
        reverseNode->next = prevReverseNode;

        head = head->next;
    }

    while (reverseNode != nullptr) {
        cout << reverseNode->data << '\n';

        reverseNode = reverseNode->next;
    }
}
