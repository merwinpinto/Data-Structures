#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

typedef struct node Node;

Node *insert(Node *head,int data)
{
    Node *P,*new;

    new = malloc(sizeof(Node));
    new -> data = data;
    new -> next = NULL;

    if(head == NULL)
    {
        head = new;
        return head;
    }

    else{
        P = head;
        while(P->next!=NULL)
        {
            P = P->next;            
        }

        P->next = new;
    }
}
Node *display(Node*head)
{
    Node *P= head;

    while(P!=NULL)
    {
        printf("%d ",P->data);
        P = P->next;
    }
}

int main()
{
    int option,value;
    Node * head=NULL;

    while(option != 3)
    {
        printf("\n\noption 1 : insert \n option 2 : display \n option 3 exit \n");
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
            printf("\nCode exited \n");
            break;

        default:
            printf("incorrect value option re-enter ");
            break;
        }
    }
}