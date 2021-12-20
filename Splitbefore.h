#ifndef SRC_SPLITBEFORE_H_
#define SRC_SPLITBEFORE_H_

#include "Error.h"

class Splitbefore: public Error {
public:
	Splitbefore():Error(){};
	virtual void Handle()const{cout << "This room was split before" << endl;};
	virtual ~Splitbefore(){};
};

#endif /* SRC_SPLITBEFORE_H_ */
