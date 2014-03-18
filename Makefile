# KallistiOS ##version##
#
# adv/Makefile
# Copyright (C)2014 Jonathan Muller
#
TARGET = adv
all: rm-elf $(TARGET).elf

include $(KOS_BASE)/Makefile.rules

OBJS = main.o \
		src/Application.o src/Texture.o src/Vector3.o \
		src/SplashScreen.o src/Menu.o src/FontManager.o src/Text.o

CFLAGS = -Iinclude -Wall
KOS_LOCAL_CFLAGS = -I$(KOS_BASE)/addons/zlib

clean:
	-rm -f $(TARGET).elf $(OBJS)
	-rm -f romdisk_boot.*

dist:
	-rm -f $(OBJS)
	-rm -f romdisk_boot.*
	$(KOS_STRIP) $(TARGET).elf
	
rm-elf:
	-rm -f $(TARGET).elf
	-rm -f romdisk_boot.*

$(TARGET).elf: $(OBJS) romdisk_boot.o 
	kos-c++ -o $(TARGET).elf $^ $(CFLAGS) -lpng -lz -lm -ldcplib $(KOS_LIBS)

romdisk_boot.img:
	$(KOS_GENROMFS) -f $@ -d romdisk_boot -v

romdisk_boot.o: romdisk_boot.img
	$(KOS_BASE)/utils/bin2o/bin2o $< romdisk_boot $@

run: $(TARGET).elf
	$(KOS_LOADER) $<