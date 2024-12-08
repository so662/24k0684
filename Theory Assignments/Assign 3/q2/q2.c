#include <stdio.h>
#include <stdbool.h>
#include <string.h>

struct Player {
    int ballScores[12];
    char playerName[50];
    int totalScore;
};

bool validateScore(int score) {
    return score >= 0 && score <= 6;
}

void playGame(struct Player *player) {
    printf("Enter Player Name: ");
    gets(player->playerName);
    player->totalScore = 0;

    for (int i = 0; i < 12; i++) {
        int temp;
        printf("Enter score for ball %d: ", i + 1);
        scanf("%d", &temp);
        if (validateScore(temp)) {
            player->ballScores[i] = temp;
            player->totalScore += temp;
        } else {
            printf("Invalid score! Ball %d marked with 0.\n", i + 1);
            player->ballScores[i] = 0;
        }
    }
}

void findWinner(struct Player player1, struct Player player2) {
    if (player1.totalScore > player2.totalScore) {
        printf("\nThe Winner is %s with a score of %d!\n", player1.playerName, player1.totalScore);
    } else if (player1.totalScore < player2.totalScore) {
        printf("\nThe Winner is %s with a score of %d!\n", player2.playerName, player2.totalScore);
    } else {
        printf("\nIt's a tie! Both players scored %d.\n", player1.totalScore);
    }
}

void displayMatchScoreboard(struct Player player1, struct Player player2) {
    printf("\n--- Match Scoreboard ---\n");
    printf("Player\t\tScores (per ball)\t\tTotal Score\tAverage Score\n");
    printf("-----------------------------------------------------------------------------\n");

    printf("%-10s\t", player1.playerName);
    for (int i = 0; i < 12; i++) {
        printf("%d ", player1.ballScores[i]);
    }
    printf("\t%d\t\t%.2f\n", player1.totalScore, player1.totalScore / 12.0);

    printf("%-10s\t", player2.playerName);
    for (int i = 0; i < 12; i++) {
        printf("%d ", player2.ballScores[i]);
    }
    printf("\t%d\t\t%.2f\n", player2.totalScore, player2.totalScore / 12.0);
}

int main() {
    struct Player player1, player2;

    printf("### Welcome to Soofiyan Cricket Showdown! ###\n\n");
    fflush(stdin);
    printf("--- Player 1 ---\n");
    playGame(&player1);

    fflush(stdin);
    printf("\n--- Player 2 ---\n");
    playGame(&player2);

    printf("\n--- Match Summary ---\n");
    displayMatchScoreboard(player1, player2);

    findWinner(player1, player2);

    printf("\nThank you for playing soofiyan Cricket Showdown!\n");
    return 0;
}
