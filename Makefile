# c++11
test : test.o
	clang++ -o test test.o -std=c++11

test.o : test/hello_world.cpp
	clang++ -c -o test.o test/hello_world_var.cpp -std=c++11

clean:
	rm *.o test
