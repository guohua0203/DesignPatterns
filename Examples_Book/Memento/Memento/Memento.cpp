// Memento.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "header.h"

#include "Memento.h"

class Graphic;
class ConstraintSolverMemento;

class ConstraintSolverMemento {
public:
	virtual ~ConstraintSolverMemento() {}

private:
	friend class ConstraintSolver;

	ConstraintSolverMemento() {
		// implementation;
	}

	// private constraint solver state;
};

class ConstraintSolver {
public:
	static ConstraintSolver* instance() {
		return new ConstraintSolver();
	};

	void solve() {
		cout << "Constraint Sovler solve the Connectivity Constraints" << endl;
	}

	ConstraintSolverMemento* createMemento() {
		cout << "Constraint Solver *create* a Memento" << endl;
		return new ConstraintSolverMemento();
	}

	void setMemento(ConstraintSolverMemento* csm) {
		cout << "Constraint Solver *set* the Memento" << endl;
	}

private:
	// nontrivial state and operations for enforcing
	// connectivity semantics;
};

class MoveCommand {
public:
	MoveCommand(Graphic* target, const Point& delta) {
		m_target = target;
		m_delta = delta;
	}

	void execute() {
		ConstraintSolver* solver = ConstraintSolver::instance();
		m_state = solver->createMemento();
		m_target->move(m_delta);
		solver->solve();
	}

	void unexecute() {
		ConstraintSolver* solver = ConstraintSolver::instance();
		m_target->move(-m_delta);
		solver->setMemento(m_state);
		solver->solve();
	}

private:
	ConstraintSolverMemento * m_state;
	Point m_delta;
	Graphic* m_target;
};

int main()
{
	Graphic* target = new Graphic();
	Point delta;
	MoveCommand mc(target, delta);

	mc.execute();
	mc.unexecute();

	return 0;
}

