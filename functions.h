#pragma once

int draw(int option, bool noFlip = false)
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
	case menuOption::options:
		al_draw_bitmap(stars, 0, 0, 0);
		al_draw_filled_rounded_rectangle(0, 10, 1080, 60, 50, 25, al_map_rgb(255, 255, 255));
		al_draw_text(selectedFont, al_map_rgb(255, 0, 0), 540, 20, ALLEGRO_ALIGN_CENTER, "Options");

		// Customize Character
		if ((joystickSelect == 0 && (mouseX >= 25 && mouseX <= 1055 && mouseY >= 110 && mouseY <= 160)) || joystickSelect == 1) {
			al_draw_filled_rounded_rectangle(25, 110, 1055, 160, 50, 25, al_map_rgb(150, 150, 150));
			al_draw_text(selectedFont, al_map_rgb(255, 0, 0), 540, 120, ALLEGRO_ALIGN_CENTER, "Difficulty");
		}
		else {
			al_draw_filled_rounded_rectangle(25, 110, 1055, 160, 50, 25, al_map_rgb(255, 255, 255));
			al_draw_text(selectedFont, al_map_rgb(255, 0, 0), 540, 120, ALLEGRO_ALIGN_CENTER, "Difficulty");
		}

		// Music
		if ((joystickSelect == 0 && (mouseX >= 25 && mouseX <= 1055 && mouseY >= 195 && mouseY <= 245)) || joystickSelect == 2) {
			al_draw_filled_rounded_rectangle(25, 195, 1055, 245, 50, 25, al_map_rgb(150, 150, 150));
			al_draw_text(selectedFont, al_map_rgb(255, 0, 0), 540, 205, ALLEGRO_ALIGN_CENTER, "Music: On / Off");
		}
		else {
			al_draw_filled_rounded_rectangle(25, 195, 1055, 245, 50, 25, al_map_rgb(255, 255, 255));
			al_draw_text(selectedFont, al_map_rgb(255, 0, 0), 540, 205, ALLEGRO_ALIGN_CENTER, "Music: On / Off");
		}

		// Font
		if ((joystickSelect == 0 && (mouseX >= 25 && mouseX <= 1055 && mouseY >= 280 && mouseY <= 330)) || joystickSelect == 3) {
			al_draw_filled_rounded_rectangle(25, 280, 1055, 330, 50, 25, al_map_rgb(150, 150, 150));
			al_draw_text(selectedFont, al_map_rgb(255, 0, 0), 540, 290, ALLEGRO_ALIGN_CENTER, "Customize Character");
		}
		else {
			al_draw_filled_rounded_rectangle(25, 280, 1055, 330, 50, 25, al_map_rgb(255, 255, 255));
			al_draw_text(selectedFont, al_map_rgb(255, 0, 0), 540, 290, ALLEGRO_ALIGN_CENTER, "Customize Character");
		}

		// difficulty
		if ((joystickSelect == 0 && (mouseX >= 25 && mouseX <= 1055 && mouseY >= 365 && mouseY <= 415)) || joystickSelect == 4) {
			al_draw_filled_rounded_rectangle(25, 365, 1055, 415, 50, 25, al_map_rgb(150, 150, 150));
			al_draw_text(selectedFont, al_map_rgb(255, 0, 0), 540, 375, ALLEGRO_ALIGN_CENTER, "Fonts");
		}
		else {
			al_draw_filled_rounded_rectangle(25, 365, 1055, 415, 50, 25, al_map_rgb(255, 255, 255));
			al_draw_text(selectedFont, al_map_rgb(255, 0, 0), 540, 375, ALLEGRO_ALIGN_CENTER, "Fonts");
		}

		// exit
		if ((joystickSelect == 0 && (mouseX >= 25 && mouseX <= 245 && mouseY >= 465 && mouseY <= 515)) || joystickSelect == 5) {
			al_draw_filled_rounded_rectangle(25, 465, 245, 515, 50, 25, al_map_rgb(150, 150, 150));
			al_draw_text(selectedFont, al_map_rgb(255, 0, 0), 135, 475, ALLEGRO_ALIGN_CENTER, "Exit");
		}
		else {
			al_draw_filled_rounded_rectangle(25, 465, 245, 515, 50, 25, al_map_rgb(255, 255, 255));
			al_draw_text(selectedFont, al_map_rgb(255, 0, 0), 135, 475, ALLEGRO_ALIGN_CENTER, "Exit");
		}
		break;

	case menuOption::menu:
		al_draw_bitmap(stars, 0, 0, 0);
		al_draw_filled_rounded_rectangle(0, 10, 1080, 60, 50, 25, al_map_rgb(255, 255, 255));
		al_draw_text(selectedFont, al_map_rgb(255, 0, 0), 540, 20, ALLEGRO_ALIGN_CENTER, "Main Menu");

		// continue
		if ((joystickSelect == 0 && (mouseX >= 25 && mouseX <= 1055 && mouseY >= 110 && mouseY <= 160)) || joystickSelect == 1) {
			al_draw_filled_rounded_rectangle(25, 110, 1055, 160, 50, 25, al_map_rgb(150, 150, 150));
			al_draw_text(selectedFont, al_map_rgb(255, 0, 0), 540, 120, ALLEGRO_ALIGN_CENTER, "Continue");
		}
		else {
			al_draw_filled_rounded_rectangle(25, 110, 1055, 160, 50, 25, al_map_rgb(255, 255, 255));
			al_draw_text(selectedFont, al_map_rgb(255, 0, 0), 540, 120, ALLEGRO_ALIGN_CENTER, "Continue");
		}

		// New Game
		if ((joystickSelect == 0 && (mouseX >= 25 && mouseX <= 1055 && mouseY >= 195 && mouseY <= 245)) || joystickSelect == 2) {
			al_draw_filled_rounded_rectangle(25, 195, 1055, 245, 50, 25, al_map_rgb(150, 150, 150));
			al_draw_text(selectedFont, al_map_rgb(255, 0, 0), 540, 205, ALLEGRO_ALIGN_CENTER, "New Game");
		}
		else {
			al_draw_filled_rounded_rectangle(25, 195, 1055, 245, 50, 25, al_map_rgb(255, 255, 255));
			al_draw_text(selectedFont, al_map_rgb(255, 0, 0), 540, 205, ALLEGRO_ALIGN_CENTER, "New Game");
		}

		// Options
		if ((joystickSelect == 0 && (mouseX >= 25 && mouseX <= 1055 && mouseY >= 280 && mouseY <= 330)) || joystickSelect == 3) {
			al_draw_filled_rounded_rectangle(25, 280, 1055, 330, 50, 25, al_map_rgb(150, 150, 150));
			al_draw_text(selectedFont, al_map_rgb(255, 0, 0), 540, 290, ALLEGRO_ALIGN_CENTER, "Options");
		}
		else {
			al_draw_filled_rounded_rectangle(25, 280, 1055, 330, 50, 25, al_map_rgb(255, 255, 255));
			al_draw_text(selectedFont, al_map_rgb(255, 0, 0), 540, 290, ALLEGRO_ALIGN_CENTER, "Options");
		}

		// Credits
		if ((joystickSelect == 0 && (mouseX >= 25 && mouseX <= 1055 && mouseY >= 365 && mouseY <= 415)) || joystickSelect == 4) {
			al_draw_filled_rounded_rectangle(25, 365, 1055, 415, 50, 25, al_map_rgb(150, 150, 150));
			al_draw_text(selectedFont, al_map_rgb(255, 0, 0), 540, 375, ALLEGRO_ALIGN_CENTER, "Credits");
		}
		else {
			al_draw_filled_rounded_rectangle(25, 365, 1055, 415, 50, 25, al_map_rgb(255, 255, 255));
			al_draw_text(selectedFont, al_map_rgb(255, 0, 0), 540, 375, ALLEGRO_ALIGN_CENTER, "Credits");
		}

		// exit
		if ((joystickSelect == 0 && (mouseX >= 25 && mouseX <= 245 && mouseY >= 465 && mouseY <= 515)) || joystickSelect == 5) {
			al_draw_filled_rounded_rectangle(25, 465, 245, 515, 50, 25, al_map_rgb(150, 150, 150));
			al_draw_text(selectedFont, al_map_rgb(255, 0, 0), 135, 475, ALLEGRO_ALIGN_CENTER, "Exit");
		}
		else {
			al_draw_filled_rounded_rectangle(25, 465, 245, 515, 50, 25, al_map_rgb(255, 255, 255));
			al_draw_text(selectedFont, al_map_rgb(255, 0, 0), 135, 475, ALLEGRO_ALIGN_CENTER, "Exit");
		}
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
	if (!noFlip) {
		al_flip_display();
	}

	return 0;
}

