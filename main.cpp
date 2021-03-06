#include <allegro5/allegro.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_audio.h>
#include <iostream>
#include <vector>

enum menuOption {
	menu,
	game,
	customizeCharacter,
	fontSelector,
	options,
	credits,
	joystickConnected,
	configureControllersMenu,
	configureControllersNewSlotSelect,
	configureControllersOldSlotSelect,
	configureControllersNew
};

enum joystickPosition {
	up,
	down,
	left,
	right,
	none
};

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
ALLEGRO_BITMAP* soundimg = NULL;
ALLEGRO_BITMAP* mute = NULL;
ALLEGRO_BITMAP* field = NULL;

ALLEGRO_SAMPLE* intro = NULL;
ALLEGRO_SAMPLE* loop = NULL;
ALLEGRO_SAMPLE_INSTANCE* intro_instance = NULL;
ALLEGRO_SAMPLE_INSTANCE* loop_instance = NULL;

bool aConfigured = false;
bool bConfigured = false;
bool xConfigured = false;
bool yConfigured = false;
bool f11 = false;
bool running = true;
bool sound = true;
bool firstPress = false;
bool joystickWaitFramesStarted = false;
bool doubleClickController = false;

int aButton, bButton, xButton, yButton;
int mouseX, mouseY, windowXPos, windowYPos;
int joystickSelect = 0;
int joystickConfigSlot = 0;
int selectedMenuOption = menuOption::menu;
int previousMenuOption = menuOption::menu;
int difficulty = 0;
int joystickWaitFrames = 0;

const float FPS = 1.0 / 60;

int joystickState = joystickPosition::none;

std::string appdatapath;

std::vector< std::string > menusettings;

