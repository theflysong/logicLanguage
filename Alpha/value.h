#ifndef __VALUE_P
#define __VALUE_P

#include "head.h"

struct Value;

struct Object {
	hash_map<string, Value*> feilds;
};

struct Value {
	union {
		void* p;
		int* ip;
		double* dp;
		string* sp;
		Object* op;
	};
	enum Type {
		DIGIT,
		DECIMAL,
		STRING,
		OBJECT
	};
	Type type;
	Value(int v);
	Value(double v);
	Value(string v);
	Value(Object v);
	~Value();
};

#endif
