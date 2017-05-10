#define _GNU_SOURCE
#include <dlfcn.h>

int rand(){
	int (*libc_rand)() = (int (*)())dlsym(RTLD_NEXT, "rand");
	
    return libc_rand(); //the most random number in the universe
}
