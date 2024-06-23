#include <stdio.h>
#include <stdlib.h>


struct No {
    int data;
    struct No* left;
    struct No* right;
};


struct No* createNode(int data) {
    struct No* novoNo = (struct Node*)malloc(sizeof(struct No));
    novoNo->data = data;
    novoNo->left = NULL;
    novoNo->right = NULL;
    return newNode;
}


struct No* insertNode(struct No* root, int data) {
    if (root == NULL) {
        return createNo(data);
    }
    if (data < root->data) {
        root->left = insertNo(root->left, data);
    } else if (data > root->data) {
        root->right = insertNo(root->right, data);
    }
    return root;
}


void inOrderTraversal(struct No* root) {
    if (root != NULL) {
        inOrderTraversal(root->left);
        printf("%d ", root->data);
        inOrderTraversal(root->right);
    }
}


void preOrderTraversal(struct No* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
}


void postOrderTraversal(struct No* root) {
    if (root != NULL) {
        postOrderTraversal(root->left);
        postOrderTraversal(root->right);
        printf("%d ", root->data);
    }
}


struct No* searchNode(struct No* root, int data) {
    if (root == NULL || root->data == data) {
        return root;
    }
    if (data < root->data) {
        return searchNo(root->left, data);
    }
    return searchNo(root->right, data);
}


struct No* findMinNo(struct No* node) {
    struct No* current = no;
    while (current && current->left != NULL) {
        current = current->left;
    }
    return current;
}


struct No* deleteNode(struct No* root, int data) {
    if (root == NULL) {
        return root;
    }
    if (data < root->data) {
        root->left = deleteNo(root->left, data);
    } else if (data > root->data) {
        root->right = deleteNo(root->right, data);
    } else {
        if (root->left == NULL) {
            struct No* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct No* temp = root->left;
            free(root);
            return temp;
        }
        struct No* temp = findMinNo(root->right);
        root->data = temp->data;
        root->right = deleteNo(root->right, temp->data);
    }
    return root;
}

int main() {
    struct No* root = NULL;
    root = insertNode(root, 50);
    insertNo(root, 30);
    insertNo(root, 20);
    insertNo(root, 40);
    insertNo(root, 70);
    insertNo(root, 60);
    insertNo(root, 80);

    printf("In-order traversal: ");
    inOrderTraversal(root);
    printf("\n");

    printf("Pre-order traversal: ");
    preOrderTraversal(root);
    printf("\n");

    printf("Post-order traversal: ");
    postOrderTraversal(root);
    printf("\n");

    printf("Searching for 40: ");
    struct No* searchResult = searchNo(root, 40);
    if (searchResult != NULL) {
        printf("Found\n");
    } else {
        printf("Not Found\n");
    }

    printf("Deleting 20\n");
    root = deleteNo(root, 20);
    printf("In-order traversal after deletion: ");
    inOrderTraversal(root);
    printf("\n");

    return 0;
}