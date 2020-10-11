#include "DisplayManager.hpp"

#include <iostream>

#include "SDL.h"


using namespace std;


// Constructors and destructor

DisplayManager::DisplayManager() :
  window(nullptr),
  renderer(nullptr)
{}

DisplayManager::~DisplayManager() {
  SDL_DestroyWindow(window);
  SDL_Quit();
}


// Public methods

bool DisplayManager::init() {
  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    cout << "SDL could not initialize! SDL_Error: " << SDL_GetError() << endl;
    return false;
  }

  window = SDL_CreateWindow("3D Projection", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
  if (window == nullptr) {
    cout << "Window could not be created! SDL_Error: " << SDL_GetError() << endl; 
    return false;
  }

  renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
  if (renderer == nullptr) {
    cout << "Renderer could not be created - SDL Error:\n" << SDL_GetError() << endl;
    return false;
  }

  SDL_SetRenderDrawColor(renderer, 0xff, 0xff, 0xff, 0xff);

  return true;
}

void DisplayManager::clear() {
  SDL_SetRenderDrawColor(renderer, 0xff, 0xff, 0xff, 0xff);
  SDL_RenderClear(renderer);
}

void DisplayManager::render() {
  SDL_RenderPresent(renderer);
}

void DisplayManager::setColor(uint8_t r, uint8_t g, uint8_t b, uint8_t a) {
  SDL_SetRenderDrawColor(renderer, r, g, b, a);
}

void DisplayManager::drawPoint(float x, float y) {
  SDL_RenderDrawPointF(renderer, x, y);
}

void DisplayManager::drawLine(float x1, float y1, float x2, float y2) {
  SDL_RenderDrawLineF(renderer, x1, y1, x2, y2);
}


// Private Methods

// code here
