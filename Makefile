all:	driver

driver:	driver.o offeringsObj.o	offeringsParser.o plannedObj.o
	g++ driver.o offeringsObj.o offeringsParser.o plannedObj.o -o schedule.exe

driver.o: driver.cpp
	g++ -c driver.cpp

offeringsObj.o:	offeringsObj.cpp offeringsObj.h
	g++ -c offeringsObj.cpp

offeringsParser.o: offeringsParser.cpp offeringsParser.h
	g++ -c offeringsParser.cpp

plannedObj.o: plannedObj.cpp plannedObj.h
	g++ -c plannedObj.cpp

clean:
	rm -f *.o schedule.exe
