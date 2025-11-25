
CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra

TARGET = lab13
SRC = lab13.cpp

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET)
