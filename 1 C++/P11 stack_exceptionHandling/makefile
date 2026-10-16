# Makefile für Stack mit Exception-Handling
# C++11 Standard verwenden

# Compiler und Flags
CXX = c++
CXXFLAGS = -std=c++11 -Wall -g

# Zieldatei
TARGET = main
SOURCES = main.cpp
HEADERS = stack_new.h stack_exception.h

# Standard-Ziel
$(TARGET): $(SOURCES) $(HEADERS)
	$(CXX) $(CXXFLAGS) $(SOURCES) -o $(TARGET)

# Alle Dateien kompilieren
all: $(TARGET)

# Aufräumen
clean:
	rm -f $(TARGET)

# Ausführen nach Kompilierung
run: $(TARGET)
	./$(TARGET)

# Phony targets (keine echten Dateien)
.PHONY: all clean run