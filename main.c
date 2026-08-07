#include "header.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static constexpr int screenWidth = 21;
static constexpr int screenHeight = 15;
static constexpr int screenSize = screenWidth * screenHeight;

static constexpr char MAP[screenSize] =
  "#####################"
  "#                   #"
  "#                   #"
  "#                   #"
  "#                   #"
  "#       |   |       #"
  "#    ---+---+---    #"
  "#       |   |       #"
  "#    ---+---+---    #"
  "#       |   |       #"
  "#                   #"
  "#                   #"
  "#                   #"
  "#                   #"
  "#####################";

int main() {
  char screen[MAX_H][MAX_W];
  for (int y = 0; y < screenHeight; y++) {
    for (int x = 0; x < screenWidth; x++) {
      screen[y][x] = MAP[y * screenWidth + x];
    }
  }

  int count = 990;
  int textSize = 4;
  char text[textSize];
  int textY = screenHeight / 2;
  int textX = screenWidth / 2;
  InitConsole();
  WriteScreenToConsole(screen, screenWidth, screenHeight);
  while (1) {
    snprintf(text, textSize, "%d", count);
    int textLen = (int) strlen(text);

    textX = screenWidth / 2 - textLen / 2;
    for (int x = screenWidth / 2 - textSize / 2; x < textSize; x++) {
      screen[textY][x] = ' ';
    }
    for (int i = 0, x = textX; i < textLen; i++) {
      screen[textY][x] = text[i];
      x++;
    }

    WriteScreenToConsole(screen, screenWidth, screenHeight);

    count++;
    SleepMs(1000);
    if (count > 999) {
      break;
    }
  }

  printf("----- Game Over! -------\n");
  DeInitConsole();
  return 0;
}
