#include <stdio.h>
#include <ctype.h>

char stack[50];
int top = -1;

void push(char x) {
    stack[++top] = x;
}

char pop() {
    return stack[top--];
}

int main() {
    char infix[50], postfix[50];
    int i = 0, k = 0;
    char ch;

    printf("Enter a valid parenthesized infix expression: ");
    scanf("%s", infix);

    while ((ch = infix[i++]) != '\0') {

        // If operand, add to postfix
        if (isalnum(ch)) {
            postfix[k++] = ch;
        }

        // If '(' push to stack
        else if (ch == '(') {
            push(ch);
        }

        // If operator push to stack
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            push(ch);
        }

        // If ')', pop operator and add to postfix
        else if (ch == ')') {
            while (stack[top] != '(') {
                postfix[k++] = pop();
            }
            pop(); // Remove '('
        }
    }

    postfix[k] = '\0';

    printf("Postfix Expression: %s\n", postfix);

    return 0;
}
