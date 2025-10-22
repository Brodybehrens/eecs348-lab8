#include <stdio.h>

int main(void) {
    int score;

    while (1) {
        printf("Enter the NFL score (Enter 1 to stop): ");
        if (scanf("%d", &score) != 1) {
            int c; while ((c = getchar()) != '\n' && c != EOF) {}
            printf("Invalid input. Please enter an integer.\n");
            continue;
        }

        if (score == 1) {
            break; // Exit the loop
        }
        if (score < 0) {
            printf("Invalid score: negative values are not allowed.\n");
            continue;
        }

        printf("Possible combinations of scoring plays if a team’s score is %d:\n", score);

        int found = 0;
        for (int td2 = 0; 8 * td2 <= score; ++td2) {
            for (int tdfg = 0; 7 * tdfg + 8 * td2 <= score; ++tdfg) {
                for (int td = 0; 6 * td + 7 * tdfg + 8 * td2 <= score; ++td) {
                    for (int fg = 0; 3 * fg + 6 * td + 7 * tdfg + 8 * td2 <= score; ++fg) {
                        int remaining = score - (8 * td2 + 7 * tdfg + 6 * td + 3 * fg);
                        if (remaining % 2 == 0) {
                            int safety = remaining / 2;
                            printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n",
                                   td2, tdfg, td, fg, safety);
                            found = 1;
                        }
                    }
                }
            }
        }

        if (!found) {
            printf("No combinations found.\n");
        }
    }

    return 0;
}
