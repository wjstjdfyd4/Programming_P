#pragma once
#include "data.h"
#include "Snake.h"

replaydata* createreplay(int x, int y);

void append(player* p, replaydata* added);

void savefile(player* p, int seed);

void recordcheck(player* p);