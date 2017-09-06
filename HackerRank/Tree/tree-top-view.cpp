void leftTopView(node *root)
{
    if (!root)
        return;

    leftTopView(root->left);

    cout << root->data << ' ';
}

void rightTopView(node *root)
{
    if (!root)
        return;

    cout << root->data << ' ';

    rightTopView(root->right);
}

void topView(node *root)
{
    leftTopView(root->left);

    cout << root->data << ' ';

    rightTopView(root->right);
}
