CC=gcc
CFLAGS=-Wall -Wextra -Werror -Wpedantic -std=c2x
TARGET = ../../../bin/examples/chapter_02/figure_2_16
OBJS = error.o figure_2.16.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

error.o: error.c apue.h
	$(CC) $(CFLAGS) -c error.c

figure_1.10.o: figure_2.16.c apue.h
	$(CC) $(CFLAGS) -c figure_2.16.c

clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all clean
