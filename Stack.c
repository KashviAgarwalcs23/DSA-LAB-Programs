#include  <stdio.h>
#define STACK_SIZE 5

void push(int *top, int item , int stack[])
{
if (*top == STACK_SIZE)
printf("The Stack is full");
else {
stack[(*top)++] = item;
}
}

int pop(int *top,int item_del,int stack[])
{
if (*top ==-1){
printf("The stack is underflown");
return -1;
}
else{
item_del = stack[(*top)--];
return item_del;
}
}

void display(int *top, int stack[]){
if (*top ==-1)
printf("The stack is in underflow condition.");
else
printf("%d",stack[(*top)--]);
}

void main()
{ int stack[STACK_SIZE],top, item_del,choice,item;

while (stack[top]!= STACK_SIZE-1){
    printf("enter your choice for the push(1), pop(2) and display(3) function");
scanf("%d",&choice);
switch(choice){
case 1:
printf("enter the item to input");
scanf("%d",&item);
push(&top,item,stack);
break;

case 2:
item_del = pop(&top,item_del,stack);
printf("%d",item_del);
break;

case 3:
display(&top,stack);
break;

default:
printf("You have exited the program");
exit(0);
}
}
}
