#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char **argv) {
	int  pad = 0xbabe;
	char buf[1024];
	
	strncpy(buf, argv[1], sizeof(buf) - 1);

	printf(buf);

	printf("\n[+] done!\n");
	
	return 0;
}
