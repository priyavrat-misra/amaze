# -*- MakeFile -*-

CXX=g++
INC_DIR=include
SRC_DIR=src
OBJ_DIR=build
OPT=-O2
CXXFLAGS=-c -Wall -Wextra -I$(INC_DIR) $(OPT) -o $@
LIBS=-lsfml-system -lsfml-window -lsfml-graphics
TARGET=amaze

all: $(OBJ_DIR) $(TARGET)

$(OBJ_DIR):
	@mkdir -p $@

$(TARGET): $(OBJ_DIR)/main.o $(OBJ_DIR)/Maze.o $(OBJ_DIR)/Game.o
	$(CXX) $^ -o $@ $(LIBS)
	@strip --strip-unneeded $(TARGET)

$(OBJ_DIR)/main.o: $(SRC_DIR)/main.cpp $(INC_DIR)/Game.hpp
	$(CXX) $(CXXFLAGS) $(SRC_DIR)/main.cpp

$(OBJ_DIR)/Maze.o: $(SRC_DIR)/Maze.cpp $(INC_DIR)/Maze.hpp $(INC_DIR)/Game.hpp $(INC_DIR)/Direction.hpp
	$(CXX) $(CXXFLAGS) $(SRC_DIR)/Maze.cpp

$(OBJ_DIR)/Game.o: $(SRC_DIR)/Game.cpp $(INC_DIR)/Game.hpp $(INC_DIR)/Maze.hpp $(INC_DIR)/Direction.hpp
	$(CXX) $(CXXFLAGS) $(SRC_DIR)/Game.cpp

clean:
	rm -rf $(OBJ_DIR) $(TARGET)

remake: clean all
