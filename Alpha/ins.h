#ifndef __INS_P
#define __INS_P

#include "head.h"
#include "value.h"

class Ins {
public:
	enum InsType {
		NOP = 0,
		RET, //NORMAL
		PUSH,
		POP, //STACK
		CONST, //CONST
		JMP,
		JZ,
		JNZ, //JUMP
		GET, //GET
		ADD,
		SUB,
		MUL,
		DIV,
		MOD,
		LSH,
		RSH,
		INC,
		DEC,
		AND,
		OR,
		XOR,
		BIG,
		SML,
		EQU,
		BIGQ,
		SMLQ,
		NEQ, //OPERATOR
		CALL
	};
private:
	const InsType type;
	const string kind;
public:
	virtual InsType getType();
	Ins(InsType typeIn, string kindIn);
	virtual string getKind();
};

struct Label {
	int pos;
	Label(int posIn);
	Label();
	void setPos(int posIn);
};

class JmpIns : public Ins{
	Label label;
public:
	JmpIns(Ins::InsType typeIn, Label labelIn);
	Label& getLabel();
};

class StackIns : public Ins{
	int id;
public:
	StackIns(Ins::InsType typeIn, int idIn);
	int getid();
};

class ConstIns : public Ins{
	Value* value;
public:
	ConstIns(Ins::InsType typeIn, Value* valueIn);
	Value* getValue();
};

class GetIns : public Ins{
	int id;
public:
	GetIns(Ins::InsType typeIn, int id);
	int getId();
};

class OperatorIns : public Ins{
public:
	OperatorIns(Ins::InsType typeIn);
};

class NormalIns : public Ins{
public:
	NormalIns(Ins::InsType typeIn);
};

#endif
