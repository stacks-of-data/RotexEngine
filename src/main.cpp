#include "SDL3/SDL_events.h"
#include "SDL3/SDL_init.h"
#include "SDL3/SDL_log.h"
#include "SDL3/SDL_oldnames.h"
#include "SDL3/SDL_pixels.h"
#include "SDL3/SDL_rect.h"
#include "SDL3/SDL_render.h"
#include "SDL3/SDL_video.h"
#include <iostream>

int main(int argc, char *argv[]) {
  SDL_Window *window = nullptr;
  if (SDL_InitSubSystem(SDL_INIT_VIDEO) == false) {
    std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
    return 1;
  }
  SDL_Log("Hello, World!");
  window = SDL_CreateWindow("RotexEngine", 800, 800, SDL_WINDOW_VULKAN);
  if (window == nullptr) {
    std::cout << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
    SDL_QuitSubSystem(SDL_INIT_VIDEO);
    SDL_Quit();
    return 1;
  }
  SDL_Event e;
  bool quit = false;
  while (quit == false) {
    while (SDL_PollEvent(&e)) {
      if (e.type == SDL_EVENT_QUIT)
        quit = true;
    }
  }
  SDL_DestroyWindow(window);
  SDL_QuitSubSystem(SDL_INIT_VIDEO);
  SDL_Quit();
  return 0;
}