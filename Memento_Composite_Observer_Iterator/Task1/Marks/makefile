marks:
	g++ -c -g *.cpp
	g++ -o Marks *.o

run: marks
	./marks

clean:
	rm *.o marks

val:
	valgrind --leak-check=full ./marks