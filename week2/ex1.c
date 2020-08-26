#include <stdio.h>
#include <limits.h>
#include <float.h>

int main() {
    int a;
    float b;
    double c;
    a = INT_MAX;
    printf("Max int is %d, its size is %d bites \n", a, sizeof(a));
    b = FLT_MAX;
    printf("Max float is %e, its size is %d bites \n", b, sizeof(b));
    c = DBL_MAX;
    printf("Max double is %e, its size is %d bites \n", c, sizeof(c));
}

