void levelOrder(node *root)
{
    queue<node *> nodes;
    nodes.push(root);

    while (!nodes.empty()) {
        node *root = nodes.front();
        nodes.pop();

        cout << root->data << ' ';

        if (root->left) {
            nodes.push(root->left);
        }
        if (root->right) {
            nodes.push(root->right);
        }
    }
}
