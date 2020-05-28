#include <allegro5/allegro.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_audio.h>
#include <iostream>

enum menuOption {
	menu,
	game,
	customizeCharacter,
	fontSelector,
	options,
	credits
};

enum joystickPosition {
	up,
	down,
	left,
	right,
	none
};

int numFonts = 4;
struct selectFont {
	ALLEGRO_FONT* Ancient_Medium;
	ALLEGRO_FONT* Metal_Mania;
	ALLEGRO_FONT* GODOFWAR;
	ALLEGRO_FONT* New_Rocker;
} fonts;

ALLEGRO_DISPLAY* display = NULL;
ALLEGRO_EVENT_QUEUE* event_queue = NULL;
ALLEGRO_TIMER* timer = NULL;
ALLEGRO_FONT* selectedFont = NULL;

ALLEGRO_BITMAP* stars = NULL;
ALLEGRO_BITMAP* spaceship = NULL;

ALLEGRO_SAMPLE* intro = NULL;
ALLEGRO_SAMPLE* loop = NULL;
ALLEGRO_SAMPLE_INSTANCE* intro_instance = NULL;
ALLEGRO_SAMPLE_INSTANCE* loop_instance = NULL;

bool f11 = false;
bool running = true;
bool sound = true;

int mouseX, mouseY, windowXPos, windowYPos;
int joystickSelect = 0;
int selectedMenuOption = menuOption::menu;
int difficulty = 0;

const float FPS = 1.0 / 60;

int joystickState = joystickPosition::none;

// include functions from "draw.h"
#include "functions.h"

int main()
{
	// initialize allegro
	al_init();
	al_install_mouse();
	al_init_native_dialog_addon();
	al_install_keyboard();
	al_init_primitives_addon();
	al_init_font_addon();
	al_init_ttf_addon();
	al_init_image_addon();
	al_install_audio();
	al_init_acodec_addon();
	al_install_joystick();

	// create event queue
	event_queue = al_create_event_queue();

	// create new display
	al_set_new_window_position(200, 100);
	al_set_new_window_title("Space Game");
	display = al_create_display(1080, 640);

	// load images
	stars = al_load_bitmap("stars.jpg");
	spaceship = al_load_bitmap("spaceship.png");

	// load audio
	al_reserve_samples(2);
	intro = al_load_sample("menuMusic.wav");
	intro_instance = al_create_sample_instance(intro);
	al_attach_sample_instance_to_mixer(intro_instance, al_get_default_mixer());
	al_set_sample_instance_playmode(intro_instance, ALLEGRO_PLAYMODE_LOOP);
	al_play_sample_instance(intro_instance);

	// load fonts
	fonts.Ancient_Medium = al_load_font("Ancient Medium.ttf", 25, NULL);
	fonts.Metal_Mania = al_load_font("Metal Mania.ttf", 25, NULL);
	fonts.GODOFWAR = al_load_font("GODOFWAR.ttf", 25, NULL);
	fonts.New_Rocker = al_load_font("New Rocker.ttf", 25, NULL);
	selectedFont = fonts.GODOFWAR;

	// create timer
	timer = al_create_timer(FPS);

	// register event sources
	al_register_event_source(event_queue, al_get_display_event_source(display));
	al_register_event_source(event_queue, al_get_timer_event_source(timer));
	al_register_event_source(event_queue, al_get_keyboard_event_source());
	al_register_event_source(event_queue, al_get_mouse_event_source());
	al_register_event_source(event_queue, al_get_joystick_event_source());

	// start the timer
	al_start_timer(timer);

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
			draw(selectedMenuOption);
			break;
		case ALLEGRO_EVENT_MOUSE_LEAVE_DISPLAY:
			joystickSelect = 1;
			break;
		case ALLEGRO_EVENT_MOUSE_ENTER_DISPLAY:
			joystickSelect = 0;
			break;
		case ALLEGRO_EVENT_KEY_UP:
			joystickKeys(event);
			break;
		case ALLEGRO_EVENT_MOUSE_BUTTON_UP:
			switch(selectedMenuOption) {
			case menuOption::fontSelector:
				checkFontButtons(event.mouse.x, event.mouse.y, false);
				break;
			case menuOption::menu:
				checkMenuButtons(event.mouse.x, event.mouse.y, false);
				break;
			case menuOption::options:
				checkOptionsButtons(event.mouse.x, event.mouse.y, false);
				break;
			}
			break;
		case ALLEGRO_EVENT_JOYSTICK_AXIS:
			joystickAxis(event);
			break;
		case ALLEGRO_EVENT_JOYSTICK_BUTTON_UP:
			switch (selectedMenuOption) {
			case menuOption::fontSelector:
				checkFontButtons(NULL, NULL, true, event.joystick.button);
				break;
			case menuOption::menu:
				checkMenuButtons(NULL, NULL, true, event.joystick.button);
				break;
			case menuOption::options:
				checkOptionsButtons(NULL, NULL, true, event.joystick.button);
				break;
			}
		}
	}
}