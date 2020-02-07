#Define variables

CC = g++

CFLAGS = -c -Wall -std=c++17 -I../SFML-2.4.0/include

all: The_spell clean

The_spell: main.o Levels.o Level_core.o Houses.o Entity.o Player.o Enemy.o Menu.o Big_rect.o
	$(CC) -no-pie *o -L../SFML-2.4.0/lib -o The_spell -lsfml-graphics-s -lsfml-window-s -lsfml-system-s

main.o: Main.cpp
	$(CC) $(CFLAGS) Main.cpp

Levels.o: Levels/Levels.cpp
	$(CC) $(CFLAGS) Levels/Levels.cpp

Level_core.o: Level_core/Level_core.cpp
	$(CC) $(CFLAGS) Level_core/Level_core.cpp

Houses.o: Houses/House.cpp
	$(CC) $(CFLAGS) Houses/House.cpp

Entity.o: Entity/Entity.cpp
	$(CC) $(CFLAGS) Entity/Entity.cpp

Player.o: Player/Player.cpp
	$(CC) $(CFLAGS) Player/Player.cpp

Enemy.o: Enemy/Enemy.cpp
	$(CC) $(CFLAGS) Enemy/Enemy.cpp

Menu.o: Game_window/Menu.cpp
	$(CC) $(CFLAGS) Game_window/Menu.cpp

Big_rect.o: Big_rect/Big_rect.cpp
	$(CC) $(CFLAGS) Big_rect/Big_rect.cpp

clean:
	rm -rf *o
