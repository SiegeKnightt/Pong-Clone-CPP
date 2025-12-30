# Make command for Windows
# $mingw32-make -f .\Makefile
# OR $mingw32-make.exe

# Compiler
CXX = g++

#SDL path
SDL_PATH = C:/sdl3

# Compiler flags
CXXFLAGS = -Wall -g -I$(SDL_PATH)/include -I$(SDL_PATH)/include/SDL3_ttf -I.

# Linker flags
LDFLAGS = -L$(SDL_PATH)/lib -lmingw32 -lSDL3 -mwindows -lSDL3_ttf

# Target executable
TARGET = pong

# For deleting the target
TARGET_DEL = pong.exe

# Source files
SOURCES = main.cpp net.cpp ball.cpp paddle.cpp
  
# Object files
OBJECTS = $(SOURCES:.cpp=.o)

# DLL path
DLL_SRC = C:\sdl3\bin\SDL3.dll

# Default rule to build and run the executable
all: $(TARGET) run

# Rule to link object files into the target executable
$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJECTS) $(LDFLAGS)

# Rule to compile .cpp files into .o files
%.o: %.cpp net.h ball.h paddle.h vec2.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Rule to run the executable
run: $(TARGET)
	$(TARGET)

# Clean rule to remove generated files
clean:
	del $(TARGET_DEL) $(OBJECTS) SDL3.dll *.o