# Enable debugging and suppress pesky warnings
# CFLAGS ?= -g -w -fsanitize=address
all: vulnerable

vulnerable: vulnerable.c
	${CC} ${CFLAGS} vulnerable.c -g -O0 -o vulnerable

clean:
	rm -f vulnerable