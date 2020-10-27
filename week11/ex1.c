#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


#define max_len 100;

void gen_random(char *s, const int len) {
    static const char alphanum[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

    for (int i = 0; i < len; ++i) {
        s[i] = alphanum[rand() % (sizeof(alphanum) - 1)];
    }

    s[len] = 0;
}

int main() {
    // Create and open fiel ex1.txt
    FILE *ex1;
    ex1 = fopen("ex1.txt", "w+");
    if (ex1 == NULL) {
        printf("Error opening file");
        exit(1);
    }

    // Choose length of string randomly
    srand(time(0));
    int rand_len = -1;
    while (rand_len <= 0){
        rand_len = rand() % max_len;
    }

    // Create random string
    char *rand_string = malloc(rand_len*sizeof(char ));
    gen_random(rand_string, rand_len);

    // Write it to the ex1.txt
    fprintf(ex1, "%s", rand_string);
    fclose(ex1);
    
    struct stat buf;
    int file = open("ex1.txt", O_RDWR);
    
    char *str = "This is a nice day\n";
    ftruncate(file, strlen(str));
    char *adr = mmap(NULL, strlen(str), PROT_WRITE, MAP_SHARED, file, 0);
    strncpy(adr, str, strlen(str));
    munmap(adr, strlen(str));
    
    close(file);
    
}
