# c++11
ci_test : ci_test.o
	clang++ -o ci_test ci_test.o -std=c++11

ci_test.o : test/hello_world_var.cpp
	clang++ -c -o ci_test.o test/hello_world_var.cpp -std=c++11

clean:
	rm *.o ci_test 
