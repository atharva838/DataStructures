#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char ch)
{
    stack[++top] = ch;
}

char pop()
{
    return stack[top--];
}

int precedence(char ch)
{
    if (ch == '^')
        return 3;
    if (ch == '*' || ch == '/')
        return 2;
    if (ch == '+' || ch == '-')
        return 1;
    return 0;
}

void infixToPostfix(char infix[], char postfix[])
{
    int i, j = 0;
    char ch;

    top = -1;

    for (i = 0; infix[i] != '\0'; i++)
    {
        ch = infix[i];

        if (ch == ' ')
            continue;

        if (isalnum((unsigned char)ch))
        {
            postfix[j++] = ch;
        }
        else if (ch == '(')
        {
            push(ch);
        }
        else if (ch == ')')
        {
            while (top != -1 && stack[top] != '(')
                postfix[j++] = pop();

            if (top != -1)
                pop();
        }
        else
        {
            while (top != -1 && stack[top] != '(' &&
                  (precedence(stack[top]) > precedence(ch) ||
                  (precedence(stack[top]) == precedence(ch) &&
                   ch != '^')))
            {
                postfix[j++] = pop();
            }

            push(ch);
        }
    }

    while (top != -1)
        postfix[j++] = pop();

    postfix[j] = '\0';
}

int evalPostfix(char postfix[])
{
    int s[MAX], t = -1;
    int i, a, b;
    char ch;

    for (i = 0; postfix[i] != '\0'; i++)
    {
        ch = postfix[i];

        if (ch == ' ')
            continue;

        if (isdigit((unsigned char)ch))
        {
            s[++t] = ch - '0';
        }
        else
        {
            b = s[t--];
            a = s[t--];

            switch (ch)
            {
                case '+': s[++t] = a + b; break;
                case '-': s[++t] = a - b; break;
                case '*': s[++t] = a * b; break;

                case '/':
                    if (b == 0)
                    {
                        printf("Error: Division by zero!\n");
                        return 0;
                    }
                    s[++t] = a / b;
                    break;

                case '^': s[++t] = (int)pow(a, b); break;
            }
        }
    }

    return s[t];
}

int main()
{
    char infix[MAX], postfix[MAX];

    printf("Enter infix expression (single-digit operands): ");
    scanf("%99s", infix);

    infixToPostfix(infix, postfix);

    printf("Postfix expression: %s\n", postfix);
    printf("Postfix evaluation: %d\n", evalPostfix(postfix));

    return 0;
}
