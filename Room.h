#ifndef ROOM_H_
#define ROOM_H_
class Student;
#include <vector>
#include <string.h>
#include <iostream>
using namespace std;


class Room {
private:
	static int numofrooms;
	int R_RoomNum;
	vector<Student*> Students;
	bool hasplit;
	Room* Daddy;
	Room* Left;
	Room* Right;
public:
	Room();
	virtual ~Room();
	void Empty();
	void AddStudent(Student& stud);
	void RemoveStudent(int id);
	void Split(Room* Left, Room* Right, const string type);
	void Work();
	void MessageAllStudentsBy(Student* stud, const string Message);
	int getnumofrooms()const{return numofrooms;}
	Room* GetLeft()const{return Left;};
	Room* GetRight()const{return Right;};
	Room* FindRoomRec(int roomnum);
	int GetRoomNum()const{return R_RoomNum;};
	void PrintRoom()const;
	void PrintRoomAndSons()const;
	bool WasSplit()const{return hasplit;};
};

#endif /* ROOM_H_ */
