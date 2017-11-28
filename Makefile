all:	driver

driver:	driver.o Requirements.o requirements_parser.o 
	g++ driver.o Requirements.o requirements_parser.o -o schedule.exe

driver.o: driver.cpp
	g++ -c driver.cpp

Requirements.o:	Requirements.cpp Requirements.h
	g++ -c Requirements.cpp

requirements_parser.o: requirements_parser.cpp Requirements.h requirements_parser.h
	g++ -c requirements_parser.cpp

clean:
	rm -f *.o schedule.exe
