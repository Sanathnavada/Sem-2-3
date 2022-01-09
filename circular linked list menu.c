#include <stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node *link;
}NODE;

NODE *listconcat(NODE*last);
NODE *getnode();
NODE *insert_front(int ele, NODE *last);
NODE *insert_rear(int ele, NODE *last);
NODE *deletefront(NODE*last);
NODE *deleterear(NODE*last);
NODE *insertspecific(int ele,int pos,NODE*last);
NODE *reverseLL(NODE *last,int n);
NODE *deletespecific(int pos,NODE*last,int n);
NODE *updatenode(int ele,int pos,NODE *last);
NODE *sortList(NODE *last);
NODE *delduplicate(NODE*last,int n);
NODE *copyll(NODE*last,int n);
NODE *checkpal(NODE*last,int n);
void display_list(NODE * last);
void search_list(int ele,NODE *last);

int main()
{ NODE *last=NULL;

 int ch,ele,n=0,pos,flag;
 for(;;)
 {   
     printf("\n MENU for CIRCULAR LINKED LIST \n enter \n 1.to Insert at the front of the list\n 2.to Insert at rear of the list\n 3.to Delete from the front of the list\n 4.to Delete from the rear of the list\n 5.to Display the content of the list \n 6.to insert at specific position \n 7.to delete from a specific position \n 8.to merge two lists \n 9.to search an element \n 10.to reverse the list \n 11.to update a node in the list \n 12.to sort the list \n 13.to remove duplicate nodes in a list if present \n 14.to check if given list is a palindrome \n 15. to exit \n");
     scanf("%d",&ch);
     switch(ch)
      {
          case 1:
                 printf("enter the data at the front of the list\n");
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
         case 6:printf("enter the position at which node should be inserted ");
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
         case 7:
                  if(n==0)
                   {printf("empty list\n");
                   break;
                   }
                    printf("enter the position of the node that has to be deleted ");
                   scanf("%d",&pos);
             	   if((pos>n+1) || (pos == 0))
                  
                   { printf("invalid position\n");
                   break;
                   } 
                   else { last=deletespecific(pos,last,n);
                   n--;}
                   break;
                
                
         case 8:
                 last = listconcat(last);
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
    	 case 10:  last = reverseLL(last,n);
                    break;    
		 
		 case 11:printf("enter the position at which node should be updated ");
             	scanf("%d",&pos);
             	if((pos>n) || (pos == 0))
             	{
             	printf("invalid position \n");
             	break;}
             	else
             	{
             	printf("enter the replacing element  ");
             	scanf("%d",&ele);
             	last = updatenode(ele,pos,last);
             	}
             	break;
        case 12: last =sortList(last);
                 break;
   	    case 13:last= delduplicate(last,n);
   	            break;
   	    case 14: last = checkpal(last, n);
   	            break;
        case 15:exit(0);
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
NODE *listconcat(NODE*last)
{   NODE *t1= NULL,*t2 = NULL,*t3;
    char ans;
    int a,b,i,ele;
    
     printf("do you want to use existing list? (enter y for yes or n for no) ");
    scanf(" %c",&ans);
    switch(ans)
    {
        case 'y':if(last ==NULL)
                {printf("no pre existing 1st list present \n ");}
                t1=last;
                printf("enter the size of second list ");
                 scanf("%d",&a);
                 printf("enter the elements of second list ");
                for(i=0;i<a;i++)
                 {  
                     scanf("%d",&ele);
                    t2=insert_rear(ele,t2);
                     
                 }
                 if(t1==NULL)
                 return t2;
                 else break;
                 
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
     printf("\n");

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

 NODE *temp = getnode();
int count =1;

temp->data = ele;
if(last==NULL)
 {

	last = temp;
	last->link =temp;
	return last;
 }	
else if(last->link==last)
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
    
}

NODE *reverseLL(NODE *last ,int n)
{
    if(last == NULL)
{   printf("empty list \n");
	return NULL;
}
if(last->link==NULL)
{
	return last;

}
NODE *prev = last,*present = last->link,*next;

 
    while (present != last)
    {
        next  = present->link;  
        present->link = prev;   
        prev = present;
        present = next;
    }
     next  = present->link;  
        present->link = prev;   
        prev = present;
        present = next;
     

    return present;
}

NODE*deletespecific(int pos,NODE*last,int n)
{
    NODE *prev=NULL,*present=last->link;
    int count=1;
    if(last == NULL)
    { 
    	return NULL;
    }
    if(last->link==last)
    {
	printf("the element deleted is %d \n",last->data);
	
	return NULL;
    }
    if(pos==1)
    {
    prev = last;
    prev->link=present->link;
     printf("the element deleted is %d\n",present->data);
    free(present);
    return prev;
    }

    while(count!=pos)
    {
        prev=present;
        present = present->link;
        count++;
    }
    printf("the element deleted is %d\n",present->data);
    prev->link=present->link;
    free(present);
    
    if(pos==n)
    {return prev;}
    else
    return last;
    
    
}

NODE *updatenode(int ele,int pos,NODE *last)
{
   int count =1;

if(last==NULL)
 {

printf(" empty list \n");
  return NULL;
 }	


else
 { NODE *present=last->link;
	while(count!=pos)
	{
		
		present = present ->link;
		count++;
	}
	present->data= ele;
	return last;
 }
} 


NODE *sortList(NODE *last)
{  
NODE *current = last->link, *index = NULL;  
int temp;  
if(last == NULL)
{  
printf("List is empty");
return NULL;
}  
else
{  
    do
    {  
        //Index will point to node next to current  
        index = current->link;  
        while(index !=last->link) 
        {  
            //If current node is greater than index data, swaps the data  
            if(current->data > index->data)
            {  
                temp =current->data;  
                current->data= index->data;  
                index->data = temp;  
            }  
            index= index->link;  
        }  
        current =current->link;  
    }while(current->link != last->link);   
    return last;
}  
}



NODE *delduplicate(NODE*last,int n)
{
    
if(last == NULL)
{  
    printf("List is empty");
    return NULL;
}  
else if(last->link == last)
{  
    printf("one only node ! no duplicates \n");
    return last;
}  
else 
{     NODE *current = last->link, *index = NULL,*prev = NULL,*temp,*first =last->link; 
          int count =0;
          index = current->link;  
        printf("removing duplicates if present...\n");

          if(first->data==index->data)     // special case if 1st 2 nodes are equal
            {        

                first->link=index->link;
                temp = index;
                index= index->link;
                if(n==2)     /// if only 2 nodes are present
                {
                    last = first;
                }
                free(temp);
                count++;
                
            }
    do
    {  
        index = current->link;  
        prev = current;
        while(index !=last->link) 
        {   
             if(current->data == index->data) //if any two random nodes are equal
            {  

                prev->link =index->link;
                temp=index;
                index=index->link;
                if(temp->data ==last->data)    // if last 2 nodes are equal
                {
                    last = prev;
                }
                free(temp);
                count++;
            } 
            
            else                            //else countinue iteration
            {
            prev= index;
            index= index->link; 
            }
            
        }  
        current =current->link;  
    } while(current->link != last->link); 
    
    if(count==0)
     {printf("No duplicates \n");
        return last;
    }
    
    return last;
    
    
   }
}


NODE *checkpal(NODE*last,int n)
{
   if(last == NULL)
{   printf("empty list \n");
	return NULL;
}
if(last->link==NULL)
{   printf("it is a palindrome\n ");
	return last;

}
NODE* new=copyll(last, n);
NODE *newlast=copyll(last, n);  //since last changes itself in reverse we preserve last here
NODE* temp= newlast;   // newlast position is changed while comparing in palindrome check      
      int count = 0;
      new = reverseLL(last,n);

      for(int i=0;i<n;i++)
      {
          if(newlast->data!=new->data)
          {
              printf("not a palindrome \n");
              count = 1;
              break;
          }
          new=new->link;
          newlast=newlast->link;
      }
      if(count==0)
      printf("it is a palindrome \n");

     return temp;
}
NODE*copyll(NODE*last,int n)
{   int b=0;
    NODE *temp = last;
    last = last ->link;
    NODE*new=getnode();
    NODE *first = new;
    for(int i=0;i<n;i++)
    {
         new ->data=last->data;
         b++;
         if(b==n)
         break;
         NODE*temp=getnode();
         new->link=temp;
         new = new ->link;
         last = last ->link;

     }
    new->link = first;
    last = temp;

    return new;
}






