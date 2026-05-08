#include "CipherHashMap.c"

int main() {
    CipherHashMap M;
    CREATE_HASHMAP(&M);

    char cmd[32];
    char key[MAX_KEY_LEN];
    int value;

    while (scanf("%s", cmd) == 1) {
        if (strcmp(cmd, "END") == 0) {
            break;
        } else if (strcmp(cmd, "SET") == 0) {
            scanf("%s %d", key, &value);
            SET_SPELL(&M, key, value);
        } else if (strcmp(cmd, "UNSET") == 0) {
            scanf("%s", key);
            UNSET_SPELL(&M, key);
        } else if (strcmp(cmd, "GET") == 0) {
            scanf("%s", key);
            if (FIND_SPELL(&M, key, &value)) {
                printf("%d\n", value);
            } else {
                printf("NOT_FOUND\n");
            }
        } else if (strcmp(cmd, "PRINT") == 0) {
            PRINT_HASHMAP(&M);
        }
    }

    return 0;
}
