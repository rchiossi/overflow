#include <stdlib.h>

char shell[] = "/bin/sh";

int main(void) {
  setreuid(1001,1001);  
  execve(shell,NULL,NULL);
}

