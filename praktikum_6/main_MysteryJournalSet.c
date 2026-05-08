#include "MysteryJournalSet.c"

int main() {
    MysteryJournalSet D, M;
    CREATE_SET(&D);
    CREATE_SET(&M);

    char cmd[32];
    int x;

    while (scanf("%s", cmd) == 1) {
        if (strcmp(cmd, "END") == 0) {
            break;
        } else if (strcmp(cmd, "ADD_D") == 0) {
            scanf("%d", &x);
            INSERT_PAGE(&D, x);
        } else if (strcmp(cmd, "ADD_M") == 0) {
            scanf("%d", &x);
            INSERT_PAGE(&M, x);
        } else if (strcmp(cmd, "DEL_D") == 0) {
            scanf("%d", &x);
            DELETE_PAGE(&D, x);
        } else if (strcmp(cmd, "DEL_M") == 0) {
            scanf("%d", &x);
            DELETE_PAGE(&M, x);
        } else if (strcmp(cmd, "UNION") == 0) {
            MysteryJournalSet U = UNION_SET(&D, &M);
            PRINT_SET(&U);
            printf("\n");
        } else if (strcmp(cmd, "INTERSECT") == 0) {
            MysteryJournalSet I = INTERSECTION_SET(&D, &M);
            PRINT_SET(&I);
            printf("\n");
        } else if (strcmp(cmd, "DIFF") == 0) {
            MysteryJournalSet R = DIFFERENCE_SET(&D, &M);
            PRINT_SET(&R);
            printf("\n");
        } else if (strcmp(cmd, "SIZE_D") == 0) {
            printf("%d\n", CARDINALITY(&D));
        } else if (strcmp(cmd, "SIZE_M") == 0) {
            printf("%d\n", CARDINALITY(&M));
        } else if (strcmp(cmd, "PRINT_D") == 0) {
            PRINT_SET(&D);
            printf("\n");
        } else if (strcmp(cmd, "PRINT_M") == 0) {
            PRINT_SET(&M);
            printf("\n");
        }
    }

    return 0;
}
