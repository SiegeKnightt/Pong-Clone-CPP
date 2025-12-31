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
SOURCES = main.cpp net.cpp ball.cpp paddle.cpp score.cpp
  
# Object files
OBJECTS = $(SOURCES:.cpp=.o)


DEPLOY_DIR = pong_dist

# Update these paths to where your MinGW bin folder is
MINGW_BIN = C:/Program Files/mingw-w64/x86_64-8.1.0-posix-seh-rt_v6-rev0/mingw64/bin

# Default rule to build and run the executable
all: $(TARGET) run

# Rule to link object files into the target executable
$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJECTS) $(LDFLAGS)

# Rule to compile .cpp files into .o files
%.o: %.cpp net.h ball.h paddle.h vec2.h score.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Rule to run the executable
run: $(TARGET)
	$(TARGET)

# Clean rule to remove generated files
clean:
	del $(TARGET_DEL) $(OBJECTS) SDL3.dll *.o

# Deploy action
deploy: $(TARGET)
	@echo Creating distribution folder...
	if not exist $(DEPLOY_DIR) mkdir $(DEPLOY_DIR)
	
	@echo Copying executable and assets...
	copy $(TARGET).exe $(DEPLOY_DIR)
	copy Minecraft.ttf $(DEPLOY_DIR)
	
	@echo Copying SDL DLLs...
	copy "$(subst /,\,$(SDL_PATH))\bin\SDL3.dll" $(DEPLOY_DIR)
	copy "$(subst /,\,$(SDL_PATH))\bin\SDL3_ttf.dll" $(DEPLOY_DIR)
	
	@echo Copying MinGW dependencies...
	copy "$(subst /,\,$(MINGW_BIN))\libgcc_s_seh-1.dll" $(DEPLOY_DIR)
	copy "$(subst /,\,$(MINGW_BIN))\libstdc++-6.dll" $(DEPLOY_DIR)
	copy "$(subst /,\,$(MINGW_BIN))\libwinpthread-1.dll" $(DEPLOY_DIR)
	
	@echo Done!