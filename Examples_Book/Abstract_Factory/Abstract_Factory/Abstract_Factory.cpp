// Abstract_Factory.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "header.h"
#include "Abstract_Factory.h"

class MazeFactory {
public:
	MazeFactory() {
		// implementation;
	}

	virtual Maze* makeMaze() const {
		return new Maze;
	}

	virtual Wall* makeWall() const {
		return new Wall;
	}

	virtual Room* makeRoom(int n) const {
		return new Room(n);
	}

	virtual Door* makeDoor(Room* r1, Room* r2) const {
		return new Door(r1, r2);
	}
};

class MazeGame {
public:
	Maze * createMaze(MazeFactory* factory) {
		Maze* maze = factory->makeMaze();
		Room* r1 = factory->makeRoom(1);
		Room* r2 = factory->makeRoom(2);
		Door* door = factory->makeDoor(r1, r2);

		maze->addRoom(r1);
		maze->addRoom(r2);

		r1->setSide(North, factory->makeWall());
		r1->setSide(East, door);
		r1->setSide(South, factory->makeWall());
		r1->setSide(West, factory->makeWall());

		r2->setSide(North, factory->makeWall());
		r2->setSide(East, factory->makeWall());
		r2->setSide(South, factory->makeWall());
		r2->setSide(West, door);

		return maze;
	}
};

class EnchantedMazeFactory : public MazeFactory {
public:
	EnchantedMazeFactory() {
		// implementation;
	}

	virtual Room* makeRoom(int n) const {
		return new EnchantedRoom(n);
	}

	virtual Door* makeDoor(Room* r1, Room* r2) {
		return new DoorNeedingSpell(r1, r2);
	}
};

class BombedMazeFactory : public MazeFactory {
public:
	BombedMazeFactory() {
		// implmentation;
	}

	Wall* makeWall() const {
		return new BombedWall;
	}

	Room* makeRoom(int n) const {
		return new RoomWithABomb(n);
	}
};

int main()
{
	MazeGame game;
	BombedMazeFactory* factory = new BombedMazeFactory();
	game.createMaze(factory);
    return 0;
}

