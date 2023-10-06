CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -g3

SRC = ClapTrap.cpp ScavTrap.cpp FragTrap.cpp DiamondTrap.cpp main.cpp
OBJ = $(patsubst %.cpp, $(OBJ_DIR)/%.o, $(SRC))
DEPS = ClapTrap.hpp ScavTrap.hpp FragTrap.hpp DiamondTrap.hpp
OBJ_DIR = obj
EXE = ex03

all: $(EXE)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: %.cpp $(DEPS) | $(OBJ_DIR)
	c++ $(CFLAGS) -c -o $@ $<

$(EXE): $(OBJ)
	c++ $(CFLAGS) -o $(EXE) $(OBJ)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(EXE)

re: fclean
	make all