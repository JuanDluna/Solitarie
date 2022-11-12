#include<iostream>
#include<allegro5/allegro_color.h>
#include"objects/classButton.hpp"

using namespace std;

int main() {

	al_init();
	al_install_mouse();

	bool inGame = true;

	ALLEGRO_DISPLAY* display = al_create_display(1080, 720);
	ALLEGRO_EVENT_QUEUE* colaEventos = al_create_event_queue();
	ALLEGRO_COLOR fondo = al_color_name("forestgreen");
	ALLEGRO_EVENT evento;	


	boton play("resources/ButtonPlayPressing.png", "resources/ButtonPlayWithoutPressing.png", (1080 / 2) - 155, (720 / 2) + 50 , 310, 90);

	al_register_event_source(colaEventos, al_get_display_event_source(display));
	al_register_event_source(colaEventos, al_get_mouse_event_source() );

	while (inGame) {
		al_wait_for_event(colaEventos, &evento);

		al_clear_to_color(fondo);

		play.print();

		switch (evento.type){
		case ALLEGRO_EVENT_DISPLAY_CLOSE:
			inGame = false;
			break;
		case ALLEGRO_EVENT_MOUSE_AXES:
			play.print();
			
		case ALLEGRO_EVENT_MOUSE_BUTTON_DOWN:
			if (play.clickAboveButton(evento)) {
				cout << "Come pija cagada\n";
			}
		}


		al_flip_display();
		
	}



	al_destroy_display(display);
	al_destroy_event_queue(colaEventos);



}