target	= mem

all: $(target)

%.so: %.cc
	gcc -shared -fPIC $< -o $@ -ldl

mem: libmalloc.so mem.cc
	gcc mem.cc -o mem

.PHONY: debug
debug:
	gcc mem.cc -pg -o mem

clean:
	rm -rf libmalloc.so mem	
