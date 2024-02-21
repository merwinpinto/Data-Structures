#include<stdio.h>
#include<stdlib.h>
#define max 100
int top = -1;
struct node 
{
    int data;
    struct node *left,*right;

};

typedef struct node Node;

Node* stack[max];
Node* push(Node *Root)
{
    if(top == max-1)
        printf("Statck full");

    else
    {
        top++;
        stack[top] = Root;
        return Root;
    }
    
        
}

Node* pop()
{
    Node * Root;
    if(top==-1)
        printf("Statck Emp");

    else{
        Root = stack[top];
        top--;
        return Root;
        }
}

Node * insert(Node *root,int data)
{
    Node *P,*new;
    
    new = malloc(sizeof(Node));
    new -> data = data;
    new -> left = NULL;
    new -> right = NULL;

    if(root == NULL)
    {
        root = new;
        return root;
    }

    P = root;

while(1)
{
    if(data < P->data)
    {
      if(P-> left == NULL)
      {
        P-> left = new;
        break;
      }   
      else
        P = P->left;
    }

    else if(data > P->data)
    {
      if(P-> right == NULL)
      {
        P-> right = new;
        break;
      }   
      else
        P = P->right;
    }

    else
        printf("Duplicated valued ! Enter non duplicated !\n\n");
        break;
}
    return P;
}

Node *Preorder(Node * Root)
{
    Node *P;

    if(Root==NULL)
    {
        printf("Null value : ! \n");
        return NULL;
    }
    
    P = Root;
    push(P);

    while(top>=0)
    {
        P = pop();
        printf("%d ",P->data);

        if(P->right!=NULL)
        {
            push(P->right);
        }

        if(P->left!=NULL)
        {
            push(P->left);
        }
    }
    return P;
}

int main()
{
    
    int option,num;
    Node *Root = NULL;

    printf("Opt 1 : take inp for tree \n");
    printf("opt 3 : exit\n\n");

    do
    {   
        printf("\n\nenter opt :");
        scanf("%d",&option);
        switch(option)
        {
            case 1:
            printf("Enter val : ");
            scanf("%d",&num);
            Root = insert(Root,num);
            break;

            case 2:
            printf("\nDisplaying : ");
            Preorder(Root);
            break;

            case 3:
            printf("Break Program");
            break;

            default:
            printf("Enter valid opt !");
            break;
        }

    }while(option!=3);
}