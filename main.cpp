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
	fontSelector
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
	ALLEGRO_FONT* Barbarian;
	ALLEGRO_FONT* GODOFWAR;
	ALLEGRO_FONT* Kingthings_Spike;
} fonts;

ALLEGRO_DISPLAY* display = NULL;
ALLEGRO_EVENT_QUEUE* event_queue = NULL;
ALLEGRO_TIMER* timer = NULL;
ALLEGRO_FONT* selectedFont = NULL;

ALLEGRO_BITMAP* stars = NULL;

ALLEGRO_SAMPLE* intro = NULL;
ALLEGRO_SAMPLE* loop = NULL;
ALLEGRO_SAMPLE_INSTANCE* intro_instance = NULL;
ALLEGRO_SAMPLE_INSTANCE* loop_instance = NULL;

bool f11 = false;

int mouseX, mouseY, windowXPos, windowYPos;
int joystickSelect = 0;
int selectedMenuOption = menuOption::fontSelector;

const float FPS = 1.0 / 60;

int joystickState = joystickPosition::none;

int checkFontButtons(int mouseX, int mouseY) {
	// kingsthing spike
	if (mouseX >= 25 && mouseX <= 1055 && mouseY >= 110 && mouseY <= 160) {
		selectedFont = fonts.Kingthings_Spike;
	}

	// Barbarian
	else if (mouseX >= 25 && mouseX <= 1055 && mouseY >= 195 && mouseY <= 245) {
		selectedFont = fonts.Barbarian;
	}

	// GODOFWAR
	else if (mouseX >= 25 && mouseX <= 1055 && mouseY >= 280 && mouseY <= 330) {
		selectedFont = fonts.GODOFWAR;
	}

	// Ancient Medium
	else if ((joystickSelect == 0 && (mouseX >= 25 && mouseX <= 1055 && mouseY >= 365 && mouseY <= 415)) || joystickSelect == 4) {
		selectedFont = fonts.Ancient_Medium;
	}

	// exit
	else if ((joystickSelect == 0 && (mouseX >= 25 && mouseX <= 245 && mouseY >= 465 && mouseY <= 515)) || joystickSelect == 4) {
		selectedMenuOption = menuOption::menu;
	}

	return 0;
}

