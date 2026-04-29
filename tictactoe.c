#include <stdio.h>
#include <stdlib.h>

int main() {
  clearScreen();
  printf("Hello this is tic tac toe\n");
  return 0;
}

void clearScreen() {
  #ifdef _WI32
    system("cls");
  #else
    system("clear");
  #endif
}

