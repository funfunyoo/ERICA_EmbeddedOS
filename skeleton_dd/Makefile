# SKELETON Device Driver

obj-m += skeleton_dd.o

USER_APP = skeleton_app

all: $(USER_APP)
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules

$(USER_APP): $(USER_APP).c
	$(CC) -o $(USER_APP) $(USER_APP).c

clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean
	rm -f $(USER_APP)
