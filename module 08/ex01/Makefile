CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -g3

SRC = main.cpp Span.cpp Ansi.cpp
OBJ = $(patsubst %.cpp, $(OBJ_DIR)/%.o, $(SRC))
DEPS = Span.hpp Ansi.hpp
OBJ_DIR = obj
EXE = ex01

all: $(EXE)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: %.cpp $(DEPS) | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c -o $@ $<

$(EXE): $(OBJ)
	$(CC) $(CFLAGS) -o $(EXE) $(OBJ)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(EXE)

re: fclean
	make all