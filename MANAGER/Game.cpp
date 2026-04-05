#include "Game.h"
#include "UI/Window.h"
#include "UI/Renderer.h"
#include "PLAYER/Player.h"
#include "SDL3/SDL.h"


Game::Game()
{
    if (!SDL_Init(SDL_INIT_VIDEO)) return;
    windowClass = std::make_unique<Window>();
    windowClass->CreateWindow("GameWindow", 1280,960, SDL_WINDOW_OPENGL);
    rendererClass = std::make_unique<Renderer>();
    rendererClass->CreateRenderer(*windowClass->GetWindow(), nullptr);
    playerClass = std::make_unique<Player>(rendererClass.get());
    isRunning = true;
}

Game::~Game()
{
    SDL_Quit();
}

void Game::RunGame()
{
    Uint64 fps = 0;
    Uint64 lastTime = SDL_GetTicks();
    Uint64 lastSecondTime = lastTime;
    while (isRunning)
    {
        Uint64 currentTick = SDL_GetTicks();
        deltaTime = (currentTick - lastTime) / 1000.0f;
        lastTime = currentTick;

        UpdateGame();
        ++fps;

        if (currentTick > lastSecondTime + 1000)
        {
            SDL_LogError(SDL_LOG_CATEGORY_CUSTOM,"FPS: %lu", fps);
            fps = 0;
            lastSecondTime = currentTick;
        }
        SDL_Delay(16);
    }
}

void Game::UpdateGame()
{
    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
        if (event.type == SDL_EVENT_QUIT)
        {
            isRunning = false;
        }
    }

    SDL_SetRenderDrawColor(rendererClass->GetRenderer(), 175, 100,0, 255);
    SDL_RenderClear(rendererClass->GetRenderer());
    playerClass->UpdatePlayer(deltaTime);
    SDL_RenderPresent(rendererClass->GetRenderer());
}