char shell[] = "/bin/sh";

int main(void) {

  __asm__(
      "xor %rdx,%rdx \n"
      "xor %rsi,%rsi \n"
      "lea shell,%rdi \n"
      "mov $0x3b,%rax \n"
      "syscall \n"
      );

  return 0;
}
