TARGET      = sand-simulator


CXX         = c++
CXXFLAGS    = -Wall -Wextra -Werror -I./sfml/2.6.1/include -std=c++11

LDFLAGS     = -L./sfml/2.6.1/lib -lsfml-window -lsfml-graphics -lsfml-system -Wl,-rpath,./sfml/2.6.1/lib

SRC_DIR     = ./src
EVENT_DIR   = $(SRC_DIR)/event
LOOP_DIR    = $(SRC_DIR)/loop
OBJ_DIR     = ./obj

CLANGD_GEN  = ./clangd_gen.sh

SRC_FILES		=	$(SRC_DIR)/main.cpp           \
							$(SRC_DIR)/World.cpp					\
							$(SRC_DIR)/SandWand.cpp				\
							$(SRC_DIR)/WaterWand.cpp


OBJ_FILES   = $(SRC_FILES:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)


HEADER      = 


all : $(TARGET)


$(TARGET) : $(OBJ_FILES)
	$(CXX) $(LDFLAGS) $^ -o $@

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.cpp $(HEADER)
	mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean :
	rm -rf $(OBJ_DIR) $(TARGET)

clangd :
	/bin/bash $(CLANGD_GEN)

.PHONY: all clean