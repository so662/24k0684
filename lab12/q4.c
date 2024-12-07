#include<stdio.h>
#include<stdlib.h>

struct book {
    char title[100];
    char author[100];
    int publicationYear;
};

struct library {
    struct book *books;
};

int main() {
    struct library lib;

    lib.books = (struct book *)malloc(5 * sizeof(struct book));

    if (lib.books == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    for (int i = 0; i < 5; i++) {
        printf("Enter Title of book %d: ", i + 1);
        gets(lib.books[i].title);

        printf("Enter author of book %d: ", i + 1);
        gets(lib.books[i].author);

        printf("Enter Publication Year of book %d: ", i + 1);
        scanf("%d", &lib.books[i].publicationYear);
        fflush(stdin);
    }

    printf("\nBooks published after 2000:\n");
    for (int i = 0; i < 5; i++) {
        if (lib.books[i].publicationYear > 2000) {
            printf("----------BOOK %d---------\n\nTitle = %s\n\n",i+1, lib.books[i].title);
        }
    }

    free(lib.books);

    return 0;
}
