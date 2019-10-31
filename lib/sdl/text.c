#include "../../main.h"

SDL_Surface* draw_text(char* text) {
  static SDL_Color color = {99, 0, 0, 0};
  static TTF_Font* font;
  if (!font) font = TTF_OpenFont("./res/sixty.ttf", 45);
  return TTF_RenderText_Blended(font, text, color);
}
