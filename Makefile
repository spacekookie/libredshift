SHELL        = /bin/sh
CC           = gcc
FLAGS        = -std=c99 -Iinclude
CFLAGS       = -fPIC -Wall -Wextra -march=native -ggdb3
DEBUGFLAGS   = -O0 -D _DEBUG
RELEASEFLAGS = -Ofast -D NDEBUG -combine -fwhole-program

TARGET  = libredshift.so
SOURCES = $(shell echo src/*.c)
HEADERS = $(shell echo include/*.h)
OBJECTS = $(SOURCES:.c=.o)

PREFIX = $(DESTDIR)/usr/local
BINDIR = $(PREFIX)/bin

all: $(TARGET)

$(TARGET): $(OBJECTS)
    $(CC) $(FLAGS) $(CFLAGS) $(DEBUGFLAGS) -o $(TARGET) $(OBJECTS)