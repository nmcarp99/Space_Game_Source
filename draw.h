#pragma once
#include <allegro5/allegro.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_primitives.h>

enum menuOption {
	menu,
	game,
	customizeCharacter
};

int draw(menuOption option);