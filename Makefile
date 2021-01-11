# c++11
hello_world_var : hello_world_var.o
	clang++ -o hello_world_var hello_world_var.o -std=c++11

hello_world_var.o : test/hello_world.cpp
	clang++ -c -o hello_world_var.o test/hello_world_var.cpp -std=c++11

clean:
	rm *.o hello_world_var 
