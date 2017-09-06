node *lca(node *root, int value1,int value2)
{
    if (value1 > value2) {
        swap(value1, value2);
    }
    
    if (value1 > root->data)
        return lca(root->right, value1, value2);
    if (value2 < root->data)
        return lca(root->left, value1, value2);
    return root;
}
