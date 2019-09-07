#include "LearningSDL.h"

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int hello_SDL()
{
    SDL_Window* window = NULL;
    SDL_Surface* screenSurface = NULL;

    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        printf("SDL could not initialize! SDL_Error: %s.\n", SDL_GetError());
        return 1;
    }

    window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (window == NULL)
    {
        printf("Window could not be created! SDL_Error: %s.\n", SDL_GetError());
        return 1;
    }

    screenSurface = SDL_GetWindowSurface(window);

    SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0xff, 0xff, 0xff));

    SDL_UpdateWindowSurface(window);

    SDL_Delay(2000);

    //Destroy window
    SDL_DestroyWindow(window);

    //Quit SDL subsystems
    SDL_Quit();

    return 0;
}

Second_SDL::Second_SDL()
{
    m_window = NULL;
    m_screenSurface = NULL;
    m_HelloWorld = NULL;
}

Second_SDL::~Second_SDL()
{
    close();
}

bool Second_SDL::init()
{
    bool success = true;

    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        success = false;
    }
    else
    {
        m_window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        if (m_window == NULL)
        {
            printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
            success = false;
        }
        else
        {
            m_screenSurface = SDL_GetWindowSurface(m_window);
        }
    }

    return success;
}

bool Second_SDL::loadMedia()
{
    bool success = true;
    m_HelloWorld = SDL_LoadBMP("02_getting_an_image_on_the_screen/hello_world.bmp");

    if (m_HelloWorld == NULL)
    {
        printf("Unable to load image %s! SDL Error: %s\n", "02_getting_an_image_on_the_screen/hello_world.bmp", SDL_GetError());
        success = false;
    }

    return success;
}

void Second_SDL::close()
{
    //Deallocate surface
    SDL_FreeSurface(m_HelloWorld);
    m_HelloWorld = NULL;

    //Destroy window
    SDL_DestroyWindow(m_window);
    m_window = NULL;

    //Quit SDL subsystems
    SDL_Quit();
}

SDL_Surface* Second_SDL::loadSurface(const char* path)
{
    SDL_Surface* loadedSurface = SDL_LoadBMP(path);
    if (loadedSurface != NULL)
    {
        printf("Unable to load image %s! SDL Error: %s\n", path, SDL_GetError());
    }

    return loadedSurface;
}