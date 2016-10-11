TARGET = lw-streamer
LIBS = -lm
CC = clang
CFLAGS = -g -Wall -std=c11
SRCDIR = src/

.PHONY: default all clean

default: $(TARGET)
all: default

OBJECTS = $(patsubst %.c, %.o, $(wildcard $(SRCDIR)*.c))
HEADERS = $(wildcard $(SRCDIR)*.h)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

.PRECIOUS: $(TARGET) $(OBJECTS)

$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) -Wall $(LIBS) -o $@

clean:
	-rm -f $(SRCDIR)*.o
	-rm -f $(TARGET)
