// Facade.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "header.h"
#include "Facade.h"

// Compiler Subsystems: ProgramNode, ProgramNodeBuilder, CodeGenerator;
class ProgramNode;
class ProgramNodeBuilder;
class CodeGenerator;

// sub classes of ProgramNode;
class StatementNode;
class ExpressionNode;

// sub class of CodeGenerator;
class RiscCodeGenerator;

class ProgramNode {
public:
	virtual void traverse(CodeGenerator& cg) {
		cout << "code generator generates code for this program node" << endl;
	}
};

class Scanner {
public:
	Scanner(istream& inputStream) : m_inputStream(inputStream) {}
	virtual Token& scan() {
		//implmentation;
		Token token;
		return token;
	}

private:
	istream & m_inputStream;
};

class Parser {
public:
	Parser() {
		// implementation;
	}

	virtual void parse(Scanner& s, ProgramNodeBuilder& pnb) {
		cout << "parser generate parse-tree that roots at a program node" << endl;
	}
};

class ProgramNodeBuilder {
public:
	ProgramNodeBuilder() {
		// implementation;
		m_node = new ProgramNode;
	}

	virtual ProgramNode* newVariable(const char* variableName) {
		// implementation;
		return nullptr;
	}

	virtual ProgramNode* newAssignment(ProgramNode* variable, ProgramNode* expression) {
		// implementation;
		return nullptr;
	}

	ProgramNode* getRootNode() {
		return m_node;
	}

private:
	ProgramNode * m_node;
};

class CodeGenerator {
public:
	virtual void visit(StatementNode*) {
		// implemenation;
	}

	virtual void visit(ExpressionNode*) {
		// implementation;
	}

protected:
	CodeGenerator(ByteCodeStream& output) : m_output(output) {
		// implementation;
	}

private:
	ByteCodeStream m_output;
};

class RiscCodeGenerator : public CodeGenerator{
public:
	RiscCodeGenerator(ByteCodeStream& output) : CodeGenerator(output){
		// implemenation;
	}
};

// Compiler is the facade of Compiler Subsystems;
class Compiler {
public:
	Compiler() {
		// implementation
	}

	virtual void compile(istream& inputStream, ByteCodeStream& output) {
		Scanner scanner(inputStream);
		ProgramNodeBuilder builder;
		Parser parser;

		parser.parse(scanner, builder);
		
		RiscCodeGenerator generator(output);
		ProgramNode* parseTree = builder.getRootNode();
		parseTree->traverse(generator);
	}
};


int main()
{
	std::filebuf fb;
	istream inputStream(&fb);
	ByteCodeStream output;
	Compiler compiler;

	compiler.compile(inputStream, output);
    return 0;
}

