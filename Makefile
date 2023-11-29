TARGET      = sand-simulator


CXX         = c++
CXXFLAGS    = -Wall -Wextra -Werror -I./lib/sfml/2.6.1/include -std=c++11

LDFLAGS     = -L./lib/sfml/2.6.1/lib -lsfml-window -lsfml-graphics -lsfml-system -Wl,-rpath,./lib/sfml/2.6.1/lib

SRC_DIR     = ./src
SSIM_DIR		=	$(SRC_DIR)/ssim

CLANGD_GEN  = ./clangd_gen.sh

SRC_FILES		=	$(SRC_DIR)/main.cpp           \
							$(SRC_DIR)/World.cpp					\
							$(SRC_DIR)/SandWand.cpp				\
							$(SRC_DIR)/WaterWand.cpp


OBJ_FILES   = $(SRC_FILES:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)


HEADER      = 

PCH					=	$(SSIM_DIR)/common.hpp.gch
PCH_SRC			=	$(SSIM_DIR)/common.hpp


all : $(TARGET)


$(TARGET) : $(OBJ_FILES)
	$(CXX) $(LDFLAGS) $^ -o $@

$(PCH) : $(PCH_SRC)
	$(CXX) $(CXXFLAGS) -x c++-header -o $@ $<

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.cpp $(HEADER)
	mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -include $(PCH_SRC) -c $< -o $@

clean :
	rm -rf $(OBJ_DIR) $(TARGET) $(PCH)

clangd :
	/bin/bash $(CLANGD_GEN)

.PHONY: all clean