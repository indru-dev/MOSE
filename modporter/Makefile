CC = g++
MAKEFILE_VERSION = 1

TARGET = ../modporter
SOURCE = src/*
HEADER = src/h/*

WFLAGS = -Wall -Wextra

$(TARGET): $(SOURCE) $(HEADER)
	$(CC) $(WFLAGS) -o $@ $(SOURCE) -I$(HEADER)

clean:
	del /q /f ..\modporter.exe