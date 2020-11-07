#include "tree.h"
#include "lexer.h"
#include "executer.h"

int main(int argc, char** argv) {
	Executer exe;
	exe.addIns(new NormalIns(Ins::NOP));
	exe.addIns(new NormalIns(Ins::NOP));
	exe.addIns(new NormalIns(Ins::NOP));
	exe.addIns(new JmpIns(Ins::JMP, Label(0)));
	exe.addIns(new NormalIns(Ins::RET));
	cout << *(exe.getValue(0) -> sp);
	exe.execute();
	return 0;
}
