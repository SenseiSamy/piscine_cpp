CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = ClapTrap.cpp FragTrap.cpp main.cpp
OBJ = $(patsubst %.cpp, %.o, $(SRC))
DEPS = ClapTrap.hpp FragTrap.hpp
EXE = ex02

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