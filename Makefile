CPP = g++
Exec= Robrawl
LibSfml = -lsfml-graphics -lsfml-window -lsfml-system
CPPFLAGS=-std=c++14

$(Exec) : Point.o Robot.o Obstacle.o Terrain.o Joueur.o
	$(CPP) -o Robrawl Point.o Robot.o Terrain.o Obstacle.o Joueur.o $(LibSfml)

Robot.o : Robot.cpp Robot.hpp Point.hpp
	$(CPP) $(CPPFLAGS) -Wall -c Robot.cpp 


Obstacle.o : Obstacle.cpp Obstacle.hpp Point.hpp
	$(CPP) $(CPPFLAGS) -Wall -c Obstacle.cpp

Terrain.o : Terrain.cpp Terrain.hpp
	$(CPP)  $(CPPFLAGS) -c Terrain.cpp 
	
Joueur.o : Joueur.cpp Joueur.hpp
	$(CPP)  $(CPPFLAGS) -Wall -c Joueur.cpp 

clean :
	rm -f *.o $(Exec)
