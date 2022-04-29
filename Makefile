CPP = g++
Exec= Robrawl
LibSfml = -lsfml-graphics -lsfml-window -lsfml-system
CPPFLAGS=-std=c++14

$(Exec) : Point.o Robot.o Obstacle.o Terrain.o Joueur.o
	$(CPP) -o Robrawl Point.o Robot.o Terrain.o Obstacle.o Joueur.o $(LibSfml)

Point.o : Point.hpp Point.cpp
	$(CPP) $(CPPFLAGS) -Wall -c Point.cpp 
	
Robot.o : Robot.cpp Robot.hpp	
	$(CPP) $(CPPFLAGS) -Wall -c Robot.cpp 


Obstacle.o : Obstacle.cpp Obstacle.hpp
	$(CPP) $(CPPFLAGS) -Wall -c Obstacle.cpp

Terrain.o : Terrain.cpp Terrain.hpp
	$(CPP)  $(CPPFLAGS) -c Terrain.cpp 
	
Joueur.o : Joueur.cpp Joueur.hpp
	$(CPP)  $(CPPFLAGS) -Wall -c Joueur.cpp 

clean :
	rm -f *.o $(Exec)
