#include "ResponsibleStudent.h"
#include "Room.h"


void ResponsibleStudent::Message(Room* room, const string Message){
	string MessageFrom = first_name + " " + last_name + ":" + Message;
	room->MessageAllStudentsBy(this, MessageFrom);
}


ResponsibleStudent::~ResponsibleStudent() {
	// TODO Auto-generated destructor stub
}
