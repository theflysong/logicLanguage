#include "value.h"

Value::Value(int v, bool isConst) : type(DIGIT), isconst(isConst) {
	ip = new int(v);
}

Value::Value(double v, bool isConst) : type(DECIMAL), isconst(isConst) {
	dp = new double(v);
}

Value::Value(string v, bool isConst) : type(STRING), isconst(isConst) {
	sp = new string(v);
}

Value::Value(Object v, bool isConst) : type(OBJECT), isconst(isConst) {
	op = new Object(v);
}

Value::~Value() {
	delete p;
}
