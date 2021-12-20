#ifndef LAZYSTUDENT_H_
#define LAZYSTUDENT_H_
#include "Student.h"

class LazyStudent : public Student{
public:
	LazyStudent(int id,const string first, const string last, float avg):
		Student(id,first,last,avg){};
	virtual void Cry() const;
	virtual void Work()const{};
	virtual void Message(Room* room, string Message){throw Studentpermissions();};
	virtual bool AddToLazyRoom(Room* currroom, Room* moveroom);
	virtual bool AddToDiligentRoom(Room* currroom, Room* moveroom){return false;};
	virtual ~LazyStudent();

};

#endif /* LAZYSTUDENT_H_ */
