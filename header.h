#pragma once
#include <unistd.h>

// App states

typedef enum AppState {
  GAME,
  PAUSE,
  MENU
} AppState;

void HandleGame();
void HandlePause();
void HandleMenu();

// Rendering

const int FPS = 60;
const int REFRESH_INTERVAL_MS = 1000 / FPS;

void clearScreen() {
  #ifdef _WIN32
    system("cls");
  #else
    system("clear");
  #endif
}

void renderFrame(const char* content) {
  usleep(REFRESH_INTERVAL_MS * 1000);
  clearScreen();
  printf(content);  
}

