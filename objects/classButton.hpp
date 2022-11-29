#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>

class boton {
private:
	ALLEGRO_MOUSE_STATE mouse_position;
	ALLEGRO_BITMAP* button_pressed;
	ALLEGRO_BITMAP* button_without_pressing;

	int positionX;
	int positionY;
	int widht;
	int height;


public:

	boton(const char* = "", const char* = "", int = 0, int = 0, int = ALLEGRO_ALIGN_RIGHT);

	inline void setPosX(int posX, int alineation);
	inline void setPosY(int posY) { this->positionY = posY; }
	inline void setPos(int posX, int posY);

	inline int getPosX() { return positionX; }
	inline int getPosY() { return positionY; }
	inline float getWidht() { return widht; }
	inline float getHeight() { return height; }
	inline int getPosX_With_Widht() { return positionX + widht; }
	inline int getPosY_With_Height() { return positionY + height; }

	void print();
	bool isAboveButton();
	bool clickAboveButton(ALLEGRO_EVENT);


	~boton();

};


boton::boton(const char* file_name_button_pressed, const char* file_name_button_witout_pressing, int positionX, int positionY, int alineation) {

	button_pressed = al_load_bitmap(file_name_button_pressed);
	button_without_pressing = al_load_bitmap(file_name_button_witout_pressing);
	this->positionY = positionY;
	this->widht = al_get_bitmap_width(button_without_pressing);
	this->height = al_get_bitmap_height(button_without_pressing);

	switch (alineation) {
	case ALLEGRO_ALIGN_LEFT:
		this->positionX = positionX - widht;
		break;
	case ALLEGRO_ALIGN_CENTRE:
		this->positionX = positionX - (widht / 2);
		break;
	case ALLEGRO_ALIGN_RIGHT:
		this->positionX = positionX;
		break;
	}

}
void boton::setPos(int posX, int posY) {

	this->positionX = posX;
	this->positionX = posY;
}
void boton::setPosX(int posX, int alineation) {

	switch (alineation) {
	case ALLEGRO_ALIGN_LEFT:
		this->positionX = posX - widht;
		break;
	case ALLEGRO_ALIGN_CENTRE:
		this->positionX = posX - (widht / 2);
		break;
	case ALLEGRO_ALIGN_RIGHT:
		this->positionX = posX;
		break;
	}
}

bool boton::isAboveButton() {
	al_get_mouse_state(&mouse_position);
	return (mouse_position.x >= positionX and mouse_position.x <= positionX + widht
		and mouse_position.y >= positionY and mouse_position.y <= positionY + height);
}

void boton::print() {


	if (isAboveButton()) {
		al_draw_bitmap(button_pressed, positionX, positionY, NULL);
	}
	else {
		al_draw_bitmap(button_without_pressing, positionX, positionY, NULL);
	}
}

bool boton::clickAboveButton(ALLEGRO_EVENT eventoAnalizar) {

	if (eventoAnalizar.mouse.button == 1) {	// Analiza si es el click izquierdo.
		return(isAboveButton());			// Retorna si esta encima del boton
	}
	return false;

}

boton::~boton() {
	al_destroy_bitmap(button_pressed);
	al_destroy_bitmap(button_without_pressing);
}