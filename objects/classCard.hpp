#include <string>
#include "classButton.hpp"

using namespace std;

enum PALO { DIAMOND = 1, HEART, SPADES, CLUBS };

class Card:public boton{
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
	Card(int suit, int number, int posX, int posY);

	bool getColor() { return color; }
	int getNumber() { return number; }
	bool getIsHidden() { return isHidden; }

	void setIsHidden(bool isHidden) { this->isHidden = isHidden; }


	void Voltear() { isHidden = !isHidden; }
	void print() override;
	void mover();
	Card operator= (const Card& carta);

};

Card::Card() {
	this->back = al_load_bitmap("resources/OwnCards/BackCard.png");
	this->width = al_get_bitmap_width(back);
	this->height = al_get_bitmap_height(back);
	this->front = nullptr;

	this->number = 1;
	this->suit = 1;
	this->color = false;
	this->isHidden = true;
	
	this->positionX = 0;
	this->positionY = 0;
}

Card::Card(int suit, int number, int posX, int posY):boton(posX, posY){
	this->number = number;
	this->suit = suit;
	this->color = false;

	switch (suit) {
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

	front = al_load_bitmap(BMP_direction.c_str());
	back = al_load_bitmap("resources/OwnCards/BackCard.png");
	width = al_get_bitmap_width(front);
	height = al_get_bitmap_height(front);
	isHidden = true;

	return;
}

void Card::print() {
	if (isHidden) {
		al_draw_bitmap(back, boton::positionX, boton::positionY, 0);
		return;
	}
	al_draw_bitmap(front, positionX, positionY, 0);
	return;
}

void Card::mover() {
	ALLEGRO_MOUSE_STATE state;
	al_get_mouse_state(&state);
	if (!isHidden and isAboveButton() and state.buttons == 1) 
		setPos(state.x - 100, state.y - 100);
}

Card Card::operator=(const Card& carta) {

	this->front = al_clone_bitmap(carta.front);
	this->number = carta.number;
	this->suit = carta.suit;
	this->color = carta.color;
	this->isHidden = carta.isHidden;

	this->positionX = carta.positionX;
	this->positionY = carta.positionY;
	this->width = carta.width;
	this->height = carta.height;
	return *this;
}

