/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include<stdio.h>
#include<stdlib.h>
typedef enum{lp,rp,plus,minus,mul,divv,mod,powe,eos,operand} precedence;
void infixtopostfix( char infix[]);
void printtoken(precedence token);
void push(int token,int*top,int stack[]);
int pop(int*top,int stack[]);
precedence gettoken(char*symbol,int*n,char infix[]);
int main()
{
	char infix[25];
	printf("enter a valid infix expression \n");
	scanf("%s",infix);
	printf(" the postfix expression is : ");
	infixtopostfix(infix);
}

void infixtopostfix( char infix[])
{

int isp[] = {0,4,1,1,2,2,2,2,3,0};
int icp[] = {10,4,1,1,2,2,2,2,3,0};
int stack[100],top = 0;
char symbol,e;
precedence token;
int n=0;

stack[top] = eos;
for(token = gettoken(&symbol,&n,infix);token!=eos;token = gettoken(&symbol,&n,infix))
{
	if(token == operand)
	printf("%c",symbol);

	else if(token==rp)
	{
		while(stack[top]!=lp)
			{printtoken(pop(&top,stack));}
		e = pop(&top,stack);
        }
        else
        {
		while(isp[stack[top]]>=icp[token])
			{printtoken(pop(&top,stack));}
		push(token,&top,stack);
        }
}
while((token=pop(&top,stack)!=(eos)))
{
printtoken(token);

}

}
precedence gettoken(char*symbol,int*n,char infix[])
{
(*symbol) = infix[(*n)++];

switch(*symbol)
{
	case '(':return lp;
	case ')':return rp;
	case '+':return plus;
	case '-':return minus;
	case '*':return mul;
	case '/':return divv;
	case '%':return mod;
	case '^':return powe;
	case '\0':return eos;
	default: return operand;
}
}

void printtoken(precedence token)
{
switch(token)
{
	case plus:printf("+");
		  break;
	case minus:printf("-");
		  break;
	case mul:printf("*");
		  break;
	case divv:printf("/");
		  break;
	case mod:printf("%%");
		  break;
	case powe:printf("^");
		  break;
}
}
void push(int token,int*top,int stack[])
{
stack[++(*top)]= token;
}

int pop(int*top,int stack[])
{
return(stack[(*top)--]);
}

