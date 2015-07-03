OBJS_USER = Source/main.cpp

#OBJS specifies which files to compile as part of the project 
OBJS_BASE = Source/engine/Base/Base.cpp \
			Source/engine/Base/EventHandler.cpp \
			Source/engine/Base/Wizard.cpp \
			Source/engine/ObjVariables/Sprite.cpp
#CC specifies which compiler we're using 
CC = g++ 
#Game name
NAME = first
#COMPILER_FLAGS specifies the additional compilation options we're using 
# -w suppresses all warnings 
COMPILER_FLAGS = -w -std=c++11
#LINKER_FLAGS specifies the libraries we're linking against 
LINKER_FLAGS = 	-lSDL2 \
				-lSDL2_image \
				-lSDL2_ttf \
				-lGL
#OBJ_NAME specifies the name of our exectuable 
OBJ_NAME = bin/$(NAME)
#This is the target that compiles our executable
all : $(OBJS) 
		$(CC) $(OBJS_USER) $(OBJS_BASE) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)
