KDIR ?= $(HOME)/linux-5.15.163
obj-m += print1_n.o
PWD := $(shell pwd)
all:
	$(MAKE) -C $(KDIR) M=$(PWD) modules
clean:
	$(MAKE) -C $(KDIR) M=$(PWD) clean
.PHONY: all clean