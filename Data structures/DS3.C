#include<stdio.h>
#define Max 100
#define true 1
#define false 0

int top1 = -1;
int top2 = -1;
int stack1[Max];
int stack2[Max];
int count = 0;

int stackE1()
{
	if(top1 == -1 )
		return true;
	else
		return false;

}

int stackF1()
{
	if(top1 == Max - 1 )
		return true;
	else
		return false;

}

void push1(int Element)
{
	if(stackF1())
		printf("Stack full !");
	else
		top1 = top1+1;
		stack1[top1] = Element;
}

int pop1()
{
	int x;
	if(stackE1())
		printf("Stack Empty !");

	else
		top1 = top1-1;
		x = stack1[top1];
}
int stackE2()
{
	if(top2 == -1 )
		return true;
	else
		return false;

}

int stackF2()
{
	if(top2 == Max - 1 )
		return true;
	else
		return false;

}

void push2(int Element)
{
	if(stackF2())
		printf("Stack full !");
	else
		top2 = top2+1;
		stack2[top2] = Element;
}

int pop2()
{
	int x;
	if(stackE2())
		printf("Stack Empty !");
	else
		top2 = top2 - 1;
		x = stack2[top2];
}

void stackqueue()
{
    int i;
    for (i = 0;i <= count;i++)
    {
        push2(pop1());
    }
    pop2();

    count--;

    for (i = 0;i <= count;i++)
    {
        push1(pop2());
    }
}

void disp()
{
	int i;
	int top = -1;
	for(i = top ; i > -1 ; i--)
	{
	     printf("%d",stack1[i]);
	}
}

void enqueue()
{
    int data, i;
    printf("Enter data into queue");
    scanf("%d", &data);
    push1(data);
    count++;
}


int main()
{
	int stack1[Max];
	int stack2[Max];
	int choice,num;
	//clrscr();
	printf("Enter ch : ");
	scanf("%d",&choice);
	while(choice != 3)
	{
		switch(choice)
	{
		case 1:
			enqueue()	;

		case 2:
			printf("Display Array ! \n");
			stackqueue();
			break;

		case 3:
			printf("Break !");

		default :
			printf("Enter again correct number choice :");
			break;
	}
       return 0;
	}
	
}