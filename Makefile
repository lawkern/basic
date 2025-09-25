.POSIX:
WARNINGS = -Wall -Wextra -Werror
CFLAGS = -std=c99 $(WARNINGS)
CXXFLAGS = $(WARNINGS)

test:
	mkdir -p build
	$(CC) -o build/basic_math_test basic_math_test.c $(CFLAGS) -lm
	$(CXX) -o build/basic_math_test_cpp basic_math_test.cpp $(CXXFLAGS) -lm

	build/basic_math_test
	build/basic_math_test_cpp

clean:
	rm build/*
