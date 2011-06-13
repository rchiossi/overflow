#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Shellcode to be loaded */
char shellcode[] =
  "\x90"
  ;

int main(int argc, char* argv[]) {
  /* Set the enviroment variable */
  setenv("EXPLOIT",shellcode,1);

  printf("[i] Shellcode set in variable $EXPLOIT\n");
  printf("[i] Type exit when done with this testing session\n");

  system("/bin/bash");
}
