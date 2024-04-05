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
struct Node * Lsearch(struct Node *p,int key)
{
    struct Node *q;
    while(p!=NULL)
    {
        if(key==p->data)
        {
            q->next=p->next;
            p->next=first;
            first=p;
          return p;
          }
          q=p;
        p=p->next;
    }
    return NULL;
}
/*struct Node* Rsearch(struct Node *p,int key)
{
    if(p==NULL)
    return NULL;
    if(key==p->data)
    return p;
    return Rsearch(p->next,key);
}*/
void RDisplay(struct Node *p)
{
    if(p!=NULL)
    {
        printf("%d",p->data);
        RDisplay(p->next);
    }
}

int main(){
    struct Node *temp;

    int A[]={3,5,7,10,15,23,45};
    create(A,5);

    temp=Lsearch(first,7);
    temp=Lsearch(first,45);
    if(temp)
    printf( "key is found %d",temp->data);
    else
    printf("key is not found");
     
     RDisplay(first);
    return 0;
}