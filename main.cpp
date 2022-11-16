
#include <iostream>
#include"objects/classButton.hpp"

#include <allegro5/allegro5.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_color.h>

using namespace std;

void inits();
void HTP_dialog(ALLEGRO_DISPLAY* display);

int main() {

	inits();
	|
	bool inGame = true;

	int ancho = 1080;
	int alto = 720;

	al_set_app_name("Solitarie 2022");

	ALLEGRO_DISPLAY* display = al_create_display(ancho, alto);
	ALLEGRO_EVENT_QUEUE* colaEventos = al_create_event_queue();
	ALLEGRO_COLOR fondo = al_color_name("forestgreen");
	ALLEGRO_EVENT evento;

	boton play("resources/ButtonPlayPressing.png", "resources/ButtonPlayWithoutPressing.png", ancho / 2, alto / 2, ALLEGRO_ALIGN_CENTER);
	boton HTP("resources/Button_HTP_Pressing.png", "resources/Button_HTP_WithoutPressing.png", ancho / 2, (alto / 2) + ((alto / 2) / 4), ALLEGRO_ALIGN_CENTER);
	boton close("resources/ButtonClosePressing.png", "resources/ButtonCloseWithoutPressing.png", ancho / 2, (alto / 2) + (alto / 4), ALLEGRO_ALIGN_CENTER);
	// La clase boton, personaliza el boton con las imagenes proporcionadas, la posicion en X y Y ademas de la alineacion conforme a esa posicion
	// Si la alineacion es al centro es0 significara que la mitad estara en la posicion X proporcionada
	// Si la alineacion es a la derecha, la imagen estara por la derecha del punto X proporcionado 
	// Y por ultimo si la alineacion es a la izquierda, la imagen estar� por la izquierda del punto X proporcionado.

	al_register_event_source(colaEventos, al_get_display_event_source(display));
	al_register_event_source(colaEventos, al_get_mouse_event_source());

	while (inGame) {
		al_wait_for_event(colaEventos, &evento);

		al_clear_to_color(fondo);


		play.print();
		HTP.print();
		close.print();


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
				cout << "Click play button\n";
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
		ALLEGRO_MESSAGEBOX_QUESTION
	);

}