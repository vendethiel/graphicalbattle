#include "../main.h"

void		draw_menu(t_game *game)
{
	TTF_Font *font = NULL;
	SDL_Surface *text = NULL;
	SDL_Surface *welcome = NULL;	
	SDL_Color color = {99, 0, 0,0};

   	font = TTF_OpenFont("./res/sixty.ttf", 65);
    text = TTF_RenderText_Blended(font, " Test Projet for Ea", color);
    welcome = TTF_RenderText_Blended(font, " ENTER", color);
    SDL_BlitSurface(text, sdlh_rect(0, 0, 400, 300),
		game->screen, sdlh_rect(0, 0, 0, 0)
	);
	SDL_BlitSurface(welcome, sdlh_rect(0, 0, 400, 300),
		game->screen, sdlh_rect(95, 150, 0, 0)
	);
    SDL_FreeSurface(text);
    TTF_CloseFont(font);
}

void		sound_menu()
{
	Mix_Chunk *music = NULL;

	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS,  1024) == -1)
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