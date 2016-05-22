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
    for (int blockIndex = 21*5; blockIndex < 21 * 15; blockIndex += 21) {
        this->blocks.push_back((CollidingObject *) new Block(blockIndex, 100, renderer));
    }

    for (int blockIndex = 210; blockIndex < 21 * 15; blockIndex += 21) {
        this->blocks.push_back((CollidingObject *) new Block(blockIndex, 230, renderer));
    }

    for (int blockIndex = 105; blockIndex < 21 * 15; blockIndex += 21) {
        this->blocks.push_back((CollidingObject *) new Block(blockIndex, 300, renderer));
    }

    for (int blockIndex = 210; blockIndex < 21 * 20; blockIndex += 21) {
        this->blocks.push_back((CollidingObject *) new Block(blockIndex, 300, renderer));
    }

    // initialize player
    this->player = new Player(renderer);
    this->player->setGameAreaBoundaries(this->gameArea);
}

GameState::StateType InGameState::update() {
    handleInput();

    this->player->update(this->blocks);


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
    for (CollidingObject *blockObject : blocks) {
        Block *block = (Block *) blockObject;
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
}