int joystickAxis(ALLEGRO_EVENT event) {
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

	return 0;
}

int joystickKeys(ALLEGRO_EVENT event) {
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

	return 0;
}

int fadeToBlack(int option) {
	bool doneFading = false;
	float transparency = 0.0;

	while (!doneFading) {
		ALLEGRO_TIMEOUT timeout;
		ALLEGRO_EVENT event;

		if (transparency >= 1) {
			doneFading = true;
		}

		al_init_timeout(&timeout, FPS);

		al_wait_for_event_until(event_queue, &event, &timeout);

		switch (event.type) {
		case ALLEGRO_EVENT_TIMER:
			draw(option, true);
			al_draw_filled_rectangle(0, 0, 1080, 640, al_map_rgba_f(0, 0, 0, transparency));
			al_flip_display();
			transparency += 0.02;
			break;
		}
	}

	return 0;
}

int fadeFromBlack(int option) {
	bool doneFading = false;
	float transparency = 1.0;

	while (!doneFading) {
		ALLEGRO_TIMEOUT timeout;
		ALLEGRO_EVENT event;

		if (transparency <= 0) {
			doneFading = true;
		}

		al_init_timeout(&timeout, FPS);

		al_wait_for_event_until(event_queue, &event, &timeout);

		switch (event.type) {
		case ALLEGRO_EVENT_TIMER:
			draw(option, true);
			al_draw_filled_rectangle(0, 0, 1080, 640, al_map_rgba_f(0, 0, 0, transparency));
			al_flip_display();
			transparency -= 0.02;
			break;
		}
	}

	return 0;
}

