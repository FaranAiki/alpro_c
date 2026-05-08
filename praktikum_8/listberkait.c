#include "listberkait.h"
#include <stdio.h>
#include <stdlib.h>

Address newNode(ElType val) {
    Address p = (Address) malloc(sizeof(Node));
    if (p != NULL) {
        INFO(p) = val;
        NEXT(p) = NULL;
    }
    return p;
}

void CreateList(List *l) {
    *l = NULL;
}

boolean isEmpty(List l) {
    return (l == NULL);
}

ElType getElmt(List l, int idx) {
    Address p = l;
    int count = 0;
    while (count < idx) {
        p = NEXT(p);
        count++;
    }
    return INFO(p);
}

void setElmt(List *l, int idx, ElType val) {
    Address p = *l;
    int count = 0;
    while (count < idx) {
        p = NEXT(p);
        count++;
    }
    INFO(p) = val;
}

int indexOf(List l, ElType val) {
    Address p = l;
    int idx = 0;
    while (p != NULL) {
        if (INFO(p) == val) {
            return idx;
        }
        p = NEXT(p);
        idx++;
    }
    return IDX_UNDEF;
}

void insertFirst(List *l, ElType val) {
    Address p = newNode(val);
    if (p != NULL) {
        NEXT(p) = *l;
        *l = p;
    }
}

void insertLast(List *l, ElType val) {
    if (isEmpty(*l)) {
        insertFirst(l, val);
    } else {
        Address p = newNode(val);
        if (p != NULL) {
            Address last = *l;
            while (NEXT(last) != NULL) {
                last = NEXT(last);
            }
            NEXT(last) = p;
        }
    }
}

void insertAt(List *l, ElType val, int idx) {
    if (idx == 0) {
        insertFirst(l, val);
    } else {
        Address p = newNode(val);
        if (p != NULL) {
            Address prec = *l;
            int count = 0;
            while (count < idx - 1) {
                prec = NEXT(prec);
                count++;
            }
            NEXT(p) = NEXT(prec);
            NEXT(prec) = p;
        }
    }
}

void deleteFirst(List *l, ElType *val) {
    Address p = *l;
    *val = INFO(p);
    *l = NEXT(p);
    free(p);
}

void deleteLast(List *l, ElType *val) {
    Address p = *l;
    Address prec = NULL;
    while (NEXT(p) != NULL) {
        prec = p;
        p = NEXT(p);
    }
    *val = INFO(p);
    if (prec == NULL) {
        *l = NULL;
    } else {
        NEXT(prec) = NULL;
    }
    free(p);
}

void deleteAt(List *l, int idx, ElType *val) {
    if (idx == 0) {
        deleteFirst(l, val);
    } else {
        Address prec = *l;
        int count = 0;
        while (count < idx - 1) {
            prec = NEXT(prec);
            count++;
        }
        Address p = NEXT(prec);
        *val = INFO(p);
        NEXT(prec) = NEXT(p);
        free(p);
    }
}

void displayList(List l) {
    printf("[");
    Address p = l;
    while (p != NULL) {
        printf("%d", INFO(p));
        if (NEXT(p) != NULL) {
            printf(",");
        }
        p = NEXT(p);
    }
    printf("]");
}

int length(List l) {
    int count = 0;
    Address p = l;
    while (p != NULL) {
        count++;
        p = NEXT(p);
    }
    return count;
}

List concat(List l1, List l2) {
    List l3;
    CreateList(&l3);
    Address p = l1;
    while (p != NULL) {
        insertLast(&l3, INFO(p));
        p = NEXT(p);
    }
    p = l2;
    while (p != NULL) {
        insertLast(&l3, INFO(p));
        p = NEXT(p);
    }
    return l3;
}
