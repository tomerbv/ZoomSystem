#include "ZoomSys.h"

ZoomSys::ZoomSys(const string address) {
	ifstream inputfile(address);
	string first,last,type;
	int id,avg;
	Student* s = NULL;
	while(inputfile >> first >> last >> id >> avg >> type){
		if(type == "L")
			s = new LazyStudent( id, first,  last,  avg);
		else if(type == "W")
			s = new DiligentStudent( id, first,  last,  avg);
		else if(type == "R")
			s = new ResponsibleStudent( id, first,  last,  avg);
		if(!s){
			cout << "Input file invalid" << endl;
			this->~ZoomSys();
			exit(1);
		}
		Students.push_back(s);
	}

}


Student* ZoomSys::FindStudent(int id){
	vector<Student*>::iterator it;
	for(it = Students.begin();it!= Students.end();++it){
		if((*it)->getid() == id)
			return (*it);
	}
	return nullptr;
}

Room* ZoomSys::FindRoom(int roomnum){
	vector<Room*>::iterator it;
	for(it = Rooms.begin();it!= Rooms.end();++it){
		if((*it)->FindRoomRec(roomnum) != nullptr)
			return (*it)->FindRoomRec(roomnum);
	}
	throw idexception();
}

void ZoomSys::addStudent(){
	cout << "---Create Student---\nFirst name:" << endl;
	string FirstName;
	cin >> FirstName;

	cout << "Last name:" << endl;
	string LastName;
	cin >> LastName;

	cout << "ID:" << endl;
	string ID;
	cin >> ID;

	int idnum = stoi(ID);

	cout << "avg:" << endl;
	int Avg;
	cin >> Avg;

	cout << "Worker(W) or Lazy(L) or Responsible(R) Student?" << endl;
	string Type;
	cin >> Type;
	Student* s;

	try{
		s = FindStudent(idnum);
		if(s != nullptr)
			throw Invaliddetails();
		if(Type == "W"){
			DiligentStudent* stud = new DiligentStudent(idnum,FirstName,LastName,Avg);
			if(!stud){
				cout << "Memory Problem" << endl;
				this->~ZoomSys();
				exit(1);
			}
			Students.push_back(stud);
		}
		else if(Type == "L"){
			LazyStudent* stud = new LazyStudent(idnum,FirstName,LastName,Avg);
			if(!stud){
				cout << "Memory Problem" << endl;
				this->~ZoomSys();
				exit(1);
			}
			Students.push_back(stud);
		}
		else if(Type == "R"){
			ResponsibleStudent* stud = new ResponsibleStudent(idnum,FirstName,LastName,Avg);
			if(!stud){
				cout << "Memory Problem" << endl;
				this->~ZoomSys();
				exit(1);
			}
			Students.push_back(stud);
		}
		else
			throw Invaliddetails();
	}
	catch(Error& e){
		e.Handle();
	}


}
void ZoomSys::removeStudent(){
	cout << "---Remove Student---\nEnter the id:" << endl;
	string ID;
	cin >> ID;
	int idnum = stoi(ID);
	Student* stud;
	try{
		stud = FindStudent(idnum);
		if(stud == nullptr)
			throw idexception();
		if(stud->GetRoomNum() != -1){
			Room* room = FindRoom(stud->GetRoomNum());
			room->RemoveStudent(idnum);
		}
		vector<Student*>::iterator it;
		for(it = Students.begin();it!= Students.end();++it){
			if((*it)->getid() == stud->getid()){
				Students.erase(it);
				break;
			}
		}
		delete stud;
	}
	catch(Error& e){
		e.Handle();
	}
}
void ZoomSys::assignStudent(){
	cout << "---Assign Student---\nEnter student id:" << endl;
	string studID;
	cin >> studID;
	cout << "Enter room id:" << endl;
	string roomID;
	cin >> roomID;

	int studIDnum = stoi(studID);
	int roomIDnum = stoi(roomID);
	Student* stud;
	try{
		stud = FindStudent(studIDnum);
		if(stud == nullptr)
			throw idexception();
		if(!(stud->GetRoomNum() == -1)){
			Room* RoomToRemoveFrom;
			RoomToRemoveFrom = FindRoom(stud->GetRoomNum());
			RoomToRemoveFrom->RemoveStudent(studIDnum);
		}

		Room* RoomToAdd;
		try{
			RoomToAdd = FindRoom(roomIDnum);
			RoomToAdd->AddStudent(*stud);
		}
		catch(Error& e){
			e.Handle();
		}
	}
	catch(Error& e){
		e.Handle();
	}
}


void ZoomSys::addRoom(){
	Room* NewRoom = new Room();
	if(!NewRoom){
		cout << "Memory Problem" << endl;
		this->~ZoomSys();
		exit(1);
	}
	Rooms.push_back(NewRoom);
	cout << "New room created" << endl;
}

