// Maze_Game_No_Pattern.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "header.h"
#include "Maze_Game_Common.h"

class MazeGame {
public:
	Maze * createMaze() {
		Maze* maze = new Maze();
		Room* r1 = new Room(1);
		Room* r2 = new Room(2);
		Door* door = new Door(r1, r2);

		maze->addRoom(r1);
		maze->addRoom(r2);
		r1->setSide(North, new Wall);
		r1->setSide(East, new Door);
		r1->setSide(South, new Wall);
		r1->setSide(West, new Wall);

		r2->setSide(North, new Wall);
		r2->setSide(East, new Wall);
		r2->setSide(South, new Wall);
		r2->setSide(West, new Door);

		return maze;
	}
};


int main()
{
    return 0;
}

