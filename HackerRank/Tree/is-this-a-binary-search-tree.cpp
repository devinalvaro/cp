bool checkBST(Node *root, Node *&prev)
{
    if (!root)
        return true;

    if (!checkBST(root->left, prev))
        return false;

    if (prev && prev->data >= root->data)
        return false;

    prev = root;
    return checkBST(root->right, prev);
}

bool checkBST(Node *root)
{
    Node *prev = nullptr;
    return checkBST(root, prev);
}
