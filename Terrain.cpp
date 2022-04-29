#include "Terrain.hpp"

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

void writetxt(Text txt, string text, size_t size /*Color color,*/)
{
	//charge la police d'écrire
	txt.setFont(loadFont());
	//Configure le texte pour l'afficher comme souhaité
	txt.setString(text); //texte à écrire
	
	txt.setCharacterSize(size); //taille du texte
	
	//txt.setFillColor(color); //Couleur du texte
	
}

int main()
{
	//Je test l'ouverture d'une fenetre avec sfml
	Terrain t(800,600,"Hello fighters!");
	//Evenement à gérer
	Event e;
	//text à écrire
	Text txt;
	Text txt2;
	
	writetxt(txt,"Hello world",36/*Color::Yellow,*/);
	writetxt(txt2,"Today is the day!",20/*,Color::Purple,*/);
	
	while(t.jeuEnCours())
	{
		t.endOfGame(e);
		
		//t.ajoutElemFenetre(Color::Green,txt);
		t.ajoutElemFenetre(Color::Black,txt2);
	}
	
	return 0;
}
