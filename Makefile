all: $(patsubst %.c, %, $(wildcard *.c))

%: %.c
	gcc -pthread -Wall -Wextra -ggdb $< -o $@

clean: $(patsubst %.c, %, $(wildcard *.c))
	rm $^

.PHONY: 
	all 
	clean
