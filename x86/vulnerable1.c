//#include <stdlib.h>
//#include <sys/mman.h>
#include <stdio.h>
#include <string.h>

unsigned int aux;

unsigned int getEGG() {
  return (unsigned int) getenv("EGG");
}

void overflow(char* source) {
  char buffer[32];
  
  printf("Buffer address : 0x%x\n",(unsigned int)buffer);
  printf("Return address : 0x%x\n",*(((unsigned int*)buffer)+8));

  strcpy(buffer,source);

  printf("Overflow       : 0x%x\n",*(((unsigned int*)buffer)+8));
}

int main(int argc, char *argv[]) {
  char buffer[512];
  int sp = getEGG();

  //  char *buffer = mmap(NULL, 512, PROT_EXEC | PROT_READ | PROT_WRITE,
  //		      MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);

  printf("EGG address = 0x%x\n",sp);

  if (argc > 1)
    overflow(argv[1]);

  printf("Exploit fail, better luck next time...\n");

  return 0;
}
