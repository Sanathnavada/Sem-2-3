/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
int stackfull(int,int);
int stackempty(int);
void push(int ele,int*top,int stack[]);
int pop(int*top,int stack[]);
void display(int stack[],int top);
int main()
{
int n,top=-1,stack[50],elepop,ch,ele;
printf("enter the size of stack \n");
scanf("%d",&n);
for(;;)
  {
    printf("enter 1 to push 2 to pop 3 to display 4 to exit\n");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:
        {if(stackfull(top,n))
        { printf("stack is full\n");
        break;
        }
        printf("enter the number to be pushed\n");
        scanf("%d",&ele);
        push(ele,&top,stack);
        break;
        }
        case 2:
        {if(stackempty(top))
        {printf("stack is empty!\n");
        break;
        }
        elepop = pop(&top,stack);
        printf("the element popped is %d \n",elepop);
        break;
        }
        
        case 3:
        {
        printf("the contents of the stack are \n");
        display(stack,top);
        break;
        }
        
        case 4: exit(0);
        
        default: printf("try again with valid number \n");
        
    }
  }
}


int stackfull(int top,int n)
{
    if (top==n-1)
     return 1;
    return 0;
}
int stackempty(int top)
{
    if(top==-1)
     return 1;
    return 0;
}

void push(int ele,int*top,int stack[])
{(*top)++;
stack[*top]= ele;
return;
}

int pop(int *top,int stack[])
{
    int i = stack[*top];
    (*top)--;
    return i;
}

void display(int stack[],int top)
{ int i;
    for(i=top;i>=0;i--)
    printf("%d\n",stack[i]);
}
