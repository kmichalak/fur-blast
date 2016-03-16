#ifndef FUR_BLAST_PLAYER_H
#define FUR_BLAST_PLAYER_H

#include "sprite.h"
#include "window.h"

class Player {
 public:
  Player(GameWindow *window);
  virtual ~Player();
  void update();

 private:
  Sprite *sprite;
  int x;
  int y;
};

#endif //FUR_BLAST_PLAYER_H
