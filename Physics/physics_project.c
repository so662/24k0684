#include <stdio.h>

double calculateAcceleration(double velocity_initial, double velocity_final, double time) {
    return (velocity_final - velocity_initial) / time;
}

double calculateFinalVelocity(double velocity_initial, double acceleration, double time) {
    return velocity_initial + (acceleration * time);
}

double calculateInitialVelocity(double velocity_final, double acceleration, double time) {
    return velocity_final - (acceleration * time);
}

void displayMenu() {
    printf("\n============================================\n");
    printf("   Welcome to the Physics Calculator! \n");
    printf("============================================\n");
    printf("Please choose one of the following options:\n");
    printf("1. Calculate Acceleration\n");
    printf("2. Calculate Final Velocity\n");
    printf("3. Calculate Initial Velocity\n");
    printf("4. Exit\n");
    printf("Enter your choice (1-4): ");
}

void promptForInputs(int choice, double *velocity_initial, double *velocity_final, double *acceleration, double *time) {
    switch (choice) {
        case 1:
            printf("Enter the initial velocity (m/s): ");
            scanf("%lf", velocity_initial);
            printf("Enter the final velocity (m/s): ");
            scanf("%lf", velocity_final);
            printf("Enter the time taken (seconds): ");
            scanf("%lf", time);
            break;
        case 2:
            printf("Enter the initial velocity (m/s): ");
            scanf("%lf", velocity_initial);
            printf("Enter the acceleration (m/s^2): ");
            scanf("%lf", acceleration);
            printf("Enter the time taken (seconds): ");
            scanf("%lf", time);
            break;
        case 3:
            printf("Enter the final velocity (m/s): ");
            scanf("%lf", velocity_final);
            printf("Enter the acceleration (m/s^2): ");
            scanf("%lf", acceleration);
            printf("Enter the time taken (seconds): ");
            scanf("%lf", time);
            break;
        default:
            printf("Invalid choice! Please select a valid option.\n");
            break;
    }
}

void displayResults(int choice, double result) {
    switch (choice) {
        case 1:
            printf("\nAcceleration: %.2f m/s^2\n", result);
            break;
        case 2:
            printf("\nFinal Velocity: %.2f m/s\n", result);
            break;
        case 3:
            printf("\nInitial Velocity: %.2f m/s\n", result);
            break;
        default:
            break;
    }
}

int main() {
    int choice;
    double velocity_initial, velocity_final, acceleration, time, result;

    do {
        displayMenu();
        scanf("%d", &choice);
        
        if (choice == 4) {
            printf("\nExiting program. Have a great day !\n\n");
            break;
        }

        promptForInputs(choice, &velocity_initial, &velocity_final, &acceleration, &time);

        switch (choice) {
            case 1:
                result = calculateAcceleration(velocity_initial, velocity_final, time);
                break;
            case 2:
                result = calculateFinalVelocity(velocity_initial, acceleration, time);
                break;
            case 3:
                result = calculateInitialVelocity(velocity_final, acceleration, time);
                break;
            default:
                printf("Invalid choice!\n");
                continue;
        }

        displayResults(choice, result);

    } while (choice != 4);

    return 0;
}
