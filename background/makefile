CC = gcc
CFLAGS = -g
LIBS = -lSDL -lSDL_image -lSDL_ttf -lSDL_mixer

OBJS = background.o main.o
TARGET = prog

.PHONY: all clean

all: $(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@ $(LIBS)
