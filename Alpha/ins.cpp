#include "ins.h"

Ins::InsType Ins::getType() {
	return this->type;
}
	
Ins::Ins(InsType typeIn, string kindIn) : type(typeIn), kind(kindIn){
}
	
string Ins::getKind() {
	return kind;
}

Label::Label(int posIn) : pos(posIn) {	
}

Label::Label() : pos(-1) {
}

void Label::setPos(int posIn) {
	this->pos = posIn;
}

Label& JmpIns::getLabel() {
	return label;
}

JmpIns::JmpIns(Ins::InsType typeIn, Label labelIn) : Ins(typeIn, "jmp"), label(labelIn) {
}

StackIns::StackIns(Ins::InsType typeIn, int idIn) : Ins(typeIn, "stack"), id(idIn) {
}

int StackIns::getid() {
	return id;
}

ConstIns::ConstIns(Ins::InsType typeIn, Value* valueIn) : Ins(typeIn, "const"), value(valueIn){
}

Value* ConstIns::getValue() {
	return value;
}

GetIns::GetIns(Ins::InsType typeIn, int idIn) : Ins(typeIn, "get"), id(idIn) {
}

int GetIns::getId() {
	return id;
}

OperatorIns::OperatorIns(Ins::InsType typeIn) : Ins(typeIn, "operator"){
}

InvokeIns::InvokeIns(Ins::InsType typeIn, string methodIn) : Ins(typeIn, "invoke"), method(methodIn){
}

string InvokeIns::getMethod() {
	return method;
}

NormalIns::NormalIns(Ins::InsType typeIn) : Ins(typeIn, "normal") {
}
