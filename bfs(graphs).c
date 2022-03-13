#include<stdio.h>
#include<stdlib.h>
#define size 20

void readmatrix(int n,int a[][20]);
void printmatrix(int n,int a[][20]);
void bfs(int n,int vis[],int a[][20],int src);
void bfsd(int n,int vis[],int src);

int main()
{
	int a[size][20],i,j,choice,n,src,vis[20];
	printf("Enter the number of vertices: ");
	scanf("%d",&n);
	printf("Enter the adjacency matrix \n");
	readmatrix(n,a);
	printf("The entered adjacency matrix is :\n");
	printmatrix(n,a);
	printf("Enter the source vertex ");
	scanf("%d",&src);
	for(i=0;i<n;i++)
	{
	vis[i]=0;
	}
	printf("implementing BFS \n");
	bfs(n,vis,a,src);
	
	bfsd(n,vis,src);
	
	
	
	
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

void bfs(int n,int vis[],int a[][20],int src)     // BFS FUNCTION
{
int q[size],f=0,r=0,u,v;
vis[src]=1;
q[r]=src;
while(f<=r)
   {
	u=q[f++];
	for(v=0;v<n;v++)
	{
		if(a[u][v]==1 && vis[v]==0)
		{
			q[++r]=v;
			vis[v] =1;
		}
	}
   }
}


void bfsd(int n,int vis[],int src)            // BFS DISPLAY
{
	for(int i=0;i<n;i++)
	{
		if(vis[i]==0)
		printf("%d not reachable from %d \n",i,src);
		else
		printf("%d reachable from %d \n",i,src);
	}

}
