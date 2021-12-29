/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include<stdio.h>
#include<stdlib.h>
int main()
{
int f = 0,r = -1,q[100],n,ele,elepop,i;
int ch;
printf("enter the size of queue ");
scanf("%d",&n);
for(;;)
{
printf(" enter 1 to push 2 to pop 3 display 4 to exit ");
scanf("%d",&ch);

switch(ch)
{
case 1: if(r== n-1)
	{printf("queue is full\n");
	break;}
	printf("enter the element to be pushed ");
	scanf("%d",&ele);
	q[++(r)]= ele;
	break;
case 2:	if(f>r)
	{printf("queue is empty\n");
	break;}
	elepop = q[(f)];
	printf("the element popped is %d",elepop);
	f++;
	break;
	
case 3: if(f>r)
	{printf("queue is empty\n");
	break;}
	printf("the contents of the queue are \n");
	for(i=f;i<=r;i++)
	printf("%d\t",q[i]);
	break;
case 4:exit(0);
}
}
}
