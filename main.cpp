#include <SDL.h>
#include "include/window.h"
#include "include/state_manager.h"

int main() {
  int status = SDL_Init(SDL_INIT_VIDEO);
  if (status == 0) {
    GameWindow *window = new GameWindow(960, 540, "Fur Blast");
    StateManager stateManager(window);
    stateManager.run();
  }
  SDL_Quit();

  return status;
}