SRCS := p1a.c p1b.c p2.c p3.c

EXECS := p1a p1b p2 p3

CC := gcc

CFLAGS := -Wall -Wextra

all: $(EXECS)

%: %.c
	$(CC) $(CFLAGS) $< -o $@
clean:
	rm -f $(EXECS)
