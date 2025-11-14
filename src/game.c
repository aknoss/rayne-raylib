#include "game.h"
#include "raylib.h"
#include <stdbool.h>

static int finishScreen = 0;
struct Player {
  Rectangle collisionMesh;
};

struct Player player;
Rectangle ground;
bool isPlayerOnGround;

void DrawLevel1(void) {
  DrawRectangle(ground.x, ground.y, ground.width, ground.height, BROWN);
}

void InitGameScreen(void) {
  finishScreen = 0;
  isPlayerOnGround = false;

  player.collisionMesh.x = 100;
  player.collisionMesh.y = 400;
  player.collisionMesh.width = 40;
  player.collisionMesh.height = 80;
  ground.x = 0;
  ground.y = GetScreenHeight() - 40;
  ground.width = GetScreenWidth();
  ground.height = 40;
}

void UpdateGameScreen(void) {
  if (CheckCollisionRecs(ground, player.collisionMesh)) {
    isPlayerOnGround = true;
  } else {
    isPlayerOnGround = false;
  }
  if (IsKeyDown(KEY_RIGHT)) {
    player.collisionMesh.x += 5;
  }
  if (IsKeyDown(KEY_LEFT)) {
    player.collisionMesh.x -= 5;
  }
  if (IsKeyDown(KEY_SPACE)) {
    player.collisionMesh.y = 40;
  }
  if (!isPlayerOnGround) {
    player.collisionMesh.y += 5;
  }
}

void DrawGameScreen(void) {
  DrawLevel1();
  DrawRectangle(player.collisionMesh.x, player.collisionMesh.y,
                player.collisionMesh.width, player.collisionMesh.height, RED);
}

void UnloadGameScreen(void) {
  // TODO: Unload GAMEPLAY screen variables here!
}

int FinishGameScreen(void) { return finishScreen; }
