#include <stdio.h>
#include <stdbool.h>

int main() {
    int i, j, arr[3][3], mininrow, maxincol, k, temp, g, l;
    bool minfound = false, maxfound;

    printf("\n##---------- Input 3x3 Matrix ----------##\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("Enter arr[%d][%d]: ", i, j);
            scanf("%d", &arr[i][j]);
        }
    }

    printf("\n##---------- Your Matrix ----------##\n\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf(" | %2d | ", arr[i][j]);
        }
        printf("\n\n");
    }

    for (i = 0; i < 3; i++) {
        mininrow = arr[i][0];
        g = i;
        temp = 0;

        for (j = 1; j < 3; j++) {
            if (arr[i][j] < mininrow) {
                mininrow = arr[i][j];
                temp = j;
                g = i;
            }
        }

        maxfound = true;
        for (k = 0; k < 3; k++) {
            if (arr[k][temp] > mininrow) {
                maxfound = false;
                break;
            }
        }

        if (maxfound) {
            l = temp;
            printf("\nSaddle Point = %d @ arr[%d][%d]\n", mininrow, g, l);
            return 0;
        }
    }

    printf("\nNo Saddle Point found in the matrix.\n");
    return 0;
}
