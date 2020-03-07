CXXFLAGS += --std=c++17
GTKFLAGS = `/usr/bin/pkg-config gtkmm-3.0 --cflags --libs`

all: club

club: main.o login.o mainwin.o club.o person.o customer.o 
	$(CXX) $(CXXFLAGS) main.o login.o mainwin.o club.o person.o customer.o  $(GTKFLAGS) -o club
main.o: main.cpp *.h
	$(CXX) $(CXXFLAGS) -c main.cpp $(GTKFLAGS) -o main.o

login.o: login.cpp *.h
	$(CXX) $(CXXFLAGS) -c login.cpp $(GTKFLAGS) -o login.o
mainwin.o: mainwin.cpp *.h 
	$(CXX) $(CXXFLAGS) -c mainwin.cpp $(GTKFLAGS) -o mainwin.o
club.o: club.cpp *.h
	$(CXX) $(CXXFLAGS) -c club.cpp -o club.o
person.o: person.cpp *.h
	$(CXX) $(CXXFLAGS) -c person.cpp -o person.o
customer.o: customer.cpp *.h
	$(CXX) $(CXXFLAGS) -c customer.cpp -o customer.o
clean:
	rm -f *.o *.gch club


