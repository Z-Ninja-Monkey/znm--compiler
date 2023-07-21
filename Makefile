CXX = g++
CXXFLAGS = -Wall -Wextra -pedantic -std=c++17
SRCDIR = src
BINDIR = bin
SOURCES = $(wildcard $(SRCDIR)/*.cpp)
OBJECTS = $(patsubst $(SRCDIR)/%.cpp,$(BINDIR)/%.o,$(SOURCES))

all: $(BINDIR)/monkeyc

$(BINDIR)/monkeyc: $(OBJECTS)
	$(CXX) $(CXXFLAGS) $^ -o $@

$(BINDIR)/%.o: $(SRCDIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(BINDIR)/*
