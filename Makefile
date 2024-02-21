CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -Werror -Iheader
LDFLAGS = -Llib/ -framework CoreVideo -framework IOKit -framework Cocoa -framework GLUT -framework OpenGL
LIBS = lib/libraylib.a
SOURCE_FILES = *.cpp header/*.cpp  # Adjust the paths based on your project structure
OUTPUT = tetris

all: $(OUTPUT)

$(OUTPUT): $(SOURCE_FILES)
	$(CXX) $(CXXFLAGS) $(SOURCE_FILES) $(LDFLAGS) $(LIBS) -o $(OUTPUT)

clean:
	rm -f $(OUTPUT)

.PHONY: all clean
