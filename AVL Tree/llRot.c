#include<stdio.h>
#include <stdlib.h> 

struct node{
    struct node *lchild;
    int data;
    int height;
    struct node *rchild;
} ;
struct node *root = NULL;

int NodeHeight(struct node *p)
{
    int hl,hr;
    hl=p && p->lchild ? p ->lchild->height : 0;
    hr=p && p->lchild ? p ->rchild->height : 0;
    
    return hl>hr? hl+1 : hr+1;
}
 int BalanceFactor(struct node *p)
 {
    int hl,hr;
    hl=p && p->lchild ? p->lchild ->height : 0;
    hr=p && p->lchild ? p->rchild ->height : 0;

    return hl-hr; 
 }

 struct node * LLRotation(struct node *p)
 {
    struct node *pl=p->lchild;
    struct node *plr=p->rchild;

    pl->rchild=p;
    p->lchild=plr;
    p->height=NodeHeight(p);
    pl->height=NodeHeight(p);
    

    if(root==p)
    root=pl;

    return p;
 };
 
 struct node * RLRotation(struct node *p)
 {
    return NULL;
 };
 struct node * LRRotation(struct node *p)
 {
    return NULL;
 };
 struct node * RRRotation(struct node *p)
 {
    return NULL;
 };
struct node *rinsert(struct node *p,int key)
{
    struct node *t=NULL;
    if(p==NULL)
    {
        t=(struct node *)malloc(sizeof(struct node));
        t->data=key;
        t->height=1;
        t->lchild=t->rchild=NULL;
        return t;
    }
    if(key<p->data)
    p->lchild=rinsert(p->lchild,key);
    else if(key>p->data)
    p->rchild=rinsert(p->rchild,key);

 p->height=NodeHeight(p);

 if(BalanceFactor(p)==2 && BalanceFactor(p->lchild)==1)
 return LLRotation(p);
 else if(BalanceFactor(p)==2 && BalanceFactor(p->lchild)==-1)
 return LRRotation(p);
else if(BalanceFactor(p)==-2 && BalanceFactor(p->rchild)==-1)
 return RRRotation(p);
 else if(BalanceFactor(p)==-2 && BalanceFactor(p->rchild)==1)
 return RLRotation(p);
     return p;
}

int main()
{
    root=rinsert(root,10);
    rinsert(root,5);
    rinsert(root,2);

    return 0;
}