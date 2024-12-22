#include <stdio.h>
#include <stdlib.h>

struct Node {
    int key;
    struct Node* left;
    struct Node* right;
};

struct Node* createNewNode(int value) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->key = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node* findMin(struct Node* root) {
    if (root == NULL) {
        return NULL;
    } else if (root->left != NULL) {
        return findMin(root->left);
    }
    return root;
}

struct Node* searchNode(struct Node* root, int target) {
    if (root == NULL) {
        return NULL;
    }

    if (root->key == target) {
        return root;
    }

    if (root->key < target) {
        return searchNode(root->right, target);
    } else {
        return searchNode(root->left, target);
    }
}

struct Node* insertNode(struct Node* node, int value) {
    if (node == NULL) {
        return createNewNode(value);
    }

    if (value < node->key) {
        node->left = insertNode(node->left, value);
    } else if (value > node->key) {
        node->right = insertNode(node->right, value);
    }

    return node;
}

struct Node* deleteNode(struct Node* root, int value) {
    if (root == NULL) {
        return NULL;
    }

    if (value > root->key) {
        root->right = deleteNode(root->right, value);
    } else if (value < root->key) {
        root->left = deleteNode(root->left, value);
    } else {
        if (root->left == NULL && root->right == NULL) {
            free(root);
            return NULL;
        } else if (root->left == NULL || root->right == NULL) {
            struct Node* temp;
            if (root->left == NULL) {
                temp = root->right;
            } else {
                temp = root->left;
            }
            free(root);
            return temp;
        } else {
            struct Node* temp = findMin(root->right);
            root->key = temp->key;
            root->right = deleteNode(root->right, temp->key);
        }
    }
    return root;
}

void inOrder(struct Node* root) {
    if (root == NULL) {
        return;
    }

    inOrder(root->left);
    printf(" %d ", root->key);
    inOrder(root->right);
}

void preOrder(struct Node* root) {
    if (root == NULL) {
        return;
    }

    printf(" %d ", root->key);
    inOrder(root->left);
    inOrder(root->right);
}

void postOrder(struct Node* root) {
    if (root == NULL) {
        return;
    }

    inOrder(root->left);
    inOrder(root->right);
    printf(" %d ", root->key);
}

int main() {
    struct Node* root = NULL;

    root = insertNode(root, 50);
    insertNode(root, 30);
    insertNode(root, 20);
    insertNode(root, 40);
    insertNode(root, 70);
    insertNode(root, 60);
    insertNode(root, 80);

    if (searchNode(root, 60) != NULL) {
        printf("60 found\n");
    } else {
        printf("60 not found\n");
    }

    postOrder(root);
    printf("\n");
    
    preOrder(root);
    printf("\n");
    
    inOrder(root);
    printf("\n");

    struct Node* temp = deleteNode(root, 70);
    printf("After Delete: \n");
    inOrder(root);

    return 0;
}