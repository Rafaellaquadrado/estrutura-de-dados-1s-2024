#include <stdio.h>
#include <stdlib.h>

int main() {
    struct No* root = NULL;
    root = insertNo(root, 50);
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
    root = deleteNode(root, 20);
    printf("In-order traversal after deletion: ");
    inOrderTraversal(root);
    printf("\n");

    return 0;
}