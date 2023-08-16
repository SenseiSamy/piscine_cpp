CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = Zombie.cpp newZombie.cpp randomChump.cpp main.cpp
OBJ = $(patsubst %.cpp, %.o, $(SRC))
EXE = zombies

all: $(OBJ)
	c++ $(CFLAGS) -o $(EXE) $(OBJ)

%.o: %.cpp
	c++ $(CFLAGS) -c -o $@ $^

$(EXE): all

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(EXE)

re: fclean
	make all