#pragma once

enum Direction { North, South, East, West };

class MapSite {
public:
	// nothing;
};

class Room : public MapSite {
public:
	Room() {
		// default constructor is needed for base class;
		// implmentation;
	}

	Room(int n) {
		// implementation;
	}

	Room(const Room&) {
		// implementation;
	};

	Room* clone() const {
		// implementation;
		return new Room(*this);
	}

	void setSide(Direction, MapSite*) {
		// implementation;
	};

private:
	MapSite * m_sides[4];
};

class Door : public MapSite {
public:
	Door() {
		// default constuctor can be used with method "initialize";
		//implementation;
	};

	Door(const Door& other) {
		m_room1 = other.m_room1;
		m_room2 = other.m_room2;
	};

	Door* clone() const {
		return new Door(*this);
	};

	virtual void initilize(Room* r1, Room* r2) {
		m_room1 = r1;
		m_room2 = r2;
	}

private:
	Room * m_room1;
	Room* m_room2;
};

class Wall : public MapSite {
public:
	Wall() {
		// implmentation;
	}

	Wall(const Wall&) {
		// implementation;
	}

	virtual Wall* clone() const {
		return new Wall(*this);
	};
};

class Maze {
public:
	Maze() {
		//implmentation;
	}

	Maze(const Maze&) {
		// implementation;
	};

	virtual Maze* clone() const {
		return new Maze(*this);
	};

	void addRoom(Room*) {
		// implementation;
	}
};

class BombedWall : public Wall {
public:
	BombedWall() {
		// implementation;
	}

	BombedWall(const BombedWall& other) {
		m_bomb = other.m_bomb;
	}

	virtual Wall* clone() const {
		return new BombedWall(*this);
	}

private:
	bool m_bomb;
};

// BombedDoor, BombedRoom are omitted;

class MazeFactory {
public:
	MazeFactory() {
		// implementation;
	}

	virtual Maze* makeMaze() const {
		// implementation
		return new Maze();
	}

	virtual Wall* makeWall() const {
		// implementation
		return new Wall();
	}

	virtual Room* makeRoom(int n) const {
		// implementation
		return new Room(n);
	}

	virtual Door* makeDoor() const {
		// implementation;
		return new Door();
	}
};