#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <SDL2/SDL.h>

enum Color
{
    BLACK,
    BLUE,
    GREEN,
    CYAN,
    RED,
    MAGENTA,
    BROWN,
    LIGHTGRAY,
    DARKGRAY,
    LIGHTBLUE,
    LIGHTGREEN,
    LIGHTCYAN,
    LIGHTRED,
    LIGHTMAGENTA,
    YELLOW,
    WHITE
};

class Graphics
{
private:
    SDL_Window *window;
    SDL_Renderer *renderer;
    int windowWidth;
    int windowHeight;

public:
    Graphics(const char *title, int width, int height)
        : windowWidth(width), windowHeight(height)
    {
        SDL_Init(SDL_INIT_VIDEO);
        window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);
        renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    }

    ~Graphics()
    {
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
    }

    void setColor(Color color)
    {
        SDL_Color c;
        switch (color)
        {
        case BLACK:
            c = {0, 0, 0, 255};
            break;
        case BLUE:
            c = {0, 0, 255, 255};
            break;
        case GREEN:
            c = {0, 255, 0, 255};
            break;
        case CYAN:
            c = {0, 255, 255, 255};
            break;
        case RED:
            c = {255, 0, 0, 255};
            break;
        case MAGENTA:
            c = {255, 0, 255, 255};
            break;
        case BROWN:
            c = {139, 69, 19, 255};
            break;
        case LIGHTGRAY:
            c = {169, 169, 169, 255};
            break;
        case DARKGRAY:
            c = {169, 169, 169, 255};
            break;
        case LIGHTBLUE:
            c = {173, 216, 230, 255};
            break;
        case LIGHTGREEN:
            c = {144, 238, 144, 255};
            break;
        case LIGHTCYAN:
            c = {224, 255, 255, 255};
            break;
        case LIGHTRED:
            c = {255, 182, 193, 255};
            break;
        case LIGHTMAGENTA:
            c = {255, 182, 193, 255};
            break;
        case YELLOW:
            c = {255, 255, 0, 255};
            break;
        case WHITE:
            c = {255, 255, 255, 255};
            break;
        default:
            c = {0, 0, 0, 255};
            break;
        }
        SDL_SetRenderDrawColor(renderer, c.r, c.g, c.b, c.a);
    }

    void line(int x1, int y1, int x2, int y2)
    {
        SDL_RenderDrawLine(renderer, x1, y1, x2, y2);
    }

    void putpixel(int x, int y)
    {
        SDL_RenderDrawPoint(renderer, x, y);
    }

    void cleardevice()
    {
        SDL_RenderClear(renderer);
    }

    void refresh()
    {
        SDL_RenderPresent(renderer);
    }

    int getwidth() { return windowWidth; }
    int getheight() { return windowHeight; }
};

#endif // GRAPHICS_H
