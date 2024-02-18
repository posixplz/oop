ELF		= a.out
CXX		= g++
CXXFLAGS 	= -pedantic -Wall -Wextra -std=c++20 -g3
LDFLAGS		=

SRC = $(wildcard *.cpp)
OBJ = $(addprefix obj/,$(SRC:.cpp=.o))

${ELF}: ${OBJ} Makefile
	${CXX} ${LDFLAGS} -o $@ ${OBJ}

obj/%.o: %.cpp Makefile
	mkdir -p obj
	${CXX} -c ${CXXFLAGS} $< -o $@

clean:
	rm -rf obj/ ${ELF}

run: ${ELF}
	./${ELF}

r: run

.PHONY: clean run r
