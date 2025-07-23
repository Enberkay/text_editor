# Makefile
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -Iinclude

SRC = src/main.cpp src/Editor.cpp
OBJ = $(SRC:.cpp=.o)
EXEC = editor

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CXX) $(OBJ) -o $@

clean:
	rm -f $(OBJ) $(EXEC)
