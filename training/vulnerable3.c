#include <stdio.h>
#include <string.h>

void overflow(char* source) {
  char buffer[12];

  printf("Copying %d bytes to buffer...\n",strlen(source));
  
  strcpy(buffer,source);
}

int main(int argc, char *argv[]) {
  if (argc > 1)
    overflow(argv[1]);

  printf("Exploit fail, better luck next time...\n");

  return 0;
}
