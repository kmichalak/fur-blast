#include "in_game_state.h"
#include "input.h"

InGameState::InGameState() {

}

InGameState::~InGameState() {
  delete this->player;
}

void InGameState::init(GameWindow *window) {
  this->player = new Player(window);
}

GameState::StateType InGameState::update() {
  handleInput();

  if (this->shouldQuit) {
    return GameState::StateType::QUIT;
  }
  return GameState::StateType::IN_GAME;
}

void InGameState::handleInput() {
  InputManager &input = InputManager::getInstance();
  input.update();

  this->shouldQuit = input.quitRequested();

  if (input.isKeyDown(SDL_SCANCODE_ESCAPE)
      || input.isKeyPressed(SDL_SCANCODE_ESCAPE)) {
    this->shouldQuit = true;
  }

  if (this->player) {
    this->player->update();
  }

}