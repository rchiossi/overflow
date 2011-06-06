#include <stdlib.h>

char shell[] = "/bin/sh";

int main(void) {
  execve(shell,NULL,NULL);
}

