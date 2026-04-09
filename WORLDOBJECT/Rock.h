#ifndef SDL3PROJECT_ROCK_H
#define SDL3PROJECT_ROCK_H
#include <memory>

class Rock
{
public:
    Rock();
    void DrawRockTexture() const;
private:
    std::unique_ptr<class SDL_Texture> rockTexture;
    std::unique_ptr<class SDL_FRect> rockStartingPosition;



};
#endif //SDL3PROJECT_ROCK_H
