#ifndef FUR_BLAST_GAME_OBJECT_H
#define FUR_BLAST_GAME_OBJECT_H

#include "rectangle.h"

class GameObject {
  public:
   GameObject();
   virtual ~GameObject();
   void setGameAreaBoundaries(Rectangle *boundaries);
   void setBoundaries(Rectangle *boundaries);
   bool isInGameAreaBoundaries();

  protected:
   bool hitRightEnd();
   bool hitLeftEnd();
   bool hitTopEnd();
   bool hitBottomEnd();

   Rectangle *boundaries;

  private:
   Rectangle *gameArea;

};

#endif //FUR_BLAST_GAME_OBJECT_H