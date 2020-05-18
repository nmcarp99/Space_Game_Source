#include "draw.h"

ALLEGRO_DISPLAY* display = NULL;
ALLEGRO_EVENT_QUEUE* event_queue = NULL;
ALLEGRO_TIMER* timer = NULL;

bool f11 = false;

const float FPS = 1.0 / 60;

int main()
{
	// initialize allegro
	al_init();
	al_init_native_dialog_addon();
	al_install_keyboard();
	al_init_primitives_addon();

	// create event queue
	event_queue = al_create_event_queue();

	// create new display
	al_set_new_display_flags(ALLEGRO_WINDOWED | ALLEGRO_RESIZABLE);
	al_set_new_window_position(200, 100);
	al_set_new_window_title("Space Game");
	display = al_create_display(1080, 640);

	// create timer
	timer = al_create_timer(FPS);

	// register event sources
	al_register_event_source(event_queue, al_get_display_event_source(display));
	al_register_event_source(event_queue, al_get_timer_event_source(timer));
	al_register_event_source(event_queue, al_get_keyboard_event_source());

	// start the timer
	al_start_timer(timer);

	bool running = true;
	while (running) {
		ALLEGRO_EVENT event;
		ALLEGRO_TIMEOUT timeout;

		al_init_timeout(&timeout, FPS);

		al_wait_for_event_until(event_queue, &event, &timeout);

		switch (event.type) {
		case ALLEGRO_EVENT_DISPLAY_CLOSE:
			running = false;
			break;
		case ALLEGRO_EVENT_TIMER:
			draw(menuOption::customizeCharacter);
			break;
		case ALLEGRO_EVENT_KEY_UP:
			switch (event.keyboard.keycode) {
			case ALLEGRO_KEY_F11:
				al_toggle_display_flag(display, ALLEGRO_FULLSCREEN_WINDOW, !f11);
				f11 = !f11;
				break;
			case ALLEGRO_KEY_ESCAPE:
				al_toggle_display_flag(display, ALLEGRO_FULLSCREEN_WINDOW, false);
				break;
			}
		}
	}
}