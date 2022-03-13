// doubly linked lists with header node

#include<stdio.h>
#include<stdlib.h>

typedef struct NODE
{
    int data;
    struct NODE *llink;
    struct NODE *rlink;
}node;

node *getnode()
{
    node *temp;
    temp = (node*)malloc(sizeof(node*));
    if(temp == NULL)
    {
        printf("No memory!\n");
    }
    return temp;
}

void ins_front(int ele,node *head)
{
    node *new = getnode();
    new->data = ele;
    if(head->rlink == NULL)
    {
        head->rlink = new;
        new->llink = head;
        (head->data)++;
        return;
    }
    node *temp;
    temp = head->rlink;
    if(temp->rlink == NULL)
    {
        new->llink = head;
        new->rlink = temp;
        head->rlink = temp->llink = new;
        (head->data)++;
        return;
    }
    new->llink = head;
    new->rlink = head->rlink;
    head->rlink = new;
    new = new->rlink;
    new->llink = head->rlink;
    (head->data)++;
    return;
}

void ins_rear(int ele,node *head)
{
    node *new = getnode();
    new->data = ele;
    new->rlink = NULL;
    if(head->rlink == NULL)
    {
        head->rlink = new;
        new->llink = head;
        (head->data)++;
        return;
    }
    node *temp;
    temp = head->rlink;
    while(temp->rlink != NULL)
    {
        temp = temp->rlink;
    }
    temp->rlink = new;
    new->llink = temp;
    (head->data)++;
    return;
}
void dis_ltor(node *head)
{
    node *temp;
    temp = head->rlink;
    printf("head-->");
    while(temp->rlink != NULL)
    {
        printf("%d-->",temp->data);
        temp = temp->rlink;
    }
    printf("%d\n",temp->data);
    return;
}

void dis_rtol(node *head)
{
    node *temp;
    temp = head->rlink;
    while(temp->rlink != NULL)
    {
        temp = temp->rlink;
    }
    while(temp->llink != head)
    {
        printf("%d-->",temp->data);
        temp = temp->llink;
    }
    printf("%d-->head\n",temp->data);
    return;
}

void ins_loc(int ele,node *head)
{
    int ch=1,pos;
    node *new = getnode();
    new->data = ele;
    node *prev = NULL,*present;
    if(head->rlink == NULL)
    {
        head->rlink = new;
        new->llink = head;
        new->rlink = NULL;
        (head->data)++;
        return;
    }
    dis_ltor(head);
    printf("Enter the position for insertion : ");
    scanf("%d",&pos);

    present = head->rlink;
    if(pos > (head->data + 1) || pos < 1)
    {
        printf("enter valid position!\n");
        return;
    }
    if(pos == 1)
    {
        ins_front(ele,head);
        return;
    }
    while(ch != pos)
    {
        prev = present;
        present = present->rlink;
        ch++;
    }
    new->llink = prev;
    new->rlink = present;
    present->llink = prev->rlink = new;
    (head->data)++;
    return;
}

void del_front(node *head)
{
    node *temp;
    if(head->rlink == NULL)
    {
        printf("No nodes to delete\n");
        return;
    }
    temp = head->rlink;
    if(temp->rlink == NULL)
    {
        printf("%d has been deleted\n",temp->data);
        head->rlink = NULL;
        free(temp);
        (head->data)--;
        return;
    }
    node *next;
    printf("%d has been deleted\n",temp->data);
    next = temp->rlink;
    head->rlink = next;
    next->llink = head;
    free(temp);
    (head->data)--;
    return;
}

void del_rear(node *head)
{
    node *temp;
    if(head->rlink == NULL)
    {
        printf("No nodes to delete\n");
        return;
    }
    temp = head->rlink;
    if(temp->rlink == NULL)
    {
        printf("%d has been deleted\n",temp->data);
        head->rlink = NULL;
        free(temp);
        (head->data)--;
        return;
    }
    node *next = NULL;
    while(temp->rlink != NULL)
    {
        next = temp;
        temp = temp->rlink;
    }
    printf("%d has been deleted\n",temp->data);
    next->rlink = NULL;
    free(temp);
    (head->data)--;
    return;
}

void del_loc(node *head)
{
    int pos,ch=1;
    node *prev = NULL,*present;
    if(head->rlink == NULL)
    {
        printf("No nodes to delete\n");
        return;
    }
    present = head->rlink;
    if(present->rlink == NULL)
    {
        printf("%d has been deleted\n",present->data);
        head->rlink = NULL;
        free(present);
        (head->data)--;
        return;
    }
    dis_ltor(head);
    printf("enter position to be deleted : ");
    scanf("%d",&pos);
    if(pos < 0 || pos >= (head->data + 1))
    {
        printf("Enter valid position!\n");
        return;
    }
    if(pos == 1)
    {
        del_front(head);
        return;
    }
    while(ch != pos)
    {
        prev = present;
        present = present->rlink;
        ch++;
    }
    node *next;
    printf("%d has been deleted\n",present->data);
    next = present->rlink;
    prev->rlink = next;
    next->llink = prev;
    free(present);
    (head->data)--;
    return;
}

int main()
{
    node *head = getnode();
    int ch,ele;
    head->data = 0;
    head->llink = head->rlink = NULL;
    for(;;)
    {
        printf("enter\n1.insert front\n2.insert rear\n3.delete front\n4.delete rear\n5.insert at certain location\n6.delete at certain location\n7.display from left to right\n8.display from right to left\n9.exit\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1 : 
            printf("enter the element : ");
            scanf("%d",&ele);
            ins_front(ele,head);
            break;
            case 2 :
            printf("enter the element : ");
            scanf("%d",&ele);
            ins_rear(ele,head);
            break;
            case 3 :
            del_front(head);
            break;
            case 4 :
            del_rear(head);
            break;
            case 5 :
            printf("enter the element : ");
            scanf("%d",&ele);
            ins_loc(ele,head);
            break;
            case 6 :
            del_loc(head);
            break;
            case 7 :
            dis_ltor(head);
            break;
            case 8 :
            dis_rtol(head);
            break;
            case 9 : exit(0);
            default : printf("enter values from (1-9) only!!\n");
            break;
        }
    }
    return 0;
}
