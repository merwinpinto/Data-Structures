#include<stdio.h>
#include<string.h>
#define max 20
int top = -1;
char stack[max];
char infix[max];
char postfix[max];

void push(char symbol)
{
    if(top == max - 1)
        printf("No str");

    top = top + 1;
    stack[top] = symbol;

}

char pop()
{
    char symbol;
    if(top == - 1)
        printf("No str");

    symbol = stack[top];
    top = top - 1;
    return symbol;
}


int precedence(char symbol)
{
    if(symbol == '*' || symbol == '/' )
        return 2;

    if(symbol == '+' || symbol == '-')
        return 1;

    return 0;
}

int infix_topost(char infix[])
{
    int i,len;
    int index=0;
    char symbol;
    char Element;

    len = strlen(infix);

    for(i = 0;i<len;i++)
    {
        symbol = infix[i];

        switch (symbol)
        {
        case '(':
                push(symbol);
                break;

        case ')':
                while((Element = pop())!= '(' )
                {
                    postfix[index] = Element;
                    index++;
                }
                break;

        case '*':
        case '/':
        case '+':
        case '-':
                while(!(top == -1) && precedence(stack[top]) >= precedence(symbol))
                {
                    postfix[index] = pop();
                    index ++;
                }
                push(symbol);
                break;
    
        
        
        default:
            postfix[index++]=symbol;
            break;
        }
        
    }

    while(!(top==-1))
    {
        postfix[index] = pop();
        index ++;
    }

    postfix[index] = '\0';
        
    return 0;
}


int main()
{
    printf("Enter Infix expression");
    scanf("%s",&infix);

    infix_topost(infix);
    printf("Postfix expression is %s",postfix);
    
}