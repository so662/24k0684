#include <stdio.h>

int main() {
    int n, i = 0, j = 0, value;

    printf("Array size: ");
    scanf("%d", &n);

    int arr[n];
    int arr2[n];

    for (i = 0; i < n; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
        arr2[i] = 0;
    }

    i = 0;
    value = arr[0];

    do {
        if (value == arr[j] && i != j) {
            arr2[j] = 1;
        }
        j++;

        if (j == n) {
            j = 0;
            value = arr[++i];
            if (i == n) {
                break;
            }
        }
    } while (i < n);

    printf("\nDuplicate elements:\n");
    int duplicateFound = 0;
    for (i = 0; i < n; i++) {
        if (arr2[i] == 1 ) {
            printf("Number %d occurs more than once.\n", arr[i]);
            duplicateFound = 1;
        }
    }

    if (!duplicateFound) {
        printf("No duplicates found.\n");
    }

    return 0;
}
