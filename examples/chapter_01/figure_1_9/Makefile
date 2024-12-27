CC=gcc
CFLAGS=-Wall -Wextra -Werror -Wpedantic -std=c2x
TARGET = ../../../bin/examples/chapter_01/figure_1_9
OBJS = error.o figure_1.9.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

error.o: error.c apue.h
	$(CC) $(CFLAGS) -c error.c

figure_1.9.o: figure_1.9.c apue.h
	$(CC) $(CFLAGS) -c figure_1.9.c

clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all clean
