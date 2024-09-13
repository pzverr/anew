.PHONY: all clean test

CXX=g++
CXXFLAGS=-O3 -static -Werror -std=c++17

SRC_PATH=$(PWD)/src
INCLUDE_PATH=$(PWD)/includes
BUILD_PATH=$(PWD)/build

EXECUTABLE=anew

SOURCES=$(SRC_PATH)/main.cpp $(SRC_PATH)/argparse.cpp

OBJECTS=$(BUILD_PATH)/main.o $(BUILD_PATH)/argparse.o

$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(FLAGS) $(OBJECTS) -o $(BUILD_PATH)/$(EXECUTABLE)

$(BUILD_PATH)/%.o: $(SRC_PATH)/%.cpp
	$(CXX) -c $< -o $@ -I$(INCLUDE_PATH)

clean:
	rm $(BUILD_PATH)/*.o $(BUILD_PATH)/$(EXECUTABLE)
