#include <stdio.h>

char shellcode[] = 
  "\xeb\x14"         
  "\x5e"            
  "\xba\x00\x00\x00\x00"
  "\xb9\x00\x00\x00\x00"
  "\x89\xf3"
  "\xb8\x0b\x00\x00\x00"
  "\xcd\x80"
  "\xe8\xe7\xff\xff\xff"
  "/bin/sh"
  ;

void call_asm(){
  asm(
      "jmp _call_label \n"
      "_jmp_label: \n"
      "pop %esi \n"
      "mov $0x0,%edx \n"
      "mov $0x0,%ecx \n"
      "mov %esi,%ebx \n"
      "mov $0xb,%eax \n"
      "int $0x80 \n"
      "_call_label: \n"
      "call _jmp_label \n"
      ".string \"/bin/sh\" \n"
      );
}

void call_func() {

  execve("/bin/sh",0,0);
}

int main(void) {
  //call_func();

  //call_asm();

  (*(void(*)()) shellcode)();

  printf("shellcode fail!\n");

  return 0;
}
