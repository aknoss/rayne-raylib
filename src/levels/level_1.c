#include "level.h"

static EnemyRaw enemies[] = {
    {10, 10},
    {10, 10},
    {10, 10},
};
const int enemy_count = 3;
const float time_to_spawn = 3;

Level level_1 = {enemies, enemy_count, time_to_spawn};
