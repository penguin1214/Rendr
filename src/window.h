//
// Created by Jinglei Yang on 4/25/17.
//

#ifndef RENDR_WINDOW_H
#define RENDR_WINDOW_H

#include <SDL2/SDL.h>
#include <vector>

using std::vector;

class  Window {
public:
    Window(const int width, const int height, const char *title)
            :width_(width), height_(height) {

        pixels_ = new Uint32[width_*height_];

        if (SDL_Init(SDL_INIT_VIDEO)) {
            std::cerr << "SDL_Init failed :(\n";
            exit(-1);
        }

        window_ = SDL_CreateWindow(title, 100, 100, width_, height_, SDL_WINDOW_SHOWN);
        if (!window_) {
            std::cout << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
            SDL_Quit();
            exit(-1);
        }

        renderer_ = SDL_CreateRenderer(window_, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
        if (!renderer_) {
            SDL_DestroyWindow(window_);
            std::cout << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
            SDL_Quit();
            exit(-1);
        }

        texture_ = SDL_CreateTexture(renderer_,
                                     SDL_PIXELFORMAT_ARGB8888,
                                     SDL_TEXTUREACCESS_STREAMING,
                                     width_, height_);
    }

    void show() const {
        SDL_RenderClear(renderer_);
        SDL_UpdateTexture(texture_, NULL, pixels_, width_* sizeof(Uint32));
        SDL_RenderCopy(renderer_, texture_, NULL, NULL);
        SDL_RenderPresent(renderer_);
    }

    Window(const Window &) = delete;
    Window& operator=(const Window &) = delete;

    ~Window() {
        delete[] pixels_;
        SDL_DestroyTexture(texture_);
        SDL_DestroyRenderer(renderer_);
    }
private:
    int 				 width_, height_;
    SDL_Window* window_;
    SDL_Renderer* renderer_;
    SDL_Texture* texture_;
    Uint32 *pixels_;
};
#endif //RENDR_WINDOW_H
