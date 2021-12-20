#include "LazyStudent.h"
#include "Room.h"

void LazyStudent::Cry() const{
	cout << first_name << " " << last_name << " is crying" << endl;
}

bool LazyStudent::AddToLazyRoom(Room* currroom, Room* moveroom){
	moveroom->AddStudent(*this);
	currroom->RemoveStudent(getid());
	return true;
}
LazyStudent::~LazyStudent() {
	// TODO Auto-generated destructor stub
}

