#ifndef SRC_STUDENTPERMISSIONS_H_
#define SRC_STUDENTPERMISSIONS_H_

#include "Error.h"

class Studentpermissions: public Error {
public:
	Studentpermissions():Error(){};
	virtual void Handle()const{cout << "this student don't have permission" << endl;};
	virtual ~Studentpermissions(){};
};

#endif /* SRC_STUDENTPERMISSIONS_H_ */
