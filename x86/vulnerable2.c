#include <stdio.h>
#include <string.h>

char* my_value = "Target Aquired!";
int my_value2;
unsigned int ret_addr;
unsigned int* stack_addr;

void func(char** argv){
  int  pad = 0xbabe;
  char buf[1024];

  strncpy(buf, argv[1], sizeof(buf) - 1);

  asm("mov 0x4(%%ebp), %0 \n" : "=r"(ret_addr) : : );
  asm("mov %%ebp, %0 \n" : "=r"(stack_addr) : : );
  stack_addr+=1;
  printf("original ret addr  = 0x%x at %p with content 0x%x\n",ret_addr,stack_addr,*stack_addr);

  printf(buf);

  asm("mov 0x4(%%ebp), %0 \n" : "=r"(ret_addr) : : );
  printf("\ncorrupted ret addr = 0x%x\n",ret_addr);
}

void show_map() {
  char cmd[256];
  sprintf(cmd,"cat /proc/%d/maps",(int)getpid());
  system(cmd);
}

int main(int argc, char **argv) {
  // show_map();

  my_value2 = 0x0;

  printf("my_value  addr = %p\n",my_value);
  printf("my_value2 addr = %p\n",&my_value2);

  printf("input data = %s\n",argv[1]);

  func(argv);

  printf("my_value2 = 0x%x\n",my_value2);

  return 0;
}
