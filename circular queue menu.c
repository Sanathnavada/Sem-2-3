#include <stdio.h>
#include<stdlib.h>
#define SIZE 50
char cq_delete(int *f,int n,char cq[],int *cnt);
void cq_insert(char ch,int n,int *r,char cq[],int *cnt);
void cq_display(int f,int n,int c,char cq[]);
int main()
{
  int f=0,r=-1,ch,count=0,n, item_del;
  char cq[SIZE],ele;
  printf("enter size of the queue\n");
  scanf("%d",&n);
 
  for(;;)
   {
       printf("enter 1.To insert\n 2.to delete\n 3.To Display\n 4.exit\n\n");
       scanf("%d",&ch);
       switch(ch)
       {
            case 1:if(count==n)
                    {
                     printf("queue is full\n\n");
                     break;
                    }
                    printf("enter the element to be inserted\n");
                    scanf("%s",&ele);
                    cq_insert(ele,n,&r,cq,&count);
                    break;
            case 2:if(count==0)
                   {
                       printf("queue is empty\n");
                       break;
                       
                   }
                   item_del=cq_delete(&f,n,cq,&count);
                   printf("ele deleted is %c\t",item_del);
                   break;
            case 3:if(count==0)
                    {
                        printf("queue is empty\n");
                        break;
                    }
                    cq_display(f,n,count,cq);
                    break;
            case 4:exit(0);
            default:printf("invalid choice\n");
                    break;
       }
       
   }
   
}  

void cq_insert(char ele,int n,int *r,char cq[],int *cnt)
{
    *r=(*r+1)%n;
    cq[*r]=ele;
    *cnt=*cnt+1;
    
    
}
char cq_delete(int *f,int n,char cq[],int *cnt)
{
    char del_ele=cq[*f];
    *f=(*f+1)%n;
    *cnt=*cnt-1;
    return del_ele;
}
void cq_display(int f,int n,int c,char cq[])
{
    for(int i=1;i<=c;i++)
    {
     printf("%c \t",cq[f]);
     f=(f+1)%n;
    } 
}

