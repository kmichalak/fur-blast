#ifndef FUR_BLAST_WINDOW_H
#define FUR_BLAST_WINDOW_H

#include <string>
#include <SDL2/SDL_video.h>
#include <SDL2/SDL_render.h>


class GameWindow {
 public:
  GameWindow(unsigned int width, unsigned int height, std::string title = "");
  virtual ~GameWindow();

  void renderImage(SDL_Texture *texture,
                   SDL_Rect *source,
                   SDL_Rect *destination);

  void destroy();

  SDL_Texture *loadImage(const char* resourceFile);
  void toggleFullscreen();

 private:
  void resize(unsigned int width, unsigned int height, std::string title);
  SDL_Window *window;
  SDL_Renderer *renderer;
  bool isInFullScreen = false;


};

#endif //FUR_BLAST_WINDOW_H
