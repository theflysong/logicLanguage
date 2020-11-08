#include "tree.h"
#include "lexer.h"
#include "executer.h"

int main(int argc, char** argv) {
	Executer exe;
	exe.addIns(new ConstIns(Ins::CONST, new Value(2, true)));
	exe.addIns(new ConstIns(Ins::CONST, new Value(3, true)));
	exe.addIns(new OperatorIns(Ins::ADD));
	exe.addIns(new NormalIns(Ins::RET));
	exe.execute();
	Value* v = exe.popRuntime();
	cout << *(v->ip);
	delete v;
	return 0;
}
