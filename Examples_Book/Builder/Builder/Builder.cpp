// Builder.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "header.h"
#include "Builder.h"
#include "Maze_Game_Common.h"

class MazeBuilder {
public:
	virtual void buildMaze() {
		// nothing;
	}

	virtual void buildRoom(int room) {
		// nothing;
	}

	virtual void buildDoor(int rommFrom, int roomTo) {
		// nothing;
	}

	virtual Maze* GetMaze() {
		return 0;
	}
protected:
	MazeBuilder() {
		// nothing;
	};
};

class MazeGame {
public:
	Maze * createMaze(MazeBuilder& builder) {
		builder.buildMaze();
		builder.buildRoom(1);
		builder.buildRoom(2);
		builder.buildDoor(1, 2);

		return builder.GetMaze();
	}
};

class StandardMazeBuilder : public MazeBuilder {
public:
	StandardMazeBuilder() {
		m_currentMaze = 0;
	};

	virtual void buildMaze() {
		m_currentMaze = new Maze;
	}

	virtual void buildRoom(int n) {
		Room* room = new Room(n);
		m_currentMaze->addRoom(room);
		room->setSide(North, new Wall);
		room->setSide(South, new Wall);
		room->setSide(East, new Wall);
		room->setSide(West, new Wall);
	}

	virtual void buildDoor(int n1, int n2) {
		Room* r1 = m_currentMaze->RoomNo(n1);
		Room* r2 = m_currentMaze->RoomNo(n2);
		Door* d = new Door(r1, r2);

		r1->setSide(commonWall(r1, r2), d);
		r2->setSide(commonWall(r2, r1), d);
	}

	virtual Maze* getMaze() {
		return m_currentMaze;
	}

private:
	Direction commonWall(Room*, Room*) {
		// implementation;
		return North;
	}

	Maze* m_currentMaze;
};

class CountingMazeBuilder : public MazeBuilder {
public:
	CountingMazeBuilder() {
		m_doors = 0;
		m_rooms = 0;
	}

	virtual void buildMaze() {
		// implementation;
	}

	virtual void buildRoom(int) {
		m_rooms++;
	}

	virtual void buildDoor(int, int) {
		m_doors++;
	}

	void getCounts(int& rooms, int& doors) {
		rooms = m_rooms;
		doors = m_doors;
	}

private:
	int m_doors;
	int m_rooms;
};

int main()
{
	Maze* maze;
	MazeGame game;
	StandardMazeBuilder builder;
	game.createMaze(builder);
	maze = builder.getMaze();

	int rooms;
	int doors;
	MazeGame game2;
	CountingMazeBuilder builder2;
	game2.createMaze(builder);
	builder2.getCounts(rooms, doors);

	cout << "The maze has " << rooms << " rooms and " << doors << " doors" << endl;

	return 0;
}

