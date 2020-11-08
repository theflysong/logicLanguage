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
	bool isconst;
	Value(int v, bool isConst=false);
	Value(double v, bool isConst=false);
	Value(string v, bool isConst=false);
	Value(Object v, bool isConst=false);
	~Value();
};

#endif
