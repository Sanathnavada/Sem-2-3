#include<stdio.h>
#include<stdlib.h>
struct node
{
	struct node * llink;
	int info;
	struct node * rlink;
};
typedef struct node * NODE;

NODE getnode();
NODE insert(NODE root, int item);
void preorder(NODE root);
void inorder(NODE root);
void postorder(NODE root);
void search(NODE root, int ele);

int main()
{
	NODE root=NULL;
	int ch,ele;
	while(1)
	{
		printf("1.Insert_BST\n2.Preorder traversal\n3.Inorder traversal\n4.Postorder traversal\n5.Search\n6.Exit:\n");
		scanf("%d", &ch);
		switch(ch)
		{
			case 1: printf("Enter the element to insert:");
				scanf("%d", &ele);
				root=insert(root,ele);
				break;
			case 2: preorder(root);
				break;
			case 3: inorder(root);
				break;
			case 4: postorder(root);
				break;
			case 5: printf("Enter the element to search:");
				scanf("%d", &ele);
				search(root,ele);
				break;
			case 6: exit(0);
		}
	}
}

NODE getnode()
{
	NODE x;
	x=(NODE)malloc(sizeof(struct node));
	if(x==NULL)
	{
		printf("No memory available");
		return NULL;
	}
	return x;
}

NODE insert(NODE root, int item)
{
	NODE cur,prev,temp;
	temp=getnode();
	temp->info=item;
	temp->llink=NULL;
	temp->rlink=NULL;
	if(root==NULL)
	{
		return temp;
	}
	cur=root;
	prev=NULL;
	while(cur!=NULL)
	{
		prev=cur;
		if(cur->info>item)
			cur=cur->llink;
		else
			cur=cur->rlink;
	}
	if(prev->info>item)
		prev->llink=temp;
	else
		prev->rlink=temp;
	return root;
}

void preorder(NODE root)
{
	if(root==NULL)
		return;
	printf("%d\n", root->info);
	preorder(root->llink);
	preorder(root->rlink);
}

void inorder(NODE root)
{
	if(root==NULL)
		return;
	inorder(root->llink);
	printf("%d\n", root->info);
	inorder(root->rlink);

}

void postorder(NODE root)
{
	if(root==NULL)
		return;
	postorder(root->llink);
	postorder(root->rlink);
	printf("%d\n", root->info);
}

void search(NODE root, int ele)
{
	NODE cur;
	if(root==NULL)
		return;
	cur=root;
	while(cur!=NULL)
	{
		if(cur->info==ele)
		{
			printf("Element found");
			return;
		}
		if(cur->info>ele)
			cur=cur->llink;
		else
			cur=cur->rlink;
	}
	printf("Element not found");
}
