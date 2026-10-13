
#include <stdio.h>
#include <string.h>

// I use this structure to store each candidate's name, party, and votes.
struct Candidate {
    char name[20];
    char party;
    int votes;
};

int main(void) {
    // I create my four candidates and start their vote counts at zero.
    struct Candidate candidates[4] = {
        {"Griffin", 'R', 0},
        {"KJ",      'D', 0},
        {"Shawn",   'R', 0},
        {"Maddie",  'D', 0}
    };

    int choice;
    int i;
    int totalVotes = 0;

    // I keep the program running until the user chooses to exit.
    do {
        printf("\n===== VOTING PROGRAM =====\n");
        printf("1. Vote for a candidate\n");
        printf("2. Check election results\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");

        // I check whether the user entered a valid number.
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");

            // I clear invalid input so the program can continue.
            while (getchar() != '\n');
            choice = 0;
            continue;
        }

        if (choice == 1) {
            // I display all four candidates and their political parties.
            printf("\n===== CANDIDATES =====\n");

            for (i = 0; i < 4; i++) {
                printf("%d. %s - %s\n",
                       i + 1,
                       candidates[i].name,
                       candidates[i].party == 'R'
                           ? "Republican (R)"
                           : "Democrat (D)");
            }

            printf("Enter the number of your candidate (1-4): ");

            if (scanf("%d", &choice) != 1) {
                printf("Invalid input. Please enter a number.\n");
                while (getchar() != '\n');
                continue;
            }

            // I record the vote only if the candidate number is valid.
            if (choice >= 1 && choice <= 4) {
                candidates[choice - 1].votes++;
                totalVotes++;

                printf("\nThank you for voting for %s!\n",
                       candidates[choice - 1].name);
            } else {
                printf("Invalid candidate choice. No vote was recorded.\n");
            }

        } else if (choice == 2) {
            // I show the current vote totals for every candidate.
            printf("\n===== ELECTION RESULTS =====\n");

            for (i = 0; i < 4; i++) {
                printf("%s (%c): %d votes\n",
                       candidates[i].name,
                       candidates[i].party,
                       candidates[i].votes);
            }

            printf("Total votes cast: %d\n", totalVotes);

            // I identify the candidate or candidates with the most votes.
            int highestVotes = 0;

            for (i = 0; i < 4; i++) {
                if (candidates[i].votes > highestVotes) {
                    highestVotes = candidates[i].votes;
                }
            }

            if (totalVotes == 0) {
                printf("No votes have been cast yet.\n");
            } else {
                printf("Leading candidate(s): ");

                for (i = 0; i < 4; i++) {
                    if (candidates[i].votes == highestVotes) {
                        printf("%s ", candidates[i].name);
                    }
                }

                printf("with %d vote(s).\n", highestVotes);
            }

        } else if (choice == 3) {
            // I thank the user before ending the program.
            printf("\nThank you for using the voting program!\n");

        } else {
            printf("Invalid menu choice. Please choose 1, 2, or 3.\n");
        }

    } while (choice != 3);

    return 0;
}