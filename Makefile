CPP : g++
Exec: Robrawl

LibSfml : -lsfml-graphics -lsfml-window -lsfml-system

$(Exec) : Point.o Robot.o
	$(CPP) $(LibSfml) -o Point.o Robot.o

Point.o : Point.hpp
	$(CPP) $(LibSfml) -c Point.hpp 
	
Robot.o : Robot.cpp Robot.hpp

	$(CPP) $(LibSfml) -c Robot.cpp

clean :
	rm -f *.o $(Exec)
