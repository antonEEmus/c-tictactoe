#include "header.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int screenWidth = 20;
const int screenHeight = 16;
const int screenSize = screenHeight * screenHeight;

int main() {
  char screen[MAX_H][MAX_W];
  for (int y = 0; y < screenHeight; y++) {
    for (int x = 0; x < screenWidth; x++) {
      screen[y][x] = ' ';
    }
  }

  int count = 0;
  size_t textSize = 12;
  char text[textSize];
  int textY = screenHeight / 2;
  int textX = screenWidth / 2;
  CreateConsole();
  WriteScreenToConsole(screen, screenWidth, screenHeight);
  while (1) {
    _itoa_s(count, text, textSize, 10);
    size_t textLen = strlen(text);

    textX = screenWidth / 2 - textLen / 2;
    for (int x = 0; x < screenWidth; x++) {
      screen[textY][x] = ' ';
    }
    for (int i = 0, x = textX; i < textLen; i++) {
      screen[textY][x] = text[i];
      x++;
    }

    WriteScreenToConsole(screen, screenWidth, screenHeight);

    count++;
    Sleep(1000);
  }

  return 0;
}
