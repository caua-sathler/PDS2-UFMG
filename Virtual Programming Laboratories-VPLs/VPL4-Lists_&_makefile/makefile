# Variables
CXX = g++
CXXFLAGS = -std=c++11 -Wall -Iinclude

# Directories
SRCDIR = src
BUILDDIR = build

# Final target file
TARGET = vpl_execution

# List of all .o files
OBJECTS = $(BUILDDIR)/list.o $(BUILDDIR)/main.o

all: $(TARGET)

# Steps to create the target file
$(TARGET): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $(TARGET)

# Steps to compile each .cpp file into .o files
$(BUILDDIR)/list.o: $(SRCDIR)/list.cpp include/list.hpp include/node.hpp
	$(CXX) $(CXXFLAGS) -c $(SRCDIR)/list.cpp -o $(BUILDDIR)/list.o

$(BUILDDIR)/main.o: $(SRCDIR)/main.cpp include/list.hpp
	$(CXX) $(CXXFLAGS) -c $(SRCDIR)/main.cpp -o $(BUILDDIR)/main.o

# Removing all .o files
clean:
	rm -f $(BUILDDIR)/*.o $(TARGET)

# Avoid redundancies between files and commands
.PHONY: all clean