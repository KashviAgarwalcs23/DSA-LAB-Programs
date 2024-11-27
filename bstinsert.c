#include <stdio.h>
#include <stdlib.h>

struct node {
    int value;
    struct node *leftnode;
    struct node *rightnode;
};
typedef struct node *NODE;

NODE getnode() {
    NODE ptr = (NODE)malloc(sizeof(struct node));
    if (ptr == NULL) {
        printf("Memory not allocated\n");
        return NULL;
    }

    int item;
    printf("Enter the item to be inserted: ");
    scanf("%d", &item);

    ptr->value = item;
    ptr->leftnode = NULL;
    ptr->rightnode = NULL;

    return ptr;
}

NODE insert(NODE root, NODE temp) {
    if (root == NULL) {
        return temp;
    }

    if (temp->value < root->value) {
        if (root->leftnode == NULL) {
            root->leftnode = temp;
        } else {
            insert(root->leftnode, temp);
        }
    } else if (temp->value > root->value) {
        if (root->rightnode == NULL) {
            root->rightnode = temp;
        } else {
            insert(root->rightnode, temp);
        }
    }

    return root;
}

void preorder(NODE root) {
    if (root != NULL) {
        printf("%d ", root->value);
        preorder(root->leftnode);
        preorder(root->rightnode);
    }
}

void postorder(NODE root) {
    if (root != NULL) {
        postorder(root->leftnode);
        postorder(root->rightnode);
        printf("%d ", root->value);
    }
}

void inorder(NODE root) {
    if (root != NULL) {
        inorder(root->leftnode);
        printf("%d ", root->value);
        inorder(root->rightnode);
    }
}

int main() {
    NODE n1 = NULL;
    int choice, item;
    int still_continue = 1;

    while (still_continue) {
        printf("\nEnter 1 for inserting a value, 2 for preorder traverse, 3 for inorder traverse, 4 for postorder traverse, 5 for exiting: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                {
                    NODE temp = getnode();
                    if (temp != NULL) {
                        n1 = insert(n1, temp);
                    }
                }
                break;
            case 2:
                printf("Preorder traversal: ");
                preorder(n1);
                break;
            case 3:
                printf("Inorder traversal: ");
                inorder(n1);
                break;
            case 4:
                printf("Postorder traversal: ");
                postorder(n1);
                break;
            case 5:
                printf("Exiting the program\n");
                still_continue = 0;
                break;
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
