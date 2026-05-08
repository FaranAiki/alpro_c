#include <stdio.h>
#include <stdlib.h>

#include "stack.h"

// masalahnya gmn biar stack bisa lebih daripada 100 oit
int main() {
  Stack stack;
  CreateStack(&stack); 
  int n, inp;
  if (scanf("%d", &n) != 1 || n <= 0) {
    printf("Celah telah tertutup\n");
    return 0;
  }
  
  for (int i = 0; i < n; i++) {
    scanf("%d", &inp);
    int meledak = 0;
    
    while (!isEmpty(stack)) {
      int temp;
      pop(&stack, &temp);
      
      if (temp > 0 && inp < 0) {
        if (temp > -inp) {
          push(&stack, temp); 
          meledak = 1;
          break;
        } else if (temp == -inp) {
          meledak = 1; 
          break;
        }
      } else {
        push(&stack, temp);
        break;
      }
    }

    // meledak di sini
    if (!meledak) {
      push(&stack, inp);
    }
  }

  if (!isEmpty(stack)) {
    Stack temp;
    CreateStack(&temp);
    
    while (!isEmpty(stack)) {
      int val;
      pop(&stack, &val);
      push(&temp, val);
    }
   
    // ubah jadi while aja biar enak bacanya
    int pertama = 1;
    while (!isEmpty(temp)) {
      int val;
      pop(&temp, &val);
      if (pertama) {
        printf("%d", val);
        pertama = 0;
      } else {
        printf(" %d", val);
      }
    }
    printf("\n");
    return 0;
  }

  printf("Celah telah tertutup\n");
  return 0;
}
