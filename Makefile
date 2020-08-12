.PHONY: test

%_test: %_test.cpp %.hpp
	$(CXX) $< -o $@ -std=c++17 -Wall -Wextra -Werror


test: functional_test
	./functional_test
