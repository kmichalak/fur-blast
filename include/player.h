#ifndef FUR_BLAST_PLAYER_H
#define FUR_BLAST_PLAYER_H

#include "sprite.h"
#include "window.h"
#include "game_object.h"

#define RUN_LEFT_FRAMES 0
#define RUN_RIGHT_FRAMES 1
#define MOVE_SPEED 0.3

class Player : public GameObject {
 public:
  Player(GameWindow *window);
  virtual ~Player();
  void update();

 private:
  Sprite *sprite;
  float x;
  float y;

  void updateFrames(int frameRow);
};

#endif //FUR_BLAST_PLAYER_H
