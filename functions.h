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
			al_draw_text(selectedFont, al_map_rgb(255, 0, 0), 540, 120, ALLEGRO_ALIGN_CENTER, "Difficulty: Easy / Medium / Hard");
		}
		else {
			al_draw_filled_rounded_rectangle(25, 110, 1055, 160, 50, 25, al_map_rgb(255, 255, 255));
			al_draw_text(selectedFont, al_map_rgb(255, 0, 0), 540, 120, ALLEGRO_ALIGN_CENTER, "Difficulty: Easy / Medium / Hard");
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
		al_draw_bitmap(spaceship, 375, 430, 0);
		break;
	case menuOption::fontSelector:
		al_draw_bitmap(stars, 0, 0, 0);
		al_draw_filled_rounded_rectangle(0, 10, 1080, 60, 50, 25, al_map_rgb(255, 255, 255));
		al_draw_text(selectedFont, al_map_rgb(255, 0, 0), 540, 20, ALLEGRO_ALIGN_CENTER, "Font Selecter");

		// kingsthing spike
		if ((joystickSelect == 0 && (mouseX >= 25 && mouseX <= 1055 && mouseY >= 110 && mouseY <= 160)) || joystickSelect == 1) {
			al_draw_filled_rounded_rectangle(25, 110, 1055, 160, 50, 25, al_map_rgb(150, 150, 150));
			al_draw_text(fonts.New_Rocker, al_map_rgb(255, 0, 0), 540, 120, ALLEGRO_ALIGN_CENTER, "New Rocker");
		}
		else {
			al_draw_filled_rounded_rectangle(25, 110, 1055, 160, 50, 25, al_map_rgb(255, 255, 255));
			al_draw_text(fonts.New_Rocker, al_map_rgb(255, 0, 0), 540, 120, ALLEGRO_ALIGN_CENTER, "New Rocker");
		}

		// Metal_Mania
		if ((joystickSelect == 0 && (mouseX >= 25 && mouseX <= 1055 && mouseY >= 195 && mouseY <= 245)) || joystickSelect == 2) {
			al_draw_filled_rounded_rectangle(25, 195, 1055, 245, 50, 25, al_map_rgb(150, 150, 150));
			al_draw_text(fonts.Metal_Mania, al_map_rgb(255, 0, 0), 540, 205, ALLEGRO_ALIGN_CENTER, "Metal Mania");
		}
		else {
			al_draw_filled_rounded_rectangle(25, 195, 1055, 245, 50, 25, al_map_rgb(255, 255, 255));
			al_draw_text(fonts.Metal_Mania, al_map_rgb(255, 0, 0), 540, 205, ALLEGRO_ALIGN_CENTER, "Metal Mania");
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

	case menuOption::joystickConnected:
		al_draw_bitmap(stars, 0, 0, 0);
		al_draw_filled_rounded_rectangle(0, 10, 1080, 60, 50, 25, al_map_rgb(255, 255, 255));
		al_draw_text(selectedFont, al_map_rgb(255, 0, 0), 540, 20, ALLEGRO_ALIGN_CENTER, "Controller Connected");

		al_draw_filled_rounded_rectangle(25, 110, 1055, 160, 50, 25, al_map_rgb(255, 255, 255));
		al_draw_text(selectedFont, al_map_rgb(255, 0, 0), 540, 120, ALLEGRO_ALIGN_CENTER, "Press Any Button On Your Controller To Continue...");

		// exit
		if (joystickSelect == 0 && (mouseX >= 25 && mouseX <= 245 && mouseY >= 465 && mouseY <= 515)) {
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

int menuGameTrans()
{
	float backgroundSize = 0.0;
	int imgWidth = al_get_bitmap_width(stars);
	int imgHeight = al_get_bitmap_width(stars);
	int transWidth = imgWidth;
	int transHeight = imgHeight;
	int transXPos = -16.875;
	int transYPos = -10;
	int circleWidth = -10;

	while (circleWidth <= 628) {

		ALLEGRO_TIMEOUT timeout;
		ALLEGRO_EVENT event;

		al_init_timeout(&timeout, FPS);

		al_wait_for_event_until(event_queue, &event, &timeout);

		switch (event.type) {
		case ALLEGRO_EVENT_TIMER:
			transWidth = transWidth + 16.875;
			transHeight = transHeight + 10;
			transXPos = 540 - (transWidth / 2);
			transYPos = 540 - (transHeight / 2);
			circleWidth = circleWidth + 10;
			al_draw_scaled_bitmap(stars, 0, 0, imgWidth, imgHeight, transXPos, transYPos, transWidth, transHeight, 0);
			al_draw_filled_circle(540, 320, circleWidth, al_map_rgb(0, 0, 0));
			al_flip_display();
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

int transitionTo(int menuoption) {
	fadeToBlack(selectedMenuOption);
	selectedMenuOption = menuoption;
	fadeFromBlack(selectedMenuOption);

	return 0;
}

int checkFontButtons(int mouseX, int mouseY, bool joystick, int button = NULL) {
	if (joystick) {
		if (button == 0) {
			switch (joystickSelect) {
			case 1:
				selectedFont = fonts.New_Rocker;
				break;
			case 2:
				selectedFont = fonts.Metal_Mania;
				break;
			case 3:
				selectedFont = fonts.GODOFWAR;
				break;
			case 4:
				selectedFont = fonts.Ancient_Medium;
				break;
			case 5:
				transitionTo(menuOption::menu);
				break;
			}
		}
		else if (button == 1) {
			transitionTo(menuOption::options);
		}
	}
	else {
		// kingsthing spike
		if (mouseX >= 25 && mouseX <= 1055 && mouseY >= 110 && mouseY <= 160) {
			selectedFont = fonts.New_Rocker;
		}

		// Metal_Mania
		else if (mouseX >= 25 && mouseX <= 1055 && mouseY >= 195 && mouseY <= 245) {
			selectedFont = fonts.Metal_Mania;
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
			transitionTo(menuOption::menu);
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
				menuGameTrans();
				break;
			case 2:
				menuGameTrans();
				break;
			case 3:
				transitionTo(menuOption::options);
				break;
			case 4:
				transitionTo(menuOption::credits);
				break;
			case 5:
				fadeToBlack(selectedMenuOption);
				running = false;
				break;
			}
		}
		else if (button == 1) {
			fadeToBlack(selectedMenuOption);
			running = false;
		}
	}
	else {
		// continue
		if (mouseX >= 25 && mouseX <= 1055 && mouseY >= 110 && mouseY <= 160) {
			transitionTo(menuOption::game);
		}

		// new game
		else if (mouseX >= 25 && mouseX <= 1055 && mouseY >= 195 && mouseY <= 245) {
			transitionTo(menuOption::game);
		}

		// options
		else if (mouseX >= 25 && mouseX <= 1055 && mouseY >= 280 && mouseY <= 330) {
			transitionTo(menuOption::options);
		}

		// credits
		else if ((joystickSelect == 0 && (mouseX >= 25 && mouseX <= 1055 && mouseY >= 365 && mouseY <= 415)) || joystickSelect == 4) {
			transitionTo(menuOption::credits);
		}

		// exit
		else if ((joystickSelect == 0 && (mouseX >= 25 && mouseX <= 245 && mouseY >= 465 && mouseY <= 515)) || joystickSelect == 4) {
			fadeToBlack(selectedMenuOption);
			running = false;
		}
	}

	return 0;
}

int checkOptionsButtons(int mouseX, int mouseY, bool joystick, int button = NULL) {
	if (joystick) {
		if (button == 0) {
			switch (joystickSelect) {
			case 1:
				difficulty++;
				if (difficulty >= 3) {
					difficulty = 0;
				}
				break;
			case 2:
				sound = !sound;
				if (sound) {
					al_play_sample_instance(intro_instance);
				}
				else {
					al_stop_sample_instance(intro_instance);
				}
				break;
			case 3:
				transitionTo(menuOption::customizeCharacter);
				break;
			case 4:
				transitionTo(menuOption::fontSelector);
				break;
			case 5:
				transitionTo(menuOption::menu);
				break;
			}
		}
		else if (button == 1) {
			transitionTo(menuOption::menu);
		}
	}
	else {
		// change difficulty
		if (mouseX >= 25 && mouseX <= 1055 && mouseY >= 110 && mouseY <= 160) {
			difficulty++;
			if (difficulty >= 3) {
				difficulty = 0;
			}
		}

		// change sound
		else if (mouseX >= 25 && mouseX <= 1055 && mouseY >= 195 && mouseY <= 245) {
			sound = !sound;
			if (sound) {
				al_play_sample_instance(intro_instance);
			}
			else {
				al_stop_sample_instance(intro_instance);
			}
		}

		// customize character
		else if (mouseX >= 25 && mouseX <= 1055 && mouseY >= 280 && mouseY <= 330) {
			transitionTo(menuOption::customizeCharacter);
		}

		// font selector
		else if ((joystickSelect == 0 && (mouseX >= 25 && mouseX <= 1055 && mouseY >= 365 && mouseY <= 415)) || joystickSelect == 4) {
			transitionTo(menuOption::fontSelector);
		}

		// exit
		else if ((joystickSelect == 0 && (mouseX >= 25 && mouseX <= 245 && mouseY >= 465 && mouseY <= 515)) || joystickSelect == 4) {
			transitionTo(menuOption::menu);
		}
	}

	return 0;
}