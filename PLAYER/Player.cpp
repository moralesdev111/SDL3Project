#include "Player.h"
#include "SDL3_image/SDL_image.h"
#include "UI/Renderer.h"
#include <SDL3/SDL_rect.h>
#include <PLAYER/PlayerMovement.h>

Player::Player(Renderer* renderer) : rendererClass(renderer)
{
    playerStartingPosition = std::make_unique<SDL_FRect>(SDL_FRect{100.f,100.f, 64.f,64.f});
    playerMovement = std::make_unique<PlayerMovement>();
    playerTexture.reset(IMG_LoadTexture(rendererClass->GetRenderer(),"ASSETS/PlayerSprite.jpg"));
    if (!playerTexture)
        {
            SDL_LogError(SDL_LOG_CATEGORY_ERROR, "Could not create player texture %s\n",
            SDL_GetError());
            return;
        }

}
Player::~Player()
{

}

void Player::UpdatePlayer()
{
    DrawPlayerTexture();
    playerMovement->Move(*playerStartingPosition);
}

void SDL_TextureDeleter::operator()(SDL_Texture* texture) const
{
    if (texture)
    {
        SDL_DestroyTexture(texture);
    }
}

void Player::DrawPlayerTexture() const
{
    if (!playerTexture) return;
    SDL_RenderTexture(rendererClass->GetRenderer(), playerTexture.get(), nullptr, playerStartingPosition.get());
}