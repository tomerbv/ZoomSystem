#ifndef SRC_IDEXCEPTION_H_
#define SRC_IDEXCEPTION_H_

#include "Error.h"

class idexception: public Error {
public:
	idexception():Error(){};
	virtual void Handle()const{cout << "id doesn't exists" << endl;};
	virtual ~idexception(){};
};

#endif /* SRC_IDEXCEPTION_H_ */
