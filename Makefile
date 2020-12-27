hello_world_test : hello_world_test.o
	clang++ -o hello_world_test hello_world_test.o

hello_world_test.o : test/hello_world.cpp
	clang++ -c -o hello_world_test.o test/hello_world.cpp

clean:
	rm *.o hello_world_test