int draw(int option)
{
	int x, y, winX, winY;
	al_get_mouse_cursor_position(&x, &y);
	al_get_window_position(display, &winX, &winY);
	x = x - winX;
	y = y - winY - 30;
	if ((x != mouseX || y != mouseY) && x >= 0 && y >= 0 && x <= 1080 && y <= 640 && joystickSelect != 0) {
		joystickSelect = 0;
	}
	mouseX = x;
	mouseY = y;

	switch (option) {
	case menuOption::customizeCharacter:
		al_clear_to_color(al_map_rgb(0, 0, 0));
		al_draw_filled_rounded_rectangle(0, 0, 1080, 50, 50, 25, al_map_rgb(255, 255, 255));
		al_draw_text(selectedFont, al_map_rgb(255, 0, 0), 540, 10, ALLEGRO_ALIGN_CENTER, "Character Customizer");
		break;
	case menuOption::fontSelector:
		al_draw_bitmap(stars, 0, 0, 0);
		al_draw_filled_rounded_rectangle(0, 10, 1080, 60, 50, 25, al_map_rgb(255, 255, 255));
		al_draw_text(selectedFont, al_map_rgb(255, 0, 0), 540, 20, ALLEGRO_ALIGN_CENTER, "Font Selecter");

		// kingsthing spike
		if ((joystickSelect == 0 && (mouseX >= 25 && mouseX <= 1055 && mouseY >= 110 && mouseY <= 160)) || joystickSelect == 1) {
			al_draw_filled_rounded_rectangle(25, 110, 1055, 160, 50, 25, al_map_rgb(150, 150, 150));
			al_draw_text(fonts.Kingthings_Spike, al_map_rgb(255, 0, 0), 540, 120, ALLEGRO_ALIGN_CENTER, "Kingsthing Spike");
		}
		else {
			al_draw_filled_rounded_rectangle(25, 110, 1055, 160, 50, 25, al_map_rgb(255, 255, 255));
			al_draw_text(fonts.Kingthings_Spike, al_map_rgb(255, 0, 0), 540, 120, ALLEGRO_ALIGN_CENTER, "Kingsthing Spike");
		}

		// Barbarian
		if ((joystickSelect == 0 && (mouseX >= 25 && mouseX <= 1055 && mouseY >= 195 && mouseY <= 245)) || joystickSelect == 2) {
			al_draw_filled_rounded_rectangle(25, 195, 1055, 245, 50, 25, al_map_rgb(150, 150, 150));
			al_draw_text(fonts.Barbarian, al_map_rgb(255, 0, 0), 540, 205, ALLEGRO_ALIGN_CENTER, "Barbarian");
		}
		else {
			al_draw_filled_rounded_rectangle(25, 195, 1055, 245, 50, 25, al_map_rgb(255, 255, 255));
			al_draw_text(fonts.Barbarian, al_map_rgb(255, 0, 0), 540, 205, ALLEGRO_ALIGN_CENTER, "Barbarian");
		}

		// GODOFWAR
		if ((joystickSelect == 0 && (mouseX >= 25 && mouseX <= 1055 && mouseY >= 280 && mouseY <= 330)) || joystickSelect == 3) {
			al_draw_filled_rounded_rectangle(25, 280, 1055, 330, 50, 25, al_map_rgb(150, 150, 150));
			al_draw_text(fonts.GODOFWAR, al_map_rgb(255, 0, 0), 540, 290, ALLEGRO_ALIGN_CENTER, "GODOFWAR");
		}
		else {
			al_draw_filled_rounded_rectangle(25, 280, 1055, 330, 50, 25, al_map_rgb(255, 255, 255));
			al_draw_text(fonts.GODOFWAR, al_map_rgb(255, 0, 0), 540, 290, ALLEGRO_ALIGN_CENTER, "GODOFWAR");
		}

		// Ancient Medium
		if ((joystickSelect == 0 && (mouseX >= 25 && mouseX <= 1055 && mouseY >= 365 && mouseY <= 415)) || joystickSelect == 4) {
			al_draw_filled_rounded_rectangle(25, 365, 1055, 415, 50, 25, al_map_rgb(150, 150, 150));
			al_draw_text(fonts.Ancient_Medium, al_map_rgb(255, 0, 0), 540, 375, ALLEGRO_ALIGN_CENTER, "Ancient Medium");
		}
		else {
			al_draw_filled_rounded_rectangle(25, 365, 1055, 415, 50, 25, al_map_rgb(255, 255, 255));
			al_draw_text(fonts.Ancient_Medium, al_map_rgb(255, 0, 0), 540, 375, ALLEGRO_ALIGN_CENTER, "Ancient Medium");
		}

		if ((joystickSelect == 0 && (mouseX >= 25 && mouseX <= 245 && mouseY >= 465 && mouseY <= 515)) || joystickSelect == 5) {
			al_draw_filled_rounded_rectangle(25, 465, 245, 515, 50, 25, al_map_rgb(150, 150, 150));
			al_draw_text(selectedFont, al_map_rgb(255, 0, 0), 135, 475, ALLEGRO_ALIGN_CENTER, "Exit");
		}
		else {
			al_draw_filled_rounded_rectangle(25, 465, 245, 515, 50, 25, al_map_rgb(255, 255, 255));
			al_draw_text(selectedFont, al_map_rgb(255, 0, 0), 135, 475, ALLEGRO_ALIGN_CENTER, "Exit");
		}
		break;
	}
	al_flip_display();

	return 0;
}

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

	// load audio
	al_reserve_samples(2);
	intro = al_load_sample("menuMusic.wav");
	intro_instance = al_create_sample_instance(intro);
	al_attach_sample_instance_to_mixer(intro_instance, al_get_default_mixer());
	al_set_sample_instance_playmode(intro_instance, ALLEGRO_PLAYMODE_LOOP);
	al_play_sample_instance(intro_instance);

	// load fonts
	fonts.Ancient_Medium = al_load_font("Ancient Medium.ttf", 25, NULL);
	fonts.Barbarian = al_load_font("Barbarian.ttf", 25, NULL);
	fonts.GODOFWAR = al_load_font("GODOFWAR.ttf", 25, NULL);
	fonts.Kingthings_Spike = al_load_font("Kingthings Spike.ttf", 25, NULL);
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
			draw(selectedMenuOption);
			break;
		case ALLEGRO_EVENT_MOUSE_LEAVE_DISPLAY:
			joystickSelect = 1;
			break;
		case ALLEGRO_EVENT_MOUSE_ENTER_DISPLAY:
			joystickSelect = 0;
			break;
		case ALLEGRO_EVENT_KEY_UP:
			if (selectedMenuOption == menuOption::fontSelector) {
				if (joystickSelect == 0) {
					joystickSelect = 1;
				}
				else {
					switch (event.keyboard.keycode) {
					case ALLEGRO_KEY_UP:
						if (joystickSelect > 1) {
							joystickSelect -= 1;
						}
						break;
					case ALLEGRO_KEY_DOWN:
						if (joystickSelect < numFonts + 1) {
							joystickSelect += 1;
						}
						break;
					}
				}
			}
			break;
		case ALLEGRO_EVENT_MOUSE_BUTTON_UP:
			if (selectedMenuOption == menuOption::fontSelector) {
				checkFontButtons(event.mouse.x, event.mouse.y);
			}
			break;
		case ALLEGRO_EVENT_JOYSTICK_AXIS:
			if (selectedMenuOption == menuOption::fontSelector) {
				if (event.joystick.axis == 1) {
					if (event.joystick.pos <= -0.8) {
						joystickState = joystickPosition::up;
					}
					else if (event.joystick.pos >= 0.8) {
						joystickState = joystickPosition::down;
					}
					else if (event.joystick.pos < 0.1 && event.joystick.pos > -0.1) {
						switch (joystickState) {
						case joystickPosition::up:
							if (joystickSelect > 1) {
								joystickSelect -= 1;
								joystickState = joystickPosition::none;
							}
							break;
						case joystickPosition::down:
							if (joystickSelect < numFonts + 1) {
								joystickSelect += 1;
								joystickState = joystickPosition::none;
							}
						}
					}
				}
			}
			break;
		case ALLEGRO_EVENT_JOYSTICK_BUTTON_UP:
			if (selectedMenuOption == menuOption::fontSelector) {
				if (event.joystick.button == 0) {
					switch (joystickSelect) {
					case 1:
						selectedFont = fonts.Kingthings_Spike;
						break;
					case 2:
						selectedFont = fonts.Barbarian;
						break;
					case 3:
						selectedFont = fonts.GODOFWAR;
						break;
					case 4:
						selectedFont = fonts.Ancient_Medium;
						break;
					case 5:
						selectedMenuOption = menuOption::menu;
						break;
					}
				}
				else if (event.joystick.button == 1) {
					selectedMenuOption = menuOption::menu;
				}
			}
		}
	}
}