CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = Contact.cpp PhoneBook.cpp main.cpp
OBJ = $(patsubst %.cpp, %.o, $(SRC))
EXE = phonebook

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