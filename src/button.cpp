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

void Button::renderButton(SDL_Renderer *renderer) {
  SDL_FRect button = { (float)x, (float)y, (float)width, (float)height };
  SDL_RenderFillRect(renderer, &button);
}

bool Button::isTouching() {
  if ((mouseX >= x && mouseX <= (x + width)) && (mouseY >= y && mouseY <= (y + height))) {
    return true;
  }
  else {
    return false;
  }
}