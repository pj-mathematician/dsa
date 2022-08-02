// program to convert infix expression to postfix expression in C using stack
#include <stdio.h>
#include <stdlib.h>

void push(char *stack, char item)
{
    *stack = item;
    stack++;
}

void pop(char *stack)
{
    stack--;
}

void display(char *stack)
{
    while (*stack != '\0')
    {
        printf("%c ", *stack);
        stack++;
    }
    printf("\n");
}

void convert_infix_to_postfix(char *infix, char *postfix)
{
    char *stack = (char *)malloc(sizeof(char) * 10);
    int i, j = 0;
    for (i = 0; infix[i] != '\0'; i++)
    {
        if (infix[i] == '(')
        {
            push(stack, infix[i]);
        }
        else if (infix[i] == ')')
        {
            while (*stack != '(')
            {
                postfix[j] = *stack;
                pop(stack);
                j++;
            }
            pop(stack);
        }
        else if (infix[i] == '+' || infix[i] == '-' || infix[i] == '*' || infix[i] == '/')
        {
            while (*stack != '\0' && *stack != '(' && (infix[i] == '*' || infix[i] == '/'))
            {
                postfix[j] = *stack;
                pop(stack);
                j++;
            }
            push(stack, infix[i]);
        }
        else
        {
            postfix[j] = infix[i];
            j++;
        }
    }
    while (*stack != '\0')
    {
        postfix[j] = *stack;
        pop(stack);
        j++;
    }
    postfix[j] = '\0';
}

int main()
{
    char infix[100], postfix[100];
    printf("Enter the infix expression: ");
    scanf("%s", infix);
    convert_infix_to_postfix(infix, postfix);
    printf("Postfix expression: ");
    display(postfix);
    return 0;
}