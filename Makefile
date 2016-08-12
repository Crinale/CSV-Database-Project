#simple make file that creates the database and complies the code
#as well as drops the table with make clean

CC=g++

#database name
CFLAGS= YouAndI 

all: main.o


main.o: main.cpp
	createdb $(CFLAGS)
	$(CC) main.cpp -lpqxx -lpq


clean:
	#dropdb $(CFLAGS)
	rm -rf *.out