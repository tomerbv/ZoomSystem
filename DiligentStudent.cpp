#include "DiligentStudent.h"
#include "Room.h"

bool DiligentStudent::AddToDiligentRoom(Room* currroom, Room* moveroom){
	moveroom->AddStudent(*this);
	currroom->RemoveStudent(getid());
	return true;
}
void DiligentStudent::Work()const{
	cout << first_name << " " << last_name << " is working" << endl;
}
DiligentStudent::~DiligentStudent() {
	// TODO Auto-generated destructor stub
}

