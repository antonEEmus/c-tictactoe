#ifdef _WIN32
#include <windows.h>
#else
// Include unix headers...
#endif

#include <stdint.h>

#define MAX_W 200
#define MAX_H 200

void CreateConsole();
void WriteScreenToConsole(char screen[MAX_H][MAX_W], int width, int height);

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

void SleepMs(uint64_t ms) { Sleep(ms); }

#else
// TODO: Implement
#endif
