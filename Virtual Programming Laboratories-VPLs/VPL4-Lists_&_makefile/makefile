# Variables
CXX = g++
CXXFLAGS = -std=c++11 -Wall -Iinclude

# Directories
SRCDIR = src
BUILDDIR = build

# Final target
TARGET = vpl_execution

# Create a list of .o objects
OBJECTS = $(BUILDDIR)/list.o $(BUILDDIR)/main.o

all: $(TARGET)

# Steps to create the executable
$(TARGET): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $(TARGET)

# Steps to compile each .cpp into .o
$(BUILDDIR)/list.o: $(SRCDIR)/list.cpp include/list.hpp include/node.hpp
	$(CXX) $(CXXFLAGS) -c $(SRCDIR)/list.cpp -o $(BUILDDIR)/list.o

$(BUILDDIR)/main.o: $(SRCDIR)/main.cpp include/list.hpp
	$(CXX) $(CXXFLAGS) -c $(SRCDIR)/main.cpp -o $(BUILDDIR)/main.o

# Clean up binary files
clean:
	rm -f $(BUILDDIR)/*.o $(TARGET)

# Avoid redundancies between files and commands
.PHONY: all clean