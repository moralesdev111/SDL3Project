#include "Window.h"
#include <SDL3/SDL.h>


void SDLWindowDeleter::operator()(SDL_Window *window) const
{
    if (window)
    {
        SDL_DestroyWindow(window);
    }
}

SDL_Window * Window::CreateWindow(const char *title, int w, int h, uint64_t flags)
{
    m_window.reset(SDL_CreateWindow(title, w, h, flags));
    if (m_window == nullptr)
    {
        SDL_LogError(SDL_LOG_CATEGORY_ERROR, "Could not create window %s,\n",
        SDL_GetError());
        return nullptr;
    }
    return m_window.get();
}