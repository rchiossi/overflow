#include <stdio.h>
#include <sys/mman.h>

int main(void) {
  uint8_t *buf = mmap(NULL, 1000, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);

  mprotect(buf, 1000, PROT_EXEC | PROT_READ | PROT_WRITE);

  return 0;
}
