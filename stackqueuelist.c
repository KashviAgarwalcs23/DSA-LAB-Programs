#include <stdio.h>
#include <stdlib.h>

struct node {
    int value;
    struct node *next;
};
typedef struct node *NODE;

NODE getnode() {
    NODE ptr = (NODE)malloc(sizeof(struct node));
    if (ptr == NULL) {
        printf("Memory not allocated\n");
        return NULL;
    }
    return ptr;
}

NODE inst_beg(int item, NODE first) {
    NODE temp = getnode();
    if (temp == NULL) return first;
    temp->value = item;
    temp->next = first;
    return temp;
}

NODE inst_end(int value, NODE first) {
    NODE new = getnode();
    if (new == NULL) return first;
    new->value = value;
    new->next = NULL;

    if (first == NULL) {
        return new;
    }

    NODE current = first;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = new;
    return first;
}

NODE del_beg(NODE first) {
    if (first == NULL){
        printf("Linked list is empty");
        return NULL;
    }
    NODE temp;
    temp = first;
    first = first->next;
    free(temp);
    return first;
}


void display(NODE first) {
    NODE temp = first;
    while (temp != NULL) {
        printf("%d ", temp->value);
        temp = temp->next;
    }
    printf("\n");
}

void main() {
    NODE n1 = NULL;
    int choice, item, pos,choice2;
    int still_continue = 1;
    printf("enter the function you want to perform 1 for stacks and 2 for queue");
    scanf("%d",&choice2);
    switch(choice2){
    case 1:
       while (still_continue) {
        printf("Enter 1 for inserting the value , 2 for deleting the value ,  3 for displaying , 4 for exiting: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                 printf("Enter the item to be inserted: ");
        scanf("%d", &item);
                n1 = inst_beg(item, n1);
                break;
            case 2:
                n1 = del_beg( n1);
                break;
            case 3:
                display(n1);
                break;
            case 4:
                printf("Exiting the program\n");
                still_continue = 0;
                break;
            default:
                printf("Invalid choice\n");}
        }break;
 case 2:
     while (still_continue) {
        printf("Enter 1 for inserting the value , 2 for deleting the value ,  3 for displaying , 4 for exiting: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                  printf("Enter the item to be inserted: ");
        scanf("%d", &item);
                n1 = inst_end(item, n1);
                break;
            case 2:
                n1 = del_beg( n1);
                break;
            case 3:
                display(n1);
                break;
            case 4:
                printf("Exiting the program\n");
                still_continue = 0;
                break;
            default:
                printf("Invalid choice\n");
        }
        }break;
        default:
                printf("Invalid choice\n");}
    }



