all:	driver

driver:	driver.o offeringsObj.o	offeringsParser.o plannedObj.o course.o credit.o courseNode.o requirementsObj.o requirementsParser.o 
	g++ driver.o offeringsObj.o offeringsParser.o plannedObj.o course.o credit.o courseNode.o requirementsObj.o requirementsParser.o -o schedule.exe

driver.o: driver.cpp
	g++ -c driver.cpp

offeringsObj.o:	offeringsObj.cpp offeringsObj.h
	g++ -c offeringsObj.cpp

offeringsParser.o: offeringsParser.cpp offeringsParser.h
	g++ -c offeringsParser.cpp

plannedObj.o: plannedObj.cpp plannedObj.h
	g++ -c plannedObj.cpp

course.o: course.cpp course.h
	g++ -c course.cpp

credit.o: credit.cpp credit.h
	g++ -c credit.cpp

courseNode.o: courseNode.cpp courseNode.h
	g++ -c courseNode.cpp

requirementsObj.o:: requirementsObj.cpp requirementsObj.h
	g++ -c requirementsObj.cpp

requirementsParser.o: requirementsParser.cpp requirementsParser.h
	g++ -c requirementsParser.cpp

clean:
	rm -f *.o schedule.exe
