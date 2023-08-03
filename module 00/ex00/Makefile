CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = megaphone.cpp
OBJ = megaphone.o
EXE = megaphone

all: $(EXE)

%.o: %.c
	c++ $(CFLAGS) -C -o $@ $ˆ

$(EXE): $(OBJ)
	c++ $(CFLAGS) -o $(EXE) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(EXE)

re: fclean
	make all