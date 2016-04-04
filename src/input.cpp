#include <SDL_events.h>
#include "input.h"

InputManager &InputManager::getInstance() {
    static InputManager instance;
    return instance;
}

void InputManager::update() {

    shouldQuit = false;
    for (int i = 0; i < SDL_NUM_SCANCODES; i++) {
        this->keyDown[i] = false;
        this->keyUp[i] = false;
    }

    SDL_Event event;
    while (SDL_PollEvent(&event)) {

        this->keyboard = SDL_GetKeyboardState(nullptr);

        switch (event.type) {
            case SDL_KEYDOWN: {
                SDL_Scancode keyIndex = event.key.keysym.scancode;
                this->keyDown[keyIndex] = true;
                break;

            }
            case SDL_KEYUP: {
                SDL_Scancode keyIndex = event.key.keysym.scancode;
                this->keyUp[keyIndex] = true;
                break;
            }
            case SDL_QUIT: {
                shouldQuit = true;
                break;
            }

            default:
                break;
        }
    }
}

bool InputManager::quitRequested() {
    return this->shouldQuit;
}

bool InputManager::isKeyDown(SDL_Scancode scanCode) {
    return this->keyDown[scanCode];
}

bool InputManager::isKeyUp(SDL_Scancode scanCode) {
    return this->keyUp[scanCode];
}

bool InputManager::isKeyPressed(SDL_Scancode scanCode) {
    return this->keyboard[scanCode];
}
