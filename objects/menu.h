#pragma once
#include <allegro5/allegro5.h>
#include <allegro5/allegro_color.h>
#include "classButton.hpp"


enum OPC{_PLAY_ = 1 ,_HTP_,_CLOSE_};

class menu {
	ALLEGRO_DISPLAY* display;
	ALLEGRO_TIMER* timer;
	ALLEGRO_EVENT_QUEUE* colaEventos;
	ALLEGRO_COLOR fondo = al_color_name("black");
	ALLEGRO_EVENT evento;
	ALLEGRO_BITMAP* logo_BMP;

	boton play;
	boton HTP;
	boton close;

	int ancho, alto;

	bool redraw;

public:
	menu(ALLEGRO_DISPLAY*);
	int run();
};

menu::menu(ALLEGRO_DISPLAY* display) {
	this->display = display;
	this->timer = al_create_timer(1.0 / 30.0);
	this->colaEventos = al_create_event_queue();
	this->logo_BMP = al_load_bitmap("resources/Solitarie2022-Logo.png");

	this->ancho = al_get_display_width(display);
	this->alto = al_get_display_height(display);

	this->redraw = true;

	this->play = boton("resources/ButtonPlayPressing.png", 
		               "resources/ButtonPlayWithoutPressing.png",
		                ancho / 2, alto / 2, ALLEGRO_ALIGN_CENTER);
	this->HTP =  boton("resources/Button_HTP_Pressing.png",
					   "resources/Button_HTP_WithoutPressing.png", 
		                ancho / 2, play.getPosY_With_Height() + 20, ALLEGRO_ALIGN_CENTER);
	this->close = boton("resources/ButtonClosePressing.png",
		                "resources/ButtonCloseWithoutPressing.png",
		                ancho / 2, HTP.getPosY_With_Height() + 20, ALLEGRO_ALIGN_CENTER);
}

int menu::run(){
	while (1) {

		al_wait_for_event(colaEventos, &evento);

		al_clear_to_color(fondo);

		al_draw_bitmap(logo_BMP, (ancho / 2) - (al_get_bitmap_width(logo_BMP) / 2), alto / 12, 0);
		play.print();
		HTP.print();
		close.print();


		if (evento.type == ALLEGRO_EVENT_TIMER) //TODO falta implementar  cuando el redraw será igual a false 
			redraw = true;

		switch (evento.type) {
		case ALLEGRO_EVENT_DISPLAY_CLOSE:
			return _CLOSE_;
			break;
		case ALLEGRO_EVENT_MOUSE_AXES:
			play.print();
			HTP.print();
			close.print();
			break;
		case ALLEGRO_EVENT_MOUSE_BUTTON_DOWN:
			if (play.clickAboveButton(evento))
				return _PLAY_;
			if (HTP.clickAboveButton(evento))
				return _HTP_;
			if (close.clickAboveButton(evento))
				return _CLOSE_;
			break;
		}


		al_flip_display();

	}
}
