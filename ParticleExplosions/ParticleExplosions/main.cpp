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
    if(SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cout << "SDL Couldn't init" << std::endl;
        return 1;
    }
    std::cout << "SDL initialized" << std::endl;
    SDL_Window * window = SDL_CreateWindow("Particle Explosion",
                                           SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                                           800, 600, SDL_WindowFlags::SDL_WINDOW_RESIZABLE);
    if (window == NULL) {
        std::cout << "SDL Sadness" << std::endl;
    } else {
        SDL_ShowWindow(window);
    }
    
    bool quit = false;
    
    SDL_Event event;
    
    while (!quit) {
        //TODO: Stuff
        
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_EventType::SDL_QUIT) {
                quit = true;
            }
        }
    }
    
    
    SDL_DestroyWindow(window);
    SDL_Quit();
    
    return 0;
}
