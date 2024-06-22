#include <stdio.h>
#include <stdlib.h>

struct No {
    int data;
    struct No *left;
    struct No *right;
};


struct No* createNode(int data) {
    struct No *novo_no = (struct No*)malloc(sizeof(struct No));
    novo_no->data = data;
    novo_no->left = NULL;
    novo_no->right = NULL;
    return novo_no;
}

//Inserção de Nós
struct No* insertNo(struct No* root, int data) {
    
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

//Percursos na Árvore

//Em ordem
void inOrder(struct No* root) {
    if (root != NULL) {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

//Pré-Ordem
void preOrder(struct No* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

//Pós-Ordem
void postOrder(struct No* root) {
    if (root != NULL) {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->data);
    }
}

//Busca de Nós
struct No* searchNode(struct No* root, int key) {
    
    if (root == NULL || root->data == key) {
        return root;
    }

    
    if (root->data < key) {
        return searchNo(root->right, key);
    }

    
    return searchNo(root->left, key);
}

//Remoção de Nós
struct Node* findMin(struct Node* node) {
    struct Node* current = node;
    while (current && current->left != NULL) {
        current = current->left;
    }
    return current;
}


struct Node* deleteNo(struct Node* root, int key) {
    
    if (root == NULL) {
        return root;
    }

    
    if (key < root->data) {
        root->left = deleteNo(root->left, key);
    }
    
    else if (key > root->data) {
        root->right = deleteNo(root->right, key);
    }
}