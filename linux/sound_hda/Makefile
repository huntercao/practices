# SPDX-License-Identifier: GPL-2.0
# Makefile for the Linux sound card driver
#
CUR = $(shell uname -r)
DIR = /lib/modules/$(CUR)/build
PWD = $(shell pwd)
CONFIG_SOUND = m
CONFIG_SND = m

obj-$(CONFIG_SOUND) += soundcore.o
obj-$(CONFIG_SND) += core/ pci/ hda/

soundcore-objs  := sound_core.o

default:
	$(MAKE) -C $(DIR) M=$(PWD) modules

clean:
	$(MAKE) -C $(DIR) M=$(PWD) clean 
	
