CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = ClapTrap.cpp main.cpp
OBJ = $(patsubst %.cpp, %.o, $(SRC))
DEPS = ClapTrap.hpp
EXE = ex00

all: $(EXE)

%.o: %.cpp $(DEPS)
	c++ $(CFLAGS) -c -o $@ $<

$(EXE): $(OBJ)
	c++ $(CFLAGS) -o $(EXE) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(EXE)

re: fclean
	make all