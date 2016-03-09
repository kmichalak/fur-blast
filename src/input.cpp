#include <SDL_events.h>
#include "input.h"

InputManager &InputManager::getInstance() {
  static InputManager instance;
  return instance;
}

void InputManager::update() {

  for (int i = 0; i < NUMBER_OF_KEYS; i++) {
    this->keyDown[i] = false;
    this->keyUp[i] = false;
  }

  SDL_Event event;
  while (SDL_PollEvent(&event)) {
    switch (event.type) {
      case SDL_KEYDOWN: {

        switch (event.key.keysym.scancode) {
          case SDL_SCANCODE_RIGHT:
            this->keyDown[KEY_RIGHT_IDX] = true;
            break;
          case SDL_SCANCODE_LEFT:
            this->keyDown[KEY_LEFT_IDX] = true;
            break;
          case SDL_SCANCODE_UP:
            this->keyDown[KEY_UP_IDX] = true;
            break;
          case SDL_SCANCODE_DOWN:
            this->keyDown[KEY_DOWN_IDX] = true;
            break;
          default:
            break;
        }
        break;

      }
      case SDL_KEYUP: {

        switch (event.key.keysym.scancode) {
          case SDL_SCANCODE_RIGHT:
            this->keyUp[KEY_RIGHT_IDX] = true;
            break;
          case SDL_SCANCODE_LEFT:
            this->keyUp[KEY_LEFT_IDX] = true;
            break;
          case SDL_SCANCODE_UP:
            this->keyUp[KEY_UP_IDX] = true;
            break;
          case SDL_SCANCODE_DOWN:
            this->keyUp[KEY_DOWN_IDX] = true;
            break;
          default:
            break;
        }
        break;

      }

      default:
        break;
    }
  }

}