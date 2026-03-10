#pragma once
#include <string>
#include <SDL3/SDL.h>
#include "globalVariables.hpp"

class Button {

  public:
    std::string id;
    int x;
    int y;
    int width;
    int height;
    std::string image;

    Button(std::string id = "Button", int x = 0, int y = 0, int width = 25, int height = 25, std::string image = "img/button.png");

    void Button::renderButton(SDL_Renderer *renderer);
    bool isTouching();
};