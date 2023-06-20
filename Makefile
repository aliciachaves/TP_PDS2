CC = g++
CFLAGS = -std=c++11 -Wall
TARGET = vpl_execution

BUILD = ./build
SRC = ./src
INCLUDE = ./include

${TARGET}: ${BUILD}/Funcionario.o ${BUILD}/Pessoa.o ${BUILD}/Professor.o ${BUILD}/main.o
	${CC} ${CFLAGS} -o ${TARGET} ${BUILD}/*.o

${BUILD}/Funcionario.o: ${INCLUDE}/Funcionario.hpp ${SRC}/entidades/Funcionario.cpp
	${CC} ${CFLAGS} -I ${INCLUDE}/ -c ${SRC}/entidades/Funcionario.cpp -o ${BUILD}/Funcionario.o

${BUILD}/Pessoa.o: ${INCLUDE}/Pessoa.hpp ${SRC}/entidades/Pessoa.cpp
	${CC} ${CFLAGS} -I ${INCLUDE}/ -c ${SRC}/entidades/Pessoa.cpp -o ${BUILD}/Pessoa.o

${BUILD}/Professor.o: ${INCLUDE}/Professor.hpp ${SRC}/entidades/Professor.cpp
	${CC} ${CFLAGS} -I ${INCLUDE}/ -c ${SRC}/entidades/Professor.cpp -o ${BUILD}/Professor.o

${BUILD}/main.o: ${INCLUDE}/Funcionario.hpp ${INCLUDE}/Pessoa.hpp ${INCLUDE}/Professor.hpp ${SRC}/main.cpp
	${CC} ${CFLAGS} -I ${INCLUDE}/ -c ${SRC}/main.cpp -o ${BUILD}/main.o

run:
	clear
	./${TARGET}

clean:
	rm -f ${BUILD}/*
	rm -f ${TARGET}