int main(void) {

  __asm__(
      "jmp l_call \n"
      "l_jmp: \n"
      "xor %rdx,%rdx \n"
      "xor %rsi,%rsi \n"
      "pop %rdi \n"
      "mov $0x3b,%rax \n"
      "syscall \n"
      "xor %rdi,%rdi \n"
      "mov $0x3c,%rax \n"
      "syscall \n"
      "l_call: \n"
      "call l_jmp \n"
      ".string \"/bin/sh\" \n"
      );
}
