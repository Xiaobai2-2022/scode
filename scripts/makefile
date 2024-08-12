CXX=g++
CXXFLAGS=-std=c++17 -Wall -g -MMD
EXEC=../bin/app
SRCDIR=../src
BINDIR=../bin

# Find all .cpp files recursively in the SRCDIR directory
CCFILES=$(shell find $(SRCDIR) -type f -name '*.cpp')

# Generate the corresponding .o and .d file paths
OBJECTS=$(patsubst $(SRCDIR)/%.cpp,$(BINDIR)/%.o,$(CCFILES))
DEPENDS=$(patsubst $(SRCDIR)/%.cpp,$(BINDIR)/%.d,$(CCFILES))

$(EXEC): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $(EXEC)

-include $(DEPENDS)

.PHONY: clean

clean:
	rm -f $(OBJECTS) $(DEPENDS) $(EXEC)

# Compile .cpp files to .o files
$(BINDIR)/%.o: $(SRCDIR)/%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@ -MMD -MF $(@:.o=.d)
