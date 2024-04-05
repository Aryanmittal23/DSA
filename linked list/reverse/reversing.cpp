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
int Rcount(struct Node *p)
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
/*int max(struct Node *p)
{
    int max=INT32_MIN;

    while(p)
    {
        if(p->data>max)
          max=p->data;
        p=p->next;
    }
    return max;
}*/
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
void Reverse1(struct Node *p)
{
    int *A,i=0;
    struct Node *q=p;

    A=(int*)malloc(sizeof(int)*count(p));
    while(q!=NULL)
    {
        A[i]=q->data;
        q=q->next;
        i++;
    }
    q=p;
    i--;
    while(q!=NULL)
    {
        q->data=A[i];
        q=q->next;
        i--;
    }
}

void Reverse2(struct Node *p)
{
    struct Node *q=NULL,*r=NULL;

    while(p!=NULL)
    {
        r=q;
        q=p;
        p=p->next;
        q->next=r;
    }
    first=q;
}

void Reverse3(struct Node *q,struct Node *p)
{
    if(p)
    {
        Reverse3(p,p->next);
        p->next=q;
    }
    else
        first=q;
}
int main(){
    int A[]={3,5,7,10,15};

    create(A,5);

    
    //printf("max is %d",Rmax(first));
     
     Reverse2(first);
    // Reverse3(NULL,first);
     RDisplay(first);
    return 0;
}