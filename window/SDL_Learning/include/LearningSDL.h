#ifndef __HY_LEARNING_SDL_H__
#define __HY_LEARNING_SDL_H__

#include <SDL.h>
#include <stdio.h>

int hello_SDL();

class Second_SDL
{
public:
    Second_SDL();
    ~Second_SDL();

    bool init();

    bool loadMedia();

    void close();

    SDL_Surface* loadSurface(const char* path);

    SDL_Window*  m_window;
    SDL_Surface* m_screenSurface;
    SDL_Surface* m_HelloWorld;
};

#endif // __HY_LEARNING_SDL_H__