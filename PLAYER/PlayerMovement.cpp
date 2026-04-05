#include "PlayerMovement.h"
#include <SDL3/SDL_keyboard.h>
#include <SDL3/SDL_log.h>

void PlayerMovement::PlayerMove(struct SDL_FRect& inPlayerPosition, float deltaTime)
{
const bool* keystate = SDL_GetKeyboardState(NULL);

    if (keystate[SDL_SCANCODE_W])
    {
        SDL_LogError(SDL_LOG_CATEGORY_ERROR, "W pressed");
        inPlayerPosition.y -= 1 * movementSpeed * deltaTime;
    }

    if (keystate[SDL_SCANCODE_S])
    {
        SDL_LogError(SDL_LOG_CATEGORY_ERROR, "S pressed");
        inPlayerPosition.y += 1 * movementSpeed * deltaTime;
    }

    if (keystate[SDL_SCANCODE_A])
    {
        SDL_LogError(SDL_LOG_CATEGORY_ERROR, "A pressed");
        inPlayerPosition.x -= 1 * movementSpeed * deltaTime;
    }

    if (keystate[SDL_SCANCODE_D])
    {
        SDL_LogError(SDL_LOG_CATEGORY_ERROR, "D pressed");
        inPlayerPosition.x += 1 * movementSpeed * deltaTime;
    }
}
