#include <string.h>
#include <stdio.h>

void main(int argc, char *argv[]) {
  char buffer[512];

  printf("PATH address = %#x\n", getenv("PATH"));
  printf("EGG address = %#x\n", getenv("EGG"));

  if (argc > 1)
    strcpy(buffer,argv[1]);
}
