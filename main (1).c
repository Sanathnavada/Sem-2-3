/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
struct student
{
    int id;
    char name[20];
    char gender;
    
};
int stackfull(int,int);
int stackempty(int);
void push(struct student newele,int*top,struct student std[]);
struct student pop(int*top,struct student std[]);
void display(struct student std[],int top);
int main()
{
int top=-1,ch,n;
struct student std[5],newele,elepop;
printf("enter the number of students \n");
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
        printf("enter the new student's detail(ID,NAME,GENDER) to be pushed\n");
        scanf("%d %s %c",&newele.id,newele.name,&newele.gender);
        push(newele,&top,std);
        break;
        }
        case 2:
        {if(stackempty(top))
        {printf("stack is empty!\n");
        break;
        }
        elepop = pop(&top,std);
        printf("the popped student's detail is\n %d \n %s \n  %c \n",elepop.id,elepop.name,elepop.gender);
        break;
        }
        
        case 3:
        {
            if(stackempty(top))
        {printf("stack is empty!\n");
        break;
        }
         else {printf("the contents of the stack are \n");
        display(std,top);
        break;
        }
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

void push(struct student newele,int*top,struct student std[])
{(*top)++;
std[*top]= newele;
return;
}

struct student pop(int*top,struct student std[])
{ 
    struct student elepop;
    elepop = std[*top];
    (*top)--;
    return elepop;
}

void display(struct student std[],int top)
{ int i;
    for(i=top;i>=0;i--)
    printf("%d\n%s\n%c\n",std[i].id,std[i].name,std[i].gender);
}

