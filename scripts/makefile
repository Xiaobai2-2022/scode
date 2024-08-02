CXX=g++
CXXFLAGS=-std=c++11 -Wall -g -MMD
EXEC=../bin/app
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