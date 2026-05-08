#include "anomalinangor.h"
#include <stdio.h>

boolean isEscalating(List L) {
    if (isEmpty(L)) {
        return true;
    }
    
    Address p = L;
    while (NEXT(p) != NULL) {
        if (INFO(p) >= INFO(NEXT(p))) {
            return false;
        }
        p = NEXT(p);
    }
    
    return true;
}

int peakAnomaly(List L) {
    Address p = L;
    int max = INFO(p);
    
    p = NEXT(p);
    while (p != NULL) {
        if (INFO(p) > max) {
            max = INFO(p);
        }
        p = NEXT(p);
    }
    
    return max;
}
