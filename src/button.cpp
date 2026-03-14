#include <SDL3/SDL.h>
#include "button.hpp"
#include "globalVariables.hpp"

Button::Button(std::string id, int x, int y, int width, int height, std::string image) {
  this->id = id;
  this->x = x;
  this->y = y;
  this->width = width;
  this->height = height;
  this->image = image;
}

void Button::renderButton(SDL_Renderer* renderer) {
  SDL_FRect button = { (float)x, (float)y, (float)width, (float)height };
  SDL_Surface* surface = SDL_LoadBMP(image.c_str());
  SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
  SDL_DestroySurface(surface);
  SDL_RenderTexture(renderer, texture, nullptr, &button);
  SDL_DestroyTexture(texture);
}

bool Button::isTouching() {
  if ((mouseX >= x && mouseX <= (x + width)) && (mouseY >= y && mouseY <= (y + height))) {
    return true;
  }
  else {
    return false;
  }
}