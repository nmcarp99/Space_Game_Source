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
	case menuOption::menu:
		al_draw_bitmap(stars, 0, 0, 0);
		al_draw_filled_rounded_rectangle(0, 10, 1080, 60, 50, 25, al_map_rgb(255, 255, 255));
		al_draw_text(selectedFont, al_map_rgb(255, 0, 0), 540, 20, ALLEGRO_ALIGN_CENTER, "Menu");

		// kingsthing spike
		if ((joystickSelect == 0 && (mouseX >= 25 && mouseX <= 1055 && mouseY >= 110 && mouseY <= 160)) || joystickSelect == 1) {
			al_draw_filled_rounded_rectangle(25, 110, 1055, 160, 50, 25, al_map_rgb(150, 150, 150));
			al_draw_text(selectedFont, al_map_rgb(255, 0, 0), 540, 120, ALLEGRO_ALIGN_CENTER, "Play");
		}
		else {
			al_draw_filled_rounded_rectangle(25, 110, 1055, 160, 50, 25, al_map_rgb(255, 255, 255));
			al_draw_text(selectedFont, al_map_rgb(255, 0, 0), 540, 120, ALLEGRO_ALIGN_CENTER, "Play");
		}

		// Barbarian
		if ((joystickSelect == 0 && (mouseX >= 25 && mouseX <= 1055 && mouseY >= 195 && mouseY <= 245)) || joystickSelect == 2) {
			al_draw_filled_rounded_rectangle(25, 195, 1055, 245, 50, 25, al_map_rgb(150, 150, 150));
			al_draw_text(selectedFont, al_map_rgb(255, 0, 0), 540, 205, ALLEGRO_ALIGN_CENTER, "Options");
		}
		else {
			al_draw_filled_rounded_rectangle(25, 195, 1055, 245, 50, 25, al_map_rgb(255, 255, 255));
			al_draw_text(selectedFont, al_map_rgb(255, 0, 0), 540, 205, ALLEGRO_ALIGN_CENTER, "Options");
		}

		// GODOFWAR
		if ((joystickSelect == 0 && (mouseX >= 25 && mouseX <= 1055 && mouseY >= 280 && mouseY <= 330)) || joystickSelect == 3) {
			al_draw_filled_rounded_rectangle(25, 280, 1055, 330, 50, 25, al_map_rgb(150, 150, 150));
			al_draw_text(selectedFont, al_map_rgb(255, 0, 0), 540, 290, ALLEGRO_ALIGN_CENTER, "Credits");
		}
		else {
			al_draw_filled_rounded_rectangle(25, 280, 1055, 330, 50, 25, al_map_rgb(255, 255, 255));
			al_draw_text(selectedFont, al_map_rgb(255, 0, 0), 540, 290, ALLEGRO_ALIGN_CENTER, "Credits");
		}

		// Ancient Medium
		if ((joystickSelect == 0 && (mouseX >= 25 && mouseX <= 1055 && mouseY >= 365 && mouseY <= 415)) || joystickSelect == 4) {
			al_draw_filled_rounded_rectangle(25, 365, 1055, 415, 50, 25, al_map_rgb(150, 150, 150));
			al_draw_text(selectedFont, al_map_rgb(255, 0, 0), 540, 375, ALLEGRO_ALIGN_CENTER, "Ancient Medium");
		}
		else {
			al_draw_filled_rounded_rectangle(25, 365, 1055, 415, 50, 25, al_map_rgb(255, 255, 255));
			al_draw_text(selectedFont, al_map_rgb(255, 0, 0), 540, 375, ALLEGRO_ALIGN_CENTER, "Ancient Medium");
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

int fontSelectorJoystickAxis(ALLEGRO_EVENT event) {
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