#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

// void CreateConsole();
// void WriteScreenToConsole(const char** screen, int width, int height);

#define MAX_W 200
#define MAX_H 200

static HANDLE hConsole;
static DWORD bytesWritten = 0;
static COORD writeCoord = {0, 0};

void CreateConsole() {
  hConsole = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL,
                                       CONSOLE_TEXTMODE_BUFFER, NULL);
  SetConsoleActiveScreenBuffer(hConsole);
}

void WriteScreenToConsole(char screen[MAX_H][MAX_W], int width, int height) {
  for (int y = 0; y < height; y++) {
    WriteConsoleOutputCharacterA(hConsole, screen[y], width, (COORD){2, y + 2},
                                 &bytesWritten);
  }
}

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