int checkFontButtons(int mouseX, int mouseY, bool joystick, int button = NULL) {
	if (joystick) {
		if (button == 0) {
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
				fadeToBlack(selectedMenuOption);
				selectedMenuOption = menuOption::menu;
				fadeFromBlack(selectedMenuOption);
				break;
			}
		}
		else if (button == 1) {
			fadeToBlack(selectedMenuOption);
			selectedMenuOption = menuOption::menu;
			fadeFromBlack(selectedMenuOption);
		}
	}
	else {
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
			fadeToBlack(selectedMenuOption);
			selectedMenuOption = menuOption::menu;
			fadeFromBlack(selectedMenuOption);
			joystickSelect = 0;
		}
	}

	return 0;
}

int checkMenuButtons(int mouseX, int mouseY, bool joystick, int button = NULL) {
	if (joystick) {
		if (button == 0) {
			switch (joystickSelect) {
			case 1:
				selectedMenuOption = menuOption::game;;
				break;
			case 2:
				selectedMenuOption = menuOption::game;
				break;
			case 3:
				fadeToBlack(selectedMenuOption);
				selectedMenuOption = menuOption::options;
				fadeFromBlack(selectedMenuOption);
				break;
			case 4:
				selectedMenuOption = menuOption::credits;
				break;
			case 5:
				fadeToBlack(selectedMenuOption);
				running = false;
				break;
			}
		}
		else if (button == 1) {
			fadeToBlack(selectedMenuOption);
			selectedMenuOption = menuOption::menu;
			fadeFromBlack(selectedMenuOption);
		}
	}
	else {
		// continue
		if (mouseX >= 25 && mouseX <= 1055 && mouseY >= 110 && mouseY <= 160) {
			selectedMenuOption = menuOption::game;
		}

		// new game
		else if (mouseX >= 25 && mouseX <= 1055 && mouseY >= 195 && mouseY <= 245) {
			selectedMenuOption = menuOption::game;
		}

		// options
		else if (mouseX >= 25 && mouseX <= 1055 && mouseY >= 280 && mouseY <= 330) {
			selectedMenuOption = menuOption::options;
		}

		// credits
		else if ((joystickSelect == 0 && (mouseX >= 25 && mouseX <= 1055 && mouseY >= 365 && mouseY <= 415)) || joystickSelect == 4) {
			selectedMenuOption = menuOption::credits;
		}

		// exit
		else if ((joystickSelect == 0 && (mouseX >= 25 && mouseX <= 245 && mouseY >= 465 && mouseY <= 515)) || joystickSelect == 4) {
			fadeToBlack(selectedMenuOption);
			running = false;
		}
	}

	return 0;
}