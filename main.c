#include <stdio.h>
#include <stdlib.h>
#include "header.h"

AppState state = MENU;

int main() {
  while(1) {
    switch (state) {
      case GAME:
        HandleGame();
        break;
      case PAUSE: 
        HandlePause();
        break;
      case MENU:
        HandleMenu();
        break;
    }
  }
  return 0;
}

void HandleGame() {
  clearScreen();
  printf("Game handled...");
}

void HandlePause() {
  clearScreen();
  printf("Game paused...");
}

void HandleMenu() {
  renderFrame(
    "Welcome To The Menu\n"
    "[Play]\n"
    "[Exit]\n"
  );
}
