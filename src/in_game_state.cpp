#include "in_game_state.h"
#include "input.h"

InGameState::InGameState() {

}

InGameState::~InGameState() {
    delete this->player;
    delete this->gameArea;
}

void InGameState::init(SDL_Renderer *renderer, Rectangle *gameArea) {
    this->gameArea = gameArea;

    // initialize game area
    for (int blockIndex =0; blockIndex < 21 * 15; blockIndex +=21) {
        this->blocks.push_back(new Block(blockIndex, 100, renderer));
    }

    // initialize player
    this->player = new Player(renderer);
    this->player->setGameAreaBoundaries(this->gameArea);
}

GameState::StateType InGameState::update() {
    handleInput();

    if (this->shouldQuit) {
        return GameState::StateType::QUIT;
    }
    return GameState::StateType::IN_GAME;
}


void InGameState::draw(SDL_Renderer *renderer) {
    Sprite *playerSprite = this->player->getSprite();
    Rectangle *destinationRect = this->player->getBoundaries();
    drawSprite(renderer, playerSprite, destinationRect);
    int blockIndex = 0;
    for (auto block : blocks) {
//        Rectangle *destination = new Rectangle(blockIndex * 21, 100, 21, 21);

        drawSprite(renderer, block->getSprite(), block->getBoundaries());
        blockIndex++;
    }

}

void InGameState::handleInput() {
    InputManager &input = InputManager::getInstance();
    input.update();

    this->shouldQuit = input.quitRequested();

    if (input.isKeyDown(SDL_SCANCODE_ESCAPE)
        || input.isKeyPressed(SDL_SCANCODE_ESCAPE)) {
        this->shouldQuit = true;
    }
    if (input.isKeyDown(SDL_SCANCODE_F)
        || input.isKeyPressed(SDL_SCANCODE_F)) {
//        this->window->toggleFullscreen();
    }

    this->player->update();

}