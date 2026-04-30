CC      = gcc
CFLAGS  = -Wall -Wextra -g
TARGET  = myshell
SRC     = shell.c parser.c executor.c builtins.c redirect.c signals.c

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC)

clean:
	rm -f $(TARGET)
