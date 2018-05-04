CFLAGS = -std=c11 -Wall -Wextra -O3 -march=native -flto
EXE = test
OBJS = test.o mr_prime.o

$(EXE): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

test.o: test.c mr_prime.h
	$(CC) $(CFLAGS) -c -o $@ $<

mr_prime.o: mr_prime.c mr_prime.h
	$(CC) $(CFLAGS) -c -o $@ $<

.PHONY: clean
clean:
	$(RM) $(EXE) $(OBJS)
