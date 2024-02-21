#include<stdio.h>
#include<stdlib.h>
#define MAX 100
#define TRUE 1
#define FALSE 0
int top = -1;
int Rear = -1;
int Front = -1;
int Queue[MAX];
char stack[MAX];

struct node
{
    int data;
    struct node *Left;
    struct node *Right; 
    struct node *next;   
};

typedef struct node Node;

Node *head = NULL;

int stackFull() 
{    
    if(top >= MAX-1)
        return TRUE;
    else
        return FALSE;
}
 
int stackEmpty()  
{
 if(top == -1)
     return TRUE;
 else
     return FALSE;
}


// Node* push(Node* Element)  
// {
//      if (stackFull())
//         printf("Stack is Full \n");

//     else 
//         stack[++top] = Element;
// }

// Node* pop()
// {
//      if (stackEmpty())
//         printf("Stack is Empty \n");

//     else 
//       stack[top --];
// }

void push ( Node* Element )  
{  
    if ( head == NULL )  
    head = Element ;  

    else
    {
	Element->next = head ;
	head = Element ;
    }
}

Node* pop()
{
    Node *n;
    n = head;
    head = head->next ;
    return n;
}

// int Queue_Full()      //We use Rear in Full Queue
// {
//     int Rear;
//     if(Rear == MAX - 1)
//         return TRUE;
//     else
//         return FALSE;
// }

// int Queue_Empty()        //We use front in Empty Queue
// {
//     int Front;
//     if(Front == - 1)
//         return TRUE;
//     else
//         return FALSE;
// }


// int AddQ(int Element)
// {
    
//     if(Queue_Full())
//     printf("Queue Full !");

//     else
//      {
//         if(Queue_Full() && Front != 0)
//         Rear = -1;

//         Queue[Rear++] = Element ;
//        printf("Element inserted is %d ",Element);
//      }
    
// }

// int DelQ()
// {
//     if(Queue_Empty())
//     printf("Queue Empty !");
    
//     else
//     {
//       printf("\nDeleted element from the Queue is : %d\n",Queue[Front++]);
//       if(Front == MAX)
// 	 Front = 0;

//       if(Front-1 == Rear)
// 	 Front = Rear = -1;
//     }

    
// }

// created a node 
Node* accept_Newnode()
{
    Node *newnode;
    newnode = malloc(sizeof(Node));
    // printf("Enter data of leaf node to be inserted \n");    
    scanf("%c",&newnode->data);
    newnode->Left  = NULL;
    newnode->Right = NULL;
    return newnode;
}



Node* Preorder(Node *P)
{
    Node *root;
    P = root;
    do
    {
        while(P!=NULL)
        {
            if(P->Right!= NULL)
            {
                push(P->Right);
                P = P -> Left;
            }
        }
        P=pop();
    }while(!stackEmpty()&& P!=NULL);
   
   return P;
}

char getcharacter()
{
    int ch;
    printf("Enter L to insert in Left node \nor\nEnter R to insert in Right node");
    scanf("%c",&ch);
    return ch;
}

int main()
{
    Node *root = NULL, *newnode,*P;
    int option;
    char ch;
    clrscr();
    // newnode = accept_Newnode();

    // if(root == NULL)
    // {
    //     root = newnode;
    // }

    // else
    // {
    //     P = root;
    //     printf("Where do you want to add this Number : %d ",newnode->data);
    //     ch = getcharacter();

    //     if(ch == 'L' || 'l')
    //     {
    //         if(P->Left == NULL)
    //         {
    //             P->Left = newnode;
    //         }
    //     }

    //     else
    //     {
    //         P = P->Left;
    //     }

    //     if(ch == 'R' || 'r')
    //     {
    //         if(P->Right == NULL)
    //         {
    //             P->Right = newnode;
    //         }
    //     }

    //     else
    //     {
    //         P = P->Right;
    //     }
    // }

    printf("Enter Option for particular Operation to be performed \nOption 1 = Preorder transversal \nOption 2 = Mirror image of tree \nOption 3 = Height of Tree \nOption 4 = To Exit");
 do
 {
    printf("\nEnter Option : ");
    scanf("%d",&option);
    printf("\n\n");
    switch (option)
    {
     case 1:
	printf("Operation Performing is Preorder transversal \n");
	printf("\n\n");
	//newnode = accept_New_node();
	root = accept_Newnode();
	root->Left = accept_Newnode();
	root->Right = accept_Newnode();
	root->Left->Left = accept_Newnode();
	root->Left->Right = accept_Newnode();
	Preorder(root);
	break;

    case 2:
	printf("Operation Performing is Mirror image of tree  \n");
	printf("\n\n");
	break;

    case 3:
	printf("Operation Performing is Height of Tree   \n");
	printf("\n\n");
	break;

    case 4:
	printf("Code Exited");
	break;

    default:
	printf("Option not avalible ! \n");
	break;
    }
 }while(option!=4);

return 0;
}