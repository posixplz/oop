ELF		= a.out
BUILDDIR	= build
CXX		= g++
CXXFLAGS 	= -Winvalid-pch -pedantic -Wall -Wextra -Wno-pragmas -std=c++20 -g3 -O0
LDFLAGS		=

SRC = $(wildcard *.cpp)
HDR = $(wildcard *.hpp)
#GCH = $(addsuffix .gch, ${HDR})
GCH = matrica.hpp.gch
OBJ = $(addprefix ${BUILDDIR}/, $(SRC:.cpp=.o))
DEP = $(wildcard ${BUILDDIR}/*.d)

${ELF}: ${OBJ}
	${CXX} ${LDFLAGS} -o $@ ${OBJ}

${OBJ}: ${BUILDDIR}/%.o: %.cpp ${GCH} Makefile | ${BUILDDIR}
#${OBJ}: ${BUILDDIR}/%.o: %.cpp Makefile | ${BUILDDIR}
	${CXX} -MMD ${CXXFLAGS} -c $< -o $@

${GCH}: %.gch: % Makefile | ${BUILDDIR}
	${CXX} -MMD ${CXXFLAGS} -c $< -o $@
	mv $<.d ${BUILDDIR}/

-include ${DEP}

${BUILDDIR}:
	mkdir -p ${BUILDDIR}

clean:
	rm -rf ${BUILDDIR} ${GCH} ${ELF}

c: clean

run: ${ELF}
	./${ELF}

r: run

.PHONY: clean c run r
