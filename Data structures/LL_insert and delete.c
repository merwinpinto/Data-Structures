#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

typedef struct node node;

node* insert(node* head , int data)
{
    node *newnode,*P;

    newnode = malloc(sizeof(node));
    newnode->data = data;
    newnode->next = NULL;

    if(head== NULL)
        {
            head = newnode;
            return newnode;
        }

    P = head;

    while(P->next!=NULL)
    {
        P = P->next;
    }

    P -> next = newnode;

    return head;
}

node* insertatstart(node* head , int data)
{
    node *newnode,*P;

    newnode = malloc(sizeof(node));
    newnode->data = data;
    newnode->next = NULL;

    if(head== NULL)
        {
            // head = newnode;
            return newnode;
        }

    P = head;
    newnode->next = P;
    P = newnode;

    return P;
}


node* display(node* head)
{
    if(head == NULL)
        return NULL;

    node *P = head;

    while(P!=NULL)
    {
        printf("%d",P->data);
        P = P->next;
    }
    
}

node* deleteatstart(node* head)
{
    node *P;

    if(head == NULL)
        return NULL;
    
     P= head;
    head =  P->next;
    free(P);

    return head;
}

node* deleteatend(node* head)
{
    node *P,*previous = NULL;

    if(head == NULL)
        return NULL;
    
    P = head;

    while(P->next != NULL)
    {
        previous = P;
        P = P->next;
    }

    previous->next = NULL;
    free(P);

    return head;
}




int main()
{
    int option,value;
    node * head=NULL;

    while(option != 6)
    {
        printf("\n\noption 1 : insert \n option 2 : display \n option 3 delete at start \n option 4 delete at end \n option 5 insert at start");
        scanf("%d",&option);

        switch (option)
        {
        case 1:
            printf("\nenter the value to be inserted : ");
            scanf("%d",&value);
            head = insert(head,value);
            break;
        
        case 2 :
            printf("\ndisplaying sequnce ! \n");
            display(head);
            break;

        case 3 :
            printf("\ndelete a node at start\n");
            head = deleteatstart(head);
            break;

        case 4 :
            printf("\ndelete a node at start\n");
            head = deleteatend(head);
            break;

        case 5 :
            printf("\ninsert\n");
            printf("\nenter the value to be inserted : ");
            scanf("%d",&value);
            head = insertatstart(head,value);
            break;

        default:
            printf("incorrect value option re-enter ");
            break;
        }
    }
}