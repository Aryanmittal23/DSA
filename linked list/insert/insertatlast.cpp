#include<iostream>
using namespace std;

struct Node{
    int data;
    struct Node* next;
}*first=NULL;

void create(int A[],int n)
{
    int i;
    struct Node *t,*last;
    first=(struct Node *)malloc(sizeof(struct Node));
    first->data=A[0];
    first->next=NULL;
    last=first;
    
    for(i=1;i<n;i++)
    {
        t=(struct Node*)malloc(sizeof(struct Node));
        t->data=A[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
}
void Display(struct Node *p)
{
    if(p!=NULL)
    {
        printf("%d",p->data);
        Display(p->next);
    }
}
int count(struct Node *p)
{
    int l=0;
    while(p)
    {
        l++;
        p=p->next;
    }
    return l;
}
void Insert(struct Node *p,int index,int x)
{
    struct Node *t;
    if(index<0 || index>count(p))
    return;
    t=(struct Node*)malloc(sizeof(struct Node));
    t->data=x;

    if(index==0)
    {
        t->next=first;
        first=t;
    }
    else
    {
        for(int i=0;i<index-1;i++)
        p=p->next;
        t->next=p->next;
        p->next=t;
    }
}
void SortedInsert(struct Node *p,int x)
{
    struct Node *t,*q=NULL;

    t=(struct Node*)malloc(sizeof(struct Node));
    t->data=x;
    t->next=NULL;

    if(first==NULL)
    first=t;
    else
    while(p && p->data<x)
    {
        q=p;
        p=p->next;
    }
    if(p==first)
    {
        t->next=first;
        first=t;
    }
    else
    {
        t->next=q->next;
        q->next=t;
    }

}
int main(){
    int A[]={1,2,3,4,5};
    create(A,5);
    SortedInsert(first,70);
    Display(first);
    printf("\n\n");

    
    return 0;
}