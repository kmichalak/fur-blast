#ifndef FUR_BLAST_RECTANGLE_H
#define FUR_BLAST_RECTANGLE_H

#include <stdint.h>

class Rectangle {
  public:
   Rectangle(int x, int y, int width, int height);
   virtual ~Rectangle();

   float x;
   float y;
   float width;
   float height;
};

#endif //FUR_BLAST_RECTANGLE_H
