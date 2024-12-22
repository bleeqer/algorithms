#include <stdio.h>
#include <stdlib.h>
struct Node {
    int item;
    struct Node* left;
    struct Node* right;
};

void inorderTraversal(struct Node* root) {
    if (root == NULL) {
        return;
    }

    inorderTraversal(root->left);
    printf("%d ->", root->item);
    inorderTraversal(root->right);
}

void preorderTraversal(struct Node* root) {
    if (root == NULL) {
        return;
    }

    printf("%d ->", root->item);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

void postorderTraversal(struct Node* root) {
    if (root == NULL) {
        return;
    }

    postorderTraversal(root->left);
    postorderTraversal(root->right);
    printf("%d ->", root->item);
}

struct Node* createNode(int value) {
    struct Node* newNode = malloc(sizeof(struct Node));

    newNode->item = value;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

void insertLeft(struct Node* root, int value) {
    root->left = createNode(value);
}

void insertRight(struct Node* root, int value) {
    root->right = createNode(value);
}

int main() {
    struct Node* root = createNode(1);
    insertLeft(root, 12);
    insertRight(root, 9);
    insertLeft(root->left, 5);
    insertRight(root->left, 6);

    printf("Inorder traversal\n");
    inorderTraversal(root);
    printf("\n");

    printf("Preorder traversal\n");
    preorderTraversal(root);
    printf("\n");

    printf("Postorder traversal\n");
    postorderTraversal(root);
}