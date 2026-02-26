#include <SDL3/SDL.h>
#include <vector>
#include <ctime>
#include "star.hpp"
#include "random.hpp"
#include "convert.hpp"

// Window
const int windowWidth = 1920;
const int windowHeight = 1080;
bool running = true;

// Stars
const int numberOfStars = 3000;
std::vector<Star> stars;

int main() {
  SDL_Init(SDL_INIT_VIDEO);
  SDL_Window* window = SDL_CreateWindow("Spawn Star", windowWidth, windowHeight, SDL_WINDOW_RESIZABLE | SDL_WINDOW_MAXIMIZED);

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
    SDL_Log("X: %d", stars[i].getX());
    SDL_Log("Y: %d", stars[i].getY());
    SDL_Log("Temperature: %d Kelvin", stars[i].getTemperature());
    SDL_Log("Solar Radius: %f", stars[i].getSolarRadius());
    SDL_Log("Distance (Light Years): %f", stars[i].getDistance());
    SDL_Log("Solar Luminosity: %f", wattsToSolarLuminosity(stars[i].getLuminosity()));
    SDL_Log("Absolute Magnitude: %f", stars[i].getAbsoluteMagnitude());
    SDL_Log("Apparent Magnitude: %f", stars[i].getApparentMagnitude());
    SDL_Log("Mass: %f", stars[i].getMass());
    SDL_Log("Surface Gravity: %f", stars[i].getSurfaceGravity());
    SDL_Log("Spectral Class: %s", stars[i].getSpectralType().c_str());
    SDL_Log("Luminosity Class: %s", stars[i].getLuminosityClass().c_str());
    SDL_Log("-------");
  }

  while (running) {
    while(SDL_PollEvent(&event)) {
      if(event.type == SDL_EVENT_QUIT){
        SDL_Log("User Quit");
        running=false;
      }
    }

    // Clear
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); 
    SDL_RenderClear(renderer);

    // Render stars
    for (int i = 0; i < stars.size(); i++) {
      SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); 
      SDL_RenderPoint(renderer, stars[i].getX(), stars[i].getY());
    }

    SDL_RenderPresent(renderer);

  }
  
  SDL_Quit();
  return 0;
}