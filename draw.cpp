#include "draw.h"

int draw(menuOption option)
{
	switch (option) {
	case menuOption::customizeCharacter:
		al_clear_to_color(al_map_rgb(0, 0, 0));
		break;
	}

	al_flip_display();

	return 0;
}
