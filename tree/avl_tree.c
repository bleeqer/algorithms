#include <stdio.h>
#include <stdlib.h>

struct Node {
    int key;
    struct Node* left;
    struct Node* right;
    int height;
};

int max(int a, int b) {
    return a > b ? a : b;
}


int getHeight(struct Node* n) {
    if (n == NULL) {
        return 0;
    }

    return n->height;
}

// get the balance factor of the node
int getBalanceFactor(struct Node* n) {
    if (n == NULL) {
        return 0;
    }
    // get the difference of the height of the left and right child
    return getHeight(n->left) - getHeight(n->right);
}

struct Node* createNode(int key) {
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;

    return node;
}

struct Node* rightRotate(struct Node* y) {
    
    // get the left child of the node
    struct Node* x = y->left;
    // get the right child of the left child
    struct Node* T2 = x->right;

    // perform the right rotation   
    x->right = y;
    y->left = T2;

    // update the height of the node
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

    // return the new root
    return x;
}

struct Node* leftRotate(struct Node* x) {
    struct Node* y = x->right;
    struct Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

    return y;
}

struct Node* insert(struct Node* node, int key) {
    if (node == NULL) {
        return createNode(key);
    }

    if (key < node->key) { // if the key is less than the node's key, insert it to the left
        node->left = insert(node->left, key);
    } else if (key > node->key) { // if the key is greater than the node's key, insert it to the right
        node->right = insert(node->right, key);
    } else {
        return node; // if the key is already in the tree, do nothing
    }

    // update the height of the node
    node->height = 1 + max(getHeight(node->left), getHeight(node->right));

    // get the balance factor of the node
    int balance = getBalanceFactor(node);

    // left left case
    if (balance > 1 && key < node->left->key) {
        return rightRotate(node);
    }

    // left right case
    if (balance > 1 && key > node->left->key) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // right right case
    if (balance < -1 && key > node->right->key) {
        return leftRotate(node);
    }

    // right left case
    if (balance < -1 && key < node->right->key) {
        node->right = rightRotate(node->right);
        return leftRotate(node);

}

    return node;
}

void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->key);
        inorder(root->right);
    }
}

int main() {
    struct Node* root = NULL;
    
    root = insert(root, 1);
    root = insert(root, 2);
    root = insert(root, 4);
    root = insert(root, 5);
    root = insert(root, 6);
    root = insert(root, 3);

    printf("Inorder traversal of AVL tree:\n");
    inorder(root);

    return 0;
}
