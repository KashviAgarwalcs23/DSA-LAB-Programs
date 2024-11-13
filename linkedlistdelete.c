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

NODE inst_post(int pos, NODE first, int item) {
    NODE new = getnode();
    if (new == NULL) return first;
    new->value = item;

    if (pos == 1) {
        new->next = first;
        return new;
    }

    NODE current = first;
    for (int count = 1; count < pos - 1; count++) {
        if (current == NULL) {
            printf("Position out of bounds\n");
            free(new);
            return first;
        }
        current = current->next;
    }

    new->next = current ? current->next : NULL;
    if (current) {
        current->next = new;
    }
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

NODE del_end( NODE first) {
   if (first == NULL){
        printf("Linked list is empty");
        return NULL;
   }
   NODE temp,prev;
temp = first;
while(temp!=NULL){
    prev =temp;
    temp = temp->next;
}
  prev->next = NULL;
  free(temp);
  return first;
}



NODE del_post(int value, NODE first) {
    if (first == NULL){
        printf("Linked list is empty");
        return NULL;
   }
    NODE temp,prev;
temp = first;
while(temp!=NULL && temp->value){
    prev =temp;
    temp = temp->next;
}
if(temp->value ==value){
    prev->next = temp->next;
    free(temp);
    return first;
}
printf("value not found");
return first;
}

int main() {
    NODE n1 = NULL;
    int choice, item, pos;
    int still_continue = 1;
    while (still_continue) {
        printf("Enter the item to be inserted: ");
        scanf("%d", &item);
        printf("Enter 1 for inserting the value in the front, 2 for inserting the value in the end, 3 for inserting the value at the desired position, 4 for displaying the list, 5 for deleting the value in the front, 6 for deleting the value in the end, 7 for deleting the value ,8 for exiting: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                n1 = inst_beg(item, n1);
                break;
            case 2:
                n1 = inst_end(item, n1);
                break;
            case 3:
                printf("Enter the position in which you want to enter the value: ");
                scanf("%d", &pos);
                n1 = inst_post(pos, n1, item);
                break;
            case 4:
                display(n1);
                break;
            case 5:
                n1 = del_beg(n1);
                break;
                case 6:
                n1 = del_end(n1);
                break;
            case 7:
printf("Enter the value which you want to delete");
                scanf("%d", &pos);
                n1 = del_post( item,n1);
                break;

            case 8:
                printf("Exiting the program\n");
                still_continue = 0;
                break;
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
