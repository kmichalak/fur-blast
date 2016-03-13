#ifndef FUR_BLAST_INPUT_H
#define FUR_BLAST_INPUT_H

#include <SDL2/SDL.h>

class InputManager {
 public:
  static InputManager &getInstance();
  void update();
  bool quitRequested();
  bool isKeyDown(SDL_Scancode scanCode);
  bool isKeyUp(SDL_Scancode scanCode);
  bool isKeyPressed(SDL_Scancode scanCode);
 private:
  // Hide possibility of object instantiation
  InputManager() : keyboard(nullptr) { };

  // Delete methods (new C++11 - http://www.stroustrup.com/C++11FAQ.html#default)
  // and disallow copying object.
  InputManager &operator=(const InputManager &) = default;
  InputManager(const InputManager &) = default;

  const uint8_t *keyboard;

  bool keyUp[SDL_NUM_SCANCODES];
  bool keyDown[SDL_NUM_SCANCODES];
  bool shouldQuit;

};

#endif //FUR_BLAST_INPUT_H
