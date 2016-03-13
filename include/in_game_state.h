#ifndef FUR_BLAST_IN_GAME_STATE_H
#define FUR_BLAST_IN_GAME_STATE_H

#include "game_state.h"

class InGameState : public GameState {
 public:
  virtual ~InGameState();
  virtual StateType update();
 private:
  bool shouldQuit;

  void handleInput();
};

#endif //FUR_BLAST_IN_GAME_STATE_H
