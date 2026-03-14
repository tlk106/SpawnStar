#include <SDL3/SDL.h>
#include <vector>
#include <ctime>
#include <math.h>
#include "star.hpp"
#include "random.hpp"
#include "convert.hpp"
#include "globalVariables.hpp"
#include "button.hpp"

// Function to render circles
void renderCircle(SDL_Renderer *renderer, int originX, int originY, int radius) {
  for (int x = -radius; x <= radius; x++) {
    for (int y = -radius; y <= radius; y++) {
      if (x*x + y*y <= radius*radius) {
        SDL_RenderPoint(renderer, x+originX, y+originY);
      }
    }
  }
}

// Window
int windowWidth;
int windowHeight;
bool running = true;

// Mouse
float mouseX;
float mouseY;
bool isMouseDown;

// Stars
int numberOfStars;
std::vector<Star> stars;

int main() {
  SDL_Init(SDL_INIT_VIDEO);
  SDL_Window* window = SDL_CreateWindow("Spawn Star v0.1.2", 384, 216, SDL_WINDOW_RESIZABLE | SDL_WINDOW_MAXIMIZED);
  SDL_Event event;
  SDL_Renderer* renderer = SDL_CreateRenderer(window, nullptr);
  SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
  std::srand(std::time(nullptr));

  // Get the window height and width
  SDL_GetWindowSizeInPixels(window, &windowWidth, &windowHeight);

  SDL_SetWindowMinimumSize(window, 192, 108);

  // Make the star density always 1 star per 1000 pixels
  numberOfStars = (windowWidth * windowHeight) / 1000;

  // Create stars and put them into the star vector
  for (int i = 0; i < numberOfStars; i++) {
    Star star;
    stars.push_back(star); 
  }

  // Delete half of the brightest stars because there are too many
  for (int i = 0; i < stars.size(); i++) {
    if (stars[i].getRenderingBrightness() == 255 && randBool()) {
      stars.erase(stars.begin() + i);
      i--;
    }
  }
  
  // Print everything in the star vector and print it
  for (int i = 0; i < stars.size(); i++) {
    SDL_Log("Star Number: #%d", i);
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
    SDL_Log("RGB Alpha: %d", stars[i].getRenderingBrightness());
    SDL_Log("-------");
  }

  SDL_Log("Window Height: %d", windowHeight);
  SDL_Log("Window Width: %d", windowWidth);
  SDL_Log("Number of initial stars (Before removal of some): %d", numberOfStars);

  while (running) {
    // Keep updating fo the buttons to be able to move. 
    SDL_GetWindowSizeInPixels(window, &windowWidth, &windowHeight);

    // Buttons
    Button refreshButton("Refresh Button", windowWidth - 90, 10, 80, 80, "img/Refresh_icon.bmp");

    // Check if the user quits
    while(SDL_PollEvent(&event)) {
      if(event.type == SDL_EVENT_QUIT){
        SDL_Log("User Quit");
        running=false;
      }
      else if (event.type == SDL_EVENT_MOUSE_MOTION) {
        mouseX = event.motion.x;
        mouseY = event.motion.y;
      }
      else if (event.type == SDL_EVENT_MOUSE_BUTTON_DOWN) {
        if (event.button.button == SDL_BUTTON_LEFT) {
          isMouseDown = true;
        }
      }
      else if (event.type == SDL_EVENT_MOUSE_BUTTON_UP) {
        if (event.button.button == SDL_BUTTON_LEFT) {
          isMouseDown = false;
        }
      }
    }

    // Refresh button detection
    if (refreshButton.isTouching() && isMouseDown) {
      SDL_Log("Refresh Button Pressed");
    }

    // Clear
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); 
    SDL_RenderClear(renderer);
    
    // Render stars
    for (int i = 0; i < stars.size(); i++) {
      SDL_SetRenderDrawColor(renderer, stars[i].getRenderingColour()[0], stars[i].getRenderingColour()[1], stars[i].getRenderingColour()[2], stars[i].getRenderingBrightness()); 
      SDL_RenderPoint(renderer, stars[i].getX(), stars[i].getY());

      // Glow
      for (int j = stars[i].getCenterGlowRadius(); j > 0; j--) {
        SDL_SetRenderDrawColor(renderer, stars[i].getRenderingColour()[0], stars[i].getRenderingColour()[1], stars[i].getRenderingColour()[2], (stars[i].getRenderingBrightness() / 5)); 
        renderCircle(renderer, stars[i].getX(), stars[i].getY(), j);
      }
    }

    refreshButton.renderButton(renderer);

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); 

    SDL_RenderPresent(renderer);
  }
  
  SDL_Quit();
  return 0;
}