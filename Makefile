CXX       := g++
CXX_FLAGS := -std=c++17 -ggdb

BIN     := bin
SRC     := src
INCLUDE := include

LIBRARIES   := -L src/lib -l sfml-audio -l sfml-system -l sfml-graphics -l sfml-window
EXECUTABLE  := main

all: $(BIN)/$(EXECUTABLE)

run: clean all
	clear
	./$(BIN)/$(EXECUTABLE)

$(BIN)/$(EXECUTABLE): $(SRC)/*.cpp
	$(CXX) $(CXX_FLAGS) -I$(INCLUDE) $^ -o $@ $(LIBRARIES)

clean:
	-rm $(BIN)/*