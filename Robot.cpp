#include "Robot.hpp"

void Robot::deplace()
{


	int x = floor(VITESSE * cos(orientation) +
					position.getX());
	int y = floor(VITESSE * sin(orientation) +
					position.getY());

	position = Point(x,y);
}

void Robot::reoriente(int direction){

	orientation += direction*VITESSE_ROTATION ;
}


int main(){
	RenderWindow app;
	app.create(sf::VideoMode(800, 600, 32), "Ma premiere fenetre SFML ! ");

	Point p = Point(400,300);
	Robot rob = Robot("nom", p, 0, 100);

	while(app.isOpen()){

		Event event;
		while(app.pollEvent(event)){
			if(event.type == Event::Closed) app.close();


			if(Keyboard::isKeyPressed(Keyboard::Left)) rob.reoriente(1);
			if(Keyboard::isKeyPressed(Keyboard::Right)) rob.reoriente(-1);
			printf("reor\n" );
		}
		rob.deplace();
		int x = rob.getPosition().getX();
		int y = rob.getPosition().getY();

		printf("X : %d | Y : %d |orient : %f\n",x,y,rob.getOrientation());

		app.clear(Color::Black);


		CircleShape circle(13); // Create circle
    circle.setPosition(x - 13, y - 13); //  We must convert the center position to the top left point position
		circle.setFillColor(Color::Red);

    app.draw(circle);

		app.display();
}

		return 0;
	}
