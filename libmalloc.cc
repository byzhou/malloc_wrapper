//#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <dlfcn.h>

#include <time.h>

void* __gxx_personality_v0;
static void* __boyou_calloc_ptr = NULL;
static size_t __boyou_calloc_size = 0;

extern "C" void* __boyou_calloc(size_t num, size_t sz){
	// time measuring
	struct timespec tstart = {0, 0}, tend = {0, 0};


	// functional pointer to calloc
	void* (*libc_calloc)(size_t, size_t) =  (void* (*)(size_t, size_t))dlsym(RTLD_NEXT, "calloc");

	// calloc instead of malloc
	clock_gettime(CLOCK_MONOTONIC, &tstart);	
	void* ptr 		= libc_calloc(num, sz);
	clock_gettime(CLOCK_MONOTONIC, &tend);	
	double timespan	= (double)tend.tv_sec + 1.0e-9 * tend.tv_nsec -
					(double)tstart.tv_sec - 1.0e-9 * tstart.tv_nsec;
	fprintf(stderr, "[CALLOC] Time %.9f block size %lu\n", timespan, sz);

    //fprintf(stderr, "[MALLOC] Calloc ptr value is %p.\n", __calloc_ptr);
    return ptr;
}

extern "C" void* malloc(size_t sz) {	
    return __boyou_calloc(1, sz);
}

extern "C" void* calloc(size_t num, size_t sz) {	
    return __boyou_calloc(num, sz);
}


extern "C" void free(void *p) {
    //fprintf(stderr, "[FREE]   Memory at %p has been freed.\n", p);
	void* (*libc_free)(void*)	= (void* (*)(void*))dlsym(RTLD_NEXT, "free");
    libc_free(p);
}

extern "C" void* memset(void* ptr, int num, size_t size) {

	void* (*libc_memset)(void*, int, size_t)	= (void* (*)(void*, int, size_t))dlsym(RTLD_NEXT, "memset");

	//fprintf(stderr, "[MEMSET] __calloc_ptr value is %p.\n", __calloc_ptr);
	if ((ptr == __boyou_calloc_ptr) && (num == 0) && (size == __boyou_calloc_size)){
		// calloc has initialized for malloc
		//fprintf(stderr, "[MEMSET] Memset the same location where the previous calloc happens. %p\n", ptr);
		__boyou_calloc_ptr = NULL;
		__boyou_calloc_size = 42;
		return ptr;
	} else {
		// memset has nothing to with malloc
		//fprintf(stderr, "[MEMSET] Memset happened without initializing previous calloc. %p\n", ptr);
		__boyou_calloc_ptr = NULL;
		__boyou_calloc_size = 42;
		return libc_memset(ptr, num, size);
	}

}
