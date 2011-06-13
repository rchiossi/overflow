#include <stdio.h>

// The binary code of your assembly code goes here
char shellcode[] = 
  "\x90"
  ;

void call_asm(){
  // the assembly code of your function goes here

  asm(
      "nop \n"
      );
}

void call_func() {
  // your function goes here
}

int main(void) {
  call_func();

  //  call_asm();

  // (*(void(*)()) shellcode)();

  printf("shellcode fail!\n");

  return 0;
}
