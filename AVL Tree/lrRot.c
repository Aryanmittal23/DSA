#include <stdio.h>
#include <stdlib.h> // for memory allocation

struct node {
    struct node *lchild;
    int data;
    int height;
    struct node *rchild;
};

struct node *root = NULL;

int NodeHeight(struct node *p) {
    int hl, hr;
    hl = p && p->lchild ? p->lchild->height : 0;
    hr = p && p->rchild ? p->rchild->height : 0;
    return hl > hr ? hl + 1 : hr + 1;
}

int BalanceFactor(struct node *p) {
    int hl, hr;
    hl = p && p->lchild ? p->lchild->height : 0;
    hr = p && p->rchild ? p->rchild->height : 0;
    return hl - hr;
}

struct node *LLRotation(struct node *p) {
    struct node *pl = p->lchild;
    struct node *plr = p->lchild->rchild;

    pl->rchild = p;
    p->lchild = plr;

    p->height = NodeHeight(p);
    pl->height = NodeHeight(pl);

    if (root == p) {
        root = pl;
    }

    return pl;
}

struct node *RLRotation(struct node *p) {
    p->lchild = RLRotation(p->lchild);
    return LLRotation(p);
}

struct node *LRRotation(struct node *p) {
    p->rchild = LLRotation(p->rchild);
    return RLRotation(p);
}

struct node *RRRotation(struct node *p) {
    struct node *plr = p->rchild;
    struct node *plrl = p->rchild->lchild;

    plr->lchild = p;
    p->rchild = plrl;

    p->height = NodeHeight(p);
    plr->height = NodeHeight(plr);

    if (root == p) {
        root = plr;
    }

    return plr;
}

struct node *rinsert(struct node *p, int key) {
    if (p == NULL) {
        struct node *t = (struct node *)malloc(sizeof(struct node));
        t->data = key;
        t->height = 1;
        t->lchild = t->rchild = NULL;
        return t;
    }

    if (key < p->data) {
        p->lchild = rinsert(p->lchild, key);
    } else if (key > p->data) {
        p->rchild = rinsert(p->rchild, key);
    }

    p->height = NodeHeight(p);

    if (BalanceFactor(p) == 2 && BalanceFactor(p->lchild) == 1) {
        return LLRotation(p);
    } else if (BalanceFactor(p) == 2 && BalanceFactor(p->lchild) == -1) {
        return LRRotation(p);
    } else if (BalanceFactor(p) == -2 && BalanceFactor(p->rchild) == -1) {
        return RRRotation(p);
    } else if (BalanceFactor(p) == -2 && BalanceFactor(p->rchild) == 1) {
        return RLRotation(p);
    }

    return p;
}

int main() {
    root = rinsert(root, 10);
    rinsert(root, 5);
    rinsert(root, 2);

    // Add code to perform operations on the AVL tree (e.g., search, deletion)

    return 0;
}
