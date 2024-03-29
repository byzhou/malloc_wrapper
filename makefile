target	= mem
sofile	= libmalloc.so  libmemsettime.so  libnoinit.so  libmalloctime.so

all: $(target)

%.so: %.c
	gcc -shared -fPIC $< -o $@ -ldl

mem: $(sofile) mem.cc
	gcc mem.cc -o mem

.PHONY: debug
debug:
	gcc mem.cc -pg -o mem

clean:
	rm -rf libmalloc.so mem	
