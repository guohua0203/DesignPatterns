// Factory_Method.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "header.h"
#include "Factory_Method.h"

class MazeGame {
public:
	Maze * createMaze();

	// factory methods:
	virtual Maze* makeMaze() const {
		return new Maze;
	}

	virtual Room* makeRoom(int n) const {
		return new Room(n);
	}

	virtual Wall* makeWall() const {
		return new Wall;
	}

	virtual Door* makeDoor(Room* r1, Room* r2) {
		return new Door(r1, r2);
	}
};

Maze* MazeGame::createMaze() {
	Maze* aMaze = makeMaze();
	Room* r1 = makeRoom(1);
	Room* r2 = makeRoom(2);
	Door* theDoor = makeDoor(r1, r2);

	aMaze->addRoom(r1);
	aMaze->addRoom(r2);

	r1->setSide(North, makeWall());
	r1->setSide(East, theDoor);
	r1->setSide(South, makeWall());
	r1->setSide(West, makeWall());

	r2->setSide(North, makeWall());
	r2->setSide(East, makeWall());
	r2->setSide(South, makeWall());
	r2->setSide(West, theDoor);

	return aMaze;
}

class BombedMazeGame : public MazeGame {
public:
	BombedMazeGame() {
		// implementation
	}

	virtual Wall* makeWall() const {
		return new BombedWall;
	}

	virtual Room* makeRoom(int n) const {
		return new RoomWithABomb(n);
	}
};

class EnchantedMazeGame : public MazeGame {
public:
	EnchantedMazeGame() {
		//implementation;
	}

	virtual Room* makeRoom(int n) const {
		return new EnchantedRoom(n);
	}

	virtual Door* makeDoor(Room* r1, Room* r2) const {
		return new DoorNeedingSpell(r1, r2);
	}
};

int main()
{
	MazeGame* mg1 = new EnchantedMazeGame();
	Maze* mz1 = mg1->createMaze();

	MazeGame* mg2 = new BombedMazeGame();
	Maze* mz2 = mg2->createMaze();

	delete(mg1);
	delete(mg2);
	delete(mz1);
	delete(mz2);

    return 0;

}

