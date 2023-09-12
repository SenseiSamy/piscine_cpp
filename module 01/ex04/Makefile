CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = main.cpp
OBJ = $(patsubst %.cpp, $(OBJ_DIR)/%.o, $(SRC))
DEPS = 
OBJ_DIR = obj
EXE = ex04

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