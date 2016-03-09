#include <SDL.h>
#include "include/window.h"

int main() {
  int status = SDL_Init(SDL_INIT_VIDEO);
  if (status == 0) {
    GameWindow *window = new GameWindow(960, 540, "Fur Blast");

    SDL_Event event;

    while(1) {
      SDL_PollEvent(&event);
      if (event.type == SDL_QUIT) {
        break;
      }
      window->update();
    }
    delete window;
  }
  SDL_Quit();

  return status;
}