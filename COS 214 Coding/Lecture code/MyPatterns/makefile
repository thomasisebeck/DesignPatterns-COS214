main:
	g++ -c -g MyVisitor2.cpp
	g++ -o MyVisitor2 MyVisitor2.o

r: main
	./main

c:
	rm MyVisitor2.o MyVisitor2 main

u:
	rm MyVisitor2.o MyVisitor2
	g++ -c -g MyVisitor2.cpp
	g++ -o MyVisitor2 MyVisitor2.o
	./MyVisitor2

val:
	valgrind --leak-check=full ./MyVisitor2
