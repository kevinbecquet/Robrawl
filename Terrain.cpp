#include "Terrain.hpp"

#include <SFML/Graphics.hpp>
using namespace sf;
using namespace std;




//fonction qui charge la police d'écriture
//Est-ce qu'il ne faudrait pas créer une classe qui s'occupe de la gestion de fenetre?
Font loadFont()
{
	Font font;
	if(!font.loadFromFile("Font/Tapestry-Regular.ttf"))
		throw runtime_error("Font file opening unsuccessful\n");
	else
		return font;
}

Text writetxt( string text, size_t size, Color color)
{
	Text* txt = new Text;
	//charge la police d'écrire
	txt->setFont(loadFont());
	//Configure le texte pour l'afficher comme souhaité
	txt->setString(text); //texte à écrire

	txt->setCharacterSize(size); //taille du texte

	txt->setFillColor(color); //Couleur du texte

	return *txt;
}




int main(){

	Robot rob = Robot("nom", Point(400,300), 1, 100);
	Terrain* t = new Terrain(800,600,"Fenetre SFML");

	RenderWindow app;
	app.create(sf::VideoMode(t->getLon(), t->getLarg(), 32), "Ma premiere fenetre SFML ! ");

	while(app.isOpen()){

		Event event;
		while(app.pollEvent(event)){
			if(event.type == Event::Closed) app.close();

			if(Keyboard::isKeyPressed(Keyboard::Escape)){
				printf("The game has been stopped by the user\n");
				return 0;
			}
			if(Keyboard::isKeyPressed(Keyboard::D)) rob.reoriente(1);
			if(Keyboard::isKeyPressed(Keyboard::Q)) rob.reoriente(-1);

		}
		rob.deplace();
		double x = rob.getPosition().getX();
		double y = rob.getPosition().getY();

		Text txt = writetxt("Hello world", 36, Color::Yellow);

		app.clear(Color::Black);

		CircleShape circle(8); // Create circle
    circle.setPosition(floor(x - 13), floor(y - 13)); //  We must convert the center position to the top left point position
		circle.setFillColor(Color::Red);

    app.draw(circle);
		//app.draw(txt);
		app.display();
	}

		return 0;
}

/*
int main()
{
	//Je test l'ouverture d'une fenetre avec sfml
	Terrain t(800,600,"Hello fighters!");
	//Evenement à gérer
	Event e;
	//text à écrire
	Text txt = writetxt("Hello world", 36, Color::Yellow);
	std::cout<<"ok"<<std::endl;
	Text txt2;

	//writetxt(txt,"Hello world", 36, Color::Yellow);
	//writetxt(txt2,"Today is the day!",20/*,Color::Purple,);

	while(t.jeuEnCours())
	{
		t.endOfGame(e);


		t.getFenetre().clear(Color::Black);
		t.getFenetre().draw(txt);
		t.getFenetre().display();

		//t.ajoutElemFenetre(Color::Green,txt);
		//t.ajoutElemFenetre(Color::Black,txt2);
	}

	return 0;
}
*/
