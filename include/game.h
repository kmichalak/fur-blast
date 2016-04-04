#ifndef FUR_BLAST_GAME_H
#define FUR_BLAST_GAME_H

class Game {

public:
    Game();
    virtual ~Game();
    void mainLoop();
private:
    void initialize();
};

#endif //FUR_BLAST_GAME_H
