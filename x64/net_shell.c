int main() {
  __asm__(
	  "mov    $0x0,%rdx\n\t"                // arg 3 = NULL
	  "mov    $0x0,%rsi\n\t"                // arg 2 = NULL
"mov    $0x0068732f6e69622f,%rdi\n\t"
	  "push   %rdi\n\t"                     // push "/bin/sh" onto stack
	  "mov    %rsp,%rdi\n\t"                // arg 1 = stack pointer = start of /bin/sh
	  "mov    $0x3b,%rax\n\t"               // syscall number = 59
"syscall\n\t"
	  );
}
