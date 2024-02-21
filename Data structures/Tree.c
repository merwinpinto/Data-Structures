#include<stdio.h>
#include<stdlib.h>
#define Max 100
#define True 1
#define False 0

struct node
{
    int data;
    struct node *Left;
    struct node *Right;   
};

typedef struct node Node;

Node* stack[Max];
Node *Queue[Max];
int top = -1;
int Rear = -1;
int Front = -1;
 
int stackFull() 
{    
    if(top == (Max-1))
        return True;
    else
        return False;
}
 
int stackEmpty()  
{
 if(top == -1)
     return True;
 else
     return False;
}

void Push(Node *Element)
{
        if(stackFull())
        {
                printf("Stack Full\n");
                return;
        }
        top=top+1;
        stack[top]=Element;
}

Node *Pop()
{
        Node *Element;
        if(stackEmpty())
        {
                printf("Stack Empty \n");
                exit(1);
        }
        Element=stack[top];
        top=top-1;
        return Element;
}


int Queue_Empty()
{
    int Front;
    if(Front == - 1 || Front == Rear + 1)
        return True;
    else
        return False;
}

Node *AddQ(Node *Element)
{
    
    if(Rear == Max-1)
    printf("Queue Full !");

    else
     {
        if(Front == -1)
            Front = 0;

        Queue[Rear] = Element ;
        Rear = Rear + 1;
     }
    
}

Node *DelQ()
{
    Node *Element;
    if(Queue_Empty()) 
    {
        printf("Queue Empty !");
        return 0;
    }
    Element = Queue[Front];
    Front = Front + 1;
    return Element;
}


Node* insert(Node* root, int data) 
{
    //allocated memeory 
    Node* new = malloc(sizeof(Node));
    new->data = data;
    new->Left = NULL;
    new->Right = NULL;

    // cheked if root null
    if (root == NULL)
    {
        root = new;
        return root;
    }

    //assign P with root and declare a paprent for P when null
    Node* P = root;
    Node* parent;

    while(1)
    {
        parent = P;

        if (data < P->data) 
        {
            P = P->Left;

            if (P == NULL) 
            {
                parent->Left = new;
                break;
            }
        } 
        
        else if (data > P->data) 
        {
            P = P->Right;
            if (P == NULL) 
            {
                parent->Right = new;
                break;
            }

        } 
        
        else 
        {
            printf("\nWarning: Value entered is being repeated");
            free(new);
            break;
        }
    }

    return root;
}

// Non recursive
Node *Preorder(Node *root)
{
     Node *P;
       P = root;
       
        if( P == NULL )
        {
                printf("Node is empty\n");
                return 0;
        }   
        Push(P);
        do
        {
                printf("%d  ",P->data);

                if(P->Right!=NULL)
                        Push(P->Right);

                if(P->Left!=NULL)
                        Push(P->Left);
                         
                         P = Pop();
        }while(!stackEmpty()&& P!=NULL);
        printf("\n");
}

// Recursive
// Node* Preorder(Node *P)
// {
//      if (P == NULL)
//         return 0;
//     printf("%d\t",P->data);
//     Preorder(P->Left);
//     Preorder(P->Right);
// }


void mirror(Node* root) 
{
    Node *temp,*P = root;
    
    if (root == NULL)
        return;

    Push(root);

    while (!stackEmpty() && P!=NULL) 
    {
        P = Pop();
        		temp = P->Right;
        		P->Right = P->Left;
        		P->Left = temp;

        if (P->Left)
            Push(P->Left);

        if (P->Right)
           Push(P->Right);
    }
    Preorder(root);
    printf("\n\n");
}

Node *Height(Node *P)
{
    int counter;
    counter = 0;
     while(!Queue_Empty() && P!= NULL ) 
    {
            
            if (P->Left == NULL && P->Right == NULL  ) 
            {
               printf("The height of Tree is : %d ",counter);   
            }
            counter++; 	
            
            if (P->Left!=NULL)
                AddQ(P->Left);

            if (P->Right!=NULL)
                AddQ(P->Right);

            P = DelQ();
    
	}
     printf("\n\n");
}

int main()
{
    
    Node *root = NULL, *newnode,*P;
    int option,val;
    char ch;
   

    printf("Enter Option for particular  Operation to be performed \nOption 1 = insertion \nOption 2 = Preorder transversal \nOption 3 = Mirror image of tree \nOption 4 = Height of tree \nOption 5 = To Exit");
 do
 {
    printf("\nEnter Option : ");
    scanf("%d",&option);
    printf("\n\n"); 
    switch (option)
    {
     case 1:
        printf("Operation Performing is insertion of Binary Node transversal \n"); 
        printf("Enter Data : ");
        scanf("%d",&val);
        root = insert(root,val);
        break;

    case 2:
        printf("Operation Performing is Preorder transversal of tree \n"); 
        Preorder(root);
        break;
    
    case 3:
        printf("Operation Performing is Mirror image of tree  \n");
        mirror(root);
        break;

    case 4:
        printf("Operation Performing is Height of tree  \n");              
        Height(root);
        break;

    case 5:
        printf("Code Exited");            
        break;

    default: 
        printf("Option not avalible ! \n");
    }

 }while(option!=5);   

return 0;
}