#include <unistd.h>
#include <stdlib.h>

void shellcode(){
  execve("/bin/sh",NULL,NULL);
}

int main(void){
  shellcode();
  exit(0);
}
