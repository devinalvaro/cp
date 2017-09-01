/*
    Print elements of a linked list in reverse order as standard output
    head pointer could be NULL as well for empty list
    Node is defined as

    struct Node
    {
        int data;
        struct Node *next;
    }
*/

void ReversePrint(Node *head)
{
    // This is a "method-only" submission.
    // You only need to complete this method.

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
