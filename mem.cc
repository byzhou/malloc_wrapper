#include <stdlib.h>
#include <stdio.h>
#include <string.h>


int main(void) {
	
	for (int i = 0; i < 10; i ++) {
		// printf ("[CALLOC] Calloc in next line.\n");
		calloc(1, 8);
		// printf ("[MALLOC] Malloc in next line.\n");
		void* ptr= malloc(8);
		// printf ("[MEMSET] Memset in next line.\n");
		memset(ptr, 0, 8);
		// printf ("[MEMSET] Illrelavent memset in next line.\n");
		memset((char*)ptr + 1, 0, 8);
	}
   	return 0;
}
