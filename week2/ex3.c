#include <stdio.h>

int main() {
    // Height of a tree
    int n;
    scanf("%d", &n);

    // Loop to draw a tree
    for (int i = 1; i < n + 1; i++){
        int k;
        // print spaces on left side
        for (k = 0; k < n - i; k++){
            printf("%c", ' ');
        }

        // print stars
        for (k = 0; k < 2 * i - 1; k++){
            printf("%c", '*');
        }

        // print spaces on right side
        for (k = 0; k < n - i; k++){
            printf("%c", ' ');
        }

        // move to next line
        printf("\n");
    }
}
