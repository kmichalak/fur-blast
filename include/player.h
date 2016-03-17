#ifndef FUR_BLAST_PLAYER_H
#define FUR_BLAST_PLAYER_H

#include "sprite.h"
#include "window.h"

#define RUN_LEFT_FRAMES 0
#define RUN_RIGHT_FRAMES 1

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
