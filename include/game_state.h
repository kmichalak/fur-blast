#ifndef FUR_BLAST_GAME_STATE_H
#define FUR_BLAST_GAME_STATE_H

class GameState {
 public:
  enum StateType {
    QUIT,
    IN_GAME
  };

  virtual ~GameState() { };
  virtual StateType update() = 0;

};


#endif //FUR_BLAST_GAME_STATE_H
