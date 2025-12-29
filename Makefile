# Make command for Windows
# $mingw32-make -f .\Makefile

# Compiler
CXX = g++

#SDL path
SDL_PATH = C:/sdl3

# Compiler flags
CXXFLAGS = -Wall -g -I$(SDL_PATH)/include

# Linker flags
LDFLAGS = -L$(SDL_PATH)/lib -lmingw32 -lSDL3 -mwindows

# Target executable
TARGET = pong

# For deleting the target
TARGET_DEL = pong.exe

# Source files
SOURCES = main.cpp
  
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
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Copy the DLL to the project root so that the program can run
copy_dll:
	@if exist $(DLL_SRC) (copy /Y $(DLL_SRC) . >nul) else (echo Warning: SDL3.dll not found!)

# Rule to run the executable
run: $(TARGET)
	$(TARGET)

# Clean rule to remove generated files
clean:
	del $(TARGET_DEL) $(OBJECTSS) SDL3.dll 2>nul