CPP = g++
Exec= Robrawl
LibSfml = -lsfml-graphics -lsfml-window -lsfml-system

$(Exec) : Point.o Robot.o Obstacle.o Terrain.o Joueur.o
	$(CPP) -o Robrawl Point.o Robot.o Terrain.o Obstacle.o Joueur.o $(LibSfml)

Point.o : Point.hpp Point.cpp
	$(CPP) -Wall -c Point.cpp $(LibSfml)
	
Robot.o : Robot.cpp Robot.hpp	
	$(CPP) -Wall -c Robot.cpp $(LibSfml)


Obstacle.o : Obstacle.cpp Obstacle.hpp
	$(CPP) -Wall -c Obstacle.cpp $(LibSfml)

Terrain.o : Terrain.cpp Terrain.hpp
	$(CPP) $(LibSfml) -c Terrain.cpp $(LibSfml)
	
Joueur.o : Joueur.cpp Joueur.hpp
	$(CPP) -Wall -c Joueur.cpp $(LibSfml)

clean :
	rm -f *.o $(Exec)
