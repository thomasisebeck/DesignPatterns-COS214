main:
	g++ -c -g *.cpp
	g++ -o main *.o

r: main
	./main

c:
	rm *.o main

u:
	rm *.o main
	g++ -c -g *.cpp
	g++ -o main *.o
	./main

val:
	valgrind --leak-check=full ./main
