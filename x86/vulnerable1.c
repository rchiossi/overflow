//#include <stdlib.h>
//#include <sys/mman.h>
#include <stdio.h>
#include <string.h>

unsigned int aux;

int getSP() {
  asm("mov %esp,%eax");
}

void overflow(char* source) {
  char buffer[512];
  
  printf("Buffer address : 0x%x\n",(unsigned int)buffer);
  printf("Return address : 0x%x\n",*(((unsigned int*)buffer)+128));

  strcpy(buffer,source);

  printf("Overflow       : 0x%x\n",*(((unsigned int*)buffer)+128));
}

void main(int argc, char *argv[]) {
  char buffer[512];
  int sp = getSP();

  //  char *buffer = mmap(NULL, 512, PROT_EXEC | PROT_READ | PROT_WRITE,
  //		      MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);

  printf("current sp = 0x%x\n",sp);

  if (argc > 1)
    overflow(argv[1]);

  printf("Exploit fail, better luck next time...\n");
}
