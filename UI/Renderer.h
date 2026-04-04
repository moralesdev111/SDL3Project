#ifndef SDL3_RENDERER_H
#define SDL3_RENDERER_H
#include <memory>

struct SDL_Renderer;
struct SDL_Window;
struct SDLRendererDeleter
{
    void operator()(SDL_Renderer *renderer) const;
};


class Renderer
{
public:
    SDL_Renderer* CreateRenderer(SDL_Window &m_window, const char* name);
    SDL_Renderer* GetRenderer() const {return m_renderer.get();}

private:
    std::unique_ptr<SDL_Renderer, SDLRendererDeleter> m_renderer;
};
#endif //SDL3_RENDERER_H