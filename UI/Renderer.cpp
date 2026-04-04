#include <SDL3/SDL.h>
#include "Renderer.h"

void SDLRendererDeleter::operator()(SDL_Renderer *renderer)const
{
    if (renderer)
    {
        SDL_DestroyRenderer(renderer);
    }
}

SDL_Renderer * Renderer::CreateRenderer(SDL_Window &window, const char* name)
{
    m_renderer.reset(SDL_CreateRenderer(&window, name));

    if (m_renderer == nullptr)
    {
        SDL_LogError(SDL_LOG_CATEGORY_ERROR, "Could not create renderer %s\n",
        SDL_GetError());
        return nullptr;
    }
    return m_renderer.get();
}