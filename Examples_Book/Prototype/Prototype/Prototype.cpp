// Prototype.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Prototype.h"

class MazePrototypeFactory : public MazeFactory {
public:
	MazePrototypeFactory(Maze* m, Wall* w, Room* r, Door* d) {
		m_prototypeMaze = m;
		m_prototypeWall = w;
		m_prototypeRoom = r;
		m_prototypeDoor = d;
	};

	// From thebook: The member functions for creating walls, rooms, and doors are similar: 
	// Each clones a prototype and then initilize it.
	virtual Maze* makeMaze() const{
		return m_prototypeMaze->clone();
	}

	// In the book this member function has a parameter "int";
	// I do not think that is correct, as it is incosistent with
	// the comment above;
	virtual Room* makeRoom() const{
		return m_prototypeRoom->clone();
	};

	virtual Wall* makeWall() const {
		return m_prototypeWall->clone();
	};

	virtual Door* makeDoor(Room* r1, Room* r2) const {
		Door* door = m_prototypeDoor->clone();
		door->initilize(r1, r2);
		return door;
	};

private:
	Maze * m_prototypeMaze;
	Room* m_prototypeRoom;
	Wall* m_prototypeWall;
	Door* m_prototypeDoor;
};

class MazeGame {
public:
	Maze * createMaze(MazePrototypeFactory* prototypeFactory) {
		Maze* maze = prototypeFactory->makeMaze();
		Room* r1 = prototypeFactory->makeRoom();
		Room* r2 = prototypeFactory->makeRoom();
		Door* door = prototypeFactory->makeDoor(r1, r2);

		maze->addRoom(r1);
		maze->addRoom(r2);

		r1->setSide(East, door);
		r1->setSide(North, prototypeFactory->makeWall());
		r1->setSide(South, prototypeFactory->makeWall());
		r1->setSide(West, prototypeFactory->makeWall());

		r2->setSide(North, prototypeFactory->makeWall());
		r2->setSide(East, prototypeFactory->makeWall());
		r2->setSide(South, prototypeFactory->makeWall());
		r2->setSide(West, door);

		return maze;
	}
};


int main()
{
	MazeGame game;

	// create a simple maze;
	MazePrototypeFactory simpleMazeFactory(new Maze, new Wall, new Room, new Door);
	Maze* simpleMaze = game.createMaze(&simpleMazeFactory);

	// create a maze with BombedWall;
	MazePrototypeFactory bombedMazeFactory(new Maze, new BombedWall, new Room, new Door);
	Maze* bombedMaze = game.createMaze(&bombedMazeFactory);
}

