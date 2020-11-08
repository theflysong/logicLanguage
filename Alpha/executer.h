#ifndef __EXECUTER_P
#define __EXECUTER_P

#include "ins.h"
#include "exec.h"
#include "method.h"

class Executer {
	int pn;
	vector<Ins*> isl;
	Array<Value*> values;
	stack<Value*> runtime;
public:
	void throwExec(LogicExec* exec);
	Value* popRuntime();
	void pushRuntime(Value* value);
	Value* getValue(int pos);
	void setValue(int pos, Value* value);
	void addIns(Ins* ins);
	int getEndPos();
	int next();
	int go(int pos);
	Ins* getIns();
	~Executer();
	Executer();
	void execute();
};

#endif

