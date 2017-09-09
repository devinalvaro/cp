int height(node *root)
{
    if (!root)
        return -1;
    return root->ht;
}

node *rightRotate(node *root)
{
    node *leftChild = root->left;

    root->left = leftChild->right;
    leftChild->right = root;

    root->ht = 1 + max(height(root->left), height(root->right));
    leftChild->ht = 1 + max(height(leftChild->left), height(leftChild->right));

    return leftChild;
}

node *leftRotate(node *root)
{
    node *rightChild = root->right;

    root->right = rightChild->left;
    rightChild->left = root;

    root->ht = 1 + max(height(root->left), height(root->right));
    rightChild->ht =
        1 + max(height(rightChild->left), height(rightChild->right));

    return rightChild;
}

int value(node *root)
{
    if (!root)
        return -1;
    return root->val;
}

node *insert(node *root, int val)
{
    if (!root) {
        root = new node;
        root->val = val;
        root->ht = 0;

        return root;
    }

    if (val < root->val) {
        root->left = insert(root->left, val);
    } else {
        root->right = insert(root->right, val);
    }

    root->ht = 1 + max(height(root->left), height(root->right));

    int balance = height(root->left) - height(root->right);

    if (balance > 1 && val < root->left->val) {
        root = rightRotate(root);
    } else if (balance > 1 && val > root->left->val) {
        root->left = leftRotate(root->left);
        root = rightRotate(root);
    } else if (balance < -1 && val > root->right->val) {
        root = leftRotate(root);
    } else if (balance < -1 && val < root->right->val) {
        root->right = rightRotate(root->right);
        root = leftRotate(root);
    }

    return root;
}
