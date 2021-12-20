output : Assignment5.o ZoomSys.o DiligentStudent.o ResponsibleStudent.o LazyStudent.o Student.o Room.o
	g++ Assignment5.o ZoomSys.o DiligentStudent.o ResponsibleStudent.o LazyStudent.o Student.o Room.o -o output.exe
	
Assignment5.o : Assignment5.cpp ZoomSys.h DiligentRoom.h Room.h LazyRoom.h DiligentStudent.h Student.h idexception.h Error.h Invaliddetails.h Splitbefore.h Studentpermissions.h LazyStudent.h ResponsibleStudent.h
	g++ -c Assignment5.cpp

ZoomSys.o: ZoomSys.cpp ZoomSys.h DiligentRoom.h Room.h LazyRoom.h DiligentStudent.h Student.h idexception.h Error.h Invaliddetails.h Splitbefore.h Studentpermissions.h LazyStudent.h ResponsibleStudent.h
	g++ -c ZoomSys.cpp

DiligentStudent.o : DiligentStudent.cpp DiligentStudent.h Student.h Error.h idexception.h Invaliddetails.h Splitbefore.h Studentpermissions.h
	g++ -c DiligentStudent.cpp

ResponsibleStudent.o : ResponsibleStudent.cpp ResponsibleStudent.h Student.h Error.h idexception.h Invaliddetails.h Splitbefore.h Studentpermissions.h
	g++ -c ResponsibleStudent.cpp	
	
LazyStudent.o : LazyStudent.cpp LazyStudent.h Student.h Error.h idexception.h Invaliddetails.h Splitbefore.h Studentpermissions.h
	g++ -c LazyStudent.cpp
	
Student.o : Student.cpp Student.h Error.h idexception.h Invaliddetails.h Splitbefore.h Studentpermissions.h
	g++ -c Student.cpp

Room.o: Room.cpp Room.h Student.h idexception.h Error.h Invaliddetails.h Splitbefore.h Studentpermissions.h
	g++ -c Room.cpp 
	
clean:
	rm -f *.o output.exe
	

