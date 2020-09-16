#pragma once

enum Direction { North, South, East, West };

class MapSite {
public:
	virtual void enter() = 0;
};

class Room : public MapSite {
public:
	Room(int roomNo) {
		// implementation;
	};

	MapSite* getSide(Direction) const {
		// implmentation;
		return nullptr;
	};

	void setSide(Direction, MapSite*) {
		// implementation;
	};

	virtual void enter() {
		// implementation;
	};

private:
	MapSite * m_sides[4];
	int m_rootNumber;
};

class Wall : public MapSite {
public:
	Wall() {
		// implementation;
	};

	virtual void enter() {
		// implementation;
	}
};

class Door : public MapSite {
public:
	Door(Room* = 0, Room* = 0) {
		// implementation;
	}

	virtual void enter() {
		// implementation;
	};

	Room* otherSideFrom(Room*) {
		//implementation;
		return nullptr;
	}

private:
	Room * m_room1;
	Room* m_room2;
	bool m_isOpen;
};

class Maze {
public:
	Maze() {
		// implementation;
	}

	void addRoom(Room*) {
		// implementation;
	}

	Room* RoomNo(int) const {
		// implementation;
		return nullptr;
	}

private:
	// ...
};