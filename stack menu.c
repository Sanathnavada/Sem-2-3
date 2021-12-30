
#include <stdio.h>

int main()
{
    int *ptr,n,i,new;
    printf("enter the number of elements ");
    scanf("%d",&n);
    ptr = (int*)calloc(n,sizeof(int));
    if(ptr==NULL)
    { printf("no free memory !");}
    printf("enter the elements \n");
    for(i=0;i<n;i++)
    scanf("%d",(ptr +i));
    printf("the elements are \n");
    for(i=0;i<n;i++)
    printf("%d\t",*(ptr +i));
    printf("\n beginning reallocation...\n");
    printf("enter new size ");
    scanf("%d",&new);
    ptr = (int*)realloc(ptr,new*sizeof(int));
    printf("enter the new elements to be inserted \n");
    for(i=n;i<new;i++)
    scanf("%d",(ptr+i));
    printf("elements after reallocation are \n");
    for(i=0;i<new;i++)
    printf("%d\t",*(ptr+i));
    getch();
    
}

