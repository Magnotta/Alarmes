all: alarmes

main.o: ../src/main.cpp
	g++ -c ../src/main.cpp

funct.o: ../include/funct.cpp
	g++ -c ../include/funct.cpp

classes.o: ../include/classes.cpp
	g++ -c ../include/classes.cpp

alarmes: main.o classes.o funct.o
	g++ main.o classes.o funct.o -o alarmes -Wall

clean:
	rm -rf *.o alarmes