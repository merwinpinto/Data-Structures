#include<stdio.h>
int top = -1;
#define max 10
int stack[max];

int push(int num)
{
    if(top == max - 1)
        return 0;

    top = top + 1;
    stack[top] = num;

}

int pop()
{
    int num;
    if(top == -1)
        return 0;

    num = stack[top];
    top= top - 1;
    return num;
}

int main()
{
    int rem,num,n;
    int dec;
    int i ;
    int arr[max];
    int t1=0,t2=1,t3;
    
    printf("Enter a number : ");
    scanf("%d",&num);

    dec = num;

    while(dec != 0)
    {
        
        rem = dec % 2;
        push(rem);
        dec = dec / 2;
    }

    while(top != -1)
    {
       printf("%d",pop());
    }
    return 0;
}