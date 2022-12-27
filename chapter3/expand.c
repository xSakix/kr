#include <stdio.h>
#include <ctype.h>

#define LIMIT 1000

void expand(char s1[], char s2[]);
void clear(char s[]);

int main() {

  char s2[LIMIT];

  clear(s2);
  expand("a-z", s2);
  printf("%s\n", s2);

  clear(s2);
  expand("a-z0-9", s2);
  printf("%s\n", s2);

  clear(s2);
  expand("A-Za-z0-9", s2);
  printf("%s\n", s2);

  clear(s2);
  expand("-A-Z-a-z-0-9-", s2);
  printf("%s\n", s2);

  return 0;
}

void clear(char s[]) {
  int i;

  for (i = 0; i < LIMIT; i++) {
    s[i] = 0;
  }
}

void expand(char s1[], char s2[]) {
  int i, j, k, start, end;
  char memory[3];
  start = end = -1;
  for (i = 0, j = 0, k = 0; s1[i] != '\0' && i < LIMIT; i++) {
    // printf("%c\n",s1[i]);

    if(k == 0 && !isalnum(s1[i])){
        s2[j++] = s1[i];
        continue;
    }

    memory[k++] = s1[i];
    if (k == 3) {
    //   if (memory[1] == '-' && ((memory[0] >= '0' && memory[2] <= '9') || (memory[0] >= 'a' && memory[2] <= 'z'))) {
      if (memory[1] == '-') {
        start = memory[0];
        end = memory[2];
      }
      
      while (start != -1 && end != -1 && start <= end) {
        s2[j++] = start++;
      }

      k = 0;
      start = end = -1;
    }
  }
}
