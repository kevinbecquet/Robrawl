CPP : g++
Exec: Robrawl

$(Exec) : Point.o Robot.o
	$(CPP) -o Point.o Robot.o

Point.o : Point.hpp
	$(CPP) -c Point.hpp 
	
Robot.o : Robot.cpp Robot.hpp

	$(CPP) -c Robot.cpp

clean :
	rm -f *.o $(Exec)
