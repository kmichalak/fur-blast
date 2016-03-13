#include <in_game_state.h>
#include "game_state.h"
#include "state_manager.h"
#include "input.h"

StateManager::StateManager(GameWindow *window) {
  this->window = window;
}

StateManager::~StateManager() {
  this->window = nullptr;
}

void StateManager::run() {

  InGameState currentState;
  GameState::StateType currentStateType = GameState::StateType::IN_GAME;
  // run the main game loop
  while (currentStateType != GameState::StateType::QUIT) {

    InputManager &inputManager = InputManager::getInstance();
    inputManager.update();

    if (inputManager.quitRequested()) {
      currentStateType = GameState::StateType::QUIT;
    } else {
      currentStateType = currentState.update();
    }

    // Update window content
    window->update();
    window->render();

  }
}