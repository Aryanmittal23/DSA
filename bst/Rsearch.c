#include<stdio.h>

Rsearch(Node*t,int key)
{
    if(t==NULL)
    return NULL;
    if(key==t->data)
    return t;
    else if(key<t->data)
    return Rsearch(t->lchild,key);
    else
    return Rsearch(t->rchild,key);
}