#ifndef STUDENT_H_
#define STUDENT_H_
#include <string>
#include <iostream>
using namespace std;
#include <vector>
#include "idexception.h"
#include "Invaliddetails.h"
#include "Splitbefore.h"
#include "Studentpermissions.h"

class Room;


class Student{
protected:
	int id;
	string first_name;
	string last_name;
	float avg;
	int RoomNum;
	vector<string> messages;
public:

	Student();
	Student(int id,const string first, const string last, float avg);
	int getid()const{return id;}
	virtual void Cry() const{};
	friend ostream& operator<<(ostream& out, Student& other);
	void SetRoomNum(int roomnum){RoomNum = roomnum;};
	int GetRoomNum()const{return RoomNum;};
	virtual void Work()const=0;
	virtual void Message(Room* room, string Message)=0;
	void AddMessage(const string Message){messages.push_back(Message);};
	virtual bool AddToLazyRoom(Room* currroom, Room* moveroom)=0;
	virtual bool AddToDiligentRoom(Room* currroom, Room* moveroom)=0;
	void PrintStudent();
	void PrintStudentDetails();
	virtual ~Student(){};
};

#endif /* STUDENT_H_ */
