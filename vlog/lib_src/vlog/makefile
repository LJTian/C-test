
all: vlog.c vlog.h
	gcc -fPIC -shared -o libvlog.so vlog.c
test: vlog.c vlog.h
	gcc  vlog.c
clean:
	rm -rf libvlog.so
