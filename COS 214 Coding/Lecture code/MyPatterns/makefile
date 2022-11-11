main:
	g++ -c -g HouseBuilder.cpp
	g++ -o HouseBuilder HouseBuilder.o

r: main
	./HouseBuilder

c:
	rm HouseBuilder.o HouseBuilder

u:
	rm HouseBuilder.o HouseBuilder
	g++ -c -g HouseBuilder.cpp
	g++ -o HouseBuilder HouseBuilder.o
	./HouseBuilder

val:
	valgrind --leak-check=full ./HouseBuilder
