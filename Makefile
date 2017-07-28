CC=gcc
CFLAGS=-s -lpthread
BINDIR =/usr/bin
TARGET =jews.iso
jews.iso: main.c
		$(CC) main.c -s -lpthread -o jews.iso
install:
		install -D -s $(TARGET) $(BINDIR)/$(TARGET)
uninstall:
		-rm $(BINDIR)/$(TARGET)
