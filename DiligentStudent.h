#ifndef DILIGENTSTUDENT_H_
#define DILIGENTSTUDENT_H_
#include "Student.h"

class DiligentStudent :	public Student{
public:
	DiligentStudent(int id,const string first,const string last, float avg):
		Student(id,first,last,avg){};
	virtual void Cry() const{};
	virtual void Work()const;
	virtual void Message(Room* room, string Message){throw Studentpermissions();};
	virtual bool AddToLazyRoom(Room* currroom, Room* moveroom){return false;};
	virtual bool AddToDiligentRoom(Room* currroom, Room* moveroom);
	virtual ~DiligentStudent();
};

#endif /* DILIGENTSTUDENT_H_ */
