#ifndef FUR_BLAST_IN_GAME_STATE_H
#define FUR_BLAST_IN_GAME_STATE_H

#include "player.h"
#include "game_state.h"
#include "window.h"

class InGameState : public GameState {
 public:
  InGameState();
  virtual ~InGameState();

  void init(GameWindow *window);
  virtual StateType update();

 private:
  bool shouldQuit;
  void handleInput();

  Player *player;
  GameWindow *window;
};

#endif //FUR_BLAST_IN_GAME_STATE_H
