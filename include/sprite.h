#ifndef FUR_BLAST_SPRITE_H
#define FUR_BLAST_SPRITE_H

#include "window.h"

#define ROWS_NUM 4
#define COLS_NUM 4

class Sprite {
 public:
  Sprite(const char *resourceFile, GameWindow *window);
  virtual ~Sprite();

  void render(int x, int y);

 void changeFrameRow(int i);

 void changeFrameCol(int i);

  private:
  const char *resourceFile;
  GameWindow *window;

  SDL_Texture *texture;
  SDL_Rect sourceRectangle;

  void init();

};

#endif //FUR_BLAST_SPRITE_H
