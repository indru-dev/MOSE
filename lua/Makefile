CXX = g++
CXXFLAGS = -Wall -Wextra
HEADER = -Isrc/h
SOURCE = src/*.cpp
TARGET = sol
LIBS = -llua

all: $(TARGET)

$(TARGET): $(SOURCE) $(HEADER)
	$(CXX) $(CXXFLAGS) -o $@ $(SOURCE) $(HEADER) $(LIBS)

clean:
	del /Q /F sol.exe
