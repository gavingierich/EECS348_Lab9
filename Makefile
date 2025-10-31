
CXX = g++
CXXFLAGS = -c -Wall -std=c++17

TARGET = lab9

all: $(TARGET)

$(TARGET): 348_Lab9.o
	$(CXX) 348_Lab9.o -o $(TARGET)

348_Lab9.o: 348_Lab9.cpp
	$(CXX) $(CXXFLAGS) 348_Lab9.cpp

clean:
	rm -f *.o $(TARGET)