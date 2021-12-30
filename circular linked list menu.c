
#include <stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node *link;
}NODE;

NODE * getnode();
NODE *insert_front(int ele, NODE *last);
NODE *insert_rear(int ele, NODE *last);
void display_list(NODE * last);
NODE * deletefront(NODE*last);
NODE *deleterear(NODE*last);
NODE *insertspecific(int ele,int pos,NODE*last);
NODE *stringconcat(NODE*last);
void search_list(int ele,NODE *last);

int main()
{
 NODE *last=NULL;
 int ch,ele,n=0,pos,flag;
 for(;;)
 {
     printf("\n enter 1.Insert at the front of the list\n 2.Insert at rear of the list\n 3.Delete from the front of the list\n 4.Delete from the rear of the list\n 5.Display the content of the list\n 6.exit\n 7. to insert at specific position \n 8.to concat two lists (not working)\n 9. to search an element\n");
     scanf("%d",&ch);
     switch(ch)
      {
          case 1:printf("enter the data at the front of the list\n");
                 scanf("%d",&ele);
                 last=insert_front(ele,last);
                 n++;
                 break;
          case 2:printf("enter the data at the rear of the list\n");
                 scanf("%d",&ele);
                 last=insert_rear(ele,last);
                 n++;
                 break;
                 
         case 3 :if(last==NULL)
                 {printf("empty list");
                     break;
                 }
                  last=deletefront(last);
                  n--; 
                 break;
         case 4: 
                 if(last==NULL)
                 {printf("empty list");
                     break;
                 } 
                 last=deleterear(last); 
                 n--;
                 break;
          case 5:if(last==NULL)
                 {printf("empty list");
                     break;
                 } 
          	printf(" content of the list\n ");
                 
                   display_list(last);
                    break;       
         case 6: exit(0);    
         case 7:printf("enter the position at which node should be inserted ");
             	scanf("%d",&pos);
             	if((pos>n+1) || (pos == 0))
             	{
             	printf("invalid position \n");
             	break;}
             	else
             	{
             	printf("enter the element to be inserted ");
             	scanf("%d",&ele);
             	last = insertspecific(ele,pos,last);
             	n++;}
             	break;
         case 8:last = stringconcat(last);
                break;
         case 9:if(last==NULL)
			  	{
			  	 printf("empty list\n");
			  	break;
			  	}
    			printf("enter the key node\n");
    			scanf("%d",&ele);
    			search_list(ele,last);
    			    			break;          
        default:printf("enter no from 1-5");
                 break;     
         
      }
 }

    return 0;
}

NODE * getnode()
{
   NODE *temp;
    temp=(NODE*)malloc(sizeof(NODE));
    if(temp==NULL)
    {
        printf("no memory\n");
        return NULL;
    }
    return temp;
}
NODE *insert_front(int ele, NODE *last)
{
    NODE *new=getnode();
    new->data=ele;
    if(last==NULL)
    {
        last=new;
    }
    else
    {
     new->link=last->link;
    }
    last->link=new;
    return last;
}
NODE *insert_rear(int ele, NODE *last)
{
    NODE *new=getnode();
    new->data=ele;
    if(last==NULL)
    {
        last=new;
    }
    else
    {
     new->link=last->link;
    }
    last->link=new;
    return new;
}
void display_list(NODE *last)
{
     NODE *temp;
     temp=last->link;
     
     while(temp->link!=last->link)
     {
         printf("%d\t",temp->data);
         temp=temp->link;
         
     }
     printf("%d\t",temp->data);
}     


NODE *deletefront(NODE*last)
{   
  if(last==NULL)
    return NULL;
    
    if(last->link==last)
  {
  printf("the element deleted is %d ",last->data);
    return NULL;
  }   
    
    NODE*temp;
    temp=last->link;
   
    printf("the element deleted is %d ",temp->data);
    last->link =temp->link;
    free(temp);
    return last;
    
}
NODE *deleterear(NODE*last)
{
if(last==NULL)
  {
    return NULL;
  }  

if(last->link==last)
  {
    printf("the element deleted is %d ",last->data);
    return NULL;
  }   
   
NODE*temp;
temp=last->link;
printf("the element deleted is %d ",last->data);
while(temp->link!=last)
{
	temp = temp->link;
}
temp->link = last->link;
free(last);
return temp;
}

NODE*insertspecific(int ele,int pos,NODE *last)
{
     printf("a");

 NODE *temp = getnode();
int count =1;

temp->data = ele;
if(last==NULL)
 {

	last = temp;
	last->link =temp;
	return last;
 }	

else if(last->link= last)
{
    last->link = temp;
    temp->link = last;
    if(pos ==2)
    return temp;
    else return last;
}
else
 { NODE *prev=NULL,*present=last->link;
	while(count!=pos)
	{
		prev = present;
		present = present ->link;
		count++;
	}
	prev->link =temp;
	temp->link = present;
	return last;
 }
}


NODE *stringconcat(NODE*last)
{   NODE *t1= NULL,*t2 = NULL,*t3;
    char ans;
    int a,b,i,ele;
    printf("do you want to use existing list? (enter y for yes or n for no");
    scanf("%c",&ans);
    switch(ans)
    {
        case 'y':if(last ==NULL)
                {printf("no pre existing list present try again\n ");
                break;}
                t1=last;
                printf("enter the size of second list ");
                 scanf("%d",&a);
                 printf("enter the elements of second list ");
                for(i=0;i<a;i++)
                 {  
                     scanf("%d",&ele);
                    t2=insert_rear(ele,t2);
                     
                 }
                 break;
        case'n':printf("enter the size of 1st list ");
                 scanf("%d",&a);
                 printf("enter the elements of 1st list "); 
                 for(i=0;i<a;i++)
                {   
                    scanf("%d",&ele);
                    t1=insert_rear(ele,t1);
                    
                }
                 
                 printf("enter the size of second list ");
                 scanf("%d",&b);
                 printf("enter the elements of second list ");
                 for(i=0;i<b;i++)
                {
                    scanf("%d",&ele);
                     t2=insert_rear(ele,t2);
                    
                }
                 break;
        
    }
    t3=t1->link;
    t1->link =t2->link;
    t2->link=t3;
    return t2;
    
}
void search_list(int ele,NODE *last)
{ ;
    NODE *temp;
    temp=last->link;
    int count=0,t=0;
    while(temp!=last)
    { count++;
        if(temp->data==ele)
        { 
            t=1;
            printf("search successfull element at position %d",count);
            break;
        }
        temp=temp->link;
    }
    if(t==0)
    {if(temp->data ==ele)
    { count++;
        t=1;
            printf("search successfull element at position %d",count);
    }}
    if(t==0)
    printf("search unsuccessfull\n");
   ; 
}




