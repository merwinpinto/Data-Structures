//202100102
//Merwin Pinto
//5/9/22
#include<stdio.h>
#include<string.h>
#define MAX 100
#define TRUE 1
#define FALSE 0
int top1 = -1;
int top2 = -1;
char Stack1[MAX];
char Stack2[MAX];

int StackFull_1()    //Checks if Stack is Full 
{    
    if(top1 >= MAX-1)
        return TRUE;
    else
        return FALSE;
}
 
int StackEmpty_1()  // Checks if Stack is Empty 
{
 if(top1 == -1)
     return TRUE;
 else
     return FALSE;
}

void push1(char element)  //To push1 elements into Stack
{
     if (StackFull_1())
        printf("Stack is Full \n");

    else 
	Stack1[top1+1] = element;
	top1++;

}

char pop1()    //To pop1 elements from Stack
{
     if (StackEmpty_1())    //checks for Stack if empty
	printf("Stack is Empty \n");

    else
     top1 = top1 - 1;
     return Stack1[top1+1];

}

int StackFull_2()    //Checks if Stack is Full 
{    
    if(top2 >= MAX-1)
        return TRUE;
    else
        return FALSE;
}

 
int StackEmpty_2()  // Checks if Stack is Empty 
{
 if(top2 == -1)
     return TRUE;
 else
     return FALSE;
}

void push2(char element)  //To push1 elements into Stack
{
     if (StackFull_1())
        printf("Stack is Full \n");

    else 
        Stack2[top2 + 1] = element;
        top2++;
        
}

char pop2()    //To pop1 elements from Stack
{
     if (StackEmpty_2())    //checks for Stack if empty
        printf("Stack is Empty \n");

    else 
     top2 = top2 - 1;
     return Stack2[top2 + 1];

}




void str_palindrome(char str[])    //Palindrome
{
     int i;
     char element=0;
     int len;
     len = strlen(str);
     
     for(i = 0; i < len; i++)
    {
        push1(str[i]);
    }

   for(i = 0; i < len; i++)
   {
       if(str[i] == pop1() )
        {
            element ++;  
        }

   }
    if(len == element )
    printf("This String is palindrome\n ");
    
    else
    printf("The String is not palindrome");
    

}

void str_reverse(char str[])   //reversing string
{
     int i;
     int len;
     len = strlen(str);
     
        for(i=0; i< len ;i++)
        {
          push1(str[i]);
        }
        
        for(i=0; i<len ;i++)
        {
          str[i]=pop1();
        }
}

void string_concat(char str[] , char str2[])   //concating string
{
    int i;
    int len,len2,len3;
    len  = strlen(str);
    len2 = strlen(str2);
    len3 = len + len2;
    for(i = 0; i < len; i++)
    {
        push1(str[i]);
    }

    for(i = 0; i < len2; i++)
    {
        push1(str2[i]);
    }

    for(i = 0; i < len3; i++)
    {
        str[i]=pop1();
    }

    str[i] = '\0';
    str_reverse(str);
    printf("Concated String is: %s\n",str);
}

void str_compare(char str[] , char str2[])   //comparing strings
{
    int i,flag=0;
    int len,len2;
    len = strlen(str);
    len2 = strlen(str2);
    str_reverse(str);   //reversing string
    str_reverse(str2);   //reversing string2

    for(i = 0; i < len; i++)
    {
        push1(str[i]);        
    }
    

   for(i = 0; i < len2; i++)
    {
        push2(str2[i]);
    }
     
 
 for(i=0 ; str[i]!= '\0' || str2[i]!='\0' ; i++)
 {
    str[i]=pop1();
    str2[i]=pop2();
    
    if(str[i] != str2[i])
   {
     flag = TRUE;
     break;
   }
 }
  if (flag == FALSE)
  printf("Strings are Same !");

  else 
  printf("Strings are not same !");

}

int main()
{
    int option,len;
    char Stack[MAX];
    char str[MAX];
    char str2[MAX];

    printf("Enter Option for particular Operation to be performed \nOption 1 = Palindrome \nOption 2 = String reverseerse \nOption 3 = String Concatenate \nOption 4 = String Compare \nOption 5 = To Exit");
 do
 {
    printf("\nEnter Option : ");
    scanf("%d",&option);
    printf("\n\n"); 
    switch (option)
    {
    case 1:
         printf("Operation Performing is Palindrome \n"); 
         printf("Enter a string : ");
         scanf("%s",str);
         str_palindrome(str);
         printf("\n\n");  
         break;
    
    case 2:
         printf("Operation Performing is String reverse \n");
         printf("Enter a string : ");
         scanf("%s",str);
         str_reverse(str);
         printf("reversed String is: %s\n",str);
         printf("\n\n"); 
         break;

    case 3:
         printf("Operation Performing is String Concatenation \n");            
         printf("Enter a string  1 : ");
         scanf("%s",str);   
         printf("Enter a string  2 : ");
         scanf("%s",str2);  
         string_concat(str ,str2);
         printf("\n\n");  
         break;

    case 4:
         printf("Operation Performing is String Compare \n");    
         printf("Enter a string  1 : ");
         scanf("%s",str);   
         printf("Enter a string  2 : ");
         scanf("%s",str2);  
         str_compare(str ,str2);
         printf("\n\n");  
         break;     

    case 5:
         printf("Code Exited");            
         break;

    default: printf("Option not avalible ! \n");
        break;
    }
 }while(option!=5);   
 return 0;
}