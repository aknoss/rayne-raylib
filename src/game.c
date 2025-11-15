#include "game.h"
#include "raylib.h"
#include <stdbool.h>

static int finishScreen = 0;
struct Player player;
struct Object ground;
bool isPlayerOnGround;

void DrawLevel1(void) { DrawRectangleRec(ground.collider, BROWN); }

void InitGameScreen(void) {
  finishScreen = 0;
  isPlayerOnGround = false;

  player.collider = (Collider){100, 400, 40, 80};
  ground.collider = (Collider){0, GetScreenHeight() - 40, GetScreenWidth(), 40};
}

void UpdateGameScreen(void) {
  float deltaTime = GetFrameTime();

  if (CheckCollisionRecs(ground.collider, player.collider)) {
    isPlayerOnGround = true;
  } else {
    isPlayerOnGround = false;
  }
  if (IsKeyDown(KEY_RIGHT)) {
    player.collider.x += 500 * deltaTime;
  }
  if (IsKeyDown(KEY_LEFT)) {
    player.collider.x -= 500 * deltaTime;
  }
  if (IsKeyDown(KEY_SPACE)) {
    player.collider.y = 40;
  }
  if (IsKeyDown(KEY_UP)) {
    player.collider.y -= 2000 * deltaTime;
  }
  if (!isPlayerOnGround) {
    player.collider.y += 1000 * deltaTime;
  }
}

void DrawGameScreen(void) {
  DrawLevel1();
  DrawRectangleRec(player.collider, RED);
}

void UnloadGameScreen(void) {
  // TODO: Unload GAMEPLAY screen variables here!
}

int FinishGameScreen(void) { return finishScreen; }
