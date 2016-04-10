#ifndef FUR_BLAST_SPRITE_H
#define FUR_BLAST_SPRITE_H

#include "SDL.h"
#include "rectangle.h"

#define ROWS_NUM 4
#define COLS_NUM 4

class Sprite {
public:
    Sprite(const char *resourceFile, SDL_Renderer *renderer, bool containsGameTiles);

    virtual ~Sprite();

    void changeFrameRow(int i);

    void changeFrameCol(int i);

    Rectangle *getBoundaries();

    SDL_Texture *getTexture();

    SDL_Rect getSourceRect();

private:
    const char *resourceFile;

    SDL_Texture *texture;
    SDL_Rect sourceRectangle;

    void init(SDL_Renderer *pRenderer, bool containsGameTiles);

};

#endif //FUR_BLAST_SPRITE_H
