.PHONY: clean

all: polytest

polytest: main.o base.o
	$(CC) $(LDFLAGS) $^ -o $@

%.o: %.c
	$(CC) $(CFLAGS) -Wall -std=gnu99 -c $< -o $@

clean:
	rm -f *.o polytest
