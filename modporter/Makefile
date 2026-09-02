CC = g++
MAKEFILE_VERSION = 1

TARGET = ../modporter
SOURCE = src/*
HEADER = h

CCFLAGS = -Wall

$(TARGET): $(SOURCE) $(HEADER)
	$(CC) $(CCFLAGS) -o $@ $(SOURCE) -I$(HEADER)

clean:
	del /q /f .\modporter.exe