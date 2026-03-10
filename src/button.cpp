#include "button.hpp"

Button::Button(std::string id, int x, int y, int width, int height, std::string image) {
  this->id = id;
  this->x = x;
  this->y = y;
  this->width = width;
  this->height = height;
  this->image = image;
}