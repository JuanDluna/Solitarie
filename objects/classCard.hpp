#include <string>
#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>

using namespace std;

//TODO Cambio de ventana en menu a juego
//TODO Construir baraja con shuffle
//

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
	Card(int number, int suit);
};

class Baraja {
	private:
		Card mazo[52];
    public:
		Baraja();
		void barajear();
		void mostrar();
};

Card::Card() {
	//back = al_load_bitmap("resources/PokerCards/[60x84]/back.png");

	isHidden = true;
}

Card::Card(int number, int suit) {
	this->number = number;
	this->suits = suit; 

	switch (suit){
	case 0:
		this->color = true;
		this->suits = 'd';
		break;
	case 1:
		this->color = true;
		this->suits = 'h';
		break;
	case 2:
		this->color = false;
		this->suits = 's';
		break;
	case 3:
		this->color = false;
		this->suits = 'c';
		break;
	}

	BMP_direction += to_string(suit) + "_", to_string(number) + ".png";

	front = al_load_bitmap(BMP_direction.c_str());
}

Baraja::Baraja() {
	int c = 0;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 13; j++) {
			mazo[c] = Card();
			mazo[c] = Card(j,i);
			c++;
		}
	}
}


