CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++11
TARGET = autocomplete

SRC = main.cpp autocomplete.cpp
HEADERS = Autocomplete.h Termo.h

OBJ = $(SRC:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)

