#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>

class boton {
private:
	ALLEGRO_MOUSE_STATE mouse_position;
	ALLEGRO_BITMAP* button_pressed;
	ALLEGRO_BITMAP* button_without_pressing;

	int positionX;
	int positionY;
	float widht;
	float lenght;

	void init();

public:

	boton(const char* = "", const char* = "",int = 0, int = 0,float = 0, float = 0);

	inline void setPosX(int posX) { this->positionX = posX; }
	inline void setPosY(int posY) { this->positionY = posY; }
	inline void setWidht(float widht) { this->widht = widht; }
	inline void setLenght(float lenght) { this->lenght = lenght; }

	inline int getPosX() { return positionX; }
	inline int getPosY() { return positionY; }
	inline float getWidht() { return widht; }
	inline float getLenght() { return lenght; }


	void print();
	bool isAboveButton();
	bool clickAboveButton(ALLEGRO_EVENT);


	~boton();

};

void boton::init() {

	if (!al_is_image_addon_initialized() ){
		al_init_image_addon();
	}
}


boton::boton(const char* file_name_button_pressed, const char* file_name_button_witout_pressing, int positionX, int positionY, float widht, float lenght) {

	init();

	button_pressed = al_load_bitmap(file_name_button_pressed);
	button_without_pressing = al_load_bitmap(file_name_button_witout_pressing);
	this->positionX = positionX;
	this->positionY = positionY;
	this->widht = widht;
	this->lenght = lenght;

}

bool boton::isAboveButton() {
	al_get_mouse_state(&mouse_position);
	return (mouse_position.x >= positionX and mouse_position.x <= positionX + widht and mouse_position.y >= positionY and mouse_position.y <= positionY + lenght);
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
	if (eventoAnalizar.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
	return(eventoAnalizar.mouse.x >= positionX and eventoAnalizar.mouse.x <= positionX + widht
		and eventoAnalizar.mouse.y >= positionY and eventoAnalizar.mouse.y <= positionY + lenght);
	}
	return false;

}

boton::~boton() {
	al_destroy_bitmap(button_pressed);
	al_destroy_bitmap(button_without_pressing);
	al_uninstall_mouse();
}