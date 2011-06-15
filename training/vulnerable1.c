#include <stdio.h>
#include <string.h>

void overflow(char* source) {
  char buffer[1024];
  
  printf("Copying %d bytes to buffer in the address %p\n",strlen(source),buffer);
  
  strcpy(buffer,source);
}

int main(int argc, char *argv[]) {
  if (argc > 1)
    overflow(argv[1]);

  printf("Exploit fail, better luck next time...\n");

  return 0;
}
