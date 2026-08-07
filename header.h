#include <stdio.h>
#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#include <termios.h>
#endif

#include <stdint.h>

#define MAX_W 200
#define MAX_H 200

void InitConsole();
void WriteScreenToConsole(char screen[MAX_H][MAX_W], int width, int height);
void DeInitConsole();

void SleepMs(uint64_t ms);

#ifdef _WIN32

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

void SleepMs(uint64_t ms) {
  Sleep(ms);
}

void DeInitConsole() {
  // Nothing here yet...
}

#else

static struct termios tNormal;
static struct termios tNoEcho;

void moveCursor(int x, int y) {
  printf("\033[%d;%dH", y, x);
}

void InitConsole() {
  // Hiding input chars
  tcgetattr(STDIN_FILENO, &tNormal);
  tNoEcho = tNormal;
  tNoEcho.c_lflag &= ~(ICANON | ECHO);
  tcsetattr(STDIN_FILENO, TCSANOW, &tNoEcho);
}

void WriteScreenToConsole(char screen[MAX_H][MAX_W], int width, int height) {
  // fflush(stdout);
  printf("\033[H\033[2J"); // Clear the screen
  for (int y = 0; y < height; y++) {
    moveCursor(3, y + 3);
    printf("%s\n", screen[y]);
  }
}

void SleepMs(uint64_t ms) {
  usleep(ms * 1000);
}
void DeInitConsole() {
  tcsetattr(STDIN_FILENO, TCSANOW, &tNormal);
}

#endif
