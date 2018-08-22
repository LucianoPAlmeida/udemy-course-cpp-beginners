//
//  main.cpp
//  ParticleExplosions
//
//  Created by Luciano Almeida on 30/05/18.
//  Copyright © 2018 Luciano Almeida. All rights reserved.
//

#include <iostream>
#include <SDL.h>

int main(int argc, const char * argv[]) {
    const int SCREEN_WIDTH = 600;
    const int SCREEN_HEIGHT = 800;
    
    if(SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cout << "SDL Couldn't init" << std::endl;
        return 1;
    }
    std::cout << "SDL initialized" << std::endl;
    SDL_Window * window = SDL_CreateWindow("Particle Explosion",
                                           SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                                           SCREEN_HEIGHT, SCREEN_WIDTH, SDL_WindowFlags::SDL_WINDOW_RESIZABLE);
    if (window == NULL) {
        std::cout << "SDL Sadness" << std::endl;
        SDL_Quit();
    } else {
        SDL_ShowWindow(window);
    }
    
    SDL_Renderer * renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);
    
    if( renderer == NULL) {
        std::cout << "SDL Sadness" << std::endl;
        SDL_ShowWindow(window);
        SDL_Quit();
        return 1;
    }
    
    SDL_Texture * texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_BGR888, SDL_TEXTUREACCESS_STATIC,
                                              SCREEN_WIDTH, SCREEN_HEIGHT);
    
    if( texture == NULL) {
        std::cout << "SDL Sadness" << std::endl;
        SDL_DestroyRenderer(renderer);
        SDL_ShowWindow(window);
        SDL_Quit();
        return 1;
    }
    
    bool quit = false;
    
    SDL_Event event;
    
    Uint32 * buffer = new Uint32[SCREEN_WIDTH * SCREEN_HEIGHT];
    
    
    while (!quit) {
        //TODO: Stuff
        
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_EventType::SDL_QUIT) {
                quit = true;
            }
        }
    }
    
    SDL_DestroyTexture(texture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    delete [] buffer;
    return 0;
}
