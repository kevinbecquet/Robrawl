CPP = g++
Exec= Robrawl
LibSfml = -lsfml-graphics -lsfml-window -lsfml-system -lsfml-network -lsfml-audio
CPPFLAGS=-std=c++14

$(Exec) : Obstacle.o Robot.o  Terrain.o SFMLManager.o
	$(CPP) -o Robrawl Robot.o Terrain.o SFMLManager.o Obstacle.o $(LibSfml) -g

Robot.o : Robot.cpp Robot.hpp MovingElt.hpp
	$(CPP) $(CPPFLAGS) -Wall -c Robot.cpp -g


Obstacle.o : Obstacle.cpp Obstacle.hpp 
	$(CPP) $(CPPFLAGS) -Wall -c Obstacle.cpp -g
	

Terrain.o : Terrain.cpp Terrain.hpp MovingElt.hpp
	$(CPP)  $(CPPFLAGS) -c Terrain.cpp -g

SFMLManager.o : SFMLManager.cpp SFMLManager.hpp Obstacle.hpp Robot.hpp MovingElt.hpp
	$(CPP) $(CPPFLAGS) -Wall -c SFMLManager.cpp -g

clean :
	rm -f *.o $(Exec)
