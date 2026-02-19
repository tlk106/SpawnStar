#pragma once
class Star {

  public:
    Star(int x = std::rand() % 101, int y = std::rand() % 101);
    int getX();
    int getY();

  private:
    int sX;
    int sY;

};