#ifndef ZOOMSYS_H_
#define ZOOMSYS_H_
#include <string>
#include <iostream>
using namespace std;
#include "DiligentRoom.h"
#include "LazyRoom.h"
#include "DiligentStudent.h"
#include "LazyStudent.h"
#include "ResponsibleStudent.h"
#include <algorithm>
#include <vector>
#include <map>
#include <fstream>

class ZoomSys {
private:
	vector <Student*> Students;
	vector <Room*> Rooms;
	Room* FindRoom(int roomnum);
	Student* FindStudent(int id);
public:
	ZoomSys(const string address);
	void addStudent();
	void removeStudent();
	void assignStudent();
	void addRoom();
	void splitRoom();
	void removeRoom();
	void work();
	void sendMessage();
	void printRooms();
	void printStudents();
	void printStudentDetails();
	virtual ~ZoomSys();


};

#endif /* ZOOMSYS_H_ */
