CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = Zombie.cpp zombieHorde.cpp main.cpp
OBJ = $(patsubst %.cpp, %.o, $(SRC))
EXE = zombies

all: $(EXE)

%.o: %.cpp
	c++ $(CFLAGS) -c -o $@ $^

$(EXE): $(OBJ)
	c++ $(CFLAGS) -o $(EXE) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(EXE)

re: fclean
	make all