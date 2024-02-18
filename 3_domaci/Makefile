BIN		= out
CXXC		= g++
CXXFLAGS 	= -pedantic -Wall -std=c++20
LDFLAGS		=

SRC = $(wildcard *.cpp)
OBJ = $(SRC:.cpp=.o)

all: ${BIN}

%.o: %.cpp Makefile
	${CXXC} ${CXXFLAGS} -c $<

${BIN}: ${OBJ} Makefile
	${CXXC} -o $@ ${OBJ} ${LDFLAGS}

clean:
	rm ${BIN} ${OBJ} 2> /dev/null

run: ${BIN}
	./${BIN}

.PHONY: clean all run