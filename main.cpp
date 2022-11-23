
#include <iostream>
#include"objects/classButton.hpp"
#include"objects/classCard.hpp"

#include <allegro5/allegro5.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_color.h>

using namespace std;

/*
	TODO (Maniana):
		Escena principal de juego
		Establecer clase carta

	TODO (Semana):
		Lista cartas
		Movimiento de carta

	TODO(General):
		Pila carta
		Menu 1 o 3 cartas
		Logica restante de juego

*/

//TODO Construir baraja con shuffle

int newScene(ALLEGRO_EVENT_QUEUE*);
void inits();
void setNewPos(boton, ALLEGRO_EVENT);
void HTP_dialog(ALLEGRO_DISPLAY* display);

int main() {

	Baraja sol();

	inits();

	bool inGame = true;

	ALLEGRO_TIMER* timer = al_create_timer(1.0 / 30.0);
	ALLEGRO_DISPLAY* display = al_create_display(1080, 720);
	al_set_display_icon(display, al_load_bitmap("resources/Solitarie2022-AppLogo.png"));
	ALLEGRO_EVENT_QUEUE* colaEventos = al_create_event_queue();
	ALLEGRO_COLOR fondo = al_color_name("black");
	ALLEGRO_EVENT evento;

	ALLEGRO_BITMAP* logo_BMP = al_load_bitmap("resources/Solitarie2022-Logo.png");

	int ancho = al_get_display_width(display);
	int alto = al_get_display_height(display);

	boton play("resources/ButtonPlayPressing.png", "resources/ButtonPlayWithoutPressing.png", ancho / 2, alto / 2, ALLEGRO_ALIGN_CENTER);
	boton HTP("resources/Button_HTP_Pressing.png", "resources/Button_HTP_WithoutPressing.png", ancho / 2, play.getPosY_With_Height() + 20, ALLEGRO_ALIGN_CENTER);
	boton close("resources/ButtonClosePressing.png", "resources/ButtonCloseWithoutPressing.png", ancho / 2, HTP.getPosY_With_Height() + 20, ALLEGRO_ALIGN_CENTER);
	// La clase boton, personaliza el boton con las imagenes proporcionadas, la posicion en X y Y ademas de la alineacion conforme a esa posicion
	// Si la alineacion es al centro es0 significara que la mitad estara en la posicion X proporcionada
	// Si la alineacion es a la derecha, la imagen estara por la derecha del punto X proporcionado 
	// Y por ultimo si la alineacion es a la izquierda, la imagen estar� por la izquierda del punto X proporcionado.

	al_register_event_source(colaEventos, al_get_display_event_source(display));
	al_register_event_source(colaEventos, al_get_mouse_event_source());
	bool redraw = true;
	al_start_timer(timer);
	while (inGame) {

		al_wait_for_event(colaEventos, &evento);

		al_clear_to_color(fondo);

		al_draw_bitmap(logo_BMP, (ancho / 2) - (al_get_bitmap_width(logo_BMP) / 2), alto / 12, 0);
		play.print();
		HTP.print();
		close.print();


		if (evento.type == ALLEGRO_EVENT_TIMER) //TODO falta implementar  cuando el redraw ser� igual a false 
			redraw = true;

		switch (evento.type) {
		case ALLEGRO_EVENT_DISPLAY_CLOSE:
			inGame = false;
			break;
		case ALLEGRO_EVENT_MOUSE_AXES:
			play.print();
			HTP.print();
			close.print();
			break;
		case ALLEGRO_EVENT_MOUSE_BUTTON_DOWN:
			if (play.clickAboveButton(evento))
				newScene(colaEventos);
			if (HTP.clickAboveButton(evento))
				HTP_dialog(display);
			if (close.clickAboveButton(evento))
				inGame = false;
			break;
		}


		al_flip_display();

	}



	al_destroy_display(display);
	al_destroy_event_queue(colaEventos);
	al_destroy_bitmap(logo_BMP);
	al_destroy_timer(timer);
	al_shutdown_native_dialog_addon();
	al_shutdown_image_addon();
	al_uninstall_mouse();


}

void inits() {
	al_init();
	al_init_native_dialog_addon();
	al_init_image_addon();
	al_install_mouse();
}

void HTP_dialog(ALLEGRO_DISPLAY* display){

	al_show_native_message_box(
		display,
		"SOLITARIE 2022",
		"COMO JUGAR",
		"Solitario es un juego para un jugador(ironico nombre cierto?)\n"
		"El proposito del juego es eliminar todas las cartas del tablero\n"
		"llevandolas de manera ascendente (A's,2,3,...,Q,K) a su cajon designado\n"
		"REGLAS:\n"
		"-No se pueden agrupar cartas del mismo color.\n"
		"-No se pueden mover cartas a espacios vacios (a menos que sea un rey).\n"
		"-El orden de apilacion es ascendente (Por ejemplo, si se quiere mover un A's , se tiene que poner encima de un 2)"
		,
		NULL,
		ALLEGRO_MESSAGEBOX_QUESTION);
}
int newScene(ALLEGRO_EVENT_QUEUE * colaEventos) {

	while (true) {
		ALLEGRO_EVENT evento;

		al_wait_for_event(colaEventos, &evento);
		al_clear_to_color( al_color_name("black") );
		al_flip_display();
	}
	return 1;
}