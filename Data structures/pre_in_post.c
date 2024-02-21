#include<stdio.h>
#include<stdlib.h>
#define max 100

struct node
{
    int data;
    struct node *left, *right;
};

typedef struct node node;

int top=-1;

node* stack[max];
node *queue[max];
int front = -1;
int rear = -1;

void push(node* ele)
{
    if(top == max - 1)
    {
        printf("stack full");
    }

    top = top + 1;
    stack[top] = ele;
}

node* pop()
{
    node * root;
    if(top == - 1)
    {
        printf("stack Empl");
    }

    root = stack[top];
    top = top -1;
    return root;
}

node* insert(node *root,int data)
{
    node * new;
    new = malloc(sizeof(node));
    new -> data = data;
    new -> left = NULL;
    new -> right = NULL;

    if(root == NULL)
    {
        root = new;
        return new;
    }

    node * P,*parent;
    P = root;

    while(P!=NULL)
    {
        parent = P;
        if(data < P-> data )
        {
            P = P->left;

            if(P== NULL)
            {
                parent-> left = new; 
                break;
            }
        }
        else if(data > P-> data )
        {
            P = P->right;

            if(P== NULL)
            {
                parent-> right = new; 
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

node *pre(node* root)
{
    node *P;

    if(P == NULL)
        return 0;
    
    P = root;
    push(P);

    do
    {
        printf("%d ",P->data);

        if(P->right != NULL)
            push(P->right);

        if(P->left != NULL)
            push(P->left);

        P = pop();
        
        
    }while(!(top==-1) && P!=NULL);
}

node *post(node* root)
{
    node *P = root;
    int i,index = 0;
    int array[max];
    if(P == NULL)
        return 0;
    
    push(P);

    do
    {
        // printf("%d ",P->data);
        array[index] = P->data;
        index++;

        if(P->left != NULL)
            push(P->left);

        if(P->right != NULL)
            push(P->right);

        P = pop();
        
    }while(!(top==-1) && P!=NULL);
    
    for (int i = index - 1; i >= 0; i--)
    {
        printf("%d ", array[i]);
    }
}



node *In(node* root)
{
    node *P = root;

    if(P == NULL)
        return 0;

    do
    {
        while(P!=NULL)
        {
            push(P);       
            P = P->left;         // L
        }

            P = pop();
            printf("%d ",P->data);   //V

            P = P->right;   // R
        
    } while(!(top==-1) || P!=NULL);
}

node *mirror(node* root)
{
    node *P;
    node *temp;
    if(P == NULL)
        return 0;
    
    P = root;
    push(P);
    

    do
    {
        //printf("%d ",P->data);
        // P = pop();
        temp = P->right;
        P->right = P->left;
        P->left = temp;
        
        if(P->right != NULL)
            push(P->right);

        if(P->left != NULL)
            push(P->left);

        P = pop();
        
        
    }while(!(top==-1) && P!=NULL);

    pre(root);
}

int main()
{
    node * root = NULL; 
    int option , num;

    do{
    printf("\n\n1: insert \n 2: preorder \n 3: postorder \n 4: Inorder\n  5: mirror\n");
    printf("Enter option : ");
    scanf("%d",&option);

        switch (option)
        {
        case 1:
            printf("Enter a number for node : ");
            scanf("%d",&num);
            root = insert(root,num);
            break;

         case 2:
            printf("preorder :");
            pre(root);
            break;
        
        case 3:
            printf("postorder :");
            post(root);
            break;

        case 4:
            printf("Inorder :");
            In(root);
            break;

         case 5:
            printf("mirror :");
            mirror(root);
            break;

        default:
            break;
        }

    }while(option != 6);
}