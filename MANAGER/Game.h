#ifndef SDL3_GAME_H
#define SDL3_GAME_H

#include <memory>


class Game
{
public:
    Game();
    ~Game();
    Game(const Game&) = delete;
    Game &operator=(const Game&) = delete;
public:
    void RunGame();
    bool GetIsRunning() const {return isRunning;}
private:
    void UpdateGame();
private:
    std::unique_ptr<class Window> windowClass;
    std::unique_ptr<class Renderer> rendererClass;
    std::unique_ptr<class Player> playerClass;
    bool isRunning = false;
};
#endif //SDL3_GAME_H