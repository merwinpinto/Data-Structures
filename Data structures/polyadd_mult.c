#include<stdio.h>
#include<stdlib.h>

struct node{
    int coeff;
    int power;
    struct node *next;
    };

typedef struct node Node;


Node *insert(Node *head,int coeff,int power)
{
    Node *P,*newnode; 
    newnode = malloc(sizeof(Node));
    newnode -> coeff = coeff;
    newnode -> power = power;
    newnode -> next = NULL;

    if(head == NULL)
    {
        head = newnode;
        return head;
    }

    P = head;
     while(P->next != NULL)
     {
        P = P->next;
     }

     P->next = newnode;
}

Node *display(Node*head);

void Add(Node* head1,Node*head2)
{
    Node *P1 = head1,*P2=head2,*P3=NULL;

    while(P1 !=NULL && P2 !=NULL)
    {
        if(P1->power == P2->power )
        {
            P3 = insert(P3,(P1 -> coeff) + (P2 -> coeff) ,P1 -> power);
            P1 = P1->next;
            P2 = P2->next;
        }

        else if(P1->power > P2->power )
        {
            P3 = insert(P3,P1 -> coeff ,P1 -> power);
            P1 = P1->next;
        }

        else
        {
            P3 = insert(P3,P2 -> coeff ,P2 -> power);
            P2 = P2->next;
        }

    }

    while(P1!=NULL)
    {
        P3 = insert(P3,P1 -> coeff ,P1 -> power);
        P1 = P1 ->next;
    }

    while(P2!=NULL)
    {
        P3 = insert(P3,P2 -> coeff ,P2 -> power);
        P2 = P2 ->next;
    }

    display(P3);
}


void Mul(Node* head1,Node*head2)
{
    Node *P1 = head1,*P2=head2,*P3=NULL;

    while( P1 != NULL)
        {
            while(P2 != NULL)
            {
                 P3 = insert(P3,P1 -> coeff * P2 -> coeff , P1 -> power + P2 -> power);
                 P2 = P2 -> next;
            }

            P1 = P1 -> next;
            P2 = head2;
        }

    display(P3);
}

Node *display(Node*head)
{
    Node *P = head;

    if(head == NULL)
        return NULL;

    while(P!=NULL)
    {
        printf("%dX^%d ",P->coeff,P->power);
        P = P->next;

        if(P!=NULL)
            printf(" + ");

        else    
          printf("\n");
    }

}

int main()
{
    Node * head1 = NULL ,*head2 = NULL;
    int i;
    int option;
    int coeff,power;

    do
    {
        printf("\n\nEnter option 1 : insert polynomial inout  \n option 2 : display \n option 3 : exit \n");
        scanf("%d",&option);

        switch (option)
        {
        case 1:
            printf("pol ----->  1 \n");
            for(i=0;i<1;i++)
            {
            printf("Enter coeff : ");
            scanf("%d",&coeff);
            printf("Enter power : ");
            scanf("%d",&power);
            head1 = insert(head1,coeff,power);
            }
            

            printf("pol ----->  2 \n");
            for(i=0;i<2;i++)
            {
            printf("Enter coeff : ");
            scanf("%d",&coeff);
            printf("Enter power : ");
            scanf("%d",&power);
            head2 = insert(head2,coeff,power);
            }
            break;

        case 2:
            printf("Displaying Pol1 : ");
            display(head1); 

            printf("\n\nDisplaying Pol2 : ");
            display(head2); 

            printf("\n\nAdded polynomial : ");
            Add(head1,head2);

            printf("\n\nMultiplied polynomial : ");
            Mul(head1,head2);
            break;
        
        default:
            break;
        }


    } while (option !=3);
    
}