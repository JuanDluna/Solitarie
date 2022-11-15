#include <string>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>

using namespace std;

enum PALO{DIAMOND, HEART, SPADES, CLUBS};

class Card {
private:
	ALLEGRO_BITMAP* front;
	ALLEGRO_BITMAP* back;
	int number;		// Numero de la carta
	char suits;		// Palo de la carta
	bool color;		// Rojo = True \\ Negro = False
	bool isHidden;

	string BMP_direction = "resources/PokerCards/[60x84]/";



public:
	Card();
	Card(int number, char suit);

};

Card::Card() {
	back = al_load_bitmap("resources/PokerCards/[60x84]/back.png");
	isHidden = true;
}

Card::Card(int number, char suit) {
	this->number = number;
	this->suits = suit;

	switch (suit){
	case 'd':
		this->color = true;
		break;
	case 'h':
		this->color = true;
		break;
	case 's':
		this->color = false;
		break;
	case 'c':
		this->color = false;
		break;
	}

	BMP_direction += to_string(number) + suit + ".png";

	front = al_load_bitmap(BMP_direction.c_str());
}