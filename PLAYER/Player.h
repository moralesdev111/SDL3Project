#ifndef SDL3_PLAYER_H
#define SDL3_PLAYER_H
#include <memory>


class Renderer;
class PlayerMovement;
struct SDL_FRect;
struct SDL_Texture;
struct SDL_Renderer;
struct SDL_TextureDeleter
{
    void operator()(SDL_Texture* texture) const;
};


class Player
{
public:
    Player(Renderer* renderer);
    ~Player();
    void DrawPlayerTexture() const;
    SDL_FRect* GetPlayerStartingPosition() const {return playerStartingPosition.get();}
    void UpdatePlayer(float deltaTime);

private:
    std::unique_ptr<SDL_Texture, SDL_TextureDeleter> playerTexture;
    std::unique_ptr<SDL_FRect> playerStartingPosition;
    std::unique_ptr<PlayerMovement> playerMovement;
    Renderer* rendererClass = nullptr;

};
#endif //SDL3_PLAYER_H