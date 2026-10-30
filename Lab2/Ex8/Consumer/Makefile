KDIR ?= $(HOME)/linux-5.15.163
obj-m += consumer.o
PWD := $(shell pwd)
KBUILD_EXTRA_SYMBOLS := /home/asus/ThucHanh/Lab2/Ex8/Provider/Module.symvers
all:
	$(MAKE) -C $(KDIR) M=$(PWD) modules
clean:
	$(MAKE) -C $(KDIR) M=$(PWD) clean
.PHONY: all clean