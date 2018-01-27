CXX = g++
CXXFLAGS = -std=c++14 -O3 -Wall -Wextra -pedantic -Werror=vla -MMD
EXEC = main
OBJECTS = main.o ShellTable.o MetaRow.o Integer.o String.o Utils.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
