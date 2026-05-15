#include "bst.h"
#include <stdio.h>
#include <stdlib.h>

/*
typedef struct {
    int key;
    int count;
} ElType;

typedef struct treeNode *Address;
typedef struct treeNode {
    ElType info;
    Address left;
    Address right;
} TreeNode;

typedef Address BinTree;

#define NIL NULL

 ********* AKSES (Selektor) ********* */
/*
#define ROOT(p) (p)->info
#define LEFT(p) (p)->left
#define RIGHT(p) (p)->right
*/

Address newTreeNode(ElType x) {
    Address p = (Address)malloc(sizeof(TreeNode));
    if (!p) return NIL;
    
    ROOT(p) = x;
    LEFT(p) = NIL;
    RIGHT(p) = NIL;
    
    return p;
}

void deallocTreeNode(Address p) {
    free(p);
}

boolean isTreeEmpty(BinTree p) {
    return p == NIL;
}

boolean isOneElmt(BinTree p) {
    return !isTreeEmpty(p) && LEFT(p) == NIL && RIGHT(p) == NIL;
}

boolean isUnerLeft(BinTree p) {
    return !isTreeEmpty(p) && LEFT(p) != NIL && RIGHT(p) == NIL;
}

boolean isUnerRight(BinTree p) {
    return !isTreeEmpty(p) && LEFT(p) == NIL && RIGHT(p) != NIL;
}

boolean isBiner(BinTree p) {
    return !isTreeEmpty(p) && LEFT(p) != NIL && RIGHT(p) != NIL;
}

BinTree buildBalancedTree(int n) {
    if (n == 0) {
        return NIL;
    } else {
        int key;
        scanf("%d", &key);
        ElType x;
        x.key = key;
        x.count = 1;
        Address p = newTreeNode(x);
        if (p != NIL) {
            int nL = n / 2;
            int nR = n - nL - 1;
            LEFT(p) = buildBalancedTree(nL);
            RIGHT(p) = buildBalancedTree(nR);
        }
        return p;
    }
}

void insSearchTree(ElType x, BinTree *p) {
    if (isTreeEmpty(*p)) {
        *p = newTreeNode(x);
    } else {
        if (x.key == ROOT(*p).key) {
            ROOT(*p).count++;
        } else if (x.key < ROOT(*p).key) {
            insSearchTree(x, &LEFT(*p));
        } else {
            insSearchTree(x, &RIGHT(*p));
        }
    }
}

void delNode(BinTree *p) {
    Address q;
    if (RIGHT(*p) != NIL) {
        delNode(&RIGHT(*p));
    } else {
        q = *p;
        *p = LEFT(*p);
        deallocTreeNode(q);
    }
}

void delBTree(BinTree *p, ElType x) {
    if (isTreeEmpty(*p)) {
        return;
    }
    if (x.key < ROOT(*p).key) {
        delBTree(&LEFT(*p), x);
    } else if (x.key > ROOT(*p).key) {
        delBTree(&RIGHT(*p), x);
    } else { 
        Address q = *p;
        if (isOneElmt(*p)) {
            *p = NIL;
            deallocTreeNode(q);
        } else if (isUnerLeft(*p)) {
            *p = LEFT(*p);
            deallocTreeNode(q);
        } else if (isUnerRight(*p)) {
            *p = RIGHT(*p);
            deallocTreeNode(q);
        } else { // Biner
            Address maxLeft = LEFT(*p);
            while (RIGHT(maxLeft) != NIL) {
                maxLeft = RIGHT(maxLeft);
            }
            ROOT(*p) = ROOT(maxLeft);
            delNode(&LEFT(*p));
        }
    }
}

Address searchNode(BinTree p, int value) {
    if (isTreeEmpty(p)) {
        return NIL;
    } else {
        if (ROOT(p).key == value) {
            return p;
        } else if (value < ROOT(p).key) {
            return searchNode(LEFT(p), value);
        } else {
            return searchNode(RIGHT(p), value);
        }
    }
}

Address findMinimum(BinTree p) {
    if (isTreeEmpty(p)) {
        return NIL;
    } else {
        if (LEFT(p) == NIL) {
            return p;
        } else {
            return findMinimum(LEFT(p));
        }
    }
}
