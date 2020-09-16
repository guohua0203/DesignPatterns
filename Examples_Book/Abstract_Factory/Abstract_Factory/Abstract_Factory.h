#pragma once

#include "Maze_Game_Common.h"

class EnchantedRoom : public Room {
public:
	EnchantedRoom(int n) : Room(n) {
		// implementation;
	}
};

class RoomWithABomb : public Room {
public:
	RoomWithABomb(int n) : Room(n){
		// implmentation;
	}
};

class DoorNeedingSpell : public Door {
public:
	DoorNeedingSpell(Room* r1, Room* r2) {
		// implmentation;
	}
};

class BombedWall : public Wall {
public:
	BombedWall() {
		// implementation;
	}
};