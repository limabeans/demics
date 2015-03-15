default:
	gcc -Wall stack.c
run:
	./a.out
clean:
	rm -rf a.out
mem:
	make
	valgrind --tool=memcheck --leak-check=full ./a.out
