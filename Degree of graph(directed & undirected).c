#include<stdio.h>
#include<stdlib.h>
#define size 30

void readmatrix(int n,int a[][20]);
void printmatrix(int n,int a[][20]);
void undirected(int n,int a[][20]);
void directed(int n,int a[][20]);

int main()
{
	int a[size][20],i,j,choice,n;
	printf("Enter the number of vertices: ");
	scanf("%d",&n);
	printf("Enter the adjacency matrix \n");
	readmatrix(n,a);
	printf("The entered adjacency matrix is :\n");
	printmatrix(n,a);
	for(;;)
	{
	printf( "Enter 1 for degree of undirected \n 2 for indegree and outdegree of directed \n 3 to exit\n");
	scanf("%d",&choice);
	
	
		switch(choice)
		{
			case 1: undirected(n,a);
				break;
			case 2:directed(n,a);
				break;
			case 3:exit(0);
			
			default: printf("enter a valid number(1-3) \n");
				break;
		}
	}
	return 0;
}

void readmatrix(int n,int a[][20])
{
	int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
}

void printmatrix(int n,int a[][20])
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d",a[i][j]);
        }
        printf("\n");
    }
}

void undirected(int n,int a[][20])
{
	int deg = 0,count=0,i,j;
	for(i=0;i<n;i++)
	{
		count =0;
		for(j=0;j<n;j++)
		{
			if(a[i][j]==1)
			count++;
		}
		if(count>deg)
		deg=count;
	}
	
	printf(" The degree of undirected graph is %d\n",deg);
	return;
}

void directed(int n,int a[][20])
{
	int indeg=0,outdeg=0,i,v;
	printf("Enter the vertices for which indegree and outdegree has to be found \n");
	scanf("%d",&v);
	
	for(i =0;i<n;i++)
	{
		if(a[v-1][i]==1)
		outdeg++;
	}
	
	for(i=0;i<n;i++)
	{
		if(a[i][v-1]==1)
		indeg++;
	}
	printf(" The indegree and outdegree of %d is %d and %d \n ",v,indeg,outdeg);
	return;
} 
