/*Write a program to perform following operations on single variable polynomials using singly linked list. 
A. Accept a polynomial, 
B. Display 
C. Addition of two polynomials, 
D. Multiplication of two polynomials
*/
#include<stdio.h>
#include<stdlib.h>
#define SIZE 100
clrscr();
struct node
  {
    int coeff;
    struct node *next;
  };

typedef struct node Node;
  
Node *Node_data();


Node * Node_data()
{
    int i;
    Node *head = NULL;
    Node *pol;

    for(i=0;i<SIZE;i++)
    {
      pol = (Node*)malloc(sizeof(Node));
      pol->coeff = 0;
      pol->next = head;
      head = pol;
    }
  return(head);
}

void  input_pol(Node *head)
{
int n,i,j;
int power,coeff;
Node *pol;
pol = Node_data();

printf("Enter number of polynomial terms :\n");
scanf("%d",&n);

for (i=0 ;i<n ;i++)
{ 
  printf("enter base number \n");
  scanf("%d",&coeff);
  
  printf("enter index (power) number \n");
  scanf("%d",&power);
  
  for( pol=head, j=0 ; j < power ; j++ )    //Powers ranging fro 1 to n powers
  {
      pol = pol->next;
      pol->coeff = coeff;
  }

}

}


void print_pol(Node *pol)
{
   int i;
  for(i=0; pol!= NULL; i++, pol = pol->next)
  if(pol->coeff!= 0)  
  printf("%dx^%d   ",pol->coeff,i);
}

Node * addfunction(Node *head, Node *current1 )
{
    Node *current2;
    Node *pol;
    current2 = Node_data();
    pol = current2 ;
    while(head!= NULL)
     {
        current2 -> coeff = ( head->coeff )+ ( current1 ->coeff) ;
        head = head->next;
        current1 = current1->next;
        current2 = current2->next;
     }
 return(pol);
}


Node * multfunction(Node *head, Node *current1 )
{
  Node *current2 ;
  Node *pol;
  Node *q;
  Node *r;
  int i,j,k,coeff,power;
  current2 =Node_data();

    for(pol=head,i=0 ; pol!=NULL ; pol = pol->next,i++)
    {
        for(q=current1 ,j=0 ; q!=NULL ; q=q->next,j++)
        {
          coeff=pol->coeff * q->coeff;
          power=i+j;
          for(r=current2 ,k=0;k<power;k++)
          {
            r=r->next;
            r->coeff=r->coeff+coeff;
          }
          
        }
}

return(current2 );
}

int main()
{
   int option;
   Node *head=NULL,*current1 = NULL,*current2 =NULL;
    printf("Enter Option for particular Operation to be performed \nOption 1 = Create Polynomial 1 \nOption 2 = Create Polynomial 2");
    printf("\nOption 3 = Display Polynomial \nOption 4 = ADD Polynomial \nOption 5 = MULTIPLY Polynomial \nOption 6 = To Exit");
 do
 {
    printf("\nEnter Option : ");
    scanf("%d",&option);
    printf("\n\n"); 
    switch (option)
    {
     case 1:
        printf("Operation Performing is Creating Polynomial 1 \n"); 
        head = Node_data();
        input_pol(head);      
        printf("\n\n");  
        break;
    
    case 2:
        printf("Operation Performing is Creating Polynomial 2 \n");
        current1 = Node_data();
        input_pol(current1 );
        printf("\n\n"); 
        break;

    case 3:
        printf("Operation Performing is Displaying Polynomial  \n");            
        printf("\npolynomial 1 -> \n");
        print_pol(head);
        printf("\npolynomial 2 -> \n");
        print_pol(current1 );
        printf("\n\n");  
        break;  
    
    case 4:
        printf("Operation Performing is Adding  Polynomial ( 1 + 2 )\n");            
        current2 = addfunction(head,current1 );
        printf("\npolynomial 1 -> \n");
        print_pol(head);
        printf("\npolynomial 2 -> \n");
        print_pol(current1 );
        printf("\nSum = \n");
        print_pol(current2 );
        printf("\n\n");  
        break;

    case 5:
        printf("Operation Performing is Multiplying Polynomial ( 1 x 2 ) \n");            
        current2 = multfunction(head,current1 );
        printf("\npolynomial 1 -> \n");
        print_pol(head);
        printf("\npolynomial 2 -> \n");
        print_pol(current1 );
        printf("\nmultiplied product = \n");
        print_pol(current2 );
        printf("\n\n");  
        break;

    case 6:
        printf("Code Exited");            
        break;
         

    default: 
          printf("Option not avalible ! \n");
          break;
    }
 }while(option!=6);   

return 0;
}