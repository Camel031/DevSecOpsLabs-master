# Enable debugging and suppress pesky warnings
# CFLAGS ?= -g -w -fsanitize=address
all:    vulnerable

vulnerable: vulnerable.c
        ${CC} ${CFLAGS} vulnerable.c -o vulnerable

clean:
        rm -f vulnerable