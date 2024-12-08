#include <stdio.h>
#include <stdbool.h>
#include <string.h>

struct dateOfJoining {
    int day;
    int month;
    int year;
};

struct Employee {
    int employeeCode;
    char employeeName[50];
    struct dateOfJoining date;
};

void assign(struct Employee *emp, int index) {
    printf("\n--- Enter Details for Employee %d ---\n", index + 1);
    printf("Employee Code: ");
    scanf("%d", &emp->employeeCode);
    fflush(stdin);
    printf("Employee Name: ");
    fgets(emp->employeeName, sizeof(emp->employeeName), stdin);
    emp->employeeName[strcspn(emp->employeeName, "\n")] = '\0';
    printf("Date of Joining (dd mm yyyy): ");
    scanf("%d %d %d", &emp->date.day, &emp->date.month, &emp->date.year);
}

bool tenure_3(struct dateOfJoining joinDate, struct dateOfJoining currentDate) {
    int years = currentDate.year - joinDate.year;
    if (years > 3) {
        return true;
    } else if (years == 3) {
        if (currentDate.month > joinDate.month ||
           (currentDate.month == joinDate.month && currentDate.day >= joinDate.day)) {
            return true;
        }
    }
    return false;
}

int main() {
    struct Employee emp[4];
    struct dateOfJoining currentDate;
    int count = 0;

    printf("### Welcome to Employee Management System ###\n");
    printf("\n--- Step 1: Input Employee Details ---\n");
    for (int i = 0; i < 4; i++) {
        assign(&emp[i], i);
    }

    printf("\n--- Step 2: Enter Current Date ---\n");
    printf("Enter Current Date (dd mm yyyy): ");
    scanf("%d %d %d", &currentDate.day, &currentDate.month, &currentDate.year);

    printf("\n--- Employees with Tenure of More Than 3 Years ---\n");
    printf("Code\tName\t\t\tDate of Joining\n");
    printf("--------------------------------------------------\n");

    for (int i = 0; i < 4; i++) {
        if (tenure_3(emp[i].date, currentDate)) {
            count++;
            printf("%-8d%-24s%02d/%02d/%04d\n", emp[i].employeeCode, emp[i].employeeName, emp[i].date.day, emp[i].date.month, emp[i].date.year);
        }
    }

    if (count == 0) {
        printf("\nNo employee have a tenure of more than 3 years.\n");
    } else {
        printf("\nTotal Employees with Tenure of More Than 3 Years: %d\n", count);
    }

    printf("\nThank you for using the Employee Management System.\n");
    return 0;
}
