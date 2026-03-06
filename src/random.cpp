#include <random>
#include "random.hpp"

int randInt(int min, int max) {
  std::random_device dev;
  std::mt19937 rng(dev());
  std::uniform_int_distribution<std::mt19937::result_type> dist6(min, max);

  return dist6(rng);
}

float randFloat(float min, float max) {
  std::random_device dev;
  std::mt19937 rng(dev());
  std::uniform_real_distribution<float> dist6(min, max);

  return dist6(rng);
}

bool randBool() {
  std::random_device dev;
  std::mt19937 rng(dev());
  std::uniform_int_distribution<std::mt19937::result_type> dist6(0, 1);

  return dist6(rng) == 1;
}

int randomTemperature() {
  if (randFloat(0, 1) > 0.25) {
    return randInt(2300, 5000);
  }
  else {
    randInt(2300, 10000);
  }
}