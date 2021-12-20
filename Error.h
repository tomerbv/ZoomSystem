#ifndef SRC_ERROR_H_
#define SRC_ERROR_H_
#include <iostream>
using namespace std;
class Error {
public:
	Error(){};
	virtual void Handle()const=0;
	virtual ~Error(){};

};

#endif /* SRC_ERROR_H_ */
