#include "Core.hpp"

#include <iostream>
#include "DisplayManager.hpp"
#include "SDL.h"


using namespace std;


Core::Core() :
  quit(false),

  dm(new DisplayManager())
{}

Core::~Core() {
  if (dm) delete dm;
}


void Core::handleInputs() {
  SDL_Event e;

  while (SDL_PollEvent(&e) != 0) {
    if (e.type == SDL_QUIT) {
      quit = true;
    }
  }
}

void Core::update() {
  
}

void Core::display() {
  dm->clear();
  dm->setColor(0x00, 0x00, 0x00);
  dm->drawLine(10.0f, 10.0f, 310.0f, 10.0f);
  dm->drawLine(10.0f, 10.0f, 160.0f, 220.0f);
  dm->drawLine(160.0f, 220.0f, 310.0f, 10.0f);
  dm->render();
}

void Core::mainloop() {
  Uint32 time;

  time = SDL_GetTicks();
  while (!quit) {
    handleInputs();
    update();
    // cap at roughly 60 fps (not quite) todo: improve
    if (SDL_GetTicks() - time > SCREEN_TICKS_PER_FRAME) {
      display();
      time = SDL_GetTicks();
    }
  }
}

bool Core::init() {
  if (!dm->init()) {
    cout << "Something went wrong initializing the display manager" << endl;
    return false;
  }

  return true;
}


// Private methods

// code here
