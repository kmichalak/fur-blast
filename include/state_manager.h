#ifndef FUR_BLAST_STATE_MANAGER_H
#define FUR_BLAST_STATE_MANAGER_H

#include "window.h"

class StateManager {
 public:
  StateManager(GameWindow *window);
  virtual ~StateManager();
  void run();

 private:
  GameWindow *window;
};

#endif //FUR_BLAST_STATE_MANAGER_H
