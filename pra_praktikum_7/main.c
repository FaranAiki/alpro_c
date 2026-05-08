#include "queue.h"
#include <stdio.h>

void displayQueue(Queue q) {
    printf("Queue: [");
    if (!isEmpty(q)) {
        for (int i = IDX_HEAD(q); i <= IDX_TAIL(q); i++) {
            printf("%d", q.buffer[i]);
            if (i < IDX_TAIL(q)) printf(", ");
        }
    }
    printf("], Length: %d, Head: %d, Tail: %d\n", length(q), IDX_HEAD(q), IDX_TAIL(q));
}

int main() {
    Queue q;
    CreateQueue(&q);
    
    printf("Initial status:\n");
    displayQueue(q);
    printf("isEmpty: %s\n", isEmpty(q) ? "true" : "false");

    printf("\nEnqueuing 1 to 5:\n");
    for (int i = 1; i <= 5; i++) {
        enqueue(&q, i);
    }
    displayQueue(q);

    printf("\nDequeuing 3 elements:\n");
    ElType val;
    for (int i = 0; i < 3; i++) {
        dequeue(&q, &val);
        printf("Dequeued: %d\n", val);
    }
    displayQueue(q);
    printf("Front: %d\n", front(q));

    printf("\nEnqueuing 6 to 13 (should trigger shift at 11):\n");
    for (int i = 6; i <= 13; i++) {
        enqueue(&q, i);
        printf("Enqueued %d. ", i);
        displayQueue(q);
    }

    printf("\nIs Full: %s\n", isFull(q) ? "true" : "false");

    printf("\nDequeuing all:\n");
    while (!isEmpty(q)) {
        dequeue(&q, &val);
        printf("Dequeued: %d, ", val);
        displayQueue(q);
    }
    printf("isEmpty: %s\n", isEmpty(q) ? "true" : "false");

    return 0;
}
