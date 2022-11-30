#include <string>
#include <iostream>
#include <vector>
#include <random>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>

using namespace std;

enum PALO{DIAMOND = 1, HEART, SPADES, CLUBS};

class Card {
private:

	ALLEGRO_BITMAP* front;
	ALLEGRO_BITMAP* back;
	int number;		// Numero de la carta
	int suit;		// Palo de la carta
	bool color;		// Rojo = True \\ Negro = False
	bool isHidden;

	string BMP_direction = "resources/OwnCards/";



public:
	Card();
	Card(int number, int suit);
	void mostrar();
	bool getColor(){ return color; }
	int getN() { return number; }
	void Voltear() { isHidden = false; }
};

class Baraja {
	private:
		vector <Card> mazo;
    public:
		Baraja();
		void MostrarC(int);
};

Card::Card() {
	this->number = 0;
	this->suit = 0;
	this->front = NULL;
	this->back = al_load_bitmap("resources/OwnCards/BackCard.png");
	this->isHidden = true;
}

Card::Card(int suit, int number) {
	this->number = number;
	this->suit = suit;

	switch (suit){
	case DIAMOND:
		this->color = true;
		break;
	case HEART:
		this->color = true;
		break;
	case SPADES:
		this->color = false;
		break;
	case CLUBS:
		this->color = false;
		break;
	}

	BMP_direction += to_string(suit) + "_" + to_string(number) + ".png";

	front = al_load_bitmap( BMP_direction.c_str() );
	back = al_load_bitmap("resources/OwnCards/BackCard.png");
	isHidden = true;
}

void Card::mostrar() {
	al_draw_bitmap(this->front, 1080 / 2, 720 / 2, 0);
}

Baraja::Baraja() {

	for (int i = 1; i <= 4; i++) {
		for (int j = 1; j <= 13; j++) {
			mazo.push_back(Card(i, j));
		}
	}

	std::random_device rd;
	std::mt19937 s(rd()); //mersenne twister engine for shuffle

	std::shuffle(mazo.begin(), mazo.end(), rd); //vector mezclado
}

void Baraja::MostrarC(int cont) {
	mazo[cont].mostrar();
}




