#ifndef FUR_BLAST_WINDOW_H
#define FUR_BLAST_WINDOW_H

#include <string>
#include <SDL2/SDL_video.h>

namespace furblast
{

class Window {
 public:
  Window (unsigned int width, unsigned int height, std::string title="");
  virtual ~Window ();

  void destroy();
  void update();
 private:
  void resize (unsigned int width, unsigned int height, std::string title);
  SDL_Window *window;
  SDL_Renderer *renderer;
};

}

#endif //FUR_BLAST_WINDOW_H
