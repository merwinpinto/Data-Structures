#include<stdio.h>
#define max 100
int top , stack[max];
void push(int n)
{
    if(top == max - 1)
    {
        printf("Stack full !");
    }

    else
    {
        top++;
        stack[top] = n;
    }
}

void pop()
{
    int val1;
    if(top == - 1)
    {
        printf("Stack Empty !");
    }

    else
    {
        val1 = stack[top];
        top--;
    }
}

void display()
{
    int i;
    if(top == - 1)
    {
        printf("Stack Empty !");
    }
    
    for (i=top ; i >0 ; i--)
    {
        printf("%d ",stack[i]);
    }
}

int main()
{
    int option;
    int num,val1;

    while(option != 4)
    {
        printf("\n1. Insert\n");
        printf("2. Display\n");
        printf("3. Pop\n");
        printf("4. Exit\n");

        printf("\nEnter your option : ");
        scanf("%d", &option);

        switch (option)
        {
        case 1: 
        printf("Enter a number : ");
        scanf("%d",&num);
        push(num);
        break;
        
        case 2:
        display();
        break;

        case 3:
        pop();
        break;

    
        default:
            break;
        }
    }
}