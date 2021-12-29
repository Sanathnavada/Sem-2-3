/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include<stdio.h>
#include<stdlib.h>
void insert(int *n,int arr[]);
void del(int *n,int arr[]);
void trav(int n,int arr[]);
#define size 25
int main()
{
int arr[size],n,ch,i;

printf("Enter number of elements\n ");
scanf("%d",&n);
printf("Enter the elements of the aray\n");
for(i=0;i<n;i++)
 scanf("%d",&arr[i]);

for(;;)
 {
printf("enter 1 to insert \n 2 to delete\n 3 to traverse \n 4 to exit\n");
scanf("%d",&ch);
switch(ch)
 {
  case 1:insert(&n,arr);
         break;
  case 2:del(&n,arr);
         break;                  
  case 3: trav(n,arr); 
         break;
  case 4: exit(0);
         
  default: printf("Enter between 1-3\n");
  }
 }
}

void insert( int *n,int arr[])
{
 int pos ,ele,i;
 printf("enter the position to be inserted\n");
scanf("%d",&pos);

if(pos>=1 && pos<= *n+1)
{
 printf("Enter the element\n");
scanf("%d",ele);


if(pos==*n)
 { arr[pos-1]=ele; }
 
else
  { for(i=(*n-1);i>pos-1;i--)
      {arr[i+1]=arr[i];}
      
      arr[pos-1]=ele;
      *n=*n+1;
  }
 }
else printf("invalid position");
return;
}

void del(int *n,int arr[])
{
int i ,pos;
printf("enter the position \n");
scanf("%d",&pos);


if(pos>=1 && pos<=*n)

 {for(i=pos-1;i<=(*n-1);i++)
{
    {if(n=0)
  printf("empty array !");}
  
    arr[i]=arr[i+1];
}
      *n=(*n-1);

return;
}
}
 
void trav(int n,int arr[])
{
    int i;
for(i=0;i<n;i++)
printf("%d ",arr[i]);
printf("\n");
return;

}



