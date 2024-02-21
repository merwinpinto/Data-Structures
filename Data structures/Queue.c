#include<stdio.h>

#include<stdio.h>
#define max 5
int Queue[max];
int front = -1,rear =-1;

void Enqueue(int num)
{
    if(rear==max-1)
    {
        printf("Queue full ");
    }
    else
    {
        Queue[rear]=num;
        rear++;
    }
}

void DelQ()
{
    int val;
    if(front == rear)
    {
        printf("Queue empty");
    }

    else
    {
        val = Queue[front];
        front++;
    }
}

void display()
{
    if(front == rear)
    {
        printf("Queue empty");
    }

    for(int i=front ; i<rear ;i++)
    {
        printf("%d",Queue[i]);
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
        Enqueue(num);
        break;
        
        case 2:
        display();
        break;

        case 3:
        DelQ();
        break;

    
        default:
            break;
        }
    }
}