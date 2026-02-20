#pragma once
class Star {

  public:
    Star(int x = std::rand() % 10000, int y = std::rand() % 10000, int red = std::rand() % 255, int green = std::rand() % 255, int blue = std::rand() % 255, int brightness = std::rand() % 255);
    int getX();
    int getY();
    int getRed();
    int getGreen();
    int getBlue();
    int getBrightness();

  private:
    int sX;
    int sY;
    int sRed;
    int sGreen;
    int sBlue;
    int sBrightness;

};