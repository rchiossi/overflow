#include <stdio.h>
#include <string.h>

void overflow(char* source,int size) {
  char buffer[128];

  printf("copying %d bytes to buffer...\n",size);
  
  memcpy(buffer,source,size);
}

int main(int argc, char *argv[]) {
  if (argc > 2)
    overflow(argv[1],atoi(argv[2]));

  printf("Exploit fail, better luck next time...\n");

  return 0;
}
