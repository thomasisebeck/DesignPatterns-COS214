capture:
	g++ -c -g *.cpp
	g++ -o Capture *.o

run: capture
	./capture

clean:
	rm *.o capture

val:
	valgrind --leak-check=full ./capture