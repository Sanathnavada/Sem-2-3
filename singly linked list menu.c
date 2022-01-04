#include <stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *link;
    
}NODE;
NODE * getdata();
NODE *insert_front(int ele,NODE *first);
NODE *insert_rear(int ele, NODE * first);
NODE *deletefront(NODE*first);
NODE *deleterear(NODE*first);
int searchlist(int el,NODE*first);
NODE*insertspecific(int elo,int pos,NODE*first);
NODE*deletespecific(int pos,NODE*first);
NODE* selectionSort(NODE *first, int n);
NODE *reversell(NODE *first);
int main()
{
    NODE *first=NULL;
    NODE *temp,*i;
   int ch,n=0,ele,el,elo,pos;
   
   for(;;)
   {
       printf("enter  \n 1 to Insert a node at the front of the list\n 2 to Insert a node at rear of the list\n 3 to Delete a node from the front of the list\n 4 to Delete a node from thr rear of the list\n 5 to insert a node at specific position \n 6 to delete a node from a specific position\n 7 to Display the content of the list \n 8 to search an element \n 9 to reverse the list \n 10 to exit \n ");
       scanf("%d",&ch);
       switch(ch)
       {
           case 1:printf("enter the data at the front of the list\n");
                  scanf("%d",&ele);
                  first=insert_front(ele,first);
                  n++;
                  break;
                  
           case 2:printf("enter the data at the rear of the list\n");
                  scanf("%d",&ele);
                  first=insert_rear(ele,first);
                  n++;
                  break;
                  
           case 3:first=deletefront(first);  
                  if(first==NULL)
                  {printf("ALL ELEMENTS HAVE BEEN DELETED\n");}  
                  n--;
                  break;
                  
           case 4:first=deleterear(first);
                  if(first==NULL)
                  {printf("ALL ELEMENTS HAVE BEEN DELETED\n");} 
                  n--;
                  break;  
                   
           case 7:if(first==NULL)
                  {printf("EMPTY LIST\n");}
                  else
                  {
                  printf("the content of the list is\n ");
                   for( i=first;i!=NULL;i=i->link)
                  {                  
                    printf("%d\t",i->data);
                   
                  }
                  }
                  break;
            case 5:printf("enter the position of the node to be inserted ");
                   scanf("%d",&pos);
                   if(pos>n+1)
                   { printf("invalid position\n");
                   break;
                   }
                   else {printf("enter the element to be inserted ");
                   scanf("%d",&elo);
                   first=insertspecific(elo,pos,first);
                   n++;
                   }
                   break;
            case 6: if(n==0)
                   {printf("empty list\n");
                   break;
                   }
                    printf("enter the position of the node that has to be deleted ");
                   scanf("%d",&pos);
                   if(pos>n)
                  
                   { printf("invalid position\n");
                   break;
                   } 
                   else { first=deletespecific(pos,first);
                   n--;}
                   break;
            
            case 8:if(first==NULL)
                  {  printf("EMPTY LIST\n");
                      break;
                  }
                  printf("enter the element to be searched ");
                  scanf("%d",&el);
                  searchlist(el,first);
                  break;
            

            case 9: first = reversell(first);
                     break;
            
           case 10:exit(0);  

            
            default: printf("enter from 1-5\n");        
       } 
   }

    return 0;
}

NODE * getdata()
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

NODE*insertspecific(int elo,int pos,NODE*first)
{
    NODE *prev=NULL,*present=first;
    NODE *temp=getdata();
    int count=1;
    if(first ==NULL)
    {   temp->data=elo;
        return temp;}
     else if(first->link==NULL)
    {
        temp->link=first;
         temp->data=elo;
        first = temp;
        
        return first;}
    else
    {
        while(count!=pos)
        {
            prev=present;
            present = present->link;
            count++;
        }
        temp->data=elo;
        prev->link=temp;
        temp->link =present;
        return first;
    }
}

NODE*deletespecific(int pos,NODE*first)
{
    NODE *prev=NULL,*present=first;
    int count=1;
    if(first == NULL)
    { 
    	return NULL;
    }
    if(first->link==NULL)
    {
	printf("the element deleted is %d \n",first->data);
	return NULL;
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
    return first;
    
    
}

NODE *insert_front(int ele,NODE *first)
{
    NODE *temp=getdata();
    temp->data=ele;
    temp->link=first;
    return temp;
    
}
NODE *insert_rear(int ele, NODE * first)
{
    NODE *tent;
    NODE *temp=getdata();
    temp->data=ele;
    temp->link=NULL;
    if(first==NULL)
    {
        return temp;
        
    }
    tent=first;
    while(tent->link!=NULL)
    {
        tent=tent->link;
        
    }
    tent->link=temp;
    return first;
}    


NODE *deleterear(NODE*first)
{
NODE*temp,*prev,*present;
if(first == NULL)
{ 
	return NULL;
}
if(first->link==NULL)
{
	printf("the element deleted is %d \n",first->data);
	return NULL;

}

prev = NULL;
present = first;
while(present->link!=NULL)
{
	prev = present;
	present = present->link;
}
printf("the element deleted is %d \n",present->data);
prev->link= NULL;
free(present);
return first;
}

NODE *deletefront(NODE*first)
{ NODE*temp;
if(first==NULL)
{
	return NULL;
}
temp=first;
first= first->link;

printf("the element deleted at the rear is %d \n",temp->data);
free(temp);
return first;
}

int searchlist(int el,NODE*first)
{   NODE*temp = first;
    int count=1,t=0;
    while(temp!=NULL)
    {
        if(temp->data==el)
        {printf("search successfull! element found at position %d\n",count);
              t=1;
            break;
          
        }
        
       
        count++;
       temp= temp->link;
    }
    if(t==0)
    printf("search unsuccessfull\n");
}

NODE *reversell(NODE *first)
{
    if(first == NULL)
{   printf("empty list \n");
	return NULL;
}
if(first->link==NULL)
{
	return first;

}
NODE *temp,*prev = NULL,*present = first,*next;

 
    while (present != NULL)
    {
        next  = present->link;  
        present->link = prev;   
        prev = present;
        present = next;
    }
    return prev;
}



