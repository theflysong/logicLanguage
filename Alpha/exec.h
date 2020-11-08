#ifndef __EXEC__H
#define __EXEC__H

#include "head.h"

abstract class LogicExec {
public:
	virtual string msg() = 0;	
};

class IncDecConstExec : public LogicExec{
public:
	virtual string msg() {
		return "can't inc/dec const value";
	}
};

#endif
