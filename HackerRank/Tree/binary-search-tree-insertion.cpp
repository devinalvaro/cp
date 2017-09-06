node *insert(node *root, int value)
{
    if (!root) {
        root = new node;
        root->data = value;
    } else if (value <= root->data) {
        root->left = insert(root->left, value);
    } else {
        root->right = insert(root->right, value);
    }

    return root;
}
