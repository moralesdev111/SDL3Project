#ifndef SDL3PROJECT_WINDOW_H
#define SDL3PROJECT_WINDOW_H
#include <memory>


struct SDL_Window;
struct SDLWindowDeleter
{
    void operator()(SDL_Window * window) const;
};

class Window
{
public:
    SDL_Window * CreateWindow(const char *title, int w, int h, uint64_t flags);
    SDL_Window * GetWindow() const {return m_window.get();}
private:
    std::unique_ptr<SDL_Window, SDLWindowDeleter> m_window;
};
#endif //SDL3PROJECT_WINDOW_H
