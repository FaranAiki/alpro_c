// NIM     : 18225122
// NAMA    : Muhammad Faran Aiki
// Tanggal : 12 Mei 2026


#include "bintree_traversal.h"
#include <stdio.h>
#include <stdlib.h>

/**
#include "bst.h"

typedef struct nodeList* AddressList;
typedef struct nodeList {
    ElType info;
    AddressList next;
} NodeList;

#define Info(L) (L)->info
#define Next(L) (L)->next
**/

void printPreOrder(BinTree p) {
    if (!isTreeEmpty(p)) {
        printf("%d ", ROOT(p).key);
        printPreOrder(LEFT(p));
        printPreOrder(RIGHT(p));
    }
}

void printInOrder(BinTree p) {
    if (!isTreeEmpty(p)) {
        printInOrder(LEFT(p));
        printf("%d ", ROOT(p).key);
        printInOrder(RIGHT(p));
    }
}

void printPostOrder(BinTree p) {
    if (!isTreeEmpty(p)) {
        printPostOrder(LEFT(p));
        printPostOrder(RIGHT(p));
        printf("%d ", ROOT(p).key);
    }
}

NodeList* newNodeListElement(ElType val) {
    NodeList* n = (NodeList*)malloc(sizeof(NodeList));
    if (n != NIL) {
        Info(n) = val;
        Next(n) = NIL;
    }
    return n;
}

NodeList* concat(NodeList* l1, NodeList* l2) {
    if (l1 == NIL) return l2;
    if (l2 == NIL) return l1;
    NodeList* p = l1;
    while (Next(p) != NIL) {
        p = Next(p);
    }
    Next(p) = l2;
    return l1;
}

NodeList* makeListPreOrder(BinTree p) {
    if (isTreeEmpty(p)) {
        return NIL;
    }
    NodeList* rootNode = newNodeListElement(ROOT(p));
    if (rootNode == NIL) return NIL;
    
    NodeList* leftList = makeListPreOrder(LEFT(p));
    NodeList* rightList = makeListPreOrder(RIGHT(p));
    
    return concat(rootNode, concat(leftList, rightList));
}

NodeList* makeListInOrder(BinTree p) {
    if (isTreeEmpty(p)) {
        return NIL;
    }
    NodeList* leftList = makeListInOrder(LEFT(p));
    NodeList* rootNode = newNodeListElement(ROOT(p));
    if (rootNode == NIL) return NIL;
    NodeList* rightList = makeListInOrder(RIGHT(p));
    
    return concat(leftList, concat(rootNode, rightList));
}

NodeList* makeListPostOrder(BinTree p) {
    if (isTreeEmpty(p)) {
        return NIL;
    }
    NodeList* leftList = makeListPostOrder(LEFT(p));
    NodeList* rightList = makeListPostOrder(RIGHT(p));
    NodeList* rootNode = newNodeListElement(ROOT(p));
    if (rootNode == NIL) return NIL;
    
    return concat(leftList, concat(rightList, rootNode));
}

/* Menampilkan isi NodeList ke layar */
void printNodeList(NodeList* l) {
    NodeList* p = l;
    while (p != NIL) {
        printf("[%d] -> ", Info(p).key);
        p = Next(p);
    }
    printf("FINISH\n");
}
