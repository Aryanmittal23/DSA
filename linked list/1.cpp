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
/*void RDisplay(struct Node *p)
{
    if(p!=NULL)
    {
        printf("%d",p->data);
        RDisplay(p->next);
    }
}*/
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
}*/
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
int main(){
    int A[]={3,5,7,10,15};

    create(A,5);

    //RDisplay(first);
    printf("max is %d",Rmax(first));
     
    return 0;
}