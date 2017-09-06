void inOrder(node *root) {
    if (root->left) {
        inOrder(root->left);
    }
    
    cout << root->data << ' ';
    
    if (root->right) {
        inOrder(root->right);
    }
}
