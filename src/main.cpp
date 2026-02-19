#include <SDL3/SDL.h>
#include <vector>
#include <ctime>
#include "star.h"

// Window
const int windowWidth = 1920;
const int windowHeight = 1080;
bool running = true;

// Stars
const int numberOfStars = 20;
std::vector<Star> stars;

int main() {
  SDL_Init(SDL_INIT_VIDEO);
  SDL_Window* window = SDL_CreateWindow("Spawn Star", windowWidth, windowHeight, 0);

  SDL_Event event;
  SDL_Renderer* renderer = SDL_CreateRenderer(window, nullptr);

  std::srand(std::time(nullptr));

  // Create stars and put them into the star vector
  for (int i = 0; i < numberOfStars; i++) {
      Star star;
      stars.push_back(star); 
  }
  
  // Print everything in the star vector and print it
  for (int i = 0; i < stars.size(); i++) {
      SDL_Log("%d, %d", stars[i].getX(), stars[i].getY());
  }

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