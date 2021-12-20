#include "Room.h"
#include "Student.h"
int Room::numofrooms = 0;

Room::Room() {

	hasplit=false;
	R_RoomNum=numofrooms;
	numofrooms++;
	Daddy = nullptr;
	Right = nullptr;
	Left = nullptr;


}
void Room::AddStudent(Student& stud){
	vector<Student*>::iterator it;
	Student* s = &stud;
	s->SetRoomNum(R_RoomNum);
	Students.push_back(s);

}

void Room::RemoveStudent(int id){
	vector<Student*>::iterator it;
	for(it = Students.begin();it!= Students.end();++it){
		if((*it)->getid()==id){
			Students.erase(it);
			break;
		}
	}
}


void Room::Split(Room* Left, Room* Right, const string type){
	if(hasplit)
		throw Splitbefore();

	if(type == "1"){
		int i = 0;
		while(i < (int)Students.size()){
			if(Students[i]->AddToDiligentRoom(this,Left))
				continue;
			if(Students[i]->AddToLazyRoom(this,Right))
				continue;
			i++;
		}
		this->Left = Left;
		this->Right = Right;
		Left->Daddy = this;
		Right->Daddy = this;
		hasplit = true;
	}

	else if(type == "2"){
		vector<Student*>::iterator it;
		int HalfInd = (Students.size()/2);
		int counter = 1;
		while((int)Students.size() != 0){
			if(counter <= HalfInd){
				Left->AddStudent(*Students[0]);
				Students.erase(Students.begin());
			}
			else{
				Right->AddStudent(*Students[0]);
				Students.erase(Students.begin());
			}
			counter++;
		}
		this->Left = Left;
		this->Right = Right;
		Left->Daddy = this;
		Right->Daddy = this;
		hasplit = true;
	}
	else
		throw Invaliddetails();

}
void Room::Work(){
	vector<Student*>::iterator it;
	for(it = Students.begin();it != Students.end();++it){
		(*it)->Work();
	}
}
void Room::MessageAllStudentsBy(Student* stud, const string Message){
	vector<Student*>::iterator it;
	for(it = Students.begin();it!= Students.end();++it){
		(*it)->AddMessage(Message);
	}
}

Room* Room::FindRoomRec(int roomnum){
	if(R_RoomNum == roomnum)
		return this;
	if(Left != nullptr)
		if(Left->FindRoomRec(roomnum) != nullptr)
			return Left->FindRoomRec(roomnum);
	if(Right != nullptr)
		if(Right->FindRoomRec(roomnum) != nullptr)
			return Right->FindRoomRec(roomnum);
	return nullptr;
}

void Room::PrintRoom()const{
	cout << "room id:" << R_RoomNum << ", students:" << Students.size() << endl;
}

void Room::PrintRoomAndSons()const{
	PrintRoom();
	if(Left != nullptr)
		Left->PrintRoomAndSons();
	if(Right != nullptr)
		Right->PrintRoomAndSons();
}
void Room::Empty(){
	if(Left != nullptr)
		Left->Empty();
	if(Right != nullptr)
		Right->Empty();
	while((int)Students.size() != 0){
		Student* temp = Students[0];
		Students.erase(Students.begin());
		temp->SetRoomNum(-1);
	}

}
Room::~Room(){
	if(Left != nullptr)
		delete Left;
	if(Right != nullptr)
		delete Right;
	if(Daddy != nullptr){
		if(Daddy->Left){
			if(Daddy->Left->R_RoomNum == this->R_RoomNum)
				Daddy->Left = nullptr;
		}
		if(Daddy->Right){
			if(Daddy->Right->R_RoomNum == this->R_RoomNum)
				Daddy->Right = nullptr;
		}
	}
	while((int)Students.size() != 0){
		Student* temp = Students[0];
		temp->Cry();
		Students.erase(Students.begin());
		if(Daddy != nullptr){
			Daddy->AddStudent(*temp);
		}
		else
			(temp)->SetRoomNum(-1);
	}
}

