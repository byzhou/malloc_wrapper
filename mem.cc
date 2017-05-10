#include <stdlib.h>
#include <stdio.h>
#include <string.h>


int main(void) {
	
	for (int i = 0; i < 10; i ++) {
		free(calloc(0, 10));
	}
	// int* ptr;
	// ptr=(int*)malloc(4);
	// memset(ptr + 1, 0, 4);
	// free(ptr);
   	return 0;
}
