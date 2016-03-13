#ifndef FUR_BLAST_SPRITE_H
#define FUR_BLAST_SPRITE_H

#include "window.h"

class Sprite {
 public:
  Sprite(const char *resourceFile, GameWindow *window);
  virtual ~Sprite();

  void render(int x, int y);
 private:
  const char *resourceFile;
  GameWindow *window;

  SDL_Texture *texture;
  SDL_Rect sourceRectangle;

  void init();

};

#endif //FUR_BLAST_SPRITE_H
