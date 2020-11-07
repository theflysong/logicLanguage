#include "value.h"

Value::Value(int v) : type(DIGIT) {
	ip = new int(v);
}

Value::Value(double v) : type(DECIMAL) {
	dp = new double(v);
}

Value::Value(string v) : type(STRING) {
	sp = new string(v);
}

Value::Value(Object v) : type(OBJECT) {
	op = new Object(v);
}

Value::~Value() {
	delete p;
}
