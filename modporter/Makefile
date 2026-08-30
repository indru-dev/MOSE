CC = g++
MAKEFILE_VERSION = 1

TARGET = modporter
SOURCE = src/*
HEADER = h

CCFLAGS = -Wall

bin/$(TARGET): $(SOURCE) $(HEADER)
	$(CC) $(CCFLAGS) -o $@ $< -I$(HEADER)

clean:
	del /q /f bin/modporter.exe