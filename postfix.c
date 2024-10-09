#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 100 // Maximum size of the stack and expressions

char stack[MAX];
int top = -1;

// Function to push an element to the stack
void push(char ele) {
    if (top >= MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = ele;
}

// Function to pop an element from the stack
char pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return -1;
    }
    return stack[top--];
}

// Function to check the precedence of operators
int precedence(char op) {
    switch (op) {
        case '+':
        case '-':
            return 1; // Lowest precedence
        case '*':
        case '/':
            return 2; // Higher precedence
        case '^':
            return 3; // Highest precedence
        default:
            return 0;
    }
}

// Function to check if the character is an operator
int isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^';
}

// Function to convert infix to postfix
void infixToPostfix(char infix[], char postfix[]) {
    int i = 0, j = 0;
    char ch;

    // Push a special marker to the stack
    push('#');

    // Iterate through the infix expression
    while (infix[i] != '\0') {
        ch = infix[i];

        // If the character is an operand (letter or digit), add it to postfix
        if (isalnum(ch)) {
            postfix[j++] = ch;
        }
        // If the character is '(', push it to the stack
        else if (ch == '(') {
            push(ch);
        }
        // If the character is ')', pop until '(' is encountered
        else if (ch == ')') {
            while (stack[top] != '(') {
                postfix[j++] = pop();
            }
            pop(); // Pop the '(' from the stack
        }
        // If the character is an operator
        else if (isOperator(ch)) {
            while (isOperator(stack[top]) && precedence(stack[top]) >= precedence(ch)) {
                postfix[j++] = pop();
            }
            push(ch);
        }

        i++;
    }

    // Pop the remaining operators from the stack
    while (stack[top] != '#') {
        postfix[j++] = pop();
    }

    postfix[j] = '\0'; // Null-terminate the postfix expression
}

int main() {
    char infix[MAX], postfix[MAX];

    printf("Enter infix expression: ");
    scanf("%s", infix); // You can also use gets(infix) if you want to allow spaces

    infixToPostfix(infix, postfix);

    printf("Postfix expression: %s\n", postfix);

    return 0;
}
