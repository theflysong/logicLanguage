#include "executer.h"

void Executer::addIns(Ins* ins) {
    isl.push_back(ins);
}

int Executer::getEndPos() {
    return isl.size();
}

int Executer::next() {
    return pn ++;
}

int Executer::go(int pos) {
    pn = pos;
}

Ins* Executer::getIns() {
    return isl[pn];
}

Executer::~Executer() {
    for (auto i : isl) {
    	if (i) delete i;
    }
	values.foreach([](Value* v) {
		if (v) delete v;
    });
    isl.clear();
    values.clear();
}

Executer::Executer() {
    pn = 0;
}

Value* Executer::getValue(int pos) {
	return values[pos];
}

void Executer::setValue(int pos, Value* value) {
	values[pos] = value;
}

Value* popRuntime() {
	Value* value = stack.top();
	stack.pop();
	return value;
}

void pushRuntime(Value* value) {
	stack.push(value);
}

void Executer::execute() {
	Ins* pins = getIns();
	while(pins->getType() != Ins::RET) {
		next();
		if (pins->getKind()=="normal") {
			NormalIns* ins = (NormalIns*)pins;
			switch (ins->getType()) {
				case Ins::NOP: {
					break;
				}
				default:{
					break;
				}
			}
		}
		else if(pins->getKind()=="jmp") {
			JmpIns* ins = (JmpIns*)pins;
			switch(ins->getType()) {
				case Ins::JMP:{
					go(ins->getLabel().pos);
					break;
				}
				default:{
					break;
				}
			}
		}
		else if(pins->getKind()=="stack") {
			StackIns* ins = (StackIns*)pins;
			switch(ins->getType()) {
				case Ins::PUSH: {
					pushRuntime(values[ins->getid()]);
					break;
				}
				case Ins::POP: {
					if (values[ins->getid()]) {
						delete values[ins->getid()];
					}
					values[ins->getid()] = popRuntime();
					break;
				}
				default:{
					break;
				}
			}
		}
		else if(pins->getKind()=="operator") {
			Operator* ins = (Operator*)pins;
		}
		ins = getIns();
	}
}
