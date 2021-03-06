//Want to know about Problem?
//-Read in Description
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node*link;
}*first=NULL;
void create(int A[], int n)
{
    struct node *t,*last;
    struct node *p=(struct node *)malloc(sizeof(struct node));
    first=p;
    first->data=A[0];
    first->link=NULL;
    last=first;
    for(int i=1;i<n;i++)
    {
        t=(struct node*)malloc(sizeof(struct node));
        t->data=A[i];
        last->link=t;
        t->link=NULL;
        last=t;
    }
}
void display(struct node*temp)
{
    while(temp->link!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->link;
    }
    printf("%d ",temp->data);
    free(temp);
}
int count(struct node*c1)
{
    int c=0;
    while(c1)
    {
        c++;
        c1=c1->link;
    }
    return c;
}
int rec_count(struct node *rec1)//recursive function to count
{
    if(rec1)
    {
        return 1+rec_count(rec1->link);
    }
    else
    {
        return 0;
    }
}
int sum(struct node *s1)
{ int find=0;
    while(s1)
    {
        find=find+s1->data;
        s1=s1->link;
    }
    return find;
}
int main()
{
    int A[5]={2,4,6,89,81};
    create(A,5);
    //display(first);
    printf("%d\n",count(first));
    printf("%d\n",rec_count(first));
    printf("%d\n",sum(first));
    return 0;
}
