ELF		= a.out
BUILDDIR	= build
DUMP            = dump
CXX		= g++
CXXFLAGS 	= -Winvalid-pch -pedantic -Wall -Wextra -Wno-pragmas -std=c++20 -O2
LDFLAGS		=

SRC = $(wildcard *.cpp)
OBJ = $(addprefix ${BUILDDIR}/, $(SRC:.cpp=.o))
DEP = $(wildcard ${BUILDDIR}/*.d)

${ELF}: ${OBJ}
	${CXX} ${LDFLAGS} -o $@ ${OBJ}

${OBJ}: ${BUILDDIR}/%.o: %.cpp Makefile | ${BUILDDIR}
	${CXX} -MMD ${CXXFLAGS} -c $< -o $@

-include ${DEP}

${BUILDDIR}:
	mkdir -p ${BUILDDIR}

clean:
	rm -rf ${BUILDDIR} ${GCH} ${ELF} ${DUMP}

c: clean

run: ${ELF}
	./${ELF}

format:
	astyle -A2 -T $(SRC)
r: run

dump: ${ELF}
	objdump -d -Mintel ${ELF} > ${DUMP}

.PHONY: clean c run r format dump
