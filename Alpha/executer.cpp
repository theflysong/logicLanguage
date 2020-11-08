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

Value* Executer::popRuntime() {
	Value* value = runtime.top();
	runtime.pop();
	return value;
}

void Executer::pushRuntime(Value* value) {
	runtime.push(value);
}

void Executer::throwExec(LogicExec* exec) {
	cout << exec->msg();
	delete exec;
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
				case Ins::JZ:{
					Value* v = popRuntime();
					if (! (*(v->ip))) {
						go(ins->getLabel().pos);
					}
					if (v -> isconst) {
						delete v;
					}
					break;
				}
				case Ins::JNZ:{
					Value* v = popRuntime();
					if (*(v->ip)) {
						go(ins->getLabel().pos);
					}
					if (v -> isconst) {
						delete v;
					}
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
			OperatorIns* ins = (OperatorIns*)pins;
			switch(ins->getType()) {
				case Ins::DEC: {
					Value* v = popRuntime();
					if (v->isconst) {
						throwExec(new IncDecConstExec());
					}
					else {
						(*(v->ip)) --;
					}
					break;
				}
				case Ins::INC: {
					Value* v = popRuntime();
					if (v->isconst) {
						throwExec(new IncDecConstExec());
					}
					else {
						(*(v->ip)) ++;
					}
					break;
				}
				case Ins::EQU: {
					Value* v1 = popRuntime();
					Value* v2 = popRuntime();
					int i1 = *(v1->ip);
					int i2 = *(v2->ip);
					if (i1 == i2) {
						pushRuntime(new Value(1, true));
					}
					else {
						pushRuntime(new Value(0, true));
					}
					if (v1->isconst) {
						delete v1;
					}
					if (v2->isconst) {
						delete v2;
					}
					break;
				}
				case Ins::NEQ: {
					Value* v1 = popRuntime();
					Value* v2 = popRuntime();
					int i1 = *(v1->ip);
					int i2 = *(v2->ip);
					if (i1 != i2) {
						pushRuntime(new Value(1, true));
					}
					else {
						pushRuntime(new Value(0, true));
					}
					if (v1->isconst) {
						delete v1;
					}
					if (v2->isconst) {
						delete v2;
					}
					break;
				}
				case Ins::SUB: {
					Value* v1 = popRuntime();
					Value* v2 = popRuntime();
					int i1 = *(v1->ip);
					int i2 = *(v2->ip);
					pushRuntime(new Value(i1 - i2));
					if (v1->isconst) {
						delete v1;
					}
					if (v2->isconst) {
						delete v2;
					}
					break;
				}
				case Ins::ADD: {
					Value* v1 = popRuntime();
					Value* v2 = popRuntime();
					int i1 = *(v1->ip);
					int i2 = *(v2->ip);
					pushRuntime(new Value(i1 + i2));
					if (v1->isconst) {
						delete v1;
					}
					if (v2->isconst) {
						delete v2;
					}
					break;
				}
				case Ins::MUL: {
					Value* v1 = popRuntime();
					Value* v2 = popRuntime();
					int i1 = *(v1->ip);
					int i2 = *(v2->ip);
					pushRuntime(new Value(i1 * i2));
					if (v1->isconst) {
						delete v1;
					}
					if (v2->isconst) {
						delete v2;
					}
					break;
				}
				case Ins::DIV: {
					Value* v1 = popRuntime();
					Value* v2 = popRuntime();
					int i1 = *(v1->ip);
					int i2 = *(v2->ip);
					pushRuntime(new Value(i1 / i2));
					if (v1->isconst) {
						delete v1;
					}
					if (v2->isconst) {
						delete v2;
					}
					break;
				}
			}
		}
		else if(pins->getKind()=="const") {
			ConstIns* ins = (ConstIns*)pins;
			switch (pins->getType()) {
				case Ins::CONST: {
					pushRuntime(ins->getValue());
					break;
				}
			}
		}
		else if(pins->getKind()=="invoke") {
		}
		pins = getIns();
	}
}
