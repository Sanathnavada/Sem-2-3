
#include <stdio.h>
#include<stdlib.h>
int eval_post(char postfix[]);
void push(int tn,int *top,int stack[]);
int pop(int *top,int stack[]);
int compute(int op1,int op2,char symbol);



int main()
{
  char postfix[10];
  int result;
  printf("enter a postix expression\n");
  scanf("%s",postfix);
  printf("the result of evaluvation=%d",eval_post(postfix));

    return 0;
}

int eval_post(char postfix[])
{
    int result;
    int i=0,top=-1,stack[10],token,op2,op1;
    char symbol;
    while(postfix[i]!='\0')
    {
         symbol=postfix[i];
         if(isdigit(symbol))
          {
              token=symbol-'0'; 
              push(token,&top,stack);
              
          }
          else
           {
               op2=pop(&top,stack);
               op1=pop(&top,stack);
               result=compute(op1,op2,symbol);
               push(result,&top,stack);
               
           }
          i=i+1;
    }
     
     return (pop(&top,stack));
     
}

void push(int tn,int *top,int stack[])
{
    ++(*top);
    stack[(*top)]=tn;
    
}

int pop(int *top,int stack[])   
{
    return (stack[(*top)--]);
    
}

int compute(int op1,int op2,char symbol)
{
    switch(symbol)
    
    {
         case '+':return(op1+op2);
                  break;
          
         case '-':return(op1-op2);
                  break;
          case'*':return(op1*op2);
                  break;
          case '/':return(op1/op2);
                   break;
           case'%':return(op1%op2);
                   break;
          default:printf("invalid symbol\n");
          
    }
}

