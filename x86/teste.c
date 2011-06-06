char shell[] = "/bin/sh";
int main(void) {
  asm(
      "xor %edx,%edx \n"
      "push %edx \n"
      "push %edx \n"
      "lea shell,%ebx \n"
      "push %ebx \n"
      "mov $0xb,%eax \n"
      "push %eax \n"
      "int $0x80 \n"
      );
}
