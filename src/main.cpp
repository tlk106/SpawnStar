#include <SDL3/SDL.h>
#include <vector>
#include "star.h"

bool running = true;
const int windowWidth = 1920;
const int windowHeight = 1080;
const int numberOfStars = 20;
std::vector<Star> stars;

int main() {
  SDL_Init(SDL_INIT_VIDEO);
  SDL_Window* window = SDL_CreateWindow("Spawn Star", windowWidth, windowHeight, 0);

  SDL_Event event;
  SDL_Renderer* renderer = SDL_CreateRenderer(window, nullptr);

  while (running) {
    while(SDL_PollEvent(&event)) {
      if(event.type == SDL_EVENT_QUIT){
        SDL_Log("User Quit");
        running=false;
      }
    }



  }
  
  SDL_Quit();
  return 0;
}