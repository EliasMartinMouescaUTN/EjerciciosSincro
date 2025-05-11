all: $(patsubst %.c, %, $(wildcard *.c))

%: %.c
	gcc -pthread -Wall -Wextra -ggdb $< -o $@

# Works only on *nix
clean:
	rm -f $(patsubst %.c, %, $(wildcard *.c))

.PHONY: all clean
