#include "../main.h"

void draw_menu(t_game* game) {
  static TTF_Font* font = NULL;
  static SDL_Surface* text = NULL;
  static SDL_Surface* welcome = NULL;
  static SDL_Rect* whole, * to1, * to2;
  SDL_Color color = {99, 0, 0, 0};
  if (!font) font = TTF_OpenFont("./res/sixty.ttf", 65);
  if (!text) text = TTF_RenderText_Blended(font, " Test Projet for Ea", color);
  if (!welcome) welcome = TTF_RenderText_Blended(font, " ENTER", color);
  if (!whole) whole = sdlh_rect(0, 0, 400, 300);
  if (!to1) to1 = sdlh_rect(0, 0, 0, 0);
  if (!to2) to2 = sdlh_rect(95, 150, 0, 0);

  SDL_BlitSurface(text, whole, game->screen, to1);
  SDL_BlitSurface(welcome, whole, game->screen, to2);
  SDL_FreeSurface(text);
  TTF_CloseFont(font);
}

void sound_menu() {
  Mix_Chunk* music = NULL;

  if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) ==
      -1)
    err("error");
  Mix_VolumeMusic(MIX_MAX_VOLUME);
  music = Mix_LoadWAV("./res/sao.ogg");
  if (music == NULL)
    return;
  /*printf("%s\n", Mix_GetError());
  * @TODO FIX
*/
  Mix_PlayChannel(-1, music, 0);
  Mix_CloseAudio();
}
