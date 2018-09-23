//
//  main.cpp
//  ParticleExplosions
//
//  Created by Luciano Almeida on 30/05/18.
//  Copyright © 2018 Luciano Almeida. All rights reserved.
//

#include <iostream>
#include <SDL.h>
#include "Screen.hpp"
#include "Particle.hpp"
#include "Swarm.hpp"

using namespace particles;

int main(int argc, const char * argv[]) {
    
    srand((unsigned int)time(NULL));
    
    Screen * screen = new Screen(new std::string("Particles Explosion"));
    
    Swarm swarm;
    
    if (!screen->init()) {
        std::cout << "SDL Fail to initialize" << std::endl;
    }
    
    while (screen->processEvents()) {
        //TODO: Particle handle.
        int elapsed = SDL_GetTicks();
        unsigned char green = (unsigned char)((1 + sin(elapsed * 0.0001)) * 128);
        unsigned char red = (unsigned char)((1 + sin(elapsed * 0.0002)) * 128);
        unsigned char blue = (unsigned char)((1 + sin(elapsed * 0.0005)) * 128);

        for(int y=0; y < Screen::SCREEN_HEIGHT; y++) {
            for(int x=0; x < Screen::SCREEN_WIDTH; x++) {
                screen->setPixel(x, y, red, green, blue);
            }
        }
        screen->update();
    }
    
    screen->close();
    delete screen;
    
    return 0;
}
