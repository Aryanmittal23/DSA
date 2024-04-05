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
void RDisplay(struct Node *p)
{
    if(p!=NULL)
    {
        printf("%d",p->data);
        RDisplay(p->next);
    }
}
/*int Rcount(struct Node *p)
{
    if (p==0)
    return 0;
     
    return 1+Rcount(p->next);
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
int Add(struct Node *p)
{
    if(p!=0)
    return Add(p->next)+p->data;
    else
    return 0;
}
int Rsum(struct Node *p)
{
    if(p!=0)
    return Rsum(p->next)+p->data;
    else
    return 0;
}
int max(struct Node *p)
{
    int max=INT32_MIN;

    while(p)
    {
        if(p->data>max)
          max=p->data;
        p=p->next;
    }
    return max;
}
int Rmax(struct Node *p)
{
    int x=0;

    if(p==0)
    return INT32_MIN;
    x=Rmax(p->next);
    if(x>p->data)
    return x;
    else 
    return p->data;
}
int IsSorted(struct Node *p)
{
    int x=-65536;
    
    while(p!=NULL)
    {
        if(p->data<x)
        return 0;
        x=p->data;
        p=p->next;
    }
    return 1;
}*/
void RemoveDuplicate(struct Node *p)
{
    struct Node *q=p->next;

    while(q!=NULL)
    {
      if(p->data!=q-> data)
      {
        p=q;
        q=p->next;
      }  
      else
      {
        p->next=q->next;
        free(q);
        q=p->next;
      }
      
    }
}
int main(){
    int A[]={3,5,5};

    create(A,3);

    //RDisplay(first);
    //printf("max is %d",Rmax(first));
     
     //printf("%d\n",IsSorted(first));

RemoveDuplicate(first);
RDisplay(first);
printf("\n");
    return 0;
}