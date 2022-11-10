#include <iostream>
#include <allegro5/allegro5.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_color.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_image.h>

using namespace std;

bool inits();

int main() {
	
	if (inits()){				// Si al tener algun Init se regreso un "1" (EXIT_FAILURE) se retornara un 1 de igual manera.
		return EXIT_FAILURE;
	}

	bool cierra = true;

	int anchoPantalla = 1080;
	int altoPantalla = 720;

	ALLEGRO_DISPLAY* display = al_create_display(anchoPantalla, altoPantalla);
	ALLEGRO_EVENT_QUEUE* event_queue = al_create_event_queue();
	
	ALLEGRO_COLOR fondoDefault = al_color_name("forestgreen");

	ALLEGRO_COLOR botones = al_color_html("#bdffff");
	
	ALLEGRO_COLOR color_letra = al_color_html("#005452");
	ALLEGRO_FONT* fuenteBase_BebasFont = al_load_font("resources/Bebas-Regular.ttf", 100, 0);
	
	al_register_event_source(event_queue, al_get_mouse_event_source() );


	while (cierra) {
		ALLEGRO_EVENT evento;	
		al_wait_for_event(event_queue, &evento);

		al_clear_to_color(fondoDefault);
		al_draw_filled_rounded_rectangle((anchoPantalla / 2) - 150, (altoPantalla / 2),	// Valor de inicio del boton "play"
			(anchoPantalla / 2) + 150, (altoPantalla / 2) + 80,							// Valor de fin del boton "play"
			20, 20, botones);															// Redondeo de esquinas y color.

		al_draw_text(fuenteBase_BebasFont,						// Fuente
			color_letra,										// Color del texto
			(anchoPantalla / 2), (altoPantalla / 2) - 25		// Posicion del texto
			, ALLEGRO_ALIGN_CENTRE, "Play");					// Alineacion conforme a la posicion y el texto.


		if (evento.type == ALLEGRO_EVENT_MOUSE_AXES) {	// Eventos de mouse.
			int mouseX = evento.mouse.x;
			int mouseY = evento.mouse.y;

			if (mouseX >= (anchoPantalla / 2) - 150 && mouseX <= (anchoPantalla / 2) + 150
				&& mouseY >= (altoPantalla / 2) && mouseY <= (altoPantalla / 2) + 80) {				// valores del rectangulo



				al_draw_filled_rounded_rectangle((anchoPantalla / 2) - 170, (altoPantalla / 2) - 20,			// Valor de inicio del boton "play"
												(anchoPantalla / 2) + 170, (altoPantalla / 2) + 100,			// Valor de fin del boton "play"
													20, 20, color_letra);										// Redondeo de esquinas y color


				al_draw_text(al_load_font("resources/Bebas-Regular.ttf", 120, 0),				// Fuente
					botones,																	// Color del texto
					(anchoPantalla / 2), (altoPantalla / 2) - 35								// Posicion del texto
					, ALLEGRO_ALIGN_CENTRE, "Play");											// Alineacion conforme a la posicion y el texto.

			}
		}
		
		
		al_flip_display();
	}


	return EXIT_SUCCESS;
}

bool inits(){
	if (!al_init()) {
		al_show_native_message_box(NULL, "ERROR", "", "No se pudo inicializar ALLEGRO 5", NULL, ALLEGRO_MESSAGEBOX_ERROR);
		return EXIT_FAILURE;
	}
	if (!al_install_keyboard()) {
		al_show_native_message_box(NULL, "ERROR", "", "No se pudo inicializar los drivers de TECLADO.\n", NULL, ALLEGRO_MESSAGEBOX_ERROR);
		return EXIT_FAILURE;
	}
	if (!al_install_mouse()) {
		al_show_native_message_box(NULL, "ERROR", "", "No se pudo inicializar los drivers de MOUSE.\n", NULL, ALLEGRO_MESSAGEBOX_ERROR);
		return EXIT_FAILURE;
	}
	if (!al_init_primitives_addon()) {
		al_show_native_message_box(NULL, "ERROR", "", "No se pudo inicializar los modelos primitivos.\n", NULL, ALLEGRO_MESSAGEBOX_ERROR);
		return EXIT_FAILURE;
	}
	if (!al_init_image_addon()) {
		al_show_native_message_box(NULL, "ERROR", "", "No se pudieron inicializar imagenes.\n", NULL, ALLEGRO_MESSAGEBOX_ERROR);
		return EXIT_FAILURE;
	}
	if (!al_init_font_addon()) {
		al_show_native_message_box(NULL, "ERROR", "", "No se pudieron inicializar las fuentes.\n", NULL, ALLEGRO_MESSAGEBOX_ERROR);
		return EXIT_FAILURE;
	}
	if (!al_init_ttf_addon()) {
		al_show_native_message_box(NULL, "ERROR", "", "No se pudieron inicializar las fuentes.\n", NULL, ALLEGRO_MESSAGEBOX_ERROR);
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}