// include functions
#include "readfromfile.h"
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

	// get appdata path
	appdatapath = appData() + "Space Game\\";

	// load fonts
	fonts.Ancient_Medium = al_load_font("Ancient Medium.ttf", 25, NULL);
	fonts.Metal_Mania = al_load_font("Metal Mania.ttf", 25, NULL);
	fonts.GODOFWAR = al_load_font("GODOFWAR.ttf", 25, NULL);
	fonts.New_Rocker = al_load_font("New Rocker.ttf", 25, NULL);

	// get menu settings
	menusettings = getStrings(appdatapath + "menusettings.txt");

	// get difficulty
	if (menusettings[0] == "1") {
		difficulty = 1;
	}
	else if (menusettings[0] == "2") {
		difficulty = 2;
	}

	// get sound
	if (menusettings[1] == "0") {
		sound = false;
	}

	// get font
	if (menusettings[3] == "GODOFWAR") {
		selectedFont = fonts.GODOFWAR;
	}
	else if (menusettings[3] == "Ancient_Medium") {
		selectedFont = fonts.Ancient_Medium;
	}
	else if (menusettings[3] == "Metal_Mania") {
		selectedFont = fonts.Metal_Mania;
	}
	else if (menusettings[3] == "New_Rocker") {
		selectedFont = fonts.New_Rocker;
	}

	// get joystick config
	if (menusettings[4] == "0") {
		aButton = getInts(appdatapath + "joystickslot1.txt")[0];
		bButton = getInts(appdatapath + "joystickslot1.txt")[1];
		xButton = getInts(appdatapath + "joystickslot1.txt")[2];
		yButton = getInts(appdatapath + "joystickslot1.txt")[3];
	}
	else if (menusettings[4] == "1") {
		aButton = getInts(appdatapath + "joystickslot2.txt")[0];
		bButton = getInts(appdatapath + "joystickslot2.txt")[1];
		xButton = getInts(appdatapath + "joystickslot2.txt")[2];
		yButton = getInts(appdatapath + "joystickslot2.txt")[3];
	}
	else if (menusettings[4] == "2") {
		aButton = getInts(appdatapath + "joystickslot3.txt")[0];
		bButton = getInts(appdatapath + "joystickslot3.txt")[1];
		xButton = getInts(appdatapath + "joystickslot3.txt")[2];
		yButton = getInts(appdatapath + "joystickslot3.txt")[3];
	}

	// create event queue
	event_queue = al_create_event_queue();

	// create new display
	al_set_new_window_position(200, 100);
	al_set_new_window_title("Space Game");
	al_set_new_display_flags(ALLEGRO_RESIZABLE);
	display = al_create_display(1080, 640);

	// load images
	stars = al_load_bitmap("stars.jpg");
	spaceship = al_load_bitmap("spaceship.png");
	mute = al_load_bitmap("mute.png");
	soundimg = al_load_bitmap("sound.png");
	field = al_load_bitmap("field.jpg");

	// load audio
	al_reserve_samples(2);
	intro = al_load_sample("menuMusic.wav");
	intro_instance = al_create_sample_instance(intro);
	al_attach_sample_instance_to_mixer(intro_instance, al_get_default_mixer());
	al_set_sample_instance_playmode(intro_instance, ALLEGRO_PLAYMODE_LOOP);

	if (sound) {
		al_play_sample_instance(intro_instance);
	}

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

	if (al_get_joystick(0)) {
		selectedMenuOption = menuOption::joystickConnected;
	}

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
			if (joystickWaitFramesStarted) {
				joystickWaitFrames += 1;
			}
			if (joystickWaitFrames > 10) {
				joystickWaitFramesStarted = false;
				joystickWaitFrames = 0;
				doubleClickController = false;
				selectedMenuOption = previousMenuOption;
			}
			break;
		case ALLEGRO_EVENT_MOUSE_LEAVE_DISPLAY:
			joystickSelect = 1;
			break;
		case ALLEGRO_EVENT_MOUSE_ENTER_DISPLAY:
			joystickSelect = 0;
			break;
		case ALLEGRO_EVENT_KEY_UP:
			if (selectedMenuOption == menuOption::joystickConnected) {
				selectedMenuOption = previousMenuOption;
			}
			else {
				joystickKeys(event);
			}
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
			case menuOption::configureControllersMenu:
				checkConfigureControllersMenuButtons(event.mouse.x, event.mouse.y, false);
				break;
			case menuOption::configureControllersNewSlotSelect:
				checkConfigureControllersNewSelectSlotButtons(event.mouse.x, event.mouse.y, false);
				break;
			case menuOption::configureControllersOldSlotSelect:
				checkConfigureControllersOldSelectSlotButtons(NULL, NULL, true, event.joystick.button);
				break;
			}
			break;
		case ALLEGRO_EVENT_JOYSTICK_AXIS:
			joystickAxis(event);
			break;
		case ALLEGRO_EVENT_JOYSTICK_BUTTON_UP:
			if (selectedMenuOption == menuOption::joystickConnected) {
				if (joystickWaitFramesStarted) {
					if (joystickWaitFrames <= 10) {
						joystickWaitFramesStarted = false;
						joystickWaitFrames = 0;
						doubleClickController = true;
						selectedMenuOption = previousMenuOption;
					}
				}
				else {
					joystickWaitFramesStarted = true;
				}
			}
			else if (firstPress || !doubleClickController) {
				firstPress = false;
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
				case menuOption::configureControllersMenu:
					checkConfigureControllersMenuButtons(NULL, NULL, true, event.joystick.button);
					break;
				case menuOption::configureControllersNewSlotSelect:
					checkConfigureControllersNewSelectSlotButtons(NULL, NULL, true, event.joystick.button);
					break;
				case menuOption::configureControllersOldSlotSelect:
					checkConfigureControllersOldSelectSlotButtons(NULL, NULL, true, event.joystick.button);
					break;
				case menuOption::configureControllersNew:
					checkConfigureControllersNewButtons(NULL, NULL, true, event.joystick.button);
					if (yConfigured) {
						replaceLineInts(appdatapath + "menusettings.txt", joystickConfigSlot, 4, 5);
						switch (joystickConfigSlot) {
						case 0:
							writeInts(appdatapath + "joystickslot1.txt", std::vector< int > { aButton, bButton, xButton, yButton }, 4);
							break;
						case 1:
							writeInts(appdatapath + "joystickslot2.txt", std::vector< int > { aButton, bButton, xButton, yButton }, 4);
							break;
						case 2:
							writeInts(appdatapath + "joystickslot3.txt", std::vector< int > { aButton, bButton, xButton, yButton }, 4);
							break;
						}
						transitionTo(menuOption::options);
						aConfigured = false;
						bConfigured = false;
						xConfigured = false;
						yConfigured = false;
					}
					break;
				}
			}
			else {
				firstPress = true;
			}
			break;
		case ALLEGRO_EVENT_JOYSTICK_CONFIGURATION:
			al_reconfigure_joysticks();
			if (al_get_joystick(0)) {
				previousMenuOption = selectedMenuOption;
				selectedMenuOption = menuOption::joystickConnected;
			}
			break;
		}
	}
}