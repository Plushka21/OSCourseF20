#include <stdio.h>
#include <string.h>

int main() {
    char line[999999];
    scanf("%s", &line);
    for (int i = strlen(line) - 1; i >= 0; i--){
        printf("%c", line[i]);
    }
}
