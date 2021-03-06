// Singleton.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "header.h"
#include "Maze_Game_Common.h"

class MazeFactory {
public:
	static MazeFactory* instance() {
		if (m_instance == 0) {
			m_instance = new MazeFactory();
		}

		return m_instance;
	}

protected:
	MazeFactory() {};

private:
	static MazeFactory* m_instance;
};

MazeFactory* MazeFactory::m_instance = 0;

int main()
{
	MazeFactory* factory = MazeFactory::instance();
}

// =========================================================================================
// optional reading: subclass EnchantedMazeFactory exists
// =========================================================================================
//class BombedMazeFactory : public MazeFactory {
//	//implmentation;
//};
//
//class MazeFactory {
//public:
//	static MazeFactory* instance() {
//		// Book: Now let 's consider what happe nswhen there aresubclass es of M a ze Fact ory, and
//		//	the application must decide which one to use.We 'll select the kind ofma ze through
//		//	an environment variable and add code that instantia tes th e proper MazeFactory
//		//	subclass based on the environment variable's value. The Instance operation is
//		//	a good place to put this code, because it already instantiate sMaze Factory:
//		if (m_instance == 0) {
//			const char* mazeStyle = getEnv("MAZESTYLE");
//
//			if (strcmp(mazeStyle, "bombed") == 0) {
//				m_instance = new BombedMazeFactory();
//			}
//			else {
//				m_instance = new MazeFactory;
//			}
//		}
//		return m_instance;
//
//		//Book: Note that Instance must be modified whenever you define a new subclass of
//		//MazeFactory.That might not be a problem in this application, but it might be
//		//for abstract factori es defined in a framework.
//		//A possible solution would be to use the registry approach described in the Implementation
//		//section.Dynamic linking could be useful here as well—it would keep
//		//the application from having to load all the subclasses that are not used.
//	}
//
//protected:
//	MazeFactory() {};
//
//private:
//	static MazeFactory* m_instance;
//};



