gcc := g++
wall := -Wall
flags := -lSDL2 -lSDL2_image -lSDL2_mixer

src := $(wildcard src/*.cpp)

all: $(src:src/%.cpp=obj/%.o)
	$(gcc) $(wall) obj/*.o -o bin/game $(flags)

obj/%.o: src/%.cpp
	$(gcc) $(wall) -c $< -o $@ -I./inc $(flags)

run:
	bin/game

clean:
	rm -rf obj/*
	rm -rf bin/*