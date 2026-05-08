#include "stack.h"
#include <stdio.h>

void displayStack(Stack s) {
    printf("Stack: [");
    for (int i = 0; i <= IDX_TOP(s); i++) {
        printf("%d", s.buffer[i]);
        if (i < IDX_TOP(s)) printf(", ");
    }
    printf("], Length: %d, Top Index: %d\n", length(s), IDX_TOP(s));
}

int main() {
    Stack s;
    CreateStack(&s);

    printf("Initial status:\n");
    displayStack(s);
    printf("isEmpty: %s\n", isEmpty(s) ? "true" : "false");

    printf("\nPushing 10, 20, 30:\n");
    push(&s, 10);
    displayStack(s);
    push(&s, 20);
    displayStack(s);
    push(&s, 30);
    displayStack(s);

    printf("\nTop element: %d\n", TOP(s));
    printf("Length: %d\n", length(s));

    printf("\nPopping elements:\n");
    ElType val;
    pop(&s, &val);
    printf("Popped: %d, ", val);
    displayStack(s);
    pop(&s, &val);
    printf("Popped: %d, ", val);
    displayStack(s);
    pop(&s, &val);
    printf("Popped: %d, ", val);
    displayStack(s);

    printf("\nisEmpty: %s\n", isEmpty(s) ? "true" : "false");

    printf("\nFilling stack to CAPACITY (%d):\n", CAPACITY);
    for (int i = 1; i <= CAPACITY; i++) {
        push(&s, i);
    }
    printf("Length: %d, isFull: %s\n", length(s), isFull(s) ? "true" : "false");

    return 0;
}
