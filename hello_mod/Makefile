# Hello Module Makefile

obj-m := hello_mod1.o

all:
	make -C /lib/modules/$(shell uname -r)/build/ M=$(shell pwd) modules
clean:
	make -C /lib/modules/$(shell uname -r)/build/ M=$(shell pwd) clean
