CC = gcc
OUT = ncurses.o
CFLAG = -lncurses
OBJECTS = $(shell find . -name "*.c")
HEADERS = $(shell find . -name "*.h")

all: $(OUT)

$(OUT): clean
	$(CC) $(OBJECTS) $(HEADERS) -o $@ $(CFLAG)

clean:
	-rm -f $(OUT)

