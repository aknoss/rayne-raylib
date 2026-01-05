#ifndef MAIN_H
#define MAIN_H

#include "raylib.h"

extern Font font;
extern const char *GAME_NAME;
extern const int SCREEN_WIDTH;
extern const int SCREEN_HEIGHT;

extern bool isGameRunning;

enum Scene {
  MENU,
  SELECT_LEVEL,
  GAME,
};

extern enum Scene currentScene;

#endif // MAIN_H
