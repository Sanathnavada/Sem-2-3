/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#define size 5    
#include<stdio.h>
#include<stdlib.h>
int deque[size];  
int f=-1, r=-1,count =0;

int main() 
{
    for(;;)
        {  int ch,ele;
        printf("\n enter \n 1 to insert front \n 2 to inser trear \n 3 to delete front \n 4 to delete rear \n 5 to display \n 6 to exit \n");
        scanf("%d",&ch); 
        switch(ch)
            { 
                case 1:if(count==size)
                       {printf("queue is full\n");
                       break;}
                       printf("enter the element to be inserted ");
                       scanf("%d",&ele);
                       enqueue_front(ele);
                       printf("here");
                       count=count+1;
                       break;
                
                case 2:if(count==size)
                       {printf("queue is full\n");
                       break;}
                       printf("enter the element to be inserted ");
                       scanf("%d",&ele);       
                       enqueue_rear(ele);  
                       count++;
                       break;
                       
                case 5:if(count==0)
                       {printf("queue is empty \n");
                       break;}
                        display();  
                        break;
                        
                case 3:if(count==0)
                       {printf("queue is empty \n");
                       break;}        
                       dequeue_front();  
                       count--;
                        break;
                case 4:if(count==0)
                       {printf("queue is empty \n");
                       break;}      
                      dequeue_rear();  
                      count--;
                      break;
                case 6:exit(0);
                
                default:printf("enter valid no(1-6) \n");
                return 0; 
            }
        }
}  

void enqueue_front(int x)  
{  
     
    if((f==-1) && (r==-1))  
    {  
        f=r=0;  
        deque[f]=x;  
    }  
    else if(f==0)  
    {  
        f=size-1;  
        deque[f]=x;  
    }  
    else  
    {  
        f=f-1;  
        deque[f]=x;  
    }
         return;

}  
  
void enqueue_rear(int x)  
{  
   if((f==-1) && (r==-1))  
    {  
        r=0;  
        deque[r]=x;  
    }  
    else if(r==size-1)  
    {  
        r=0;  
        deque[r]=x;  
    }  
    else  
    {  
        r++;  
        deque[r]=x;  
    }  
       return;

}  
  
void display()  
{  
    int i=f;  
    printf("\n Elements in a deque : ");  
      
    while(i!=r)  
    {  
        printf("%d ",deque[i]);  
        i=(i+1)%size;  
    }  
     printf("%d",deque[r]);  
}  
  

  
void dequeue_front()  
{  
    if(f==r)  
    {  
        printf("\nThe deleted element is %d", deque[f]);  
        f=-1;  
        r=-1;  
          
    }  
     else if(f==(size-1))  
     {  
         printf("\nThe deleted element is %d", deque[f]);  
         f=0;  
     }  
     else  
     {  
          printf("\nThe deleted element is %d", deque[f]);  
          f=f+1;  
     }  
          return;

}  
  
void dequeue_rear()  
{  
    if(f==r)  
    {  
        printf("\nThe deleted element is %d", deque[r]);  
        f=-1;  
        r=-1;  
          
    }  
     else if(r==0)  
     {  
         printf("\nThe deleted element is %d", deque[r]);  
         r=size-1;  
     }  
     else  
     {  
          printf("\nThe deleted element is %d", deque[r]);  
          r=r-1;  
     } 
     return;
}  
  

