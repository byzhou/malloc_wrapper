target	= mem

all: $(target)

%.so: %.c
	gcc -shared -fPIC $< -o $@ -ldl

mem: libmalloc.so  libmemsettime.so  libnoinit.so mem.cc
	gcc mem.cc -o mem

.PHONY: debug
debug:
	gcc mem.cc -pg -o mem

clean:
	rm -rf libmalloc.so mem	
