ELF		= a.out
BUILDDIR	= build
CXX		= g++
CXXFLAGS 	= -pedantic -Wall -Wextra -std=c++20 -g3 -O0
LDFLAGS		=

SRC = $(wildcard *.cpp)
OBJ = $(addprefix ${BUILDDIR}/,$(SRC:.cpp=.o))
DEP = $(OBJ:.o=.d)

${ELF}: ${OBJ}
	${CXX} ${LDFLAGS} -o $@ ${OBJ}

${OBJ}: ${BUILDDIR}/%.o: %.cpp Makefile | ${BUILDDIR}
	${CXX} -MMD ${CXXFLAGS} -c $< -o $@

-include ${DEP}

${BUILDDIR}:
	mkdir -p ${BUILDDIR}

clean:
	rm -rf ${BUILDDIR} ${ELF}

c: clean

run: ${ELF}
	./${ELF}

r: run

.PHONY: clean c run r
