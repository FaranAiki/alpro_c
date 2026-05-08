#include <stdio.h>
#include <string.h>
#include "MysteryShopMap.c"

int main() {
    MysteryShopMap M;
    CREATE_MAP(&M);

    char cmd[16];
    char key[MAX_KEY_LEN];
    int value;

    while (scanf("%s", cmd) == 1) {
        if (strcmp(cmd, "END") == 0) {
            break;
        } else if (strcmp(cmd, "SET") == 0) {
            scanf("%s %d", key, &value);
            SET_ITEM(&M, key, value);
        } else if (strcmp(cmd, "UNSET") == 0) {
            scanf("%s", key);
            UNSET_ITEM(&M, key);
        } else if (strcmp(cmd, "GET") == 0) {
            scanf("%s", key);
            if (FIND_ITEM(&M, key, &value)) {
                printf("%d\n", value);
            } else {
                printf("NOT_FOUND\n");
            }
        } else if (strcmp(cmd, "TOTAL") == 0) {
            printf("%d\n", TOTAL_STOCK(&M));
        } else if (strcmp(cmd, "PRINT") == 0) {
            PRINT_MAP(&M);
        }
    }

    return 0;
}
