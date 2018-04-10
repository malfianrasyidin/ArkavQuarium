# Masukkan semua file cpp Anda
OBJS = FishFoodDriver.cpp ../../oop.cpp ../*.cpp

CC = g++
COMPILER_FLAGS = -std=c++11 -Wall -O2
LINKER_FLAGS = -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer
OBJ_NAME = main
all : $(OBJS)
	$(CC) $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)
