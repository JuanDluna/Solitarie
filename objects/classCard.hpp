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
};

class Baraja {
	private:
		vector <Card> mazo;
    public:
		Baraja();
		void barajear();
		void mostrar();
};

Card::Card() {
	back = al_load_bitmap("resources/OwnCards/BackCard.png");

	isHidden = true;
}

Card::Card(int number, int suit) {
	this->number = number;
	this->suit = suit; 

	switch (suit){
	case DIAMOND:
		this->color = true;
		this->suit = DIAMOND;
		break;
	case HEART:
		this->color = true;
		this->suit = HEART;
		break;
	case SPADES:
		this->color = false;
		this->suit = SPADES;
		break;
	case CLUBS:
		this->color = false;
		this->suit = CLUBS;
		break;
	}

	BMP_direction += to_string(suit) + "_", to_string(number) + ".png";

	front = al_load_bitmap(BMP_direction.c_str());
}

Baraja::Baraja() {
	int c = 0;
	for (int i = 1; i <= 4; i++) {
		for (int j = 1; j <= 13; j++) {
			mazo.push_back(Card(i, j));
		}
	}

	std::random_device rd;
	std::mt19937 s(rd()); //mersenne twister engine for shuffle

	std::shuffle(mazo.begin(), mazo.end(), rd); //vector mezclado
}


