#include "draw.h"

int draw(menuOption option)
{
	switch (option) {
	case menuOption::customizeCharacter:
		al_clear_to_color(al_map_rgb(0, 0, 0));
		al_draw_filled_rounded_rectangle(0, 0, 1080, 100, 20, 20, al_map_rgb(0, 208, 0));
		break;
	}
	al_flip_display();

	return 0;
}
