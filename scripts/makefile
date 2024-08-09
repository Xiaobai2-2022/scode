CXX=g++
CXXFLAGS=-std=c++17 -Wall -g -MMD
EXEC=../bin/scode_test
SRCDIR=../src
BINDIR=../bin

CCFILES=$(wildcard $(SRCDIR)/*.cpp)
OBJECTS=$(patsubst $(SRCDIR)/%.cpp,$(BINDIR)/%.o,$(CCFILES))
DEPENDS=$(patsubst $(SRCDIR)/%.cpp,$(BINDIR)/%.d,$(CCFILES))

$(EXEC): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $(EXEC)

-include $(DEPENDS)

.PHONY: clean

clean:
	rm $(OBJECTS) $(DEPENDS) $(EXEC)

$(BINDIR)/%.o: $(SRCDIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@ -MMD -MF $(@:.o=.d)