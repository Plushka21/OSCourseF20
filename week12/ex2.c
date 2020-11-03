#include <stdio.h>
#include <string.h>

void Mytee(FILE* input, char name[100]){
  char str[1024];
  FILE *res = fopen(name, "a");
  while(!feof(input)){
    fgets(str, 1024, input);
    printf("%s", str);
    fprintf(res, "%s", str);
  }
  //printf("%s", "\n");
  //fprintf(res, "%s", "\n");
  fclose(res);
}

int main(void) {
  FILE* input;
  input = fopen("input.txt", "r");
  if (input == NULL){
    printf("Error");
    return 1;
  }
  else{
    Mytee(input, "ex2.txt");
  }
  fclose(input);
}
