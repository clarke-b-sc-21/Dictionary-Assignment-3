dict: dictionary.o main.o
	g++ dictionary.o main.o -o prog

dictionary.o: dictionary.cpp
	g++ -c dictionary.cpp

main.o: main.cpp
	g++ -c main.cpp


clean:
	rm *.o dict


