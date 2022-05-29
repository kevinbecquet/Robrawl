CPP = g++
Exec= Robrawl
LibSfml = -lsfml-graphics -lsfml-window -lsfml-system -lsfml-network -lsfml-audio
CPPFLAGS=-std=c++14

$(Exec) : Robot.o Obstacle.o Terrain.o Joueur.o SFMLManager.o
	$(CPP) -o Robrawl Robot.o Terrain.o SFMLManager.o Obstacle.o Joueur.o $(LibSfml)

Robot.o : Robot.cpp Robot.hpp 
	$(CPP) $(CPPFLAGS) -Wall -c Robot.cpp 


Obstacle.o : Obstacle.cpp Obstacle.hpp Element.hpp
	$(CPP) $(CPPFLAGS) -Wall -c Obstacle.cpp
	
Joueur.o : Joueur.cpp Joueur.hpp Element.hpp
	$(CPP)  $(CPPFLAGS) -Wall -c Joueur.cpp 
	

Terrain.o : Terrain.cpp Terrain.hpp Element.hpp
	$(CPP)  $(CPPFLAGS) -c Terrain.cpp 

SFMLManager.o : SFMLManager.cpp SFMLManager.hpp Joueur.hpp Obstacle.hpp Robot.hpp
	$(CPP) $(CPPFLAGS) -Wall -c SFMLManager.cpp

clean :
	rm -f *.o $(Exec)
