#ifndef SRC_INVALIDDETAILS_H_
#define SRC_INVALIDDETAILS_H_

#include "Error.h"

class Invaliddetails: public Error {
public:
	Invaliddetails():Error(){};
	virtual void Handle()const{cout << "Please enter valid details" << endl;};
	virtual ~Invaliddetails(){};
};

#endif /* SRC_INVALIDDETAILS_H_ */
