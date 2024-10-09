#include <stdio.h>
#include <stdlib.h>
#define STACK_SIZE 5

void push(int *top, int item , int stack[])
{
    if (*top == STACK_SIZE - 1)
        printf("The Stack is full\n");
    else {
        stack[++(*top)] = item;
        printf("Item pushed: %d\n", item);
    }
}

int pop(int *top, int stack[])
{
    if (*top == -1) {
        printf("The stack is underflown\n");
        return -1;
    } else {
        int item_del = stack[(*top)--];
        return item_del;
    }
}

void display(int *top, int stack[])
{
    if (*top == -1)
        printf("The stack is in underflow condition.\n");
    else {
        printf("Stack contents: ");
        for (int i = 0; i <= *top; i++) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

void main()
{
    int stack[STACK_SIZE], top = -1, item_del, choice, item;

    while (1) {
        printf("\nEnter your choice for push(1), pop(2), and display(3), exit(4): ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("Enter the item to input: ");
                scanf("%d", &item);
                push(&top, item, stack);
                break;
            
            case 2:
                item_del = pop(&top, stack);
                if (item_del != -1) {
                    printf("Item popped: %d\n", item_del);
                }
                break;
            
            case 3:
                display(&top, stack);
                break;
            
            case 4:
                printf("You have exited the program.\n");
                exit(0);
            
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}
