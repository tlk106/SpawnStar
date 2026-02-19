#pragma once
class Star {

  public:
    Star(int x = std::rand() % 10000, int y = std::rand() % 10000);
    int getX();
    int getY();

  private:
    int sX;
    int sY;

};