.POSIX:
CFLAGS = -std=c99 -Wall -Wextra -Werror

test:
	mkdir -p build
	$(CC) -o build/basic_math_test basic_math_test.c $(CFLAGS) -lm

	build/basic_math_test

clean:
	rm build/*
