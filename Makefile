CXX = g++
CXXFLAGS = -Wall -Wextra
HEADER = -Isrc/h
SOURCE = src/*.cpp
TARGET = modporter
LIBS = -llua

all: $(TARGET)

$(TARGET): $(SOURCE) $(HEADER)
	$(CXX) $(CXXFLAGS) -o $@ $(SOURCE) $(HEADER) $(LIBS)

clean:
del /Q /F $(TARGET).exe
