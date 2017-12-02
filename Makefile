all:	driver

driver:	driver.o offeringsObj.o	offeringsParser.o
	g++ driver.o offeringsObj.o offeringsParser.o -o schedule.exe

driver.o: driver.cpp
	g++ -c driver.cpp

offeringsObj.o:	offeringsObj.cpp offeringsObj.h
	g++ -c offeringsObj.cpp

offeringsParser.o: offeringsParser.cpp offeringsParser.h
	g++ -c offeringsParser.cpp

clean:
	rm -f *.o schedule.exe
