#ifndef RESPONSIBLESTUDENT_H_
#define RESPONSIBLESTUDENT_H_
#include "Student.h"

class ResponsibleStudent : public Student{
public:
	ResponsibleStudent(int id,const string first, const string last, float avg):
		Student(id,first,last,avg){};
	virtual void Cry() const{};
	virtual void Work()const{};
	virtual void Message(Room* room, const string Message);
	virtual bool AddToLazyRoom(Room* currroom, Room* moveroom){return false;};
	virtual bool AddToDiligentRoom(Room* currroom, Room* moveroom){return false;};
	virtual ~ResponsibleStudent();
};

#endif /* RESPONSIBLESTUDENT_H_ */
