default:
	gcc -Wall binary_tree.c
mem:
	valgrind --tool=memcheck --leak-check=full ./a.out
valgrind: 
	valgrind -v ./a.out
run:
	./a.out
