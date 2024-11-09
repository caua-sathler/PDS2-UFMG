#Variables 
CC = g++
CCFLAGS = -Wall -g -Iinclude

#Directories
SRC_DIR = src
B_DIR = build

#Target
TARGET = VPL3.exe

#List of all .o files
OBJECTS = $(B_DIR)/Bus.o $(B_DIR)/Company.o $(B_DIR)/main.o

all: $(TARGET)

#Steps to create the .exe target file
$(TARGET): $(OBJECTS)
	$(CC) $(CCFLAGS) $(OBJECTS) -o $(TARGET)

#Steps to create each .o file
$(B_DIR)/Bus.o: $(SRC_DIR)/Bus.cpp include/Bus.hpp 
	$(CC) $(CCFLAGS) -c $(SRC_DIR)/Bus.cpp -o $(B_DIR)/Bus.o

$(B_DIR)/Company.o: $(SRC_DIR)/Company.cpp include/Bus.hpp include/Company.hpp 
	$(CC) $(CCFLAGS) -c $(SRC_DIR)/Company.cpp -o $(B_DIR)/Company.o 

$(B_DIR)/main.o: $(SRC_DIR)/main.cpp include/Bus.hpp include/Company.hpp 
	$(CC) $(CCFLAGS) -c $(SRC_DIR)/main.cpp -o $(B_DIR)/main.o 

# Clean up binary files
clean:
	rm -f $(B_DIR)/*.o $(TARGET)

# Avoid redundancies between files and commands
.PHONY: all clean

