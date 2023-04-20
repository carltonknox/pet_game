c_files=$(shell find . -type f \( -iname "*.c" ! -iname "*.mod.c" \))
ko_files=$(c_files:.c=.ko)
o_files=$(programs:=.o)

ifneq ($(KERNELRELEASE),)
	obj-m := kscreensaverlauncher.o
else
	KERNELDIR := $(EC535)/bbb/stock/stock-linux-4.19.82-ti-rt-r33
	PWD := $(shell pwd)
	ARCH := arm
	CROSS := arm-linux-gnueabihf-

default:
	$(MAKE) -C $(KERNELDIR) M=$(PWD) ARCH=$(ARCH) CROSS_COMPILE=$(CROSS) modules
clean:
	$(MAKE) -C $(KERNELDIR) M=$(PWD) ARCH=$(ARCH) clean

endif
