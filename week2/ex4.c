#include <stdio.h>

void Swap(int *x, int *y){
    int t = *x;
    *x = *y;
    *y = t;
}

int main() {
    printf("%s \n", "Please enter two integers:");
    int a, b;
    scanf("%d \n %d", &a, &b);
    //scanf("%d", &b);

    printf("%s \n", "Now they will be swapped:");
    Swap(&a, &b);
    printf("%d %d", a, b);
}