void ZoomSys::splitRoom(){
	cout << "---Split Room---\nRoom id:" << endl;
	string Roomid;
	cin >> Roomid;
	int Roomidnum = stoi(Roomid);
	Room* RoomToSplit;
	try{
		RoomToSplit = FindRoom(Roomidnum);
		try{
			if(RoomToSplit->WasSplit())
				throw Splitbefore();
			cout << "1.Character split\n2.Size split" << endl;
			string ch;
			cin >> ch;
			try{
				if(!(ch == "1" || ch == "2"))
					throw Invaliddetails();
				Room* Left;
				Room* Right;
				if(ch == "1"){
					Left = new DiligentRoom();
					if(!Left){
						cout << "Memory Problem" << endl;
						this->~ZoomSys();
						exit(1);
					}
					Right = new LazyRoom();
					if(!Right){
						cout << "Memory Problem" << endl;
						this->~ZoomSys();
						exit(1);
					}
				}
				else{
					Left = new Room();
					if(!Left){
						cout << "Memory Problem" << endl;
						this->~ZoomSys();
						exit(1);
					}
					Right = new Room();
					if(!Right){
						cout << "Memory Problem" << endl;
						this->~ZoomSys();
						exit(1);
					}
				}
				RoomToSplit->Split(Left, Right, ch);
			}
			catch(Error& e){
				e.Handle();
			}
		}
		catch(Error& e){
			e.Handle();
		}
	}
	catch(Error& e){
		e.Handle();
	}
}



void ZoomSys::removeRoom(){
	cout << "---Remove Room---\nEnter room id:" << endl;
	string roomID;
	cin >> roomID;

	int roomIDnum = stoi(roomID);
	Room* RoomToRemove;
	try{
		RoomToRemove = FindRoom(roomIDnum);
		vector<Room*>::iterator it;
		for(it = Rooms.begin();it!= Rooms.end();++it){
			if((*it)->GetRoomNum() == RoomToRemove->GetRoomNum()){
				Rooms.erase(it);
				break;
			}
		}
		delete RoomToRemove;
	}
	catch(Error& e){
		e.Handle();
	}

}

void ZoomSys::work(){
	cout << "Enter the room you want to work:" << endl;
	string roomID;
	cin >> roomID;
	int roomIDnum = stoi(roomID);
	Room* RoomToWork;
	try{
		RoomToWork = FindRoom(roomIDnum);
		RoomToWork->Work();
	}
	catch(Error& e){
		e.Handle();
	}

}

void ZoomSys::sendMessage(){
	cout << "Enter the id:" << endl;
	string studID;
	cin >> studID;

	int studIDnum = stoi(studID);
	Student* stud;
	try{
		stud = FindStudent(studIDnum);
		if(stud == nullptr)
			throw idexception();
		cout << "Enter the message:" << endl;
		string Message;
		cin.ignore();
		getline(cin,Message);
		if(!(stud->GetRoomNum() == -1)){
			Room* RoomToMessage = FindRoom(stud->GetRoomNum());
			try{
				stud->Message(RoomToMessage, Message);
			}
			catch(Error& e){
				e.Handle();
			}
		}
	}
	catch(Error& e ){
		e.Handle();
	}
}

class less_than{
public:
	template <class T>
	bool operator()(const T& t1, const T& t2)const{
		return t1->GetRoomNum() < t2->GetRoomNum();
	}
};

void rec_add(vector <Room*>& rooms, Room* curr){
	rooms.push_back(curr);
	if(curr->GetLeft() != nullptr)
		rec_add(rooms,curr->GetLeft());
	if(curr->GetRight() != nullptr)
		rec_add(rooms,curr->GetRight());

	}
void ZoomSys::printRooms(){
	vector <Room*> SortedRooms;
	vector<Room*>::iterator it;
	for(it = Rooms.begin();it!= Rooms.end();++it){
		rec_add( SortedRooms ,(*it));
	}
	sort(SortedRooms.begin(),SortedRooms.end(),less_than());
	for(it = SortedRooms.begin();it!= SortedRooms.end();++it){
		(*it)->PrintRoom();
	}
}

void ZoomSys::printStudents(){
	cout << "First name, Last Name, ID, Avg, Room ID" << endl;
	vector<Student*>::iterator it;
	for(it = Students.begin();it!= Students.end();++it){
		(*it)->PrintStudent();
	}
}
void ZoomSys::printStudentDetails(){
	cout << "Enter student id:" << endl;
	string studID;
	cin >> studID;

	int studIDnum = stoi(studID);
	Student* stud;
	try{
		stud = FindStudent(studIDnum);
		if(stud == nullptr)
			throw idexception();
		stud->PrintStudentDetails();
	}
	catch(Error& e){
		e.Handle();
	}

}

ZoomSys::~ZoomSys() {
	while((int)Rooms.size() != 0){
		Room* temproom = Rooms[0];
		temproom->Empty();
		delete temproom;
		Rooms.erase(Rooms.begin());
	}

	while((int)Students.size() != 0){
		Student* tempstud = Students[0];
		delete tempstud;
		Students.erase(Students.begin());
	}
}
