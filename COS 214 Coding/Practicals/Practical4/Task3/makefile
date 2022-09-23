main:
	g++ -c -g *.cpp
	g++ -o Main *.o

run: main
	./main

clean:
	rm *.o main

val:
	valgrind --leak-check=full ./main