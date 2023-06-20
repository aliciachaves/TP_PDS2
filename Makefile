CC = g++
CFLAGS = -std=c++11 -Wall
TARGET = main.exe

BUILD = ./build
SRC = ./src
INCLUDE = ./include

${TARGET}: ${BUILD}/normalize.o ${BUILD}/readfile.o ${BUILD}/main.o
	${CC} ${CFLAGS} -o ${TARGET} ${BUILD}/*.o

${BUILD}/normalize.o: ${INCLUDE}/normalize.hpp ${SRC}/normalize.cpp
	${CC} ${CFLAGS} -I ${INCLUDE}/ -c ${SRC}/normalize.cpp -o ${BUILD}/normalize.o

${BUILD}/readfile.o: ${INCLUDE}/readfile.hpp ${INCLUDE}/normalize.hpp ${SRC}/readfile.cpp
	${CC} ${CFLAGS} -I ${INCLUDE}/ -c ${SRC}/readfile.cpp -o ${BUILD}/readfile.o

${BUILD}/main.o: ${INCLUDE}/normalize.hpp ${INCLUDE}/readfile.hpp ${SRC}/main.cpp
	${CC} ${CFLAGS} -I ${INCLUDE}/ -c ${SRC}/main.cpp -o ${BUILD}/main.o

run:
	clear
	./${TARGET}

clean:
	rm -f ${BUILD}/*
	rm -f ${TARGET}