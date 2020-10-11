#ifndef _DISPLAY_MANAGER_HPP_
#define _DISPLAY_MANAGER_HPP_

#include <cstdint>


struct SDL_Window;
struct SDL_Renderer;

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;


class DisplayManager {
public:
  DisplayManager();
  ~DisplayManager();

  bool init();

  void clear();
  void render();

  void setColor(uint8_t r, uint8_t g, uint8_t b, uint8_t a = 0xff);
  void drawPoint(float x, float y);
  void drawLine(float x1, float y1, float x2, float y2);

private:
  SDL_Window* window;
  SDL_Renderer* renderer;
};

#endif // _DISPLAY_MANAGER_HPP_
