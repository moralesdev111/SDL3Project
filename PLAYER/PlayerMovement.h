#ifndef SDL3PROJECT_PLAYERMOVEMENT_H
#define SDL3PROJECT_PLAYERMOVEMENT_H

class PlayerMovement
{
public:
    void PlayerMove(struct SDL_FRect& inPlayerPosition, float deltaTime);
private:
    float movementSpeed = 300.f;
};
#endif //SDL3PROJECT_PLAYERMOVEMENT_H
