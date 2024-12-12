// 3) Design, Develop and Implement a Program in C for the following operations on
// expression.
// a. Read infix expression String (INFIX)
// b. Convert the infix expression (INFIX) to a postfix expression using stacks.
// c. Evaluate the postfix expression using stacks.
// d. Check the following test cases.
// Test Case 1: Infix = “(1+ (2-3) *4)”, Postfix=”123-4*+”, Result = -3
// Test Case 2: Infix = “4/2-2+3*3-4*2”, Postfix=”42/233*42*-+-”, Result = -1
// Note: Program should support for both parenthesized and free parenthesized expressions
// with the operators: +, -, *, /, % (Remainder), ^ (Power) and alphanumeric operands.

CODE:

#include <stdio.h>
#include <ctype.h>
#include <math.h>
char stack[100];
int top = -1;
void push(char x)
{
    stack[++top] = x;
}
char pop()
{
    if (top == -1)
        return -1;
    else
        return stack[top--];
}
int priority(char x)
{
    if (x == '(')
        return 0;
    if (x == '+' || x == '-')
        return 1;
    if (x == '*' || x == '/' || x == '%')
        return 2;
    if (x == '^')
        return 3;
    return 0;
}
void main()
{
    char exp[20];
    char *e, x;
    printf("enter the expression : ");
    scanf("%s", exp);
    printf("\n");
    e = exp;
    while (*e != '\0')
    {
        if (isalnum(*e))
            printf("%c", *e);
        else if (*e == '(')
            push(*e);
        else if (*e == ')')
        {
            while ((x = pop()) != '(')
                printf("%c", x);
        }
        else
        {
            while (priority(stack[top]) >= priority(*e))
                printf("%c", pop());
            push(*e);
        }
        e++;
    }
    while (top != -1)
    {
        printf("%c", pop());
    }
    char postfix[20];
    char *p;
    int n1, n2, n3, num;
    printf("\nEnter the result to calculate :: ");
    scanf("%s", postfix);
    p = postfix;
    while (*p != '\0')
    {
        if (isdigit(*p))
        {
            num = *p - 48;
            push(num);
        }
        else
        {
            n1 = pop();
            n2 = pop();
            switch (*p)
            {
            case '+':
            {
                n3 = n2 + n1;
                break;
            }
            case '-':
            {
                n3 = n2 - n1;
                break;
            }
            case '*':
            {
                n3 = n2 * n1;
                break;
            }
            case '/':
            {
                n3 = n2 / n1;
                break;
            }
            case '^':
            {
                n3 = pow(n2, n1);
                break;
            }
            case '%':
            {
                n3 = n2 % n1;
                break;
            }
            }
            push(n3);
        }
        p++;
    }
    printf("\nThe result of the converted postfix = %d", pop());
}
