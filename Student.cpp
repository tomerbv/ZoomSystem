#include "Student.h"

Student::Student(int id,const string first, const string last, float avg)
{
	if(avg > 100 || avg < 0 || id < 0)
		throw Invaliddetails();
	this->id = id;
	this->avg = avg;
	this->first_name = first;
	this->last_name = last;
	this->RoomNum = -1;
}


void Student::PrintStudent(){
	cout << *this;
}

void Student::PrintStudentDetails(){
	cout << *this << "---Messages---" << endl;
	vector<string>::iterator it;
	for(it = messages.begin(); it!=messages.end(); ++it){
		cout << *it << endl;
	}
}

ostream& operator<<(ostream& out, Student& other){
	out << other.first_name << " " << other.last_name <<" " << other.id << " "<< other.avg << " " << other.RoomNum << endl;
	return out;
}

